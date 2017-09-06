//
//	Class for red-black trees of argument-multiplicity pairs.
//
#ifndef _ACU_Tree_hh_
#define _ACU_Tree_hh_
#include "argVec.hh"
#include "ACU_Pair.hh"
#include "ACU_RedBlackNode.hh"

class ACU_Tree
{
public:
  ACU_Tree(){}
  ACU_Tree(const ArgVec<ACU_Pair>& source);

  void clear();
  int getSize() const;
  int getMaxMult() const;
  void copyToArgVec(ArgVec<ACU_Pair>& dest) const;
  DagNode* getSoleDagNode() const;
  int getSoleMultiplicity() const;

  bool find(DagNode* dagNode, ACU_Stack& path) const;
  bool find(Term* term, ACU_Stack& path) const ;
  bool findFirstPotentialMatch(Term* key,
			       const Substitution& partial,
			       ACU_Stack& path) const;
  bool findGeqMult(int multiplicity, ACU_Stack& path) const;

  void insertMult(DagNode* dagNode, int multiplicity);
  void deleteMult(ACU_Stack& path, int multiplicity);

  int computeBaseSort(BinarySymbol* symbol) const;
  void mark();

#ifdef CHECK_TREE
  void checkIntegrity(DagNode* dagNode = 0, int multiplicity = 0) const;
#endif

private:
  static bool pow2min1(int i);
  static ACU_RedBlackNode*  makeTree(const ArgVec<ACU_Pair>& args,
				     int first,
				     int size,
				     bool makeRed);
  static int computeBaseSort2(BinarySymbol* symbol, ACU_RedBlackNode* root);

  int size;
  ACU_RedBlackNode* root;

  friend class ACU_FastIter;
  friend class ACU_SlowIter;
};

inline int
ACU_Tree::getSize() const
{
  return size;
}

inline void
ACU_Tree::clear()
{
  size = 0;
  root = 0;
}

inline int
ACU_Tree::getMaxMult() const
{
  return root->getMaxMult();
}

inline DagNode*
ACU_Tree::getSoleDagNode() const
{
  Assert(size == 1, "more than one node in tree");
  return root->getDagNode();
}

inline int
ACU_Tree::getSoleMultiplicity() const
{
  Assert(size == 1, "more than one node in tree");
  return root->getMultiplicity();
}

inline bool
ACU_Tree::find(DagNode* dagNode, ACU_Stack& path) const
{
  return ACU_RedBlackNode::find(root, dagNode, path);
}

inline bool
ACU_Tree::find(Term* term, ACU_Stack& path) const
{
  return ACU_RedBlackNode::find(root, term, path);
}

inline bool
ACU_Tree::findFirstPotentialMatch(Term* key,
				  const Substitution& partial,
				  ACU_Stack& path) const
{
  return ACU_RedBlackNode::findFirstPotentialMatch(root, key, partial, path);
}

inline bool
ACU_Tree::findGeqMult(int multiplicity, ACU_Stack& path) const
{
  return ACU_RedBlackNode::findGeqMult(root, multiplicity, path);
}

inline int
ACU_Tree::computeBaseSort(BinarySymbol* symbol) const
{
  Assert(size > 0 && root != 0, "bad tree for sort computation");
  int index = root->getSortIndex();
  if (index != Sort::SORT_UNKNOWN)
    return index;
  return computeBaseSort2(symbol, root);
}

inline void
ACU_Tree::insertMult(DagNode* dagNode, int multiplicity)
{
#ifdef CHECK_TREE
  checkIntegrity();
#endif

  int delta;
  root = ACU_RedBlackNode::consInsert(root, dagNode, multiplicity, delta);
  size += delta;

#ifdef CHECK_TREE
  checkIntegrity(dagNode, multiplicity);
#endif
}

inline void
ACU_Tree::deleteMult(ACU_Stack& path, int multiplicity)
{
#ifdef CHECK_TREE
  checkIntegrity();
  ACU_RedBlackNode* dagNode = path.top();
#endif

  int delta;
  root = ACU_RedBlackNode::consDelete(path, multiplicity, delta);
  size += delta;

#ifdef CHECK_TREE
  checkIntegrity(dagNode, multiplicity);
#endif
}

#endif
