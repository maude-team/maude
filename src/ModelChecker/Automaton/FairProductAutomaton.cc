/*
 * FairProductAutomaton.cc
 *
 *  Created on: Sep 10, 2013
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
#include "buchiAutomaton2.hh"
#include "genBuchiAutomaton.hh"

//	automaton definitions
#include "FairTable/FormulaFairnessTable.hh"
#include "FairSet/CompositeFairSet.hh"
#include "FairProductAutomaton.hh"

namespace modelChecker {

/**
 * A FairProductAutomaton constructor. Since it "moves" two input arguments, it is important to
 * first construct "base" ProductAutomaton instance before the others.
 */
template <bool hasState, bool hasEvent, typename SA, typename PA>
FairProductAutomaton<hasState,hasEvent,SA,PA>::FairProductAutomaton(unique_ptr<SA>&& system,
		unique_ptr<PA>&& property, unique_ptr<AbstractFairnessTable>&& systemFairTable):
	base(move(system),move(property)),
	fairTable(makeInitFairTable(move(systemFairTable))),
	formulaRef(&static_cast<FormulaFairnessTable&>(fairTable->getComponent(fairTable->nrComponents()-1))) {}


template <bool hasState, bool hasEvent, typename SA, typename PA>
unique_ptr<FairSet>
FairProductAutomaton<hasState,hasEvent,SA,PA>::makeFairSet(const Transition& t)
{
	unique_ptr<FairSet> sysf = base.getSystemAutomaton().makeFairSet(t.source.first, t.systemIndex);
	unique_ptr<FairSet> forf = formulaRef->makeFairSet(t.propertyIndex);
	if (CompositeFairSet* cfs = dynamic_cast<CompositeFairSet*>(sysf.get()))
	{
		cfs->addComponent(move(forf));
		return move(sysf);
	}
	else
	{
		cfs = new CompositeFairSet;
		cfs->addComponent(move(sysf));
		cfs->addComponent(move(forf));
		return unique_ptr<FairSet>(cfs);
	}
}

template <bool hasState, bool hasEvent, typename SA, typename PA>
CompositeFairnessTable*
FairProductAutomaton<hasState,hasEvent,SA,PA>::makeInitFairTable(unique_ptr<AbstractFairnessTable>&& systemFairTable) const
{
	CompositeFairnessTable* result;
	if (dynamic_cast<CompositeFairnessTable*>(systemFairTable.get()))
	{
		result = static_cast<CompositeFairnessTable*>(systemFairTable.release());
	}
	else
	{
		result = new CompositeFairnessTable;
		result->addComponent(move(systemFairTable));
	}
	result->addComponent(unique_ptr<AbstractFairnessTable>(new FormulaFairnessTable(this->getPropertyAutomaton())));
	return result;
}


} /* namespace modelChecker */
