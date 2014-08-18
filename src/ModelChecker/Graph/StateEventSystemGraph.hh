/*
 * StateEventSystemGraph.hh
 *
 *  Created on: Aug 13, 2013
 *      Author: kquine
 */

#ifndef STATEEVENTSYSTEMGRAPH_HH_
#define STATEEVENTSYSTEMGRAPH_HH_
#include "PropChecker/PropSet.hh"
#include "GraphTemplate/BaseSystemGraphIter.hh"
#include "GraphTemplate/CompactProofTermTransitionGraph.hh"
#include "GraphTemplate/DefaultStateDagContainer.hh"

namespace modelChecker {

/*
 * an ordinary state/event-based RW system graph; every state proposition should be defined by equations.
 */
template <typename PL>
class StateEventSystemGraph:
		public BaseSystemGraphIter<StateEventSystemGraph<PL>>,
		private CompactProofTermTransitionGraph,
		private DefaultStateDagContainer,
		private SystemGraphTraits<StateEventSystemGraph<PL>>
{
	friend class BaseSystemGraph<StateEventSystemGraph>;
	friend class BaseSystemGraphIter<StateEventSystemGraph>;
	friend class SystemGraphTraits<StateEventSystemGraph<PL>>;

	using Super =	BaseSystemGraphIter<StateEventSystemGraph<PL>>;
	using Traits =	SystemGraphTraits<StateEventSystemGraph<PL>>;

public:
	using typename Traits::State;
	using typename Traits::Transition;
	using typename Traits::ActiveState;

	StateEventSystemGraph(unique_ptr<PL>&& sepl, RewritingContext& initial,
			const ProofTermGenerator& ptg, const PropositionTable& propTable);

private:
	using DefaultStateDagContainer::index2StateDag;				/* implements */
	using DefaultStateDagContainer::stateDag2index;				/* implements */
	using CompactProofTermTransitionGraph::makeTransitionDag;	/* implements */
	using Traits::insertTransition;								/* implements */
	using Traits::insertDeadlockTransition;						/* implements */
	using Traits::satisfiesStateProp;							/* implements */
	using Traits::satisfiesEventProp;							/* implements */
	using Traits::updateStateLabel;								/* implements */
};

template <typename PL>
class SystemGraphTraits<StateEventSystemGraph<PL>>
{
public:
	struct State;
	struct Transition;
	struct ActiveState;

	SystemGraphTraits(unique_ptr<PL>&& pl): propLabel(move(pl)) {}

	bool insertTransition(unsigned int nextState, State& n, DagNode*);
	void insertDeadlockTransition(unsigned int stateNr, State& n);
	bool satisfiesStateProp(unsigned int propId, const State& s) const;
	bool satisfiesEventProp(unsigned int propId, const Transition& t) const;
	unique_ptr<PropSet> updateStateLabel(DagNode* stateDag, State& s) const;

private:
	const unique_ptr<PL> propLabel;
};

template <typename PL>
struct SystemGraphTraits<StateEventSystemGraph<PL>>::State:
	public BaseSystemGraphIterTraits::State<ActiveState,Transition>, public PL::StateLabel {};

template <typename PL>
struct SystemGraphTraits<StateEventSystemGraph<PL>>::Transition:
	public BaseSystemGraphIterTraits::Transition,
	public CompactProofTermTransitionGraph::Transition, public PL::EventLabel
{
	Transition(unsigned int nextState, unsigned int transitionIndex):
		BaseSystemGraphIterTraits::Transition{nextState},
		CompactProofTermTransitionGraph::Transition(transitionIndex) {}
	bool operator<(const Transition& t) const;
};

template <typename PL>
struct SystemGraphTraits<StateEventSystemGraph<PL>>::ActiveState: public BaseSystemGraphIterTraits::ActiveState
{
	ActiveState(RewritingContext& parent, DagNode* stateDag): BaseSystemGraphIterTraits::ActiveState(parent,stateDag) {}

	ptr_set<Transition> transitionPtrSet;	// to distinguish equivalent transitions
	unsigned int transitionCount = 0;		// to recover the corresponding proofterm
};



} /* namespace modelChecker */

#include "StateEventSystemGraph.cc"	// to separate the implementation for the template

#endif /* STATEEVENTSYSTEMGRAPH_HH_ */
