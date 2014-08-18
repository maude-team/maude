/*
 * PropCheckerFactory.hh
 *
 *  Created on: Sep 12, 2013
 *      Author: kquine
 */

#ifndef PROPCHECKERFACTORY_HH_
#define PROPCHECKERFACTORY_HH_
#include "PropTable/PropositionTable.hh"
#include "PropChecker.hh"
#include "EnabledPropHandler.hh"

namespace modelChecker {

class PropCheckerFactory
{
public:
	static unique_ptr<PropChecker> createChecker(const vector<unsigned int>& targets,
			PropositionTable& propTable, const PropEvaluator& pe, RewritingContext& context);

	static unique_ptr<EnabledPropHandler> createHandler(const vector<unsigned int>& enabledProps,
			unsigned int nrFormulaPropIds, const PropositionTable& propTable);
};

} /* namespace modelChecker */
#endif /* PROPCHECKERFACTORY_HH_ */
