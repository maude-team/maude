/*
 * BaseSystemGraph.hh
 *
 *  Created on: Aug 14, 2013
 *      Author: kquine
 */

#ifndef BASESYSTEMGRAPH_HH_
#define BASESYSTEMGRAPH_HH_
#include "PropTable/PropositionTable.hh"
#include "RewriteTransitionState.hh"
#include "Graph/DagSystemLabelGraph.hh"

namespace modelChecker {

template <typename T> class SystemGraphTraits;

template <class T>
class BaseSystemGraph: public DagSystemLabelGraph
{
	friend class SystemGraphTraits<T>;
public:
	using State = 		typename SystemGraphTraits<T>::State;
	using Transition =	typename SystemGraphTraits<T>::Transition;

	BaseSystemGraph(RewritingContext& initial, const PropositionTable& propTable);
	BaseSystemGraph(const BaseSystemGraph&) = delete;
	BaseSystemGraph& operator=(const BaseSystemGraph&) = delete;

	void init();

	DagNode* getStateDag(unsigned int stateNr) const final;
	DagNode* getTransitionDag(unsigned int stateNr, unsigned int index) const final;

	unsigned int getNrStates() const final;
	unsigned int getNrTransitions(unsigned int stateNr) const final;
	int getNextState(unsigned int stateNr, unsigned int index) final;	// return -1 if no more transitions

	bool satisfiesStateFormula(Bdd formula, unsigned int stateNr) const final;
	bool satisfiesStateEventFormula(Bdd formula, unsigned int stateNr, unsigned int transitionNr) const final;
	pair<bool,Bdd> satisfiesPartialStateFormula(Bdd formula, unsigned int stateNr) const final;

protected:
	vector<unique_ptr<State>> seen;
	RewritingContext& context;
	//
	// template functions (to be implemented in subclasses)
	//
	DagNode* index2StateDag(unsigned int index) const;
	unsigned int insertState(DagNode* stateDag);
	int computeNextState(unsigned int stateNr, unsigned int index);
	bool satisfiesStateProp(unsigned int propId, const State& s) const;
	bool satisfiesEventProp(unsigned int propId, const Transition& t) const;
	DagNode* makeTransitionDag(const Transition& t, DagNode* stateDag, RewritingContext& context);

private:
	const PropositionTable& propTable;
};

struct BaseSystemGraphTraits
{
	struct Transition
	{
		bool operator<(const Transition& t) const;
		const unsigned int nextState;
	};

	template <typename TRANSITION>
	struct State
	{
		vector<unique_ptr<TRANSITION>> transitions;
	};
};


} /* namespace modelChecker */

#include "BaseSystemGraph.cc"	// to separate the implementation for the template

#endif /* BASESYSTEMGRAPH_HH_ */
