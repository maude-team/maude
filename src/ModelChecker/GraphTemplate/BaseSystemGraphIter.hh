/*
 * BaseSystemGraphIter.hh
 *
 *  Created on: Aug 27, 2013
 *      Author: kquine
 */

#ifndef BASESYSTEMGRAPHITER_HH_
#define BASESYSTEMGRAPHITER_HH_
#include "BaseSystemGraph.hh"

namespace modelChecker {

//
// A graph where transitions of a state are iteratively generated.
//
template <class T>
class BaseSystemGraphIter: public BaseSystemGraph<T>
{
	friend class BaseSystemGraph<T>;
	using ActiveState = typename SystemGraphTraits<T>::ActiveState;

public:
	using typename BaseSystemGraph<T>::State;
	using typename BaseSystemGraph<T>::Transition;

	BaseSystemGraphIter(RewritingContext& initial, const PropositionTable& propTable);

	unsigned int getNrVisitedStates() const final;
	unsigned int getNrVisitedTransitions(unsigned int stateNr) const final;

protected:
	//
	// template functions (to be implemented in subclasses)
	//
	unsigned int stateDag2index(DagNode* dag);
	bool insertTransition(unsigned int nextState, State& n, DagNode* stateDag) const;
	void insertDeadlockTransition(unsigned int stateNr, State& n) const;
	unique_ptr<PropSet> updateStateLabel(DagNode* stateDag, State& s) const;

private:
	unsigned int insertState(DagNode* stateDag);					/* implements */
	int computeNextState(unsigned int stateNr, unsigned int index);	/* implements */
};

struct BaseSystemGraphIterTraits: public BaseSystemGraphTraits
{
	struct ActiveState: public RewriteTransitionState
	{
		ActiveState(RewritingContext& parent, DagNode* stateDag): RewriteTransitionState(parent,stateDag) {}
	};

	template <typename ACTIVESTATE, typename TRANSITION>
	struct State: public BaseSystemGraphTraits::State<TRANSITION>
	{
		unique_ptr<ACTIVESTATE> explore;
	};
};

} /* namespace modelChecker */

#include "BaseSystemGraphIter.cc"

#endif /* BASESYSTEMGRAPHITER_HH_ */
