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
//#include "ACU_ExtensionInfo.hh"
#include "ACU_UnificationSubproblem.hh"

ACU_UnificationSubproblem::ACU_UnificationSubproblem(ACU_Symbol* topSymbol,
						     const Vector<DagNode*>& subterms)
  : topSymbol(topSymbol),
    subterms(subterms),
    savedSubstitution(0)
{
  generatedSubproblem = 0;
}

ACU_UnificationSubproblem::~ACU_UnificationSubproblem()
{
  delete generatedSubproblem;
}

void
ACU_UnificationSubproblem::markReachableNodes()
{
  //  cout << this << endl;
  int nrFragile = savedSubstitution.nrFragileBindings();
  //  cout << "nrFragile = " << nrFragile << endl;
  for (int i = 0; i < nrFragile; i++)
    {
      //      cout << i << endl;
      DagNode* d = savedSubstitution.value(i);
      if (d != 0)
	{
	  //	  cout << d << endl;
	  d->mark();
	}
    }
}

void
ACU_UnificationSubproblem::addBasisElement(MpzSystem::IntVec element)
{
  Assert(element.size() == subterms.size(), "bad element size");
  
  basis.push_front(Entry());
  Entry& e = basis.front();
  e.remainder = accumulator;
  int nrSubterms = subterms.size();
  e.element.resize(nrSubterms);
  for (int i = 0; i < nrSubterms; ++i)
    {
      if ((e.element[i] = element[i].get_si()))
	accumulator.insert(i);
    }
}

bool
ACU_UnificationSubproblem::coverable() const
{
  int nrSubterms = subterms.size();
  for (int i = 0; i < nrSubterms; ++i)
    {
      if (!(accumulator.contains(i)))
	return false;
    }
  return true;
}

bool
ACU_UnificationSubproblem::unificationSolve(bool findFirst, UnificationContext& solution)
{
  int nrSubterms = subterms.size();
  //for (int i = 0; i < nrSubterms; ++i)
  //  cout << subterms[i] << '\t';
  //cout << endl;

  if (findFirst)
    {
      savedSubstitution.clone(solution);
      /*
      cout << this << endl;
      int nrFragile = savedSubstitution.nrFragileBindings();
      cout << "2-nrFragile = " << nrFragile << endl;
      for (int i = 0; i < nrFragile; i++)
	{
	  cout << i << " ";
	  DagNode* d = savedSubstitution.value(i);
	  if (d != 0)
	    cout << d;
	  cout << endl;
	}
      */
      initialize(solution);
    }
  else
    {
      if (generatedSubproblem != 0 &&
	  generatedSubproblem->unificationSolve(false, solution))
	return true;
      delete generatedSubproblem;
      generatedSubproblem = 0;
      solution.clone(savedSubstitution);
    }

  //int counter = 1;
  while (nextSelection(findFirst))
    {
      findFirst = false;
      //cout << "selection " << counter++ << endl;
      int selectionSize = selection.size();
      //for (int i = 0; i < selectionSize; ++i)
      //	{
      //	  for (int j = 0; j < nrSubterms; ++j)
      //	    cout << selection[i]->element[j] << '\t';
      //	  cout << endl;
      //	}
      if (buildSolution(solution) &&
	  (generatedSubproblem == 0 || generatedSubproblem->unificationSolve(true, solution)))
	return true;
      delete generatedSubproblem;
      generatedSubproblem = 0;
      solution.clone(savedSubstitution);
    }
  return false;
}

