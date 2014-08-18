/*
 * CompositeFairSet.hh
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

#ifndef COMPOSITEFAIRSET_HH_
#define COMPOSITEFAIRSET_HH_
#include <memory>
#include "FairSet.hh"
#include "FairTable/CompositeFairnessTable.hh"

namespace modelChecker {

class CompositeFairSet: public FairSet
{
public:
	struct Goal;
	struct Bad;

	void addComponent(unique_ptr<FairSet>&& fs);
	const FairSet& getComponent(unsigned int i) const;

	void paste(const FairSet& f) override;
	void merge(const FairSet& f, const AbstractFairnessTable& table) override;

	bool isSatisfied() const override;
	bool operator<(const FairSet& f) const override;

	unique_ptr<FairSet> clone() const override;
	unique_ptr<FairSet::Goal> makeFairGoal(const AbstractFairnessTable& table) const override;
	unique_ptr<FairSet::Bad> makeBadGoal() const override;

	void dump(ostream& o) const override;
private:
	vector<unique_ptr<FairSet>> fairSets;	// own the fairsets!
};

class CompositeFairSet::Goal: public FairSet::Goal
{
public:
	Goal(const CompositeFairSet& fs, const AbstractFairnessTable& table);
	bool empty() const override;
	bool update(const FairSet& f, const AbstractFairnessTable& table) override;
	void dump(ostream& o) const override;

private:
	vector<unique_ptr<FairSet::Goal>> fairGoals;
};

struct CompositeFairSet::Bad: public FairSet::Bad
{
public:
	Bad(const CompositeFairSet& fs);
	bool isBad(const FairSet& f, const AbstractFairnessTable& table) const override;
	bool empty() const override;
	void merge(const FairSet::Bad& b) override;
	void dump(ostream& o) const override;
private:
	vector<unique_ptr<FairSet::Bad>> fairBadSets;
};

} /* namespace modelChecker */
#endif /* COMPOSITEFAIRSET_HH_ */
