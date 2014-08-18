/*
 * WeakFairSet.hh
 *
 *  Created on: Dec 10, 2010
 *      Author: kquine
 */

#ifndef WEAKFAIRSET_HH_
#define WEAKFAIRSET_HH_
#include "natSet.hh"
#include "FairSet.hh"

namespace modelChecker {

class WeakFairSet: public FairSet
{
public:
	struct Goal;
	struct Bad;

	WeakFairSet() = default;
	WeakFairSet(const WeakFairSet&) = default;
	WeakFairSet(WeakFairSet&& other) noexcept;

	void setFalsified(unsigned int fairId);
	bool getFalsified(unsigned int fairId) const;
	void swapFalsified(NatSet& falsified);

	virtual void paste(const FairSet& f) override;
	virtual void merge(const FairSet& f, const AbstractFairnessTable& table) override;

	bool isSatisfied() const override;
	bool operator<(const FairSet& fs) const override;

	virtual unique_ptr<FairSet> clone() const override;
	unique_ptr<FairSet::Goal> makeFairGoal(const AbstractFairnessTable& table) const override;
	unique_ptr<FairSet::Bad> makeBadGoal() const override;

	void dump(ostream& o) const override;

protected:
	NatSet falsifiedWeakFair;
};


class WeakFairSet::Goal: public FairSet::Goal
{
public:
	Goal(unsigned int nrFairness, const WeakFairSet& f);
	bool empty() const override;
	virtual bool update(const FairSet& f, const AbstractFairnessTable& table) override;
	void dump(ostream& o) const override;
protected:
	NatSet weakFairGoal;	// all fairness indices
};

struct WeakFairSet::Bad: public FairSet::Bad
{
	bool isBad(const FairSet&, const AbstractFairnessTable&) const override	{ return false; }
	bool empty() const override												{ return true; }
	void merge(const FairSet::Bad& ) override								{}
	void dump(ostream& o) const override									{ o << "[]"; }
};

}

#endif /* WEAKFAIRSET_HH_ */
