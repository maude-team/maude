/*
 * ParamWeakFairSet.hh
 *
 *  Created on: Sep 11, 2013
 *      Author: kquine
 */

#ifndef PARAMWEAKFAIRSET_HH_
#define PARAMWEAKFAIRSET_HH_
#include "WeakFairSet.hh"
#include "ParamRealizedSet.hh"

namespace modelChecker {

class ParamWeakFairSet: public WeakFairSet, public ParamRealizedSet
{
public:
	struct Goal;

	ParamWeakFairSet(WeakFairSet&& f);

	void paste(const FairSet& f) override;
	void merge(const FairSet& f, const AbstractFairnessTable& table) override;

	unique_ptr<FairSet> clone() const override;

	void dump(ostream& o) const override;

	unique_ptr<FairSet::Goal> makeFairGoal(const AbstractFairnessTable& table) const override;

};

class ParamWeakFairSet::Goal: public WeakFairSet::Goal
{
public:
	Goal(unsigned int nrFairness, const ParamWeakFairSet& fs);
	bool update(const FairSet& f, const AbstractFairnessTable& table) override;
};


} /* namespace modelChecker */
#endif /* PARAMWEAKFAIRSET_HH_ */
