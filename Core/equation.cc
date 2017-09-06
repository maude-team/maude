//
//	Implementation for class Equation.
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
#include "rhsAutomaton.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "termBag.hh"
#include "equation.hh"

Equation::Equation(int label,
		   Term* lhs,
		   Term* rhs,
		   bool owise,
		   const Vector<ConditionFragment*>& condition)
  : PreEquation(label, lhs, condition),
    rhs(rhs)
{
  if (owise)
    setFlags(OWISE);
  Assert(rhs != 0, cerr << "null rhs");
}

Equation::~Equation()
{
  rhs->deepSelfDestruct();
}

void
Equation::check()
{
  NatSet boundVariables;
  PreEquation::check(boundVariables);
  rhs = rhs->normalize(false);
  rhs->indexVariables(*this);

  NatSet unboundVariables(rhs->occursBelow());
  unboundVariables.subtract(boundVariables);
  addUnboundVariables(unboundVariables);
  if (!getUnboundVariables().empty())
    {
      IssueWarning(*this << ": variable " <<
		   QUOTE(index2Variable(getUnboundVariables().min())) <<
		   " is used before it is bound in equation:\n" <<
		   this);
      markAsBad();
    }
}

void
Equation::preprocess()
{
  PreEquation::preprocess();
  rhs->symbol()->fillInSortInfo(rhs);
  Assert(getLhs()->getComponent() == rhs->getComponent(),
	 cerr << "connected component clash");
}

void
Equation::compile(bool compileLhs)
{
  if (isCompiled())
    return;
  setCompiled();
  TermBag availableTerms;  // terms available for reuse
  compileBuild(availableTerms, true);
  rhs->compileTopRhs(builder, *this, availableTerms);
  compileMatch(compileLhs, true);
  //builder.dump(cerr, *this);
  builder.remapIndices(*this);
  //builder.dump(cerr, *this);

  fast = hasCondition() ? DEFAULT : getNrProtectedVariables();  // HACK
}

int
Equation::traceBeginTrial(DagNode* subject, RewritingContext& context) const
{
  return context.traceBeginEqTrial(subject, this);
}
