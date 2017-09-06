//
//      Implementation for class SortConstraint.
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
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "termBag.hh"
#include "sortConstraint.hh"

SortConstraint::SortConstraint(int label, Term* lhs, Sort* sort, const Vector<ConditionFragment*>& condition)
  : PreEquation(label, lhs, condition),
    sort(sort)
{
  Assert(sort != 0, cerr << "null sort");
}

void
SortConstraint::check()
{
  NatSet boundVariables;
  PreEquation::check(boundVariables);
  if (!getUnboundVariables().empty())
    {
      IssueWarning(*this << ": variable " <<
                   QUOTE(index2Variable(getUnboundVariables().min())) <<
                   " is used before it is bound in membership axiom:\n" <<
                   this);
      markAsBad();
    }
}

void
SortConstraint::preprocess()
{
  PreEquation::preprocess();
  Assert(getLhs()->getComponent() == sort->component(), cerr << "component clash");
}

void
SortConstraint::compile(bool compileLhs)
{
  if (isCompiled())
    return;
  setCompiled();
  TermBag availableTerms;  // terms available for reuse
  compileBuild(availableTerms, false);
  compileMatch(compileLhs, false);
}

int
SortConstraint::traceBeginTrial(DagNode* subject, RewritingContext& context) const
{
  return context.traceBeginScTrial(subject, this);
}
