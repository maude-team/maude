//
//	Class for trivial right hand side automata which just does a construct
//	or replace using an already bound (pseudo)-variable.
//
#ifndef _trivialRhsAutomaton_hh_
#define _trvialRhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rhsAutomaton.hh"

class TrivialRhsAutomaton : public RhsAutomaton
{
  NO_COPYING(TrivialRhsAutomaton);

public:
  TrivialRhsAutomaton(int index);

  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher);
  void replace(DagNode* old, Substitution& matcher);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  int index;
};

#endif
