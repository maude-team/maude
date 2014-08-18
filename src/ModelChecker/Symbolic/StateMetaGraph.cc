/*
 * StateMetaGraph.cc
 *
 *  Created on: Nov 15, 2011
 *      Author: kquine
 */
//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "freeTheory.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

//      free theory class definitions
#include "freeDagNode.hh"

// core class definitions
#include "rewritingContext.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNodeSet.hh"

// lmc definitions
#include "StateMetaGraph.hh"


namespace modelChecker {

StateMetaGraph::StateMetaGraph(unique_ptr<StatePropLabel>&& spl, RewritingContext& initial,
			const PropositionTable& propTable, Symbol* stateSymbol, Symbol* transitionSymbol, DagNode* deadlockDag):
		BaseSystemGraphIter<StateMetaGraph>(initial,propTable),
		Traits(move(spl)), stateSymbol(stateSymbol), transitionSymbol(transitionSymbol), deadlockDag(deadlockDag) {}


DagNode*
StateMetaGraph::index2StateDag(size_type index) const
{
	return hashConsSet.getCanonical(seen[index]->hashConsIndex);
}


DagNode*
StateMetaGraph::makeTransitionDag(const Transition& t, DagNode*, RewritingContext&) const
{
	return hashConsSet.getCanonical(t.hashConsIndex);
}


unsigned int
StateMetaGraph::dag2index(DagNode* dag, const int info)
{
	const unsigned int hashConsIndex = hashConsSet.insert(dag);
	const auto mapSize = hashCons2dagIndex.size();

	//DebugAdvisory("replacement dag = " << dag << "hashConsIndex = " << hashConsIndex);
	if (hashConsIndex < mapSize)	// Seen before
	{
		auto oldinfo = hashCons2dagIndex[hashConsIndex];
		if (oldinfo != NONE)
			return hashConsIndex;
		// But only as a subdag, not as a state dag, so it counts as a new dag.
	}
	else	//	Definitely a new dag.
	{
		hashCons2dagIndex.resize(hashConsIndex + 1, NONE);
	}
	Assert(hashCons2dagIndex[hashConsIndex] == NONE, "StateMetaGraph::dag2index: try to overwrite");
	hashCons2dagIndex[hashConsIndex] = info;
	return hashConsIndex;
}


unsigned int
StateMetaGraph::insertState(DagNode* metaDag)
{
	auto stateDag = metaDag->symbol() == transitionSymbol ? safeCast(FreeDagNode*,metaDag)->getArgument(1) : metaDag;
	auto currHashConsIndex = this->dag2index(stateDag, getNrStates());
	unsigned int nextState = hashCons2dagIndex[currHashConsIndex];

	if (nextState == this->seen.size())	// if a new state identified
	{
		Vector<DagNode*> arg(1);
		arg[0] = hashConsSet.getCanonical(currHashConsIndex);;
		auto activeDag = stateSymbol->makeDagNode(arg);		// make META transitions from [STATE] ...

		unique_ptr<State> s(new State(currHashConsIndex));
		s->explore.reset(new ActiveState(this->context, activeDag));
		this->updateStateLabel(arg[0], *s);
		this->seen.push_back(std::move(s));
	}
	return nextState;
}


bool
StateMetaGraph::insertTransition(unsigned int nextState, State& n, DagNode* metaDag)
{
	auto transDag = safeCast(FreeDagNode*,metaDag)->getArgument(0);
	unique_ptr<Transition> t(new Transition(nextState, this->dag2index(transDag,transId)));

	if (n.explore->transitionPtrSet.insert(t.get()).second)		// if a new transition identified
	{
		n.transitions.push_back(std::move(t));
		return true;
	}
	return false;
}


void
StateMetaGraph::insertDeadlockTransition(unsigned int stateNr, State& n)
{
	Assert(n.explore->transitionPtrSet.empty(), "StateMetaGraph::insertDeadlockTransition: not deadlock");
	unique_ptr<Transition> t(new Transition(stateNr, this->dag2index(deadlockDag,transId)));

	n.explore->transitionPtrSet.insert(t.get());
	n.transitions.push_back(std::move(t));
}

} /* namespace modelChecker */
