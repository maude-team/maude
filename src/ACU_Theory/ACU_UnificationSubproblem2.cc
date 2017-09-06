/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2008 SRI International, Menlo Park, CA 94025, USA.

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
#include "intSystem.hh"

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
#include "unificationContext.hh"
#include "localBinding.hh"

//	variable class definitions
#include "variableSymbol.hh"
#include "variableDagNode.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_UnificationSubproblem2.hh"

ACU_UnificationSubproblem2::ACU_UnificationSubproblem2(ACU_Symbol* topSymbol)
  : topSymbol(topSymbol),
    savedSubstitution(0),
    preSolveSubstitution(0)
{
#ifndef NO_ASSERT
  DebugAdvisory("Created ACU_UnificationSubproblem2() base " << ((void*) this) <<
		" for topSymbol " << topSymbol);
#endif
}


ACU_UnificationSubproblem2::~ACU_UnificationSubproblem2()
{
}

void
ACU_UnificationSubproblem2::markReachableNodes()
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
  //
  //	No need to mark preSolveSubstitution since it's dags are a subset of those in
  //	savedSubstitution.
  //
}

void
ACU_UnificationSubproblem2::addUnification(DagNode* lhs, DagNode* rhs)
{
  Assert(lhs->symbol() == topSymbol, "bad lhs dag " << lhs);
  Assert(topSymbol->getIdentity() != 0 || rhs->symbol() == topSymbol, "bad rhs dag " << rhs);

  ArgVec<ACU_DagNode::Pair> lhsArgs = safeCast(ACU_DagNode*, lhs)->argArray;
  multiplicities.clear();
  if (rhs->symbol() != topSymbol)
    {
      //
      //	Must be a theory clash problem f(...) = g(...) where f(...) is forced
      //	to collapse.
      //
      bool rhsIsOurId = topSymbol->getIdentity()->equal(rhs);
      if (!rhsIsOurId && !(rhs->symbol()->isStable()))
	{
	  //
	  //	Stable subterms always get an upperbound of 1 during classification
	  //	so we don't need to keep track of them here.
	  //
	  restrictedSubterms.append(rhs);
	}
      bool selfOccurs = false;
      FOR_EACH_CONST(i, ArgVec<ACU_DagNode::Pair>, lhsArgs)
	{
	  DagNode* d = i->dagNode;
	  if (rhs->equal(d))
	    {
	      //
	      //	f(..., g(...), ...) = g(...)
	      //
	      selfOccurs = true;
	      int diff = i->multiplicity - 1;
	      if (diff != 0)
		setMultiplicity(d, diff);
	    }
	  else
	    setMultiplicity(d, i->multiplicity);
	}
      if (!selfOccurs && !rhsIsOurId)
	setMultiplicity(rhs, -1);
    }
  else
    {
      ArgVec<ACU_DagNode::Pair> rhsArgs = safeCast(ACU_DagNode*, rhs)->argArray;
      int nrLhsArgs = lhsArgs.length();
      int nrRhsArgs = rhsArgs.length();
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
	    r = (j == nrRhsArgs) ? -1 : lhsArgs[i].dagNode->compare(rhsArgs[j].dagNode);
	  
	  if (r < 0)
	    {
	      setMultiplicity(lhsArgs[i].dagNode, lhsArgs[i].multiplicity);
	      ++i;
	    }
	  else if (r > 0)
	    {
	      setMultiplicity(rhsArgs[j].dagNode, - rhsArgs[j].multiplicity);
	      ++j;
	    }
	  else
	    {
	      int diff = lhsArgs[i].multiplicity - rhsArgs[j].multiplicity;
	      if (diff != 0)
		setMultiplicity(lhsArgs[i].dagNode, diff);
	      ++i;
	      ++j;
	    }      
	}
    }
  if (!multiplicities.empty())
    unifications.push_back(multiplicities);
}

void
ACU_UnificationSubproblem2::setMultiplicity(DagNode* dagNode, int multiplicity)
{
  int nrSubterms = subterms.size();
  int i = 0;
  for (;; ++i)
    {
      if (i == nrSubterms)
	{
	  subterms.append(dagNode);
	  break;
	}
      if (dagNode->equal(subterms[i]))
	break;
    }
  int nrMultiplicities = multiplicities.size();
  if (i >= nrMultiplicities)
    {
      multiplicities.resize(i + 1);
      for (int j = nrMultiplicities; j < i; ++j)
	multiplicities[j] = 0;
    }
  multiplicities[i] = multiplicity;
}

