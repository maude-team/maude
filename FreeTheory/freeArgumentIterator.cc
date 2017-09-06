//
//	Implementation for class FreeArgumentIterator
//

#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"

//	interface class definitions
#include "rawArgumentIterator.hh"

//	free theory class definitions
#include "freeArgumentIterator.hh"

bool
FreeArgumentIterator::valid() const
{
  return position < argArray->length();
}
  
Term*
FreeArgumentIterator::argument() const
{
  Assert(position < argArray->length(), "no args left");
  return (*argArray)[position];
}

void
FreeArgumentIterator::next()
{
  Assert(position < argArray->length(), "no args left");
  ++position;
}
