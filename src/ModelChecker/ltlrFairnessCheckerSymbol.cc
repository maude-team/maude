

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "temporal.hh"
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "builtIn.hh"
#include "higher.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

// interface class definitions
#include "symbol.hh"
#include "dagNodeSet.hh"
#include "term.hh"

// core class definitions
#include "dagArgumentIterator.hh"
#include "rewritingContext.hh"
#include "symbolMap.hh"
#include "rule.hh"
#include "rewriteSequenceSearch.hh"

// free theory class definitions
#include "freeDagNode.hh"

// built in class definitions
#include "bindingMacros.hh"

// temporal class definitions
#include "logicFormula.hh"

// qid class definitions
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierDagNode.hh"

// ltlr class definitions
#include "PropTable/ParamPropositionTable.hh"
#include "FairTable/ParamFairnessTable.hh"
#include "Interface/FairnessDecoder.hh"
#include "Interface/CounterExampleGenerator.hh"
#include "Utility/TermUtil.hh"
#include "ModelCheckerManager.hh"
#include "ltlrFairnessCheckerSymbol.hh"


//#define TDEBUG

namespace modelChecker {

LTLRFairnessCheckerSymbol::LTLRFairnessCheckerSymbol(int id, int arity): TemporalSymbol(id, arity) {}

bool
LTLRFairnessCheckerSymbol::attachData(const Vector<Sort*>& opDeclaration,
		const char* purpose, const Vector<const char*>& data)
{
    NULL_DATA(purpose, LTLRFairnessCheckerSymbol, data);
    return  TemporalSymbol::attachData(opDeclaration, purpose, data);
}

bool
LTLRFairnessCheckerSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
    BIND_SYMBOL(purpose, symbol, fairnessSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, strongFairTypeSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, weakFairTypeSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, fairnessSetSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, emptyFairnessSetSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, counterexampleSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, transitionSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, transitionListSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, nilTransitionListSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, prooftermSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, assignOp, Symbol*);
    BIND_SYMBOL(purpose, symbol, holeOp, Symbol*);
    BIND_SYMBOL(purpose, symbol, substitutionSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, emptySubstSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, qidSymbol, QuotedIdentifierSymbol*);
    BIND_SYMBOL(purpose, symbol, unlabeledSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, noContextSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, realizedPropSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, realizedActionSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, satisfiesSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, actionmatchSymbol, Symbol*);
    BIND_SYMBOL(purpose, symbol, enabledSymbol, Symbol*);
	return TemporalSymbol::attachSymbol(purpose, symbol);
}

bool
LTLRFairnessCheckerSymbol::attachTerm(const char* purpose, Term* term)
{
	BIND_TERM(purpose, term, falseTerm);
	BIND_TERM(purpose, term, deadlockTerm);
	BIND_TERM(purpose, term, trueTerm);
    return TemporalSymbol::attachTerm(purpose, term);
}

void
LTLRFairnessCheckerSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
	LTLRFairnessCheckerSymbol* orig = safeCast(LTLRFairnessCheckerSymbol*, original);
	COPY_SYMBOL(orig, fairnessSymbol, map, Symbol*);
	COPY_SYMBOL(orig, strongFairTypeSymbol, map, Symbol*);
	COPY_SYMBOL(orig, weakFairTypeSymbol, map, Symbol*);
	COPY_SYMBOL(orig, fairnessSetSymbol, map, Symbol*);
	COPY_SYMBOL(orig, emptyFairnessSetSymbol, map, Symbol*);
	COPY_SYMBOL(orig, counterexampleSymbol, map, Symbol*);
	COPY_SYMBOL(orig, transitionSymbol, map, Symbol*);
	COPY_SYMBOL(orig, transitionListSymbol, map, Symbol*);
	COPY_SYMBOL(orig, nilTransitionListSymbol, map, Symbol*);
	COPY_SYMBOL(orig, prooftermSymbol, map, Symbol*);
	COPY_SYMBOL(orig, assignOp, map, Symbol*);
	COPY_SYMBOL(orig, holeOp, map, Symbol*);
	COPY_SYMBOL(orig, substitutionSymbol, map, Symbol*);
	COPY_SYMBOL(orig, emptySubstSymbol, map, Symbol*);
	COPY_SYMBOL(orig, qidSymbol, map, QuotedIdentifierSymbol*);
	COPY_SYMBOL(orig, unlabeledSymbol, map, Symbol*);
	COPY_SYMBOL(orig, noContextSymbol, map, Symbol*);
	COPY_SYMBOL(orig, realizedPropSymbol, map, Symbol*);
	COPY_SYMBOL(orig, realizedActionSymbol, map, Symbol*);
	COPY_SYMBOL(orig, satisfiesSymbol, map, Symbol*);
	COPY_SYMBOL(orig, actionmatchSymbol, map, Symbol*);
	COPY_SYMBOL(orig, enabledSymbol, map, Symbol*);
	COPY_TERM(orig, falseTerm, map);
	COPY_TERM(orig, deadlockTerm, map);
	COPY_TERM(orig, trueTerm, map);
	TemporalSymbol::copyAttachments(original, map);
}

