//
//      Class for subproblems which simply involve checking the sort of a dagNode
//
#ifndef _sortCheckSubproblem_hh_
#define _sortCheckSubproblem_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "subproblem.hh"

class SortCheckSubproblem : public Subproblem
{
public:
  SortCheckSubproblem(DagNode* subject, const Sort* sort);

  bool solve(bool findFirst, RewritingContext& solution);

private:
  DagNode* subject;
  const Sort* sort;
  int result;
};

#endif
