//
//  Class for DAG argument iterators in the free theory
//
#ifndef _freeDagArgumentIterator_hh_
#define _freeDagArgumentIteraror_hh_
#ifdef __GNUG__
#pragma interface
#endif

class FreeDagArgumentIterator : public RawDagArgumentIterator
{
public:
  FreeDagArgumentIterator(DagNode** first, int nrArgs);

  bool valid() const;
  DagNode* argument() const;
  void next();

private:
  DagNode** position;
  int nrRemaining;
};

inline
FreeDagArgumentIterator::FreeDagArgumentIterator(DagNode** first, int nrArgs)
{
  position = first;
  nrRemaining = nrArgs;
}

#endif