void
LTLRFairnessCheckerSymbol::getDataAttachments(const Vector<Sort*>& opDeclaration,
		Vector<const char*>& purposes, Vector<Vector<const char*> >& data)
{
    APPEND_DATA(purposes, data, LTLRFairnessCheckerSymbol);
    TemporalSymbol::getDataAttachments(opDeclaration, purposes, data);
}

void
LTLRFairnessCheckerSymbol::getSymbolAttachments(Vector<const char*>& purposes, Vector<Symbol*>& symbols)
{
	APPEND_SYMBOL(purposes, symbols, fairnessSymbol);
	APPEND_SYMBOL(purposes, symbols, strongFairTypeSymbol);
	APPEND_SYMBOL(purposes, symbols, weakFairTypeSymbol);
	APPEND_SYMBOL(purposes, symbols, fairnessSetSymbol);
	APPEND_SYMBOL(purposes, symbols, emptyFairnessSetSymbol);
	APPEND_SYMBOL(purposes, symbols, counterexampleSymbol);
	APPEND_SYMBOL(purposes, symbols, transitionSymbol);
	APPEND_SYMBOL(purposes, symbols, transitionListSymbol);
	APPEND_SYMBOL(purposes, symbols, nilTransitionListSymbol);
	APPEND_SYMBOL(purposes, symbols, prooftermSymbol);
	APPEND_SYMBOL(purposes, symbols, assignOp);
	APPEND_SYMBOL(purposes, symbols, holeOp);
	APPEND_SYMBOL(purposes, symbols, substitutionSymbol);
	APPEND_SYMBOL(purposes, symbols, emptySubstSymbol);
	APPEND_SYMBOL(purposes, symbols, qidSymbol);
	APPEND_SYMBOL(purposes, symbols, unlabeledSymbol);
	APPEND_SYMBOL(purposes, symbols, noContextSymbol);
	APPEND_SYMBOL(purposes, symbols, realizedPropSymbol);
	APPEND_SYMBOL(purposes, symbols, realizedActionSymbol);
	APPEND_SYMBOL(purposes, symbols, satisfiesSymbol);
	APPEND_SYMBOL(purposes, symbols, actionmatchSymbol);
	APPEND_SYMBOL(purposes, symbols, enabledSymbol);
	TemporalSymbol::getSymbolAttachments(purposes, symbols);
}

void
LTLRFairnessCheckerSymbol::getTermAttachments(Vector<const char*>& purposes, Vector<Term*>& terms)
{
	APPEND_TERM(purposes, terms, falseTerm);
	APPEND_TERM(purposes, terms, deadlockTerm);
	APPEND_TERM(purposes, terms, trueTerm);
	TemporalSymbol::getTermAttachments(purposes, terms);
}

void
LTLRFairnessCheckerSymbol::postInterSymbolPass()
{
	PREPARE_TERM(falseTerm);
	PREPARE_TERM(deadlockTerm);
	PREPARE_TERM(trueTerm);
	TemporalSymbol::postInterSymbolPass();
}

