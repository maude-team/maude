//
//	Implementation for class Substitution
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      core class definitions
#include "substitution.hh"
#include "localBinding.hh"

int Substitution::allocateSize = 1;

Substitution::Substitution(const Substitution& original)
  : values(original.copySize)
{
  copySize = original.copySize;
  for (int i = 0; i < copySize; i++)
    values[i] = original.values[i];
}

LocalBinding*
Substitution::operator-(const Substitution& original) const
{
  int nrDiff = 0;
  for (int i = 0; i < copySize; i++)
    {
      if (original.values[i] == 0)
	{
	  if (values[i] != 0)
	    ++nrDiff;
	}
      else
	Assert(values[i] != 0, cerr << "substitution inconsistancy at index " << i);
    }
  if (nrDiff == 0)
    return 0;
  LocalBinding* result = new LocalBinding(nrDiff);
  for (int i = 0; i < copySize; i++)
    {
      if (original.values[i] == 0)
	{
	  DagNode* d = values[i];
	  if (d != 0)
	    result->addBinding(i, d);
	}
    }
  return result;
}
