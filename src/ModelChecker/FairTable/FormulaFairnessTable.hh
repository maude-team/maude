/*
 * FormulaFairnessTable.hh
 *
 *  Created on: Sep 13, 2013
 *      Author: kquine
 */

#ifndef FORMULAFAIRNESSTABLE_HH_
#define FORMULAFAIRNESSTABLE_HH_
#include "genBuchiAutomaton.hh"
#include "AbstractFairnessTable.hh"
#include "FairSet/FairSet.hh"

namespace modelChecker {

class FormulaFairnessTable: public AbstractFairnessTable
{
public:
	FormulaFairnessTable(const GenBuchiAutomaton& aut);

	unique_ptr<FairSet> makeFairSet(const GenBuchiAutomaton::FairTransitionSet::const_iterator& index) const;

	unsigned int nrFairness() const override	{ return formulaFairnessIds.size(); }
	bool hasStrongFairness() const override		{ return false; }

private:
	const GenBuchiAutomaton& automaton;
	NatSet formulaFairnessIds;
};

} /* namespace modelChecker */
#endif /* FORMULAFAIRNESSTABLE_HH_ */
