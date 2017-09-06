//
//	Parser for Maude surface syntax.
//

%{
#include <string>

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "mixfix.hh"

//	core class definitions
#include "lineNumber.hh"

//	front end class definitions
#include "token.hh"
#include "fileTable.hh"
#include "directoryManager.hh"
#include "preModule.hh"
#include "visibleModule.hh"  // HACK
#include "userLevelRewritingContext.hh"
#include "interpreter.hh"

#include "main.hh"
#define clear()		bubble.contractTo(0);
#define store(token)	bubble.append(token)
#define YYPARSE_PARAM	parseResult
#define PARSE_RESULT	(*((UserLevelRewritingContext::ParseResult*) parseResult))

#define CM		interpreter.getCurrentModule()

void lexerInitialMode();
void lexerIdMode();
void lexerCmdMode();
void lexerFileNameMode();
void lexerStringMode();
void lexerLatexMode();
bool handleEof();
bool includeFile(const string& directory, const string& fileName, bool silent, int lineNr);
void eatComment(bool firstNonWhite);

Vector<Token> bubble;
Vector<Token> moduleExpr;

//PreModule* currentModule = 0;
Int64 number;
Int64 number2;

static void yyerror(char *s);
void cleanUpParser();
%}
%pure_parser

%union
{
  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
}

%{
int yylex(YYSTYPE* lvalp);
%}

%token <yyString> FILE_NAME_STRING UNINTERPRETED_STRING LATEX_STRING
/*
 *	Inert keywords: these are only recognized by lexer when in initial mode.
 */
%token <yyToken> KW_FMOD KW_MOD KW_OMOD
%token KW_PARSE KW_NORMALIZE KW_REDUCE KW_REWRITE
%token KW_LOOP KW_NARROW KW_MATCH KW_XMATCH KW_UNIFY KW_XUNIFY
%token KW_EREWRITE KW_FREWRITE KW_OREWRITE
%token KW_CONTINUE KW_SEARCH
%token KW_SET KW_SHOW KW_ON KW_OFF 
%token KW_TRACE KW_CONTEXT KW_WHOLE KW_SELECT KW_DESELECT KW_CONDITION KW_SUBSTITUTION
%token KW_PRINT KW_GRAPH KW_MIXFIX KW_FLAT
%token KW_WITH KW_PARENS KW_ALIASES KW_GC KW_TIME KW_STATS KW_TIMING
%token KW_CMD KW_BREAKDOWN KW_BREAK KW_PATH
%token KW_MODULE KW_ALL KW_SORTS KW_OPS KW_VARS
%token KW_MBS KW_EQS KW_RLS KW_SUMMARY KW_KINDS KW_ADVISE KW_VERBOSE
%token KW_DO KW_CLEAR
%token KW_INCLUDE KW_EXCLUDE KW_CONCEAL KW_REVEAL KW_COMPILE KW_COUNT
%token KW_DEBUG KW_RESUME KW_ABORT KW_STEP KW_WHERE KW_CREDUCE KW_DUMP KW_PROFILE
%token KW_NUMBER KW_RAT KW_COLOR
%token <yyInt64> SIMPLE_NUMBER
%token KW_PWD KW_CD KW_PUSHD KW_POPD KW_LS KW_LOAD KW_QUIT KW_EOF

/*
 *	Start keywords: signal end of mixfix statement if following '.'.
 */
%token <yyToken> KW_ENDFM KW_ENDM KW_ENDOM
%token <yyToken> KW_IMPORT KW_SORT KW_SUBSORT KW_OP KW_OPS KW_MSGS KW_VAR KW_CLASS KW_SUBCLASS
%token <yyToken> KW_MB KW_CMB KW_EQ KW_CEQ KW_RL KW_CRL

/*
 *	Mid keywords: need to be recognized in the middle of mixfix syntax.
 */
%token <yyToken> KW_IS
%token <yyToken> KW_ARROW KW_ARROW2 KW_PARTIAL KW_IF
%type <yyToken> ':' '=' '(' ')' '.' '<' '[' ']' ',' '|'

/*
 *	Attribute keywords need to be recognized when parsing attributes.
 */
%token <yyToken> KW_ASSOC KW_COMM KW_ID KW_IDEM KW_ITER
%token <yyToken> KW_LEFT KW_RIGHT KW_PREC KW_GATHER KW_STRAT
%token <yyToken> KW_MEMO KW_FROZEN KW_CTOR KW_LATEX KW_SPECIAL KW_CONFIG KW_OBJ KW_MSG
%token <yyToken> KW_DITTO KW_FORMAT
%token <yyToken> KW_ID_HOOK KW_OP_HOOK KW_TERM_HOOK

/*
 *	Command keywords need to be recognized when parsing commands.
 */
%token <yyToken> KW_IN

/*
 *	Special tokens.
 */
%token <yyToken> IDENTIFIER NUMERIC_ID

/*
 *	Nonterminals that return tokens.
 */
