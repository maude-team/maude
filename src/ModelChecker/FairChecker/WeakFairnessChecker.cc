/*
 * WeakFairnessChecker.cc
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "WeakFairnessChecker.hh"

namespace modelChecker {

WeakFairnessChecker::WeakFairnessChecker(const vector<unsigned int>& weakFairIds, WeakFairnessTable& fTable):
		weakFairIds(weakFairIds), fTable(fTable) {}

unsigned int
WeakFairnessChecker::getNrFairness() const
{
	return weakFairIds.size();
}

unique_ptr<FairSet>
WeakFairnessChecker::computeAllFairness(const PropSet& trueProps)
{
	auto result = new WeakFairSet;
	for (auto i = weakFairIds.crbegin(); i != weakFairIds.crend(); ++i)
	{
		const Bdd ff = fTable.getFairFormula(*i);
		if ( ! FairnessChecker::satisfiesFairFormula(trueProps,ff)) result->setFalsified(*i);
	}
	return unique_ptr<FairSet>(result);
}

unique_ptr<FairSet>
WeakFairnessChecker::computeCompactFairness(const PropSet& trueProps)
{
	auto result = new WeakFairSet;
	for (unsigned int i = weakFairIds.size(); i-- > 0; )
	{
		const Bdd ff = fTable.getFairFormula(weakFairIds[i]);
		if ( ! FairnessChecker::satisfiesFairFormula(trueProps,ff)) result->setFalsified(i);	// store a compact version
	}
	return unique_ptr<FairSet>(result);
}

unique_ptr<FairSet>
WeakFairnessChecker::unzip(const FairSet& fs) const
{
	const WeakFairSet& wfs = static_cast<const WeakFairSet&>(fs);

	auto result = new WeakFairSet;
	for (unsigned int i = weakFairIds.size(); i-- > 0; )
	{
		if ( wfs.getFalsified(i) ) result->setFalsified(weakFairIds[i]);	// store an expanded version
	}
	return unique_ptr<FairSet>(result);
}

} /* namespace modelChecker */
