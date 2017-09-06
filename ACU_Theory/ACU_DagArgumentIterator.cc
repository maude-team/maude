//
//      Implementation for class ACU_DagArgumentIterator.
//
#ifdef __GNUG__
#pragma implementation
#endif
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_RedBlack.hh"
#include "ACU_Theory.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_DagArgumentIterator.hh"

bool
ACU_DagArgumentIterator::valid() const
{
  return multiplicityRemaining > 0;
}
 
DagNode*
ACU_DagArgumentIterator::argument() const
{
  Assert(multiplicityRemaining > 0, cerr << "no args left");
  return (*argArray)[position].dagNode;
}

void
ACU_DagArgumentIterator::next()
{
  Assert(multiplicityRemaining > 0, cerr << "no args left");
  --multiplicityRemaining;
  if (multiplicityRemaining == 0)
    {
      ++position;
      if (position < argArray->length())
        multiplicityRemaining = (*argArray)[position].multiplicity;
    }
}