bool
ACU_UnificationSubproblem2::unsolve(int index, UnificationContext& solution)
{
  //
  //	We take a solved form X = f(...), turn it into a Diophantine equation and
  //	remove it from the current solution.
  //
  DagNode* variable = solution.getVariableDagNode(index);
  DagNode* value = solution.value(index);
  Assert(variable != 0, "couldn't get variable for index " << index << " bound to " << value);
  DebugAdvisory("### unsolving " << variable << " <- " << value);

  multiplicities.clear();
  ArgVec<ACU_DagNode::Pair> args = safeCast(ACU_DagNode*, value)->argArray;
  bool selfOccurs = false;
  FOR_EACH_CONST(i, ArgVec<ACU_DagNode::Pair>, args)
    {
      DagNode* d = i->dagNode;
      if (variable->equal(d))
	{
	  //
	  //	X = f(..., X, ...)
	  //
	  if (topSymbol->getIdentity() == 0)
	    return false;  // occur check fail
	  //
	  //	Might be satisfiable through collapse.
	  //
	  selfOccurs = true;
	  int diff = i->multiplicity - 1;
	  if (diff != 0)
	    setMultiplicity(d, diff);
	}
      else
	setMultiplicity(d, i->multiplicity);
    }
  if (!selfOccurs)
    setMultiplicity(variable, -1);
  unifications.push_back(multiplicities);
  solution.bind(index, 0);
  return true;
}

bool
ACU_UnificationSubproblem2::solve(bool findFirst, UnificationContext& solution, PendingUnificationStack& pending)
{
  if (subterms.empty())
    return findFirst;  // degenerate case where all unification problems cancelled
  if (findFirst)
    {
      //
      //	Save the current substitution
      //
      preSolveSubstitution.clone(solution);
      //
      //	Unsolve any solved forms that are in our theory. This seeming wasteful step
      //	has to be done in order to avoid nontermination.
      //
      int nrFragile = solution.nrFragileBindings();
      for (int i = 0; i < nrFragile; ++i)
	{
	  DagNode* value = solution.value(i);
	  if (value != 0 && value->symbol() == topSymbol)
	    {
	      if (!unsolve(i, solution))
		{
		  //
		  //	Restore current solution and fail.
		  //
		  solution.clone(preSolveSubstitution);
		  return false;
		}
	    }
	}

      if (!buildAndSolveDiophantineSystem(solution))
	{
	  //
	  //	Restore current solution and fail.
	  //
	  solution.clone(preSolveSubstitution);
	  return false;
	}
      //
      //	Save state of the pending stack with the substitution so that
      //	we can restore both in order to undo each of our solutions.
      //
      savedSubstitution.clone(solution);
      savedPendingState = pending.checkPoint();
    }
  else
    {
      //
      //	Restore pending stack and current substitution, implicitly deallocating
      //	any fresh variables we introduced.
      //
      pending.restore(savedPendingState);
      solution.clone(savedSubstitution);
    }
  while ((topSymbol->getIdentity() == 0) ? nextSelection(findFirst) : nextSelectionWithIdentity(findFirst))
    {
      findFirst = false;

      if (buildSolution(solution, pending))
	return true;
      //
      //	Restore pending stack and current substitution, implicitly deallocating
      //	any fresh variables we introduced.
      //
      pending.restore(savedPendingState);
      solution.clone(savedSubstitution);
    }
  solution.clone(preSolveSubstitution);
  return false;
}

