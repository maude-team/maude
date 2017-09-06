//
//	Class for DAG nodes that are variables.
//
#ifndef _variableDagNode_hh_
#define _variableDagNode_hh_
#include "dagNode.hh"
#include "namedEntity.hh"

class VariableDagNode : public DagNode, public NamedEntity
{
  NO_COPYING(VariableDagNode);

public:
  VariableDagNode(Symbol* symbol, int name);
  
  RawDagArgumentIterator* arguments();
  size_t getHashValue();
  int compareArguments(const DagNode* other) const;
  void overwriteWithClone(DagNode* old);
  DagNode* makeClone();
  DagNode* copyWithReplacement(int argIndex, DagNode* replacement);
  DagNode* copyWithReplacement(Vector<RedexPosition>& redexStack,
			       int first,
			       int last);
  void stackArguments(Vector<RedexPosition>& stack,
		      int parentIndex,
		      bool respectFrozen);

private:
  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();
  void clearCopyPointers2();
};

inline
VariableDagNode::VariableDagNode(Symbol* symbol, int name)
  : DagNode(symbol),
    NamedEntity(name)
{
}

#endif
