//
//      Implementation for class ACU_ArgumentIterator.
//
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_Theory.hh"

//      ACU theory class definitions
#include "ACU_Term.hh"
#include "ACU_ArgumentIterator.hh"

bool
ACU_ArgumentIterator::valid() const
{
  return multiplicityRemaining > 0;
}

Term*
ACU_ArgumentIterator::argument() const
{
  Assert(multiplicityRemaining > 0, "no args left");
  return (*argArray)[position].term;
}

void
ACU_ArgumentIterator::next()
{
  Assert(multiplicityRemaining > 0, "no args left");
  --multiplicityRemaining;
  if (multiplicityRemaining == 0)
    {
      ++position;
      if (position < argArray->length())
	multiplicityRemaining = (*argArray)[position].multiplicity;
    }
}
