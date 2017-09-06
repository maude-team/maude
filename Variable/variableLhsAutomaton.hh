//
//      Class for left hand side automata when lhs is a bare variable.
//
#ifndef _variableLhsAutomaton_hh_
#define _variableLhsAutomaton_hh_
#include "lhsAutomaton.hh"

class VariableLhsAutomaton : public LhsAutomaton
{
  NO_COPYING(VariableLhsAutomaton);

public:
  VariableLhsAutomaton(int index, const Sort* sort, bool copyToAvoidOverwriting);

  bool match(DagNode* subject,
	     Substitution& solution,
	     Subproblem*& returnedSubproblem,
	     ExtensionInfo* extensionInfo);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  const int index;
  const Sort* const sort;
  const bool copyToAvoidOverwriting;
};
 
#endif
