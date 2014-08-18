/*
 * StateSystemGraph.hh
 *
 *  Created on: Sep 11, 2013
 *      Author: kquine
 */

#ifndef STATESYSTEMGRAPH_HH_
#define STATESYSTEMGRAPH_HH_
#include "PropChecker/PropSet.hh"
#include "GraphTemplate/BaseSystemGraphIter.hh"
#include "GraphTemplate/RuleTransitionGraph.hh"
#include "GraphTemplate/DefaultStateDagContainer.hh"

namespace modelChecker {

//
// Only state propositions
//
template <typename PL>
class StateSystemGraph:
		public BaseSystemGraphIter<StateSystemGraph<PL>>,
		private RuleTransitionGraph,
		private DefaultStateDagContainer,
		private SystemGraphTraits<StateSystemGraph<PL>>
{
	friend class BaseSystemGraph<StateSystemGraph>;
	friend class BaseSystemGraphIter<StateSystemGraph>;
	friend class SystemGraphTraits<StateSystemGraph<PL>>;

	using Super =	BaseSystemGraphIter<StateSystemGraph<PL>>;
	using Traits =	SystemGraphTraits<StateSystemGraph<PL>>;

public:
	using typename Traits::State;
	using typename Traits::Transition;

	StateSystemGraph(unique_ptr<PL>&& spl, RewritingContext& initial,
			const ProofTermGenerator& ptg, const PropositionTable& propTable);

private:
	using DefaultStateDagContainer::index2StateDag;		/* implements */
	using DefaultStateDagContainer::stateDag2index;		/* implements */
	using RuleTransitionGraph::makeTransitionDag;		/* implements */
	using Traits::insertTransition;						/* implements */
	using Traits::insertDeadlockTransition;				/* implements */
	using Traits::satisfiesStateProp;					/* implements */
	using Traits::satisfiesEventProp;					/* implements */
	using Traits::updateStateLabel;						/* implements */
};


template <typename PL>
class SystemGraphTraits<StateSystemGraph<PL>>
{
public:
	struct State;
	struct Transition;
	struct ActiveState;

	SystemGraphTraits(unique_ptr<PL>&& pl): propLabel(move(pl)) {}

	template <typename STATE>
	bool insertTransition(unsigned int nextState, STATE& n, DagNode*) const;

	template <typename STATE>
	void insertDeadlockTransition(unsigned int stateNr, STATE& n) const;

	template <typename STATE>
	bool satisfiesStateProp(unsigned int propId, const STATE& s) const;

	template <typename TRANSITION>
	bool satisfiesEventProp(unsigned int propId, const TRANSITION& t) const;

	template <typename STATE>
	unique_ptr<PropSet> updateStateLabel(DagNode* stateDag, STATE& s) const;

protected:
	const unique_ptr<PL> propLabel;
};


template <typename PL>
struct SystemGraphTraits<StateSystemGraph<PL>>::State:
	public BaseSystemGraphIterTraits::State<ActiveState,Transition>, public PL::StateLabel {};

template <typename PL>
struct SystemGraphTraits<StateSystemGraph<PL>>::Transition:
	public BaseSystemGraphIterTraits::Transition,
	public RuleTransitionGraph::Transition
{
	Transition(unsigned int nextState, const Rule* rule):
		BaseSystemGraphIterTraits::Transition{nextState},
		RuleTransitionGraph::Transition(rule) {}
};

template <typename PL>
struct SystemGraphTraits<StateSystemGraph<PL>>::ActiveState: public BaseSystemGraphIterTraits::ActiveState
{
	ActiveState(RewritingContext& parent, DagNode* stateDag): BaseSystemGraphIterTraits::ActiveState(parent,stateDag) {}
	set<unsigned int> nextStateSet;
};


} /* namespace modelChecker */

#include "StateSystemGraph.cc"	// to separate the implementation for the template

#endif /* STATESYSTEMGRAPH_HH_ */
