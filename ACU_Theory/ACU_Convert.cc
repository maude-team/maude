//
//	ArgVec to Red-Black tree conversion.
//

ACU_RedBlackNode* 
ACU_DagNode::makeTree()
{
  ACU_RedBlackNode* n = makeTree(argArray, 0, argArray.length(), false);

#ifdef CHECK_RED_BLACK
  if (!(n->checkRedBlackProperty()))
    abort();
#endif

  return n;
}

local_inline bool
ACU_DagNode::pow2min1(int i)
{
  //
  //	Return true iff i is 2^n - 1 for some n >= 0.
  //
  return ((i + 1) & i) == 0;
}

ACU_RedBlackNode* 
ACU_DagNode::makeTree(const ArgVec<Pair>& args,
		      int first,
		      int size,
		      bool makeRed)
{
  if (size == 0)
    return 0;
  int leftSize = size / 2;
  int rightSize = size - 1 - leftSize;
  ACU_RedBlackNode* leftTree = makeTree(args, first, leftSize,
					leftSize > rightSize && pow2min1(leftSize));
  ACU_RedBlackNode* rightTree = makeTree(args, first + leftSize + 1, rightSize, false);
  ACU_RedBlackNode* t = new ACU_RedBlackNode(args[first + leftSize].dagNode,
					     args[first + leftSize].multiplicity,
					     leftTree,
					     rightTree);
  if (makeRed)
    t->makeRed();
  return t;
}
