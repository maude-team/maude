//
//	Class for argument iterator for AU dag nodes.
//
#ifndef _AU_DagArgumentIterator_hh_
#define _AU_DagArgumentIterator_hh_
#include "rawDagArgumentIterator.hh"

class AU_DagArgumentIterator : public RawDagArgumentIterator
{
public:
  AU_DagArgumentIterator(const ArgVec<DagNode*>& arguments);
 
  bool valid() const;
  DagNode* argument() const;
  void next();
 
private:
  const ArgVec<DagNode*>& argArray;
  int position;
};

inline
AU_DagArgumentIterator::AU_DagArgumentIterator(const ArgVec<DagNode*>& arguments)
  : argArray(arguments)
{
  position = 0;
}
 
#endif
