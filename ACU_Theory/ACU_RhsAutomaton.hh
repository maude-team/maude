//
//      Class for right hand side automata in the AC and ACU theories.
//
#ifndef _ACU_RhsAutomaton_hh_
#define _ACU_RhsAutomaton_hh_
#include "rhsAutomaton.hh"

class ACU_RhsAutomaton : public RhsAutomaton
{
  NO_COPYING(ACU_RhsAutomaton);

public:
  ACU_RhsAutomaton(ACU_Symbol* symbol, int nrArgs);
  void addArgument(int index, int multiplicity);
  void close(int destinationIndex);
  //
  //	Standard RhsAutomaton operations.
  //
  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher);
  void replace(DagNode* old, Substitution& matcher);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  struct Argument
    {
      int index;
      int multiplicity;
    };

  void buildArguments(ArgVec<ACU_DagNode::Pair>& argArray, Substitution& matcher) const;
  
  ACU_Symbol* const topSymbol;
  Vector<Argument> arguments;
  int destination;
};

#endif
