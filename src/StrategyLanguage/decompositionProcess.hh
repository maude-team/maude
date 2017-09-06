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
//	Class for a process that tries to decompose a strategy to reach a leaf.
//
#ifndef _decompositionProcess_hh_
#define _decompositionProcess_hh_
#include "strategicProcess.hh"

class DecompositionProcess : public StrategicProcess
{
public:
  DecompositionProcess(DagNode* dag,
		       StrategyExpression* strategy,
		       StrategicExecution* taskSibling,
		       StrategicProcess* other);
  DecompositionProcess(DagNode* dag,
		       const StrategyStack& pending,
		       StrategicExecution* taskSibling,
		       StrategicProcess* other);
  //
  //	We can't pass const here because we need to touch original to
  //	handle double linking both on the task list and the process queue.
  //
  DecompositionProcess(DecompositionProcess* original);

  Survival run(StrategicSearch& searchObject);
  void pushStrategy(StrategyExpression* strategy);
  const StrategyStack& getPending() const;
  DagNode* getDag();


private:
  DagNode* const dag;
  StrategyStack pending;
};

inline void
DecompositionProcess::pushStrategy(StrategyExpression* strategy)
{
  pending.push(strategy);
}

inline const StrategicExecution::StrategyStack&
DecompositionProcess::getPending() const
{
  return pending;
}

inline DagNode*
DecompositionProcess::getDag()
{
  Assert(dag != 0, "null dag");
  return dag;
}

#endif
