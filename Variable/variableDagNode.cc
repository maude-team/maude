//
//      Implementation for class VariableDagNode
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

//	variable class definitions
#include "variableDagNode.hh"

RawDagArgumentIterator*
VariableDagNode::arguments()
{
  return 0;
}

size_t
VariableDagNode::getHashValue()
{
  return hash(symbol()->getHashValue(), id());
}

int
VariableDagNode::compareArguments(const DagNode* other) const
{
  return id() - safeCast(const VariableDagNode*, other)->id();
}

DagNode*
VariableDagNode::markArguments()
{
  return 0;
}

DagNode*
VariableDagNode::copyEagerUptoReduced2()
{
  return new VariableDagNode(symbol(), id());
}

void
VariableDagNode::clearCopyPointers2()
{
}

void
VariableDagNode::overwriteWithClone(DagNode* old)
{
  
  VariableDagNode* d = new(old) VariableDagNode(symbol(), id());
  d->copySetRewritingFlags(this);
  d->setSortIndex(getSortIndex());
}

DagNode*
VariableDagNode::makeClone()
{
  VariableDagNode* d = new VariableDagNode(symbol(), id());
  d->copySetRewritingFlags(this);
  d->setSortIndex(getSortIndex());
  return d;
}

DagNode*
VariableDagNode::copyWithReplacement(int /* argIndex */, DagNode* /* replacement */)
{
  CantHappen("should never be called");
  return 0;
}

DagNode*
VariableDagNode::copyWithReplacement(Vector<RedexPosition>& /* redexStack  */,
				     int /* first */,
				     int /* last */)
{
  CantHappen("should never be called");
  return 0;
}

void
VariableDagNode::stackArguments(Vector<RedexPosition>& /* stack */,
				int /* parentIndex */,
				bool /* respectFrozen */)
{
}