%type <yyToken> identifier startKeyword startKeyword2 midKeyword attrKeyword attrKeyword2
%type <yyToken> token endToken
%type <yyToken> tokenBarLt tokenBarColon tokenBarEqual tokenBarIf tokenBarArrow2
%type <yyToken> identityChunk tokenBarDot
%type <yyToken> cToken cTokenBarDot cTokenBarDotColon cTokenBarIn
%type <yyToken> cTokenBarLeftIn cTokenBarDotNumber cTokenBarDotRight
%type <yyToken> cSimpleTokenBarDot
%type <yyToken> cTokenBarDotCommaRight
%type <yyToken> sortToken
%type <yyToken> notEndfm notEndm notEndom

/*
 *	Nonterminals that return bool.
 */
%type <yyBool> polarity select match optDebug conceal exclude arrow
/*
 *	Nonterminals that return int.
 */
%type <yyInt64> optNumber

%start top

%%

top		:	item { YYACCEPT; }
		|
			{
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			}
		;

item		:	module
		|	directive
		|	command
		;

/*
 *	Directives.
 */
directive	:	KW_IN		{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  int lineNr = lineNumber;
			  eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile($3, directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			}
		|	KW_LOAD		{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  int lineNr = lineNumber;
			  eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile($3, directory, fileName, lineNr))
			    includeFile(directory, fileName, true, lineNr);
			}
		|	KW_PWD
			{
			  cout << directoryManager.getCwd() << '\n';
			}
		|	KW_CD		{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  string directory;
			  directoryManager.realPath($3, directory);
			  if (!directoryManager.cd(directory))
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": cd failed");
			    }
			}
		|	KW_PUSHD	{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  string directory;
			  directoryManager.realPath($3, directory);
			  if (directoryManager.pushd(directory) == UNDEFINED)
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": pushd failed");
			    }
			}
		|	KW_POPD
			{
			  const char* path = directoryManager.popd();
			  if (path != 0)
			    cout << path << '\n';
			  else
			    {
			      IssueWarning(LineNumber(lineNumber) <<
					   ": popd failed");
			    }
			}
		|	KW_LS		{ lexerStringMode(); }
			UNINTERPRETED_STRING
			{
			  system((string("ls") + $3).c_str());
			}
		|	KW_QUIT
			{
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			  YYACCEPT;
			}
		|	KW_EOF
			{
			  if(!handleEof())
			    {
			      PARSE_RESULT = UserLevelRewritingContext::QUIT;
			    }
			}
		;
/*
 *	Modules.
 */
module		:	KW_FMOD			{ lexerIdMode(); }
			token KW_IS
			{
			  interpreter.
			    setCurrentModule(new PreModule($3, MixfixModule::FUNCTIONAL_MODULE));
			  fileTable.beginModule($1, $3);
			}
			fDecList endfm
			{
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule();
			}
		|	KW_MOD			{ lexerIdMode(); }
			token KW_IS
			{
			  interpreter.
			    setCurrentModule(new PreModule($3, MixfixModule::SYSTEM_MODULE));
			  fileTable.beginModule($1, $3);
			}
			decList endm
			{
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule();
			}
		|	KW_OMOD			{ lexerIdMode(); }
			token KW_IS
			{
			  interpreter.
			    setCurrentModule(new PreModule($3, MixfixModule::SYSTEM_MODULE));
			  fileTable.beginModule($1, $3);
			}
			oDecList endom
			{
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule();
			}
		;

endfm		:	KW_ENDFM	{}
		|	notEndfm
			{
			  IssueWarning(LineNumber(lineNumber) <<
			               ": fmod ended by " << $1 << '.');
			}
		;

notEndfm	:	KW_ENDM | KW_ENDOM
		;

endm		:	KW_ENDM	{}
		|	notEndm
			{
			  IssueWarning(LineNumber(lineNumber) <<
			               ": mod ended by " << $1 << '.');
			}
		;

notEndm		:	KW_ENDFM | KW_ENDOM
		;

endom		:	KW_ENDOM	{}
		|	notEndom
			{
			  IssueWarning(LineNumber(lineNumber) <<
			               ": omod ended by " << $1 << '.');
			}
		;

notEndom	:	KW_ENDFM | KW_ENDM
		;

fDecList	:	fDecList fDeclaration
		|
		;

decList		:	decList declaration
		|
		;

oDecList	:	oDecList oDeclaration
		|
		;

fDeclaration	:	KW_IMPORT		{ clear(); store($1); }
			endTokens '.'		{ CM->addImport(bubble); }

