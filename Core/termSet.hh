//
//      Class for set of pointers to terms.
//
#ifndef _termSet_hh_
#define _termSet_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "pointerSet.hh"

class TermSet : private PointerSet
{
public:
  void insert(Term* t);
  int term2Index(Term* t) const;
  PointerSet::cardinality;
  PointerSet::makeEmpty;

private:
  unsigned int hash(void* pointer) const;
  bool isEqual(void* pointer1, void* pointer2) const;
};

#endif
