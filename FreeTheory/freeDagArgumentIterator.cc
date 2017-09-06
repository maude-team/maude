//
//      Implementation for class FreeDagArgumentIterator
//
#ifdef __GNUG__
#pragma implementation
#endif

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
  Assert(nrRemaining > 0, cerr << "no args left");
  return *position;
}

void
FreeDagArgumentIterator::next()
{
  Assert(nrRemaining > 0, cerr << "no args left");
  ++position;
  --nrRemaining;
}
