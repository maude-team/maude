//
//	Implementation for class PreEquation.
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
#include "termBag.hh"
#include "conditionFragment.hh"
#include "preEquation.hh"

const Vector<ConditionFragment*> PreEquation::noCondition;

PreEquation::PreEquation(int label, Term* lhs, const Vector<ConditionFragment*>& cond)
  : label(label),
    lhs(lhs)
{
  Assert(lhs != 0, "null lhs");
  lhsAutomaton = 0;
  if (cond.length() > 0)  // insure that isNull() is true for empty condition
    condition = cond;  // semi-deep copy
}

PreEquation::~PreEquation()
{
  delete lhsAutomaton;
  lhs->deepSelfDestruct();
  int nrFragments = condition.length();
  for (int i = 0; i < nrFragments; i++)
    delete condition[i];
}

void
PreEquation::check(NatSet& boundVariables)
{
  //
  //	Normalize lhs and fill out variable info
  //
  lhs = lhs->normalize(true);
  lhs->indexVariables(*this);
  boundVariables = lhs->occursBelow();  // deep copy
  int nrFragments = condition.length();
  for (int i = 0; i < nrFragments; i++)
    condition[i]->check(*this, boundVariables);
}

void
PreEquation::preprocess()
{
  lhs->symbol()->fillInSortInfo(lhs);
  /*
  AdvisoryCheck(lhs->getSortIndex() != Sort::ERROR_SORT,
		"lhs pattern " << lhs <<
		" has different operational semantics in Maude 2.0.");
  */
  lhs->analyseCollapses();
  int nrFragments = condition.length();
  for (int i = 0; i < nrFragments; i++)
    condition[i]->preprocess();
}

void
PreEquation::compileBuild(TermBag& availableTerms, bool eagerContext)
{
  lhs->findAvailableTerms(availableTerms, eagerContext, true);
  lhs->determineContextVariables();
  lhs->insertAbstractionVariables(*this);
  int nrFragments = condition.length();
  for (int i = 0; i < nrFragments; i++)
    condition[i]->compileBuild(*this, availableTerms);
}

void
PreEquation::compileMatch(bool compileLhs, bool withExtension)
{
  computeIndexRemapping();
  if (compileLhs)
    {
      NatSet boundUniquely;
      bool subproblemLikely;
      lhsAutomaton = lhs->compileLhs(withExtension, *this, boundUniquely, subproblemLikely);
    }
  NatSet boundUniquely(lhs->occursBelow());
  int nrFragments = condition.length();
  for (int i = 0; i < nrFragments; i++)
    condition[i]->compileMatch(*this, boundUniquely);
}

bool
PreEquation::checkCondition(DagNode* subject,
			    RewritingContext& context,
			    Subproblem* subproblem) const
{
  int trialRef =  UNDEFINED;
  stack<ConditionState*> state;
  bool result = checkCondition(true, subject, context, subproblem, trialRef, state);
  Assert(result || state.empty(), "non-empty condition state stack");
  while (!state.empty())
    {
      delete state.top();
      state.pop();
    }
  return result;
}

bool
PreEquation::checkCondition(bool findFirst,
			    DagNode* subject,
			    RewritingContext& context,
			    Subproblem* subproblem,
			    int& trialRef,
			    stack<ConditionState*>& state) const
{
  Assert(condition.length() != 0, "no condition");
  Assert(!findFirst || state.empty(), "non-empty condition state stack");
  if (findFirst)
    trialRef = UNDEFINED;
  do
    {
      if (RewritingContext::getTraceStatus())
	{
	  if (findFirst)
	    trialRef = traceBeginTrial(subject, context);
	  if (context.traceAbort())
	    {
	      cleanStack(state);
	      return false;  // return false since condition variables may be unbound
	    }
	}
      bool success = solveCondition(findFirst, trialRef, context, state);
      if (RewritingContext::getTraceStatus())
	{
	  if (context.traceAbort())
	    {
	      cleanStack(state);
	      return false;  // return false since condition variables may be unbound
	    }
	  if (trialRef != UNDEFINED)
	    context.traceEndTrial(trialRef, success);
	}
      if (success)
	return true;
      Assert(state.empty(), "non-empty condition state stack");
      findFirst = true;
      trialRef = UNDEFINED;
      //
      //	Condition evaluation may create nodes without doing rewrites so...
      //
      DagNode::okToCollectGarbage();
    }
  while (subproblem != 0 && subproblem->solve(false, context));
  if (RewritingContext::getTraceStatus() && trialRef != UNDEFINED)
    context.traceExhausted(trialRef);
  return false;
}

bool
PreEquation::solveCondition(bool findFirst,
			    int trialRef,
			    RewritingContext& solution,
			    stack<ConditionState*>& state) const
{
  int nrFragments = condition.length();
  int i = findFirst ? 0 : nrFragments - 1;
  for(;;)
    {
      if (RewritingContext::getTraceStatus())
	{
	  if (solution.traceAbort())
	    return false;
	  solution.traceBeginFragment(trialRef, this, i, findFirst);
	}
      findFirst = condition[i]->solve(findFirst, solution, state);
      if (RewritingContext::getTraceStatus())
	{
	  if (solution.traceAbort())
	    return false;
	  solution.traceEndFragment(trialRef, this, i, findFirst);
	}
      if (findFirst)
	{
	  if (++i == nrFragments)
	    break;
	}
      else
	{
	  if (--i < 0)
	    break;
	}
    }
  return findFirst;
}

void
PreEquation::cleanStack(stack<ConditionState*>& conditionStack)
{
  DebugAdvisoryCheck(conditionStack.empty(),
		     "cleaning condition stack because of abort");
  while (!conditionStack.empty())
    {
      delete conditionStack.top();
      conditionStack.pop();
    }
}
