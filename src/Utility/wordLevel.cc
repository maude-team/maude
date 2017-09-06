/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2015 SRI International, Menlo Park, CA 94025, USA.

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
//      Implementation for class WordSystem.
//
#include "macros.hh"
#include "vector.hh"
#include "wordLevel.hh"
#include "indent.hh"
#include "natSet.hh"

//	our stuff
#include "wordLevel-simplifyAssignments.cc"
#include "wordLevel-simplifyEquations.cc"

WordLevel::WordLevel(int nrVariables, int nrEquations)
  : constraintMap(nrVariables),
    partialSolution(nrVariables),
    unsolvedEquations(nrEquations)
{
  //
  //	Unbound variables must be bound to themselves; by default variables are unconstrained.
  //
  for (int i = 0; i < nrVariables; ++i)
    {
      partialSolution[i].append(i);
      constraintMap[i] = NONE;
    }
  chosenEquation = NOT_YET_CHOSEN;
  pigPug = 0;
  incompletenessFlag = 0;
}

WordLevel::~WordLevel()
{
  delete pigPug;
}

WordLevel::ResultPair
WordLevel::findNextPartialSolution()
{
  if (chosenEquation == NOT_YET_CHOSEN)
    {
      //
      //	Must be first call.
      //
      if (!simplify())
	return ResultPair(FAILURE, 0);  // occurs check failure or constraint clash during simplification
      //
      //	Need to chose an equation and create a PigPug.
      //
      chooseEquation();
      if (chosenEquation == NONE)
	return ResultPair(SUCCESS, 0);  // no equations left to solve
      makePigPug();
    }
  if (pigPug == 0)
    return ResultPair(FAILURE, 0);  // must have already returned the unique solution
  //
  //	Get next PigPug solution; create a new WordLevel.
  //	Because we used PigPug, we may have had to use an incomplete transformation
  //	and thus we need to OR in the incompleteness flag.
  //
  Subst unifier;
  int nextFreshVariable = pigPug->getNextUnifier(unifier);
  if (nextFreshVariable == NONE)
    return ResultPair(FAILURE | incompletenessFlag, 0);  // PigPug solutions exhausted

  WordLevel* next = makeNewLevel(unifier, nextFreshVariable);
  return ResultPair(SUCCESS | incompletenessFlag, next);
}

bool
WordLevel::simplify()
{
  //
  //	We start by simplifying the partial solution.
  //
  if (!fullyExpandAssignments())
    return false;
  //
  //	Then we simplify the equations until there is no change in the partial solution.
  //
  for (;;)
    {
      Result result = simplifyEquations();
      if (result == FAIL)
	return false;
      if (result == DONE)
	break;
    }
  return true;
}

WordLevel*
WordLevel::makeNewLevel(const Subst& unifier, int nextFreshVariable)
{
  //
  //	We have a PigPug solution - need to copy old stuff and new solution into a new WordLevel object.
  //
  int equationCount = 0;
  FOR_EACH_CONST(i, EquationVec, unsolvedEquations)
    {
      if (!(i->lhs.empty()))
	++equationCount;
    }
  WordLevel* newLevel = new WordLevel(nextFreshVariable, equationCount - 1);
  //
  //	Copy in old information and unifier.
  //
  int nrConstraints = constraintMap.size();
  for (int i = 0; i < nrConstraints; ++i)
    newLevel->addConstraint(i, constraintMap[i]);
  int nrVariables = partialSolution.size();
  for (int i = 0; i < nrVariables; ++i)
    {
      const Word& u = unifier[i];
      if (u.size() != 1 || u[0] != i)
	newLevel->addAssignment(i, u);
      else
	newLevel->addAssignment(i, partialSolution[i]);
    }
  int equationIndex = 0;
  int nrEquations = unsolvedEquations.size();
  for (int i = 0; i < nrEquations; ++i)
    {
      if (i != chosenEquation)
	{
	  Equation& e = unsolvedEquations[i];
	  if (!(e.lhs.empty()))
	    {
	      newLevel->addEquation(equationIndex, e.lhs, e.rhs);
	      ++equationIndex;
	    }
	}
    }
  return newLevel;
}

