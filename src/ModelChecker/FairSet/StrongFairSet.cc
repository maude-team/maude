/*
 * StrongFairSet.cc
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
#include "StrongFairSet.hh"

namespace modelChecker {

StrongFairSet::StrongFairSet(StrongFairSet&& other) noexcept
{
	falsifiedSupp.swap(other.falsifiedSupp);
	falsifiedCons.swap(other.falsifiedCons);
}

void
StrongFairSet::setSuppFalse(unsigned int fairId)
{
	falsifiedSupp.insert(fairId);
}

void
StrongFairSet::setConsFalse(unsigned int fairId)
{
	falsifiedCons.insert(fairId);
}

bool
StrongFairSet::getSuppFalse(unsigned int fairId) const
{
	return falsifiedSupp.contains(fairId);
}

bool
StrongFairSet::getConsFalse(unsigned int fairId) const
{
	return falsifiedCons.contains(fairId);
}

void
StrongFairSet::paste(const FairSet& f)
{
	const StrongFairSet& sf = static_cast<const StrongFairSet&>(f);
	falsifiedSupp.insert(sf.falsifiedSupp);
	falsifiedCons.insert(sf.falsifiedCons);
}

void
StrongFairSet::merge(const FairSet& f, const AbstractFairnessTable&)
{
	const StrongFairSet& sf = static_cast<const StrongFairSet&>(f);
	falsifiedSupp.intersect(sf.falsifiedSupp);
	falsifiedCons.intersect(sf.falsifiedCons);
}

bool
StrongFairSet::isSatisfied() const
{
	return falsifiedSupp.contains(falsifiedCons);
}

bool
StrongFairSet::operator<(const FairSet& f) const
{
	const StrongFairSet& sf = static_cast<const StrongFairSet&>(f);
	return falsifiedSupp < sf.falsifiedSupp ||  falsifiedCons < sf.falsifiedCons;
}

unique_ptr<FairSet>
StrongFairSet::clone() const
{
	return unique_ptr<FairSet>(new StrongFairSet(*this));
}

unique_ptr<FairSet::Goal>
StrongFairSet::makeFairGoal(const AbstractFairnessTable& table) const
{
	auto& stable = static_cast<const StrongFairnessTable&>(table);
	return unique_ptr<FairSet::Goal>(new Goal(stable.nrFairness(), *this));
}

unique_ptr<FairSet::Bad>
StrongFairSet::makeBadGoal() const
{
	return unique_ptr<FairSet::Bad>(new Bad(*this));
}

void
StrongFairSet::dump(ostream& o) const
{
	o << "(false_strong: " << falsifiedSupp << " , " << falsifiedCons << ")";
}

StrongFairSet::Goal::Goal(unsigned int nrFairness, const StrongFairSet& f)
{
	for (auto i = nrFairness ; i > 0 ; --i)
		strongFairGoal.insert(i - 1);	// add all fairness

	// but not both falsified
	strongFairGoal.subtract(f.falsifiedSupp);
	strongFairGoal.subtract(f.falsifiedCons);
}

bool
StrongFairSet::Goal::empty() const
{
	return strongFairGoal.empty();
}

bool
StrongFairSet::Goal::update(const FairSet& f, const AbstractFairnessTable&)
{
	const StrongFairSet& sf = static_cast<const StrongFairSet&>(f);
	if (sf.falsifiedCons.contains(strongFairGoal))	// all still falsified
		return false;
	else
	{
		strongFairGoal.intersect(sf.falsifiedCons);	// goal = still falsified
		return true;
	}
}

void
StrongFairSet::Goal::dump(ostream& o) const
{
	o << "[strong goal: " << strongFairGoal << "]";
}

StrongFairSet::Bad::Bad(const StrongFairSet& f): badFairs(f.falsifiedCons)
{
	badFairs.subtract(f.falsifiedSupp);		// only (true => false)
}

bool
StrongFairSet::Bad::isBad(const FairSet& f, const AbstractFairnessTable&) const
{
	const StrongFairSet& sf = static_cast<const StrongFairSet&>(f);
	return ! sf.falsifiedSupp.contains(badFairs);
}

bool
StrongFairSet::Bad::empty() const
{
	return badFairs.empty();
}

void
StrongFairSet::Bad::merge(const FairSet::Bad& b)
{
	const Bad& nb = static_cast<const Bad&>(b);
	badFairs.insert(nb.badFairs);
}

void
StrongFairSet::Bad::dump(ostream& o) const
{
	o << "[strong bad: " << badFairs << "]";
}

}
