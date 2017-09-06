//
//	Class for subproblems created by variable abstraction.
//
#ifndef _variableAbstractionSubproblem_hh_
#define _variableAbstractionSubproblem_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "subproblem.hh"

class VariableAbstractionSubproblem : public Subproblem
{
public:
  VariableAbstractionSubproblem(LhsAutomaton* abstractedPattern,
				int abstractionVariable,
				int nrVariables);
  ~VariableAbstractionSubproblem();

  bool solve(bool findFirst, RewritingContext& solution);

private:
  LhsAutomaton* abstractedPattern;
  int abstractionVariable;
  LocalBinding* difference;
  Subproblem* subproblem;
  Substitution local;
};

#endif
