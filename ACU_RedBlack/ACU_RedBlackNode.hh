//
//	Class for nodes in persistent red-black trees.
//
#ifndef _ACU_RedBlackNode_hh_
#define _ACU_RedBlackNode_hh_
#include "memoryCell.hh"

class ACU_RedBlackNode
{
  NO_COPYING(ACU_RedBlackNode);

public:
  enum PublicValues
  {
    MAX_TREE_HEIGHT = 64,	// must be height of largest red-black tree
    SAT_MULT = 127		// saturation multiplicity for findGeqMult()
  };

  ACU_RedBlackNode(DagNode* dagNode,
		   int multiplicity,
		   ACU_RedBlackNode* left,
		   ACU_RedBlackNode* right);

  ACU_RedBlackNode(DagNode* dagNode,
		   int multiplicity,
		   ACU_RedBlackNode* left,
		   ACU_RedBlackNode* right,
		   int size,
		   int maxMult);

  DagNode* getDagNode() const;
  int getMultiplicity() const;
  ACU_RedBlackNode* getLeft() const;
  ACU_RedBlackNode* getRight() const;
  int getSize() const;

  void setSortIndex(int index);
  int getSortIndex() const;

  void makeRed();  // need for conversion from array

  void* operator new(size_t size);
  void setMarked();
  bool isMarked();

  static bool find(ACU_RedBlackNode* root,
		   DagNode* dagNode,
		   ACU_Stack& path);

  static bool find(ACU_RedBlackNode* root,
		   Term* term,
		   ACU_Stack& path);

  static bool findFirstPotentialMatch(ACU_RedBlackNode* root,
				      Term* key,
				      const Substitution& partial,
				      ACU_Stack& path);

  static bool findGeqMult(ACU_RedBlackNode* root,
			  int multiplicity,
			  ACU_Stack& path);

  static void findIth(ACU_RedBlackNode* root,
		      int index,
		      ACU_Stack& path);

  static ACU_RedBlackNode* consInsert(ACU_RedBlackNode* root,
				      DagNode* dagNode,
				      int multiplicity);

  static ACU_RedBlackNode* consDelete(ACU_Stack& path, int multiplicity);


  void dump(ostream& s, int indent);

#ifdef CHECK_RED_BLACK
  //
  //	Extra functions for strict checking of red-black property
  //	after each operation.
  //
  bool checkRedBlackProperty();
  bool checkRedBlackProperty(int& height);
  static ACU_RedBlackNode* consInsert2(ACU_RedBlackNode* root,
				      DagNode* dagNode,
				      int multiplicity);

  static ACU_RedBlackNode* consDelete2(ACU_Stack& path, int multiplicity);

#endif

private:
  enum Values
  {
    LEFT_INDEX = 0,
    RIGHT_INDEX = 1
  };

  enum Flags
  {
    RED = 1
  };

  static ACU_RedBlackNode* copy(ACU_Stack& path,
				ACU_RedBlackNode* n,
				ACU_RedBlackNode* old);

  static ACU_RedBlackNode* copy(ACU_Stack& path,
				ACU_RedBlackNode* n,
				ACU_RedBlackNode* old,
				ACU_RedBlackNode* victim,
				ACU_RedBlackNode* surrogate);

  static ACU_RedBlackNode* copyRebalance(ACU_Stack& path,
					 ACU_RedBlackNode* n,
					 ACU_RedBlackNode* old,
					 ACU_RedBlackNode* victim,
					 ACU_RedBlackNode* surrogate);

  static ACU_RedBlackNode* blackNode(ACU_RedBlackNode* key,
				     ACU_RedBlackNode* left,
				     ACU_RedBlackNode* right);

  static ACU_RedBlackNode* redNode(ACU_RedBlackNode* key,
				   ACU_RedBlackNode* left,
				   ACU_RedBlackNode* right);

  bool isRed() const;
  static bool isRed(const ACU_RedBlackNode* mightBeNull);

  int getMaxMult() const;
  //
  //	Nasty cross casting stuff.
  //
  MemoryCell* getMemoryCell();
  const MemoryCell* getMemoryCell() const;

  DagNode* const dagNode;
  int const multiplicity;
  ACU_RedBlackNode* children[2];  // no way to initialize const
  int size;  // subtree size in red-black nodes;
};

