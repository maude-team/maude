//
//      Wrapper around raw DAG argument iterators to provide cleaner interface.
//
#ifndef _dagArgumentIterator_hh_
#define _dagArgumentIterator_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rawDagArgumentIterator.hh"

class DagArgumentIterator
{
public:
  DagArgumentIterator(DagNode& d);
  DagArgumentIterator(DagNode* d);
  ~DagArgumentIterator();

  bool valid() const;
  DagNode* argument() const;
  void next();

private:
  RawDagArgumentIterator* dagArgumentIterator;
};

inline
DagArgumentIterator::DagArgumentIterator(DagNode& d)
{
  dagArgumentIterator = d.arguments();

}
inline
DagArgumentIterator::DagArgumentIterator(DagNode* d)
{
  dagArgumentIterator = d->arguments();
}

inline
DagArgumentIterator::~DagArgumentIterator()
{
  delete dagArgumentIterator;
}

inline bool
DagArgumentIterator::valid() const
{
  return (dagArgumentIterator != 0) && dagArgumentIterator->valid();
}

inline DagNode*
DagArgumentIterator::argument() const
{
  return dagArgumentIterator->argument();
}

inline void
DagArgumentIterator::next()
{
  dagArgumentIterator->next();
}

#endif
