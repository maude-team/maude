/*
 * StateFoldingGraph.hh
 *
 *  Created on: Aug 7, 2011
 *      Author: kquine
 */

#ifndef STATEFOLDINGGRAPH_HH_
#define STATEFOLDINGGRAPH_HH_
#include <memory>
#include <set>
#include "protectedDagNodeSet.hh"
#include "Graph/DagSystemGraph.hh"
#include "FoldingChecker.hh"
#include "PrettyPrinter.hh"

namespace modelChecker {

template <typename GRAPH>
class StateFoldingGraph: public DagSystemGraph
{
public:
	StateFoldingGraph(unique_ptr<GRAPH>&& graph, unique_ptr<FoldingChecker>&& sfc);

	StateFoldingGraph(const StateFoldingGraph&) = delete;
	StateFoldingGraph& operator=(const StateFoldingGraph&) = delete;
	virtual ~StateFoldingGraph() = default;

	unsigned int getNrStates() const override;
	unsigned int getNrTransitions(unsigned int stateNr) const override;
    unsigned int getNrVisitedStates() const override;
    unsigned int getNrVisitedTransitions(unsigned int stateNr) const override;
	int getNextState(unsigned int stateNr, unsigned int index) override;

    DagNode* getStateDag(unsigned int stateNr) const override;
    DagNode* getTransitionDag(unsigned int stateNr, unsigned int index) const override;
    bool satisfiesStateFormula(Bdd formula, unsigned int stateNr) const;

    bool fold(unsigned int s, unsigned int t) const;
	bool reachFixpoint() const;
	unsigned int getCurrLevel() const;
	bool boundState(int stateNr) const;
	void incrementLevel();

	void dump(ostream& o, unsigned int stateNr, PrettyPrinter* stateP, PrettyPrinter* transP) const;	// state dump

private:
	struct State;
	struct MaximalState;
	struct FoldedState;

	void insertFoldedState(unsigned int stateNr);

	void dump_fold(ostream& o, unsigned int stateNr) const;

	const unique_ptr<GRAPH> graph;			// underlying graph
	const unique_ptr<FoldingChecker> sfc;	// state folding checker

	vector<unique_ptr<State>> foldGraph;	// folding graph (the same stateIndex with the underlying graph)
	vector<unsigned int> maximalStates;		// the maximal state indices
	vector<unsigned int> levelIndices;		// the vector of the least indices with each level (in maximalStates)
};


template <typename GRAPH>
struct StateFoldingGraph<GRAPH>::State
{
	virtual ~State() = default;
};

template <typename GRAPH>
struct StateFoldingGraph<GRAPH>::MaximalState: public State
{
	unique_ptr<vector<pair<int,int>>> trans;	// (next state, orig trIndex)
};

template <typename GRAPH>
struct StateFoldingGraph<GRAPH>::FoldedState: public State
{
	FoldedState(set<int>&& fs): foldRel(std::move(fs)) {}
	set<int> foldRel;	// folded States (in original graph)
};

}

#include "StateFoldingGraph.cc"	// to separate the implementation for the template


#endif /* STATEFOLDINGGRAPH_HH_ */
