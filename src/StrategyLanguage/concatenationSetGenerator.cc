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
//      Implementation for abstract class ConcatenationSetGenerator.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "strategyLanguage.hh"

//	strategy language class definitions
#include "strategyExpression.hh"
#include "concatenationSetGenerator.hh"

ConcatenationSetGenerator::ConcatenationSetGenerator(DagNode* subject,
						     RewritingContext& context,
						     const Vector<StrategyExpression*>& strategies)
  : start(subject),
    context(context),
    strategies(strategies)
{
}

ConcatenationSetGenerator::~ConcatenationSetGenerator()
{
  FOR_EACH_CONST(i, GenQueue, genQueue)
    delete i->generator;
}

DagNode*
ConcatenationSetGenerator::findNextSolution()
{
  if (genQueue.empty())
    {
      //
      //	Initialize by applying first strategy to start term.
      //
      genQueue.push_back(SearchNode());
      genQueue.back().generator = strategies[0]->execute(start.getNode(), context);
      genQueue.back().nextStrategy = 1;
    }

  int nrStrategies = strategies.size();
  do
    {
      SetGenerator* g = genQueue.front().generator;
      int i = genQueue.front().nextStrategy;
      genQueue.pop_front();

      for (;; ++i)
	{
	  DagNode* d = g->findNextSolution();
	  if (d == 0)
	    break;
	  //
	  //	g produced a solution so it earns its place on the queue.
	  //
	  genQueue.push_back(SearchNode());
	  genQueue.back().generator = g;
	  genQueue.back().nextStrategy = i;
	  
	  if (i == nrStrategies)
	    return d;
	  g = strategies[i]->execute(d, context);
	}
      delete g;
    }
  while (!genQueue.empty());
  return 0;
}
