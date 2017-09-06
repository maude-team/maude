//
//	Class for LTL model checking.
//
//	We implement the double depth first search method from:
//	  G. J. Holzmann, D. Peled and M. Yannakakis,
//	  "On nested depth first search",
//	  Second SPIN Workshop, pp23-32, AMS 1996.
//
#ifndef _modelChecker2_hh_
#define _modelChecker2_hh_
#include <list>
#include "natSet.hh"
#include "buchiAutomaton2.hh"

class ModelChecker2
{
  NO_COPYING(ModelChecker2);

public:
  struct System
  {
    virtual int getNextState(int stateNr, int transitionNr) = 0;
    virtual bool checkProposition(int stateNr, int propositionIndex) const = 0;
  };

  ModelChecker2(System& system, LogicFormula& property, int top);
  bool findCounterexample();
  const list<int>& getLeadIn() const;
  const list<int>& getCycle() const;

private:
  struct StateSet
  {
    NatSet dfs1Seen;
    NatSet onDfs1Stack;
    NatSet dfs2Seen;
    NatSet testedProps;
    NatSet trueProps;
  };

  bool dfs1PropertyTransitions(int systemStateNr, int propertyStateNr);
  bool dfs2PropertyTransitions(int systemStateNr, int propertyStateNr);
  bool dfs1SystemTransitions(int systemStateNr, int propertyStateNr);
  bool dfs2SystemTransitions(int systemStateNr, int propertyStateNr);
  bool satisfiesPropositionalFormula(int systemStateNr, Bdd formula);

  System& system;
  BuchiAutomaton2 propertyAutomaton;
  Vector<StateSet> intersectionStates;
  //
  //	Stuff for recovering counterexample.
  //
  int cycleSystemStateNr;
  int cyclePropertyStateNr;
  list<int> path;
  list<int> cycle;
};

inline const list<int>&
ModelChecker2::getLeadIn() const
{
  return path;
}

inline const list<int>&
ModelChecker2::getCycle() const
{
  return cycle;
}

#endif
