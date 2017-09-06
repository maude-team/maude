//
//      Implementation for class TermSet
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "term.hh"

//	core class definitions
#include "termSet.hh"

void
TermSet::insert(Term* t)
{
  (void) PointerSet::insert(t, t->getHashValue());
}

int
TermSet::term2Index(Term* t) const
{
  return pointer2Index(t, t->getHashValue());
}

unsigned int
TermSet::hash(void* /* pointer */) const
{
  CantHappen("should never be called");
  return 0;
}

bool
TermSet::isEqual(void* pointer1, void* pointer2) const
{
  Term* t1 = static_cast<Term*>(pointer1);
  Term* t2 = static_cast<Term*>(pointer2);
  return t1->hasEagerContext() == t2->hasEagerContext() && t1->equal(t2);
}
