/*
 * ParamEnabledPropHandler.cc
 *
 *  Created on: Aug 29, 2013
 *      Author: kquine
 */

// utility stuff
#include <memory>
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "ParamEnabledPropHandler.hh"

namespace modelChecker {

ParamEnabledPropHandler::ParamEnabledPropHandler(const vector<unsigned int>& grFairEnbPropIds,
		const vector<unsigned int>& prFairEnbPropIds, const ParamPropositionTable& propTable):
				EnabledPropHandler(grFairEnbPropIds, propTable),
				paramFairEnabledPropIds(prFairEnbPropIds), paramPropTableRef(propTable) {}

unique_ptr<PropSet>
ParamEnabledPropHandler::computeEnabledProps(const vector<unique_ptr<PropSet>>& trueEventPropIds) const
{
	unique_ptr<PropSet> res = EnabledPropHandler::computeEnabledProps(trueEventPropIds);
	for (auto i: paramFairEnabledPropIds)
	{
		auto evtId = propositions.getEnabledEventId(i);
		for (auto& j  : trueEventPropIds)
			res->setTrueParamSubst(i, j->getTrueParamSubst(evtId));
	}
	return res;
}

} /* namespace modelChecker */
