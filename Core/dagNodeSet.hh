//
//      Class for set of pointers to dag nodes.
//
#ifndef _dagNodeSet_hh_
#define _dagNodeSet_hh_
#include "pointerSet.hh"

class DagNodeSet : private PointerSet
{
public:
  void insert(DagNode* d);
  int dagNode2Index(DagNode* d) const;
  PointerSet::cardinality;
  PointerSet::makeEmpty;
  DagNode* index2DagNode(int i) const;

private:
  unsigned int hash(void* pointer) const;
  bool isEqual(void* pointer1, void* pointer2) const;
};

#endif
