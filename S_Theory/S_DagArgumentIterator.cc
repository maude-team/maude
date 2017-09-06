//
//      Implementation for class S_DagArgumentIterator.
//
 
//	utility stuff
#include "macros.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "S_Theory.hh"

//	S theory class definitions
#include "S_DagArgumentIterator.hh"

bool
S_DagArgumentIterator::valid() const
{
  return arg != 0;
}
 
DagNode*
S_DagArgumentIterator::argument() const
{
  Assert(valid(), "no args left");
  return arg;
}

void
S_DagArgumentIterator::next()
{
  Assert(valid(), "no args left");
  arg = 0;
}
