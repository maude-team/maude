/*
 * CompactProofTermTransitionGraph.hh
 *
 *  Created on: Jul 29, 2014
 *      Author: kquine
 */

#ifndef COMPACTPROOFTERMTRANSITIONGRAPH_HH_
#define COMPACTPROOFTERMTRANSITIONGRAPH_HH_
#include "Interface/ProofTermGenerator.hh"

namespace modelChecker {

class CompactProofTermTransitionGraph
{
public:
	class Transition;

	CompactProofTermTransitionGraph(const ProofTermGenerator& ptg);
	DagNode* makeTransitionDag(const Transition& t, DagNode* stateDag, RewritingContext& context) const;

	DagNode* makeProofDag(const RewriteTransitionState& rts) const;
	DagNode* getDeadlockDag() const;

private:
	const ProofTermGenerator& ptGenerator;
};


inline DagNode*
CompactProofTermTransitionGraph::makeProofDag(const RewriteTransitionState& rts) const
{
	return ptGenerator.makeProofDag(rts.getPosition(),*rts.getRule(),rts.getSubstitution());
}

inline DagNode*
CompactProofTermTransitionGraph::getDeadlockDag() const
{
	return ptGenerator.getDeadlockDag();
}

class CompactProofTermTransitionGraph::Transition
{
	friend class CompactProofTermTransitionGraph;
public:
	Transition(unsigned int index): transitionIndex(index) {}
private:
	const unsigned int transitionIndex;		// to construct a proofterm (NOTE: 0 means deadlock)
};

} /* namespace modelChecker */

#endif /* COMPACTPROOFTERMTRANSITIONGRAPH_HH_ */
