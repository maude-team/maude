//
//	Class for searching for one step rewrites within a DAG.
//
#ifndef _rewriteSearchState_hh_
#define _rewriteSearchState_hh_
#include "searchState.hh"

class RewriteSearchState : public SearchState
{
  NO_COPYING(RewriteSearchState);

public:
  RewriteSearchState(RewritingContext* context,
		     int label,
		     int flags = 0,
		     int minDepth = 0,
		     int maxDepth = -1);

  Rule* getRule() const;
  DagNode* getReplacement() const;
  bool findNextRewrite();

private:
  const int label;
  const bool withExtension;
  int ruleIndex;
};

#endif
