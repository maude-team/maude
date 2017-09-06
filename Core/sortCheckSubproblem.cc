//
//      Implementation for class SortCheckSubproblem
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      core class definitions
#include "sortCheckSubproblem.hh"

SortCheckSubproblem::SortCheckSubproblem(DagNode* subject, const Sort* sort) :
  subject(subject), sort(sort)
{
  result = UNDEFINED;
}

bool
SortCheckSubproblem::solve(bool findFirst, RewritingContext& solution)
{
  if (!findFirst)
    return false;	// only ever one way to solve; otherwise infinite loop
  if (result == UNDEFINED)
    result = subject->checkSort(sort, solution);
  return result;
}

