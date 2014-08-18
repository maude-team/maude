/*
 * BFSGraph.hh
 *
 *  Created on: Nov 29, 2010
 *      Author: kquine
 */

#ifndef BFSGRAPH_HH_
#define BFSGRAPH_HH_
#include <list>
#include <queue>
#include "macros.hh"
#include "Utility/StateMap.hh"
#include "Automaton/Automaton.hh"
#include "ModelChecker.hh"

namespace modelChecker {

//
//	Used for short counter example generation (by breadth first search).
//
template <typename PA>
class BFSGraph
{
	using Edge	= 				ModelChecker::Edge;
public:
	using State =				typename Automaton<PA>::State;
	using Transition =			typename Automaton<PA>::Transition;
	using TransitionIterator =	typename Automaton<PA>::TransitionIterator;

	BFSGraph(Automaton<PA>& graph, const vector<State>& initials);
	virtual ~BFSGraph() = default;

	virtual bool inDomain(const State& s) const = 0;
	virtual bool isTarget(const State& t) const = 0;
	virtual bool isTarget(const Transition& t) = 0;
	State doBFS(list<Edge>& path);

protected:
	Automaton<PA>& graph;

private:
	struct Step;		// used for counter-example generation

	queue<State> toVisit;
	StateMap<Step> parent;			// parent state + transition index
	const vector<State>& initials;
};

template <typename PA>
struct BFSGraph<PA>::Step		// used for counter-example generation
{
	Step() : Step(make_pair(NONE,NONE), NONE) {}
	Step(const State& p, int index) : parent(p), systemIndex(index) {}
	State parent;
	int systemIndex;
};

}

#include "BFSGraph.cc"

#endif /* BFSGRAPH_HH_ */
