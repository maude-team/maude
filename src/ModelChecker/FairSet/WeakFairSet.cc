/*
 * WeakFairSet.cc
 *
 *  Created on: Dec 10, 2010
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"
#include "natSet.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "FairTable/FairnessTable.hh"
#include "WeakFairSet.hh"

namespace modelChecker {


WeakFairSet::WeakFairSet(WeakFairSet&& other) noexcept
{
	falsifiedWeakFair.swap(other.falsifiedWeakFair);
}

void
WeakFairSet::setFalsified(unsigned int fairId)
{
	falsifiedWeakFair.insert(fairId);
}

bool
WeakFairSet::getFalsified(unsigned int fairId) const
{
	return falsifiedWeakFair.contains(fairId);
}


void
WeakFairSet::swapFalsified(NatSet& falsified)
{
	falsifiedWeakFair.swap(falsified);
}


void
WeakFairSet::paste(const FairSet& f)
{
	falsifiedWeakFair.insert(static_cast<const WeakFairSet&>(f).falsifiedWeakFair);
}

void
WeakFairSet::merge(const FairSet& f, const AbstractFairnessTable&)
{
	falsifiedWeakFair.intersect(static_cast<const WeakFairSet&>(f).falsifiedWeakFair);
}

bool
WeakFairSet::isSatisfied() const
{
	return falsifiedWeakFair.empty();
}

bool
WeakFairSet::operator<(const FairSet& f) const
{
	const WeakFairSet& wf = static_cast<const WeakFairSet&>(f);
	return falsifiedWeakFair < wf.falsifiedWeakFair;
}


unique_ptr<FairSet>
WeakFairSet::clone() const
{
	return unique_ptr<FairSet>(new WeakFairSet(*this));
}

unique_ptr<FairSet::Goal>
WeakFairSet::makeFairGoal(const AbstractFairnessTable& table) const
{
	auto& wtable = static_cast<const WeakFairnessTable&>(table);
	return unique_ptr<FairSet::Goal>(new Goal(wtable.nrFairness(), *this));
}

unique_ptr<FairSet::Bad>
WeakFairSet::makeBadGoal() const
{
	return unique_ptr<FairSet::Bad>(new Bad);
}

void
WeakFairSet::dump(ostream& o) const
{
	o << "(false_weak: " << falsifiedWeakFair << ")";
}


WeakFairSet::Goal::Goal(unsigned int nrFairness, const WeakFairSet& f)
{
	for (auto i = nrFairness ; i > 0 ; --i)
		weakFairGoal.insert(i - 1);		// add all fairness
	weakFairGoal.subtract(f.falsifiedWeakFair); // but not falsified
}

bool
WeakFairSet::Goal::empty() const
{
	return weakFairGoal.empty();
}

bool
WeakFairSet::Goal::update(const FairSet& f, const AbstractFairnessTable&)
{
	const WeakFairSet& wf = static_cast<const WeakFairSet&>(f);
	if (wf.falsifiedWeakFair.contains(weakFairGoal))	// all still falsified
		return false;
	else
	{
		weakFairGoal.intersect(wf.falsifiedWeakFair);	// goal = still falsified
		return true;
	}
}

void
WeakFairSet::Goal::dump(ostream& o) const
{
	o << "[weak goal: " << weakFairGoal << "]";
}

}
