/*
 * FairAutomaton.hh
 *
 *  Created on: Sep 23, 2013
 *      Author: kquine
 */

#ifndef FAIRAUTOMATON_HH_
#define FAIRAUTOMATON_HH_
#include "Automaton.hh"
#include "FairTable/AbstractFairnessTable.hh"
#include "FairSet/FairSet.hh"

namespace modelChecker {

/**
 * An automaton with fairness
 */
template <typename PA>
class FairAutomaton: public Automaton<PA>
{
public:
	using Transition =	typename Automaton<PA>::Transition;

	virtual AbstractFairnessTable& getFairnessTable() const = 0;
	virtual unique_ptr<FairSet> makeFairSet(const Transition& t) = 0;
};

} /* namespace modelChecker */
#endif /* FAIRAUTOMATON_HH_ */
