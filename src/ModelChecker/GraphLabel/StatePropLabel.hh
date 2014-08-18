/*
 * StatePropLabel.hh
 *
 *  Created on: Sep 19, 2013
 *      Author: kquine
 */

#ifndef STATEPROPLABEL_HH_
#define STATEPROPLABEL_HH_
#include "BasePropLabel.hh"
#include "EmptyPropLabel.hh"

namespace modelChecker {

//
// only state props (and no enabled props, either)
//
class StatePropLabel: private BasePropLabel, private EmptyPropLabel
{
public:
	using StateLabel = BasePropLabel::Label;
	using EventLabel = EmptyPropLabel::Label;

	StatePropLabel(const NatSet& props, PropChecker& spc, PropChecker* epc):
		BasePropLabel(props,spc), EmptyPropLabel(epc) {}

	void setExtraFlag(bool flag)
	{
		BasePropLabel::setExtraFlag(flag);
	}

	bool satisfiesStateProp(unsigned int propId, const StateLabel& l) const
	{
		return BasePropLabel::satisfiesProp(propId,l);
	}

	bool satisfiesEventProp(unsigned int propId, const EventLabel& l) const
	{
		return EmptyPropLabel::satisfiesProp(propId,l);
	}

	unique_ptr<PropSet> updateStateLabel(DagNode* dag, StateLabel& l) const
	{
		return BasePropLabel::updateLabel(dag,l);
	}

	unique_ptr<PropSet> updateEventLabel(DagNode* dag, EventLabel& l) const
	{
		return EmptyPropLabel::updateLabel(dag,l);
	}
};


} /* namespace modelChecker */
#endif /* STATEPROPLABEL_HH_ */
