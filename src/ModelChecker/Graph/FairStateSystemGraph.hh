/*
 * FairStateSystemGraph.hh
 *
 *  Created on: Aug 27, 2013
 *      Author: kquine
 */

#ifndef FAIRSTATESYSTEMGRAPH_HH_
#define FAIRSTATESYSTEMGRAPH_HH_
#include "StateSystemGraph.hh"
#include "FairChecker/FairnessChecker.hh"
#include "GraphTemplate/RuleTransitionGraph.hh"
#include "GraphTemplate/DefaultStateDagContainer.hh"

namespace modelChecker {

template <typename PL, typename FL>
class FairStateSystemGraph:
		public BaseSystemGraphIter<FairStateSystemGraph<PL,FL>>,
		private RuleTransitionGraph,
		private DefaultStateDagContainer,
		private SystemGraphTraits<FairStateSystemGraph<PL,FL>>
{
	friend class BaseSystemGraph<FairStateSystemGraph>;
	friend class BaseSystemGraphIter<FairStateSystemGraph>;
	friend class SystemGraphTraits<FairStateSystemGraph<PL,FL>>;

	using Super = 	BaseSystemGraphIter<FairStateSystemGraph<PL,FL>>;
	using Traits = 	SystemGraphTraits<FairStateSystemGraph<PL,FL>>;

public:
	using typename Traits::State;
	using typename Traits::Transition;

	FairStateSystemGraph(unique_ptr<PL>&& spl, unique_ptr<FL>&& sfl,
			RewritingContext& initial, const ProofTermGenerator& ptg, const PropositionTable& propTable);

	unique_ptr<FairSet> makeFairSet(unsigned int stateNr, unsigned int transitionNr) const;

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


template <typename PL, typename FL>
class SystemGraphTraits<FairStateSystemGraph<PL,FL>>: public SystemGraphTraits<StateSystemGraph<PL>>
{
public:
	struct State;
	using typename SystemGraphTraits<StateSystemGraph<PL>>::Transition;
	using typename SystemGraphTraits<StateSystemGraph<PL>>::ActiveState;

	SystemGraphTraits(unique_ptr<PL>&& pl, unique_ptr<FL>&& fl):
		SystemGraphTraits<StateSystemGraph<PL>>(move(pl)), fairLabel(move(fl)) {}

	void updateStateLabel(DagNode* stateDag, State& s) const;

protected:
	const unique_ptr<FL> fairLabel;

private:
	using PreState = BaseSystemGraphIterTraits::State<ActiveState,Transition>;
};

template <typename PL, typename FL>
struct SystemGraphTraits<FairStateSystemGraph<PL,FL>>::State:
	public PreState, public PL::StateLabel, public FL::StateLabel {};

} /* namespace modelChecker */

#include "FairStateSystemGraph.cc"	// to separate the implementation for the template

#endif /* FAIRSTATESYSTEMGRAPH_HH_ */
