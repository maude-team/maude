/*
 * RuleTransitionGraph.hh
 *
 *  Created on: Jul 29, 2014
 *      Author: kquine
 */

#ifndef RULETRANSITIONGRAPH_HH_
#define RULETRANSITIONGRAPH_HH_
#include "Interface/ProofTermGenerator.hh"

namespace modelChecker {

class RuleTransitionGraph
{
public:
	class Transition;

	RuleTransitionGraph(const ProofTermGenerator& ptg);
	DagNode* makeTransitionDag(const Transition& t, DagNode* stateDag, RewritingContext& context) const;

private:
	const ProofTermGenerator& ptGenerator;
};

class RuleTransitionGraph::Transition
{
	friend class RuleTransitionGraph;
public:
	Transition(const Rule* rule): rule(rule) {}
private:
	const Rule* rule;
};

} /* namespace modelChecker */

#endif /* RULETRANSITIONGRAPH_HH_ */
