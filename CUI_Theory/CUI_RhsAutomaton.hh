//
//      Class for right hand side automata for theories made from C, Ul, Ur and I axioms.
//
#ifndef _CUI_RhsAutomaton_hh_
#define _CUI_RhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rhsAutomaton.hh"

class CUI_RhsAutomaton : public RhsAutomaton
{
  NO_COPYING(CUI_RhsAutomaton);

public:
  CUI_RhsAutomaton(CUI_Symbol* symbol);
  void close(int sourceIndex0, int sourceIndex1, int destinationIndex);
  //
  //	Standard RhsAutomaton operations
  //
  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher);
  void replace(DagNode* old, Substitution& matcher);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  CUI_Symbol* const topSymbol;
  int source0;
  int source1;
  int destination;
};

#endif
