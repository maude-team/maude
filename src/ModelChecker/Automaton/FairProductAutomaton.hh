/*
 * FairProductAutomaton.hh
 *
 *  Created on: Sep 10, 2013
 *      Author: kquine
 */

#ifndef FAIRPRODUCTAUTOMATON_HH_
#define FAIRPRODUCTAUTOMATON_HH_
#include "FairAutomaton.hh"
#include "ProductAutomaton.hh"
#include "FairTable/CompositeFairnessTable.hh"
#include "FairTable/FormulaFairnessTable.hh"

namespace modelChecker {

/**
 * A generic product automaton implementation with fairness. To avoid ambiguous inheritance,
 * a ProductAutomaton instance is declared as a member variable.
 *
 */
template <bool hasState, bool hasEvent, typename SA, typename PA>
class FairProductAutomaton: public FairAutomaton<PA>
{
public:
	using State = 					typename Automaton<PA>::State;
	using Transition = 				typename Automaton<PA>::Transition;
	using PreTransitionIterator =	typename Automaton<PA>::TransitionIterator;

	FairProductAutomaton(unique_ptr<SA>&& system,
			unique_ptr<PA>&& property, unique_ptr<AbstractFairnessTable>&& systemFairTable);

	unique_ptr<FairSet> makeFairSet(const Transition& t) override;
	AbstractFairnessTable& getFairnessTable() const override	{ return *fairTable; }

	const PA& getPropertyAutomaton() const  override			{ return base.getPropertyAutomaton(); }
	const vector<State>& getInitialStates() const override		{ return base.getInitialStates(); }

	unique_ptr<PreTransitionIterator>
	makeTransitionIterator(const State& state) override			{ return base.makeTransitionIterator(state); }

private:
	CompositeFairnessTable* makeInitFairTable(unique_ptr<AbstractFairnessTable>&& systemFairTable) const;

	ProductAutomaton<hasState,hasEvent,SA,PA> base;			// an underlying product automaton
	const unique_ptr<CompositeFairnessTable> fairTable;		// (system + formula) fairness table
	const FormulaFairnessTable* formulaRef;					// a reference to the formula fairness table
};

} /* namespace modelChecker */

#include "FairProductAutomaton.cc"

#endif /* FAIRPRODUCTAUTOMATON_HH_ */
