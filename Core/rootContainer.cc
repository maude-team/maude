//
//      Implementation for class RootContainer
//

//	utility stuff
#include "macros.hh"

//      forward declarations
#include "core.hh"

//      core class definitions
#include "rootContainer.hh"

RootContainer* RootContainer::listHead = 0;

#ifdef DUMP

void
RootContainer::dump(ostream& s)
{
  for (RootContainer* p = listHead; p; p = p->next)
    {
      s << static_cast<void*>(p) << endl;
      Assert((p->prev == 0 && listHead == p) || p->prev->next == p,
	     "bad linked list");
    }
}

#endif
