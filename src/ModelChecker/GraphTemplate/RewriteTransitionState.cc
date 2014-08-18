/*
 * RewriteTransitionState.cc
 *
 *  Created on: Jun 24, 2011
 *      Author: kquine
 */

//	utility stuff
#include <memory>
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"

//	interface class definitions
#include "dagNode.hh"

#include "RewriteTransitionState.hh"

namespace modelChecker {

RewriteTransitionState::RewriteTransitionState(RewritingContext& parent, DagNode* stateDag):
		RewriteSearchState(parent.makeSubcontext(stateDag), NONE,
				RewriteSearchState::GC_CONTEXT | RewriteSearchState::SET_UNREWRITABLE | PositionState::SET_UNSTACKABLE,
				0, UNBOUNDED) {}

DagNode*
RewriteTransitionState::getNextStateDag(RewritingContext& parent)
{
	RewritingContext* context = getContext();
	bool success = findNextRewrite();
	transferCount(parent);

	if (success)
	{
		bool trace = RewritingContext::getTraceStatus();
		if (trace)
		{
			context->tracePreRuleRewrite(getDagNode(), getRule());
			if (context->traceAbort())
				return nullptr;
		}
		DagNode* replacement = getReplacement();
		RewriteSearchState::DagPair r = rebuildDag(replacement);
		const unique_ptr<RewritingContext> c(context->makeSubcontext(r.first));
		parent.incrementRlCount();
		if (trace)
		{
			c->tracePostRuleRewrite(r.second);
			if (c->traceAbort())
				return nullptr;
		}
		c->reduce();
		if (c->traceAbort())
			return nullptr;
		parent.addInCount(*c);
		return r.first;
	}
	else
		return nullptr;
}

}
