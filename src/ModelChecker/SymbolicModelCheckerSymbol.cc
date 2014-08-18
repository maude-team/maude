/*
 * SymbolicModelCheckerSymbol.cc
 *
 *  Created on: Jul 22, 2011
 *      Author: kquine
 */

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "temporal.hh"
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "NA_Theory.hh"
#include "S_Theory.hh"
#include "builtIn.hh"
#include "higher.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//      core class definitions
#include "dagArgumentIterator.hh"
#include "rewritingContext.hh"
#include "symbolMap.hh"

//      additional theory class definitions
#include "freeDagNode.hh"
#include "S_Symbol.hh"
#include "S_DagNode.hh"

//      built in class definitions
#include "bindingMacros.hh"

//	temporal class definitions
#include "logicFormula.hh"

// model checker
#include "buchiAutomaton2.hh"
#include "Search/NDFSModelChecker.hh"
#include "PropChecker/PropCheckerFactory.hh"
#include "Symbolic/StateMetaGraph.hh"
#include "Symbolic/PrettyPrinter.hh"
#include "Symbolic/InputInterpreter.hh"
#include "Symbolic/ConcreteResultGenerator.hh"
#include "SymbolicModelCheckerSymbol.hh"

// #define SDEBUG
// #define TDEBUG

namespace modelChecker {


SymbolicModelCheckerSymbol::SymbolicModelCheckerSymbol(int id, int arity): TemporalSymbol(id, arity) {}

bool
SymbolicModelCheckerSymbol::attachData(const Vector<Sort*>& opDeclaration,
		const char* purpose, const Vector<const char*>& data)
{
	NULL_DATA(purpose, SymbolicModelCheckerSymbol, data);
	return  TemporalSymbol::attachData(opDeclaration, purpose, data);
}

bool
SymbolicModelCheckerSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
	BIND_SYMBOL(purpose, symbol, satisfiesSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, metaStateSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, metaTransitionSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, prettyPrintStateSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, prettyPrintTransSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, subsumeFoldingRelSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, renameFoldingRelSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, compatibleTransSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, unboundedSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, succSymbol, SuccSymbol*);
	BIND_SYMBOL(purpose, symbol, resultreportSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, counterexampleSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, transitionSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, transitionListSymbol, Symbol*);
	BIND_SYMBOL(purpose, symbol, nilTransitionListSymbol, Symbol*);
	return TemporalSymbol::attachSymbol(purpose, symbol);
}

bool
SymbolicModelCheckerSymbol::attachTerm(const char* purpose, Term* term)
{
	BIND_TERM(purpose, term, trueTerm);
	BIND_TERM(purpose, term, falseTerm);
	BIND_TERM(purpose, term, deadlockTerm);
	return TemporalSymbol::attachTerm(purpose, term);
}

void
SymbolicModelCheckerSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
	SymbolicModelCheckerSymbol* orig = safeCast(SymbolicModelCheckerSymbol*, original);
	COPY_SYMBOL(orig, satisfiesSymbol, map, Symbol*);
	COPY_SYMBOL(orig, metaStateSymbol, map, Symbol*);
	COPY_SYMBOL(orig, metaTransitionSymbol, map, Symbol*);
	COPY_SYMBOL(orig, prettyPrintStateSymbol, map, Symbol*);
	COPY_SYMBOL(orig, prettyPrintTransSymbol, map, Symbol*);
	COPY_SYMBOL(orig, subsumeFoldingRelSymbol, map, Symbol*);
	COPY_SYMBOL(orig, renameFoldingRelSymbol, map, Symbol*);
	COPY_SYMBOL(orig, compatibleTransSymbol, map, Symbol*);
	COPY_SYMBOL(orig, unboundedSymbol, map, Symbol*);
	COPY_SYMBOL(orig, succSymbol, map, SuccSymbol*);
	COPY_SYMBOL(orig, resultreportSymbol, map, Symbol*);
	COPY_SYMBOL(orig, counterexampleSymbol, map, Symbol*);
	COPY_SYMBOL(orig, transitionSymbol, map, Symbol*);
	COPY_SYMBOL(orig, transitionListSymbol, map, Symbol*);
	COPY_SYMBOL(orig, nilTransitionListSymbol, map, Symbol*);
	COPY_TERM(orig, trueTerm, map);
	COPY_TERM(orig, falseTerm, map);
	COPY_TERM(orig, deadlockTerm, map);
	TemporalSymbol::copyAttachments(original, map);
}

void
SymbolicModelCheckerSymbol::getDataAttachments(const Vector<Sort*>& opDeclaration, Vector<const char*>& purposes,
		Vector<Vector<const char*> >& data)
{
	APPEND_DATA(purposes, data, SymbolicModelCheckerSymbol);
	TemporalSymbol::getDataAttachments(opDeclaration, purposes, data);
}

