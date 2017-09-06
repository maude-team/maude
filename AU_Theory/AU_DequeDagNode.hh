//
//	Class for A and AU dag nodes based on persistent deques.
//
#ifndef _AU_DequeDagNode_hh_
#define _AU_DequeDagNode_hh_
#include "AU_BaseDagNode.hh"
#include "AU_Deque.hh"

class AU_DequeDagNode : public AU_BaseDagNode
{
  NO_COPYING(AU_DequeDagNode);

public:
  AU_DequeDagNode(AU_Symbol* symbol, const AU_Deque& original);
  //
  //	Functions required by theory interface.
  //
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
  //
  //	Functions required to handle extension information.
  //
  ExtensionInfo* makeExtensionInfo();
  //
  //	Functions particular to AU_DequeDagNode.
  //
  int nrArgs() const;
  const AU_Deque& getDeque() const;
  static AU_DagNode* dequeToArgVec(AU_DequeDagNode* original);

private:
  //
  //	Functions required by theory interface.
  //
  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();
  void clearCopyPointers2();

  AU_Deque deque;
};

inline
AU_DequeDagNode::AU_DequeDagNode(AU_Symbol* symbol, const AU_Deque& original)
  : AU_BaseDagNode(symbol),
    deque(original)
{
  setNormalizationStatus(DEQUE);
}

inline int
AU_DequeDagNode::nrArgs() const
{
  return deque.length();
}

inline const AU_Deque&
AU_DequeDagNode::getDeque() const
{
  return deque;
}

#endif
