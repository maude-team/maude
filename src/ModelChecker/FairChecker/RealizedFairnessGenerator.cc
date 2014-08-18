/*
 * RealizedFairnessGenerator.cc
 *
 *  Created on: Sep 8, 2013
 *      Author: kquine
 */

//      utility stuff
#include <memory>
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "temporal.hh"
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "RealizedFairnessGenerator.hh"

namespace modelChecker {

RealizedFairnessGenerator::RealizedFairnessGenerator(const vector<unsigned int>& paramFairIds,
		RealizedFairnessTable& fairTable):
	paramFairIds(paramFairIds), fairTable(fairTable) {}

deque<pair<unsigned int,NatSet>>
RealizedFairnessGenerator::generateRealizedFairness(const PropSet& ps)
{
	deque<pair<unsigned int,NatSet>> result;
	for (auto i : paramFairIds)
	{
		const ParamSubstitutionBuilder& builder = fairTable.getSubstBuilder(i);
		builder.buildRealizedFairness(ps, i, fairTable, result);
	}
	return result;
}



} /* namespace modelChecker */
