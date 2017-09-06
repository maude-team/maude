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
//      Implementation for abstract class Strategy.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "strategyLanguage.hh"

//	strategy language class definitions
#include "unionSetGenerator.hh"
#include "strategyExpression.hh"

UnionSetGenerator::UnionSetGenerator(DagNode* start,
				     RewritingContext& context,
				     const Vector<StrategyExpression*>& strategies)
  : start(start),
    context(context),
    strategies(strategies)
{
  current = 0;
}

UnionSetGenerator::~UnionSetGenerator()
{
  FOR_EACH_CONST(i, GenQueue, genQueue)
    delete *i;
}

DagNode*
UnionSetGenerator::findNextSolution()
{
  int nrStrategies = strategies.size();
  while (current < nrStrategies)
    {
      SetGenerator* g = strategies[current]->execute(start.getNode(), context);
      ++current;
      DagNode* d = g->findNextSolution();
      if (d == 0)
	delete g;
      else
	{
	  genQueue.push_back(g);
	  return d;
	}
    }

  while (!genQueue.empty())
    {
      SetGenerator* g = genQueue.front();
      genQueue.pop_front();
      DagNode* d = g->findNextSolution();
      if (d == 0)
	delete g;
      else
	{
	  genQueue.push_back(g);
	  return d;
	}
    }
  return 0;
}
