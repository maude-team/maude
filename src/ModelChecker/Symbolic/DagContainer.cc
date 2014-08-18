/*
 * DagContainer.cc
 *
 *  Created on: May 24, 2011
 *      Author: kquine
 */


//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "freeTheory.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

#include "DagContainer.hh"

namespace modelChecker {

unsigned int
DagContainer::insertDag(DagNode* dag)
{
	int nextState;
	const unsigned int hashConsIndex = hashConsSet.insert(dag);	// NOTE: hashConsSet must always return a positive number

	//DebugAdvisory("replacement dag = " << dag << "hashConsIndex = " << hashConsIndex);
	if (hashConsIndex < hashCons2dagIndex.size())	// Seen before
	{
		nextState = hashCons2dagIndex[hashConsIndex];
		if (nextState != NONE)
			return nextState;
		// But only as a subdag, not as a state dag, so it counts as a new dag.
	}
	else	//	Definitely a new dag.
	{
		hashCons2dagIndex.resize(hashConsIndex + 1, NONE);
	}
	nextState = state2hashConsIndex.size();
	hashCons2dagIndex[hashConsIndex] = nextState;
	state2hashConsIndex.push_back(hashConsIndex);

	Assert(nextState >= 0, "StateDagContainer::insertDag: violate integer limit.");
	return nextState;
}

}
