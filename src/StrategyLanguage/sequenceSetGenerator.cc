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
#include "sequenceSetGenerator.hh"
#include "strategyExpression.hh"

SequenceSetGenerator::SequenceSetGenerator(DagNode* start,
					   RewritingContext& context,
					   const Vector<StrategyExpression*>& strategies)
  : context(context),
    strategies(strategies),
    genStack(0, strategies.size())
{
  genStack.append(strategies[0]->execute(start, context));
}

SequenceSetGenerator::~SequenceSetGenerator()
{
  int nrGenerators = genStack.size();
  for (int i = 0; i < nrGenerators; ++i)
    delete genStack[i];
}

DagNode*
SequenceSetGenerator::findNextSolution()
{
  int current = genStack.size();
  if (current == 0)
    return 0;
  --current;

  int nrStrategies = strategies.size();
  for (;;)
    {
      DagNode* subject = genStack[current]->findNextSolution();
      if (subject == 0)
	{
	  delete genStack[current];
	  genStack.contractTo(current);
	  if (current == 0)
	    break;
	  --current;
	}
      else
	{
	  ++current;
	  if (current == nrStrategies)
	    return subject;
	  genStack.append(strategies[current]->execute(subject, context));
	}
    }
  return 0;
}
