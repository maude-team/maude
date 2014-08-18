/*
 * StateEventSystemGraph.cc
 *
 *  Created on: Aug 13, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "freeTheory.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

// interface class definitions
#include "symbol.hh"
#include "dagNodeSet.hh"

// core class definitions
#include "rewritingContext.hh"

// ltlr definitions
#include "StateEventSystemGraph.hh"

namespace modelChecker {


template <typename PL>
StateEventSystemGraph<PL>::StateEventSystemGraph(unique_ptr<PL>&& pl, RewritingContext& initial,
		const ProofTermGenerator& ptg, const PropositionTable& propTable):
			Super(initial,propTable), CompactProofTermTransitionGraph(ptg), Traits(move(pl)) {}

template <typename PL> bool
SystemGraphTraits<StateEventSystemGraph<PL>>::satisfiesStateProp(unsigned int propId, const State& s) const
{
	return propLabel->satisfiesStateProp(propId, s);
}

template <typename PL> bool
SystemGraphTraits<StateEventSystemGraph<PL>>::satisfiesEventProp(unsigned int propId, const Transition& t) const
{
	return propLabel->satisfiesEventProp(propId, t);
}

template <typename PL> unique_ptr<PropSet>
SystemGraphTraits<StateEventSystemGraph<PL>>::updateStateLabel(DagNode* stateDag, State& s) const
{
	return propLabel->updateStateLabel(stateDag, s);
}

template <typename PL> bool
SystemGraphTraits<StateEventSystemGraph<PL>>::insertTransition(unsigned int nextState, State& n, DagNode*)
{
	auto& as = *n.explore;
	unique_ptr<Transition> t(new Transition(nextState, ++ as.transitionCount));

	DagNode* eventDag = static_cast<StateEventSystemGraph<PL>*>(this)->makeProofDag(as);	// create a proof term
	propLabel->updateEventLabel(eventDag, *t);	// compute all event props and store the formula event props

	if (as.transitionPtrSet.insert(t.get()).second)		// if a new transition identified
	{
		n.transitions.push_back(std::move(t));
		return true;
	}
	return false;
}

template <typename PL> void
SystemGraphTraits<StateEventSystemGraph<PL>>::insertDeadlockTransition(unsigned int stateNr, State& n)
{
	Assert(n.explore->transitionCount == 0 && n.explore->transitionPtrSet.empty(),
			"StateEventSystemGraph::insertDeadlockTransition: not deadlock");

	unique_ptr<Transition> t(new Transition(stateNr, 0));	// 0 indicates a deadlock transition!
	DagNode* eventDag = static_cast<StateEventSystemGraph<PL>*>(this)->getDeadlockDag();
	propLabel->updateEventLabel(eventDag, *t);
	n.explore->transitionPtrSet.insert(t.get());
	n.transitions.push_back(std::move(t));
}

template <typename PL> bool
SystemGraphTraits<StateEventSystemGraph<PL>>::Transition::operator<(const Transition& t) const
{
	return BaseSystemGraphIterTraits::Transition::operator<(t) || PL::EventLabel::operator<(t);
}

} /* namespace modelChecker */