/*
 *	Now that '.' is not a valid sort name we can probably get rid of
 *	endTokens2 and noTrailingDot2
 */
		|	KW_SORT			{ clear(); }
			endTokens2 '.'		{ CM->addSortDecl(bubble); }

		|	KW_SUBSORT token	{ clear(); store($2); }
			listBarLt '<'		{ store($5); }
			endTokens2 '.'		{ CM->addSubsortDecl(bubble); }

		|	KW_OP opName domainRangeAttr {}

		|	KW_OPS opNameList domainRangeAttr {}

		|	KW_VAR varNameList ':' type '.' {}

		|	KW_MB			{ clear(); store($1); }
			tokensBarColon ':'	{ store($4); }
			endTokens '.'		{ CM->addStatement(bubble); }

		|	KW_CMB			{ clear(); store($1); }
			tokensBarColon ':'	{ store($4); }
			tokensBarIf KW_IF	{ store($7); }
			endTokens '.'		{ CM->addStatement(bubble); }

		|	KW_EQ			{ clear(); store($1); }
			tokensBarEqual '='	{ store($4); }
			endTokens '.'		{ CM->addStatement(bubble); }

		|	KW_CEQ			{ clear(); store($1); }
			tokensBarEqual '='	{ store($4); }
			tokensBarIf KW_IF		{ store($7); }
			endTokens '.'		{ CM->addStatement(bubble); }

		|	error '.' 		{ CM->makeOpDeclsConsistent(); }
		;

declaration	:	fDeclaration
		|	KW_RL			{ clear(); store($1); }
			tokensBarArrow2 KW_ARROW2  { store($4); }
			endTokens '.'		{ CM->addStatement(bubble); }

		|	KW_CRL			{ clear(); store($1); }
			tokensBarArrow2 KW_ARROW2	{ store($4); }
			tokensBarIf KW_IF		{ store($7); }
			endTokens '.'		{ CM->addStatement(bubble); }
		;

oDeclaration	:	declaration
		|	KW_MSG opName domainRangeAttr
			{
			  CM->setFlag(SymbolType::MESSAGE);
			}
		|	KW_MSGS opNameList domainRangeAttr
			{
			  CM->setFlag(SymbolType::MESSAGE);
			}
		|	KW_CLASS token
			{
			}
			classDef '.'
			{
			}
		|	KW_SUBCLASS token	{ clear(); store($2); }
			listBarLt '<'		{ store($5); }
			endTokens2 '.'		{ CM->addSubsortDecl(bubble); }
		;

classDef	:	'|' {}
		|	'|' cPairList {}
		;

cPairList	:	cPair
		|	cPairList ',' cPair
		;

cPair		:	tokenBarDot ':' token
			{
			}
		;

varNameList	:	varNameList tokenBarColon { CM->addVarDecl($2); }
		|	tokenBarColon		{ CM->addVarDecl($1); }
		;

opName		:	token			{ clear(); store($1); }
			tokensBarColon		{ CM->addOpDecl(bubble); }
		|	'(' 			{ clear(); }
			tokens ')'		{ CM->addOpDecl(bubble); }
		;

opNameList	:	opNameList simpleOpName
		|	simpleOpName
		;

simpleOpName	:	tokenBarColon
			{
			  clear();
			  store($1);
			  CM->addOpDecl(bubble);
			}
		|	'('			{ clear(); }
			tokens ')'		{ CM->addOpDecl(bubble); }
		;

domainRangeAttr	:	':' typeList arrow type attributes '.'
			{
			  if ($3)
			    CM->convertSortsToKinds();
			}
		;

arrow		:	KW_ARROW      		{ $$ = false; }
		|	KW_PARTIAL	       	{ $$ = true; }
		;

typeList	:	typeList type
		|
		;

type		:	sortToken
			{
			  clear();
			  bubble.append($1);
			  CM->addType(false, bubble);
			}
		|	'['			{ clear(); }
			sortTokens ']'
			{
			  CM->addType(true, bubble);
			}
		;

sortTokens	:	sortTokens ',' sortToken	{ store($3); }
		|	sortToken			{ store($1); }
		;

attributes	:	'[' attributeList ']'	{}
		|
		;

attributeList	:	attributeList attribute
		|	attribute
		;

idKeyword	:	KW_ID
			{
			  CM->setFlag(SymbolType::LEFT_ID | SymbolType::RIGHT_ID);
			}
		|	KW_LEFT KW_ID
			{
			  CM->setFlag(SymbolType::LEFT_ID);
			}
		|	KW_RIGHT KW_ID
			{
			  CM->setFlag(SymbolType::RIGHT_ID);
			}
		;

