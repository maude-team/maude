//
//      Implementation for class AU_Deque.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "AU_Persistent.hh"

//	interface class definitions
#include "symbol.hh"

//	AU stack class definitions
#include "AU_Deque.hh"

int
AU_Deque::computeBaseSort(Symbol* symbol) const
{
#ifdef CHECK_DEQUE
  checkIntegrity();
#endif

  if (left != 0)
    {
      int index = left->getSortIndex();
      if (index == Sort::SORT_UNKNOWN)
	index = left->fwdComputeBaseSort(symbol);

#ifdef CHECK_DEQUE
  checkIntegrity();
#endif

      if (right == 0)
	return index;
      int index2 = right->getSortIndex();
      if (index2 == Sort::SORT_UNKNOWN)
	index2 = right->revComputeBaseSort(symbol);

#ifdef CHECK_DEQUE
  checkIntegrity();
#endif

      return symbol->traverse(symbol->traverse(0, index), index2);
    }
  Assert(right != 0, "no args");
  int index = right->getSortIndex();
  if (index == Sort::SORT_UNKNOWN)
    index = right->revComputeBaseSort(symbol);

#ifdef CHECK_DEQUE
  checkIntegrity();
#endif

  return index;
}

#ifdef CHECK_DEQUE

void
AU_Deque::checkIntegrity() const 
{
  int l = AU_StackNode::checkIntegrity(left);
  int r = AU_StackNode::checkIntegrity(right);
  Assert(nrElements == l + r,
	 "bad deque size: " << nrElements << " != " << l << " + " << r);
}

#endif
