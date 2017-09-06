//
//	Class for accumulating sequeces of subproblems
//
#ifndef _subproblemAccumulator_hh_
#define _subproblemAccumulator_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "subproblemSequence.hh"

class SubproblemAccumulator
{
public:
  SubproblemAccumulator();
  ~SubproblemAccumulator();

  void add(Subproblem* sp);
  Subproblem* extractSubproblem();

private:
  Subproblem* first;
  SubproblemSequence* sequence;
};

inline
SubproblemAccumulator::SubproblemAccumulator()
{
  first = 0;
  sequence = 0;
}

inline
SubproblemAccumulator::~SubproblemAccumulator()
{
  if (sequence != 0)
    delete sequence;
  else
    delete first;
}

inline void
SubproblemAccumulator::add(Subproblem* sp)
{
  if (sp != 0)
    {
      if (first == 0)
	first = sp;
      else if (sequence == 0)
	sequence = new SubproblemSequence(first, sp);
      else
	sequence->append(sp);
    }
}

inline Subproblem*
SubproblemAccumulator::extractSubproblem()
{
  Subproblem* r = 0;
  if (sequence != 0)
    {
      r = sequence;
      sequence = 0;
      first = 0;
    }
  else if (first != 0)
    {
      r = first;
      first = 0;
    }
  return r;
}

#endif