void
LTLRFairnessCheckerSymbol::reset()
{
	falseTerm.reset();
	deadlockTerm.reset();
	trueTerm.reset();
	TemporalSymbol::reset();
}


bool
LTLRFairnessCheckerSymbol::eqRewrite(DagNode* subject, RewritingContext& context) noexcept
{
    Assert(this == subject->symbol(), "bad symbol");
    FreeDagNode* d = safeCast(FreeDagNode*,subject);
    //
    // 1. declare the argument contexts, and reduce the formula/fairness arguments into the normal forms
    //
    const unique_ptr<RewritingContext> sysCxt(context.makeSubcontext(d->getArgument(0)));
	const unique_ptr<RewritingContext> formulaCxt(context.makeSubcontext(negate(d->getArgument(1))));
	const unique_ptr<RewritingContext> fairnessCxt(context.makeSubcontext(d->getArgument(2)));

	formulaCxt->reduce();	context.addInCount(*formulaCxt);
	fairnessCxt->reduce();	context.addInCount(*fairnessCxt);
	//
	// 2. create a prop table and a fairness decoder
	//
	const PropInterpreter pInterpreter(satisfiesSymbol, actionmatchSymbol, enabledSymbol);
	const unique_ptr<PropositionTable> propTable(TermUtil::checkGround(fairnessCxt->root()) ?
			new PropositionTable(pInterpreter) : new ParamPropositionTable(pInterpreter));
	const FairnessDecoder fDecoder(*this, *propTable, fairnessSymbol,
			strongFairTypeSymbol, weakFairTypeSymbol, fairnessSetSymbol, emptyFairnessSetSymbol);
	//
	// 3. interpret the formula and the fairness conditions
	//
    unique_ptr<Formula> formula;
    unique_ptr<AbstractFairnessTable> fairTable;
    try {
    	// NOTE: the formula must be interpreted BEFORE fairness formulas.
    	formula = interpretFormula(formulaCxt->root(), *propTable);
    	fairTable = fDecoder.interpretFairnessSet(fairnessCxt->root());
    } catch (const invalid_argument& e)
    {
    	IssueAdvisory(e.what());
    	return TemporalSymbol::eqRewrite(subject, context);
    }
    //
    // 4. construct a suitable model checker
    //
    const PropEvaluator stateEval(satisfiesSymbol, realizedPropSymbol, trueTerm.getDag());
    const PropEvaluator eventEval(actionmatchSymbol, realizedActionSymbol, trueTerm.getDag());
    const ProofTermGenerator ptg(safeCast(MixfixModule*,getModule()), context,
    		prooftermSymbol,assignOp,holeOp,substitutionSymbol,emptySubstSymbol,qidSymbol,
    		unlabeledSymbol,noContextSymbol,deadlockTerm.getDag());
    ModelCheckerManager mcm(*formula, *propTable, move(fairTable), stateEval, eventEval, ptg, *sysCxt);
    //
    // 5. perform the model checking
    //
    DagNode* resultDag;
    try {
    	const CounterExampleGenerator cg(counterexampleSymbol,transitionSymbol,transitionListSymbol,nilTransitionListSymbol);
    	resultDag = mcm.findCounterExample() ?
    			cg.makeCounterexample(mcm.getDagSystemGraph(), mcm.getLeadIn(), mcm.getCycle()) : trueTerm.getDag();
    } catch (const logic_error& e)
    {
    	IssueAdvisory(e.what());
    	return TemporalSymbol::eqRewrite(subject, context);
    }
    //
    // 6. print state space size..
    //
    if (globalVerboseFlag)
    {
    	auto& graph = mcm.getDagSystemGraph();
		auto totalStates = graph.getNrVisitedStates();
		unsigned int totalTransitions = 0;
		for (unsigned int i = 0; i < graph.getNrStates(); ++i) totalTransitions += graph.getNrVisitedTransitions(i);
		cout << "ModelChecker: Examined " << totalStates << " system state" << pluralize(totalStates)
			 << " and " << totalTransitions << " transition" << pluralize(totalTransitions) << '.' << endl;
    }
    context.addInCount(*sysCxt);
    return context.builtInReplace(subject, resultDag);
}




}
