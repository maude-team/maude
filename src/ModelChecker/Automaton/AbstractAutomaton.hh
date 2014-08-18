/*
 * AbstractAutomaton.hh
 *
 *  Created on: Jul 26, 2014
 *      Author: kquine
 */

#ifndef ABSTRACTAUTOMATON_HH_
#define ABSTRACTAUTOMATON_HH_

/**
 * A place holder for an automaton, an interface for model checkers.
 * Notice that a virtual destructor is used to ensure a correct memory
 * deallocation for automata.
 *
 */
class AbstractAutomaton
{
public:
	using State			= pair<int,int>;

	virtual ~AbstractAutomaton() = default;
	virtual const vector<State>& getInitialStates() const = 0;
};

#endif /* ABSTRACTAUTOMATON_HH_ */
