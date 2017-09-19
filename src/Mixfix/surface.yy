/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//	Parser for Maude surface syntax.
//

%{
#include <string>
#include <stack>

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

//	core class definitions
#include "lineNumber.hh"

//	front end class definitions
#include "token.hh"
#include "renaming.hh"
#include "view.hh"
#include "moduleExpression.hh"
#include "fileTable.hh"
#include "directoryManager.hh"
#include "syntacticPreModule.hh"
#include "visibleModule.hh"  // HACK
#include "userLevelRewritingContext.hh"
#include "interpreter.hh"

#include "global.hh"
#define clear()			tokenSequence.clear();
#define store(token)		tokenSequence.append(token)
#define fragClear()		fragments.contractTo(0);
#define fragStore(token)	fragments.append(token)
#define YYPARSE_PARAM	parseResult
#define PARSE_RESULT	(*((UserLevelRewritingContext::ParseResult*) parseResult))

#define CM		interpreter.getCurrentModule()
#define CV		interpreter.getCurrentView()

#include "lexerAux.hh"
/*
void lexerInitialMode();
void lexerIdMode();
void lexerCmdMode();
void lexerFileNameMode();
void lexerStringMode();
void lexerLatexMode();
bool handleEof();
bool includeFile(const string& directory, const string& fileName, bool silent, int lineNr);
//void eatComment(bool firstNonWhite);
*/
Vector<Token> singleton(1);
Vector<Token> tokenSequence;
Vector<Token> lexerBubble;
Vector<Token> fragments;
Vector<Token> moduleExpr;
Vector<Token> opDescription;
stack<ModuleExpression*> moduleExpressions;
Renaming* currentRenaming = 0;
SyntaxContainer* currentSyntaxContainer = 0;
SyntaxContainer* oldSyntaxContainer = 0;

Int64 number;
Int64 number2;

static void yyerror(char *s);

void cleanUpModuleExpression();
void cleanUpParser();
void missingSpace(const Token& token);
%}
%pure_parser

%union
{
  bool yyBool;
  Int64 yyInt64;
  const char* yyString;
  Token yyToken;
  ImportModule::ImportMode yyImportMode;
  Interpreter::Flags yyFlags;
  Interpreter::PrintFlags yyPrintFlags;
  Interpreter::SearchKind yySearchKind;
}

%{
int yylex(YYSTYPE* lvalp);
%}

%token <yyString> FILE_NAME_STRING UNINTERPRETED_STRING LATEX_STRING
/*
 *	Inert keywords: these are only recognized by lexer when in initial mode.
 */
%token <yyToken> KW_MOD KW_OMOD KW_VIEW
%token KW_PARSE KW_NORMALIZE KW_REDUCE KW_REWRITE
%token KW_LOOP KW_NARROW KW_XG_NARROW KW_MATCH KW_XMATCH KW_UNIFY
%token KW_GET KW_VARIANTS KW_VARIANT
%token KW_EREWRITE KW_FREWRITE KW_SREWRITE
%token KW_CONTINUE KW_SEARCH
%token KW_SET KW_SHOW KW_ON KW_OFF 
%token KW_TRACE KW_BODY KW_BUILTIN KW_WHOLE KW_SELECT KW_DESELECT KW_CONDITION KW_SUBSTITUTION
%token KW_PRINT KW_GRAPH KW_MIXFIX KW_FLAT KW_ATTRIBUTE KW_NEWLINE
%token KW_WITH KW_PARENS KW_ALIASES KW_GC KW_TIME KW_STATS KW_TIMING
%token KW_CMD KW_BREAKDOWN KW_BREAK KW_PATH
%token KW_MODULE KW_MODULES KW_VIEWS KW_ALL KW_SORTS KW_OPS2 KW_VARS
%token KW_MBS KW_EQS KW_RLS KW_SUMMARY KW_KINDS KW_ADVISE KW_VERBOSE
%token KW_DO KW_CLEAR
%token KW_PROTECT KW_EXTEND KW_INCLUDE KW_EXCLUDE
%token KW_CONCEAL KW_REVEAL KW_COMPILE KW_COUNT
%token KW_DEBUG KW_IRREDUNDANT KW_RESUME KW_ABORT KW_STEP KW_WHERE KW_CREDUCE KW_SREDUCE KW_DUMP KW_PROFILE
%token KW_NUMBER KW_RAT KW_COLOR
%token <yyInt64> SIMPLE_NUMBER
%token KW_PWD KW_CD KW_PUSHD KW_POPD KW_LS KW_LOAD KW_QUIT KW_EOF

/*
 *	Start keywords: signal end of mixfix statement if following '.'.
 */
%token <yyToken> KW_ENDM KW_IMPORT KW_ENDV
%token <yyToken> KW_SORT KW_SUBSORT KW_OP KW_OPS KW_MSGS KW_VAR KW_CLASS KW_SUBCLASS
%token <yyToken> KW_MB KW_CMB KW_EQ KW_CEQ KW_RL KW_CRL

/*
 *	Mid keywords: need to be recognized in the middle of mixfix syntax.
 */
%token <yyToken> KW_IS KW_FROM
%token <yyToken> KW_ARROW KW_ARROW2 KW_PARTIAL KW_IF
%type <yyToken> ':' '=' '(' ')' '.' '<' '[' ']' ',' '|'

/*
 *	Module expression keywords.
 */
