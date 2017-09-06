//
//      Implementation for class FreeDagArgumentIterator
//

#include "macros.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"

//	interface class definitions
#include "rawDagArgumentIterator.hh"

//	free theory class definitions
#include "freeDagArgumentIterator.hh"

bool
FreeDagArgumentIterator::valid() const
{
  return nrRemaining > 0;
}

DagNode*
FreeDagArgumentIterator::argument() const
{
  Assert(nrRemaining > 0, "no args left");
  return *position;
}

void
FreeDagArgumentIterator::next()
{
  Assert(nrRemaining > 0, "no args left");
  ++position;
  --nrRemaining;
}
