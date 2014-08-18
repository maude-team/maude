/*
 * ParamPropChecker.hh
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

#ifndef PARAMPROPCHECKER_HH_
#define PARAMPROPCHECKER_HH_
#include "PropChecker.hh"
#include "RealizedPropGenerator.hh"

namespace modelChecker {

class ParamPropChecker: public PropChecker, private RealizedPropGenerator
{
public:
	ParamPropChecker(const vector<unsigned int>& groundPropIds, const vector<unsigned int>& paramPropIds,
			ParamPropositionTable& propTable, const PropEvaluator& pe, RewritingContext& context);

	unique_ptr<PropSet> computeCheckResult(DagNode* target) override;
};

} /* namespace modelChecker */
#endif /* PARAMPROPCHECKER_HH_ */