%token <yyToken> KW_LABEL KW_TO KW_COLON2
%left <yyToken> '+'
%left <yyToken> '*'
%type <yyToken> '{' '}'

/*
 *	Attribute keywords need to be recognized when parsing attributes.
 */
%token <yyToken> KW_ASSOC KW_COMM KW_ID KW_IDEM KW_ITER
%token <yyToken> KW_LEFT KW_RIGHT KW_PREC KW_GATHER KW_METADATA KW_STRAT KW_POLY
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
%token <yyToken> IDENTIFIER NUMERIC_ID ENDS_IN_DOT

/*
 *	This is a dummy token that is never passed by the lexer but by
 *	giving this as an alternative we force the parser to lookahead
 *	one token and allow the lexer to grab a bubble.
 */
%token FORCE_LOOKAHEAD

/*
 *	Nonterminals that return tokens.
 */
%type <yyToken> identifier inert startKeyword startKeyword2 midKeyword attrKeyword attrKeyword2
%type <yyToken> token endsInDot badType
%type <yyToken> tokenBarColon
%type <yyToken> tokenBarDot
%type <yyToken> cTokenBarIn
%type <yyToken> cTokenBarLeftIn cTokenBarDotNumber cTokenBarDotRight
%type <yyToken> cSimpleTokenBarDot
%type <yyToken> cTokenBarDotCommaRight cTokenBarDotCommaNumber
%type <yyToken> sortName sortToken startModule sortDot

/*
 *	Nonterminals that return Interpreter::SearchKind.
 */
%type <yySearchKind> search
/*
 *	Nonterminals that return bool.
 */
%type <yyBool> polarity select match optDebug optIrredundant conceal exclude arrow
/*
 *	Nonterminals that return int.
 */
%type <yyInt64> optNumber
/*
 *	Nonterminals that return ImportMode.
 */
%type <yyImportMode> importMode
/*
 *	Nonterminals that return Flags.
 */
%type <yyFlags> traceOption
/*
 *	Nonterminals that return PrintFlags.
 */
%type <yyPrintFlags> printOption

%start top

%%

top		:	item { YYACCEPT; }
		|
			{
			  PARSE_RESULT = UserLevelRewritingContext::QUIT;
			}
		;

item		:	module
		|	view
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
			  //eatComment(false); // eat \n so that line number is correct
			  string directory;
			  string fileName;
			  if (findFile($3, directory, fileName, lineNr))
			    includeFile(directory, fileName, false, lineNr);
			}
		|	KW_LOAD		{ lexerFileNameMode(); }
			FILE_NAME_STRING
			{
			  int lineNr = lineNumber;
			  //eatComment(false); // eat \n so that line number is correct
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

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

/*
 *	Module expressions.
 */
moduleExprDot	:	tokenBarDot expectedDot
                        {
                          moduleExpressions.push(new ModuleExpression($1));
                        }
		|	endsInDot '.'
                        {
                          moduleExpressions.push(new ModuleExpression($1));
                        }
		|	parenExpr expectedDot
		|	renameExpr expectedDot
		|	instantExpr expectedDot
		|	moduleExpr '+' moduleExprDot
			{
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			}
		|	ENDS_IN_DOT
			{
			  Token t;
			  t.dropChar($1);
			  missingSpace(t);
			  moduleExpressions.push(new ModuleExpression(t));
			}
		;

moduleExpr	:	moduleExpr2
		|	moduleExpr '+' moduleExpr
			{
			  ModuleExpression* m1 = moduleExpressions.top();
			  moduleExpressions.pop();
			  ModuleExpression* m2 = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m1, m2));
			}
		;

moduleExpr2	:	moduleExpr3
		|	renameExpr
		;

moduleExpr3	:	parenExpr
		|	instantExpr
		|	token
		        {
                          moduleExpressions.push(new ModuleExpression($1));
                        }

		;
		
renameExpr	:	moduleExpr2 '*' renaming
			{
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			}
		;

instantExpr	:	moduleExpr3 '{'			{ clear(); }
			argList '}'
			{
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, tokenSequence));
			}
		;

parenExpr	:	'(' moduleExpr ')' {}
		;

argList		:	argList ',' token		{ store($3); }
		|	token				{ store($1); }
		;

/*
 *	Renamings.
 */
renaming	:	'('
			{
			  oldSyntaxContainer = currentSyntaxContainer;
			  currentSyntaxContainer = currentRenaming = new Renaming;
			}
			renaming2  /* must succeed so we can restore currentSyntaxContainer */
			{
			  currentSyntaxContainer = oldSyntaxContainer;
			}
			')'
		;

renaming2	:	mappingList
		|	error
		;

mappingList	:	mappingList ',' mapping
		|	mapping
		;

mapping		:	KW_SORT sortName KW_TO sortName
			{
			  currentRenaming->addSortMapping($2, $4);
			}
		|	KW_LABEL token KW_TO token
			{
			  currentRenaming->addLabelMapping($2, $4);
			}
		|	KW_OP 			{ lexBubble(BAR_COLON | BAR_TO, 1); }
			fromSpec KW_TO		{ lexBubble(BAR_COMMA | BAR_LEFT_BRACKET | BAR_RIGHT_PAREN, 1); }
			toAttributes		{}
		;
/*
 *	The ':' alternative forces lookahead which allows the lexer to grab the bubble.
 */
