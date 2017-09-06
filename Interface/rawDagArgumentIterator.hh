//
//      Abstract base class for raw DAG argument iterators.
//
#ifndef _rawDagArgumentIterator_hh_
#define _rawDagArgumentIterator_hh_

class RawDagArgumentIterator
{
public:
  virtual ~RawDagArgumentIterator() {}
  virtual bool valid() const = 0;
  virtual DagNode* argument() const = 0;
  virtual void next() = 0;
};

#endif
