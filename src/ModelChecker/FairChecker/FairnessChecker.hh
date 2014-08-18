/*
 * FairnessChecker.hh
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

#ifndef FAIRNESSCHECKER_HH_
#define FAIRNESSCHECKER_HH_
#include "bdd.hh"
#include "natSet.hh"
#include "FairSet/FairSet.hh"
#include "PropChecker/PropSet.hh"
#include "Utility/BddUtil.hh"

namespace modelChecker {

/**
 * An interface for checking fairness conditions.
 */
class FairnessChecker
{
public:
	virtual ~FairnessChecker() = default;

	virtual unsigned int getNrFairness() const = 0;
	virtual unique_ptr<FairSet> computeAllFairness(const PropSet& trueProps) = 0;		// for state-only or event-only
	virtual unique_ptr<FairSet> computeCompactFairness(const PropSet& trueProps) = 0;	// for state/event
	virtual unique_ptr<FairSet> unzip(const FairSet& fs) const = 0;

protected:
	bool satisfiesFairFormula(const PropSet& trueProps, Bdd formula) const;

};

inline bool
FairnessChecker::satisfiesFairFormula(const PropSet& trueProps, Bdd formula) const
{
	return BddUtil::satisfiesFormula(formula, [&trueProps] (unsigned int propId) { return trueProps.isTrue(propId); });
}

} /* namespace modelChecker */
#endif /* FAIRNESSCHECKER_HH_ */


