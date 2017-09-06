//
//      Implementation for class AU_DequeDagArgumentIterator.
//
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "AU_Persistent.hh"

//	AU theory class definitions
#include "AU_DequeDagArgumentIterator.hh"

bool
AU_DequeDagArgumentIterator::valid() const
{
  return iter.valid();
}
 
DagNode*
AU_DequeDagArgumentIterator::argument() const
{
  Assert(valid(), "no args left");
  return iter.getDagNode();
}

void
AU_DequeDagArgumentIterator::next()
{
  Assert(valid(), "no args left");
  iter.next();
}
