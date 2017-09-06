//
//	Implementation for class EqualityConditionFragment.
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

//	higher class definitions
#include "equalityConditionFragment.hh"

EqualityConditionFragment::EqualityConditionFragment(Term* lhs, Term* rhs)
  : lhs(lhs),
    rhs(rhs)
{
  lhsIndex = NONE;
  rhsIndex = NONE;
}

EqualityConditionFragment::~EqualityConditionFragment()
{
  lhs->deepSelfDestruct();
  rhs->deepSelfDestruct();
}

void
EqualityConditionFragment::check(VariableInfo& variableInfo, NatSet& boundVariables)
{
  NatSet unboundVariables;

  lhs->normalize(false);
  lhs->indexVariables(variableInfo);
  variableInfo.addConditionVariables(lhs->occursBelow());
  unboundVariables.insert(lhs->occursBelow());

  rhs->normalize(false);
  rhs->indexVariables(variableInfo);
  variableInfo.addConditionVariables(rhs->occursBelow());
  unboundVariables.insert(rhs->occursBelow());

  unboundVariables.subtract(boundVariables);
  variableInfo.addUnboundVariables(unboundVariables);
}

void
EqualityConditionFragment::preprocess()
{
  lhs->symbol()->fillInSortInfo(lhs);
  rhs->symbol()->fillInSortInfo(rhs);
  Assert(lhs->getComponent() == rhs->getComponent(), cerr << "component clash");
}

void
EqualityConditionFragment::compileBuild(VariableInfo& variableInfo, TermBag& availableTerms)
{
  lhsIndex = lhs->compileRhs(builder, variableInfo, availableTerms, true);
  rhsIndex = rhs->compileRhs(builder, variableInfo, availableTerms, true);
  variableInfo.useIndex(lhsIndex);
  variableInfo.useIndex(rhsIndex);
  variableInfo.endOfFragment();
}

void
EqualityConditionFragment::compileMatch(VariableInfo& variableInfo, NatSet& boundUniquely)
{
  builder.remapIndices(variableInfo);
  lhsIndex = variableInfo.remapIndex(lhsIndex);
  rhsIndex = variableInfo.remapIndex(rhsIndex);
}

bool
EqualityConditionFragment::solve(bool findFirst,
				 RewritingContext& solution,
				 stack<ConditionState*>& state)
{
  if (!findFirst)
    return false;
  builder.safeConstruct(solution);
  RewritingContext* lhsContext =
    solution.makeSubcontext(solution.value(lhsIndex), RewritingContext::CONDITION_EVAL);
  RewritingContext* rhsContext =
    solution.makeSubcontext(solution.value(rhsIndex), RewritingContext::CONDITION_EVAL);
  lhsContext->reduce();
  solution.addInCount(*lhsContext);
  rhsContext->reduce();
  solution.addInCount(*rhsContext);
  //
  //	Check for equality modulo axioms.
  //
  bool success = lhsContext->root()->equal(rhsContext->root());
  delete lhsContext;
  delete rhsContext;
  return success;
}
