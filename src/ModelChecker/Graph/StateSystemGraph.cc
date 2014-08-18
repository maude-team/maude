/*
 * StateSystemGraph.cc
 *
 *  Created on: Sep 11, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

// interface class definitions
#include "symbol.hh"
#include "dagNodeSet.hh"

// core class definitions
#include "rewritingContext.hh"

// ltlr definitions
#include "StateSystemGraph.hh"

namespace modelChecker {

template <typename PL>
StateSystemGraph<PL>::StateSystemGraph(unique_ptr<PL>&& pl, RewritingContext& initial,
		const ProofTermGenerator& ptg, const PropositionTable& propTable):
			Super(initial,propTable), RuleTransitionGraph(ptg), Traits(move(pl)) {}

template <typename PL>
template <typename STATE> bool
SystemGraphTraits<StateSystemGraph<PL>>::satisfiesStateProp(unsigned int propId, const STATE& s) const
{
	return propLabel->satisfiesStateProp(propId, s);
}

template <typename PL>
template <typename TRANSITION> bool
SystemGraphTraits<StateSystemGraph<PL>>::satisfiesEventProp(unsigned int, const TRANSITION&) const
{
	throw logic_error("StateSystemGraph::satisfiesEventProp.");
}

template <typename PL>
template <typename STATE> unique_ptr<PropSet>
SystemGraphTraits<StateSystemGraph<PL>>::updateStateLabel(DagNode* stateDag, STATE& s) const
{
	return propLabel->updateStateLabel(stateDag, s);
}

template <typename PL>
template <typename STATE> bool
SystemGraphTraits<StateSystemGraph<PL>>::insertTransition(unsigned int nextState, STATE& n, DagNode*) const
{
	if (n.explore->nextStateSet.insert(nextState).second)	// if a new transition identified
	{
		n.transitions.emplace_back(new Transition(nextState, n.explore->getRule()));
		return true;
	}
	return false;
}

template <typename PL>
template <typename STATE> void
SystemGraphTraits<StateSystemGraph<PL>>::insertDeadlockTransition(unsigned int stateNr, STATE& n) const
{
	Assert(n.explore->nextStateSet.empty(), "StateSystemGraph::insertDeadlockTransition: not deadlock");
	n.explore->nextStateSet.insert(stateNr);
	n.transitions.emplace_back(new Transition(stateNr, nullptr));
}

} /* namespace modelChecker */
