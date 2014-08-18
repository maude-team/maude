/*
 * ProductAutomaton.hh
 *
 *  Created on: Nov 23, 2010
 *      Author: kquine
 */

#ifndef PRODUCTAUTOMATON_HH_
#define PRODUCTAUTOMATON_HH_
#include "Automaton.hh"

namespace modelChecker {

/**
 * A generic product automaton implementation.
 */
template <bool hasState, bool hasEvent, typename SA, typename PA>
class ProductAutomaton: public Automaton<PA>
{
public:
	using State = 				typename Automaton<PA>::State;
	using Transition = 			typename Automaton<PA>::Transition;
	using TransitionIterator =	typename Automaton<PA>::TransitionIterator;
	struct ProdTransitionIterator;

	ProductAutomaton(unique_ptr<SA>&& system, unique_ptr<PA>&& property);

	const SA& getSystemAutomaton() const					{ return *systemAut; }
	const PA& getPropertyAutomaton() const override			{ return *propertyAut; }
	const vector<State>& getInitialStates() const override	{ return initialStates; }

	unique_ptr<TransitionIterator> makeTransitionIterator(const State& state) override;

private:
	friend class ProdTransitionIterator;

	const unique_ptr<SA> systemAut;
	const unique_ptr<PA> propertyAut;
	vector<State> initialStates;
};

template <bool hasState, bool hasEvent>
struct ProductTransitionIteratorTraits
{
	template <typename SA, typename PA>
	void computeNextTransition(bool first, typename Automaton<PA>::Transition& tr,
			const typename PropertyTransitionTraits<PA>::PropertyTransitionSet& ts, SA& ks);
};


template <bool hasState, bool hasEvent, typename SA, typename PA>
struct ProductAutomaton<hasState,hasEvent,SA,PA>::ProdTransitionIterator:
	public TransitionIterator, private ProductTransitionIteratorTraits<hasState,hasEvent>
{
public:
	ProdTransitionIterator(SA& sys, const PA& prop, const State& state):
		TransitionIterator(state), sysGraph(sys), ts(prop.getTransitions(state.second)) {}

protected:
	void computeNextTransition(bool first) override
	{
		ProductTransitionIteratorTraits<hasState,hasEvent>::template
		computeNextTransition<SA,PA>(first,this->tr,ts,sysGraph);
	}

	SA& sysGraph;
	const typename PropertyTransitionTraits<PA>::PropertyTransitionSet& ts;
};

}

#include "ProductAutomaton.cc"

#endif /* PRODUCTAUTOMATON_HH_ */
