//
//      Implementation for class S_ArgumentIterator.
//

//	utility stuff
#include "macros.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "S_Theory.hh"

//      S theory class definitions
#include "S_ArgumentIterator.hh"

bool
S_ArgumentIterator::valid() const
{
  return arg != 0;
}
 
Term*
S_ArgumentIterator::argument() const
{
  Assert(valid(), "no args left");
  return arg;
}

void
S_ArgumentIterator::next()
{
  Assert(valid(), "no args left");
  arg = 0;
}
