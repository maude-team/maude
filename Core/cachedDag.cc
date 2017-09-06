//
//      Implementation for class CachedDag.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
 
//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//      core class definitions
#include "cachedDag.hh"

void
CachedDag::prepare()
{
  //
  //        Mark eager paths in preparation for term to dag conversion.
  //
  NatSet emptySet;
  Vector<int> emptyVector;
  term->markEagerArguments(0, emptySet, emptyVector);
}