attribute	:	KW_ASSOC		
			{
			  CM->setFlag(SymbolType::ASSOC);
			}
		|	KW_COMM
			{
			  CM->setFlag(SymbolType::COMM);
			}
		|	idKeyword		{ clear(); }
			identity		{ CM->setIdentity(bubble); }
		|	KW_IDEM
			{
			  CM->setFlag(SymbolType::IDEM);
			}
		|	KW_ITER
			{
			  CM->setFlag(SymbolType::ITER);
			}
		|	KW_PREC IDENTIFIER	{ CM->setPrec($2); }
		|	KW_GATHER '('		{ clear(); }
			idList ')'		{ CM->setGather(bubble); }
		|	KW_FORMAT '('		{ clear(); }
			idList ')'		{ CM->setFormat(bubble); }
		|	KW_STRAT '('		{ clear(); }
			idList ')'		{ CM->setStrat(bubble); }
		|	KW_MEMO
			{
			  CM->setFlag(SymbolType::MEMO);
			}
		|	KW_CTOR
			{
			  CM->setFlag(SymbolType::CTOR);
			}
		|	KW_FROZEN
			{
			  clear();
			  CM->setFrozen(bubble);
			}
		|	KW_FROZEN '('		{ clear(); }
			idList ')'		{ CM->setFrozen(bubble); }
		|	KW_CONFIG
			{
			  CM->setFlag(SymbolType::CONFIG);
			}
		|	KW_OBJ
			{
			  CM->setFlag(SymbolType::OBJECT);
			}
		|	KW_MSG
			{
			  CM->setFlag(SymbolType::MESSAGE);
			}
		|	KW_LATEX '('		{ lexerLatexMode(); }
			LATEX_STRING ')'	{ CM->setLatexMacro($4); }
		|	KW_SPECIAL '(' hookList ')'	{}
		|	KW_DITTO
			{
			  CM->setFlag(SymbolType::DITTO);
			}
		;

idList		:	idList IDENTIFIER	{ store($2); }
		|	IDENTIFIER		{ store($1); }
		;

hookList	:	hookList hook
		|	hook
		;

hook		:	KW_ID_HOOK token
			{
			  clear();
			  CM->addHook(PreModule::ID_HOOK, $2, bubble);
			}
		|	KW_ID_HOOK token '(' 	{ clear(); }
			tokens ')'
			{
			  CM->addHook(PreModule::ID_HOOK, $2, bubble);
			}
		|	KW_OP_HOOK token '('	{ clear(); }
			tokens ')'
			{
			  CM->addHook(PreModule::OP_HOOK, $2, bubble);
			}
		|	KW_TERM_HOOK token '('	{ clear(); }
			tokens ')'
			{
			  CM->addHook(PreModule::TERM_HOOK, $2, bubble);
			}
		;

/*
 *	Token lists.
 */
listBarLt	:	listBarLt tokenBarLt	{ store($2); }
		|
		;

endTokens2	:	noTrailingDot2
		|	endTokens2 '.'		{ store($2); }
		|	'.'			{ store($1); }
		;

noTrailingDot2	:	noTrailingDot2 startKeyword	{ store($2); }
		|	endTokens2 endToken	{ store($2); }
		|	tokenBarDot		{ store($1); }
		;

/*
 *	Token trees.
 */
tokens		:	tokens '('		{ store($2); }
			tokens ')'		{ store($5); }
		|	tokens token		{ store($2); }
		|
		;

tokensBarColon	:	tokensBarColon '('	{ store($2); }
			tokens ')'		{ store($5); }
		|	tokensBarColon tokenBarColon	{ store($2); }
		|
		;

tokensBarEqual	:	tokensBarEqual '('	{ store($2); }
			tokens ')'		{ store($5); }
		|	tokensBarEqual tokenBarEqual	{ store($2); }
		|
		;

tokensBarArrow2	:	tokensBarArrow2 '('	{ store($2); }
			tokens ')'		{ store($5); }
		|	tokensBarArrow2 tokenBarArrow2	{ store($2); }
		|
		;

tokensBarIf	:	tokensBarIf '('		{ store($2); }
			tokens ')'		{ store($5); }
		|	tokensBarIf tokenBarIf	{ store($2); }
		|
		;

endTokens	:	noTrailingDot
		|	endTokens '.'		{ store($2); }
		|	'.'			{ store($1); }
		;

noTrailingDot	:	'('			{ store($1); }
			tokens ')'		{ store($4); }
		|	endTokens '('		{ store($2); }
			tokens ')'		{ store($5); }
		|	noTrailingDot startKeyword	{ store($2); }
		|	endTokens endToken	{ store($2); }
		|	tokenBarDot		{ store($1); }
		;

/*
 *	Special trees
 */
identity	:	identityChunk		{ store($1); }
		|	identity identityChunk	{ store($2); }
		;

identityChunk	:	identifier | startKeyword2 | midKeyword | '.'
		|	'('			{ store($1); }
			tokens ')'		{ $$ = $4; }
		;

/*
 *	Token types.
 */
token		:	identifier | startKeyword | midKeyword | attrKeyword | '.'
		;

tokenBarDot	:	identifier | startKeyword | midKeyword | attrKeyword
		;

endToken	:	identifier | midKeyword | attrKeyword
		;

tokenBarArrow2	:	identifier | startKeyword | attrKeyword | '.'
		|	'<' | ':' | KW_ARROW | KW_PARTIAL | '=' | KW_IF | KW_IS
		;
