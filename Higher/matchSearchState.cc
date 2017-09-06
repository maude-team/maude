//
//	Implementation for class MatchSearchState.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "pattern.hh"
#include "matchSearchState.hh"

MatchSearchState::MatchSearchState(RewritingContext* context,
				   Pattern* pattern,
				   int flags,
				   int minDepth,
				   int maxDepth)
  : SearchState(context, flags, minDepth, maxDepth),
    pattern(pattern)
{
  firstMatch = true;
}

MatchSearchState::~MatchSearchState()
{
  //
  //	Delete stuff entrusted to us by our creator.
  //
  if (getFlags() & GC_PATTERN)
    delete pattern;
}

bool
MatchSearchState::findNextMatch()
{
  if (firstMatch)
    firstMatch = false;
  else
    {
      if (findNextSolution())
	return true;
    }

  while (findNextPosition())
    {
      if (findFirstSolution(pattern, pattern->getLhsAutomaton()))
	return true;
    }
  return false;
}
