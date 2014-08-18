/*
 * EventPropLabel.hh
 *
 *  Created on: Sep 19, 2013
 *      Author: kquine
 */

#ifndef EVENTPROPLABEL_HH_
#define EVENTPROPLABEL_HH_
#include "EmptyPropLabel.hh"
#include "BasePropLabel.hh"

namespace modelChecker {

//
// only event props
//
class EventPropLabel: private EmptyPropLabel, private BasePropLabel
{
public:
	using StateLabel = EmptyPropLabel::Label;
	using EventLabel = BasePropLabel::Label;

	EventPropLabel(const NatSet& props, PropChecker* spc, PropChecker& epc):
		EmptyPropLabel(spc), BasePropLabel(props,epc) {}

	void setExtraFlag(bool flag)
	{
		BasePropLabel::setExtraFlag(flag);
	}

	bool satisfiesStateProp(unsigned int propId, const StateLabel& l) const
	{
		return EmptyPropLabel::satisfiesProp(propId,l);
	}

	bool satisfiesEventProp(unsigned int propId, const EventLabel& l) const
	{
		return BasePropLabel::satisfiesProp(propId,l);
	}

	unique_ptr<PropSet> updateStateLabel(DagNode* dag, StateLabel& l) const
	{
		return EmptyPropLabel::updateLabel(dag,l);
	}

	unique_ptr<PropSet> updateEventLabel(DagNode* dag, EventLabel& l) const
	{
		return BasePropLabel::updateLabel(dag,l);
	}
};

} /* namespace modelChecker */
#endif /* EVENTPROPLABEL_HH_ */
