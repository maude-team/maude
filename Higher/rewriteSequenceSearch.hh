//
//	Class for searching for sequences of rewrites within a DAG.
//
#ifndef _rewriteSequenceSearch_hh_
#define _rewriteSequenceSearchState_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "stateTransitionGraph3.hh"
#include "matchSearchState.hh"

class RewriteSequenceSearch : public StateTransitionGraph3
{
  NO_COPYING(RewriteSequenceSearch);

public:
  enum SearchType
  {
    ONE_STEP,
    AT_LEAST_ONE_STEP,
    ANY_STEPS,
    NORMAL_FORM
  };

  RewriteSequenceSearch(RewritingContext* initial,
			SearchType searchType,
			Pattern* goal,
			int maxDepth = -1);
  ~RewriteSequenceSearch();

  bool findNextMatch();
  const Pattern* getGoal() const;
  Rule* getStateRule(int stateNr) const;
  int getStateNr() const;
  const Substitution* getSubstitution() const;
  
private:
  int findNextInterestingState();

  const SearchType searchType;
  Pattern* const goal;
  const int maxDepth;
  int explore;
  int exploreDepth;
  int firstDeeperNodeNr;
  int nextArc;
  bool needToTryInitialState;
  MatchSearchState* matchState;
  int stateNr;
};

inline const Pattern*
RewriteSequenceSearch::getGoal() const
{
  return goal;
}

inline const Substitution*
RewriteSequenceSearch::getSubstitution() const
{
  return matchState->getContext();
}

inline int
RewriteSequenceSearch::getStateNr() const
{
  return stateNr;
}

#endif
