/*
 * NDFSModelChecker.hh
 *
 *  Created on: Nov 26, 2010
 *      Author: kquine
 */

#ifndef NDFSMODELCHECKER_HH_
#define NDFSMODELCHECKER_HH_
#include <memory>
#include "buchiAutomaton2.hh"
#include "Automaton/Automaton.hh"
#include "ModelChecker.hh"
#include "BFSGraph.hh"

namespace modelChecker {

template <typename PA>
class NDFSModelChecker: public ModelChecker
{
	using State =				typename Automaton<PA>::State;
	using Transition =			typename Automaton<PA>::Transition;
	using TransitionIterator =	typename Automaton<PA>::TransitionIterator;

public:
	explicit NDFSModelChecker(Automaton<PA>& prod);

	bool findCounterExample() override;

private:
	struct StateSet
	{
		NatSet dfs1Seen;
	    NatSet onDfs1Stack;		// flags for states on dfs1 stack
	    NatSet dfs2Seen;
	};
	class PrefixBFSGraph;				// for generating prefix counter example

	bool trap(const State& s) const;	// return true for a trap state
	bool checkVisit(const State& ns);

	bool dfs1(const State& initial);	// outer dfs
	bool dfs2(const State& initial);	// inner dfs

	State cycleState;					// intersection of cycle and prefix after nested dfs
	vector<unique_ptr<StateSet>> intersectionStates;

	Automaton<PA>& prod;
};

template <typename PA>
class NDFSModelChecker<PA>::PrefixBFSGraph : public BFSGraph<PA>
{
public:
	PrefixBFSGraph(Automaton<PA>& prod, const vector<unique_ptr<StateSet> >& stateMap, const State& cycleState):
		BFSGraph<PA>(prod, prod.getInitialStates()), cycleState(cycleState), stateMap(stateMap) {}

	bool isTarget(const State& s) const	{ return s == cycleState; }
	bool isTarget(const Transition& t)	{ return isTarget(t.target); }

	bool inDomain(const State& s) const	{
		// ignore unvisited states
		return (size_t)s.first < stateMap.size() ? stateMap[s.first]->dfs1Seen.contains(s.second) : false;
	}

private:
	const State cycleState;
	const vector<unique_ptr<StateSet> >& stateMap;
};

}

#include "NDFSModelChecker.cc"

#endif /* NDFSMODELCHECKER_HH_ */
