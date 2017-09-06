//
//      Class for to hold state for solving an rewrite condition fragment.
//
#ifndef _rewriteConditionState_hh_
#define _rewriteConditionState_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "conditionState.hh"
#include "stateTransitionGraph3.hh"
#include "substitution.hh"

class RewriteConditionState : public ConditionState
{
public:
  RewriteConditionState(RewritingContext& original,
			DagNode* lhsInstance,
			LhsAutomaton* matcher);
  ~RewriteConditionState();

  bool solve(bool findFirst, RewritingContext& solution);

private:
  int findNextState();

  StateTransitionGraph3 stateGraph;
  LhsAutomaton* const matcher;

  Substitution saved;
  Subproblem* subproblem;
  int explore;
  int arcNr;
};

#endif
