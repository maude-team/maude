//
//	Implementation for class Substitution
//

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

LocalBinding*
Substitution::operator-(const Substitution& original) const
{
  int nrDiff = 0;
  Vector<DagNode*>::const_iterator b = values.begin();
  Vector<DagNode*>::const_iterator e = b + copySize;

  Vector<DagNode*>::const_iterator j = original.values.begin();
  for (Vector<DagNode*>::const_iterator i = b; i != e; ++i, ++j)
    {
      Assert(*j == 0 || *i == *j,
	     "substitution inconsistancy at index " << i - b);
      if (*i != *j)
	++nrDiff;
    }

  if (nrDiff == 0)
    return 0;
  LocalBinding* result = new LocalBinding(nrDiff);

  j = original.values.begin();
  for (Vector<DagNode*>::const_iterator i = b; i != e; ++i, ++j)
    {
      DagNode* d = *i;
      if (d != *j)
	result->addBinding(i - b, d);
    }
  return result;
}
