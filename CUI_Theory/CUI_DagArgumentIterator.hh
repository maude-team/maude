//
//	Class for argument iterator for CUI dag nodes.
//
#ifndef _CUI_DagArgumentIterator_hh_
#define _CUI_DagArgumentIterator_hh_
#include "rawDagArgumentIterator.hh"

class CUI_DagArgumentIterator : public RawDagArgumentIterator
{
public:
  CUI_DagArgumentIterator(DagNode** first);

  bool valid() const;
  DagNode* argument() const;
  void next();

private:
  DagNode** position;
  int nrRemaining;
};

inline
CUI_DagArgumentIterator::CUI_DagArgumentIterator(DagNode** first)
{
  position = first;
  nrRemaining = 2;
}

#endif
