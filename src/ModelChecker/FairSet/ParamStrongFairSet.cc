/*
 * ParamStrongFairSet.cc
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
#include "ParamStrongFairSet.hh"

namespace modelChecker {

ParamStrongFairSet::ParamStrongFairSet(StrongFairSet&& f): StrongFairSet(move(f)) {}

void
ParamStrongFairSet::paste(const FairSet& f)
{
	StrongFairSet::paste(f);
	ParamRealizedSet::paste(static_cast<const ParamStrongFairSet&>(f));
}

void
ParamStrongFairSet::merge(const FairSet& f, const AbstractFairnessTable& table)
{
	auto& stable = static_cast<const ParamStrongFairnessTable&>(table);
	auto& psf = static_cast<const ParamStrongFairSet&>(f);

	auto falsifiedSuppOther = psf.falsifiedSupp;
	this->extend(psf, falsifiedSupp, stable);
	psf.extend(*this, falsifiedSuppOther, stable);

	auto falsifiedConsOther = psf.falsifiedCons;
	this->extend(psf, falsifiedCons, stable);
	psf.extend(*this, falsifiedConsOther, stable);

	falsifiedSupp.intersect(falsifiedSuppOther);
	falsifiedCons.intersect(falsifiedConsOther);
	ParamRealizedSet::merge(psf);
}

unique_ptr<FairSet>
ParamStrongFairSet::clone() const
{
	return unique_ptr<ParamStrongFairSet>(new ParamStrongFairSet(*this));
}

unique_ptr<FairSet::Bad>
ParamStrongFairSet::makeBadGoal() const
{
	return unique_ptr<FairSet::Bad>(new Bad(*this));
}

void
ParamStrongFairSet::dump(ostream& o) const
{
	StrongFairSet::dump(o);
	ParamRealizedSet::dump(o);
}

ParamStrongFairSet::Goal::Goal(unsigned int nrFairness, const ParamStrongFairSet& f):
		StrongFairSet::Goal(nrFairness, f) {}


bool
ParamStrongFairSet::Goal::update(const FairSet& f, const AbstractFairnessTable& table)
{
	auto& stable = static_cast<const ParamStrongFairnessTable&>(table);
	auto& psf = static_cast<const ParamStrongFairSet&>(f);

	NatSet falsifiedCons = psf.falsifiedCons;
	psf.extend(strongFairGoal, falsifiedCons, stable);

	if (falsifiedCons.contains(strongFairGoal))	// all still falsified
		return false;
	else
	{
		strongFairGoal.intersect(falsifiedCons);	// goal = still falsified
		return true;
	}
}



ParamStrongFairSet::Bad::Bad(const ParamStrongFairSet& fs): StrongFairSet::Bad(fs) {}

bool
ParamStrongFairSet::Bad::isBad(const FairSet& f, const AbstractFairnessTable& table) const
{
	auto& stable = static_cast<const ParamStrongFairnessTable&>(table);
	auto& psf = static_cast<const ParamStrongFairSet&>(f);

	NatSet falsifiedSupp = psf.falsifiedSupp;
	psf.extend(badFairs, falsifiedSupp, stable);

	return ! falsifiedSupp.contains(badFairs);
}

} /* namespace modelChecker */
