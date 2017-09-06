//
//      Implementation for class FloatDagNode.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      built in class definitions
#include "floatSymbol.hh"
#include "floatDagNode.hh"

FloatDagNode::FloatDagNode(FloatSymbol* symbol, double value)
  : NA_DagNode(symbol),
    value((value == 0.0) ? 0.0 : value)  // don't allow IEEE-754 -0.0
{
}

size_t
FloatDagNode::getHashValue()
{
  Int64 bitPattern = *(reinterpret_cast<const Int64*>(&value));
  return hash(symbol()->getHashValue(), bitPattern ^ (bitPattern >> 32));
}

int
FloatDagNode::compareArguments(const DagNode* other) const
{
  double otherValue = static_cast<const FloatDagNode*>(other)->value;
  return (value == otherValue) ? 0 : ((value > otherValue) ? 1 : -1);
}
 
void
FloatDagNode::overwriteWithClone(DagNode* old)
{
  FloatDagNode* d = new(old) FloatDagNode(safeCast(FloatSymbol*, symbol()), value);
  d->copySetRewritingFlags(this);
  d->setSortIndex(getSortIndex());
}

DagNode*
FloatDagNode::makeClone()
{
  FloatDagNode* d = new FloatDagNode(safeCast(FloatSymbol*, symbol()), value);
  d->copySetRewritingFlags(this);
  d->setSortIndex(getSortIndex());
  return d;
}
