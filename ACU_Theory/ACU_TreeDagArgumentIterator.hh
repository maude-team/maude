//
//	Class for argument iterator for ACU tree dag nodes.
//
#ifndef _ACU_TreeDagArgumentIterator_hh_
#define _ACU_TreeDagArgumentIterator_hh_
#include "rawDagArgumentIterator.hh"
#include "ACU_FastIter.hh"

class ACU_TreeDagArgumentIterator : public RawDagArgumentIterator
{
  NO_COPYING(ACU_TreeDagArgumentIterator);

public:
  ACU_TreeDagArgumentIterator(ACU_RedBlackNode* root);
 
  bool valid() const;
  DagNode* argument() const;
  void next();
 
private:
  ACU_FastIter iter;
  int multiplicityRemaining;
};

inline
ACU_TreeDagArgumentIterator::ACU_TreeDagArgumentIterator(ACU_RedBlackNode* root)
  : iter(root)
{
  multiplicityRemaining = iter.getMultiplicity();
}
 
#endif
