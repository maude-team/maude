/*
 * BasePropLabel.hh
 *
 *  Created on: Sep 21, 2013
 *      Author: kquine
 */

#ifndef BASEPROPLABEL_HH_
#define BASEPROPLABEL_HH_
#include <memory>
#include "natSet.hh"
#include "dagNode.hh"
#include "PropChecker/PropChecker.hh"

namespace modelChecker {

//
// a base class for either StatePropLabel or EventPropLabel
//
class BasePropLabel
{
public:
	struct Label
	{
		NatSet label;
		bool operator<(const Label& l) const						{ return label < l.label; }
	};

	BasePropLabel(const NatSet& props, PropChecker& pc): props(props), pc(pc) {}

	void setExtraFlag(bool flag) 									{ extra = flag; }
	bool satisfiesProp(unsigned int propId, const Label& l) const	{ return l.label.contains(propId); }
	unique_ptr<PropSet> updateLabel(DagNode* dag, Label& l) const;

private:
	bool extra = true;
	const NatSet props;
	PropChecker& pc;
};

inline unique_ptr<PropSet>
BasePropLabel::updateLabel(DagNode* dag, Label& l) const
{
	unique_ptr<PropSet> truePropIds = pc.computeCheckResult(dag);
	l.label.insert(truePropIds->getTruePropIds());
	if (extra) { l.label.intersect(props); }	// there is an extra prop, so that it should be removed.
	return truePropIds;
}

} /* namespace modelChecker */
#endif /* BASEPROPLABEL_HH_ */
