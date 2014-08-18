/*
 * StateFairLabel.hh
 *
 *  Created on: Sep 20, 2013
 *      Author: kquine
 */

#ifndef STATEFAIRLABEL_HH_
#define STATEFAIRLABEL_HH_
#include <memory>
#include "FairSet/FairSet.hh"
#include "FairChecker/FairnessChecker.hh"

namespace modelChecker {

class StateFairLabel
{
public:
	struct StateLabel
	{
		unique_ptr<FairSet> fs;
		bool operator<(const StateLabel& l) const	{ return *fs < *l.fs; }
	};
	struct EventLabel
	{
		bool operator<(const EventLabel&) const		{ return false; }
	};

	StateFairLabel(FairnessChecker& sfc): stateFC(sfc)	{}

	void updateStateLabel(const PropSet& tps, StateLabel& l) const		{ l.fs = stateFC.computeAllFairness(tps); }
	void updateEventLabel(const PropSet&, EventLabel&) const			{}
	unique_ptr<FairSet> makeFairSet(StateLabel* l, EventLabel*) const	{ return l->fs->clone(); }

private:
	FairnessChecker& stateFC;
};

} /* namespace modelChecker */
#endif /* STATEFAIRLABEL_HH_ */
