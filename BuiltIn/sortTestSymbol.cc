//
//      Implementation for class SortTestSymbol.
//
#ifdef __GNUG__
#pragma implementation
#endif
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"
 
//      core class definitions
#include "argumentIterator.hh"
#include "rewritingContext.hh"

//      free theory class definitions
#include "freeDagNode.hh"
 
//      built in class definitions
#include "sortTestSymbol.hh"

const Vector<int>&
SortTestSymbol::makeLazyStrategy()
{
  static Vector<int> lazyStrategy;
  if (lazyStrategy.length() == 0)
    lazyStrategy.append(0);
  return lazyStrategy;
}

SortTestSymbol::SortTestSymbol(int id,
			       Sort* testSort,
			       FreeSymbol* leq,
			       FreeSymbol* nleq,
			       bool eager)
  : FreeSymbol(id, 1, eager ? standard : makeLazyStrategy())
{
  cmpSort = testSort;
  leqResult = leq;
  notLeqResult = nleq;
  eagerFlag = eager;
}

bool
SortTestSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), cerr << "Bad symbol");
  DagNode *t = static_cast<FreeDagNode*>(subject)->getArgument(0);
  if (eagerFlag)
    t->reduce(context);
  else
    t->computeTrueSort(context);
  t->symbol()->constrainToExactSort(t, context);  // HACK
  FreeSymbol* result = (t->leq(cmpSort)) ? leqResult : notLeqResult;
  bool trace = RewritingContext::getTraceStatus();
  if (trace)
    {
      context.tracePreEqRewrite(subject, 0, RewritingContext::BUILTIN);
      if (context.traceAbort())
	return false;
    }
  (void) new(subject) FreeDagNode(result);
  context.incrementEqCount();
  if (trace)
    context.tracePostEqRewrite(subject);
  return true;
}

bool
SortTestSymbol::acceptEquation(Equation* /* equation */)
{
  return false;
}

void
SortTestSymbol::compileEquations()
{
}
