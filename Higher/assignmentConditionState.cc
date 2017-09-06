//
//	Implementation for class AssignmentConditionState.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
//#include "symbol.hh"
//#include "dagNode.hh"
#include "term.hh"
#include "lhsAutomaton.hh"
#include "subproblem.hh"

//	core class definitions
#include "rewritingContext.hh"

//	higher class definitions
#include "assignmentConditionState.hh"

AssignmentConditionState::AssignmentConditionState(RewritingContext& original,
						   LhsAutomaton* matcher,
						   DagNode* rhsInstance)
  : saved(original.nrFragileBindings())
{
  saved.copy(original);
  rhsContext = original.makeSubcontext(rhsInstance, RewritingContext::CONDITION_EVAL);
  rhsContext->reduce();
  original.addInCount(*rhsContext);
  subproblem = 0;
  succeeded = matcher->match(rhsContext->root(), original, subproblem);
}

AssignmentConditionState::~AssignmentConditionState()
{
  delete subproblem;
  delete rhsContext;
}

bool
AssignmentConditionState::solve(bool findFirst, RewritingContext& solution)
{
  if (succeeded)
    {
      if (subproblem == 0)
	{
	  if (findFirst)
	    return true;
	}
      else
	{
	  if (subproblem->solve(findFirst, solution))
	    return true;
	}
    }
  solution.copy(saved);  // restore substitution to pre-match condition
  return false;
}