tokenBarEqual	:	identifier | startKeyword | attrKeyword | '.'
		|	'<' | ':' | KW_ARROW | KW_PARTIAL | KW_ARROW2 | KW_IF | KW_IS
		;
tokenBarIf	:	identifier | startKeyword | attrKeyword | '.'
		|	'<' | ':' | KW_ARROW | KW_PARTIAL | '=' | KW_ARROW2 | KW_IS
		;
tokenBarColon	:	identifier | startKeyword | attrKeyword | '.'
		|	'<' | KW_ARROW | KW_PARTIAL | '=' | KW_ARROW2 | KW_IF | KW_IS
		;
tokenBarLt	:	identifier | startKeyword | attrKeyword | '.'
		|	':' | KW_ARROW | KW_PARTIAL | '=' | KW_ARROW2 | KW_IF | KW_IS
		;

sortToken	:	identifier | startKeyword | attrKeyword2 | '='
		|	KW_ARROW2 | KW_IF | KW_IS
		;

/*
 *	Keywords (in id mode).
 */
identifier	:	IDENTIFIER | ',' | '|'
		;

startKeyword	:	KW_MSG | startKeyword2
		;

startKeyword2	:	KW_IMPORT | KW_SORT | KW_SUBSORT | KW_OP | KW_OPS | KW_VAR
		|	KW_MSGS | KW_CLASS | KW_SUBCLASS
		|	KW_MB | KW_CMB | KW_EQ | KW_CEQ | KW_RL | KW_CRL
		|	KW_ENDFM | KW_ENDM | KW_ENDOM
		;

midKeyword	:	'<' | ':' | KW_ARROW | KW_PARTIAL | '=' | KW_ARROW2 | KW_IF | KW_IS
		;

attrKeyword	:	'[' | ']' | attrKeyword2
		;

attrKeyword2	:	KW_ASSOC | KW_COMM | KW_ID | KW_IDEM | KW_ITER | KW_LEFT | KW_RIGHT
		|	KW_PREC | KW_GATHER | KW_STRAT | KW_MEMO | KW_CTOR
		|	KW_LATEX | KW_SPECIAL | KW_FROZEN
		|	KW_CONFIG | KW_OBJ | KW_DITTO | KW_FORMAT
		|	KW_ID_HOOK | KW_OP_HOOK | KW_TERM_HOOK
		;
/*
 *	Commands.
 */
command		:	KW_SELECT		{ lexerCmdMode(); clear(); }
			cToken			{ store($3); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  interpreter.setCurrentModule(bubble);
			}
		|	KW_DUMP			{ lexerCmdMode(); clear(); }
			cToken			{ store($3); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->dump();
			}
		|	KW_PARSE
			{
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(bubble);
			}

		|	KW_CREDUCE
			{
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(bubble);
			}

		|	optDebug KW_REDUCE
			{
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(bubble, $1);
			}

		|	optDebug KW_REWRITE
			{
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(bubble, number, $1);
			}
		|	optDebug KW_EREWRITE
			{
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    ;
			}
		|	optDebug KW_FREWRITE
			{
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
			numbersModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(bubble, number, number2, $1);
			}
		|	KW_SEARCH
			{
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(bubble, number);
			}
		|	match
			{
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(bubble, $1, number);
			}
		|	optDebug KW_CONTINUE optNumber '.'
			{
			  interpreter.cont($3, $1);
			}
		|	KW_LOOP
			{
			  lexerCmdMode();
			  clear();
			  moduleExpr.contractTo(0);
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(bubble);
			}
		|	'('			{ lexerCmdMode(); clear(); }
			cTokens	')'
			{
			  lexerInitialMode();
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(bubble);
			}

		|	KW_TRACE select		{ lexerCmdMode(); }
			cOpNameList '.'
			{
			  lexerInitialMode();
			  interpreter.traceSelect($2);
			}
		|	KW_TRACE exclude		{ lexerCmdMode(); }
			cOpNameList '.'
			{
			  lexerInitialMode();
			  interpreter.traceExclude($2);
			}
		|	KW_BREAK select		{ lexerCmdMode(); }
			cOpNameList '.'
			{
			  lexerInitialMode();
			  interpreter.breakSelect($2);
			}
		|	KW_PRINT conceal		{ lexerCmdMode(); }
			cOpNameList '.'
			{
			  lexerInitialMode();
			  interpreter.printConceal($2);
			}
		|	KW_DO KW_CLEAR KW_MEMO '.'
			{
			  if (CM != 0)  // HACK
			    CM->getFlatSignature()->clearMemo();
			}
