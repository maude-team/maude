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
//      Implementation for class ACU_Subproblem.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"
#include "diophantineSystem.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "ACU_Persistent.hh"
#include "ACU_Theory.hh"

//      interface class definitions
#include "argVec.hh"
#include "associativeSymbol.hh"
#include "dagNode.hh"
#include "subproblem.hh"

//      core class definitions
#include "variableInfo.hh"
#include "subproblemAccumulator.hh"
#include "unificationContext.hh"
#include "localBinding.hh"

//	variable class definitions
#include "variableSymbol.hh"
#include "variableDagNode.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_ExtensionInfo.hh"
#include "ACU_UnificationSubproblem.hh"
#include "ACU_UnificationWithExtensionSubproblem.hh"

ACU_UnificationWithExtensionSubproblem::ACU_UnificationWithExtensionSubproblem(ACU_DagNode* lhs, ACU_DagNode* rhs, ACU_ExtensionInfo* extensionInfo)
  : lhs(lhs),
    rhs(rhs),
    extensionInfo(extensionInfo)
{
  //cerr << "ACU_UnificationWithExtensionSubproblem " << lhs << " " << rhs << endl;
  int nrLhsArgs = lhs->argArray.length();
  int nrRhsArgs = rhs->argArray.length();
  rhsDups.resize(nrLhsArgs);
  handledByLhs.resize(nrRhsArgs);
  selection.resize(nrRhsArgs);
  multisetSize = 0;
  //
  //	Discover lhs arguments that are duplicated in the rhs by a merge style comparison.
  //
  int i = 0;
  int j = 0;
  for (;;)
    {
      int r;
      if (i == nrLhsArgs)
	{
	  if (j == nrRhsArgs)
	    break;
	  r = 1;
	}
      else
	r = (j == nrRhsArgs) ? -1 : lhs->argArray[i].dagNode->compare(rhs->argArray[j].dagNode);
      
      if (r < 0)
	{
	  rhsDups[i] = NONE;
	  ++i;
	}
      else
	{
	  if (r > 0)
	    handledByLhs[j] = false;
	  else
	    {
	      handledByLhs[j] = true;
	      rhsDups[i] = j;
	      ++i;
	    }
	  multisetSize += rhs->argArray[j].multiplicity;
	  ++j;
	}
    }
  extensionInfo->reset();  // we are responsible for setting extensionInfo
  generatedSubproblem = 0;
}

ACU_UnificationWithExtensionSubproblem::~ACU_UnificationWithExtensionSubproblem()
{
  delete generatedSubproblem;
}

bool
ACU_UnificationWithExtensionSubproblem::unificationSolve(bool findFirst, UnificationContext& solution)
{
  //cerr << "ACU_UnificationWithExtensionSubproblem::unificationSolve " << findFirst << endl;
  if (findFirst)
    {
      //
      //	Initialize multiset selection variables.
      //
      selectionDiff = multisetSize;  // everything needs to be allocated
      int nrRhsArgs = selection.size();
      for (int i = 0; i < nrRhsArgs; ++i)
	selection[i] = 0;
    }
  else
    {
      //
      //	If we are already in the process of solving a regular AC unification problem,
      //	try to find another solution.
      //
      if (generatedSubproblem != 0)
	{
	  if (generatedSubproblem->unificationSolve(false, solution))
	    return true;
	  delete generatedSubproblem;
	  generatedSubproblem = 0;
	}
    }

  for (;;)
    {
      //
      //	Try to find a selection with current size that gives rise to a soluble regular AC unification problem.
      //
      while (nextSelection())
	{
	  if (generateUnificationSubproblem(solution))
	    {
	      extensionInfo->setMatchedWhole(findFirst);
	      //cerr << "setMatchedWhole " << findFirst << endl;
	      if (!findFirst)
		fillOutExtensionInfo();
	      if (generatedSubproblem == 0 || generatedSubproblem->unificationSolve(true, solution))
		return true;
	      delete generatedSubproblem;
	      generatedSubproblem = 0;
	    }
	  findFirst = false;
	}
      --selectionDiff;
      if (selectionDiff < 2)
	break;
    }
  return false;
}

