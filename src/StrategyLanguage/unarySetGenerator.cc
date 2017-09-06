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
//      Implementation for class UnarySetGenerator.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "strategyLanguage.hh"

//	strategy language class definitions
#include "unarySetGenerator.hh"
#include "strategyExpression.hh"

UnarySetGenerator::UnarySetGenerator(DagNode* start,
				     RewritingContext& context,
				     StrategyExpression* test,
				     UnaryStrategy::StrategyType type)
  : start(start),
    context(context),
    test(test),
    type(type)
{
  testGen = 0;
  first = true;
}

UnarySetGenerator::~UnarySetGenerator()
{
  delete testGen;
}

DagNode*
UnarySetGenerator::findNextSolution()
{
  if (first)
    testGen = test->execute(start.getNode(), context);
  else
    {
      if (!testGen)
	return 0;
    }

  switch (type)
    {
    case UnaryStrategy::NOT:
      {
	Assert(first, "not first");
	DagNode* testResult = testGen->findNextSolution();
	delete testGen;
	testGen = 0;
	first = false;
	if (!testResult)
	  return start.getNode();
	break;
      }
    case UnaryStrategy::TEST:
      {
	Assert(first, "not first");
	DagNode* testResult = testGen->findNextSolution();
	delete testGen;
	testGen = 0;
	first = false;
	if (testResult)
	  return start.getNode();
	break;
      }
    case UnaryStrategy::TRY:
      {
	DagNode* testResult = testGen->findNextSolution();
	if (!testResult)
	  {
	    delete testGen;
	    testGen = 0;
	    if (first)
	      testResult = start.getNode();
	  }
	first = false;
	return testResult;
      }
    default:
      CantHappen("bad type");
    }
  return 0;
}
