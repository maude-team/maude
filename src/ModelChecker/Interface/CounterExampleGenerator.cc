/*
 * CounterExampleGenerator.cc
 *
 *  Created on: Aug 6, 2013
 *      Author: kquine
 */

//  utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      core class definitions
#include "dagArgumentIterator.hh"
#include "rewritingContext.hh"

// ltlr definitions
#include "CounterExampleGenerator.hh"

//#define TDEBUG

namespace modelChecker {

CounterExampleGenerator::CounterExampleGenerator(Symbol* counterexampleSymbol, Symbol* transitionSymbol,
		Symbol* transitionListSymbol, Symbol* nilTransitionListSymbol):
				counterexampleSymbol(counterexampleSymbol), transitionSymbol(transitionSymbol),
				transitionListSymbol(transitionListSymbol), nilTransitionListSymbol(nilTransitionListSymbol) {}

DagNode*
CounterExampleGenerator::makeCounterexample(const DagSystemGraph& dg, const list<Edge>& path, const list<Edge>& cycle) const
{
#ifdef TDEBUG
	cout << "counter example: " << endl;
	cout << "  path: ";
	for (auto& i : path) cout << i.first << "=(" << i.second << ")=> ";
	cout << "\n  cycle: ";
	for (auto& j : cycle) cout << j.first << "=(" << j.second << ")=> ";
	cout << endl;
#endif

	static Vector<DagNode*> args(2);
	args[0] = makeTransitionList(dg, path);
	args[1] = makeTransitionList(dg, cycle);
	return counterexampleSymbol->makeDagNode(args);
}


DagNode*
CounterExampleGenerator::makeTransitionList(const DagSystemGraph& dg, const list<Edge>& path) const
{
    if (path.empty())
        return nilTransitionListSymbol->makeDagNode();
    else
    {
		Vector<DagNode*> args;
		for(const Edge& i : path)
			args.append(makeTransition(dg, i.first, i.second));
		return (args.length() == 1) ? args[0] : transitionListSymbol->makeDagNode(args);
    }
}

DagNode*
CounterExampleGenerator::makeTransition(const DagSystemGraph& dg, unsigned int stateNr, unsigned int count) const
{
	static Vector<DagNode*> targs(2);
	targs[0] = dg.getStateDag(stateNr);
	targs[1] = dg.getTransitionDag(stateNr, count);
	return transitionSymbol->makeDagNode(targs);
}

} /* namespace modelChecker */
