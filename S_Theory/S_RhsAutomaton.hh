//
//      Class for right hand side automata for S theory.
//
#ifndef _S_RhsAutomaton_hh_
#define _S_RhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include <gmpxx.h>
#include "rhsAutomaton.hh"

class S_RhsAutomaton : public RhsAutomaton
{
  NO_COPYING(S_RhsAutomaton);

public:
  S_RhsAutomaton(S_Symbol* symbol, mpz_class& number, int source, int destination);
  //
  //    Functions required by theory interface.
  //
  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher);
  void replace(DagNode* old, Substitution& matcher);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  S_Symbol* const topSymbol;
  const mpz_class number;
  int source;
  int destination;
};

#endif
