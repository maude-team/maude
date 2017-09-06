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
moduleExprDot	:	moduleExpr2 '.'
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
			  IssueWarning(LineNumber($1.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar($1);
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
		|	moduleExpr2 '*' renaming
			{
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, currentRenaming));
			  currentRenaming = 0;
			}
		;

moduleExpr3	:	'(' moduleExpr ')' {}	
		|	moduleExpr3 '{'			{ clear(); }
			argList '}'
			{
			  ModuleExpression* m = moduleExpressions.top();
			  moduleExpressions.pop();
			  moduleExpressions.push(new ModuleExpression(m, bubble));
			}
		|	token
			{
			  moduleExpressions.push(new ModuleExpression($1));
			}
		;

argList		:	argList ',' token		{ store($3); }
		|	token				{ store($1); }
		;

/*
 *	Renamings.
 */
renaming	:	'('
			{
			  currentRenaming = new Renaming;
			}
			mappingList ')'
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
		|	KW_OP fromOpName fromSpec KW_TO toOpName toAttributes {}
		;

fromOpName	:	token			{ clear(); store($1); }
			tokensBarColonTo
			{
			  currentRenaming->addOpMapping(bubble);
			}
		|	'(' 			{ clear(); }
			tokens ')'
			{
			  currentRenaming->addOpMapping(bubble);
			}
		;

fromSpec	:	':' fromTypeList arrow fromType {}
		|
		;

fromTypeList	:	fromTypeList fromType
		|
		;

fromType	:	sortName
			{
			  clear();
			  bubble.append($1);
			  currentRenaming->addType(bubble);
			}
		|	'['			{ clear(); }
			sortNames ']'
			{
			  currentRenaming->addType(bubble);
			}
		;

toOpName	:	token			{ clear(); store($1); }
			tokensBarCommaLeft	{ currentRenaming->addOpTarget(bubble); }
		|	'(' 			{ clear(); }
			tokens ')'		{ currentRenaming->addOpTarget(bubble); }
		;

toAttributes	:	'[' toAttributeList ']'	{}
		|
		;

toAttributeList	:	toAttributeList toAttribute
		|	toAttribute
			;

toAttribute	:	KW_PREC IDENTIFIER	{ currentRenaming->setPrec($2); }
		|	KW_GATHER '('		{ clear(); }
			idList ')'		{ currentRenaming->setGather(bubble); }
		|	KW_FORMAT '('		{ clear(); }
			idList ')'		{ currentRenaming->setFormat(bubble); }
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
			  CV->addFrom(moduleExpressions.top());
			  moduleExpressions.pop();
			}
			KW_TO moduleExpr
			{
			  CV->addTo(moduleExpressions.top());
			  moduleExpressions.pop();
			  currentRenaming = CV;  // trick to reuse renaming fromOpName, fromSpec syntax
			}
			KW_IS viewDecList KW_ENDV
			{
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CV->finishView();
			  interpreter.insertView(($3).code(), CV);
			  currentRenaming = 0;
			}
		;

viewDecList	:	viewDecList viewDeclaration
		|
		;

viewDeclaration	:	KW_SORT sortName KW_TO sortDot
			{
			  CV->addSortMapping($2, $4);
			}
		|	KW_OP fromOpName fromSpec KW_TO	{ clear(); }
			endStatement			{ CV->addOpTarget(bubble); }
		;

