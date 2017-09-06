/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

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
//	Class for searching for single narrowing steps within a DAG.
//
#ifndef _narrowingSearchState_hh_
#define _narrowingSearchState_hh_
#include "positionState.hh"
#include "narrowingVariableInfo.hh"

class NarrowingSearchState : public PositionState
{
  NO_COPYING(NarrowingSearchState);

public:
  enum Flags
  {
    ALLOW_NONEXEC = 32
  };

  //
  //
  //	label may be UNDEFINED to make any rule usable.
  //
  //	maxDepth may be NONE to force at top narrowing steps without extension;
  //	otherwise narrowing is done with extension and maxDepth may be
  //	UNBOUNDED to indicate no bound.
  //
  //	FIXME: need to handle variable names and substitution slots
  //
  NarrowingSearchState(RewritingContext* context,
		       FreshVariableGenerator* freshVariableGenerator,
		       int label = UNDEFINED,
		       int flags = ALLOW_NONEXEC,
		       int minDepth = 0,
		       int maxDepth = UNBOUNDED);
  ~NarrowingSearchState();

  Rule* getRule() const;
  DagNode* getNarrowedDag() const;
  bool findNextNarrowing();
  const Substitution& getSubstitution() const;

private:
  FreshVariableGenerator* freshVariableGenerator;
  const int label;
  const bool withExtension;

  NarrowingVariableInfo variableInfo;

  int ruleIndex;  // index of current rule being tried

  NarrowingUnificationProblem* unificationProblem;
};

#endif
