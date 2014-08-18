/*
 * EnabledPropHandler.cc
 *
 *  Created on: Aug 28, 2013
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
#include "EnabledPropHandler.hh"

namespace modelChecker {

EnabledPropHandler::EnabledPropHandler(const vector<unsigned int>& fairEnbPropIds, const PropositionTable& propositions):
		fairEnabledPropIds(fairEnbPropIds), propositions(propositions) {}

unique_ptr<PropSet>
EnabledPropHandler::computeEnabledProps(const vector<unique_ptr<PropSet>>& trueEventPropIds) const
{
	unique_ptr<PropSet> result(new PropSet);
	for (auto i: fairEnabledPropIds)
	{
		auto propId = propositions.getEnabledEventId(i);
		for (auto& j  : trueEventPropIds)
		{
			if (j->isTrue(propId))
			{
				result->setTrue(i);
				break;
			}
		}
	}
	return result;
}


} /* namespace modelChecker */
