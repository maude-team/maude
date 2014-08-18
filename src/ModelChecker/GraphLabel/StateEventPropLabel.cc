/*
 * StateEventPropLabel.cc
 *
 *  Created on: Sep 19, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "StateEventPropLabel.hh"

namespace modelChecker {

StateEventPropLabel::StateEventPropLabel(const NatSet& stateProps,
		const NatSet& eventProps, PropChecker& spc, PropChecker& epc): statePC(spc), eventPC(epc)
{
	unsigned int max_id = max(stateProps.max(), eventProps.max());

	for (auto i : stateProps)	statePropIds.push_back(i);
	for (auto i : eventProps)	eventPropIds.push_back(i);

	localPropIds.resize(max_id + 1, make_pair(NEITHER,0));
	for (unsigned int i = 0; i < statePropIds.size(); ++i)	localPropIds[statePropIds[i]] = make_pair(STATE_PROP,i);
	for (unsigned int i = 0; i < eventPropIds.size(); ++i)	localPropIds[eventPropIds[i]] = make_pair(EVENT_PROP,i);
}

bool
StateEventPropLabel::satisfiesStateProp(unsigned int propId, const StateLabel& l) const
{
	Assert(localPropIds[propId].first == STATE_PROP, "StateEventPropLabel::satisfiesStateProp: requires a state prop id.");
	return l.label.contains(localPropIds[propId].second);
}

bool
StateEventPropLabel::satisfiesEventProp(unsigned int propId, const EventLabel& l) const
{
	Assert(localPropIds[propId].first == EVENT_PROP, "StateEventPropLabel::satisfiesEventProp: requires an event prop id.");
	return l.label.contains(localPropIds[propId].second);
}


unique_ptr<PropSet>
StateEventPropLabel::updateStateLabel(DagNode* stateDag, StateLabel& l) const
{
	return updateLabel(stateDag, l, statePropIds, statePC);
}

unique_ptr<PropSet>
StateEventPropLabel::updateEventLabel(DagNode* eventDag, EventLabel& l) const
{
	return updateLabel(eventDag, l, eventPropIds, eventPC);
}

template <typename Label> unique_ptr<PropSet>
StateEventPropLabel::updateLabel(DagNode* dag, Label& l, const vector<unsigned int>& propIds, PropChecker& pc) const
{
	unique_ptr<PropSet> truePropIds = pc.computeCheckResult(dag);
	for (auto i = propIds.rbegin(); i != propIds.rend(); ++i)
		if (truePropIds->isTrue(*i))
			l.label.insert(localPropIds[*i].second);
	return truePropIds;
}

} /* namespace modelChecker */
