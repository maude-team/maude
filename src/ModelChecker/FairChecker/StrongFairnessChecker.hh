/*
 * StrongFairnessChecker.hh
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

#ifndef STRONGFAIRNESSCHECKER_HH_
#define STRONGFAIRNESSCHECKER_HH_
#include "FairnessChecker.hh"
#include "FairSet/StrongFairSet.hh"
#include "FairTable/FairnessTable.hh"

namespace modelChecker {

class StrongFairnessChecker: public FairnessChecker
{
public:
	StrongFairnessChecker(const vector<unsigned int>& strongFairIds, StrongFairnessTable& fTable);

	virtual unsigned int getNrFairness() const override;
	virtual unique_ptr<FairSet> computeAllFairness(const PropSet& trueProps) override;
	virtual unique_ptr<FairSet> computeCompactFairness(const PropSet& trueProps) override;
	virtual unique_ptr<FairSet> unzip(const FairSet& fs) const override;

private:
	const vector<unsigned int> strongFairIds;
	StrongFairnessTable& fTable;
};


} /* namespace modelChecker */
#endif /* STRONGFAIRNESSCHECKER_HH_ */
