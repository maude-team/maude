/*
 * RewriteTransitionState.hh
 *
 *  Created on: Jun 24, 2011
 *      Author: kquine
 */

#ifndef REWRITETRANSITIONSTATE_HH_
#define REWRITETRANSITIONSTATE_HH_
#include "rewriteSearchState.hh"

namespace modelChecker {

class RewriteTransitionState: private RewriteSearchState
{
public:
	RewriteTransitionState(RewritingContext& parent, DagNode* stateDag);

	RewriteTransitionState(const RewriteTransitionState&) = delete;
	RewriteTransitionState& operator=(const RewriteTransitionState&) = delete;

	DagNode* getNextStateDag(RewritingContext& parent);

	const PositionState* getPosition() const	{ return this; }
	const Rule* getRule() const					{ return RewriteSearchState::getRule(); }
	const Substitution* getSubstitution() const	{ return getContext(); }
};

}

#endif /* REWRITETRANSITIONSTATE_HH_ */
