//
//      Implementation for class NA_DagNode.
//
#ifdef __GNUG__
#pragma implementation
#endif
 
//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"

//      NA theory class definitions
#include "NA_Symbol.hh"
#include "NA_DagNode.hh"

RawDagArgumentIterator*
NA_DagNode::arguments()
{
  return 0;
}

DagNode*
NA_DagNode::markArguments()
{
  return 0;
}

DagNode*
NA_DagNode::copyEagerUptoReduced2()
{
  return makeClone();
}

void
NA_DagNode::clearCopyPointers2()
{
}

DagNode*
NA_DagNode::copyWithReplacement(int /* argIndex */, DagNode* /* replacement */)
{
  CantHappen("should never be called");
  return 0;
}

DagNode*
NA_DagNode::copyWithReplacement(Vector<RedexPosition>& /* redexStack  */,
				int /* first */,
				int /* last */)
{
  CantHappen("should never be called");
  return 0;
}

void
NA_DagNode::stackArguments(Vector<RedexPosition>& /* stack */,
			   int /* parentIndex */,
			   bool /* respectFrozen */)
{
}
