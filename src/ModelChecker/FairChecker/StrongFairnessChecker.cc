/*
 * StrongFairnessChecker.cc
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
#include "StrongFairnessChecker.hh"

namespace modelChecker {

StrongFairnessChecker::StrongFairnessChecker(const vector<unsigned int>& strongFairIds, StrongFairnessTable& fTable):
		strongFairIds(strongFairIds), fTable(fTable) {}

unsigned int
StrongFairnessChecker::getNrFairness() const
{
	return strongFairIds.size();
}

unique_ptr<FairSet>
StrongFairnessChecker::computeAllFairness(const PropSet& trueProps)
{
	auto result = new StrongFairSet;
	for(auto i = strongFairIds.crbegin(); i != strongFairIds.crend(); ++i)
	{
		const pair<Bdd,Bdd> ff = fTable.getFairFormula(*i);
		if ( ! FairnessChecker::satisfiesFairFormula(trueProps,ff.first))	result->setSuppFalse(*i);
		if ( ! FairnessChecker::satisfiesFairFormula(trueProps,ff.second))	result->setConsFalse(*i);
	}
	return unique_ptr<FairSet>(result);
}

unique_ptr<FairSet>
StrongFairnessChecker::computeCompactFairness(const PropSet& trueProps)
{
	auto result = new StrongFairSet;
	for(unsigned int i = strongFairIds.size(); i-- > 0; )	// store a compact version
	{
		const pair<Bdd,Bdd> ff = fTable.getFairFormula(strongFairIds[i]);
		if ( ! FairnessChecker::satisfiesFairFormula(trueProps,ff.first))	result->setSuppFalse(i);
		if ( ! FairnessChecker::satisfiesFairFormula(trueProps,ff.second))	result->setConsFalse(i);
	}
	return unique_ptr<FairSet>(result);
}

unique_ptr<FairSet>
StrongFairnessChecker::unzip(const FairSet& fs) const
{
	const StrongFairSet& sfs = static_cast<const StrongFairSet&>(fs);

	auto result = new StrongFairSet;
	for (unsigned int i = strongFairIds.size(); i-- > 0; )	// store an expanded version
	{
		if (sfs.getConsFalse(i))	result->setConsFalse(strongFairIds[i]);
		if (sfs.getSuppFalse(i))	result->getSuppFalse(strongFairIds[i]);
	}
	return unique_ptr<FairSet>(result);
}

} /* namespace modelChecker */
