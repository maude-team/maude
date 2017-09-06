//
//	Implementation for class ConditionFragment.
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
#include "higher.hh"

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
#include "rewriteConditionState.hh"
#include "rewriteConditionFragment.hh"

RewriteConditionFragment::RewriteConditionFragment(Term* lhs, Term* rhs)
  : lhs(lhs),
    rhs(rhs)
{
  lhsIndex = NONE;
  rhsMatcher = 0;
}

RewriteConditionFragment::~RewriteConditionFragment()
{
  lhs->deepSelfDestruct();
  rhs->deepSelfDestruct();
  delete rhsMatcher;
}

void
RewriteConditionFragment::check(VariableInfo& variableInfo, NatSet& boundVariables)
{
  NatSet unboundVariables;

  lhs->normalize(false);
  lhs->indexVariables(variableInfo);
  variableInfo.addConditionVariables(lhs->occursBelow());
  unboundVariables.insert(lhs->occursBelow());

  rhs->normalize(true);
  rhs->indexVariables(variableInfo);
  variableInfo.addConditionVariables(rhs->occursBelow());
      
  unboundVariables.subtract(boundVariables);
  variableInfo.addUnboundVariables(unboundVariables);
  boundVariables.insert(rhs->occursBelow());
}

void
RewriteConditionFragment::preprocess()
{
  lhs->symbol()->fillInSortInfo(lhs);
  rhs->symbol()->fillInSortInfo(rhs);
  Assert(lhs->getComponent() == rhs->getComponent(), cerr << "component clash");
  rhs->analyseCollapses();
}

void
RewriteConditionFragment::compileBuild(VariableInfo& variableInfo, TermBag& availableTerms)
{

  lhsIndex = lhs->compileRhs(builder, variableInfo, availableTerms, true);
  variableInfo.useIndex(lhsIndex);
  rhs->findAvailableTerms(availableTerms, true);
  rhs->determineContextVariables();
  rhs->insertAbstractionVariables(variableInfo);
  variableInfo.endOfFragment();
}

void
RewriteConditionFragment::compileMatch(VariableInfo& variableInfo, NatSet& boundUniquely)
{
  builder.remapIndices(variableInfo);
  lhsIndex = variableInfo.remapIndex(lhsIndex);
  bool subproblemLikely;
  rhsMatcher = rhs->compileLhs(false, variableInfo, boundUniquely, subproblemLikely);
  boundUniquely.insert(rhs->occursBelow());
}

bool
RewriteConditionFragment::solve(bool findFirst,
				RewritingContext& solution,
				stack<ConditionState*>& state)
{
  if (findFirst)
    {
      builder.safeConstruct(solution);
      RewriteConditionState* cs =
	new RewriteConditionState(solution, solution.value(lhsIndex), rhsMatcher);
      if (cs->solve(true, solution))
	{
	  state.push(cs);
	  return true;
	}
      delete cs;
    }
  else
    {
      RewriteConditionState* cs = safeCast(RewriteConditionState*, state.top());
      if (cs->solve(false, solution))
	return true;
      delete cs;
      state.pop();
    }
  return false;
}
