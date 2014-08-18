/*
 * ModelCheckerManager.cc
 *
 *  Created on: Aug 6, 2013
 *      Author: kquine
 */

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "temporal.hh"
#include "higher.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//	ltlr definitions
#include "Utility/ptr_set.hh"
#include "Automaton/FairProductAutomaton.hh"
#include "Graph/FairStateSystemGraph.hh"
#include "Graph/FairStateEventSystemGraph.hh"
#include "Graph/FairStateEventEnabledSystemGraph.hh"
#include "GraphLabel/StatePropLabel.hh"
#include "GraphLabel/EventPropLabel.hh"
#include "GraphLabel/StateEventPropLabel.hh"
#include "GraphLabel/StateFairLabel.hh"
#include "GraphLabel/EventFairLabel.hh"
#include "GraphLabel/StateEventFairLabel.hh"
#include "PropTable/ParamPropositionTable.hh"
#include "PropChecker/PropCheckerFactory.hh"
#include "FairTable/ParamFairnessTable.hh"
#include "FairChecker/FairnessCheckerFactory.hh"
#include "Search/NDFSModelChecker.hh"
#include "Search/StreettModelChecker.hh"
#include "Search/SCCBuchiModelChecker.hh"
#include "Utility/StringStream.hh"
#include "ModelCheckerManager.hh"

//#define TDEBUG

