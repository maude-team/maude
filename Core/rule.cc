//
//	Implementation for class Rule.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"

//	interface class definitions
//#include "symbol.hh"
//#include "dagNode.hh"
#include "term.hh"
#include "extensionInfo.hh"
#include "lhsAutomaton.hh"
#include "rhsAutomaton.hh"
#include "subproblem.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "termBag.hh"
#include "rule.hh"

Rule::Rule(int label, Term* lhs, Term* rhs, const Vector<ConditionFragment*>& condition)
  : PreEquation(label, lhs, condition),
    rhs(rhs)
{
  Assert(rhs != 0, "null rhs");
  nonExtLhsAutomaton = 0;
  extLhsAutomaton = 0;
}

Rule::~Rule()
{
  delete nonExtLhsAutomaton;
  delete extLhsAutomaton;
  rhs->deepSelfDestruct();
}

void
Rule::check()
{
  NatSet boundVariables;
  PreEquation::check(boundVariables);
  rhs = rhs->normalize(false);
  rhs->indexVariables(*this);
  NatSet unboundVariables(rhs->occursBelow());
  unboundVariables.subtract(boundVariables);
  addUnboundVariables(unboundVariables);
}

void
Rule::preprocess()
{
  PreEquation::preprocess();
  rhs->symbol()->fillInSortInfo(rhs);
  Assert(getLhs()->getComponent() == rhs->getComponent(), "connected component clash");
}

LhsAutomaton*
Rule::getNonExtLhsAutomaton()
{
  if (nonExtLhsAutomaton == 0)
    {
      NatSet boundUniquely;
      bool subproblemLikely;
      nonExtLhsAutomaton = getLhs()->compileLhs(false, *this, boundUniquely, subproblemLikely);
    }
  return nonExtLhsAutomaton;
}

LhsAutomaton*
Rule::getExtLhsAutomaton()
{
  if (extLhsAutomaton == 0)
    {
      NatSet boundUniquely;
      bool subproblemLikely;
      extLhsAutomaton = getLhs()->compileLhs(true, *this, boundUniquely, subproblemLikely);
    }
  return extLhsAutomaton;
}

void
Rule::compile(bool compileLhs)
{
  if (isCompiled())
    return;
  setCompiled();
  TermBag availableTerms;  // terms available for reuse
  compileBuild(availableTerms, false);
  rhs->compileTopRhs(builder, *this, availableTerms);
  compileMatch(compileLhs, true);
  builder.remapIndices(*this);
  //
  //	Make all variables in a rules lhs into condition variables so that
  //	if we compile lhs again in getNonExtLhsAutomaton() or getExtLhsAutomaton()
  //	it will be compiled to generate all matchers rather than just those
  //	that differ on variables in the condition.
  //
  addConditionVariables(getLhs()->occursBelow());
}

int
Rule::traceBeginTrial(DagNode* subject, RewritingContext& context) const
{
  return context.traceBeginRuleTrial(subject, this);
}