/*
 *	Commands to show interpreter state.
 */
		|	KW_SHOW KW_MOD		{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			}
		|	KW_SHOW KW_MODULE	{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    CM->showModule();
			}
		|	KW_SHOW KW_ALL		{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showModule(true);
			}
		|	KW_SHOW KW_SORTS	{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSortsAndSubsorts();
			}
		|	KW_SHOW KW_OPS		{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showOps();
			}
		|	KW_SHOW KW_VARS		{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showVars();
			}
		|	KW_SHOW KW_MBS		{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showMbs();
			}
		|	KW_SHOW KW_EQS		{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showEqs();
			}
		|	KW_SHOW KW_RLS		{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showRls();
			}
		|	KW_SHOW KW_SUMMARY	{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showSummary();
			}
		|	KW_SHOW KW_KINDS	{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showKinds();
			}
		|	KW_SHOW KW_PATH SIMPLE_NUMBER '.'
			{
			  interpreter.showSearchPath($3);
			}
		|	KW_SHOW KW_SEARCH KW_GRAPH '.'
			{
			  interpreter.showSearchGraph();
			}
		|	KW_SHOW KW_PROFILE	{ lexerCmdMode(); clear(); }
			cTokensBarDot '.'
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(bubble))
			    interpreter.showProfile();
			}
/*
 *	Commands to set interpreter state variables.
 */
		|	KW_SET KW_SHOW KW_ADVISE polarity '.'
			{
			  globalAdvisoryFlag = $4;
			}
		|	KW_SET KW_SHOW KW_STATS polarity '.'
			{
			  interpreter.setFlag(Interpreter::SHOW_STATS, $4);
			}
		|	KW_SET KW_SHOW KW_LOOP KW_STATS polarity '.'
			{
			  interpreter.setFlag(Interpreter::SHOW_LOOP_STATS, $5);
			}
		|	KW_SET KW_SHOW KW_TIMING polarity '.'
			{
			  interpreter.setFlag(Interpreter::SHOW_TIMING, $4);
			}
		|	KW_SET KW_SHOW KW_BREAKDOWN polarity '.'
			{
			  interpreter.setFlag(Interpreter::SHOW_BREAKDOWN, $4);
			}
		|	KW_SET KW_SHOW KW_LOOP KW_TIMING polarity '.'
			{
			  interpreter.setFlag(Interpreter::SHOW_LOOP_TIMING, $5);
			}
		|	KW_SET KW_SHOW KW_CMD polarity '.'
			{
			  interpreter.setFlag(Interpreter::SHOW_COMMAND, $4);
			}
		|	KW_SET KW_SHOW KW_GC polarity '.'
			{
			  MemoryCell::setShowGC($4);
			}
		|	KW_SET KW_PRINT KW_MIXFIX polarity '.'
			{
			  MixfixModule::setPrintMixfix($4);
			}
		|	KW_SET KW_PRINT KW_FLAT polarity '.'
			{
			  MixfixModule::setPrintFlat($4);
			}
		|	KW_SET KW_PRINT KW_WITH KW_ALIASES polarity '.'
			{
			  MixfixModule::setPrintWithAliases($5);
			}
		|	KW_SET KW_PRINT KW_WITH KW_PARENS polarity '.'
			{
			  MixfixModule::setPrintWithParens($5);
			}
		|	KW_SET KW_PRINT KW_GRAPH polarity '.'
			{
			  MixfixModule::setPrintGraph($4);
			}
		|	KW_SET KW_PRINT KW_CONCEAL polarity '.'
			{
			  MixfixModule::setPrintConceal($4);
			}
		|	KW_SET KW_PRINT KW_NUMBER polarity '.'
			{
			  interpreter.setFlag(Interpreter::PRINT_NUMBER, $4);
			}
		|	KW_SET KW_PRINT KW_RAT polarity '.'
			{
			  interpreter.setFlag(Interpreter::PRINT_RAT, $4);
			}
		|	KW_SET KW_PRINT KW_COLOR polarity '.'
			{
			  interpreter.setFlag(Interpreter::PRINT_COLOR, $4);
			}
		|	KW_SET KW_PRINT KW_FORMAT polarity '.'
			{
			  MixfixModule::setPrintFormat($4);
			}
		|	KW_SET KW_TRACE polarity '.'
			{
			  interpreter.setFlag(Interpreter::TRACE, $3);
			}
		|	KW_SET KW_TRACE KW_CONDITION polarity '.'
			{
			  UserLevelRewritingContext::setTraceConditionFlag($4);
			}
		|	KW_SET KW_TRACE KW_CONTEXT polarity '.'
			{
			// ??? what is this supposed to do?
			}
		|	KW_SET KW_TRACE KW_WHOLE polarity '.'
			{
			  UserLevelRewritingContext::setTraceWholeFlag($4);
			}
		|	KW_SET KW_TRACE KW_SUBSTITUTION polarity '.'
			{
			  UserLevelRewritingContext::setTraceSubstitutionFlag($4);
			}
		|	KW_SET KW_TRACE KW_SELECT polarity '.'
			{
			  UserLevelRewritingContext::setTraceSelectFlag($4);
			}
		|	KW_SET KW_TRACE KW_MBS polarity '.'
			{
			  UserLevelRewritingContext::setTraceScFlag($4);
			}
		|	KW_SET KW_TRACE KW_EQS polarity '.'
			{
			  UserLevelRewritingContext::setTraceEqFlag($4);
			}
		|	KW_SET KW_TRACE KW_RLS polarity '.'
			{
			  UserLevelRewritingContext::setTraceRuleFlag($4);
			}
		|	KW_SET KW_BREAK polarity '.'
			{
			  interpreter.setFlag(Interpreter::BREAK, $3);
			}
		|	KW_SET KW_INCLUDE		{ lexerCmdMode(); }
			cSimpleTokenBarDot		{ lexerInitialMode(); }
			polarity '.'
			{
			  interpreter.setInclude($4, $6);
			}
		|	KW_SET KW_OMOD KW_INCLUDE	{ lexerCmdMode(); }
			cSimpleTokenBarDot		{ lexerInitialMode(); }
			polarity '.'
			{
			  interpreter.setOmodInclude($5, $7);
			}
		|	KW_SET KW_VERBOSE polarity '.'
			{
			  globalVerboseFlag = $3;
			}
		|	KW_SET KW_CLEAR KW_MEMO polarity '.'
			{
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_MEMO, $4);
			}
		|	KW_SET KW_COMPILE KW_COUNT polarity '.'
			{
			  interpreter.setFlag(Interpreter::COMPILE_COUNT, $4);
			}
		|	KW_SET KW_PROFILE polarity '.'
			{
			  interpreter.setFlag(Interpreter::PROFILE, $3);
			}
		|	KW_SET KW_CLEAR KW_PROFILE polarity '.'
			{
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_PROFILE, $4);
			}
