//
//	Class for fast iterators for ACU red-black trees.
//
//	They are fast in the sense that we do the explicit
//	stack version of tail recursion elimination and therefore
//	may not have a full path on the stack.
//
#ifndef _ACU_FastIter_hh_
#define _ACU_FastIter_hh_
#include "ACU_Stack.hh"
#include "ACU_Tree.hh"

class ACU_FastIter : private ACU_Stack
{
  NO_COPYING(ACU_FastIter);

public:
  ACU_FastIter(const ACU_Tree& tree);
  
  bool valid() const;
  DagNode* getDagNode() const;
  int getMultiplicity() const;
  void next();
};

inline
ACU_FastIter::ACU_FastIter(const ACU_Tree& tree)
{
  stackLeftmostPath(tree.root);
}

inline bool
ACU_FastIter::valid() const
{
  return !empty();
}

inline DagNode*
ACU_FastIter::getDagNode() const
{
  return top()->getDagNode();
}

inline int
ACU_FastIter::getMultiplicity() const
{
  return top()->getMultiplicity();
}

inline void
ACU_FastIter::next()
{
  stackLeftmostPath(pop()->getRight());
}

#endif
