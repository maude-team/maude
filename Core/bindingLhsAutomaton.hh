//
//      Class for left hand side automata that just bind a variable and call
//	another lhs automaton to do the real work.
//
#ifndef _bindingLhsAutomaton_hh_
#define _bindingLhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "lhsAutomaton.hh"

class BindingLhsAutomaton : public LhsAutomaton
{
  NO_COPYING(BindingLhsAutomaton);

public:
  BindingLhsAutomaton(int variableIndex, LhsAutomaton* realLhsAutomaton);
  ~BindingLhsAutomaton();
  //
  //	Standard LhsAutomaton operations.
  //
  bool match(DagNode* subject,
             Substitution& solution,
             Subproblem*& returnedSubproblem,
             ExtensionInfo* extensionInfo);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  const int variableIndex;
  LhsAutomaton* const realLhsAutomaton;
};

#endif