/*
 *	Debugger mode commands
 */
		|	KW_RESUME '.'
			{
			  PARSE_RESULT = UserLevelRewritingContext::RESUME;
			}
		|	KW_ABORT '.'
			{
			  PARSE_RESULT = UserLevelRewritingContext::ABORT;
			}
		|	KW_STEP '.'
			{
			  PARSE_RESULT = UserLevelRewritingContext::STEP;
			}
		|	KW_WHERE '.'
			{
			  PARSE_RESULT = UserLevelRewritingContext::WHERE;
			}
/*
 *	OBJ3 legacy cruft.
 */
		|	KW_SET KW_GC KW_SHOW polarity '.'
			{
			  MemoryCell::setShowGC($4);
			}
		|	KW_SET KW_STATS polarity '.'
			{
			  interpreter.setFlag(Interpreter::SHOW_STATS, $3);
			}
/*
 *	Error recovery.
 */
		|	error			{ lexerInitialMode(); }
			'.'
		;

/*
 *	Options
 */
polarity	:	KW_ON			{ $$ = true; }
		|	KW_OFF			{ $$ = false; }
		;

select		:	KW_SELECT		{ $$ = true; }
		|	KW_DESELECT		{ $$ = false; }
		;

exclude		:	KW_EXCLUDE	       	{ $$ = true; }
		|	KW_INCLUDE	       	{ $$ = false; }
		;

conceal		:	KW_CONCEAL		{ $$ = true; }
		|	KW_REVEAL		{ $$ = false; }
		;

match		:	KW_XMATCH		{ $$ = true; }
		|	KW_MATCH		{ $$ = false; }
		;

optDebug       	:	KW_DEBUG 	       	{ $$ = true; }
		|	       			{ $$ = false; }
		;

optNumber	:	SIMPLE_NUMBER	        { $$ = $1; }
		|				{ $$ = NONE; }
		;
/*
 *	Optional module expression followed by term followed by dot.
 *	{"in" <module expression> ":"} <term> "."
 *	<module expression> is a (possibly empty) bubble not containing ':' or '.'
 *	<term> is a (non-empty) bubble not containing '.' except as first token
 */
moduleAndTerm	:	KW_IN			{ store($1); }
			cTokensBarDotColon inEnd
		|	cTokenBarIn		{ store($1); }
			cTokensBarDot '.'
		;

inEnd		:	':'			{ moduleExpr = bubble; clear(); }
			cToken			{ store($3); }
			cTokensBarDot '.'	{}
		|	'.'			{}
		;

/*
 *	Optional [number] followed by optional module expression, followed
 *	by term, followed by dot.
 *	{"[" <number> "]"} {"in" <module expression> ":"} <term> "."
 */
numberModuleTerm
		:	'['			{ store($1); }
			numberModuleTerm1
		|	KW_IN			{ store($1); }
			cTokensBarDotColon inEnd
		|	cTokenBarLeftIn		{ store($1); }
			cTokensBarDot '.'
		;

numberModuleTerm1
		:	NUMERIC_ID		{ store($1); }
			numberModuleTerm2
		|	cTokenBarDotNumber	{ store($1); }
			cTokensBarDot '.'
		|	'.'			{}
		;

numberModuleTerm2
		:	']'
			{
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			}
			moduleAndTerm
		|	cTokenBarDotRight	{ store($1); }
			cTokensBarDot '.'
		|	'.'			{}
		;

