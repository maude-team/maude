//
//	Class for argument iterator for S_DagNodes.
//
#ifndef _S_DagArgumentIterator_hh_
#define _S_DagArgumentIterator_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rawDagArgumentIterator.hh"

class S_DagArgumentIterator : public RawDagArgumentIterator
{
public:
  S_DagArgumentIterator(DagNode* arg);
  //
  //    Functions required by theory interface.
  //
  bool valid() const;
  DagNode* argument() const;
  void next();
 
private:
  DagNode* arg;
};

inline
S_DagArgumentIterator::S_DagArgumentIterator(DagNode* arg)
  : arg(arg)
{
}
 
#endif
