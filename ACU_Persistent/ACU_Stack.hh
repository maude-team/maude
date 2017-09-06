//
//	Class for stack of pointers to red-black nodes.
//
#ifndef _ACU_Stack_hh_
#define _ACU_Stack_hh_
#include "ACU_RedBlackNode.hh"

class ACU_Stack
{
  NO_COPYING(ACU_Stack);
  
public:
  ACU_Stack();
  
  bool empty() const;
  ACU_RedBlackNode* top() const;
  
  void clear();
  void push(ACU_RedBlackNode* node);
  ACU_RedBlackNode* pop();
  void unpop();  // only valid if no clear() or push() since last pop()
  void multiPop(int nr);
  void stackLeftmostPath(ACU_RedBlackNode* n);
  void save();
  void restore();
 
private:
  enum Sizes
  {
    STACK_SIZE = ACU_RedBlackNode::MAX_TREE_HEIGHT
  };

  ACU_RedBlackNode** ptr;
  ACU_RedBlackNode** old;
  ACU_RedBlackNode* base[STACK_SIZE];
};

inline
ACU_Stack::ACU_Stack()
{
  ptr = base;
}

inline bool
ACU_Stack::empty() const
{
  return ptr == base;
}

inline ACU_RedBlackNode*
ACU_Stack::top() const
{
  Assert(ptr > base, "ACU stack underflow");
  return *(ptr - 1);
}

inline void
ACU_Stack::clear()
{
  ptr = base;
}

inline void
ACU_Stack::push(ACU_RedBlackNode* node)
{
  Assert(ptr < base + STACK_SIZE, "ACU stack overflow");
  *ptr++ = node;
}

inline ACU_RedBlackNode*
ACU_Stack::pop()
{
  Assert(ptr > base, "ACU stack underflow");
  return *(--ptr);
}

inline void
ACU_Stack::unpop()
{
  Assert(ptr < base + STACK_SIZE, "ACU stack overflow");
  ++ptr;
}

inline void
ACU_Stack::multiPop(int nr)
{
  Assert(ptr - nr >= base, "ACU stack underflow");
  ptr -= nr;
}

inline void
ACU_Stack::stackLeftmostPath(ACU_RedBlackNode* n)
{
  while (n != 0)  // might be optimized
    {
      push(n);
      n = n->getLeft();
    }
}

inline void
ACU_Stack::save()
{
  old = ptr;
}

inline void
ACU_Stack::restore()
{
  ptr = old;
}

#endif
