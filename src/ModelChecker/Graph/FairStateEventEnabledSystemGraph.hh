/*
 * FairStateEventEnabledSystemGraph.hh
 *
 *  Created on: Aug 27, 2013
 *      Author: kquine
 */

#ifndef FAIRSTATEEVENTENABLEDSYSTEMGRAPH_HH_
#define FAIRSTATEEVENTENABLEDSYSTEMGRAPH_HH_
#include "StateEventEnabledSystemGraph.hh"
#include "GraphTemplate/CompactProofTermTransitionGraph.hh"
#include "GraphTemplate/DefaultStateDagContainer.hh"

namespace modelChecker {

template <typename PL, typename FL>
class FairStateEventEnabledSystemGraph:
		public BaseSystemGraphOnce<FairStateEventEnabledSystemGraph<PL,FL>>,
		private CompactProofTermTransitionGraph,
		private DefaultStateDagContainer,
		private SystemGraphTraits<FairStateEventEnabledSystemGraph<PL,FL>>
{
	friend class BaseSystemGraph<FairStateEventEnabledSystemGraph<PL,FL>>;
	friend class BaseSystemGraphOnce<FairStateEventEnabledSystemGraph<PL,FL>>;
	friend class SystemGraphTraits<FairStateEventEnabledSystemGraph<PL,FL>>;

	using Super =	BaseSystemGraphOnce<FairStateEventEnabledSystemGraph<PL,FL>>;
	using Traits =	SystemGraphTraits<FairStateEventEnabledSystemGraph<PL,FL>>;

public:
	using typename Traits::State;
	using typename Traits::Transition;

	FairStateEventEnabledSystemGraph(unique_ptr<PL>&& sepl, unique_ptr<FL>&& sefl, unique_ptr<EnabledPropHandler>&& enpc,
			RewritingContext& initial, const ProofTermGenerator& ptg, const PropositionTable& propTable);

	unique_ptr<FairSet> makeFairSet(unsigned int stateNr, unsigned int transitionNr) const;

private:
	using DefaultStateDagContainer::index2StateDag;				/* implements */
	using DefaultStateDagContainer::stateDag2index;				/* implements */
	using CompactProofTermTransitionGraph::makeTransitionDag;	/* implements */
	using CompactProofTermTransitionGraph::makeProofDag;		/* implements */
	using CompactProofTermTransitionGraph::getDeadlockDag;		/* implements */
	using Traits::satisfiesStateProp;							/* implements */
	using Traits::satisfiesEventProp;							/* implements */
	using Traits::updateAllLabels;								/* implements */
};

template <typename PL, typename FL>
class SystemGraphTraits<FairStateEventEnabledSystemGraph<PL,FL>>: public SystemGraphTraits<StateEventEnabledSystemGraph<PL>>
{
public:
	struct State;
	struct Transition;

	SystemGraphTraits(unique_ptr<PL>&& pl, unique_ptr<FL>&& fl, unique_ptr<EnabledPropHandler>&& enpc):
		SystemGraphTraits<StateEventEnabledSystemGraph<PL>>(move(pl),move(enpc)), fairLabel(move(fl)) {}

	void updateAllLabels(DagNode* stateDag, const vector<DagNode*>& proofDags,
			State& s, vector<unique_ptr<Transition>>& trs);

protected:
	const unique_ptr<FL> fairLabel;
};

template <typename PL, typename FL>
struct SystemGraphTraits<FairStateEventEnabledSystemGraph<PL,FL>>::State:
	public BaseSystemGraphOnceTraits::State<Transition>, public PL::StateLabel, public FL::StateLabel {};

template <typename PL, typename FL>
struct SystemGraphTraits<FairStateEventEnabledSystemGraph<PL,FL>>::Transition:
	public BaseSystemGraphOnceTraits::Transition,
	public CompactProofTermTransitionGraph::Transition, public PL::EventLabel, public FL::EventLabel
{
	Transition(unsigned int nextState, unsigned int transitionIndex):
		BaseSystemGraphOnceTraits::Transition{nextState},
		CompactProofTermTransitionGraph::Transition(transitionIndex) {}
	bool operator<(const Transition& t) const;
};

} /* namespace modelChecker */

#include "FairStateEventEnabledSystemGraph.cc"

#endif /* FAIRSTATEEVENTENABLEDSYSTEMGRAPH_HH_ */
