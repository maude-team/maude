/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2006 SRI International, Menlo Park, CA 94025, USA.

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
//	Class for processes that solve matching problems associated with condition fragments.
//
#ifndef _matchProcess_hh_
#define _matchProcess_hh_
#include "strategicProcess.hh"
#include "sharedRewriteSearchState.hh"

class MatchProcess : public StrategicProcess
{
  NO_COPYING(MatchProcess);

public:
  MatchProcess(SharedRewriteSearchState::Ptr rewriteState,
	       PositionState::PositionIndex redexIndex,
	       ExtensionInfo* extensionInfo,
	       RewritingContext* matchContext,
	       Subproblem* subproblem,
	       Rule* rule,
	       int fragmentNr,
	       const Vector<StrategyExpression*>& strategies,
	       int strategyNr,
	       const StrategyStack& pending,
	       StrategicExecution* taskSibling,
	       StrategicProcess* insertionPoint);
  ~MatchProcess();

  Survival run(StrategicSearch& searchObject);

private:
  SharedRewriteSearchState::Ptr rewriteState;		// smart pointer to rewrite state that found our redex
  const PositionState::PositionIndex redexIndex;	// index of redex withing rewrite state
  ExtensionInfo* extensionInfoCopy;			// copy of extension info from original rule match
  RewritingContext* matchContext;			// rewrite context associated with our fragment match
  Subproblem* subproblem;				// subproblem associated with our fragment match
  Rule* const rule;					// pointer to rule whose lhs matched
  const int fragmentNr;					// number of condition fragment within rule
  const Vector<StrategyExpression*>& strategies;	// vector of strategies for rewrite fragments
  const int strategyNr;					// number of next strategy to use
  const StrategyStack pending;				// continuation once we finally do a rewrite
  bool findFirst;					// are we looking for a first solution to fragment match?
};

#endif