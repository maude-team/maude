//
//	Class for slow iterators for ACU red-black trees.
//
//	They are slow in the sense that we always keep the full
//	path on the stack.
//
#ifndef _ACU_SlowIter_hh_
#define _ACU_SlowIter_hh_
#include "ACU_Stack.hh"

class ACU_SlowIter : public ACU_Stack
{
  NO_COPYING(ACU_SlowIter);

public:
  ACU_SlowIter();
  ACU_SlowIter(ACU_RedBlackNode* root);
  
  bool valid() const;
  DagNode* getDagNode() const;
  int getMultiplicity() const;
  void next();
};

inline
ACU_SlowIter::ACU_SlowIter()
{
}

inline
ACU_SlowIter::ACU_SlowIter(ACU_RedBlackNode* root)
{
  stackLeftmostPath(root);
}

inline bool
ACU_SlowIter::valid() const
{
  return !empty();
}

inline DagNode*
ACU_SlowIter::getDagNode() const
{
  return top()->getDagNode();
}

inline int
ACU_SlowIter::getMultiplicity() const
{
  return top()->getMultiplicity();
}

/*
inline void
ACU_SlowIter::next()
{
  ACU_RedBlackNode* t = pop();
  if (t->getRight() != 0)
    {
      unpop();
      stackLeftmostPath(t->getRight());
    }
  else
    {
      while (!empty() && top()->getRight() == t)
	t = pop();
    }
}
*/

inline void
ACU_SlowIter::next()
{
  ACU_RedBlackNode* t = top()->getRight();
  if (t != 0)
    stackLeftmostPath(t);
  else
    {
      do
	t = pop();
      while (!empty() && top()->getRight() == t);
    }
}

#endif
