//
//      Abstract base class for objects that contain dag root pointers and don't need
//	to manually link and unlink from the active list.
//
#ifndef _simpleRootContainer_hh_
#define _simpleRootContainer_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rootContainer.hh"

class SimpleRootContainer : protected RootContainer
{
protected:
  SimpleRootContainer();
  ~SimpleRootContainer();
};

inline
SimpleRootContainer::SimpleRootContainer()
{
  link();
}

inline
SimpleRootContainer::~SimpleRootContainer()
{
  unlink();
}

#endif
