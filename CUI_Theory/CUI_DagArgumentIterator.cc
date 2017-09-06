//
//      Implementation for class CUI_DagArgumentIterator.
//

//	utility stuff
#include "macros.hh"
 
//      forward declarations
#include "interface.hh"

//	CUI theory class definitions
#include "CUI_DagArgumentIterator.hh"

bool
CUI_DagArgumentIterator::valid() const
{
  return nrRemaining > 0;
}
 
DagNode*
CUI_DagArgumentIterator::argument() const
{
  Assert(nrRemaining > 0, "no args left");
  return *position;
}

void
CUI_DagArgumentIterator::next()
{
  Assert(nrRemaining > 0, "no args left");
  ++position;
  --nrRemaining;
}
