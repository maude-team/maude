/*
 * FairStateEventSystemGraph.cc
 *
 *  Created on: Aug 27, 2013
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
#include "FairStateEventSystemGraph.hh"

namespace modelChecker {

template <typename PL, typename FL>
FairStateEventSystemGraph<PL,FL>::FairStateEventSystemGraph(unique_ptr<PL>&& sepl, unique_ptr<FL>&& sefl,
		RewritingContext& initial, const ProofTermGenerator& ptg, const PropositionTable& propTable):
			Super(initial,propTable), CompactProofTermTransitionGraph(ptg),
			propLabel(move(sepl)), fairLabel(move(sefl)) {}

template <typename PL, typename FL> unique_ptr<FairSet>
FairStateEventSystemGraph<PL,FL>::makeFairSet(unsigned int stateNr, unsigned int transitionNr) const
{
	return this->fairLabel->makeFairSet(static_cast<State*>(this->seen[stateNr].get()),
			static_cast<Transition*>(this->seen[stateNr]->transitions[transitionNr].get()));
}

template <typename PL, typename FL> bool
SystemGraphTraits<FairStateEventSystemGraph<PL,FL>>::satisfiesStateProp(unsigned int propId, const State& s) const
{
	return static_cast<const FairStateEventSystemGraph<PL,FL>*>(this)->propLabel->satisfiesStateProp(propId, s);
}

template <typename PL, typename FL> bool
SystemGraphTraits<FairStateEventSystemGraph<PL,FL>>::satisfiesEventProp(unsigned int propId, const Transition& t) const
{
	return static_cast<const FairStateEventSystemGraph<PL,FL>*>(this)->propLabel->satisfiesEventProp(propId, t);
}

template <typename PL, typename FL> void
SystemGraphTraits<FairStateEventSystemGraph<PL,FL>>::updateAllLabels(DagNode* stateDag, const vector<DagNode*>& proofDags,
		State& s, vector<unique_ptr<Transition> >& trs)
{
	const auto self = static_cast<const FairStateEventSystemGraph<PL,FL>*>(this);

	// compute and store all state props (for s)
	unique_ptr<PropSet> trueStateProps = self->propLabel->updateStateLabel(stateDag,s);
	if (trueStateProps)
		self->fairLabel->updateStateLabel(*trueStateProps,s);		// compute all state fairness conditions

	vector<unique_ptr<PropSet>> trueEventProps(trs.size());

	// compute and store all event prop (for transitions)
	for (unsigned int i = 0; i < trs.size(); ++i)
	{
		trueEventProps[i] = self->propLabel->updateEventLabel(proofDags[i],*trs[i]);
		PropSet::merge(trueEventProps[i],trueStateProps);						// transfer truth
		if (trueEventProps[i])
			self->fairLabel->updateEventLabel(*trueEventProps[i],*trs[i]);	// compute and store all SE fairness conditions
	}
}

template <typename PL, typename FL> bool
SystemGraphTraits<FairStateEventSystemGraph<PL,FL>>::Transition::operator<(const Transition& t) const
{
	return BaseSystemGraphOnceTraits::Transition::operator<(t) ||
			PL::EventLabel::operator<(t) || FL::EventLabel::operator<(t);
}

} /* namespace modelChecker */
