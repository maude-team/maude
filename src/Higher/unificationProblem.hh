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
//	Class for searching for order-sorted unifiers.
//
#ifndef _unificationProblem_hh_
#define _unificationProblem_hh_
#include "variableInfo.hh"
#include "substitution.hh"
#include "simpleRootContainer.hh"

class UnificationProblem : public VariableInfo, private SimpleRootContainer
{
  NO_COPYING(UnificationProblem);

public:
  UnificationProblem(Vector<Term*>& lhs, Vector<Term*>& rhs, FreshVariableGenerator* freshVariableGenerator, bool withExtension = false);
  ~UnificationProblem();

  bool variablesOK() const;
  bool findNextUnifier();
  const Substitution& getSolution() const;
  int getNrFreeVariables() const;
  DagNode* makeContext(DagNode* filler) const;
  ExtensionInfo* getExtensionInfo() const;
  const Vector<Term*>& getLeftHandSides() const;

private:
  void markReachableNodes();
  void findOrderSortedUnifiers();
  bool extractUnifier();
  bool explore(int index);

  Vector<Term*> leftHandSides;
  Vector<Term*> rightHandSides;
  FreshVariableGenerator* freshVariableGenerator;

  const SortBdds* sortBdds;
  Vector<DagNode*> leftHandDags;
  Vector<DagNode*> rightHandDags;

  ExtensionInfo* extensionInfo;
  UnificationContext* unsortedSolution;
  Subproblem* subproblem;
  bool varsOK;
  bool viable;
  Vector<int> freeVariables;
  AllSat* orderSortedUnifiers;
  Substitution* sortedSolution;
  //
  //	Stuff for resolving dependencies in solved form.
  //
  Vector<int> order;
  NatSet done;
  NatSet pending;
};

inline bool
UnificationProblem::variablesOK() const
{
  return varsOK;
}

inline const Substitution&
UnificationProblem::getSolution() const
{
  return *sortedSolution;
}

inline int
UnificationProblem::getNrFreeVariables() const
{
  return freeVariables.size();
}

inline ExtensionInfo*
UnificationProblem::getExtensionInfo() const
{
  return extensionInfo;
}

inline const Vector<Term*>&
UnificationProblem::getLeftHandSides() const
{
  return leftHandSides;
}

#endif
