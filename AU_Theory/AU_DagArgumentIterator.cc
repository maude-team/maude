//
//      Implementation for class AU_DagArgumentIterator.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "AU_Theory.hh"

//	A theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"
#include "AU_DagArgumentIterator.hh"

bool
AU_DagArgumentIterator::valid() const
{
  return position < argArray.length();
}
 
DagNode*
AU_DagArgumentIterator::argument() const
{
  Assert(position < argArray.length(), "no args left");
  return argArray[position];
}

void
AU_DagArgumentIterator::next()
{
  Assert(position < argArray.length(), "no args left");
  ++position;
}
