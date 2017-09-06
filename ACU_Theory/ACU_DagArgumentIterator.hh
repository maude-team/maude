//
//	Class for argument iterator for ACU dag nodes.
//
#ifndef _ACU_DagArgumentIterator_hh_
#define _ACU_DagArgumentIterator_hh_
#include "rawDagArgumentIterator.hh"

class ACU_DagArgumentIterator : public RawDagArgumentIterator
{
public:
  ACU_DagArgumentIterator(const ArgVec<ACU_DagNode::Pair>* arguments);
 
  bool valid() const;
  DagNode* argument() const;
  void next();
 
private:
  const ArgVec<ACU_DagNode::Pair>* argArray;
  int position;
  int multiplicityRemaining;
};

inline
ACU_DagArgumentIterator::ACU_DagArgumentIterator(const ArgVec<ACU_DagNode::Pair>* arguments)
{
  argArray = arguments;
  position = 0;
  multiplicityRemaining = (*arguments)[0].multiplicity;
}
 
#endif
