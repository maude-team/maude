//
//	Class for sequence of subproblems to be solved sequentially
//
#ifndef _subproblemSequence_hh_
#define _subproblemSequence_hh_
#include "subproblem.hh"

class SubproblemSequence : public Subproblem
{
public:
  SubproblemSequence(Subproblem* first, Subproblem* second);
  ~SubproblemSequence();

  void append(Subproblem* sp);
  bool solve(bool findFirst, RewritingContext& solution);

private:
  Vector<Subproblem*> sequence;
};

inline
SubproblemSequence::SubproblemSequence(Subproblem* first, Subproblem* second)
  : sequence(2)
{
  sequence[0] = first;
  sequence[1] = second;
}

inline void 
SubproblemSequence::append(Subproblem* sp)
{
  sequence.append(sp);
}

#endif
