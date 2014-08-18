/*
 * StateFoldingGraph.cc
 *
 *  Created on: Aug 7, 2011
 *      Author: kquine
 */

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"

//	lmc declarations
#include "StateFoldingGraph.hh"

//#define TDEBUG

namespace modelChecker {

template <typename GRAPH>
StateFoldingGraph<GRAPH>::StateFoldingGraph(unique_ptr<GRAPH>&& graph, unique_ptr<FoldingChecker>&& sfc):
		graph(std::move(graph)), sfc(std::move(sfc)), levelIndices{0}
{
	insertFoldedState(0);
}

template <typename GRAPH> unsigned int
StateFoldingGraph<GRAPH>::getNrStates() const
{
	return maximalStates.size();
}

template <typename GRAPH> unsigned int
StateFoldingGraph<GRAPH>::getNrTransitions(unsigned int stateNr) const
{
	Assert(stateNr < foldGraph.size(), "StateFoldingGraph::getNrTransitions: invalid state lookup");
	const MaximalState* ms = safeCast(const MaximalState*,foldGraph[stateNr].get());
	return ms->trans ? 0 : ms->trans->size();
}

template <typename GRAPH> unsigned int
StateFoldingGraph<GRAPH>::getNrVisitedStates() const
{
	return graph->getNrVisitedStates();
}

template <typename GRAPH> unsigned int
StateFoldingGraph<GRAPH>::getNrVisitedTransitions(unsigned int stateNr) const
{
	return graph->getNrVisitedTransitions(stateNr);
}

template <typename GRAPH> int
StateFoldingGraph<GRAPH>::getNextState(unsigned int stateNr, unsigned int index)
{
	Assert(stateNr < foldGraph.size() && foldGraph[stateNr],
				"StateFoldingGraph::getNextState: unknown source state folding");

	const MaximalState* ms = safeCast(const MaximalState*,foldGraph[stateNr].get());
	return ms->trans ? (index < ms->trans->size() ? (*ms->trans)[index].first : NONE) : NONE;
}

template <typename GRAPH> DagNode*
StateFoldingGraph<GRAPH>::getStateDag(unsigned int stateNr) const
{
	return graph->getStateDag(stateNr);
}

template <typename GRAPH> DagNode*
StateFoldingGraph<GRAPH>::getTransitionDag(unsigned int stateNr, int unsigned index) const
{
	Assert(stateNr < foldGraph.size(), "StateFoldingGraph::getTransitionDag: invalid state lookup");
	const MaximalState* ms = safeCast(const MaximalState*,foldGraph[stateNr].get());

	Assert(ms->trans.get() != NULL && ((index == 0 && (*ms->trans).size() == 0) || index < (*ms->trans).size()),
			"StateFoldingGraph::getTransitionDag: invalid folding transition lookup");

	return (index == 0 && (*ms->trans).size() == 0) ? NULL
			: graph->getTransitionDag(stateNr, (*ms->trans)[index].second);
}

template <typename GRAPH> bool
StateFoldingGraph<GRAPH>::satisfiesStateFormula(Bdd formula, unsigned int stateNr) const
{
	return graph->satisfiesStateFormula(formula, stateNr);
}

template <typename GRAPH> bool
StateFoldingGraph<GRAPH>::fold(unsigned int s, unsigned int t) const
{
	return sfc->fold(getStateDag(s), getStateDag(t));
}

template <typename GRAPH> bool
StateFoldingGraph<GRAPH>::reachFixpoint() const
{
	return levelIndices[levelIndices.size() - 1] >= maximalStates.size();
}

template <typename GRAPH> unsigned int
StateFoldingGraph<GRAPH>::getCurrLevel() const
{
	return reachFixpoint() ? levelIndices.size() - 1 : levelIndices.size();
}

template <typename GRAPH> bool
StateFoldingGraph<GRAPH>::boundState(int stateNr) const
{
	return bool(safeCast(const MaximalState*,foldGraph[stateNr].get())->trans);
}

template <typename GRAPH> void
StateFoldingGraph<GRAPH>::incrementLevel()
{
	if (reachFixpoint())	// do nothing if already fixpoint reached
		return;

	auto oldSize = maximalStates.size();
	for(auto i = levelIndices[levelIndices.size() - 1]; i < oldSize; ++i)
	{
		auto mStateNr = maximalStates[i];
		MaximalState* ms = safeCast(MaximalState*,foldGraph[mStateNr].get());

		Assert(!ms->trans, "the maximal level, but already explored");
		ms->trans.reset(new vector<pair<int,int> >());

		// compute next states of maximal state ms
		for (int j = 0, n = NONE; (n = graph->getNextState(mStateNr,j)) != NONE; ++j)
		{
			insertFoldedState(n);	//	state folding
			//
			//	folding graph
			//
			if (FoldedState* fns = dynamic_cast<FoldedState*>(foldGraph[n].get()))	// if the target state is folded
			{
				for(auto k : fns->foldRel)
					ms->trans->emplace_back(k, j);	// set a next state to be folding states
			}
			else
				ms->trans->emplace_back(n, j);		// if the target NOT folded
		}
	}
	levelIndices.push_back(oldSize);
}

template <typename GRAPH> void
StateFoldingGraph<GRAPH>::insertFoldedState(unsigned int stateNr)
{
	// TODO: indexing mechanisms for folding relations, and backward folding

	if (stateNr >= foldGraph.size())
		foldGraph.resize(stateNr + 1);

	if (foldGraph[stateNr])	// do NOTHING if stateNr have already been created
		return;

	set<int> foldingStates;
	for (auto ms : maximalStates)		// get maximal states that subsumes "stateNr"
	{
		if (this->fold(ms,stateNr))		// forward folding
			foldingStates.insert(ms);
	}

	if (foldingStates.empty())			// if not folded, i.e., stateNR is maximal
	{
		foldGraph[stateNr].reset(new MaximalState());
		maximalStates.push_back(stateNr);
	}
	else	// folding cases
	{
		foldGraph[stateNr].reset(new FoldedState(std::move(foldingStates)));
	}
}


template <typename GRAPH> void
StateFoldingGraph<GRAPH>::dump(ostream& o, unsigned int stateNr, PrettyPrinter* stateP, PrettyPrinter* transP) const
{
	if (auto fs = dynamic_cast<const FoldedState*>(foldGraph[stateNr].get()))
	{
	}
	else
	{
		o << " " << stateNr;
		o << ": ";
		stateP->print(cout, getStateDag(stateNr));
		o << endl;
	}
	for (int j = 0; j < graph->getNrTransitions(stateNr); ++j)
	{
		auto nx = graph->getNextState(stateNr,j);
		o << "    " << "-[ ";
		transP->print(cout, graph->getTransitionDag(stateNr,j));
		o << " ]-> " << nx;
		dump_fold(o, nx);
		o << endl;
	}
}

template <typename GRAPH> void
StateFoldingGraph<GRAPH>::dump_fold(ostream& o, unsigned int stateNr) const
{
	if (auto fs = dynamic_cast<const FoldedState*>(foldGraph[stateNr].get()))
	{
		o << "[folded";
		FOR_EACH_CONST(j, set<int>, fs->foldRel)
		{
			o << " " << *j;
		}
		o << "]";
	}
}

}
