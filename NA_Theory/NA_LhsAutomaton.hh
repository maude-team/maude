//
//      Class for left hand side automata in the NA theory.
//
#ifndef _NA_LhsAutomaton_hh_
#define _NA_LhsAutomaton_hh_
#include "lhsAutomaton.hh"

class NA_LhsAutomaton : public LhsAutomaton
{
  NO_COPYING(NA_LhsAutomaton);

public:
  NA_LhsAutomaton(NA_Term* term);
  
  bool match(DagNode* subject,
             Substitution& solution,
             Subproblem*& returnedSubproblem,
             ExtensionInfo* extensionInfo);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  NA_Term* const term;
};

#endif