void
ACU_UnificationSubproblem2::classify(UnificationContext& solution,
				     DagNode* subject,
				     bool& canTakeIdentity,
				     int& upperBound,
				     Symbol*& stableSymbol)
{
  //
  //	We classify a subject occuring on our top symbol.
  //	We chase variable chains and determine:
  //	(1) Is is possible that the subject can be unified against identity.
  //	(2) Can we determine an upperbound on how many other subjects could be unified against it.
  //	(3) Can we determine what it will only unify against something with a specific stable top symbol.
  //
  Term* identity = topSymbol->getIdentity();
  //
  //	We chase variable chains and accumuate the most restrictive settings over the sorts
  //	of all variables we encounter.
  //
  canTakeIdentity = (identity != 0);  // default: can unify with identity if it exists
  upperBound = UNBOUNDED;  // default: can unify with any number of subjects
  stableSymbol = 0;  // default: no stable symbol
  VariableDagNode* v;
  while ((v = dynamic_cast<VariableDagNode*>(subject)))
    {
      VariableSymbol* variableSymbol = safeCast(VariableSymbol*, v->symbol());
      Sort* variableSort = variableSymbol->getSort();
      int variableSortBound = topSymbol->sortBound(variableSort);
      if (variableSortBound < upperBound)
	upperBound = variableSortBound;
      canTakeIdentity = canTakeIdentity && topSymbol->takeIdentity(variableSort);
      subject = solution.value(v->getIndex());
      if (subject == 0)
	return;  // ended with unbound variable
    }
  Symbol* symbol = subject->symbol();
  DebugAdvisory("ACU_UnificationSubproblem2::classify() symbol = " << symbol <<
	        " symbol->isStable() = " << symbol->isStable());
  if (symbol != topSymbol)
    {
      if (symbol->isStable())
	{
	  //
	  //	Anything that unifies with subject must have symbol on top.
	  //
	  upperBound = 1;  // stable symbol can unify with at most one thing
	  canTakeIdentity = canTakeIdentity && (symbol == identity->symbol());
	  stableSymbol = symbol;
	}
      else
	{
	  FOR_EACH_CONST(i, Vector<DagNode*>, restrictedSubterms)
	    {
	      if (*i == subject)
		{
		  upperBound = 1;
		  break;
		}
	    }
	}
    }
}

bool
ACU_UnificationSubproblem2::buildAndSolveDiophantineSystem(UnificationContext& solution)
{
#ifndef NO_ASSERT
  DebugAdvisory("building DiophantineSystem for ACU_UnificationSubproblem2 " << ((void*) this));
#if 0
  for (int i = 0; i < subterms.length(); ++i)
  cerr << subterms[i] << '\t';
  cerr << endl;
#endif
#endif
  //
  //	Each distinct alien subdag from a unification problem that didn't get cancelled
  //	is represented by a Diophantine variable.
  //
  int nrDioVars = subterms.size();
  Assert(nrDioVars > 0, "shouldn't be called in degenerate case");
  if (nrDioVars == 1)
    return false;  // trivial failure
  //
  //	Create the Diophantine system.
  //
  IntSystem system(nrDioVars);
  FOR_EACH_CONST(i, list<Vector<int> >, unifications)
    system.insertEqn(*i);
  //
  //	Compute an upperbound on the assignment to each Diophantine variable.
  //
  upperBounds.resize(nrDioVars);  // for basis selection use
  IntSystem::IntVec upperBnds(nrDioVars);  // for Diophantine system use
  Vector<Symbol*> stableSymbols(nrDioVars);   // if we know we can only unify against a stable alien
  for (int i = 0; i < nrDioVars; ++i)
    {
      bool canTakeIdentity;
      int upperBound;
      classify(solution, subterms[i], canTakeIdentity, upperBound, stableSymbols[i]);
      DebugAdvisory("ACU_UnificationSubproblem2::buildAndSolveDiophantineSystem() i = " << i <<
		    " subterms[i] = " << subterms[i] <<
		    " canTakeIdentity = " << canTakeIdentity <<
		    " upperBound = " << upperBound);
		    
      if (!canTakeIdentity)
	needToCover.insert(i);  // can't take identity so mark as uncovered and be sure to cover
      upperBounds[i] = upperBound;
      upperBnds[i] = upperBound;
    }
  system.setUpperBounds(upperBnds);
  //
  //	Extract the basis.
  //
  Vector<int> dioSol;
  for (int index = 0; system.findNextMinimalSolution(dioSol);)
    {
#ifndef NO_ASSERT
      DebugAdvisory("added basis element for ACU_UnificationSubproblem2 " << ((void*) this));
#if 0
      for (int i = 0; i < dioSol.length(); ++i)
	cerr << dioSol[i] << '\t';
      cerr << endl;
#endif
#endif
      Symbol* existingStableSymbol = 0;
      for (int i = 0; i < nrDioVars; ++i)
	{
	  int t = dioSol[i];
	  if (t != 0)
	    {
	      Symbol* stableSymbol = stableSymbols[i];
	      if (stableSymbol != 0)
		{
		  //
		  //	We have a basis element that is going to force a term with a stable symbol to
		  //	unify with something.
		  //
		  if (existingStableSymbol == 0)
		    existingStableSymbol = stableSymbol;
		  else if (existingStableSymbol != stableSymbol)
		    {
		      //
		      //	Forced unification is guaranteed to fail.
		      //
		      DebugAdvisory("killing basis element, " << existingStableSymbol << " vs " << stableSymbol);
		      goto killElement;
		    }
		}
	    }
	}
      {
	basis.push_front(Entry());
	Entry& e = basis.front();
	e.remainder = accumulator;  // deep copy
	e.element.resize(nrDioVars);
	for (int i = 0; i < nrDioVars; ++i)
	  {
	    if ((e.element[i] = dioSol[i]) != 0)
	      accumulator.insert(i);  // subterm i is covered
	  }
	e.index = index;
	++index;
      }
    killElement:
      ;
    }
  //
  //	Check that each term that needs to be covered is covered by at least one basis element.
  //
  if (!accumulator.contains(needToCover))
    return false;
  //
  //	Initialize totals vector and uncovered set.
  //
  totals.resize(nrDioVars);
  for (int i = 0; i < nrDioVars; ++i)
    totals[i] = 0;
  uncovered = needToCover;
  return true;
}

