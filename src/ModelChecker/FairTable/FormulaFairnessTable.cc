/*
 * FormulaFairnessTable.cc
 *
 *  Created on: Sep 13, 2013
 *      Author: kquine
 */

//	utility stuff
#include <memory>
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "temporal.hh"

//	interface class definitions
#include "genBuchiAutomaton.hh"

//	automaton definitions
#include "FairSet/WeakFairSet.hh"
#include "FormulaFairnessTable.hh"

namespace modelChecker {

FormulaFairnessTable::FormulaFairnessTable(const GenBuchiAutomaton& aut): automaton(aut)
{
	for (auto i = aut.getNrFairnessSets() - 1; i >= 0; --i)		// a set of all formula fairness ids
		formulaFairnessIds.insert(i);
}

unique_ptr<FairSet>
FormulaFairnessTable::makeFairSet(const GenBuchiAutomaton::FairTransitionSet::const_iterator& index) const
{
	NatSet falsified(formulaFairnessIds);
	falsified.subtract(automaton.getFairnessCombination(index->first.second));
	WeakFairSet* res = new WeakFairSet;
	res->swapFalsified(falsified);
	return unique_ptr<FairSet>(res);
}


} /* namespace modelChecker */
