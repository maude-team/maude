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
#include "branchSetGenerator.hh"
#include "strategyExpression.hh"

BranchSetGenerator::BranchSetGenerator(DagNode* start,
				       RewritingContext& context,
				       StrategyExpression* test,
				       StrategyExpression* success,
				       StrategyExpression* failure)
  : start(start),
    context(context),
    test(test),
    success(success),
    failure(failure)
{
  testGen = 0;
}

BranchSetGenerator::~BranchSetGenerator()
{
  delete testGen;
  FOR_EACH_CONST(i, GenQueue, genQueue)
    delete *i;
}

DagNode*
BranchSetGenerator::findNextSolution()
{
  if (genQueue.empty())
    {
      testGen = test->execute(start.getNode(), context);
      DagNode* testResult = testGen->findNextSolution();
      if (testResult == 0)
	{
	  delete testGen;
	  testGen = 0;
	  genQueue.push_back(failure->execute(start.getNode(), context));
	}
      else
	{
	  genQueue.push_back(success->execute(testResult, context));
	  genQueue.push_back(0);  // dummy as marker for testGen
	}
    }

  do
    {
      SetGenerator* g = genQueue.front();
      genQueue.pop_front();
      if (g == 0)
	{
	  //
	  //	If it's the dummy generators turn, it means we need to
	  //	interleave a run of the test generator.
	  //
	  DagNode* testResult = testGen->findNextSolution();
	  if (testResult == 0)
	    {
	      delete testGen;
	      testGen = 0;
	      continue;
	    }
	  genQueue.push_back(0);  // requeue dummy
	  g = success->execute(testResult, context);
	}
      DagNode* result = g->findNextSolution();
      if (result != 0)
	{
	  genQueue.push_back(g);
	  return result;
	}
      delete g;
    }
  while (!genQueue.empty());
  return 0;
}
