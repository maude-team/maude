/*
 * SCCModelChecker.hh
 *
 *  Created on: Nov 29, 2010
 *      Author: kquine
 */

#ifndef SCCMODELCHECKER_HH_
#define SCCMODELCHECKER_HH_
#include "Utility/StateMap.hh"
#include "Automaton/FairAutomaton.hh"
#include "ModelChecker.hh"
#include "BFSGraph.hh"


namespace modelChecker {

template <typename PA>
class SCCModelChecker: public ModelChecker
{
public:
	using State =				typename FairAutomaton<PA>::State;
	using Transition =			typename FairAutomaton<PA>::Transition;
	using TransitionIterator =	typename FairAutomaton<PA>::TransitionIterator;

	explicit SCCModelChecker(FairAutomaton<PA>& graph);

	bool findCounterExample() override;

protected:
	using IndexMap = StateMap<unsigned int>;

	struct SCC	//	scc = (root index, incoming fair set, scc acceptance fair set)
	{
		SCC(unsigned int root, unique_ptr<FairSet>&& incoming): root(root), incoming_fair(move(incoming)) {}

		const unsigned int root;
		const unique_ptr<FairSet> incoming_fair;
		unique_ptr<FairSet> acc_fair;
	};

	class SCCStack
	{
	public:
		SCCStack(SCCModelChecker<PA>& mc): mc(mc) {}

		bool empty() const					{ return sccStack.empty(); }
		unique_ptr<SCC>& topSCC()			{ return sccStack.top(); }
		void nextSucc()						{ dfsStack.top()->next(); }
		const Transition& pickSucc() const	{ return dfsStack.top()->pick(); }

		bool hasNextSucc();
		State sccPop(bool unvisit = false);	// pop and return a root

		void dfsPush(const State& s, unique_ptr<FairSet>&& a);
		void merge(unsigned int threshold, unique_ptr<FairSet>&& back);

	private:
		stack<unique_ptr<SCC>> sccStack;
		stack<unique_ptr<TransitionIterator>> dfsStack;
		stack<State> stateStack;
		SCCModelChecker<PA>& mc;
	};

	virtual unique_ptr<SCC> findAcceptedSCC(const vector<State>& initials) = 0;

	unsigned int max = 0;				// dfs index
	IndexMap H;
	FairAutomaton<PA>& graph;

private:
	class SCCBFSGraph;
	class PrefixBFSGraph;
	class CycleBFSGraph;
	class CycleCompBFSGraph;
};

//
//	to generate counter example..
//
template <typename PA>
class SCCModelChecker<PA>::SCCBFSGraph: public BFSGraph<PA>
{
public:
	SCCBFSGraph(SCCModelChecker<PA>& mc, const IndexMap& H, unsigned int root, const vector<State>& initials):
		BFSGraph<PA>(mc.graph, initials), root(root), map(H), mc(mc) {}

protected:
	const unsigned int root;
	const IndexMap& map;
	SCCModelChecker<PA>& mc;
};

template <typename PA>
struct SCCModelChecker<PA>::PrefixBFSGraph: public SCCBFSGraph
{
	PrefixBFSGraph(SCCModelChecker<PA>& mc, const IndexMap& H, unsigned int root):
		SCCBFSGraph(mc,H,root, mc.graph.getInitialStates()) {}

	bool inDomain(const State& s) const	{ return this->map.contains(s); }
	bool isTarget(const State& s) const	{ return inDomain(s) && this->map.get(s) >= this->root; }
	bool isTarget(const Transition& t)	{ return isTarget(t.target); }
};

template <typename PA>
class SCCModelChecker<PA>::CycleCompBFSGraph: public SCCBFSGraph
{
public:
	CycleCompBFSGraph(SCCModelChecker<PA>& mc, const IndexMap& H, unsigned int root, const State& start, const State& des):
		SCCBFSGraph(mc,H,root,initial), des(des), initial{start} {}

	bool inDomain(const State& s) const	{ return this->map.contains(s) && this->map.get(s) >= this->root; }
	bool isTarget(const State& s) const	{ return s == des; }
	bool isTarget(const Transition& t)	{ return isTarget(t.target); }

private:
	const State des;
	const vector<State> initial;
};

template <typename PA>
class SCCModelChecker<PA>::CycleBFSGraph: public SCCBFSGraph
{
public:
	CycleBFSGraph(SCCModelChecker<PA>& mc, const IndexMap& H, unsigned int root, const State& start, FairSet::Goal& goal):
		SCCBFSGraph(mc,H,root,initial), goal(goal), initial{start} {}

	bool inDomain(const State& s) const	{ return this->map.contains(s) && this->map.get(s) >= this->root; }
	bool isTarget(const State& ) const	{ return false; }
	bool isTarget(const Transition& t)	{
		return goal.empty() ||	// already satisfied
			   goal.update(*this->mc.graph.makeFairSet(t), this->mc.graph.getFairnessTable());
	}

private:
	FairSet::Goal& goal;
	const vector<State> initial;
};

}

#include "SCCModelChecker.cc"

#endif /* SCCMODELCHECKER_HH_ */
