//
//	Class for Very Weak Alternating Automata.
//
//	We implement the LTL to VWAA translation and VWAA optimization
//	algorithms from:
//	  Paul Gastin and Denis Oddoux.
//	  "Fast LTL to Buchi Automaton Translation",
//	  CAV 2001, LNCS 2102, pp 53-65, 2001.
//
#ifndef _veryWeakAlternationAutomaton_hh_
#define _veryWeakAlternationAutomaton_hh_
#include "bddUser.hh"
#include "transitionSet.hh"
#include "natSet.hh"

class VeryWeakAlternatingAutomaton : private BddUser
{
public:
  VeryWeakAlternatingAutomaton(LogicFormula* formula, int top);

  int getNrStates() const;
  int getNrFinalStates() const;
  const TransitionSet& getInitialStates();
  const TransitionSet& getTransitionSet(int stateIndex) const;
  void computeFairnessSet(const Transition& transition,
			  NatSet& fairnessSet);
  void dump(ostream& s) const;

private:
  void dnf(int subformulaIndex, TransitionSet& result);
  void computeTransitionSet(int subformulaIndex);
  void reachabilityOpt();
  void findReachable(const TransitionSet& ts);
  bool checkFairness(const Transition& transition, int finalStateIndex) const;

  TransitionSet initialStates;
  Vector<TransitionSet> states;
  Vector<int> finalStates;
  //
  //	Temporary data used during construction.
  //
  LogicFormula* const formula;
  int nrNewStates;
  Vector<int> renaming;
};

inline int
VeryWeakAlternatingAutomaton::getNrStates() const
{
  return states.length();
}

inline int
VeryWeakAlternatingAutomaton::getNrFinalStates() const
{
  return finalStates.length();
}

inline const TransitionSet&
VeryWeakAlternatingAutomaton::getInitialStates()
{
  return initialStates;
}

inline const TransitionSet&
VeryWeakAlternatingAutomaton::getTransitionSet(int stateIndex) const
{
  return states[stateIndex];
}

#endif
