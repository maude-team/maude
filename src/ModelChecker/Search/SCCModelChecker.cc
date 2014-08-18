/*
 * SCCModelChecker.cc
 *
 *  Created on: Dec 7, 2010
 *      Author: kquine
 */

//      utility class definitions
#include "natSet.hh"
#include "SCCModelChecker.hh"

//#define TDEBUG

namespace modelChecker {

template <typename PA>
SCCModelChecker<PA>::SCCModelChecker(FairAutomaton<PA>& graph): graph(graph) {}

template <typename PA> bool
SCCModelChecker<PA>::findCounterExample()
{
	if (const auto& res = findAcceptedSCC(graph.getInitialStates()))
	{
		const auto& goal = res->acc_fair->makeFairGoal(graph.getFairnessTable());
		const State& root = PrefixBFSGraph(*this,H,res->root).doBFS(leadIn);	// prefix

		State s = root;
		do {
			s = CycleBFSGraph(*this,H,res->root,s,*goal).doBFS(cycle);			// cycle
		}
		while( !goal->empty());

		if (s != root)
			CycleCompBFSGraph(*this,H,res->root,s,root).doBFS(cycle);			// cycle completion
		return true;
	}
	return false;
}

template <typename PA> bool
SCCModelChecker<PA>::SCCStack::hasNextSucc()
{
	// pop SCCs with no successors
	while ( !dfsStack.empty() &&
			sccStack.top()->root <= mc.H.get(dfsStack.top()->getSource()) && !dfsStack.top()->hasNext())
	{
		stateStack.push(dfsStack.top()->getSource());	// keep states of the top SCC for later use
		dfsStack.pop();
	}

	return  !dfsStack.empty() && sccStack.top()->root <= mc.H.get(dfsStack.top()->getSource());
}

template <typename PA> void
SCCModelChecker<PA>::SCCStack::dfsPush(const State& s, unique_ptr<FairSet>&& a)
{
	mc.H.set(s, ++mc.max);
	sccStack.emplace(new SCC(mc.max, move(a)));
	dfsStack.emplace(mc.graph.makeTransitionIterator(s));
}

template <typename PA>
typename SCCModelChecker<PA>::State
SCCModelChecker<PA>::SCCStack::sccPop(bool unvisit)
{
	Assert(mc.H.get(stateStack.top()) == sccStack.top()->root, "SCC Error (root index)");

	auto top_root = sccStack.top()->root;
	State root = stateStack.top();
	if (unvisit)
	{
		while (!stateStack.empty() && mc.H.get(stateStack.top()) >= top_root )
		{
			mc.H.remove(stateStack.top());	// set unvisited.
			stateStack.pop();
		}
	}
	else
	{
		while (!stateStack.empty() && mc.H.get(stateStack.top()) >= top_root )
		{
			mc.H.set(stateStack.top(), 0);	// set removed. (H[state] = 0 iff the state is removed from the dfs stack)
			stateStack.pop();
		}
	}
	mc.max = top_root - 1;
	sccStack.pop();
	return root;
}

template <typename PA> void
SCCModelChecker<PA>::SCCStack::merge(unsigned int threshold, unique_ptr<FairSet>&& back)
{
#ifdef TDEBUG
	cout << "\nMERGE:  ";	back->dump(cout);	cout << endl;
#endif
	while ( threshold <  sccStack.top()->root )
	{
		if (sccStack.top()->acc_fair)
		{
#ifdef TDEBUG
			cout << "  + ";	sccStack.top()->acc_fair->dump(cout);	cout << endl;
#endif
			back->merge(*sccStack.top()->acc_fair, mc.graph.getFairnessTable());
		}
		if (sccStack.top()->incoming_fair)
		{
#ifdef TDEBUG
			cout << "  + ";	sccStack.top()->incoming_fair->dump(cout);	cout << endl;
#endif
			back->merge(*sccStack.top()->incoming_fair, mc.graph.getFairnessTable());
		}
		sccStack.pop();
	}
	if (auto& top_acc = sccStack.top()->acc_fair)
	{
#ifdef TDEBUG
		cout << "  + ";	top_acc->dump(cout);	cout << endl;
#endif
		top_acc->merge(*back, mc.graph.getFairnessTable());
	}
	else
		top_acc = std::move(back);
#ifdef TDEBUG
	cout << "  = ";	sccStack.top()->acc_fair->dump(cout);	cout << "\n" << endl;
#endif
}

}
