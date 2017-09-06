//
//	Class for Buchi Automata.
//
#ifndef _buchiAutomaton2_hh_
#define _buchiAutomaton2_hh_
#include <map>
#include "bddUser.hh"
#include "bdd.hh"
#include "indexedSet.hh"

class BuchiAutomaton2 : private BddUser
{
public:
  typedef pair<int, Bdd> Transition;
  typedef map<int, Bdd> TransitionMap;

  BuchiAutomaton2(LogicFormula* formula, int top);

  int getNrStates() const;
  const NatSet& getInitialStates() const;
  bool isAccepting(int stateNr) const;
  const TransitionMap& getTransitions(int stateNr) const;

  void dump(ostream& s);

private:
  typedef IndexedSet<TransitionMap> TransitionMapTable;

  static void remapNatSet(NatSet& newSet,
			  const NatSet& oldSet,
			  const Vector<int>& natMap);

  bool hasNonAcceptingTarget(const TransitionMap& tm);
  void transformTransitionMap(TransitionMap& transformed,
			      const TransitionMap& original);
  void collapseStates();
  void generate(const GenBuchiAutomaton& g,
		int oldStateNr,
		int instanceNr);
  void insertTransition(TransitionMap& m, const Transition& t);

  NatSet initialStates;
  NatSet acceptingStates;
  Vector<int> states;
  TransitionMapTable transitionMaps;
};

inline int
BuchiAutomaton2::getNrStates() const
{
  return states.length();
}

inline const NatSet&
BuchiAutomaton2::getInitialStates() const
{
  return initialStates;
}

inline bool
BuchiAutomaton2::isAccepting(int stateNr) const
{
  return acceptingStates.contains(stateNr);
}

inline const BuchiAutomaton2::TransitionMap&
BuchiAutomaton2::getTransitions(int stateNr) const
{
  return transitionMaps.ithElement(states[stateNr]);
}

#endif
