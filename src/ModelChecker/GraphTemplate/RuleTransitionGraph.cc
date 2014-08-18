/*
 * RuleTransitionGraph.cc
 *
 *  Created on: Jul 29, 2014
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
#include "RuleTransitionGraph.hh"

namespace modelChecker {

RuleTransitionGraph::RuleTransitionGraph(const ProofTermGenerator& ptg): ptGenerator(ptg) {}

DagNode*
RuleTransitionGraph::makeTransitionDag(const Transition& t, DagNode* /* stateDag */, RewritingContext& context) const
{
	if (t.rule)
	{
		DagNode* d = ptGenerator.makeProofDag(nullptr, *t.rule, nullptr);
		d->reduce(context);
		return d;
	}
	else
		return ptGenerator.getDeadlockDag();
}


} /* namespace modelChecker */
