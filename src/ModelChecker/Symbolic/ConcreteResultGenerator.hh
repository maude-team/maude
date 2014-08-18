/*
 * ConcreteResultGenerator.hh
 *
 *  Created on: Jul 26, 2014
 *      Author: kquine
 */

#ifndef CONCRETERESULTGENERATOR_HH_
#define CONCRETERESULTGENERATOR_HH_
#include "Interface/CounterExampleGenerator.hh"
#include "StateMetaGraph.hh"
#include "StateFoldingGraph.hh"

namespace modelChecker {

class ConcreteResultGenerator: private CounterExampleGenerator
{
public:
	ConcreteResultGenerator(StateFoldingGraph<StateMetaGraph>& graph,
			Symbol* counterexampleSymbol, Symbol* transitionSymbol,
			Symbol* transitionListSymbol, Symbol* nilTransitionListSymbol);

    pair<DagNode*,bool> makeConcreteCounterExample(bool subsumption,
    		const list<Edge>& path, const list<Edge>& cycle);	// the second indicates whether real counterexample

private:
    bool concretePath(const list<Edge>& path, const list<Edge>& cycle, list<Edge>& resP, list<Edge>& resCy);

    bool constConcrPath(const list<Edge>& path, const list<Edge>& cycle, list<Edge>::const_iterator pos,
    		bool inCycle, unsigned int statePos, list<Edge>& resP, list<Edge>& resCy);

    StateFoldingGraph<StateMetaGraph>& graph;
};

}

#endif /* CONCRETERESULTGENERATOR_HH_ */
