/*
 * ConcreteResultGenerator.cc
 *
 *  Created on: Jul 26, 2014
 *      Author: kquine
 */

//  utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

// interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      core class definitions
#include "dagArgumentIterator.hh"
#include "rewritingContext.hh"

// lmc definitions
#include "ConcreteResultGenerator.hh"

namespace modelChecker {

ConcreteResultGenerator::ConcreteResultGenerator(StateFoldingGraph<StateMetaGraph>& graph,
		Symbol* counterexampleSymbol, Symbol* transitionSymbol,
		Symbol* transitionListSymbol, Symbol* nilTransitionListSymbol):
				CounterExampleGenerator(counterexampleSymbol,transitionSymbol,transitionListSymbol,nilTransitionListSymbol),
				graph(graph) {}

pair<DagNode*,bool>
ConcreteResultGenerator::makeConcreteCounterExample(bool subsumption, const list<Edge>& path, const list<Edge>& cycle)
{

	if (subsumption)
	{
		list<Edge> np, nc;
		if (concretePath(path, cycle, np, nc))
			return make_pair(this->makeCounterexample(graph,np,nc), true);			// real
		else
			return make_pair(this->makeCounterexample(graph,path,cycle), false);	// spurious
	}
	else	// renaming equivalence
	{
		return make_pair(this->makeCounterexample(graph, path, cycle),true);	// real
	}
}


bool
ConcreteResultGenerator::concretePath(const list<Edge>& path, const list<Edge>& cycle, list<Edge>& resP, list<Edge>& resCy)
{
	Assert (!path.empty() || !cycle.empty(), "ConcreteResultGenerator: empty counterexample");
	resP.clear();
	resCy.clear();
	return path.empty()?
			constConcrPath(path, cycle, cycle.begin(), true, cycle.front().first, resP, resCy):
			constConcrPath(path, cycle, path.begin(), false, path.front().first, resP, resCy);
}

bool
ConcreteResultGenerator::constConcrPath(const list<Edge>& path, const list<Edge>& cycle, list<Edge>::const_iterator pos,
		bool inCycle, unsigned int spos, list<Edge>& resP, list<Edge>& resCy)
{
	if (!inCycle && pos == path.end())
		return cycle.empty() ? true : constConcrPath(path,cycle, cycle.begin(),true, spos,resP,resCy);

	if (inCycle && pos == cycle.end())
		return cycle.front().first == spos;		// for a cycle, only when exactly matched

	if (pos->first == spos || graph.fold(pos->first, spos))
	{
		++ pos;
		for (int index = 0, next = NONE; (next = graph.getNextState(spos, index)) != NONE; ++index)
		{
			if (constConcrPath(path, cycle, pos, inCycle, next, resP, resCy))
			{
				if (inCycle)
					resCy.emplace_front(spos,index);
				else
					resP.emplace_front(spos,index);
				return true;
			}
		}
	}
	return false;
}

}