fromSpec	:	':'			{ Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
			typeList arrow typeName {}
		|				{ Token::peelParens(lexerBubble); currentRenaming->addOpMapping(lexerBubble); }
		;

/*
 *	The '[' alternative forces lookahead which allows the lexer to grab the bubble.
 */
toAttributes	:	'['			{ Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
			toAttributeList ']'	{}
		|				{ Token::peelParens(lexerBubble); currentRenaming->addOpTarget(lexerBubble); }
		;

toAttributeList	:	toAttributeList toAttribute
		|	toAttribute
		;

toAttribute	:	KW_PREC IDENTIFIER	{ currentRenaming->setPrec($2); }
		|	KW_GATHER '('		{ clear(); }
			idList ')'		{ currentRenaming->setGather(tokenSequence); }
		|	KW_FORMAT '('		{ clear(); }
			idList ')'		{ currentRenaming->setFormat(tokenSequence); }
		|	KW_LATEX '('		{ lexerLatexMode(); }
			LATEX_STRING ')'	{ currentRenaming->setLatexMacro($4); }
		;

/*
 *	Views.
 */
view		:	KW_VIEW			{ lexerIdMode(); }
			token KW_FROM moduleExpr
			{
			  fileTable.beginModule($1, $3);
			  interpreter.setCurrentView(new View($3));
			  currentSyntaxContainer = CV;
			  CV->addFrom(moduleExpressions.top());
			  moduleExpressions.pop();
			}
			KW_TO moduleExpr
			{
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			}
			expectedIs viewDecList KW_ENDV
			{
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  interpreter.insertView(($3).code(), CV);
			  CV->finishView();
			}
		;

viewDecList	:	viewDecList viewDeclaration
		|
		;

skipStrayArrow	:	KW_ARROW
			{
			  IssueWarning(LineNumber($1.lineNumber()) <<
				       ": skipping " << QUOTE("->") << " in variable declaration.");
			}
		|
		;

viewDeclaration	:	KW_SORT sortName KW_TO sortDot
			{
			  CV->addSortMapping($2, $4);
			}
		|	KW_VAR varNameList ':' skipStrayArrow typeDot {}
		|	KW_OP			{ lexBubble(BAR_COLON | BAR_TO, 1); }
			viewEndOpMap
		|	error '.'
		;

sortDot		:	sortName expectedDot		{ $$ = $1; }
		|	ENDS_IN_DOT
			{
			  Token t;
			  t.dropChar($1);
			  missingSpace(t);
			  $$ = t;
			}
		;

viewEndOpMap	:	':'
			{
			  //
			  //	Specific op->op mapping.
			  //
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpMapping(lexerBubble);
			}
			typeList arrow typeName KW_TO
			{
			  lexBubble(END_STATEMENT, 1);
			}
			endBubble
			{
			  Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			  CV->addOpTarget(lexerBubble);
			}
		|	KW_TO
			{
			  //
			  //	At this point we don't know if we have an op->term mapping
			  //	or a generic op->op mapping so we save the from description and
			  //	press on.
			  //
			  opDescription = lexerBubble;
			  lexBubble(END_STATEMENT, 1);
			}
			endBubble
			{
			  if (lexerBubble[0].code() == Token::encode("term"))
			    {
			      //
			      //	Op->term mapping.
			      //
			      CV->addOpTermMapping(opDescription, lexerBubble);
			    }
			  else
			    {
			      //
			      //	Generic op->op mapping.
			      //
			      Token::peelParens(opDescription);  // remove any enclosing parens from op name
			      CV->addOpMapping(opDescription);
			      Token::peelParens(lexerBubble);  // remove any enclosing parens from op name
			      CV->addOpTarget(lexerBubble);
			    }
			}
		;


endBubble	:	'.' {}
		|	ENDS_IN_DOT
			{
			  Token t;
			  t.dropChar($1);
			  missingSpace(t);
			  lexerBubble.append(t);
			}
		;

parenBubble	:	'(' 			{ lexBubble(BAR_RIGHT_PAREN, 1); }
			')'			{}
		;

/*
 *	Modules and theories.
 */
module		:	startModule		{ lexerIdMode(); }
			token
			{
			  interpreter.setCurrentModule(new SyntacticPreModule($1, $3));
			  currentSyntaxContainer = CM;
			  fileTable.beginModule($1, $3);
			}
			parameters expectedIs decList KW_ENDM
			{
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule($8);
			}
		;

dot		:	'.' {}
		|	ENDS_IN_DOT
			{
			  Token t;
			  t.dropChar($1);
			  missingSpace(t);
			  store(t);
			}
		;

parameters	:	'{' parameterList '}' {}
		|
		;

parameterList	:	parameterList ',' parameter
		|	parameter
		;

parameter	:	token colon2 moduleExpr
			{
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter($1, me);
			}
		;

colon2		:	KW_COLON2 {}
		|	':'
			{
			  IssueWarning(LineNumber($1.lineNumber()) <<
			    ": saw " << QUOTE(':') << " instead of " <<
			    QUOTE("::") << " in parameter declaration.");
			}
		;

badType		:	ENDS_IN_DOT
			{
			  singleton[0].dropChar($1);
			  missingSpace(singleton[0]);
			  currentSyntaxContainer->addType(false, singleton);
			  $$ = $1;  // needed for line number
			}
		;

typeDot		:	typeName expectedDot
		|	badType {}
		;

startModule	:	KW_MOD | KW_OMOD
		;

decList		:	decList declaration
		|
		;

declaration	:	KW_IMPORT moduleExprDot
			{
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addImport($1, me);
			}

		|	KW_SORT			{ clear(); }
			sortNameList dot	{ CM->addSortDecl(tokenSequence); }

		|	KW_SUBSORT		{ clear(); }
			subsortList dot		{ CM->addSubsortDecl(tokenSequence); }

		|	KW_OP			{ lexBubble(BAR_COLON, 1); }
			':'			{ Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
			domainRangeAttr		{}

		|	KW_OPS opNameList ':' domainRangeAttr {}

		|	KW_VAR varNameList ':' skipStrayArrow typeDot {}

		|	KW_MB			{ lexBubble($1, BAR_COLON, 1); }
			':'			{ lexContinueBubble($3, END_STATEMENT, 1); }
			endBubble	       	{ CM->addStatement(lexerBubble); }

		|	KW_CMB			{ lexBubble($1, BAR_COLON, 1);  }
			':'			{ lexContinueBubble($3, BAR_IF, 1); }
			KW_IF			{ lexContinueBubble($5, END_STATEMENT, 1); }
			endBubble		{ CM->addStatement(lexerBubble); }

		|	KW_EQ			{ lexBubble($1, BAR_EQUALS, 1); }
			'='			{ lexContinueBubble($3, END_STATEMENT, 1); }
			endBubble	  	{ CM->addStatement(lexerBubble); }

		|	KW_CEQ			{ lexBubble($1, BAR_EQUALS, 1); }
			'='			{ lexContinueBubble($3, BAR_IF, 1); }
			KW_IF			{ lexContinueBubble($5, END_STATEMENT, 1); }
			endBubble	  	{ CM->addStatement(lexerBubble); }

		|	KW_RL			{ lexBubble($1, BAR_ARROW2, 1); }
			KW_ARROW2		{ lexContinueBubble($3, END_STATEMENT, 1); }
			endBubble		{ CM->addStatement(lexerBubble); }

		|	KW_CRL			{ lexBubble($1, BAR_ARROW2, 1); }
			KW_ARROW2		{ lexContinueBubble($3, BAR_IF, 1); }
			KW_IF			{ lexContinueBubble($5, END_STATEMENT, 1); }
			endBubble	    	{ CM->addStatement(lexerBubble); }

		|	KW_MSG			{ lexBubble(BAR_COLON, 1); }
			':'			{ Token::peelParens(lexerBubble); CM->addOpDecl(lexerBubble); }
			domainRangeAttr		{ CM->setFlag(SymbolType::MESSAGE); }

		|	KW_MSGS opNameList ':' domainRangeAttr
			{
			  CM->setFlag(SymbolType::MESSAGE);
			}

		|	KW_CLASS token
			{
			}
			classDef '.'
			{
			}

		|	KW_SUBCLASS		{ clear(); }
			subsortList dot		{ CM->addSubsortDecl(tokenSequence); }

		|	error '.'
		        {
			  //
			  //	Fix things that might be in a bad state due
			  //	to a partially processed declaration.
			  //
			  cleanUpModuleExpression();
			  CM->makeOpDeclsConsistent();
			}
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

varNameList	:	varNameList tokenBarColon	{ currentSyntaxContainer->addVarDecl($2); }
		|	tokenBarColon			{ currentSyntaxContainer->addVarDecl($1); }
		;

opNameList	:	opNameList simpleOpName
		|	simpleOpName
		;

simpleOpName	:	tokenBarColon		{ singleton[0] = $1; CM->addOpDecl(singleton); }
		|	parenBubble		{ CM->addOpDecl(lexerBubble); }
		;

domainRangeAttr	:	typeName typeList dra2
		|	rangeAttr
		|	badType
			{
			  IssueWarning(LineNumber(lineNumber) <<
				       ": missing " << QUOTE("->") << " in constant declaration.");
			}
		;

skipStrayColon 	:	':'
			{
			  IssueWarning(LineNumber($1.lineNumber()) <<
				       ": skipping stray " << QUOTE(":") << " in operator declaration.");

			}
		|
		;

dra2		:	skipStrayColon rangeAttr
		|	'.'
			{
			  IssueWarning(LineNumber($1.lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
		|	badType
			{
			  IssueWarning(LineNumber($1.lineNumber()) <<
			  ": missing " << QUOTE("->") << " in operator declaration.");
			}
		;

rangeAttr	:	arrow typeAttr
			{
			  if ($1)
			    CM->convertSortsToKinds();
			}
		;

typeAttr	:	typeName attributes expectedDot
		|	badType {}
		;

arrow		:	KW_ARROW      		{ $$ = false; }
		|	KW_PARTIAL	       	{ $$ = true; }
		;

typeList	:	typeList typeName
		|
		;

typeName	:	sortName
			{
			  singleton[0] = $1;
			  currentSyntaxContainer->addType(false, singleton);
			}
		|	'['			{ clear(); }
			sortNames ']'
			{
			  currentSyntaxContainer->addType(true, tokenSequence);
			}
		;

sortNames	:	sortNames ',' sortName		{ store($3); }
		|	sortName			{ store($1); }
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
		|	idKeyword		{ lexBubble(BAR_RIGHT_BRACKET | BAR_OP_ATTRIBUTE, 1); }
			identity		{ CM->setIdentity(lexerBubble); }
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
			idList ')'		{ CM->setGather(tokenSequence); }
		|	KW_FORMAT '('		{ clear(); }
			idList ')'		{ CM->setFormat(tokenSequence); }
		|	KW_STRAT '('		{ clear(); }
			idList ')'		{ CM->setStrat(tokenSequence); }
		|	KW_POLY '('		{ clear(); }
			idList ')'		{ CM->setPoly(tokenSequence); }
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
			  CM->setFrozen(tokenSequence);
			}
		|	KW_FROZEN '('		{ clear(); }
			idList ')'		{ CM->setFrozen(tokenSequence); }
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
		|	KW_METADATA IDENTIFIER
			{
			  CM->setMetadata($2);
			}
		|	KW_LATEX '('		{ lexerLatexMode(); }
			LATEX_STRING ')'	{ CM->setLatexMacro($4); }
		|	KW_SPECIAL '(' hookList ')'	{}
		|	KW_DITTO
			{
			  CM->setFlag(SymbolType::DITTO);
			}
		;

/*
 *	The ony point of this rule is to force a one token lookahead and allow the lexer to grab the
 *	bubble corresponding to the identity. We never see a FORCE_LOOKAHEAD token.
 */
identity	:	FORCE_LOOKAHEAD
		|
		;

idList		:	idList IDENTIFIER	{ store($2); }
		|	IDENTIFIER		{ store($1); }
		;

hookList	:	hookList hook
		|	hook
		;

hook		:	KW_ID_HOOK token		{ clear(); CM->addHook(SyntacticPreModule::ID_HOOK, $2, tokenSequence); }
		|	KW_ID_HOOK token parenBubble	{ CM->addHook(SyntacticPreModule::ID_HOOK, $2, lexerBubble); }
		|	KW_OP_HOOK token parenBubble	{ CM->addHook(SyntacticPreModule::OP_HOOK, $2, lexerBubble); }
		|	KW_TERM_HOOK token parenBubble	{ CM->addHook(SyntacticPreModule::TERM_HOOK, $2, lexerBubble); }
		;

/*
 *	Recovery from missing tokens
 */
expectedIs	:	KW_IS {}
		|
			{
			  IssueWarning(LineNumber(lineNumber) << ": missing " <<
				       QUOTE("is") << " keyword.");
			}
		;

expectedDot	:	'.' {}
		|
			{
			  IssueWarning(LineNumber(lineNumber) << ": missing period.");
			}
		;

/*
 *	Sort and subsort lists.
 */
sortNameList	:	sortNameList sortName	{ store($2); }
		|
		;

subsortList	:	subsortList sortName	{ store($2); }
		|	subsortList '<'		{ store($2); }
		|	sortName		{ store($1); }
			sortNameList '<'	{ store($4); }
		;

/*
 *	Sort names
 */
sortName	:	sortNameFrag
			{
			  Token t;
			  if (fragments.size() == 1)
			    t = fragments[0];
			  else
			    t.tokenize(Token::bubbleToPrefixNameCode(fragments), fragments[0].lineNumber());
			  fragClear();
			  $$ = t;
			}
		;

sortNameFrag	:	sortToken		{ fragStore($1); }
		|	sortNameFrag '{'	{ fragStore($2); }
			sortNameFrags '}'	{ fragStore($5); }
		;

sortNameFrags	:	sortNameFrags ','	{ fragStore($2); }
			sortNameFrag		{}
		|	sortNameFrag		{}
		;

/*
 *	Token types.
 */
token		:	identifier | startKeyword | midKeyword | attrKeyword | '.'
		;

tokenBarDot	:	inert | ',' | KW_TO
		|	startKeyword | midKeyword | attrKeyword
		;

tokenBarColon	:	identifier | startKeyword | attrKeyword | '.'
		|	'<' | KW_ARROW | KW_PARTIAL | '=' | KW_ARROW2 | KW_IF
		;

sortToken	:	IDENTIFIER | startKeyword | attrKeyword2
		|	'=' | '|' | '+' | '*'
		|	KW_ARROW2 | KW_IF | KW_IS | KW_LABEL | KW_TO
		;

endsInDot	:	'.' | ENDS_IN_DOT
		;

/*
 *	Keywords (in id mode).
 */
inert		:	IDENTIFIER | '{' | '}' | '+' | '*' | '|' | KW_COLON2 | KW_LABEL
		|	KW_FROM | KW_IS
		;

identifier	:	inert | ENDS_IN_DOT | ',' | KW_TO
		;

startKeyword	:	KW_MSG | startKeyword2
		;

startKeyword2	:	KW_IMPORT | KW_SORT | KW_SUBSORT | KW_OP | KW_OPS | KW_VAR
		|	KW_MSGS | KW_CLASS | KW_SUBCLASS
		|	KW_MB | KW_CMB | KW_EQ | KW_CEQ | KW_RL | KW_CRL | KW_ENDM | KW_ENDV
		;

midKeyword	:	'<' | ':' | KW_ARROW | KW_PARTIAL | '=' | KW_ARROW2 | KW_IF
		;

attrKeyword	:	'[' | ']' | attrKeyword2
		;

attrKeyword2	:	KW_ASSOC | KW_COMM | KW_ID | KW_IDEM | KW_ITER | KW_LEFT | KW_RIGHT
		|	KW_PREC | KW_GATHER | KW_STRAT | KW_POLY | KW_MEMO | KW_CTOR
		|	KW_LATEX | KW_SPECIAL | KW_FROZEN | KW_METADATA
		|	KW_CONFIG | KW_OBJ | KW_DITTO | KW_FORMAT
		|	KW_ID_HOOK | KW_OP_HOOK | KW_TERM_HOOK
		;
/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

/*
 *	Commands.
 */
command		:	KW_SELECT		{ lexBubble(END_COMMAND, 1); }
			endBubble
			{
			  interpreter.setCurrentModule(lexerBubble);
			}
		|	KW_DUMP			{ lexBubble(END_COMMAND, 1); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->dump();
			}
		|	KW_PARSE
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.parse(lexerBubble);
			}

		|	KW_CREDUCE
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.creduce(lexerBubble);
			}

		|	KW_SREDUCE
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sreduce(lexerBubble);
			}

		|	optDebug KW_REDUCE
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.reduce(lexerBubble, $1);
			}

		|	optDebug KW_REWRITE
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.rewrite(lexerBubble, number, $1);
			}
		|	optDebug KW_EREWRITE
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
			numbersModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.eRewrite(lexerBubble, number, number2, $1);
			}
		|	optDebug KW_FREWRITE
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
			numbersModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.fRewrite(lexerBubble, number, number2, $1);
			}
		|	optDebug KW_SREWRITE
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.sRewrite(lexerBubble, number, $1);
			}
		|	search
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			  number2 = NONE;
			}
			numbersModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.search(lexerBubble, number, number2, $1);
			}
		|	match
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.match(lexerBubble, $1, number);
			}
		|	KW_UNIFY
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.unify(lexerBubble, number);
			}
		|	optDebug KW_VARIANT KW_UNIFY
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.variantUnify(lexerBubble, number, $1);
			}

		|	optDebug KW_GET optIrredundant KW_VARIANTS
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			  number = NONE;
			}
			numberModuleTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.getVariants(lexerBubble, number, $3, $1);
			}
		|	optDebug KW_CONTINUE optNumber '.'
			{
			  interpreter.cont($3, $1);
			}
		|	KW_LOOP
			{
			  lexerCmdMode();
			  moduleExpr.contractTo(0);
			}
			moduleAndTerm
			{
			  lexerInitialMode();
			  if (interpreter.setCurrentModule(moduleExpr, 1))
			    interpreter.loop(lexerBubble);
			}
		|	parenBubble
			{
			  moduleExpr.contractTo(0);
			  if (interpreter.setCurrentModule(moduleExpr))  // HACK
			    interpreter.contLoop(lexerBubble);
			}
		|	KW_TRACE select		{ lexerCmdMode(); }
			opSelect
			{
			  lexerInitialMode();
			  interpreter.traceSelect($2);
			}
		|	KW_TRACE exclude		{ lexerCmdMode(); }
			opSelect
			{
			  lexerInitialMode();
			  interpreter.traceExclude($2);
			}
		|	KW_BREAK select		{ lexerCmdMode(); }
			opSelect
			{
			  lexerInitialMode();
			  interpreter.breakSelect($2);
			}
		|	KW_PRINT conceal		{ lexerCmdMode(); }
			opSelect
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
		|	KW_SHOW KW_MOD		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
		|	KW_SHOW KW_MODULE	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    CM->showModule();
			}
		|	KW_SHOW KW_ALL		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showModule(true);
			}
		|	KW_SHOW KW_VIEW		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentView(lexerBubble))
			    interpreter.showView();
			}
		|	KW_SHOW KW_MODULES '.'
			{
			  interpreter.showModules(true);
			}
		|	KW_SHOW KW_VIEWS '.'
			{
			  interpreter.showNamedViews();
			}
		|	KW_SHOW KW_SORTS	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSortsAndSubsorts();
			}
		|	KW_SHOW KW_OPS2		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showOps();
			}
		|	KW_SHOW KW_VARS		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showVars();
			}
		|	KW_SHOW KW_MBS		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showMbs();
			}
		|	KW_SHOW KW_EQS		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showEqs();
			}
		|	KW_SHOW KW_RLS		{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showRls();
			}
		|	KW_SHOW KW_SUMMARY	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showSummary();
			}
		|	KW_SHOW KW_KINDS	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showKinds();
			}
		|	KW_SHOW KW_PATH SIMPLE_NUMBER '.'
			{
			  interpreter.showSearchPath($3);
			}
		|	KW_SHOW KW_PATH KW_LABEL SIMPLE_NUMBER '.'
			{
			  interpreter.showSearchPathLabels($4);
			}
		|	KW_SHOW KW_SEARCH KW_GRAPH '.'
			{
			  interpreter.showSearchGraph();
			}
		|	KW_SHOW KW_PROFILE	{ lexBubble(END_COMMAND, 0); }
			endBubble
			{
			  if (interpreter.setCurrentModule(lexerBubble))
			    interpreter.showProfile();
			}
