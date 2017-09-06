//
//      Class for right hand side automata in the the A, AUl, AUr and AU theories.
//
#ifndef _AU_RhsAutomaton_hh_
#define _AU_RhsAutomaton_hh_
#include "rhsAutomaton.hh"

class AU_RhsAutomaton : public RhsAutomaton
{
  NO_COPYING(AU_RhsAutomaton);

public:
  AU_RhsAutomaton(AU_Symbol* symbol, int nrArgs);

  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher);
  void replace(DagNode* old, Substitution& matcher);
  void addArgument(int index);
  void close(int destinationIndex);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  void buildArguments(ArgVec<DagNode*>& argArray, Substitution& matcher) const;

  AU_Symbol* const topSymbol;
  Vector<int> arguments;
  int destination;
};

inline void
AU_RhsAutomaton::addArgument(int index)
{
  arguments.append(index);
}

inline void
AU_RhsAutomaton::close(int destinationIndex)
{
  destination = destinationIndex;
}

#endif
