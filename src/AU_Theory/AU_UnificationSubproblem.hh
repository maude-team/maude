/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2014 SRI International, Menlo Park, CA 94025, USA.

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
//      Class for unification subproblems in the A theory.
//
#ifndef _AU_UnificationSubproblem_hh_
#define _AU_UnificationSubproblem_hh_
//#include <list>
#include "unificationSubproblem.hh"
#include "simpleRootContainer.hh"
#include "natSet.hh"
#include "dagNode.hh"
#include "substitution.hh"
#include "pendingUnificationStack.hh"
#include "sequenceAssignment.hh"

class AU_UnificationSubproblem : public UnificationSubproblem, private SimpleRootContainer
{
  NO_COPYING(AU_UnificationSubproblem);

public:
  AU_UnificationSubproblem(AU_Symbol* topSymbol);
  ~AU_UnificationSubproblem();

  void addUnification(DagNode* lhs, DagNode* rhs, bool marked, UnificationContext& solution);
  bool solve(bool findFirst, UnificationContext& solution, PendingUnificationStack& pending);

private:
  struct Unification
  {
    DagNode* lhs;
    DagNode* rhs;
    SequenceAssignment* problem;
  };

  void markReachableNodes();
  bool checkAndInsertVariable(VariableDagNode* variable, UnificationContext& solution, NatSet& seenVariableIndices);
  bool checkArgumentList(AU_DagNode* dagNode, UnificationContext& solution, NatSet& seenVariableIndices);
  bool checkForCollapseAndNonLinearVariables(UnificationContext& solution);

  int findUpperBound(DagNode* d, UnificationContext& solution);
  bool findNextSolution(bool findFirst);
  bool buildSolution(UnificationContext& solution, PendingUnificationStack& pending);
  bool buildSolution(const Unification& unification, UnificationContext& solution, PendingUnificationStack& pending);
  bool resolve(DagNode* subterm, const Vector<DagNode*>& freshVariables, UnificationContext& solution, PendingUnificationStack& pending);

  //
  //	New algorithm.
  //
  bool hasArgumentBoundInTheory(AU_DagNode* target, UnificationContext& solution);
  AU_DagNode* flatten(int index, AU_DagNode* target, UnificationContext& solution);
  bool interflattenBindings(UnificationContext& solution);
  bool simplify(UnificationContext& solution, PendingUnificationStack& pending);
  bool purifyAndBind(VariableDagNode* variable, AU_DagNode* target, UnificationContext& solution, PendingUnificationStack& pending);
  void handleNonlinearVariable(VariableDagNode* v);
  void computeBounds(UnificationContext& solution);
  bool constrained(AU_DagNode* target, UnificationContext& solution);
  void updateBounds(int freshVariableIndex, int bound);

  void dump(UnificationContext& solution);
  void makeSequenceAssignmentProblems(UnificationContext& solution);
  bool flattenUnifications(UnificationContext& solution);
  AU_DagNode* flattenDag(AU_DagNode* target, UnificationContext& solution, NatSet& seenVariables);



  AU_Symbol* const topSymbol;
  Vector<Unification> unifications;
  //
  //	For keeping track of variables bounds. We only track representative variables.
  //
  Vector<int> bounds;
  //
  //	For backtracking.
  //
  Substitution preSolveSubstitution;
  Substitution savedSubstitution;
  PendingUnificationStack::Marker preSolveState;
  PendingUnificationStack::Marker savedPendingState;
};

#endif