/*
 *	Commands to set interpreter state variables.
 */
		|	KW_SET KW_SHOW KW_ADVISE polarity '.'
			{
			  globalAdvisoryFlag = alwaysAdviseFlag ? true : $4;
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
		|	KW_SET KW_PRINT printOption polarity '.'
			{
			  interpreter.setPrintFlag($3, $4);
			}
		|	KW_SET KW_PRINT KW_ATTRIBUTE polarity '.'
			{
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE, $4);
			}
		|	KW_SET KW_PRINT KW_ATTRIBUTE KW_NEWLINE polarity '.'
			{
			  interpreter.setFlag(Interpreter::PRINT_ATTRIBUTE_NEWLINE, $5);
			}
		|	KW_SET KW_TRACE traceOption polarity '.'
			{
			  interpreter.setFlag($3, $4);
			}
		|	KW_SET KW_BREAK polarity '.'
			{
			  interpreter.setFlag(Interpreter::BREAK, $3);
			}
		|	KW_SET importMode		{ lexerCmdMode(); }
			cSimpleTokenBarDot		{ lexerInitialMode(); }
			polarity '.'
			{
			  interpreter.setAutoImport($2, $4, $6);
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
		|	KW_SET KW_CLEAR KW_RLS polarity '.'
			{
			  interpreter.setFlag(Interpreter::AUTO_CLEAR_RULES, $4);
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
printOption	:	KW_MIXFIX		{ $$ = Interpreter::PRINT_MIXFIX; }
		|	KW_FLAT			{ $$ = Interpreter::PRINT_FLAT; }
		|	KW_WITH KW_ALIASES	{ $$ = Interpreter::PRINT_WITH_ALIASES; }
		|	KW_WITH KW_PARENS	{ $$ = Interpreter::PRINT_WITH_PARENS; }
		|	KW_GRAPH		{ $$ = Interpreter::PRINT_GRAPH; }
		|	KW_CONCEAL		{ $$ = Interpreter::PRINT_CONCEAL; }
		|	KW_NUMBER		{ $$ = Interpreter::PRINT_NUMBER; }
		|	KW_RAT			{ $$ = Interpreter::PRINT_RAT; }
		|	KW_COLOR		{ $$ = Interpreter::PRINT_COLOR; }
		|	KW_FORMAT		{ $$ = Interpreter::PRINT_FORMAT; }
		;

traceOption	:				{ $$ = Interpreter::TRACE; }
		|	KW_CONDITION		{ $$ = Interpreter::TRACE_CONDITION; }
		|	KW_WHOLE		{ $$ = Interpreter::TRACE_WHOLE; }
		|	KW_SUBSTITUTION		{ $$ = Interpreter::TRACE_SUBSTITUTION; }
		|	KW_SELECT		{ $$ = Interpreter::TRACE_SELECT; }
		|	KW_MBS			{ $$ = Interpreter::TRACE_MB; }
		|	KW_EQS			{ $$ = Interpreter::TRACE_EQ; }
		|	KW_RLS			{ $$ = Interpreter::TRACE_RL; }
		|	KW_REWRITE		{ $$ = Interpreter::TRACE_REWRITE; }
		|	KW_BODY			{ $$ = Interpreter::TRACE_BODY; }
		|	KW_BUILTIN		{ $$ = Interpreter::TRACE_BUILTIN; }
		;

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
/*
 *	Return true if we should do a narrowing search.
 */
search		:	KW_NARROW		{ $$ = Interpreter::NARROW; }
		|	KW_XG_NARROW		{ $$ = Interpreter::XG_NARROW; }
		|	KW_SEARCH		{ $$ = Interpreter::SEARCH; }
		;

match		:	KW_XMATCH		{ $$ = true; }
		|	KW_MATCH		{ $$ = false; }
		;

optDebug       	:	KW_DEBUG 	       	{ $$ = true; }
		|	       			{ $$ = false; }
		;

optIrredundant	:	KW_IRREDUNDANT		{ $$ = true; }
		|	       			{ $$ = false; }
		;

optNumber	:	SIMPLE_NUMBER	        { $$ = $1; }
		|				{ $$ = NONE; }
		;

importMode	:	KW_PROTECT		{ $$ = ImportModule::PROTECTING; }
		|	KW_EXTEND		{ $$ = ImportModule::EXTENDING; }
		|	KW_INCLUDE		{ $$ = ImportModule::INCLUDING; }
		;
/*
 *	Optional module expression followed by term followed by dot.
 *	{"in" <module expression> ":"} <term> "."
 *	<module expression> is a (possibly empty) bubble not containing ':' or '.'
 *	<term> is a (non-empty) bubble not containing '.' except as first token
 */

moduleAndTerm	:	initialEndBubble
		|	cTokenBarIn		{ lexBubble($1, END_COMMAND, 0); }
			endBubble
		;

inEnd		:	':'			{ moduleExpr = lexerBubble; lexBubble(END_COMMAND, 1); }
			endBubble
		|	endBubble
		;

/*
 *	Optional [number] followed by optional module expression, followed
 *	by term, followed by dot.
 *	{"[" <number> "]"} {"in" <module expression> ":"} <term> "."
 */

numberModuleTerm
		:	'['			{ lexSave($1); }
			numberModuleTerm1
		|	initialEndBubble
		|	cTokenBarLeftIn		{ lexBubble($1, END_COMMAND, 0);  }
			endBubble
		;

numberModuleTerm1
		:	NUMERIC_ID		{ lexContinueSave($1); }
			numberModuleTerm2
		|	cTokenBarDotNumber	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

numberModuleTerm2
		:	']'			{ number = Token::codeToInt64(lexerBubble[1].code()); }
			moduleAndTerm
		|	cTokenBarDotRight	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Optional [number],  [, number] or [number, number] followed by optional
 *	module expression, followed by term, followed by dot.
 *	{"[" { {<number>} , } <number> "]"} {"in" <module expression> ":"} <term> "."
 */

/*
 *	Seen <command>; looking for "[", "in", or start of term.
 */
numbersModuleTerm
		:	'['			{ lexSave($1); }
			numbersModuleTerm1
		|	initialEndBubble
		|	cTokenBarLeftIn		{ lexBubble($1, END_COMMAND, 0); }
			endBubble
		;

/*
 *	Seen <command> "["; looking for <number>, ",", continuation of
 *	term or "." to end command.
 */
numbersModuleTerm1
		:	NUMERIC_ID		{ lexContinueSave($1); }
			numbersModuleTerm2
		|	','			{ lexContinueSave($1); }
			numbersModuleTerm5
		|	cTokenBarDotCommaNumber	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" <number>; looking for "]", ",",
 *	continuation of term or "." to end command.
 */
numbersModuleTerm2
		:	']'			{ number = Token::codeToInt64(lexerBubble[1].code()); }
			moduleAndTerm
		|	','			{ lexContinueSave($1); }
			numbersModuleTerm3
		|	cTokenBarDotCommaRight	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" <number> ","; looking for <number>,
 *	continuation of term or "." to end command.
 */
numbersModuleTerm3
		:	NUMERIC_ID		{ lexContinueSave($1); }
			numbersModuleTerm4
		|	cTokenBarDotNumber	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" <number> "," <number>; looking for "]",
 *	continuation of term or "." to end command.
 */