bool
ACU_UnificationWithExtensionSubproblem::generateUnificationSubproblem(UnificationContext& solution)
{
  Vector<DagNode*> abstracted;
  MpzSystem::IntVec multiplicities;
   //
  //	Insert lhs arguments.
  //
  int nrLhsArgs = rhsDups.size();
  for (int i = 0; i < nrLhsArgs; ++i)
    {
      int lhsMult = lhs->argArray[i].multiplicity;
      int dup = rhsDups[i];
      if (dup != NONE)
	{
	  lhsMult -= selection[dup];  // cancel with selected rhs arg
	  if (lhsMult == 0)
	    continue;
	}
      abstracted.append(lhs->argArray[i].dagNode);
      multiplicities.append(lhsMult);
    }
  //
  //	Insert rhs arguments.
  //
  int nrRhsArgs = selection.size();
  for (int i = 0; i < nrRhsArgs; ++i)
    {
      if (!handledByLhs[i])
	{
	  int rhsMult = selection[i];
	  if (rhsMult > 0)
	    {
	      abstracted.append(rhs->argArray[i].dagNode);
	      multiplicities.append(-rhsMult);
	    }
	}
    }
  //
  //	Check trivial cases.
  //
  int nrDioVars = multiplicities.size();
  if (nrDioVars == 0)
     return true;  // selection cancelled with lhs
  if (nrDioVars == 1)
    return false;  // trivial failure
  //
  //	Build Diophanine system.
  //
  MpzSystem system;
  system.insertEqn(multiplicities);

  ACU_Symbol* s = lhs->symbol();
  MpzSystem::IntVec upperBounds(nrDioVars);
  for (int i = 0; i < nrDioVars; ++i)
    {
      DagNode* d = abstracted[i];
      if (VariableDagNode* v = dynamic_cast<VariableDagNode*>(d))
	{
	  DagNode* b = solution.value(v->lastVariableInChain(solution)->getIndex());
	  upperBounds[i] = (b != 0 && b->symbol() != s) ? 1 :  // bound to alien
	    s->sortBound(static_cast<VariableSymbol*>(v->symbol())->getSort());
	}
      else
	upperBounds[i] = 1;  // non-variable alien
    }
  system.setUpperBounds(upperBounds);
  //
  //	Solve Diopantine system and build ACU_UnificationSubproblem.
  //
  MpzSystem::IntVec dioSol;
  delete generatedSubproblem;  // just in case we were restarted part way through
  generatedSubproblem = new ACU_UnificationSubproblem(s, abstracted);
  while (system.findNextMinimalSolution(dioSol))
    generatedSubproblem->addBasisElement(dioSol);
  if (!(generatedSubproblem->coverable()))
    {
      delete generatedSubproblem;
      return false;
    }
  return true;      
}

void
ACU_UnificationWithExtensionSubproblem::fillOutExtensionInfo()
{
  int nrRhsArgs = selection.size();
  for (int i = 0; i < nrRhsArgs; ++i)
    extensionInfo->setUnmatched(i, rhs->argArray[i].multiplicity - selection[i]);
}

bool
ACU_UnificationWithExtensionSubproblem::nextSelection()
{
  if (selectionDiff == 0)
    {
      //
      //	Undo current selection until we can increase an allocation.
      //
      int nrRhsArgs = selection.size();
      for (int i = 0;; ++i)
	{
	  if (i == nrRhsArgs)
	    return false;
	  int current = selection[i];
	  if (selectionDiff > 0 && current < rhs->argArray[i].multiplicity)
	    {
	      selection[i] = current + 1;
	      --selectionDiff;
	      break;
	    }
	  selection[i] = 0;
	  selectionDiff += current;
	}
      if (selectionDiff == 0)
	return true;
    }
  //
  //	Find earliest way of allocating selectionDiff.
  //
  for (int i = 0;; ++i)
    {
      int multiplicity = rhs->argArray[i].multiplicity;
      if (selectionDiff > multiplicity)
	{
	  selection[i] = multiplicity;
	  selectionDiff -= multiplicity;
	}
      else
	{
	  selection[i] = selectionDiff;
	  selectionDiff = 0;
	  break;
	}
    }
  return true;
}
