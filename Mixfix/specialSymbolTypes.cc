//
//	List of all the special symbol types supported.
//
//	We generate various chunks of linear (branching) code to handle
//	this hetrogeneous collection by macro expansion.
//	The format is:
//		MACRO(HookName, SymbolBasicType)
//
  MACRO(SystemTrue, SymbolType::SYSTEM_TRUE)
  MACRO(SystemFalse, SymbolType::SYSTEM_FALSE)
  MACRO(BranchSymbol, SymbolType::BRANCH_SYMBOL)
  MACRO(EqualitySymbol, SymbolType::EQUALITY_SYMBOL)
  MACRO(FloatSymbol, SymbolType::FLOAT)
  MACRO(FloatOpSymbol, SymbolType::FLOAT_OP)
  MACRO(StringSymbol, SymbolType::STRING)
  MACRO(StringOpSymbol, SymbolType::STRING_OP)
  MACRO(QuotedIdentifierSymbol, SymbolType::QUOTED_IDENTIFIER)
  MACRO(QuotedIdentifierOpSymbol, SymbolType::QUOTED_IDENTIFIER_OP)
  MACRO(MetaLevelOpSymbol, SymbolType::META_LEVEL_OP_SYMBOL)
  MACRO(LoopSymbol, SymbolType::LOOP_SYMBOL)
  MACRO(Bubble, SymbolType::BUBBLE)
  MACRO(ModelCheckerSymbol, SymbolType::MODEL_CHECKER_SYMBOL)
  MACRO(SatSolverSymbol, SymbolType::SAT_SOLVER_SYMBOL)
  MACRO(SuccSymbol, SymbolType::SUCC_SYMBOL)
  MACRO(MinusSymbol, SymbolType::MINUS_SYMBOL)
  MACRO(NumberOpSymbol, SymbolType::NUMBER_OP_SYMBOL)
  MACRO(ACU_NumberOpSymbol, SymbolType::ACU_NUMBER_OP_SYMBOL)
  MACRO(CUI_NumberOpSymbol, SymbolType::CUI_NUMBER_OP_SYMBOL)
  MACRO(DivisionSymbol, SymbolType::DIVISION_SYMBOL)
