//
//      Implementation for class EqualitySubproblem.
//
 
//      utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "lhsAutomaton.hh"
#include "extensionInfo.hh"
 
//      core class definitions
#include "rewritingContext.hh"
#include "equalitySubproblem.hh"

bool
EqualitySubproblem::solve(bool findFirst, RewritingContext& solution)
{
  if (!findFirst)
    return false;
  DagNode* rhs = (rhsExtensionInfo != 0) ? rhsExtensionInfo->buildMatchedPortion() :
    solution.value(rhsVariable);
  bool equal = (lhsTerm != 0) ? lhsTerm->equal(rhs) :
    solution.value(lhsVariable)->equal(rhs);
  return equal == checkEqual;
}
