/*
 * ParamWeakFairSet.cc
 *
 *  Created on: Sep 11, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "FairTable/ParamFairnessTable.hh"
#include "ParamWeakFairSet.hh"

namespace modelChecker {

ParamWeakFairSet::ParamWeakFairSet(WeakFairSet&& f): WeakFairSet(move(f)) {}

void
ParamWeakFairSet::paste(const FairSet& f)
{
	WeakFairSet::paste(f);
	ParamRealizedSet::paste(static_cast<const ParamWeakFairSet&>(f));
}

void
ParamWeakFairSet::merge(const FairSet& f, const AbstractFairnessTable& table)
{
	auto& wtable = static_cast<const ParamWeakFairnessTable&>(table);
	auto& pwf = static_cast<const ParamWeakFairSet&>(f);

	auto falsifiedWeakFairOther = pwf.falsifiedWeakFair;
	this->extend(pwf, falsifiedWeakFair, wtable);
	pwf.extend(*this, falsifiedWeakFairOther, wtable);

	falsifiedWeakFair.intersect(falsifiedWeakFairOther);
	ParamRealizedSet::merge(pwf);
}

unique_ptr<FairSet>
ParamWeakFairSet::clone() const
{
	return unique_ptr<ParamWeakFairSet>(new ParamWeakFairSet(*this));
}

void
ParamWeakFairSet::dump(ostream& o) const
{
	WeakFairSet::dump(o);
	ParamRealizedSet::dump(o);
}

unique_ptr<FairSet::Goal>
ParamWeakFairSet::makeFairGoal(const AbstractFairnessTable& table) const
{
	auto& wtable = static_cast<const ParamWeakFairnessTable&>(table);
	return unique_ptr<FairSet::Goal>(new Goal(wtable.nrFairness(), *this));
}


ParamWeakFairSet::Goal::Goal(unsigned int nrFairness, const ParamWeakFairSet& f):
		WeakFairSet::Goal(nrFairness, f) {}

bool
ParamWeakFairSet::Goal::update(const FairSet& f, const AbstractFairnessTable& table)
{
	auto& wtable = static_cast<const ParamWeakFairnessTable&>(table);
	auto& pwf = static_cast<const ParamWeakFairSet&>(f);

	NatSet falsifiedWeakFair = pwf.falsifiedWeakFair;
	pwf.extend(weakFairGoal, falsifiedWeakFair, wtable);

	if (falsifiedWeakFair.contains(weakFairGoal))	// all still falsified
		return false;
	else
	{
		weakFairGoal.intersect(falsifiedWeakFair);	// goal = still falsified
		return true;
	}
}

} /* namespace modelChecker */
