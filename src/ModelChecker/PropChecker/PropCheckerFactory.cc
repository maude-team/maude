/*
 * PropCheckerFactory.cc
 *
 *  Created on: Sep 12, 2013
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
#include "ParamEnabledPropHandler.hh"
#include "PropCheckerFactory.hh"

namespace modelChecker {

unique_ptr<PropChecker>
PropCheckerFactory::createChecker(const vector<unsigned int>& targetIds,
		PropositionTable& propTable, const PropEvaluator& pe, RewritingContext& context)
{
	if (targetIds.empty())
		return nullptr;
	else
	{
		vector<unsigned int> groundIds, paramIds;
		for (auto k : targetIds)
			(propTable.isParamProp(k) ? paramIds : groundIds).push_back(k);

		if (paramIds.empty())
			return unique_ptr<PropChecker>(new PropChecker(groundIds, propTable, pe, context));	// no param
		else
			return unique_ptr<PropChecker>(new ParamPropChecker(groundIds, paramIds,
					static_cast<ParamPropositionTable&>(propTable), pe, context));
	}

}

unique_ptr<EnabledPropHandler>
PropCheckerFactory::createHandler(const vector<unsigned int>& enabledProps,
		unsigned int nrFormulaPropIds, const PropositionTable& propTable)
{
	if ( enabledProps.empty() )
		return nullptr;
	else
	{
		vector<unsigned int> fairEnbIds;
		for (auto k : enabledProps) { if ( k >= nrFormulaPropIds ) fairEnbIds.push_back(k); }

		vector<unsigned int> groundIds, paramIds;
		for (auto k : fairEnbIds) { (propTable.isParamProp(k) ? paramIds : groundIds).push_back(k); }

		if (paramIds.empty())
			return unique_ptr<EnabledPropHandler>(new EnabledPropHandler(groundIds, propTable));	// no param
		else
			return unique_ptr<EnabledPropHandler>(new ParamEnabledPropHandler(groundIds,
					paramIds, static_cast<const ParamPropositionTable&>(propTable)));
	}
}


} /* namespace modelChecker */
