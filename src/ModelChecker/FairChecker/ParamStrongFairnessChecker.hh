/*
 * ParamStrongFairnessChecker.hh
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

#ifndef PARAMSTRONGFAIRNESSCHECKER_HH_
#define PARAMSTRONGFAIRNESSCHECKER_HH_
#include "StrongFairnessChecker.hh"
#include "RealizedFairnessGenerator.hh"
#include "FairTable/ParamFairnessTable.hh"

namespace modelChecker {

class ParamStrongFairnessChecker: public StrongFairnessChecker, private RealizedFairnessGenerator
{
public:
	ParamStrongFairnessChecker(const vector<unsigned int>& strongFairIds,
			const vector<unsigned int>& paramStrongFairIds, ParamStrongFairnessTable& fTable);

	unsigned int getNrFairness() const override;
	unique_ptr<FairSet> computeAllFairness(const PropSet& trueProps) override;
	unique_ptr<FairSet> computeCompactFairness(const PropSet& trueProps) override;
	unique_ptr<FairSet> unzip(const FairSet& fs) const override;

private:
	indexed_set<unsigned int> compactIndices;	// for compact fairness ids
	const ParamStrongFairnessTable& fTableRef;
};

} /* namespace modelChecker */
#endif /* PARAMSTRONGFAIRNESSCHECKER_HH_ */
