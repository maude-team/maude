//
//      Implementation for class AU_ArgumentIterator.
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
#include "AU_Theory.hh"
 
//      AU theory class definitions
#include "AU_ArgumentIterator.hh"

bool
AU_ArgumentIterator::valid() const
{
  return position < argArray.length();
}

Term*
AU_ArgumentIterator::argument() const
{
  Assert(position < argArray.length(), cerr << "no args left");
  return argArray[position].term;
}

void
AU_ArgumentIterator::next()
{
  Assert(position < argArray.length(), cerr << "no args left");
  ++position;
}
