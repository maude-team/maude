/*
 * ModelCheckerManager.hh
 *
 *  Created on: Aug 6, 2013
 *      Author: kquine
 */

#ifndef MODELCHECKERMANAGER_HH_
#define MODELCHECKERMANAGER_HH_
#include "logicFormula.hh"
#include "Automaton/FairProductAutomaton.hh"
#include "Graph/DagSystemGraph.hh"
#include "PropTable/PropositionTable.hh"
#include "PropChecker/PropChecker.hh"
#include "PropChecker/EnabledPropHandler.hh"
#include "FairTable/FairnessTable.hh"
#include "FairChecker/FairnessChecker.hh"
#include "Interface/FormulaBuilder.hh"
#include "Interface/ProofTermGenerator.hh"
#include "Search/ModelChecker.hh"

namespace modelChecker {

class ModelCheckerManager
{
	using Formula =	FormulaBuilder::Formula;
public:
	ModelCheckerManager(Formula& formula, PropositionTable& propTable,
			unique_ptr<AbstractFairnessTable>&& fairTable, const PropEvaluator& stateEval,
			const PropEvaluator& eventEval, const ProofTermGenerator& ptg, RewritingContext& context);

	const DagSystemGraph& getDagSystemGraph() const		{ return *dagGraphRef; }
	const list<ModelChecker::Edge>& getLeadIn() const	{ return modelChecker->getLeadIn(); }
	const list<ModelChecker::Edge>& getCycle() const	{ return modelChecker->getCycle(); }
	bool findCounterExample()							{ return modelChecker->findCounterExample(); }

private:
	void initPropFairCheckers(const PropEvaluator& sev, const PropEvaluator& eev, AbstractFairnessTable* fairTable);

	void initModelChecker(unique_ptr<AbstractFairnessTable>&& fairTable);

	template <template <typename...> class Graph, typename... Args>
	void initFairLabel(Args&&... args);

	template <template <typename...> class Graph, typename... Args>
	void initPropLabel(Args&&... args);

	template <template <typename> class Graph, typename PL, typename... Args>
	void makeGraph(unique_ptr<PL>&& pl, Args&&... args);

	template <template <typename,typename> class Graph, typename PL, typename FL, typename... Args>
	void makeGraph(unique_ptr<PL>&& pl, unique_ptr<FL>&& fl, unique_ptr<AbstractFairnessTable>&& fairTable, Args&&... args);

	template <typename SA, typename PA, typename... Args>
	void makeProd(unique_ptr<SA>&& sysGraph, unique_ptr<PA>&& propGraph, Args&&... args);

	template <bool hasState, bool hasEvent, typename SA>
	void makeModelChecker(unique_ptr<SA>&& sysGraph, unique_ptr<BuchiAutomaton2>&& propGraph);

	template <bool hasState, bool hasEvent, typename SA>
	void makeModelChecker(unique_ptr<SA>&& sysGraph,
			unique_ptr<GenBuchiAutomaton>&& propGraph, unique_ptr<AbstractFairnessTable>&& fairTable);

	//
	// formula and propositions
	//
	Formula& formula;
	PropositionTable& propTable;
	//
	// Maude interfaces
	//
	const ProofTermGenerator& pGenerator;
	RewritingContext& sysContext;
	//
	// categorized propositions
	//
	vector<unsigned int> stateProps, eventProps, enabledProps;
	NatSet fStateProps, fEventProps;
	bool hasStateProp = false, hasEventProp = false;
	//
	// prop/fair checkers
	//
	unique_ptr<PropChecker> spc, epc;
	unique_ptr<FairnessChecker> sfc, efc;
	//
	// a model checker
	//
	DagSystemGraph* dagGraphRef = nullptr;
	unique_ptr<AbstractAutomaton> product;
	unique_ptr<ModelChecker> modelChecker;
};


} /* namespace modelChecker */
#endif /* MODELCHECKERMANAGER_HH_ */
