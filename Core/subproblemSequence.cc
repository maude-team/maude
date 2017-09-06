//
//	Implementation for subproblem sequences
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	core class definitions
#include "subproblemSequence.hh"

SubproblemSequence::~SubproblemSequence()
{
  
  for (int i = sequence.length() - 1; i >= 0; i--)
    delete sequence[i];
}

bool
SubproblemSequence::solve(bool findFirst, RewritingContext& solution)
{
  int len = sequence.length();
  int i = findFirst ? 0 : len - 1;
  for(;;)
    {
      findFirst = sequence[i]->solve(findFirst, solution);
      if (findFirst)
	{
	  if (++i == len)
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
