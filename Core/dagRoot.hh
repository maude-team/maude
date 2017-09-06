//
//      Class for smart pointers that form DAG roots for garbage collection.
//	They have zero impact on performance of GC when null.
//
#ifndef _dagRoot_hh_
#define _dagRoot_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rootContainer.hh"

class DagRoot : private RootContainer
{
public:
  DagRoot(DagNode* initial = 0);
  ~DagRoot();
  DagNode* getNode() const;
  void setNode(DagNode* node);
 
private:
  void markReachableNodes();

  DagNode* nodePointer;
};

inline
DagRoot::DagRoot(DagNode* initial)
{
  nodePointer = initial;
  if (initial != 0)
    link();
}

inline
DagRoot::~DagRoot()
{
  if (nodePointer != 0)
    unlink();
}

inline DagNode*
DagRoot::getNode() const
{
  return nodePointer;
}

inline void
DagRoot::setNode(DagNode* node)
{
  if (node == 0)
    {
      if (nodePointer != 0)
	unlink();
    }
  else
    {
      if (nodePointer == 0)
	link();
    }
  nodePointer = node;
}

#endif