numbersModuleTerm4
		:	']'
			{
			  number = Token::codeToInt64(lexerBubble[1].code());
			  number2 = Token::codeToInt64(lexerBubble[3].code());
			  clear();
			}
			moduleAndTerm
		|	cTokenBarDotRight	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" ","; looking for <number>, continuation of
 *	term or "." to end command. 
 */
numbersModuleTerm5
		:	NUMERIC_ID		{ lexContinueSave($1); }
			numbersModuleTerm6
		|	cTokenBarDotNumber	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

/*
 *	Seen <command> "[" "," <number>; looking for "]", continuation
 *	of term or "." to end command. 
 */
numbersModuleTerm6
		:	']'			{ number2 = Token::codeToInt64(lexerBubble[2].code()); }
			moduleAndTerm
		|	cTokenBarDotRight	{ lexContinueBubble($1, END_COMMAND, 0); }
			endBubble
		|	miscEndBubble
		;

miscEndBubble	:	'('			{ lexContinueBubble($1, END_COMMAND, 0, 1); }
			endBubble
		|	endBubble
		;

initialEndBubble
		:	'('			{ lexBubble($1, END_COMMAND, 1, 1); }
			endBubble
		|	KW_IN			{ lexBubble($1, BAR_COLON | END_COMMAND, 0); }
			inEnd
		|	ENDS_IN_DOT
			{
			  lexerBubble.resize(1);
			  lexerBubble[0].dropChar($1);
			  missingSpace(lexerBubble[0]);
			}
		;

