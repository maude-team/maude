//
//      Functions to allocate a new memory cell.
//
//	This is in a seperate header file since we want it inlined
//	and it uses the class DagNode declaration. We can't put it
//	in memoryCell.hh because class DagNode is derived from
//	class MemoryCell.
//
#ifndef _memoryCellNew_hh_
#define _memoryCellNew_hh_
#ifdef __GNUG__
#pragma interface
#endif

inline void
MemoryCell::callDtor()
{
  //
  //	MemoryCell cannot have a virtual destructor since we want to
  //	avoid a virtual function table pointer. Instead we assume
  //	it is a DagNode and downcast it. This means that only classes
  //	derived from DagNode can use the call dtor flag.
  //
  (static_cast<DagNode*>(this))->~DagNode();
}

inline void
MemoryCell::initialize()
{
  h.flags = 0;
  h.halfWord = Sort::SORT_UNKNOWN;
}

inline void*
MemoryCell::operator new(size_t /* size */)
{
#ifdef GC_DEBUG
  checkInvariant();
#endif
  FullSizeMemoryCell* e = endPointer;
  for (FullSizeMemoryCell* c = nextNode; c != e; c++)
    {
      if (!(c->getFlag(MARKED | CALL_DTOR)))
	{
	  c->initialize();
	  nextNode = c + 1;
	  DebugAdvisory("gc new nondtor case at "<< (void*)(c));
	  Assert(c->h.halfWord == Sort::SORT_UNKNOWN, cerr << "bad sort init");
	  return static_cast<void*>(c);
	}
      if (!(c->getFlag(MARKED)))
	{
	  c->callDtor();
	  c->initialize();
	  nextNode = c + 1;
	  DebugAdvisory("gc new dtor case at " << (void*)(c));
	  Assert(c->h.halfWord == Sort::SORT_UNKNOWN, cerr << "bad sort init");
	  return static_cast<void*>(c);
	}
      c->clearFlag(MARKED);
    }
  return slowNew();
}

#endif
