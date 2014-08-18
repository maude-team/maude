/*
 * SCCBuchiModelChecker.cc
 *
 *  Created on: Dec 6, 2010
 *      Author: kquine
 */

//      utility class definitions
#include "natSet.hh"
#include "SCCBuchiModelChecker.hh"

//#define TDEBUG

namespace modelChecker {

template <typename PA>
SCCBuchiModelChecker<PA>::SCCBuchiModelChecker(FairAutomaton<PA>& graph): SCCModelChecker<PA>(graph) {}

template <typename PA>
unique_ptr<typename SCCModelChecker<PA>::SCC>
SCCBuchiModelChecker<PA>::findAcceptedSCC(const vector<State>& initials)
{
	SCCStack stack(*this);

	for(const State& i : initials)
	{
		if (!this->H.contains(i))	// if the initial state has not visited yet..
		{
			stack.dfsPush(i,nullptr);
			while (! stack.empty() )	// main loop
			{
				if (stack.hasNextSucc())
				{
					Transition t = stack.pickSucc();
					auto a = this->graph.makeFairSet(t);
					stack.nextSucc();
#ifdef TDEBUG
					cout << t.source << " --> " << t.target << " " << flush;	a->dump(cout);	cout << endl;
#endif

					if (!this->H.contains(t.target))			// if the next state not visited yet..
					{
#ifdef TDEBUG
							cout << "    # NOT VISITED" << endl;
#endif
						stack.dfsPush(t.target, move(a));
					}
					else if (this->H.get(t.target) > 0)		// if on the dfs stack..
					{
#ifdef TDEBUG
							cout << "    # ON DEF STACK" << endl;
#endif
						stack.merge(this->H.get(t.target), move(a));
						if ( stack.topSCC()->acc_fair->isSatisfied() )
						{
#ifdef TDEBUG
								cout << "    #FIND";	stack.topSCC()->acc_fair->dump(cout);	cout << endl;
#endif
							return move(stack.topSCC());
						}
					}
				}
				else
					stack.sccPop();
			}
		}
	}
	return nullptr;
}


}
