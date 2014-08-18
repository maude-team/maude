/*
 * ProductAutomaton.cc
 *
 *  Created on: Dec 1, 2010
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
#include "Graph/StateSystemGraph.hh"
#include "ProductAutomaton.hh"

namespace modelChecker {

template <bool hasState, bool hasEvent, typename SA, typename PA>
ProductAutomaton<hasState,hasEvent,SA,PA>::ProductAutomaton(unique_ptr<SA>&& system, unique_ptr<PA>&& property):
	systemAut(move(system)), propertyAut(move(property))
{
	//
	// First, create a set of initial states
	//
	for(auto i : propertyAut->getInitialStates())
		initialStates.emplace_back(0,i);
}

/**
 * Create an appropriate transition iterator
 */
template <bool hasState, bool hasEvent, typename SA, typename PA>
inline unique_ptr<typename ProductAutomaton<hasState,hasEvent,SA,PA>::TransitionIterator>
ProductAutomaton<hasState,hasEvent,SA,PA>::makeTransitionIterator(const State& state)
{
	ProdTransitionIterator* ti = new ProdTransitionIterator(*systemAut, *propertyAut, state);
	ti->init();
	return unique_ptr<TransitionIterator>(ti);
}

/**
 * An iterator for state-only graphs
 */
template <>
struct ProductTransitionIteratorTraits<true,false>
{
	template <typename SA, typename PA>
	void computeNextTransition(bool first, typename Automaton<PA>::Transition& tr,
			const typename PropertyTransitionTraits<PA>::PropertyTransitionSet& ts, SA& ks)
	{
		switch(first)
		{
		case 1:
			for (tr.propertyIndex = ts.begin(); tr.propertyIndex != ts.end(); ++tr.propertyIndex)
			{
				if (ks.satisfiesStateFormula(PropertyTransitionTraits<PA>::getFormula(*tr.propertyIndex), tr.source.first))
				{
					for (tr.systemIndex = 0; ; ++tr.systemIndex)
					{
						tr.target.first = ks.getNextState(tr.source.first, tr.systemIndex);
						if (tr.target.first == NONE)
							break;
						tr.target.second = PropertyTransitionTraits<PA>::getNextState(*tr.propertyIndex);
						return;
		default:;
					}
				}
			}
			/* no break */
		}
		tr.systemIndex = NONE;
		tr.target = make_pair(NONE,NONE);
	}
};

/**
 * An iterator for event-only graphs (formula, not fairness)
 */
template <>
struct ProductTransitionIteratorTraits<false,true>
{
	template <typename SA, typename PA>
	void computeNextTransition(bool first, typename Automaton<PA>::Transition& tr,
			const typename PropertyTransitionTraits<PA>::PropertyTransitionSet& ts, SA& ks)
	{
		switch(first)
		{
		case 1:
			for (tr.propertyIndex = ts.begin(); tr.propertyIndex != ts.end(); ++tr.propertyIndex)
			{
				for (tr.systemIndex = 0; ; ++tr.systemIndex)
				{
					tr.target.first = ks.getNextState(tr.source.first, tr.systemIndex);
					if (tr.target.first == NONE)
						break;

					// check state/event props
					if (ks.satisfiesStateEventFormula(PropertyTransitionTraits<PA>::getFormula(
							*tr.propertyIndex), tr.source.first, tr.systemIndex))
					{
						tr.target.second = PropertyTransitionTraits<PA>::getNextState(*tr.propertyIndex);
						return;
		default:;
					}
				}
			}
			/* no break */
		}
		tr.systemIndex = NONE;
		tr.target = make_pair(NONE,NONE);
	}
};

/**
 * an iterator for state/event graphs (formula, not fairness)
 */
template <>
struct ProductTransitionIteratorTraits<true,true>
{
	Bdd label;	// temporary label

	template <typename SA, typename PA>
	void computeNextTransition(bool first, typename Automaton<PA>::Transition& tr,
			const typename PropertyTransitionTraits<PA>::PropertyTransitionSet& ts, SA& ks)
	{
		pair<bool,Bdd> test;
		switch(first)
		{
		case 1:
			for (tr.propertyIndex = ts.begin(); tr.propertyIndex != ts.end(); ++tr.propertyIndex)
			{
				test = ks.satisfiesPartialStateFormula(PropertyTransitionTraits<PA>::getFormula(
						*tr.propertyIndex), tr.source.first);

				if (test.first)
				{
					label = test.second;
					for (tr.systemIndex = 0; ; ++tr.systemIndex)
					{
						tr.target.first = ks.getNextState(tr.source.first, tr.systemIndex);
						if (tr.target.first == NONE)
							break;
						//
						// check state/event props
						//
						if (ks.satisfiesStateEventFormula(label, tr.source.first, tr.systemIndex))
						{
							tr.target.second = PropertyTransitionTraits<PA>::getNextState(*tr.propertyIndex);
							return;
			default:;
						}
					}
				}
			}
			/* no break */
		}
		tr.systemIndex = NONE;
		tr.target = make_pair(NONE,NONE);
	}
};


}