namespace modelChecker {

ModelCheckerManager::ModelCheckerManager(Formula& f, PropositionTable& props,
		unique_ptr<AbstractFairnessTable>&& fairTable, const PropEvaluator& sev,
		const PropEvaluator& eev, const ProofTermGenerator& ptg, RewritingContext& sysCxt):
			formula(f), propTable(props), pGenerator(ptg), sysContext(sysCxt)
{
	initPropFairCheckers(sev, eev, fairTable.get());
	initModelChecker(move(fairTable));
}

void
ModelCheckerManager::initPropFairCheckers(const PropEvaluator& sev,
		const PropEvaluator& eev, AbstractFairnessTable* fairTablePtr)
{
	for (unsigned int i = 0; i < propTable.cardinality(); ++i)
	{
		if (propTable.isStateProp(i))	stateProps.push_back(i);
		if (propTable.isEventProp(i))	eventProps.push_back(i);
		if (propTable.isEnabledProp(i))	enabledProps.push_back(i);
	}

	for (unsigned int i = 0; i < formula.nrRealFormulaPropIds; ++i)
	{
		hasStateProp |= (propTable.isStateProp(i) | propTable.isEnabledProp(i));
		hasEventProp |= propTable.isEventProp(i);
	}

	for (auto i = stateProps.rbegin(); i != stateProps.rend(); ++i)
	{
		if (*i < formula.nrFormulaPropIds) fStateProps.insert(*i);
	}
	for (auto i = eventProps.rbegin(); i != eventProps.rend(); ++i)
	{
		if (*i < formula.nrFormulaPropIds) fEventProps.insert(*i);
	}

	spc = 	PropCheckerFactory::createChecker(stateProps, propTable, sev, sysContext);
	epc =	PropCheckerFactory::createChecker(eventProps, propTable, eev, sysContext);
	sfc = 	FairnessCheckerFactory::createChecker(true, fairTablePtr);
	efc = 	FairnessCheckerFactory::createChecker(false, fairTablePtr);

#ifdef TDEBUG
	cout << "#Prop Checkers: " << bool(spc) << ", " << bool(epc) << endl;
	cout << "#Fair Checkers: " << bool(sfc) << ", " << bool(efc) << endl;
#endif
}

void
ModelCheckerManager::initModelChecker(unique_ptr<AbstractFairnessTable>&& fTable)		// choose a graph type
{
	if ( eventProps.empty() )			// no event props
	{
		Verbose("ModelChecker: a system graph may compute only state propositions..");

		unique_ptr<StatePropLabel> pl(new StatePropLabel(fStateProps,*spc,epc.get()));
		if (sfc)
			makeGraph<FairStateSystemGraph>(move(pl),unique_ptr<StateFairLabel>(new StateFairLabel(*sfc)),move(fTable));
		else
			makeGraph<StateSystemGraph>(move(pl));
	}
	else if ( enabledProps.empty() )	// there exist event props, but no enabled props
	{
		Verbose("ModelChecker: a system graph may compute state and event propositions..");

		if (sfc || efc)	initFairLabel<FairStateEventSystemGraph>(move(fTable));
		else			initPropLabel<StateEventSystemGraph>();
	}
	else
	{
		Verbose("ModelChecker: a system graph may compute state, event, and enabled propositions..");

		auto enph = PropCheckerFactory::createHandler(enabledProps, formula.nrFormulaPropIds, propTable);
		if (sfc || efc)	initFairLabel<FairStateEventEnabledSystemGraph>(move(fTable),move(enph));
		else			initPropLabel<StateEventEnabledSystemGraph>(move(enph));
	}
}

template <template <typename...> class Graph, typename... Args> void
ModelCheckerManager::initFairLabel(Args&&... args)
{
	if (sfc && efc)
		initPropLabel<Graph>(unique_ptr<StateEventFairLabel>(new StateEventFairLabel(*sfc,*efc)),forward<Args>(args)...);
	else if (sfc)
		initPropLabel<Graph>(unique_ptr<StateFairLabel>(new StateFairLabel(*sfc)),forward<Args>(args)...);
	else if (efc)
		initPropLabel<Graph>(unique_ptr<EventFairLabel>(new EventFairLabel(*efc)),forward<Args>(args)...);
	else
		throw logic_error("cannot happen.");
}

template <template <typename...> class Graph, typename... Args> void
ModelCheckerManager::initPropLabel(Args&&... args)
{
	if (!fStateProps.empty() && !fEventProps.empty())
		makeGraph<Graph>(unique_ptr<StateEventPropLabel>(new StateEventPropLabel(
				fStateProps,fEventProps,*spc,*epc)),forward<Args>(args)...);
	else if ( !fStateProps.empty() )
		makeGraph<Graph>(unique_ptr<StatePropLabel>(new StatePropLabel(fStateProps,*spc,epc.get())),forward<Args>(args)...);
	else if ( !fEventProps.empty())
		makeGraph<Graph>(unique_ptr<EventPropLabel>(new EventPropLabel(fEventProps,spc.get(),*epc)),forward<Args>(args)...);
	else
		throw invalid_argument("no propositions are provided.");
}

template <template <typename> class Graph, typename PL, typename... Args> void
ModelCheckerManager::makeGraph(unique_ptr<PL>&& pl, Args&&... args)
{
	pl->setExtraFlag(false);	// notify that there are no fairness props.
	unique_ptr<Graph<PL>> sysGraph(new Graph<PL>(move(pl),forward<Args>(args)..., sysContext, pGenerator, propTable));
	sysGraph->init();
	dagGraphRef = sysGraph.get();

	unique_ptr<BuchiAutomaton2> propGraph(new BuchiAutomaton2(&formula.data,formula.top));
	makeProd(move(sysGraph), move(propGraph));
}

template <template <typename,typename> class Graph, typename PL, typename FL, typename... Args> void
ModelCheckerManager::makeGraph(unique_ptr<PL>&& pl, unique_ptr<FL>&& fl,
		unique_ptr<AbstractFairnessTable>&& fairTable, Args&&... args)
{
	pl->setExtraFlag(true);		// notify that there exist fairness props.
	unique_ptr<Graph<PL,FL>> sysGraph(new Graph<PL,FL>(move(pl),
			move(fl),forward<Args>(args)..., sysContext, pGenerator, propTable));
	sysGraph->init();
	dagGraphRef = sysGraph.get();

	unique_ptr<GenBuchiAutomaton> propGraph(new GenBuchiAutomaton(&formula.data,formula.top));
	propGraph->simplify();
	makeProd(move(sysGraph), move(propGraph), move(fairTable));
}

template <typename SA, typename PA, typename... Args> void
ModelCheckerManager::makeProd(unique_ptr<SA>&& sysGraph, unique_ptr<PA>&& propGraph, Args&&... args)
{
	if (hasStateProp && hasEventProp)
	{
		Verbose("ModelChecker: LTLR model checking with a state/event-based algorithm.");
		makeModelChecker<true,true>(move(sysGraph), move(propGraph), forward<Args>(args)...);
	}
	else if (hasStateProp)
	{
		Verbose("ModelChecker: LTL model checking with a state-based algorithm.");
		makeModelChecker<true,false>(move(sysGraph), move(propGraph), forward<Args>(args)...);
	}
	else if (hasEventProp)
	{
		Verbose("ModelChecker: LTLR model checking with an event-based algorithm.");
		makeModelChecker<false,true>(move(sysGraph), move(propGraph), forward<Args>(args)...);
	}
	else
		throw invalid_argument("no propositions in the formula.");
}

template <bool hasState, bool hasEvent, typename SA> void
ModelCheckerManager::makeModelChecker(unique_ptr<SA>&& sysGraph, unique_ptr<BuchiAutomaton2>&& propGraph)
{
	auto propSize = propGraph->getNrStates();

	using Prod = ProductAutomaton<hasState,hasEvent,SA,BuchiAutomaton2>;
	product.reset(new Prod(move(sysGraph), move(propGraph)));

	Verbose("ModelChecker: Use the NDFS algorithm with a Buchi automaton (" << propSize << " states).");
	modelChecker.reset(new NDFSModelChecker<BuchiAutomaton2>(static_cast<Prod&>(*product)));
}

template <bool hasState, bool hasEvent, typename SA> void
ModelCheckerManager::makeModelChecker(unique_ptr<SA>&& sysGraph,
		unique_ptr<GenBuchiAutomaton>&& propGraph, unique_ptr<AbstractFairnessTable>&& fairTable)
{
	auto propSize = propGraph->getNrStates();

	using Prod = FairProductAutomaton<hasState,hasEvent,SA,GenBuchiAutomaton>;
	product.reset(new Prod(move(sysGraph), move(propGraph), move(fairTable)));

	if (static_cast<Prod*>(product.get())->getFairnessTable().hasStrongFairness())
	{
		Verbose("ModelChecker: Use the Streett algorithm with a gen-Buchi automaton (" << propSize << " states).");
		modelChecker.reset(new StreettModelChecker<GenBuchiAutomaton>(static_cast<Prod&>(*product)));
	}
	else
	{
		Verbose("ModelChecker: Use the SCC-Buchi algorithm with a gen-Buchi automaton (" << propSize << " states).");
		modelChecker.reset(new SCCBuchiModelChecker<GenBuchiAutomaton>(static_cast<Prod&>(*product)));
	}
}


} /* namespace modelChecker */