void
WordLevel::chooseEquation()
{
  //
  //	Chosen an unsolved equation and set chosenEquation to it true.
  //	If there are no unsolved equations set chosenEquation to NONE.
  //
  int firstUnsolved = NONE;
  int nrEquations = unsolvedEquations.size();
  for (int i = 0; i < nrEquations; ++i)
    {
      Equation& e = unsolvedEquations[i];
      if (!(e.lhs.empty()))
	{
	  //
	  //	Examine unconstrained variables.
	  //
	  NatSet lhsOccurs;
	  NatSet lhsNonlinear;
	  checkUnconstrainedVariables(e.lhs, lhsOccurs, lhsNonlinear);
	  NatSet rhsOccurs;
	  NatSet rhsNonlinear;
	  checkUnconstrainedVariables(e.rhs, rhsOccurs, rhsNonlinear);
	  if (lhsOccurs.disjoint(rhsOccurs))
	    {
	      if (lhsNonlinear.empty())
		{
		  chosenEquation = i;
		  return;
		}
	      if (rhsNonlinear.empty())
		{
		  //
		  //	Need to flip equation.
		  //
		  e.lhs.swap(e.rhs);
		  chosenEquation = i;
		  return;
		}
	    }
	  if (firstUnsolved == NONE)
	    firstUnsolved = i;
	}
    }
  if (firstUnsolved == NONE)
    {
      //
      //	We didn't see any unsolved equations.
      //
      chosenEquation = NONE;
      return;
    }
  //
  //	Didn't see an equation we could solved with PigPug.
  //	We take the first unsolved equation and add constraints to make it sovable with PigPug.
  //
  //IssueWarning("Associative unification encountered too hard an instance - may be incomplete");
  //dump(cout);
  incompletenessFlag = INCOMPLETE;
  Equation& e = unsolvedEquations[firstUnsolved];
  NatSet lhsOccurs;
  NatSet lhsNonlinear;
  checkUnconstrainedVariables(e.lhs, lhsOccurs, lhsNonlinear);
  NatSet rhsOccurs;
  NatSet rhsNonlinear;
  checkUnconstrainedVariables(e.rhs, rhsOccurs, rhsNonlinear);

  lhsOccurs.intersect(rhsOccurs);
  if (!(lhsOccurs.empty()))
    {
      //
      //	Any unconstrained variable that occurs on both sides must be constrained to be
      //	an element variable.
      //
      FOR_EACH_CONST(i, NatSet, lhsOccurs)
	constraintMap[*i] = PigPug::ELEMENT;
      //
      //	This may have also fixed any nonlinearity issue.
      //
      lhsNonlinear.subtract(lhsOccurs);
      rhsNonlinear.subtract(rhsOccurs);
    }
  //
  //	Flip equation if rhs has few nonlinear unconstrained variables.
  //
  if (rhsNonlinear.cardinality() < lhsNonlinear.cardinality())
    {
      e.lhs.swap(e.rhs);
      lhsNonlinear.swap(rhsNonlinear);
    }
  //
  //	Constrain nonlinear lhs variables.
  //
  FOR_EACH_CONST(i, NatSet, lhsNonlinear)
    constraintMap[*i] = PigPug::ELEMENT;
  //
  //	And now we have our chosen, hacked up equation.
  //
  chosenEquation = firstUnsolved;
}

void
WordLevel::checkUnconstrainedVariables(const Word& word, NatSet& occurs, NatSet& nonlinear)
{
  FOR_EACH_CONST(i, Word, word)
    {
      int index = *i;
      if (constraintMap[index] == NONE)
	{
	  if (occurs.contains(index))
	    nonlinear.insert(index);
	  else
	    occurs.insert(index);
	}
    }
}

void
WordLevel::makePigPug()
{
  Equation& e = unsolvedEquations[chosenEquation];
  int nrVariables = partialSolution.size();
  pigPug = new PigPug(e.lhs, e.rhs, constraintMap, nrVariables - 1, nrVariables);
}

void
WordLevel::dump(ostream& s, int indentLevel)
{
  s << Indent(indentLevel) << "begin{WordLevel}" << endl;
  {
    s << Indent(indentLevel + 1) << "constraintMap = " << endl;
    int nrVariables = constraintMap.size();
    for (int i = 0; i < nrVariables; ++i)
      {
	s << Indent(indentLevel + 2) << "X" << i << " : ";
	int c = constraintMap[i];
	if (c == PigPug::ELEMENT)
	  s << "ELEMENT";
	else if (c == NONE)
	  s << "NONE";
	else
	  s << "theory" << c;
	s << endl;
      }
  }
  {
    s << Indent(indentLevel + 1) << "partialSolution = " << endl;
    int nrVariables = partialSolution.size();
    for (int i = 0; i < nrVariables; ++i)
      {
	s << Indent(indentLevel + 2) << "x" << i << " |-> ";
	dumpWord(s, partialSolution[i]);
	s << endl;
      }
  }
  {
    s << Indent(indentLevel + 1) << "unsolvedEquations = " << endl;
    int nrEquations = unsolvedEquations.size();
    for (int i = 0; i < nrEquations; ++i)
      {
	s << Indent(indentLevel + 2) << "e" << i << " : ";
	if (unsolvedEquations[i].lhs.empty())
	  s << "(cancelled)" << endl;
	else
	  {
	    dumpWord(s, unsolvedEquations[i].lhs);
	    s << " =?  ";
	    dumpWord(s, unsolvedEquations[i].rhs);
	    s << endl;
	  }
      }
  }
}

void
WordLevel::dumpWord(ostream& s, const Word& word)
{
  FOR_EACH_CONST(i, Word, word)
    s << "x" << *i << " ";
}
