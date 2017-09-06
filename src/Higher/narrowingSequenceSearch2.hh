/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2017 SRI International, Menlo Park, CA 94025, USA.

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
//	Class for breadth-first searching for sequences of narrowing steps using variant unification.
//
#ifndef _narrowingSequenceSearch2_hh_
#define _narrowingSequenceSearch2_hh_
#include "sequenceSearch.hh"
#include "narrowingSearchState2.hh"
#include "dagRoot.hh"

class NarrowingSequenceSearch2 : public SequenceSearch
{
  NO_COPYING(NarrowingSequenceSearch2);

public:
  //
  //	We take responsibility for protecting goal and deleting initial and freshVariableGenerator.
  //
  NarrowingSequenceSearch2(RewritingContext* initial,
			   SearchType searchType,
			   DagNode* goal,
			   int label,
			   int maxDepth,
			   int narrowingFlags,
			   FreshVariableGenerator* freshVariableGenerator,
			   int incomingVariableFamily);
  ~NarrowingSequenceSearch2();

  bool findNextUnifier();
  DagNode* getStateDag() const;
  int getStateVariableFamily() const;
  const Vector<DagNode*>* getUnifier() const;
  int getUnifierVariableFamily() const;
  const NarrowingVariableInfo& getVariableInfo() const;

  RewritingContext* getContext() const;
  bool isIncomplete() const;

private:
  bool allVariablesBelongToIncomingFamily(const NarrowingVariableInfo& variableInfo);
  bool findNextInterestingState();
  bool findNextNormalForm();

  struct ReachedDag
  {
    RewritingContext* reducedDagContext;
    int variableFamily;
  };

  typedef Vector<ReachedDag> Frontier;
  //
  //	Initial stuff.
  //
  RewritingContext* initial;
  DagRoot goal;
  const int label;
  const int maxDepth;
  const int narrowingFlags;
  FreshVariableGenerator* freshVariableGenerator;
  int incomingVariableFamily;
  bool needToTryInitialState;
  bool normalFormNeeded;
  Symbol* unificationPairSymbol;
  //
  //	State of search.
  //
  NarrowingSearchState2* stateBeingExpanded;
  Frontier currentFrontier;
  Frontier nextFrontier;
  int nextToExpand;
  int currentDepth;
  bool expansionSuccessful;
  bool expansionFinished;
  //
  //	Final variant unification between goal and state.
  //
  VariantSearch* unificationProblem;
  const Vector<DagNode*>* currentUnifier;
  int nrFreeVariablesInUnifier;
  int variableFamilyInUnifier;

  bool incompleteFlag;
};

inline const Vector<DagNode*>*
NarrowingSequenceSearch2::getUnifier() const
{
  return currentUnifier;
}

inline int
NarrowingSequenceSearch2::getUnifierVariableFamily() const
{
  return variableFamilyInUnifier;
}

inline DagNode*
NarrowingSequenceSearch2::getStateDag() const
{
  const ReachedDag& state = normalFormNeeded ? currentFrontier[nextToExpand - 1] : nextFrontier[nextFrontier.size() - 1];
  return state.reducedDagContext->root();
}

inline int
NarrowingSequenceSearch2::getStateVariableFamily() const
{
  const ReachedDag& state = normalFormNeeded ? currentFrontier[nextToExpand - 1] : nextFrontier[nextFrontier.size() - 1];
  return state.variableFamily;
}

inline const NarrowingVariableInfo&
NarrowingSequenceSearch2::getVariableInfo() const
{
  return unificationProblem->getVariableInfo();
}

inline RewritingContext*
NarrowingSequenceSearch2::getContext() const
{
  return initial;
}

inline bool
NarrowingSequenceSearch2::isIncomplete() const
{
  //
  //	Returns true if any incompleteness has been encountered so far.
  //
  return incompleteFlag;
}

#endif
