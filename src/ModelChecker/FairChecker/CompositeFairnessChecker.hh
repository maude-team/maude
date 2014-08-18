/*
 * CompositeFairnessChecker.hh
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

#ifndef COMPOSITEFAIRNESSCHECKER_HH_
#define COMPOSITEFAIRNESSCHECKER_HH_
#include "FairnessChecker.hh"
#include "FairSet/CompositeFairSet.hh"
#include "FairTable/FairnessTable.hh"

namespace modelChecker {

/**
 * A CompositeFairnessChecker. This is intended only for system graphs,
 * while composite checkers/fair-sets are also used for generalized Buchi automata.
 */
class CompositeFairnessChecker: public FairnessChecker
{
public:
	void addComponent(unique_ptr<FairnessChecker>&& checker);

	unsigned int getNrFairness() const override;
	unique_ptr<FairSet> computeAllFairness(const PropSet& trueProps) override;
	unique_ptr<FairSet> computeCompactFairness(const PropSet& trueProps) override;
	unique_ptr<FairSet> unzip(const FairSet& fs) const override;

private:
	vector<unique_ptr<FairnessChecker>> fairCheckers;	// own the checkers!
};

} /* namespace modelChecker */
#endif /* COMPOSITEFAIRNESSCHECKER_HH_ */
