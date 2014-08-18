/*
 * LabelSymbolChecker.cc
 *
 *  Created on: Dec 3, 2010
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "PropChecker.hh"

namespace modelChecker {

PropChecker::PropChecker(const vector<unsigned int>& propIds, const PropositionTable& propositions,
		const PropEvaluator& pe, RewritingContext& context):
				propIds(propIds), propositions(propositions), pEvaluator(pe), context(context)  {}

const vector<unsigned int>&
PropChecker::getGroundPropIds() const
{
	return propIds;
}

unique_ptr<PropSet>
PropChecker::computeCheckResult(DagNode* target)
{
	unique_ptr<PropSet> result(new PropSet);
	for (auto i = propIds.crbegin(); i != propIds.crend(); ++i)
	{
		if (pEvaluator.computeProp(target, propositions.index2DagNode(*i), context))
			result->setTrue(*i);
	}
	return result;
}

}
