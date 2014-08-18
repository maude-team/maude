/*
 * BaseSystemGraphOnce.hh
 *
 *  Created on: Sep 23, 2013
 *      Author: kquine
 */

#ifndef BASESYSTEMGRAPHONCE_HH_
#define BASESYSTEMGRAPHONCE_HH_
#include "protectedDagNodeSet.hh"
#include "BaseSystemGraph.hh"

namespace modelChecker {

//
// A graph where transitions of a state are generated at once.
//
template <class T>
class BaseSystemGraphOnce: public BaseSystemGraph<T>
{
	friend class BaseSystemGraph<T>;
public:
	using typename BaseSystemGraph<T>::State;
	using typename BaseSystemGraph<T>::Transition;

	BaseSystemGraphOnce(RewritingContext& initial, const PropositionTable& propTable);

	unsigned int getNrVisitedStates() const final;
	unsigned int getNrVisitedTransitions(unsigned int stateNr) const final;

protected:
	//
	// template functions (to be implemented in subclasses)
	//
	unsigned int stateDag2index(DagNode* dag);
	DagNode* makeProofDag(const RewriteTransitionState& rts) const;
	DagNode* getDeadlockDag() const;
	void updateAllLabels(DagNode* sd, const vector<DagNode*>& pd, State& s, vector<unique_ptr<Transition>>& trs) const;

private:
	unsigned int insertState(DagNode* stateDag);					/* implements */
	int computeNextState(unsigned int stateNr, unsigned int index);	/* implements */

	int enableState(unsigned int stateNr);
};

struct BaseSystemGraphOnceTraits: public BaseSystemGraphTraits
{
	template <typename TRANSITION>
	struct State: public BaseSystemGraphTraits::State<TRANSITION>
	{
		unsigned int nrVisited = 0;
	};
};

} /* namespace modelChecker */

#include "BaseSystemGraphOnce.cc"

#endif /* BASESYSTEMGRAPHONCE_HH_ */
