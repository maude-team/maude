/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2007 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//	Class for depthfirst searching for sequences of narrowing steps.
//
#ifndef _narrowingSequenceSearch_hh_
#define _narrowingSequenceSearch_hh_
#include "sequenceSearch.hh"
#include "matchSearchState.hh"
#include "protectedDagNodeSet.hh"

class NarrowingSequenceSearch : public SequenceSearch
{
  NO_COPYING(NarrowingSequenceSearch);

public:
  NarrowingSequenceSearch(RewritingContext* initial,
			  SearchType searchType,
			  Pattern* goal,
			  int maxDepth,
			  FreshVariableGenerator* freshVariableGenerator);
  ~NarrowingSequenceSearch();

  bool findNextMatch();
  const Pattern* getGoal() const;
  NarrowingSearchState* getState() const;
  const Substitution* getSubstitution() const;
  RewritingContext* getContext() const;
  DagNode* getStateDag() const;

private:
  bool findNextInterestingState();
  bool findNextNormalForm();

  RewritingContext* initial;
  Pattern* const goal;
  const int maxDepth;
  FreshVariableGenerator* freshVariableGenerator;

  bool needToTryInitialState;
  //bool reachingInitialStateOK;
  bool normalFormNeeded;
  bool topOfStackFresh;

  Vector<NarrowingSearchState*> stateStack;
  Vector<RewritingContext*> contextStack;
  MatchSearchState* matchState;

  ProtectedDagNodeSet seenSet;
};

inline const Pattern*
NarrowingSequenceSearch::getGoal() const
{
  return goal;
}

inline const Substitution*
NarrowingSequenceSearch::getSubstitution() const
{
  return matchState->getContext();
}

inline NarrowingSearchState*
NarrowingSequenceSearch::getState() const
{
  return stateStack[stateStack.size() - 1];
}

inline RewritingContext*
NarrowingSequenceSearch::getContext() const
{
  return initial;
}

inline DagNode*
NarrowingSequenceSearch::getStateDag() const
{
  return contextStack[contextStack.size() - 1]->root();
}

#endif
