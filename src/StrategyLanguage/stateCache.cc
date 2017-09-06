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
//	Implementation for class StateTransitionGraph3.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "dagNode.hh"

//	strategy language class definitions
#include "stateCache.hh"


StateCache::~StateCache()
{
  FOR_EACH_CONST(i, Vector<IdSet*>, seen)
    delete *i;
}

void
StateCache::markReachableNodes()
{
  int nrDags = seen.length();
  for (int i = 0; i < nrDags; i++)
    seenSet.index2DagNode(i)->mark();
}

bool
StateCache::insertState(DagNode* dag, StrategyId stratPos)
{
  int dagIndex = seenSet.dagNode2Index(dag);
  if (dagIndex == NONE)
    {
      seenSet.insert(dag);
      IdSet *is = new IdSet;
      is->insert(stratPos);
      seen.append(is);
      return false;
    }
  return !((seen[dagIndex]->insert(stratPos)).second);
}
