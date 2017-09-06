//
//      Class for to hold state for solving an assignment condition fragment.
//
#ifndef _assignmentConditionState_hh_
#define _assignmentConditionState_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "conditionState.hh"
#include "substitution.hh"

class AssignmentConditionState : public ConditionState
{
public:
  AssignmentConditionState(RewritingContext& original,
			   LhsAutomaton* matcher,
			   DagNode* rhsInstance);
  ~AssignmentConditionState();

  bool solve(bool findFirst, RewritingContext& solution);

private:
  Substitution saved;
  RewritingContext* rhsContext;
  Subproblem* subproblem;
  bool succeeded;
};

#endif
