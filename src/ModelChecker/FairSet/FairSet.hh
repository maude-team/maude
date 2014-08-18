/*
 * FairSet.hh
 *
 *  Created on: Dec 10, 2010
 *      Author: kquine
 */

#ifndef FAIRSET_HH_
#define FAIRSET_HH_
#include <memory>
#include "FairTable/AbstractFairnessTable.hh"

namespace modelChecker {

struct FairSet
{
	struct Goal;
	struct Bad;

	virtual ~FairSet() = default;

	virtual void paste(const FairSet& f) = 0;
	virtual void merge(const FairSet& f, const AbstractFairnessTable& table) = 0;

	virtual bool isSatisfied() const = 0;
	virtual bool operator<(const FairSet& f) const = 0;

	virtual unique_ptr<FairSet> clone() const = 0;
	virtual unique_ptr<Goal> makeFairGoal(const AbstractFairnessTable& table) const = 0;
	virtual unique_ptr<Bad> makeBadGoal() const = 0;

	virtual void dump(ostream& o) const = 0;
};

struct FairSet::Goal
{
	virtual ~Goal() = default;
	virtual bool empty() const = 0;
	virtual bool update(const FairSet& f, const AbstractFairnessTable& table) = 0;
	virtual void dump(ostream& o) const = 0;
};

struct FairSet::Bad
{
	virtual ~Bad() = default;
	virtual bool isBad(const FairSet& f, const AbstractFairnessTable& table) const = 0;
	virtual bool empty() const = 0;
	virtual void merge(const Bad& b) = 0;
	virtual void dump(ostream& o) const = 0;
};

}

#endif /* FAIRSET_HH_ */