bool
ACU_UnificationSubproblem::buildSolution(UnificationContext& solution)
{
  //
  //	First we allocate a fresh variable for each basis element selected.
  //
  ConnectedComponent* component = topSymbol->rangeComponent();
  int selectionSize = selection.size();
  Vector<DagNode*> freshVariables(selectionSize);
  for (int i = 0; i < selectionSize; ++i)
    freshVariables[i] = solution.makeFreshVariable(component);
  //
  //	Now for each abstracted subterm we unify it against its solution in
  //	the purified problem.
  //
  SubproblemAccumulator subproblems;
  int nrSubterms = subterms.size();
  for (int i = 0; i < nrSubterms; ++i)
    {
      int nrElements = 0;
      int lastElement = NONE;
      for (int j = 0; j < selectionSize; ++j)
	{
	  if (selection[j]->element[i] > 0)
	    {
	      ++nrElements;
	      lastElement = j;
	    }
	}
      Assert(nrElements > 0, "empty solution");
      DagNode* d;
      if (nrElements == 1 && selection[lastElement]->element[i] == 1)
	d = freshVariables[lastElement];
      else
	{
	  ACU_DagNode* a = new ACU_DagNode(topSymbol, nrElements);
	  int pos = 0;
	  for (int j = 0; j < selectionSize; ++j)
	    {
	      int m = selection[j]->element[i];
	      if (m > 0)
		{
		  a->argArray[pos].dagNode = freshVariables[j];
		  a->argArray[pos].multiplicity = m;
		  ++pos;
		}
	    }
	  a->dumbNormalizeAtTop();  // UGLY!
	  Assert(a->isTree() == false, "Oops we got a tree! " << a);
	  d = a;
	}
      //cout << subterms[i] << " =? " << d << endl;
      Subproblem* returnedSubproblem;
      if (!(subterms[i]->computeSolvedForm(d, solution, returnedSubproblem)))
	return false;
      subproblems.add(returnedSubproblem);
    }
  generatedSubproblem = subproblems.extractSubproblem();
  return true;
}

bool
ACU_UnificationSubproblem::nextSelection(bool findFirst)
{
  int nrSubterms = subterms.size();
  if (findFirst)
    { 
      current = basis.begin();
    forward:
      //
      //	We keep adding basis elements to the selection as long as they don't violate
      //	an upper bound. When we do hit a violation, if we find that a covering is
      //	not possible without this element we backtrack.
      //
      for (; current != basis.end(); ++current)
	{
	  if (includable(current))
	    {
	      for (int i = 0; i < nrSubterms; ++i)
		{
		  if (int v = current->element[i])
		    {
		      totals[i] += v;
		      uncovered.subtract(i);
		    }
		}
	      selection.append(current);
	    }
	  else
	    {
	      if (!(current->remainder.contains(uncovered)))
		goto backtrack;
	    }
	}
      Assert(uncovered.empty(), "failed to cover");
      return true;
    }
  else
    {
    backtrack:
      //
      //	We backtrack by removing basis elements from the current selection. Each time
      //	we remove an element, if we can still get a covering with later elements we
      //	start forward again.
      //
      Assert(selection.size() > 0, "backtracking over empty selection");
      for (int i = selection.size() - 1; i >= 0; --i)
	{
	  current = selection[i];
	  for (int j = 0; j < nrSubterms; ++j)
	    {
	      if ((totals[j] -= current->element[j]) == 0)
		uncovered.insert(j);
	    }
	  if (current->remainder.contains(uncovered))
	    {
	      ++current;
	      selection.resize(i);
	      goto forward;
	    }
	}
    }
  return false;
}

bool
ACU_UnificationSubproblem::includable(Basis::const_iterator potential)
{
  int nrSubterms = subterms.size();
  for (int i = 0; i < nrSubterms; ++i)
    {
      if (totals[i] + potential->element[i] > upperBounds[i])
	return false;
    }
  return true;
}

void
ACU_UnificationSubproblem::initialize(UnificationContext& solution)
{
  int nrSubterms = subterms.size();
  totals.resize(nrSubterms);
  upperBounds.resize(nrSubterms);
  for (int i = 0; i < nrSubterms; ++i)
    {
      uncovered.insert(i);
      totals[i] = 0;
      DagNode* d = subterms[i];
      if (VariableDagNode* v = dynamic_cast<VariableDagNode*>(d))
	{
	  DagNode* b = solution.value(v->lastVariableInChain(solution)->getIndex());
	  upperBounds[i] = (b != 0 && b->symbol() != topSymbol) ? 1 :  // bound to alien
	    topSymbol->sortBound(static_cast<VariableSymbol*>(v->symbol())->getSort());
	}
      else
	upperBounds[i] = 1;  // non-variable alien
    }
}
