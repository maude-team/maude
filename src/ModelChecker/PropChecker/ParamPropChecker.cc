/*
 * ParamPropChecker.cc
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "ParamPropChecker.hh"

namespace modelChecker {

ParamPropChecker::ParamPropChecker(const vector<unsigned int>& groundPropIds, const vector<unsigned int>& paramPropIds,
		ParamPropositionTable& propTable, const PropEvaluator& pe, RewritingContext& context):
				PropChecker(groundPropIds, propTable, pe, context),
				RealizedPropGenerator(paramPropIds, propTable, pe, context) {}

unique_ptr<PropSet>
ParamPropChecker::computeCheckResult(DagNode* target)
{
	unique_ptr<PropSet> res = PropChecker::computeCheckResult(target);
	RealizedPropGenerator::generateRealizedProps(target, *res);
	return res;
}


} /* namespace modelChecker */
