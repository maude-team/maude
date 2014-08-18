/*
 * NDFSModelChecker.cc
 *
 *  Created on: Dec 1, 2010
 *      Author: kquine
 */

#include "natSet.hh"
#include "BFSGraph.hh"
#include "NDFSModelChecker.hh"

//#define TDEBUG
//#define NO_PREFIX_OPT

namespace modelChecker {

template <typename PA>
NDFSModelChecker<PA>::NDFSModelChecker(Automaton<PA>& prod): prod(prod) {}

template <typename PA> bool
NDFSModelChecker<PA>::findCounterExample()
{
	intersectionStates.emplace_back(new StateSet);
	auto& is = prod.getInitialStates();
	bool result = any_of(is.begin(), is.end(), [&](const State& i) {return this->dfs1(i);});

#ifndef NO_PREFIX_OPT
	if (result)	// Shorten prefix of a counterexample using BFS if it's found
	{
		leadIn.clear();
		PrefixBFSGraph(prod,intersectionStates,cycleState).doBFS(leadIn);
	}
#endif
	return result;
}


template <typename PA> bool
NDFSModelChecker<PA>::trap(const State& s) const
{
	const int propertyIndex = s.second;
	if (prod.getPropertyAutomaton().isAccepting(propertyIndex))
	{
		auto& cm = prod.getPropertyAutomaton().getTransitions(propertyIndex);
		if (cm.size() == 1 && cm.begin()->first == propertyIndex && cm.begin()->second == bdd_true())
			return true;
	}
	return false;
}

template <typename PA> bool
NDFSModelChecker<PA>::checkVisit(const State& ns)
{
	if ( (unsigned int)ns.first <  intersectionStates.size() )				// return true if ns.first = NONE
		return intersectionStates[ns.first]->dfs1Seen.contains(ns.second);
	else
	{
		while (ns.first >= 0 && (unsigned int)ns.first >=  intersectionStates.size())
			intersectionStates.emplace_back(new StateSet);	// allocate state space
	}
	return false;
}

template <typename PA> bool
NDFSModelChecker<PA>::dfs1(const State& initial)
{
	stack<unique_ptr<TransitionIterator> > dfs1;
	intersectionStates[initial.first]->dfs1Seen.insert(initial.second);
	intersectionStates[initial.first]->onDfs1Stack.insert(initial.second);
	leadIn.push_back(make_pair(NONE,NONE));	// dummy node to make "leadIn" have the same size with dfs1 stack.
	dfs1.push(prod.makeTransitionIterator(initial));

	while (!dfs1.empty())
	{
		if (dfs1.top()->hasNext())
		{
			State ns = dfs1.top()->pick().target;
			auto sysIndex = dfs1.top()->pick().systemIndex;
#ifdef TDEBUG
			cout << "DFS1: " << dfs1.top()->pick().source << " -(" << sysIndex << ")-> " << ns << " " << endl;
#endif
			dfs1.top()->next();

			if (checkVisit(ns))
				continue;	// skip already visited

			// if not visited yet
			intersectionStates[ns.first]->dfs1Seen.insert(ns.second);
			intersectionStates[ns.first]->onDfs1Stack.insert(ns.second);
			leadIn.push_back(make_pair(dfs1.top()->getSource().first, sysIndex));
			dfs1.push(prod.makeTransitionIterator(ns));

			// if a trap state, then stop immediately (a cycle part counterexample will be an empty list)
			if (trap(ns))
			{
				cycleState = ns;
				leadIn.pop_front();		// remove dummy
				return true;
			}
		}
		else	// pop
		{
			auto& cur = dfs1.top()->getSource();
			if (prod.getPropertyAutomaton().isAccepting(cur.second))	// if accepting state
			{
				if (dfs2(cur))
				{
					while (dfs1.top()->getSource() != cycleState)	// complete the list "cycle" for the counterexample
					{
						cycle.push_front(leadIn.back());
						leadIn.pop_back();
						dfs1.pop();
					}
					leadIn.pop_front();		// remove dummy
					return true;
				}
			}
			intersectionStates[cur.first]->onDfs1Stack.subtract(cur.second);
			dfs1.pop();
			leadIn.pop_back();
		}
	}
	return false;
}

template <typename PA> bool
NDFSModelChecker<PA>::dfs2(const State& initial)
{
	stack<unique_ptr<TransitionIterator> > dfs2;
	intersectionStates[initial.first]->dfs2Seen.insert(initial.second);
	cycle.push_back(make_pair(NONE,NONE));	// dummy node to make "cycle" have the same size with dfs2 stack.
	dfs2.push(prod.makeTransitionIterator(initial));

	while (!dfs2.empty())
	{
		if (dfs2.top()->hasNext())
		{
			State ns = dfs2.top()->pick().target;
			auto sysIndex = dfs2.top()->pick().systemIndex;
#ifdef TDEBUG
			cout << "DFS2: " << dfs2.top()->pick().source << " -(" << sysIndex << ")-> " << ns << " " << endl;
#endif
			dfs2.top()->next();

			Assert( ns.first >= 0 && (unsigned int)ns.first < intersectionStates.size(),
					"visited system state for the first time on dfs2");
			StateSet& sset = *intersectionStates[ns.first];
			if ( sset.onDfs1Stack.contains(ns.second))	// found an accepted cycle
			{
				cycleState = ns;
				cycle.push_back(make_pair(dfs2.top()->getSource().first, sysIndex));
				cycle.pop_front();		// remove dummy
				return true;
			}
			if ( !sset.dfs2Seen.contains(ns.second))	// not visited yet during DFS2
			{
				sset.dfs2Seen.insert(ns.second);
				cycle.push_back(make_pair(dfs2.top()->getSource().first, sysIndex));
				dfs2.push(prod.makeTransitionIterator(ns));
			}
			// skip
		}
		else
		{
			dfs2.pop();
			cycle.pop_back();
		}
	}
	return false;
}


}
