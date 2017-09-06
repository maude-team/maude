//
//	Implementation for class AssignmentConditionFragment.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
//#include "variable.hh"

//	interface class definitions
//#include "symbol.hh"
//#include "dagNode.hh"
#include "term.hh"
#include "lhsAutomaton.hh"
#include "rhsAutomaton.hh"
#include "subproblem.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "variableInfo.hh"

//	higher class definitions
#include "assignmentConditionState.hh"
#include "assignmentConditionFragment.hh"

AssignmentConditionFragment::AssignmentConditionFragment(Term* lhs, Term* rhs)
  : lhs(lhs),
    rhs(rhs)
{
  lhsMatcher = 0;
  rhsIndex = NONE;
}

AssignmentConditionFragment::~AssignmentConditionFragment()
{
  lhs->deepSelfDestruct();
  rhs->deepSelfDestruct();
  delete lhsMatcher;
}

void
AssignmentConditionFragment::check(VariableInfo& variableInfo, NatSet& boundVariables)
{
  NatSet unboundVariables;

  lhs->normalize(true);
  lhs->indexVariables(variableInfo);
  variableInfo.addConditionVariables(lhs->occursBelow());

  rhs->normalize(false);
  rhs->indexVariables(variableInfo);
  variableInfo.addConditionVariables(rhs->occursBelow());
  unboundVariables.insert(rhs->occursBelow());

  unboundVariables.subtract(boundVariables);
  variableInfo.addUnboundVariables(unboundVariables);
  boundVariables.insert(lhs->occursBelow());
}

void
AssignmentConditionFragment::preprocess()
{
  lhs->symbol()->fillInSortInfo(lhs);
  lhs->analyseCollapses();
  rhs->symbol()->fillInSortInfo(rhs);
  Assert(lhs->getComponent() == rhs->getComponent(), "component clash");
}

void
AssignmentConditionFragment::compileBuild(VariableInfo& variableInfo, TermBag& availableTerms)
{
  rhsIndex = rhs->compileRhs(builder, variableInfo, availableTerms, true);
  variableInfo.useIndex(rhsIndex);
  lhs->findAvailableTerms(availableTerms, true);
  lhs->determineContextVariables();
  lhs->insertAbstractionVariables(variableInfo);
  variableInfo.endOfFragment();
}

void
AssignmentConditionFragment::compileMatch(VariableInfo& variableInfo, NatSet& boundUniquely)
{
  builder.remapIndices(variableInfo);
  rhsIndex = variableInfo.remapIndex(rhsIndex);
  bool subproblemLikely;
  lhsMatcher = lhs->compileLhs(false, variableInfo, boundUniquely, subproblemLikely);
  boundUniquely.insert(lhs->occursBelow());
}

bool
AssignmentConditionFragment::solve(bool findFirst,
				   RewritingContext& solution,
				   stack<ConditionState*>& state)
{
  if (findFirst)
    {
      builder.safeConstruct(solution);
      AssignmentConditionState* cs =
	new AssignmentConditionState(solution, lhsMatcher, solution.value(rhsIndex));
      if (cs->solve(true, solution))
	{
	  state.push(cs);
	  return true;
	}
      delete cs;
    }
  else
    {
      AssignmentConditionState* cs = safeCast(AssignmentConditionState*, state.top());
      if (cs->solve(false, solution))
	return true;
      delete cs;
      state.pop();
    }
  return false;
}
