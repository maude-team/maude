/*
 * DefaultStateDagContainer.hh
 *
 *  Created on: Jul 29, 2014
 *      Author: kquine
 */

#ifndef DEFAULTSTATEDAGCONTAINER_HH_
#define DEFAULTSTATEDAGCONTAINER_HH_
#include "hashConsSet.hh"
#include "dagNode.hh"

namespace modelChecker {

class DefaultStateDagContainer
{
	using size_type = vector<int>::size_type;
public:

	DagNode* index2StateDag(size_type index) const;		// return the dag for the index
	unsigned int stateDag2index(DagNode* dag);			// return the state index

private:
	vector<size_type> state2hashConsIndex;	// stateIndex |-> hashconse index
	vector<int> hashCons2dagIndex;			// partial map of hashCons indices to dag info
	HashConsSet hashConsSet;
};


inline DagNode*
DefaultStateDagContainer::index2StateDag(size_type index) const
{
	Assert(index < state2hashConsIndex.size(), "DagContainer::getStateDag: invalid state lookup (state dag)");
	return hashConsSet.getCanonical(state2hashConsIndex[index]);
}


} /* namespace modelChecker */

#endif /* DEFAULTSTATEDAGCONTAINER_HH_ */
