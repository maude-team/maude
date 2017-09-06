//
//	Class for searching for matches within a DAG.
//
#ifndef _matchSearchState_hh_
#define _matchSearchState_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "searchState.hh"

class MatchSearchState : public SearchState
{
  NO_COPYING(MatchSearchState);

public:
  enum Flags
  {
    GC_PATTERN = 8
  };

  MatchSearchState(RewritingContext* context,
		   Pattern* pattern,
		   int flags = 0,
		   int minDepth = 0,
		   int maxDepth = -1);
  ~MatchSearchState();

  Pattern* getPattern() const;
  bool findNextMatch();

private:
  Pattern* const pattern;
  bool firstMatch;
};

inline Pattern*
MatchSearchState::getPattern() const
{
  return pattern;
}

#endif
