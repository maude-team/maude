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
//	Class for holding the set of (dag, remaining strategy) pairs encountered
//	during rewriting with a strategy. Rather than keep an explicit representation of
//	the remaining strategy, callers are instead assigned a unique identifier.
//
#ifndef _stateCache_hh_
#define _stateCache_hh_
#include <set>
#include "simpleRootContainer.hh"
#include "dagNodeSet.hh"

class StateCache : private SimpleRootContainer
{
  NO_COPYING(StateCache);

public:
  typedef int StrategyId;  // might make this Int64 at some point

  ~StateCache();

  StrategyId newStratId();
  bool insertState(DagNode* dag, StrategyId stratPos);

private:
  typedef set<StrategyId> IdSet;

  struct Pair
  {
    DagNode* dag;
    IdSet ids;
  };

  void markReachableNodes();

  StrategyId counter;
  DagNodeSet seenSet;
  Vector<IdSet*> seen;
};

inline StateCache::StrategyId
StateCache::newStratId()
{
  ++counter;
  return counter;
}

#endif
