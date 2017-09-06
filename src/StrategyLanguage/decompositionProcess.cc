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
//      Implementation for abstract class StrategicTask.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "strategyLanguage.hh"

//	strategy language class definitions
#include "decompositionProcess.hh"
#include "strategyExpression.hh"

DecompositionProcess::DecompositionProcess(DagNode* start,
					   StrategyExpression* strategy,
					   StrategicExecution* taskSibling,
					   StrategicProcess* other)
  : StrategicProcess(taskSibling, other),
    dag(start)
{
  Assert(start != 0, "null dag");
  pending.push(strategy);
}

DecompositionProcess::DecompositionProcess(DagNode* dag,
					   const StrategyStack& pending,
					   StrategicExecution* taskSibling,
					   StrategicProcess* other)
  : StrategicProcess(taskSibling, other),
    dag(dag),
    pending(pending)
{
  Assert(dag != 0, "null dag");
}

DecompositionProcess::DecompositionProcess(DecompositionProcess* original)
  : StrategicProcess(original, original),
    dag(original->dag),
    pending(original->pending)
{
  //
  //	A copy of a process will be owned by same task as original and will
  //	get put in the process queue just ahead of original. It will share
  //	dag and get a copy of the pending stack.
  //
}

StrategicExecution::Survival
DecompositionProcess::run(StrategicSearch& searchObject)
{
  //cout << "DecompositionProcess::run(): pending.size() = " <<  pending.size() << endl;
  if (pending.empty())
    {
      //
      //	Report our success.
      //
      succeeded(dag, this);
      //
      //	Request deletion.
      //
      return DIE;
    }
  StrategyExpression* s = pending.top();
  pending.pop();
  Survival r = s->decompose(searchObject, this);
  if (r == DIE)
    finished(this);
  return r;
}
