noinst_LIBRARIES = libModelChecker.a

libModelChecker_a_CPPFLAGS = \
	-I$(top_srcdir)/src/Utility \
	-I$(top_srcdir)/src/Interface \
	-I$(top_srcdir)/src/Core \
	-I$(top_srcdir)/src/FullCompiler \
	-I$(top_srcdir)/src/Higher \
	-I$(top_srcdir)/src/Temporal \
	-I$(top_srcdir)/src/Mixfix \
	-I$(top_srcdir)/src/SMT \
	-I$(top_srcdir)/src/StrategyLanguage \
	-I$(top_srcdir)/src/BuiltIn \
	-I$(top_srcdir)/src/Variable \
	-I$(top_srcdir)/src/S_Theory \
	-I$(top_srcdir)/src/NA_Theory \
	-I$(top_srcdir)/src/FreeTheory \
	-I$(top_srcdir)/src/CUI_Theory \
	-I$(top_srcdir)/src/AU_Theory \
	-I$(top_srcdir)/src/ACU_Theory \
	-I$(top_srcdir)/src/3rdParty


libModelChecker_a_SOURCES = \
	Utility/TermUtil.cc \
	PropTable/PropositionTable.cc \
	PropTable/ParamPropositionTable.cc \
	PropTable/ParamSubstitution.cc \
	PropChecker/PropSet.cc \
	PropChecker/PropChecker.cc \
	PropChecker/EnabledPropHandler.cc \
	PropChecker/RealizedPropGenerator.cc \
	PropChecker/ParamPropChecker.cc \
	PropChecker/ParamEnabledPropHandler.cc \
	PropChecker/PropCheckerFactory.cc \
	FairTable/CompositeFairnessTable.cc \
	FairTable/FormulaFairnessTable.cc \
	FairTable/ParamSubstitutionBuilder.cc \
	FairTable/ParamVarInfo.cc \
	FairTable/RealizedFairnessTable.cc \
	FairChecker/WeakFairnessChecker.cc \
	FairChecker/StrongFairnessChecker.cc \
	FairChecker/CompositeFairnessChecker.cc \
	FairChecker/RealizedFairnessGenerator.cc \
	FairChecker/ParamWeakFairnessChecker.cc \
	FairChecker/ParamStrongFairnessChecker.cc \
	FairChecker/FairnessCheckerFactory.cc \
	FairSet/WeakFairSet.cc \
	FairSet/StrongFairSet.cc \
	FairSet/CompositeFairSet.cc \
	FairSet/ParamRealizedSet.cc \
	FairSet/ParamWeakFairSet.cc \
	FairSet/ParamStrongFairSet.cc \
	GraphLabel/StateEventPropLabel.cc \
	GraphLabel/StateEventFairLabel.cc \
	GraphTemplate/CompactProofTermTransitionGraph.cc \
	GraphTemplate/RuleTransitionGraph.cc \
	GraphTemplate/RewriteTransitionState.cc \
	GraphTemplate/DefaultStateDagContainer.cc \
    Interface/PropInterpreter.cc \
    Interface/PropEvaluator.cc \
    Interface/FairnessDecoder.cc \
    Interface/ProofTermGenerator.cc \
    Interface/CounterExampleGenerator.cc \
    Interface/FormulaBuilder.cc \
    Symbolic/FoldingChecker.cc \
    Symbolic/PrettyPrinter.cc \
    Symbolic/StateMetaGraph.cc \
    Symbolic/InputInterpreter.cc \
    Symbolic/ConcreteResultGenerator.cc \
    ModelCheckerManager.cc \
    ltlrFairnessCheckerSymbol.cc \
    SymbolicModelCheckerSymbol.cc

noinst_HEADERS = \
	ltlrFairnessCheckerSymbol.hh \
	SymbolicModelCheckerSymbol.hh




	
