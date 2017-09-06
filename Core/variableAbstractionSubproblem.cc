//
//      Implementation for class VariableAbstractionSubproblem.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "lhsAutomaton.hh"
 
//      core class definitions
#include "substitution.hh"
#include "rewritingContext.hh"
#include "localBinding.hh"
#include "variableAbstractionSubproblem.hh"

VariableAbstractionSubproblem::VariableAbstractionSubproblem(LhsAutomaton* abstractedPattern,
							     int abstractionVariable,
							     int nrVariables)
  : abstractedPattern(abstractedPattern),
    abstractionVariable(abstractionVariable),
    local(nrVariables)
{
  difference = 0;
  subproblem = 0;
}

VariableAbstractionSubproblem::~VariableAbstractionSubproblem()
{
  delete difference;
  delete subproblem;
}

bool
VariableAbstractionSubproblem::solve(bool findFirst, RewritingContext& solution)
{
  if (findFirst)
    {
      local.copy(solution);
      DagNode* v = solution.value(abstractionVariable);
      Assert(v != 0, "Unbound abstraction variable");
      if (!(abstractedPattern->match(v, local, subproblem, 0)))
	return false;
      difference = local - solution;
      if (difference != 0)
	difference->assert(solution);
      if (subproblem == 0 || subproblem->solve(true, solution))
	return true;
    }
  else
    {
      if (subproblem != 0 && subproblem->solve(false, solution))
	return true;
    }
  if (difference != 0)
    {
      difference->retract(solution);
      delete difference;
      difference = 0;
    }
  delete subproblem;
  subproblem = 0;
  return false;
}
