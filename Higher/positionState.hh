//
//	Class for storing position and extension information during a search.
//
#ifndef _positionState_hh_
#define _positionState_hh_
#include <stack>
#include "redexPosition.hh"

class PositionState
{
  NO_COPYING(PositionState);

public:
  enum Flags
  {
    RESPECT_FROZEN = 1
  };

  PositionState(DagNode* top, int flags = 0, int minDepth = 0, int maxDepth = -1);
  ~PositionState();

  bool findNextPosition();  // should this be protected?
  DagNode* getDagNode() const;
  ExtensionInfo* getExtensionInfo() const;
  DagNode* rebuildDag(DagNode* replacement) const;
  int getFlags() const;

private:
  bool exploreNextPosition();

  const int flags;
  const int minDepth;
  const int maxDepth;
  ExtensionInfo* extensionInfo;
  //
  //	For breathfirst traversal over positions.
  //
  Vector<RedexPosition> positionQueue;
  Vector<int> depth;
  int nextToExplore;
  int nextToReturn;
};

inline int
PositionState::getFlags() const
{
  return flags;
}

inline DagNode*
PositionState::getDagNode() const
{
  Assert(nextToReturn >= 0, "findNextPosition() not called");
  return positionQueue[nextToReturn].node();
}

inline ExtensionInfo* 
PositionState::getExtensionInfo() const
{
  Assert(nextToReturn >= 0, "findNextPosition() not called");
  return extensionInfo;
}

#endif
