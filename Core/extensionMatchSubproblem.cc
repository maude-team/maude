//
//      Implementation for class ExtensionMatchSubproblem.
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
#include "lhsAutomaton.hh"
#include "extensionInfo.hh"
 
//      core class definitions
#include "rewritingContext.hh"
#include "localBinding.hh"
#include "extensionMatchSubproblem.hh"

ExtensionMatchSubproblem::ExtensionMatchSubproblem(LhsAutomaton* pattern,
						   ExtensionInfo* extensionInfo,
						   int nrVariables)
  : pattern(pattern),
    extensionInfo(extensionInfo),
    local(nrVariables)
{
  difference = 0;
  subproblem = 0;
}

ExtensionMatchSubproblem::~ExtensionMatchSubproblem()
{
  delete difference;
  delete subproblem;
}

bool
ExtensionMatchSubproblem::solve(bool findFirst, RewritingContext& solution)
{
  if (findFirst)
    {
      DagNode* d = extensionInfo->buildMatchedPortion();
      if (extensionInfo->matchedWhole())
	d = d->makeClone();  // match may assign whole subject to a variable
      matchedPortion.setNode(d);  // protection from garbage collection
      local.copy(solution);
      if (!(pattern->match(d, local, subproblem)))
	return false;
      difference = local - solution;
      if (difference != 0)
	difference->assert(solution);
      if (subproblem == 0 || subproblem->solve(true, solution))
	return true;
    }
  else
    {
      if (subproblem != 0 && subproblem->solve(false, solution))
	return true;
    }
  if (difference != 0)
    {
      difference->retract(solution);
      delete difference;
      difference = 0;
    }
  delete subproblem;
  subproblem = 0;
  return false;
}
