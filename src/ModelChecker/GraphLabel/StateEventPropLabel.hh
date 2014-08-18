/*
 * StateEventPropLabel.hh
 *
 *  Created on: Sep 19, 2013
 *      Author: kquine
 */

#ifndef STATEEVENTPROPLABEL_HH_
#define STATEEVENTPROPLABEL_HH_
#include "natSet.hh"
#include "BasePropLabel.hh"

namespace modelChecker {

//
// both state and event props (but enabled props should be already treated in the graph level)
//
class StateEventPropLabel
{
public:
	using StateLabel = BasePropLabel::Label;
	using EventLabel = BasePropLabel::Label;

	StateEventPropLabel(const NatSet& stateProps, const NatSet& eventProps, PropChecker& spc, PropChecker& epc);

	void setExtraFlag(bool) {}
	bool satisfiesStateProp(unsigned int propId, const StateLabel& l) const;
	bool satisfiesEventProp(unsigned int propId, const EventLabel& l) const;

	unique_ptr<PropSet> updateStateLabel(DagNode* stateDag, StateLabel& l) const;
	unique_ptr<PropSet> updateEventLabel(DagNode* eventDag, EventLabel& l) const;

private:
	enum PROP_TYPE { STATE_PROP, EVENT_PROP, NEITHER };

	template <typename Label>
	unique_ptr<PropSet> updateLabel(DagNode* dag, Label& l, const vector<unsigned int>& propIds, PropChecker& pc) const;

	vector<unsigned int> statePropIds;
	vector<unsigned int> eventPropIds;
	vector<pair<PROP_TYPE,unsigned int>> localPropIds;	//  global prop id |-> local prop id

	PropChecker& statePC;
	PropChecker& eventPC;
};


} /* namespace modelChecker */
#endif /* STATEEVENTPROPLABEL_HH_ */
