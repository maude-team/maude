//
//	Class for Red-Black Tree based DAG nodes in the AC and ACU theories.
//
#ifndef _ACU_TreeDagNode_hh_
#define _ACU_TreeDagNode_hh_
#include "ACU_BaseDagNode.hh"
#include "ACU_Tree.hh"

class ACU_TreeDagNode : public ACU_BaseDagNode
{
public:
  ACU_TreeDagNode(ACU_Symbol* symbol, const ACU_Tree& tree);
   //
  //	Member functions required by theory interface.
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
  //	Member functions required to handle extension information.
  //
  bool matchVariableWithExtension(int index,
				  const Sort* sort,
				  Substitution& solution,
				  Subproblem*& returnedSubproblem,
				  ExtensionInfo* extensionInfo);
  void partialReplace(DagNode* replacement, ExtensionInfo* extensionInfo);
  DagNode* partialConstruct(DagNode* replacement, ExtensionInfo* extensionInfo);
  //
  //	ACU_TreeDagNode -> ACU_DagNode in-place conversion function.
  //
  static ACU_DagNode* treeToArgVec(ACU_TreeDagNode* original);

  const ACU_Tree& getTree() const;

private:
 //
  //	Theory interface functions.
  //
  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();
  void clearCopyPointers2();
  //
  //	Arguments under ACU symbol.
  //
  ACU_Tree tree;
  //
  //	Slot for caching hash value.
  //
  size_t hashCache;
};

inline
ACU_TreeDagNode::ACU_TreeDagNode(ACU_Symbol* symbol, const ACU_Tree& tree)
  : ACU_BaseDagNode(symbol), tree(tree)
{
  Assert(tree.getSize() > 1 || tree.getMaxMult() > 1,
  	 "tried to make ACU_TreeDagNode with single argument");
  setNormalizationStatus(TREE);
}

inline
const ACU_Tree&
ACU_TreeDagNode::getTree() const
{
  return tree;
}

#endif