sortDot		:	sortName '.'		{ $$ = $1; }
		|	ENDS_IN_DOT
			{
			  IssueWarning(LineNumber($1.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar($1);
			  $$ = t;
			}
		;

/*
 *	Modules and Theories.
 */
module		:	startModule		{ lexerIdMode(); }
			token
			{
			  interpreter.setCurrentModule(new PreModule($1, $3));
			  fileTable.beginModule($1, $3);
			}
			parameters KW_IS decList KW_ENDM
			{
			  lexerInitialMode();
			  fileTable.endModule(lineNumber);
			  CM->finishModule($8);
			}
		;

dot		:	'.' {}
		|	ENDS_IN_DOT
			{
			  IssueWarning(LineNumber($1.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar($1);
			  store(t);
			}
		;

parameters	:	'{' parameterList '}' {}
		|
		;

parameterList	:	parameterList ',' parameter
		|	parameter
		;

parameter	:	token KW_COLON2 moduleExpr
			{
			  ModuleExpression* me = moduleExpressions.top();
			  moduleExpressions.pop();
			  CM->addParameter($1, me);
			}
		;

badType		:	ENDS_IN_DOT
			{
			  IssueWarning(LineNumber($1.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar($1);
			  clear();
			  store(t);
			  CM->addType(false, bubble);
			}
		;

typeDot		:	typeName '.'
		|	badType
		;

endStatement	:	endTokens dot
		|	ENDS_IN_DOT
			{
			  IssueWarning(LineNumber($1.lineNumber()) <<
                                       ": missing space before period.");
			  Token t;
			  t.dropChar($1);
			  store(t);
			}
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
			sortNameList dot	{ CM->addSortDecl(bubble); }

		|	KW_SUBSORT		{ clear(); }
			subsortList dot		{ CM->addSubsortDecl(bubble); }

		|	KW_OP opName domainRangeAttr {}

		|	KW_OPS opNameList domainRangeAttr {}

		|	KW_VAR varNameList ':' typeDot {}

		|	KW_MB			{ clear(); store($1); }
			tokensBarColon ':'	{ store($4); }
			endStatement		{ CM->addStatement(bubble); }

		|	KW_CMB			{ clear(); store($1); }
			tokensBarColon ':'	{ store($4); }
			tokensBarIf KW_IF	{ store($7); }
			endStatement		{ CM->addStatement(bubble); }

		|	KW_EQ			{ clear(); store($1); }
			tokensBarEqual '='	{ store($4); }
			endStatement		{ CM->addStatement(bubble); }

		|	KW_CEQ			{ clear(); store($1); }
			tokensBarEqual '='	{ store($4); }
			tokensBarIf KW_IF		{ store($7); }
			endStatement		{ CM->addStatement(bubble); }

		|	KW_RL			{ clear(); store($1); }
			tokensBarArrow2 KW_ARROW2  { store($4); }
			endStatement		{ CM->addStatement(bubble); }

		|	KW_CRL			{ clear(); store($1); }
			tokensBarArrow2 KW_ARROW2	{ store($4); }
			tokensBarIf KW_IF		{ store($7); }
			endStatement		{ CM->addStatement(bubble); }

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

		|	KW_SUBCLASS		{ clear(); }
			subsortList dot		{ CM->addSubsortDecl(bubble); }

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

domainRangeAttr	:	':' typeList arrow typeAttr
			{
			  if ($3)
			    CM->convertSortsToKinds();
			}
		;

typeAttr	:	typeName attributes '.'
		|	badType
		;

arrow		:	KW_ARROW      		{ $$ = false; }
		|	KW_PARTIAL	       	{ $$ = true; }
		;

typeList	:	typeList typeName
		|
		;

typeName	:	sortName
			{
			  clear();
			  store($1);
			  CM->addType(false, bubble);
			}
		|	'['			{ clear(); }
			sortNames ']'
			{
			  CM->addType(true, bubble);
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
		|	KW_POLY '('		{ clear(); }
			idList ')'		{ CM->setPoly(bubble); }
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

tokensBarColonTo	:	tokensBarColonTo '('	{ store($2); }
				tokens ')'		{ store($5); }
			|	tokensBarColonTo tokenBarColonTo	{ store($2); }
			|
			;

tokensBarCommaLeft	:	tokensBarCommaLeft '('	{ store($2); }
				tokens ')'		{ store($5); }
			|	tokensBarCommaLeft tokenBarCommaLeft	{ store($2); }
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
		|	endTokens endsInDot	{ store($2); }
		|	endsInDot		{ store($1); }
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

tokenBarDot	:	inert | ',' | KW_TO
		|	startKeyword | midKeyword | attrKeyword
		;

endToken	:	inert | ',' | KW_TO
		|	midKeyword | attrKeyword
		;

tokenBarArrow2	:	identifier | startKeyword | attrKeyword | '.'
		|	'<' | ':' | KW_ARROW | KW_PARTIAL | '=' | KW_IF
		;

tokenBarEqual	:	identifier | startKeyword | attrKeyword | '.'
		|	'<' | ':' | KW_ARROW | KW_PARTIAL | KW_ARROW2 | KW_IF
		;

tokenBarIf	:	identifier | startKeyword | attrKeyword | '.'
		|	'<' | ':' | KW_ARROW | KW_PARTIAL | '=' | KW_ARROW2
		;

tokenBarColon	:	identifier | startKeyword | attrKeyword | '.'
		|	'<' | KW_ARROW | KW_PARTIAL | '=' | KW_ARROW2 | KW_IF
		;

tokenBarColonTo	:	inert | ENDS_IN_DOT | ','
		|	startKeyword | attrKeyword | '.'
		|	'<' | KW_ARROW | KW_PARTIAL | '=' | KW_ARROW2 | KW_IF
		;

tokenBarCommaLeft	:	inert | ENDS_IN_DOT | KW_TO
			|	startKeyword | attrKeyword2 | '.' | ']' | midKeyword
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
