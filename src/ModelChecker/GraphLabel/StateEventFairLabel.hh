/*
 * StateEventFairLabel.hh
 *
 *  Created on: Sep 21, 2013
 *      Author: kquine
 */

#ifndef STATEEVENTFAIRLABEL_HH_
#define STATEEVENTFAIRLABEL_HH_
#include <memory>
#include "FairSet/FairSet.hh"
#include "FairChecker/FairnessChecker.hh"

namespace modelChecker {

//
// Both for state and state-event fair labels; using a compact fair set.
//
class StateEventFairLabel
{
public:
	struct StateLabel;
	struct EventLabel;

	StateEventFairLabel(FairnessChecker& sfc, FairnessChecker& efc);

	void updateStateLabel(const PropSet& tps, StateLabel& l) const;
	void updateEventLabel(const PropSet& tps, EventLabel& l) const;

	unique_ptr<FairSet> makeFairSet(StateLabel* sl, EventLabel* el) const;

private:
	FairnessChecker& stateFC;
	FairnessChecker& eventFC;
};

struct StateEventFairLabel::StateLabel
{
	unique_ptr<FairSet> fs;
	bool operator<(const StateLabel& l) const	{ return *fs < *l.fs; }
};
struct StateEventFairLabel::EventLabel
{
	unique_ptr<FairSet> fs;
	bool operator<(const EventLabel& l) const	{ return *fs < *l.fs; }
};


} /* namespace modelChecker */
#endif /* STATEEVENTFAIRLABEL_HH_ */
