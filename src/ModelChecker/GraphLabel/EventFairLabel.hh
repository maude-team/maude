/*
 * EventFairLabel.hh
 *
 *  Created on: Sep 21, 2013
 *      Author: kquine
 */

#ifndef EVENTFAIRLABEL_HH_
#define EVENTFAIRLABEL_HH_
#include <memory>
#include "FairSet/FairSet.hh"
#include "FairChecker/FairnessChecker.hh"

namespace modelChecker {

class EventFairLabel
{
public:
	struct StateLabel
	{
		bool operator<(const StateLabel&) const		{ return false; }
	};
	struct EventLabel
	{
		unique_ptr<FairSet> fs;
		bool operator<(const EventLabel& l) const	{ return *fs < *l.fs; }
	};

	EventFairLabel(FairnessChecker& efc): eventFC(efc)			{}

	void updateStateLabel(const PropSet&, StateLabel&) const			{}
	void updateEventLabel(const PropSet& tps, EventLabel& l) const		{ l.fs = eventFC.computeAllFairness(tps); }
	unique_ptr<FairSet> makeFairSet(StateLabel*, EventLabel* l) const	{ return l->fs->clone(); }

private:
	FairnessChecker& eventFC;
};


} /* namespace modelChecker */
#endif /* EVENTFAIRLABEL_HH_ */
