//
//      Implementation for class ACU_DagArgumentIterator.
//
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_RedBlack.hh"

//	ACU theory class definitions
#include "ACU_TreeDagArgumentIterator.hh"

bool
ACU_TreeDagArgumentIterator::valid() const
{
  return multiplicityRemaining > 0;
}
 
DagNode*
ACU_TreeDagArgumentIterator::argument() const
{
  Assert(valid(), "no args left");
  return iter.getDagNode();
}

void
ACU_TreeDagArgumentIterator::next()
{
  Assert(valid(), "no args left");
  --multiplicityRemaining;
  if (multiplicityRemaining == 0)
    {
      iter.next();
      if (iter.valid())
        multiplicityRemaining = iter.getMultiplicity();
    }
}