/*
 *	Command mode token types.
 */
cTokenBarIn	:	IDENTIFIER | NUMERIC_ID | '[' | ']' | ':' | '.' | ','
		;

cTokenBarLeftIn	:	IDENTIFIER | NUMERIC_ID | ']' | ':' | '.' | ','
		;

cTokenBarDotNumber
		:	IDENTIFIER | '[' | ']' | KW_IN | ':' | ','
		;

cTokenBarDotRight
		:	IDENTIFIER | NUMERIC_ID | '[' | KW_IN | ':' | ','
		;

cTokenBarDotCommaNumber
		:	IDENTIFIER | '[' | ']' | KW_IN | ':'
		;

cTokenBarDotCommaRight
		:	IDENTIFIER | NUMERIC_ID | '[' | KW_IN | ':'
		;

/*
 *	Selections are lists of operator names.
 */
opSelect	:	cOpNameList endSelect
		|	badSelect
		;

endSelect	:	'.'		{}
		|	badSelect
		;

badSelect	:	ENDS_IN_DOT
			{
			  singleton[0].dropChar($1);
			  missingSpace(singleton[0]);
			  interpreter.addSelected(singleton);
			}

cOpNameList	:	cOpNameList cSimpleOpName
		|	cSimpleOpName
		;

cSimpleOpName	:	cSimpleTokenBarDot
			{
			  singleton[0] = $1;
			  interpreter.addSelected(singleton);
			}
		|	parenBubble
			{
			  interpreter.addSelected(lexerBubble);
			}
		;

cSimpleTokenBarDot
		:	IDENTIFIER | NUMERIC_ID | '[' | ']' | KW_IN | ':' | ','
		;
/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

%%

static void
yyerror(char *s)
{
  if (!(UserLevelRewritingContext::interrupted()))
    IssueWarning(LineNumber(lineNumber) << ": " << s);
}

void
cleanUpModuleExpression()
{
  //
  //	Delete pieces of a partly built module expression.
  //
  delete currentRenaming;
  currentRenaming = 0;
  while (!moduleExpressions.empty())
    {
      moduleExpressions.top()->deepSelfDestruct();
      moduleExpressions.pop();
    }
}

void
cleanUpParser()
{
  interpreter.makeClean(lineNumber);
}

void
missingSpace(const Token& token)
{
  IssueWarning(LineNumber(token.lineNumber()) << ": missing space between " <<
	       QUOTE(token) << " and period.");
}