bool
ACU_UnificationSubproblem2::nextSelection(bool findFirst)
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
ACU_UnificationSubproblem2::nextSelectionWithIdentity(bool findFirst)
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
	      selectionSet.insert(current->index);
	    }
	  else
	    {
	      if (!(current->remainder.contains(uncovered)))
		goto backtrack;
	    }
	}
      Assert(uncovered.empty(), "failed to cover");
      FOR_EACH_CONST(i, NatSetList, old)
	{
	  if (i->contains(selectionSet))
	    goto backtrack;
	}
      old.push_front(selectionSet);
      return true;
    }
  else
    {
    backtrack:
      //
      //	We backtrack by removing basis elements from the current selection. Each time
      //	we remove an element, if we can still get a covering with later elements we
      //	start forward again. Because the empty selection is valid in the
      //	identity case we can backtrack over it.
      //
      for (int i = selection.size() - 1; i >= 0; --i)
	{
	  current = selection[i];
	  for (int j = 0; j < nrSubterms; ++j)
	    {
	      if ((totals[j] -= current->element[j]) == 0 && needToCover.contains(j))
		uncovered.insert(j);
	    }
	  selectionSet.subtract(current->index);
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
ACU_UnificationSubproblem2::includable(Basis::const_iterator potential)
{
  int nrSubterms = subterms.size();
  for (int i = 0; i < nrSubterms; ++i)
    {
      if (totals[i] + potential->element[i] > upperBounds[i])
	return false;
    }
  return true;
}

bool
ACU_UnificationSubproblem2::buildSolution(UnificationContext& solution, PendingUnificationStack& pending)
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
      DagNode* d;
      if (nrElements == 0)
	{
	  d = topSymbol->getIdentityDag();
	  //
	  //	If this is the first time we use the identity element it is possible
	  //	that it will not have it's sort computed or ground flag set.
	  //
	  if (!(d->isGround()))
	    d->computeBaseSortForGroundSubterms();
	}
      else if (nrElements == 1 && selection[lastElement]->element[i] == 1)
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
	  //
	  //	There is no guarantee that the fresh variables that we generate are
	  //	is the same order as needed for AC normal form - so we call this
	  //	private member function to fix this without too much overhead.
	  //
	  a->sortAndUniquize();	  
	  Assert(a->isTree() == false, "Oops we got a tree! " << a);
	  d = a;
	}
      if (!(subterms[i]->computeSolvedForm(d, solution, pending)))
	return false;
    }
  return true;
}
