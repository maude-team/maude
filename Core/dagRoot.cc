//
//      Implementation for class DagRoot.
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

//      core class definitions
#include "dagRoot.hh"

void
DagRoot::markReachableNodes()
{
  nodePointer->mark();
}
