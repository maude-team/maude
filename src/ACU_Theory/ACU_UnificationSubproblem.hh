/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2007 SRI International, Menlo Park, CA 94025, USA.

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
//      Class for unification subproblems in the AC theory.
//	It consists of the AC symbol, a vector of abstracted subterms and a basis for the
//	Diophantine system corresponding the purified AC unification problem.
//
#ifndef _ACU_UnificationSubproblem_hh_
#define _ACU_UnificationSubproblem_hh_
#include <list>
#include "subproblem.hh"
#include "simpleRootContainer.hh"
#include "mpzSystem.hh"
#include "natSet.hh"
#include "dagNode.hh"

class ACU_UnificationSubproblem : public Subproblem, private SimpleRootContainer
{
  NO_COPYING(ACU_UnificationSubproblem);

public:
  ACU_UnificationSubproblem(ACU_Symbol* topSymbol, const Vector<DagNode*>& subterms);
  ~ACU_UnificationSubproblem();

  bool unificationSolve(bool findFirst, UnificationContext& solution);

  void addBasisElement(MpzSystem::IntVec& element);
  bool coverable() const;

#ifdef DUMP
  //void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  struct Entry
  {
    Vector<int> element;	// practical basis elements will fit in 32-bit machine integers
    NatSet remainder;		// which subterms will be assigned by remaining elements
  };

  typedef list<Entry> Basis;

  void markReachableNodes();

  bool nextSelection(bool findFirst);
  bool includable(Basis::const_iterator potential);
  void initialize(UnificationContext& solution);
  bool buildSolution(UnificationContext& solution);

  ACU_Symbol* topSymbol;
  Vector<DagNode*> subterms;
  Basis basis;
  Subproblem* generatedSubproblem;

  NatSet accumulator;
  Vector<int> totals;
  Vector<int> upperBounds;
  NatSet uncovered;
  Vector<Basis::const_iterator> selection;
  Basis::const_iterator current;
  Substitution savedSubstitution;
};

#endif
