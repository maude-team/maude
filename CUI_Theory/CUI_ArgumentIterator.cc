//
//      Implementation for class CUI_ArgumentIterator.
//
#ifdef __GNUG__
#pragma implementation
#endif
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"

//      CUI theory class definitions
#include "CUI_ArgumentIterator.hh"

bool
CUI_ArgumentIterator::valid() const
{
  return position < 2;
}

Term*
CUI_ArgumentIterator::argument() const
{
  Assert(position < 2, cerr << "no args left");
  return argArray[position];
}

void
CUI_ArgumentIterator::next()
{
  Assert(position < 2, cerr << "no args left");
  ++position;
}
