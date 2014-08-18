/*
 * DagContainer.hh
 *
 *  Created on: May 24, 2011
 *      Author: kquine
 */

#ifndef DAGCONTAINER_HH_
#define DAGCONTAINER_HH_
#include "hashConsSet.hh"
#include "dagNode.hh"

namespace modelChecker {

class DagContainer
{
public:
	using size_type = vector<int>::size_type;

	unsigned int getNrDags() const;
	DagNode* getDag(size_type index) const;		// return the dag for the index
	unsigned int insertDag(DagNode* dag);		// return the state index

private:
	vector<size_type> state2hashConsIndex;	// stateIndex |-> hashconse index
	vector<int> hashCons2dagIndex;			// partial map of hashCons indices to dag info
	HashConsSet hashConsSet;
};

inline unsigned int
DagContainer::getNrDags() const
{
	return state2hashConsIndex.size();
}

inline DagNode*
DagContainer::getDag(size_type index) const
{
	Assert(index < state2hashConsIndex.size(), "DagContainer::getStateDag: invalid state lookup (state dag)");
	return hashConsSet.getCanonical(state2hashConsIndex[index]);
}

}

#endif /* DAGCONTAINER_HH_ */
