/*
 * StatePropChecker
 *
 *  Created on: Dec 3, 2010
 *      Author: kquine
 */

#ifndef STATEPROPCHECKER_HH_
#define STATEPROPCHECKER_HH_
#include <memory>
#include "Interface/PropEvaluator.hh"
#include "PropTable/PropositionTable.hh"
#include "PropSet.hh"

namespace modelChecker {

class PropChecker
{
public:
	PropChecker(const vector<unsigned int>& propIds, const PropositionTable& propositions,
			const PropEvaluator& pe, RewritingContext& context);
	virtual ~PropChecker() = default;

	const vector<unsigned int>& getGroundPropIds() const;

	virtual unique_ptr<PropSet> computeCheckResult(DagNode* target);

private:
	const vector<unsigned int> propIds;					// either state props or event props (all ground)
	const PropositionTable& propositions;
	const PropEvaluator& pEvaluator;
	RewritingContext& context;
};

}

#endif /* STATEPROPCHECKER_HH_ */
