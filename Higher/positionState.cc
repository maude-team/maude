//
//	Implementation for class PositionState.
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
#include "extensionInfo.hh"

//	core class definitions
#include "positionState.hh"

PositionState::PositionState(DagNode* top, int flags, int minDepth, int maxDepth)
  : flags(flags),
    minDepth(minDepth),
    maxDepth(maxDepth)
{
  positionQueue.append(RedexPosition(top, UNDEFINED, UNDEFINED));
  depth.append(0);
  extensionInfo = 0;
  nextToReturn = -1;
  nextToExplore = -1;
}

PositionState::~PositionState()
{
  delete extensionInfo;
}

local_inline bool
PositionState::exploreNextPosition()
{
  int finish = positionQueue.length();
  for(;;)
    {
      if (++nextToExplore >= finish)
	return false;
      int ourDepth = depth[nextToExplore];
      if (ourDepth >= maxDepth)
	return false;
      DagNode* d = positionQueue[nextToExplore].node();
      d->stackArguments(positionQueue, nextToExplore, flags & RESPECT_FROZEN);
      int newFinish = positionQueue.length();
      if (finish < newFinish)
	{
	  ++ourDepth;
	  depth.expandTo(newFinish);
	  for (; finish < newFinish; finish++)
	    depth[finish] = ourDepth;
	  break;
	}
    }
  return true;
}

bool
PositionState::findNextPosition()
{
  do
    {
      if (++nextToReturn >= positionQueue.length() && !exploreNextPosition())
	return false;
    }
  while (depth[nextToReturn] < minDepth);
  if (maxDepth >= 0)
    {
      delete extensionInfo;
      extensionInfo = getDagNode()->makeExtensionInfo();
    }
  return true;
}

DagNode*
PositionState::rebuildDag(DagNode* replacement) const
{
  if (extensionInfo != 0 && !(extensionInfo->matchedWhole()))
    replacement = getDagNode()->partialConstruct(replacement, extensionInfo);
  int argIndex = positionQueue[nextToReturn].argIndex();
  for (int i = positionQueue[nextToReturn].parentIndex(); i != UNDEFINED;)
    {
      const RedexPosition& rp = positionQueue[i];
      replacement = rp.node()->copyWithReplacement(argIndex, replacement);
      argIndex = rp.argIndex();
      i = rp.parentIndex();
    }
  return replacement;
}
