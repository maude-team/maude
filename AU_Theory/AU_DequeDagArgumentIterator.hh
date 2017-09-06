//
//	Class for argument iterator for AU deque dag nodes.
//
#ifndef _AU_DequeDagArgumentIterator_hh_
#define _AU_DequeDagArgumentIterator_hh_
#include "rawDagArgumentIterator.hh"
#include "AU_DequeIter.hh"

class AU_DequeDagArgumentIterator : public RawDagArgumentIterator
{
  NO_COPYING(AU_DequeDagArgumentIterator);

public:
  AU_DequeDagArgumentIterator(const AU_Deque& deque);
 
  bool valid() const;
  DagNode* argument() const;
  void next();
 
private:
  AU_DequeIter iter;
};

inline
AU_DequeDagArgumentIterator::AU_DequeDagArgumentIterator(const AU_Deque& deque)
  : iter(deque)
{
}
 
#endif
