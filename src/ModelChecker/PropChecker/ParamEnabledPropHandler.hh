/*
 * ParamEnabledPropHandler.hh
 *
 *  Created on: Aug 29, 2013
 *      Author: kquine
 */

#ifndef PARAMENABLEDPROPHANDLER_HH_
#define PARAMENABLEDPROPHANDLER_HH_
#include "PropTable/ParamPropositionTable.hh"
#include "EnabledPropHandler.hh"

namespace modelChecker {

class ParamEnabledPropHandler: public EnabledPropHandler
{
public:
	ParamEnabledPropHandler(const vector<unsigned int>& groundFairEnbPropIds,
			const vector<unsigned int>& paramFairEnbPropIds, const ParamPropositionTable& propTable);

	unique_ptr<PropSet> computeEnabledProps(const vector<unique_ptr<PropSet>>& trueEventPropIds) const override;

private:
	const vector<unsigned int> paramFairEnabledPropIds;
	const ParamPropositionTable& paramPropTableRef;
};

} /* namespace modelChecker */
#endif /* PARAMENABLEDPROPHANDLER_HH_ */
