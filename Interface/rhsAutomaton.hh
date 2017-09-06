//
//      Abstract base class for right hand side automata.
//
#ifndef _rhsAutomaton_hh_
#define _rhsAutomaton_hh_

class RhsAutomaton
{
public:
  virtual ~RhsAutomaton() {}

  virtual void remapIndices(VariableInfo& variableInfo) = 0;
  virtual DagNode* construct(Substitution& matcher) = 0;
  virtual void replace(DagNode* old, Substitution& matcher) = 0;

#ifdef DUMP
  virtual void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel = 0) = 0;
#endif

};

#endif
