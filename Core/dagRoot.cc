//
//      Implementation for class DagRoot.
//
#ifdef __GNUG__
#pragma implementation
#endif

#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      core class definitions
#include "dagRoot.hh"

void
DagRoot::markReachableNodes()
{
  nodePointer->mark();
}
