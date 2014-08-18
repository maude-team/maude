/*
 * WeakFairnessChecker.hh
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

#ifndef WEAKFAIRNESSCHECKER_HH_
#define WEAKFAIRNESSCHECKER_HH_
#include "FairnessChecker.hh"
#include "FairSet/WeakFairSet.hh"
#include "FairTable/FairnessTable.hh"

namespace modelChecker {

class WeakFairnessChecker: public FairnessChecker
{
public:
	WeakFairnessChecker(const vector<unsigned int>& weakFairIds, WeakFairnessTable& fTable);

	virtual unsigned int getNrFairness() const override;
	virtual unique_ptr<FairSet> computeAllFairness(const PropSet& trueProps) override;
	virtual unique_ptr<FairSet> computeCompactFairness(const PropSet& trueProps) override;
	virtual unique_ptr<FairSet> unzip(const FairSet& fs) const;

private:
	const vector<unsigned int> weakFairIds;
	WeakFairnessTable& fTable;
};

} /* namespace modelChecker */
#endif /* WEAKFAIRNESSCHECKER_HH_ */
