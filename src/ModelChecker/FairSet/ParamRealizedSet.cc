/*
 * ParamRealizedSet.cc
 *
 *  Created on: Sep 17, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "temporal.hh"
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "ParamRealizedSet.hh"

namespace modelChecker
{

void
ParamRealizedSet::setRealized(unsigned int fairId)
{
	realizedFair.insert(fairId);
}

bool
ParamRealizedSet::getRealized(unsigned int fairId) const
{
	return realizedFair.contains(fairId);
}

void
ParamRealizedSet::paste(const ParamRealizedSet& f)
{
	realizedFair.insert(f.realizedFair);		// union
}

void
ParamRealizedSet::merge(const ParamRealizedSet& f)
{
	realizedFair.insert(f.realizedFair);		// union
}

void
ParamRealizedSet::extend(const NatSet& other, NatSet& target, const RealizedFairnessTable& rtable) const
{
	NatSet not_realized_other = other;

	// NOTE: not_realized_other may contain ground/param fairness indices; e.g., badFair
	not_realized_other.subtract(realizedFair);

	for (auto i : not_realized_other)
	{
		if ( target.contains(rtable.getRealizedFairId(i, realizedFair)) )
			target.insert(i);
	}
}

void
ParamRealizedSet::extend(const ParamRealizedSet& other, NatSet& target, const RealizedFairnessTable& rtable) const
{
	extend(other.realizedFair, target, rtable);
}

void
ParamRealizedSet::dump(ostream& o) const
{
	o << "|realized: " << realizedFair << "|";
}


} /* namespace modelChecker */
