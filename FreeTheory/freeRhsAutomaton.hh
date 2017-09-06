//
//	Class for right hand side automata in the free theory.
//
#ifndef _freeRhsAutomaton_hh_
#define _freeRhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rhsAutomaton.hh"

class FreeRhsAutomaton : public RhsAutomaton
{
public:
  void addFree(Symbol* symbol,
	       int destination,
	       const Vector<int>& sources);
  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher);
  void replace(DagNode* old, Substitution& matcher);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  struct Instruction
    {
      Symbol* symbol;
      int destination;
      Vector<int> sources;
    };

  static void fillOutArgs(int nrArgs,
			  const Instruction& instr,
			  Substitution& matcher,
			  FreeDagNode* d);

  Vector<Instruction> instructions;
};

#endif
