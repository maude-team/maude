/*
 * StrongFairSet.hh
 *
 *  Created on: Dec 10, 2010
 *      Author: kquine
 */

#ifndef STRONGFAIRSET_HH_
#define STRONGFAIRSET_HH_
#include "natSet.hh"
#include "FairSet.hh"

namespace modelChecker {

class StrongFairSet: public FairSet
{
public:
	struct Goal;
	struct Bad;

	StrongFairSet() = default;
	StrongFairSet(const StrongFairSet& ) = default;
	StrongFairSet(StrongFairSet&& other) noexcept;

	void setSuppFalse(unsigned int fairId);
	void setConsFalse(unsigned int fairId);

	bool getSuppFalse(unsigned int fairId) const;
	bool getConsFalse(unsigned int fairId) const;

	virtual void paste(const FairSet& f) override;
	virtual void merge(const FairSet& f, const AbstractFairnessTable& table) override;

	bool isSatisfied() const override;
	bool operator<(const FairSet& fs) const override;

	virtual unique_ptr<FairSet> clone() const override;
	unique_ptr<FairSet::Goal> makeFairGoal(const AbstractFairnessTable& table) const override;
	virtual unique_ptr<FairSet::Bad> makeBadGoal() const override;

	void dump(ostream& o) const override;

protected:
	NatSet falsifiedSupp;
	NatSet falsifiedCons;
};


class StrongFairSet::Goal: public FairSet::Goal
{
public:
	Goal(unsigned int nrFairness, const StrongFairSet& fs);
	bool empty() const override;
	bool update(const FairSet& f, const AbstractFairnessTable& table) override;
	void dump(ostream& o) const override;
protected:
	NatSet strongFairGoal;
};

struct StrongFairSet::Bad: public FairSet::Bad
{
public:
	Bad(const StrongFairSet& fs);
	virtual bool isBad(const FairSet& f, const AbstractFairnessTable& table) const override;
	bool empty() const override;
	void merge(const FairSet::Bad& b) override;
	void dump(ostream& o) const override;
protected:
	NatSet badFairs;
};


}

#endif /* STRONGFAIRSET_HH_ */
