/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2016 SRI International, Menlo Park, CA 94025, USA.

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
//	Class for searching for single narrowing step using variant unification.
//
#ifndef _narrowingSearchState2_hh_
#define _narrowingSearchState2_hh_
#include "cacheableState.hh"
#include "positionState.hh"
#include "simpleRootContainer.hh"
#include "narrowingVariableInfo.hh"
#include "variantUnificationProblem.hh"

class NarrowingSearchState2 : public CacheableState, private SimpleRootContainer
{
  NO_COPYING(NarrowingSearchState2);

public:
  enum Flags
  {
    ALLOW_NONEXEC = 32,		// allow narrowing with nonexecutable rules, unbound variables being treated as fresh
  };
  //
  //
  //	label may be UNDEFINED to make any rule usable.
  //
  //	maxDepth may be NONE to force at top narrowing steps without extension;
  //	otherwise narrowing is done with extension and maxDepth may be
  //	UNBOUNDED to indicate no bound.
  //
  //	Takes over responsibility for deleting context and freshVariableGenerator on destruction.
  //
  NarrowingSearchState2(RewritingContext* context,
			const Vector<DagNode*>& blockerDags,
			FreshVariableGenerator* freshVariableGenerator,
			int incomingVariableFamily,
			int label = UNDEFINED,
			int flags = ALLOW_NONEXEC | PositionState::RESPECT_FROZEN,
			int minDepth = 0,
			int maxDepth = UNBOUNDED);
  ~NarrowingSearchState2();

  bool findNextNarrowing();
  //
  //	This is the original context we passed in.
  //
  RewritingContext* getContext() const;
  //
  //	This is either the original context, or a child context if we did
  //	a variable renaming.
  //
  RewritingContext* getActiveContext() const;
  //
  //	Get information about last narrowing step.
  //
  Rule* getRule() const;
  DagNode* getNarrowedDag(DagNode*& replacement) const;
  const Substitution& getSubstitution() const;
  const NarrowingVariableInfo& getVariableInfo() const;
  const NarrowingVariableInfo& getActiveVariableInfo() const;
  int getVariableFamily() const;
  bool isIncomplete() const;
  DagNode* getReplacedDag() const;

private:
  void markReachableNodes();
  bool allVariablesBelongToIncomingFamily();

  RewritingContext* const context;
  const Vector<DagNode*> blockerDags;
  FreshVariableGenerator* const freshVariableGenerator;
  const int incomingVariableFamily;
  const int label;
  Module* const module;
  //
  //	We keep two maps between substitution slots and variables.
  //	The first hold the original variables.
  //	The second is either emty or holds their renamings.
  //
  NarrowingVariableInfo variableInfo;
  NarrowingVariableInfo freshVariableInfo;
  //
  //	We might need to rename variables before we give the dag to
  //	PositionState to handle the traversal, we we can't have PositionState
  //	as a base class as we normally do.
  //
  PositionState *positionState;

  int ruleIndex;  // index of current rule being tried
  VariantUnificationProblem* unificationProblem;
  int variableFamily;
  RewritingContext* newContext;
  bool incompleteFlag;
};

inline RewritingContext*
NarrowingSearchState2::getContext() const
{
  return context;
}

inline RewritingContext*
NarrowingSearchState2::getActiveContext() const
{
  //
  //	If we didn't replace variables with fresh variables, this
  //	will be the same as context.
  //
  return newContext;
}

inline const NarrowingVariableInfo&
NarrowingSearchState2::getVariableInfo() const
{
  //
  //	We return the NarrowingVariableInfo containing the original
  //	variables, even if we renamed them to do the narrowing.
  //
  return variableInfo;
}

inline const NarrowingVariableInfo&
NarrowingSearchState2::getActiveVariableInfo() const
{
  //
  //	We return the NarrowingVariableInfo containing the variables actually
  //	used during the narrowing step - these may be fresh.
  //
  bool variablesReplaced = (freshVariableInfo.getNrVariables() != 0);
  return variablesReplaced ? freshVariableInfo : variableInfo;
}

inline bool
NarrowingSearchState2::isIncomplete() const
{
  //
  //	Returns true if any incompleteness has been encountered so far.
  //
  return incompleteFlag;
}

inline Rule*
NarrowingSearchState2::getRule() const
{
  return module->getRules()[ruleIndex];
}

inline int
NarrowingSearchState2::getVariableFamily() const
{
  return unificationProblem->getVariableFamily();
}

inline const Substitution&
NarrowingSearchState2::getSubstitution() const
{
  return unificationProblem->getSolution();
}

inline DagNode*
NarrowingSearchState2::getReplacedDag() const
{
  return positionState->getDagNode();
}

#endif
