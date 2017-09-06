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
//      Class for generators that apply a success or failure strategy, based on the
//	result of a test strategy.
//
#ifndef _branchSetGenerator_hh_
#define _branchSetGenerator_hh_
#include <list>
#include "dagRoot.hh"
#include "setGenerator.hh"

class BranchSetGenerator : public SetGenerator
{
public:
  BranchSetGenerator(DagNode* start,
		     RewritingContext& context,
		     StrategyExpression* test,
		     StrategyExpression* success,
		     StrategyExpression* failure);
  ~BranchSetGenerator();

  DagNode* findNextSolution();

private:
  typedef list<SetGenerator*> GenQueue;

  DagRoot start;
  RewritingContext& context;
  StrategyExpression* test;
  StrategyExpression* success;
  StrategyExpression* failure;
  SetGenerator* testGen;
  GenQueue genQueue;
};

#endif