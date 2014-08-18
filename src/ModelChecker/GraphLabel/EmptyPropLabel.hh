/*
 * EmptyPropLabel.hh
 *
 *  Created on: Sep 21, 2013
 *      Author: kquine
 */

#ifndef EMPTYPROPLABEL_HH_
#define EMPTYPROPLABEL_HH_
#include "PropChecker/PropSet.hh"

namespace modelChecker {

class EmptyPropLabel
{
public:
	struct Label
	{
		bool operator<(const Label&) const { return false; }
	};

	EmptyPropLabel(PropChecker* pc): pc(pc) {}

	unique_ptr<PropSet> updateLabel(DagNode* dag, Label&) const;
	bool satisfiesProp(unsigned int, const Label&) const		{ return false; }

private:
	PropChecker* pc;
};

inline unique_ptr<PropSet>
EmptyPropLabel::updateLabel(DagNode* dag, Label&) const
{
	return pc ? pc->computeCheckResult(dag) : nullptr;	// creates a prop set only.
}


} /* namespace modelChecker */
#endif /* EMPTYPROPLABEL_HH_ */