void
SymbolicModelCheckerSymbol::getSymbolAttachments(Vector<const char*>& purposes, Vector<Symbol*>& symbols)
{
	APPEND_SYMBOL(purposes, symbols, satisfiesSymbol);
	APPEND_SYMBOL(purposes, symbols, metaStateSymbol);
	APPEND_SYMBOL(purposes, symbols, metaTransitionSymbol);
	APPEND_SYMBOL(purposes, symbols, prettyPrintStateSymbol);
	APPEND_SYMBOL(purposes, symbols, prettyPrintTransSymbol);
	APPEND_SYMBOL(purposes, symbols, subsumeFoldingRelSymbol);
	APPEND_SYMBOL(purposes, symbols, renameFoldingRelSymbol);
	APPEND_SYMBOL(purposes, symbols, compatibleTransSymbol);
	APPEND_SYMBOL(purposes, symbols, unboundedSymbol);
	APPEND_SYMBOL(purposes, symbols, succSymbol);
	APPEND_SYMBOL(purposes, symbols, resultreportSymbol);
	APPEND_SYMBOL(purposes, symbols, counterexampleSymbol);
	APPEND_SYMBOL(purposes, symbols, transitionSymbol);
	APPEND_SYMBOL(purposes, symbols, transitionListSymbol);
	APPEND_SYMBOL(purposes, symbols, nilTransitionListSymbol);
	TemporalSymbol::getSymbolAttachments(purposes, symbols);
}

void
SymbolicModelCheckerSymbol::getTermAttachments(Vector<const char*>& purposes, Vector<Term*>& terms)
{
	APPEND_TERM(purposes, terms, trueTerm);
	APPEND_TERM(purposes, terms, falseTerm);
	APPEND_TERM(purposes, terms, deadlockTerm);
	TemporalSymbol::getTermAttachments(purposes, terms);
}

void
SymbolicModelCheckerSymbol::postInterSymbolPass()
{
	PREPARE_TERM(trueTerm);
	PREPARE_TERM(falseTerm);
	PREPARE_TERM(deadlockTerm);
	TemporalSymbol::postInterSymbolPass();
}

void
SymbolicModelCheckerSymbol::reset()
{
	trueTerm.reset();
	falseTerm.reset();
	deadlockTerm.reset();
	TemporalSymbol::reset();  // parents reset() tasks
}


