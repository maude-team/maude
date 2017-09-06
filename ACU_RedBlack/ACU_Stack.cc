//
//      Implementation for class ACU_RedBlackNode.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_RedBlack.hh"

//	ACU red-black class definitions
#include "ACU_RedBlackNode.hh"
#include "ACU_Stack.hh"

int
ACU_Stack::pathToIndex()
{
  //
  //	Need to have the complete path on the stack.
  //
  Assert(ptr != base, cerr << "empty stack");
  int index = 0;
  ACU_RedBlackNode* n = base[0];
  for (ACU_RedBlackNode** q = base + 1; q != ptr; ++q)
    {
      ACU_RedBlackNode* t = *q;
      if (n->getRight() == t)
	{
	  ACU_RedBlackNode* l = n->getLeft();
	  ++index;
	  if (l != 0)
	    index += l->getSize();
	}
      n = t;
    }
  ACU_RedBlackNode* l = n->getLeft();
  if (l != 0)
    index += l->getSize();
  return index;
}
