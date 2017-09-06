//
//	Class for connected components in the sort hierarchy
//
#ifndef _connectedComponent_hh_
#define _connectedComponent_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "moduleItem.hh"
#include "natSet.hh"

class ConnectedComponent : public ModuleItem
{
  NO_COPYING(ConnectedComponent);

public:
  ConnectedComponent(Sort* firstSort);
  ~ConnectedComponent();

  int nrSorts() const;
  int nrMaximalSorts() const;
  Sort* sort(int index) const;
  bool leq(int index1, int index2) const;
  void findMaximalSorts(const NatSet& uSorts, Vector<int>& indices) const;
  int findIndex(const NatSet& leqSorts) const;
  const NatSet& getLeqSorts(int index) const;
  bool errorFree() const;
  void errorSortSeen();
  //
  //	for use by Sort only
  //
  void registerSort(Sort* sort);
  int appendSort(Sort* sort);

#ifdef DUMP
  void dump(ostream& s);
#endif

private:
  int sortCount;
  short nrMaxSorts;
  Bool errorFreeFlag;
  Vector<Sort*> sorts;
};

inline void
ConnectedComponent::errorSortSeen()
{
  errorFreeFlag = false;
}

inline bool
ConnectedComponent::errorFree() const
{
  return errorFreeFlag;
}

inline int
ConnectedComponent::nrSorts() const
{
  return sortCount;
}

inline int
ConnectedComponent::nrMaximalSorts() const
{
  return nrMaxSorts;
}

inline Sort*
ConnectedComponent::sort(int index) const
{
  return sorts[index];
}

inline void
ConnectedComponent::registerSort(Sort* /* sort */)
{
  ++sortCount;
}

inline int
ConnectedComponent::appendSort(Sort* sort)
{
  int i = sorts.length();
  sorts.append(sort);
  return i;
}

#endif
