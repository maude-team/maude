//
//      Abstract base class for objects that contain dag root pointers.
//
#ifndef _rawRootContainer_hh_
#define _rawRootContainer_hh_
#ifdef __GNUG__
#pragma interface
#endif

class RawRootContainer
{
public:
  static void markPhase();

protected:
  void link();
  void unlink();
  virtual void markReachableNodes() = 0;

private:
  static RootContainer* listHead;

  RootContainer* next;
  RootContainer* prev;
};

inline
RootContainer::link()
{
  prev = 0;
  next = listHead;
  if (listHead != 0)
    listHead->prev = this;
  listHead = this;
}

inline
RootContainer::unlink()
{
  if (next != 0)
    next->prev = prev;
  if (prev != 0)
    prev->next = next;
  else
    listHead = next;
}

inline void
RootContainer::markPhase()
{
  for (RootContainer* p = listHead; p; p = p->next)
    p->markReachableNodes();
}

#endif
