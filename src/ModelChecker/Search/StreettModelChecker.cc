/*
 * StreettModelChecker.cc
 *
 *  Created on: Dec 8, 2010
 *      Author: kquine
 */

#include <queue>
#include "natSet.hh"
#include "BFSGraph.hh"
#include "StreettModelChecker.hh"

//#define TDEBUG

namespace modelChecker {

template <typename PA>
StreettModelChecker<PA>::StreettModelChecker(FairAutomaton<PA>& graph): SCCModelChecker<PA>(graph) {}

template <typename PA>
unique_ptr<typename SCCModelChecker<PA>::SCC>
StreettModelChecker<PA>::findAcceptedSCC(const vector<State>& initials)
{
	queue<State> region;
	for(const State& i : initials)
		region.push(i);
	return findAcceptedSCC(region, nullptr);
}

template <typename PA>
unique_ptr<typename SCCModelChecker<PA>::SCC>
StreettModelChecker<PA>::findAcceptedSCC(queue<State>& region, FairSet::Bad* bad)
{
	SCCStack stack(*this);

	while ( !region.empty())
	{
		State cur = region.front();
		region.pop();

		if (! this->H.contains(cur))
		{
			stack.dfsPush(cur,nullptr);
			while (! stack.empty() )	// main loop
			{
				if (stack.hasNextSucc())
				{
					Transition t = stack.pickSucc();
					unique_ptr<FairSet> a(this->graph.makeFairSet(t));
					stack.nextSucc();
#ifdef TDEBUG
					cout << t.source << " --> " << t.target << " " << flush;	a->dump(cout);	cout << endl;
#endif
					if (bad != nullptr && bad->isBad(*a, this->graph.getFairnessTable()))	// if bad transition
					{
#ifdef TDEBUG
						cout << "    # BAD  ";	bad->dump(cout);	cout << endl;
#endif
						region.push(t.target);
					}
					else
					{
						if (!this->H.contains(t.target))			// if not visited yet
						{
#ifdef TDEBUG
							cout << "    # NOT VISITED" << endl;
#endif
							stack.dfsPush(t.target, std::move(a));
						}
						else if (this->H.get(t.target) > 0)		// if on the dfs stack..
						{
#ifdef TDEBUG
							cout << "    # ON DEF STACK" << endl;
#endif
							stack.merge(this->H.get(t.target), std::move(a));
							if ( stack.topSCC()->acc_fair->isSatisfied() )
							{
#ifdef TDEBUG
								cout << "    #FIND";	stack.topSCC()->acc_fair->dump(cout);	cout << endl;
#endif
								return move(stack.topSCC());
							}
						}
#ifdef TDEBUG
						else cout << "    # SKIP" << endl;
#endif
					}
				}
				else	// SCC pop
				{
#ifdef TDEBUG
					cout << "## POP" << endl;
#endif
					// revisit the SCC ff there is a new bad goal
					if (const auto& new_bad = makeNewBadGoal(stack.topSCC()->acc_fair,bad))
					{
						queue<State> new_region;
						new_region.push(stack.sccPop(true));	// pop the top SCC with *unvisit*

						if (auto scc = findAcceptedSCC(new_region, new_bad.get()))
							return scc;
					}
					else
						stack.sccPop();
				}
			}
		}
	}
	return nullptr;
}

template <typename PA>
unique_ptr<FairSet::Bad>
StreettModelChecker<PA>::makeNewBadGoal(const unique_ptr<FairSet>& fair, const FairSet::Bad* old)
{
	if (fair)
	{
		unique_ptr<FairSet::Bad> new_bad = fair->makeBadGoal();
		if ( !new_bad->empty())
		{
			if (old)
				new_bad->merge(*old);
			return new_bad;
		}
	}
	return nullptr;
}

}
