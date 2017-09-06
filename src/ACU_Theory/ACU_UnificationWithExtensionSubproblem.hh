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
//      Class for unification with extension subproblems in the AC theory.
//	We look at all selections of size >= 2 from the rhs multiset and form
//	regular AC unification subproblems.
//
#ifndef _ACU_UnificationnWithExtensionSubproblem_hh_
#define _ACU_UnificationnWithExtensionSubproblem_hh_
#include "subproblem.hh"

class ACU_UnificationWithExtensionSubproblem : public Subproblem
{
  NO_COPYING(ACU_UnificationWithExtensionSubproblem);

public:
  ACU_UnificationWithExtensionSubproblem(ACU_DagNode* lhs, ACU_DagNode* rhs, ACU_ExtensionInfo* extensionInfo);
  ~ACU_UnificationWithExtensionSubproblem();

  bool unificationSolve(bool findFirst, UnificationContext& solution);

#ifdef DUMP
  //void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  bool generateUnificationSubproblem(UnificationContext& solution);
  void fillOutExtensionInfo();
  bool nextSelection();

  ACU_DagNode* lhs;			// left hand side as passed during construction
  ACU_DagNode* rhs;			// right hand side as passed during construction
  ACU_ExtensionInfo* extensionInfo;	// extension info to fill out
  Vector<int> rhsDups;  		// NONE or index of duplicate in rhs
  Vector<bool> handledByLhs;  		// true if this argument has a duplicate in the lhs
  int multisetSize;			// size of rhs multiset
  int selectionDiff;			// difference between size of current selection and wanted size
  Vector<int> selection;		// current selection from rhs multiset
  ACU_UnificationSubproblem* generatedSubproblem;	// lhs vs current selection unification problem
};

#endif
