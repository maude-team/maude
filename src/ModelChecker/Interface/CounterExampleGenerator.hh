/*
 * CounterExampleGenerator.hh
 *
 *  Created on: Aug 6, 2013
 *      Author: kquine
 */

#ifndef COUNTEREXAMPLEGENERATOR_HH_
#define COUNTEREXAMPLEGENERATOR_HH_
#include <deque>
#include "Graph/DagSystemGraph.hh"
#include "Search/ModelChecker.hh"

namespace modelChecker {

class CounterExampleGenerator
{
public:
	using Edge = ModelChecker::Edge;

	CounterExampleGenerator(Symbol* counterexampleSymbol,
			Symbol* transitionSymbol, Symbol* transitionListSymbol, Symbol* nilTransitionListSymbol);

	DagNode* makeCounterexample(const DagSystemGraph& dg, const list<Edge>& path, const list<Edge>& cycle) const;

private:
    DagNode* makeTransitionList(const DagSystemGraph& dg, const list<Edge>& path) const;
    DagNode* makeTransition(const DagSystemGraph& dg, unsigned int stateNr, unsigned int count) const;

    Symbol* counterexampleSymbol;
    Symbol* transitionSymbol;
    Symbol* transitionListSymbol;
    Symbol* nilTransitionListSymbol;
};

} /* namespace modelChecker */
#endif /* COUNTEREXAMPLEGENERATOR_HH_ */
