//
//      Class for right hand side automata which make copies of
//	bindings in the substitution.
//
#ifndef _copyRhsAutomaton_hh_
#define _copyRhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rhsAutomaton.hh"

class CopyRhsAutomaton : public RhsAutomaton
{
  NO_COPYING(CopyRhsAutomaton);

public:
  CopyRhsAutomaton(int originalIndex, int copyIndex);
  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher);
  void replace(DagNode* old, Substitution& matcher);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel = 0);
#endif

private:
  int originalIndex;
  int copyIndex;
};

#endif
