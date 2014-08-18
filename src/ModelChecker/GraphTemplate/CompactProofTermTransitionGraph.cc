/*
 * CompactProofTermTransitionGraph.cc
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
#include "RewriteTransitionState.hh"
#include "CompactProofTermTransitionGraph.hh"

namespace modelChecker {

CompactProofTermTransitionGraph::CompactProofTermTransitionGraph(const ProofTermGenerator& ptg): ptGenerator(ptg) {}

DagNode*
CompactProofTermTransitionGraph::makeTransitionDag(const Transition& t, DagNode* stateDag, RewritingContext& context) const
{
	if (t.transitionIndex > 0)
	{
		unique_ptr<RewriteTransitionState>  tr(new RewriteTransitionState(context, stateDag));
		for (unsigned int i = 0; i < t.transitionIndex; ++i)
			tr->getNextStateDag(context);
		DagNode* d = makeProofDag(*tr);
		d->reduce(context);
		return d;
	}
	else
		return getDeadlockDag();
}

} /* namespace modelChecker */
