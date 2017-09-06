//
//      Class for right hand side automata in the NA theory.
//
#ifndef _NA_RhsAutomaton_hh_
#define _NA_RhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rhsAutomaton.hh"

class NA_RhsAutomaton : public RhsAutomaton
{
  NO_COPYING(NA_RhsAutomaton);

public:
  NA_RhsAutomaton(NA_Term* term, int destination);
 
  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher);
  void replace(DagNode* old, Substitution& matcher);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  NA_Term* const term;
  int destination;
};

#endif
