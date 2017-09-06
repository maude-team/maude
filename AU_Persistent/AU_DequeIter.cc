//
//      Implementation for class AU_DequeIter.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "AU_Persistent.hh"

//	AU persistent class definitions
#include "AU_DequeIter.hh"

void
AU_DequeIter::reverseRight()
{
  revIndex = (nrElementsRemaining - 1) / AU_StackNode::ELEMENTS_PER_NODE;
  reversed.resize(revIndex);
  AU_StackNode* p = right;
  for (Vector<AU_StackNode*>::iterator b = reversed.begin();; ++b)
    {
      AU_StackNode* n = p->next;
      if (n == 0)
	break;
      *b = p;
      p = n;
    }
  current = p;
  index = AU_StackNode::ELEMENTS_PER_NODE - 1;
}
