/*
 * Automaton.hh
 *
 *  Created on: Sep 22, 2013
 *      Author: kquine
 */

#ifndef AUTOMATON_HH_
#define AUTOMATON_HH_
#include <memory>
#include "AbstractAutomaton.hh"
#include "buchiAutomaton2.hh"
#include "genBuchiAutomaton.hh"

namespace modelChecker {

template <typename PropertyAutomaton> struct PropertyTransitionTraits;

/**
 * A basic automata interface
 */
template <typename PA>
class Automaton: public AbstractAutomaton
{
public:
	using State =			AbstractAutomaton::State;
	using PropertyIndex	=	typename PropertyTransitionTraits<PA>::PropertyTransitionSet::const_iterator;
	struct Transition;
	struct TransitionIterator;

	virtual const PA& getPropertyAutomaton() const = 0;
	virtual unique_ptr<TransitionIterator> makeTransitionIterator(const State& state) = 0;
};

/**
 * A transition for an automaton
 */
template <typename PA>
struct Automaton<PA>::Transition
{
	State source, target;
	int systemIndex;
	PropertyIndex propertyIndex;
};

/**
 * An old-style iterator for transitions
 */
template <typename PA>
struct Automaton<PA>::TransitionIterator
{
	TransitionIterator(const State& state)	{ tr.source = state; }
	virtual ~TransitionIterator() = default;

	bool hasNext() const					{ return tr.systemIndex != NONE; }
	const Transition& pick() const			{ return tr; }
	const State& getSource() const			{ return tr.source; }
	void init()								{ computeNextTransition(true); }
	void next()								{ computeNextTransition(false); }

protected:
	virtual void computeNextTransition(bool first) = 0;

	typename Automaton<PA>::Transition tr;
};

/**
 * Print a state
 */
template <typename T1, typename T2>
inline ostream& operator<<(ostream &o, const pair<T1,T2>& pair)
{
	o << "(" << pair.first << "," <<  pair.second << ")";
	return o;
}

/**
 * property transition specialization for Buchi automata
 */
template <>
struct PropertyTransitionTraits<BuchiAutomaton2>
{
	using PropertyTransition =		BuchiAutomaton2::Transition;
	using PropertyTransitionSet =	BuchiAutomaton2::TransitionMap;
	static int getNextState(const PropertyTransition& t)		{ return t.first; }
	static const Bdd& getFormula(const PropertyTransition&t)	{ return t.second; }
};

/**
 * property transition specialization for generalied Buchi automata
 */
template <>
struct PropertyTransitionTraits<GenBuchiAutomaton>
{
	using PropertyTransition =		GenBuchiAutomaton::FairTransition;
	using PropertyTransitionSet =	GenBuchiAutomaton::FairTransitionSet;
	static int getNextState(const PropertyTransition& t)		{ return t.first.first; }
	static const Bdd& getFormula(const PropertyTransition&t)	{ return t.second; }
};

} /* namespace modelChecker */
#endif /* AUTOMATON_HH_ */