bool
SymbolicModelCheckerSymbol::eqRewrite(DagNode* subject, RewritingContext& context) noexcept
{
	Assert(this == subject->symbol(), "bad symbol");
	FreeDagNode* d = safeCast(FreeDagNode*, subject);
	//
	//	1. declare the argument contexts, and reduce the arguments into the normal forms
	//
	const unique_ptr<RewritingContext> sysCxt(context.makeSubcontext(d->getArgument(0)));
	const unique_ptr<RewritingContext> formulaCxt(context.makeSubcontext(negate(d->getArgument(1))));
    const unique_ptr<RewritingContext> boolCxt(context.makeSubcontext(d->getArgument(2)));
    const unique_ptr<RewritingContext> boundCxt(context.makeSubcontext(d->getArgument(3)));

	formulaCxt->reduce();	context.addInCount(*formulaCxt);
	boolCxt->reduce();		context.addInCount(*boolCxt);
	boundCxt->reduce();		context.addInCount(*boundCxt);
#ifdef TDEBUG
	cout << "Negated formula: " << formulaCxt->root() << endl;
#endif
	//
	// 2. interpret input flags
	//
	const InputInterpreter iInterpreter(succSymbol, unboundedSymbol, trueTerm.getDag(), falseTerm.getDag());
	bool subsume = iInterpreter.interpretBoolDag(boolCxt->root());
	long globalBound = iInterpreter.interpretNatDag(boundCxt->root());
	//
	// 3. interpret the formula
	//
	unique_ptr<Formula> formula;
	const PropInterpreter pInterpreter(satisfiesSymbol, nullptr, nullptr);
	PropositionTable propTable(pInterpreter);
    try {
    	formula = interpretFormula(formulaCxt->root(), propTable);
    }
    catch (const invalid_argument& e)
    {
    	IssueAdvisory(e.what());
    	return TemporalSymbol::eqRewrite(subject, context);
    }
#ifdef TDEBUG
	cout << "top = " << formula->top << endl;
	formula->data.dump(cout);
#endif
    //
    // 4. construct an model checker environment
    //
	vector<unsigned int> stateProps;
	for (unsigned int i = 0; i < propTable.cardinality(); ++i)
		stateProps.push_back(i);

	const PropEvaluator stateEval(satisfiesSymbol, nullptr, trueTerm.getDag());
    unique_ptr<PropChecker> spc = PropCheckerFactory::createChecker(stateProps, propTable, stateEval, context);

    unique_ptr<Prod> prod;
    Graph* gRef = nullptr;
    {
    	unique_ptr<BuchiAutomaton2> propGraph(new BuchiAutomaton2(&formula->data, formula->top));
    	unique_ptr<Graph> tGraph = createSystemGraph(*sysCxt, subsume, stateProps, *spc, propTable);
    	gRef = tGraph.get();
    	prod.reset(new Prod(move(tGraph), move(propGraph)));
    }
	//
	//  5. perform bounded model checking
	//
    unique_ptr<ModelChecker> mc(new NDFSModelChecker<BuchiAutomaton2>(*prod));
    bool result = false;
#ifdef SDEBUG
	unsigned int bound_state = 0;
	PrettyPrinter printState(prettyPrintStateSymbol, &context);
	PrettyPrinter printTrans(prettyPrintTransSymbol, &context);
#endif
	do {
		auto oldSize = gRef->getNrStates();
		Verbose("SymbolicModelCheckerSymbol: examined " << oldSize << " logical state" << pluralize(oldSize)
				<< " in bound " << gRef->getCurrLevel() << '.');
		gRef->incrementLevel();
#ifdef SDEBUG
		if (globalVerboseFlag)
			for (auto k = bound_state; k < oldSize; ++k)
				gRef->dump(cout, k, &printState, &printTrans);
		bound_state = oldSize;
#endif
		mc.reset(new NDFSModelChecker<BuchiAutomaton2>(*prod));
		result = mc->findCounterExample();
	}
	while((globalBound == NONE || gRef->getCurrLevel() < globalBound) &&	// user bound
			(result == false && ! gRef->reachFixpoint()));					// no counterexample & not fixedpoint
#ifdef SDEBUG
	if (globalVerboseFlag)
		for (auto k = bound_state; k < gRef->getNrVisitedStates(); ++k)
			gRef->dump(cout, k, &printState, &printTrans);
#endif
	auto nrSysStates = gRef->getNrStates();
	Verbose("SymbolicModelCheckerSymbol: examined " << nrSysStates << " logical state" << pluralize(nrSysStates) << '.');
	//
	//  3. results
	//
	auto resultDag = makeModelCheckReportDag(result, gRef->getCurrLevel(), gRef->reachFixpoint(), subsume, *gRef, *mc);
	context.addInCount(*sysCxt);
	return context.builtInReplace(subject, resultDag);
}


unique_ptr<SymbolicModelCheckerSymbol::Graph>
SymbolicModelCheckerSymbol::createSystemGraph(RewritingContext& sysCxt,
		bool subsumption, const vector<unsigned int>& stateProps, PropChecker& spc,
		const PropositionTable& propTable)
{
	// create a state prop label generator
	NatSet fprops;
	for (auto i = stateProps.rbegin(); i != stateProps.rend(); ++i) fprops.insert(*i);

	unique_ptr<StatePropLabel> spl(new StatePropLabel(fprops,spc,nullptr));
	spl->setExtraFlag(false);	// set "no fairness"

	// create a meta graph
    unique_ptr<StateMetaGraph> mgraph(new StateMetaGraph(move(spl), sysCxt, propTable,
    		metaStateSymbol, metaTransitionSymbol, deadlockTerm.getDag()));
    mgraph->init();

    // create a folding checker
    Symbol* foldingSymbol = subsumption ? subsumeFoldingRelSymbol : renameFoldingRelSymbol;
	unique_ptr<FoldingChecker> foldc(new FoldingChecker(foldingSymbol, trueTerm.getDag(), &sysCxt));

	// create a folding graph
    return unique_ptr<Graph>(new StateFoldingGraph<StateMetaGraph>(std::move(mgraph),std::move(foldc)));
}

DagNode*
SymbolicModelCheckerSymbol::makeModelCheckReportDag(bool result, int bound, bool complete, bool subsume,
		Graph& g, const ModelChecker& mc)
{
	Vector<DagNode*> res_args(4);
	if (result)
	{
		ConcreteResultGenerator cA(g, counterexampleSymbol, transitionSymbol, transitionListSymbol, nilTransitionListSymbol);
		auto ceg = cA.makeConcreteCounterExample(subsume, mc.getLeadIn(), mc.getCycle());
		res_args[0] = ceg.first;
		res_args[1] = ceg.second ? trueTerm.getDag() : falseTerm.getDag();
	}
	else
	{
		res_args[0] = trueTerm.getDag();
		res_args[1] = trueTerm.getDag();
	}
	res_args[2] = succSymbol->makeNatDag(bound);
	res_args[3] = complete ? trueTerm.getDag() : falseTerm.getDag();
	return resultreportSymbol->makeDagNode(res_args);
}

}