inline MemoryCell*
ACU_RedBlackNode::getMemoryCell()
{
  return static_cast<MemoryCell*>(static_cast<void*>(this));
}

inline const MemoryCell*
ACU_RedBlackNode::getMemoryCell() const
{
  return static_cast<const MemoryCell*>(static_cast<const void*>(this));
}

inline void*
ACU_RedBlackNode::operator new(size_t size)
{
  //
  //	We rely on MemoryCell::allocateMemoryCell() setting the half word to
  //	Sort::SORT_UNKNOWN.
  //
  Assert(size <= sizeof(MemoryCell), cerr << "red-black node too big");
  return MemoryCell::allocateMemoryCell();
}

inline void
ACU_RedBlackNode::setMarked()
{
  getMemoryCell()->setMarked();
}

inline bool
ACU_RedBlackNode::isMarked()
{
  return getMemoryCell()->isMarked();
}

inline int
ACU_RedBlackNode::getMaxMult() const
{
  return getMemoryCell()->getByte();
}

inline
ACU_RedBlackNode::ACU_RedBlackNode(DagNode* dagNode,
				   int multiplicity,
				   ACU_RedBlackNode* left,
				   ACU_RedBlackNode* right)
  : dagNode(dagNode),
    multiplicity(multiplicity)
{
  int sz = 1;
  int maxMult = multiplicity;
  if (maxMult > SAT_MULT)
    maxMult = SAT_MULT;
  if (left != 0)
    {
      sz += left->size;
      int t = left->getMaxMult();
      if (t > maxMult)
	maxMult = t;
    }
  if (right != 0)
    {
      sz += right->size;
      int t = right->getMaxMult();
      if (t > maxMult)
	maxMult = t;
    }
  size = sz;
  getMemoryCell()->setByte(maxMult);
  children[LEFT_INDEX] = left;
  children[RIGHT_INDEX] = right;
}

inline
ACU_RedBlackNode::ACU_RedBlackNode(DagNode* dagNode,
				   int multiplicity,
				   ACU_RedBlackNode* left,
				   ACU_RedBlackNode* right,
				   int size,
				   int maxMult)
  : dagNode(dagNode),
    multiplicity(multiplicity),
    size(size)
{
  Assert(size == 1 +
	 ((left == 0) ? 0 : left->size) +
	 ((right == 0) ? 0 : right->size),
	 cerr << "bad size");
  Assert(maxMult ==
	 min(SAT_MULT, max(multiplicity,
			   max((left == 0) ? 0 : left->getMaxMult(),
			       (right == 0) ? 0 : right->getMaxMult()))),
	  cerr << "bad maxMult");
  getMemoryCell()->setByte(maxMult);
  children[LEFT_INDEX] = left;
  children[RIGHT_INDEX] = right;
}

inline DagNode*
ACU_RedBlackNode::getDagNode() const
{
  return dagNode;
}

inline int
ACU_RedBlackNode::getMultiplicity() const
{
  return multiplicity;
}

inline ACU_RedBlackNode*
ACU_RedBlackNode::getLeft() const
{
  return children[LEFT_INDEX];
}

inline ACU_RedBlackNode*
ACU_RedBlackNode::getRight() const
{
  return children[RIGHT_INDEX];
}

inline int
ACU_RedBlackNode::getSize() const
{
  return size;
}

inline void
ACU_RedBlackNode::setSortIndex(int index)
{
  getMemoryCell()->setHalfWord(index);
}

inline int
ACU_RedBlackNode::getSortIndex() const
{
  return getMemoryCell()->getHalfWord();
}

inline bool
ACU_RedBlackNode::isRed() const
{
  return getMemoryCell()->getFlag(RED);
}

inline bool
ACU_RedBlackNode::isRed(const ACU_RedBlackNode* mightBeNull)
{
  return mightBeNull != 0 && mightBeNull->getMemoryCell()->getFlag(RED);
}

inline void
ACU_RedBlackNode::makeRed()
{
  getMemoryCell()->setFlag(RED);
}

inline ACU_RedBlackNode*
ACU_RedBlackNode::redNode(ACU_RedBlackNode* key,
			  ACU_RedBlackNode* left,
			  ACU_RedBlackNode* right)
{
  ACU_RedBlackNode* n = blackNode(key, left, right);
  n->makeRed();
  return n;
}

#endif
