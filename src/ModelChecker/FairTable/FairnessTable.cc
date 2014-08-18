/*
 * FairnessTable.cc
 *
 *  Created on: Aug 22, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// ltlr definitions
#include "FairnessTable.hh"

namespace modelChecker {

template <typename Formula>
FairnessTable<Formula>::FairnessTable(PropositionTable& propTable): propTable(propTable) {}


template <typename Formula> const Formula&
FairnessTable<Formula>::getFairFormula(unsigned int fairId) const
{
	return static_cast<GroundFairness&>(*fairTable[fairId]).formula;
}

template <typename Formula> bool
FairnessTable<Formula>::isStateFairness(unsigned int fairId) const
{
	return static_cast<GroundFairness&>(*fairTable[fairId]).noEvent;
}

template <typename Formula> bool
FairnessTable<Formula>::isStateEventFairness(unsigned int fairId) const
{
	return ! isStateFairness(fairId);
}

template <typename Formula>
unsigned int
FairnessTable<Formula>::insertFairnessFormula(const Formula& f, const vector<unsigned int>& propIds, DagNode* fairDag)
{
	auto newIndex = fairTable.size();
	auto fi = fairFormulas.emplace(f,newIndex);
	if (fi.second)	// when new fairness formula identified
	{
		fairTable.push_back( createFormulaFairness(fi.first->first, propIds, fairDag) );
		origFairIds.insert(newIndex);
	}
	return fi.first->second;
}

template <typename Formula>
unique_ptr<typename FairnessTable<Formula>::GroundFairness>
FairnessTable<Formula>::createFormulaFairness(const Formula& f, const vector<unsigned int>& propIds, DagNode*) const
{
	bool noEvent = none_of(propIds.begin(), propIds.end(), [&](unsigned int i){ return propTable.isEventProp(i); });
	return unique_ptr<GroundFairness>(new GroundFairness(f, noEvent));
}



} /* namespace modelChecker */
