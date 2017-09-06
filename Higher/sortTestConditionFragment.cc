//
//	Implementation for class SortTestConditionFragment.
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
//#include "conditionState.hh"
#include "sortTestConditionFragment.hh"

SortTestConditionFragment::SortTestConditionFragment(Term* lhs, Sort* sort)
  : lhs(lhs),
    sort(sort)
{
  lhsIndex = NONE;
}

SortTestConditionFragment::~SortTestConditionFragment()
{
  lhs->deepSelfDestruct();
}

void
SortTestConditionFragment::check(VariableInfo& variableInfo, NatSet& boundVariables)
{
  NatSet unboundVariables;

  lhs->normalize(false);
  lhs->indexVariables(variableInfo);
  variableInfo.addConditionVariables(lhs->occursBelow());
  unboundVariables.insert(lhs->occursBelow());
  unboundVariables.subtract(boundVariables);
  variableInfo.addUnboundVariables(unboundVariables);
}

void
SortTestConditionFragment::preprocess()
{
  lhs->symbol()->fillInSortInfo(lhs);
  Assert(lhs->getComponent() == sort->component(), "component clash");
}

void
SortTestConditionFragment::compileBuild(VariableInfo& variableInfo, TermBag& availableTerms)
{
  lhsIndex = lhs->compileRhs(builder, variableInfo, availableTerms, true);
  variableInfo.useIndex(lhsIndex);
  variableInfo.endOfFragment();
}

void
SortTestConditionFragment::compileMatch(VariableInfo& variableInfo, NatSet& boundUniquely)
{
  builder.remapIndices(variableInfo);
  lhsIndex = variableInfo.remapIndex(lhsIndex);
}

bool
SortTestConditionFragment::solve(bool findFirst,
				 RewritingContext& solution,
				 stack<ConditionState*>& state)
{
  if (!findFirst)
    return false;
  builder.safeConstruct(solution);
  RewritingContext* lhsContext =
    solution.makeSubcontext(solution.value(lhsIndex), RewritingContext::CONDITION_EVAL);
  lhsContext->reduce();
  solution.addInCount(*lhsContext);
  //
  //	Check for low enough sort axioms.
  //
  bool success = lhsContext->root()->leq(sort);
  delete lhsContext;
  return success;
}
