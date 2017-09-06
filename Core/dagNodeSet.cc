//
//      Implementation for class DagNodeSet
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//	core class definitions
#include "dagNodeSet.hh"

void
DagNodeSet::insert(DagNode* d)
{
  (void) PointerSet::insert(d, d->getHashValue());
}

int
DagNodeSet::dagNode2Index(DagNode* d) const
{
  return pointer2Index(d, d->getHashValue());
}

DagNode*
DagNodeSet::index2DagNode(int i) const
{
  return static_cast<DagNode*>(index2Pointer(i));
}

unsigned int
DagNodeSet::hash(void* /* pointer */) const
{
  CantHappen("should never be called");
  return 0;
}

bool
DagNodeSet::isEqual(void* pointer1, void* pointer2) const
{
  DagNode* d1 = static_cast<DagNode*>(pointer1);
  DagNode* d2 = static_cast<DagNode*>(pointer2);
  return d1->equal(d2);
}