/*
 *	Optional [number] or [number, number] followed by optional module
 *	expression, followed by term, followed by dot.
 *	{"[" <number> "]"} {"in" <module expression> ":"} <term> "."
 */
numbersModuleTerm
		:	'['			{ store($1); }
			numbersModuleTerm1
		|	KW_IN			{ store($1); }
			cTokensBarDotColon inEnd
		|	cTokenBarLeftIn		{ store($1); }
			cTokensBarDot '.'
		;

numbersModuleTerm1
		:	NUMERIC_ID		{ store($1); }
			numbersModuleTerm2
		|	cTokenBarDotNumber	{ store($1); }
			cTokensBarDot '.'
		|	'.'			{}
		;

numbersModuleTerm2
		:	']'
			{
			  number = Token::codeToInt64(bubble[1].code());
			  clear();
			}
			moduleAndTerm
		|	','			{ store($1); }
			numbersModuleTerm3
		|	cTokenBarDotCommaRight	{ store($1); }
			cTokensBarDot '.'
		|	'.'			{}
		;

numbersModuleTerm3
		:	NUMERIC_ID		{ store($1); }
			numbersModuleTerm4
		|	cTokenBarDotNumber	{ store($1); }
			cTokensBarDot '.'
		|	'.'			{}
		;

numbersModuleTerm4
		:	']'
			{
			  number = Token::codeToInt64(bubble[1].code());
			  number2 = Token::codeToInt64(bubble[3].code());
			  clear();
			}
			moduleAndTerm
		|	cTokenBarDotRight	{ store($1); }
			cTokensBarDot '.'
		|	'.'			{}
		;

/*
 *	Command mode token trees.
 */
cTokens		:	cTokens cToken		{ store($2); }
		|
		;

cTokensBarDot	:	cTokensBarDot cTokenBarDot	{ store($2); }
		|
		;

cTokensBarDotColon
		:	cTokensBarDotColon cTokenBarDotColon	{ store($2); }
		|
		;

/*
 *	Command mode token types.
 */
cToken		:	IDENTIFIER | NUMERIC_ID | '[' | ']' | KW_IN | ':' | '.' | ','
		|	'('			{ store($1); }
			cTokens ')'		{ $$ = $4; }
		;

cTokenBarDot	:	IDENTIFIER | NUMERIC_ID | '[' | ']' | KW_IN | ':' | ','
		|	'('			{ store($1); }
			cTokens ')'		{ $$ = $4; }
		;

cTokenBarDotColon
		:	IDENTIFIER | NUMERIC_ID | '[' | ']' | KW_IN | ','
		|	'('			{ store($1); }
			cTokens ')'		{ $$ = $4; }
		;

cTokenBarIn	:	IDENTIFIER | NUMERIC_ID | '[' | ']' | ':' | '.' | ','
		|	'('			{ store($1); }
			cTokens ')'		{ $$ = $4; }
		;

cTokenBarLeftIn	:	IDENTIFIER | NUMERIC_ID | ']' | ':' | '.' | ','
		|	'('			{ store($1); }
			cTokens ')'		{ $$ = $4; }
		;

cTokenBarDotNumber
		:	IDENTIFIER | '[' | ']' | KW_IN | ':' | ','
		|	'('			{ store($1); }
			cTokens ')'		{ $$ = $4; }
		;

cTokenBarDotRight
		:	IDENTIFIER | NUMERIC_ID | '[' | KW_IN | ':' | ','
		|	'('			{ store($1); }	
			cTokens ')'		{ $$ = $4; }
		;

cTokenBarDotCommaRight
		:	IDENTIFIER | NUMERIC_ID | '[' | KW_IN | ':'
		|	'('			{ store($1); }	
			cTokens ')'		{ $$ = $4; }
		;

/*
 *	Lists of operator names.
 */
cOpNameList	:	cOpNameList cSimpleOpName
		|	cSimpleOpName
		;

cSimpleOpName	:	cSimpleTokenBarDot
			{
			  clear();
			  store($1);
			  interpreter.addSelected(bubble);
			}
		|	'(' 			{ clear(); }
			cTokens ')'
			{
			  interpreter.addSelected(bubble);
			}
		;

cSimpleTokenBarDot
		:	IDENTIFIER | NUMERIC_ID | '[' | ']' | KW_IN | ':' | ','
		;
%%

static void
yyerror(char *s)
{
  if (!(UserLevelRewritingContext::interrupted()))
    IssueWarning(LineNumber(lineNumber) << ": " << s);
}

void
cleanUpParser()
{
  //bubble.contractTo(0);
  //moduleExpr.contractTo(0);
  //pattern.contractTo(0);
  interpreter.makeClean(lineNumber);
  /*
  if (currentModule != 0 && !(currentModule->isComplete()))
    {
      IssueAdvisory(cerr << LineNumber(lineNumber) << ": discarding incomplete module.");
      delete currentModule;
      currentModule = 0;
    }
  */
}
