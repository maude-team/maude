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
//      Implementation for class ACU_UnificationSubproblem2.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "AU_Persistent.hh"
#include "AU_Theory.hh"

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

//	AU theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"
#include "AU_UnificationSubproblem.hh"

#define FOR_EACH(var, conType, container) \
const conType::iterator var##_end = (container).end(); \
for (conType::iterator var = (container).begin(); var != var##_end; ++var)


AU_UnificationSubproblem::AU_UnificationSubproblem(AU_Symbol* topSymbol)
  : topSymbol(topSymbol),
    preSolveSubstitution(0),
    savedSubstitution(0)
{
}

AU_UnificationSubproblem::~AU_UnificationSubproblem()
{
  FOR_EACH_CONST(i, Vector<Unification>, unifications)
    delete i->problem;
}

void
AU_UnificationSubproblem::addUnification(DagNode* lhs, DagNode* rhs, bool marked, UnificationContext& solution)
{
  Assert(lhs->symbol() == topSymbol, "bad lhs dag " << lhs);
  Assert(topSymbol->hasIdentity() ||
	 rhs->symbol() == topSymbol ||
	 dynamic_cast<VariableDagNode*>(rhs) != 0, "bad rhs for for non-collapse theory " << rhs);
  Assert(topSymbol->hasIdentity() || !marked, "bad mark for non-collapse theory");

  int nrUnifications = unifications.size();
  unifications.expandTo(nrUnifications + 1);
  unifications[nrUnifications].lhs = lhs;
  unifications[nrUnifications].rhs = rhs;
  unifications[nrUnifications].problem = 0;
}

bool
AU_UnificationSubproblem::checkAndInsertVariable(VariableDagNode* variable, UnificationContext& solution, NatSet& seenVariableIndices)
{
  VariableDagNode* lv = variable->lastVariableInChain(solution);
  int index = lv->getIndex();
  if (seenVariableIndices.contains(index))
    {
      IssueWarning("Associative unification failing due to non-linear variable " <<
		   static_cast<DagNode*>(lv));
      return false;
    }
  if (solution.value(index) != 0)
    {
      IssueWarning("Associative unification failing due to variable " <<
		   static_cast<DagNode*>(lv) <<
		   " being already bound.");
      return false;
    }
  seenVariableIndices.insert(index);
  return true;
}

bool
AU_UnificationSubproblem::checkArgumentList(AU_DagNode* dagNode, UnificationContext& solution, NatSet& seenVariableIndices)
{
  int nrArgs = dagNode->argArray.length();
  for (int i = 0; i < nrArgs; ++i)
    {
      DagNode* subject = dagNode->argArray[i];
      if (VariableDagNode* v = dynamic_cast<VariableDagNode*>(subject))
	{
	  if (!(checkAndInsertVariable(v, solution, seenVariableIndices)))
	    return false;
	}
      else
	{
	  //
	  //	Must be an alien; need to check it for collapse.
	  //
	  if (!(subject->symbol()->isStable()))
	    {
	      IssueWarning("Associative unification failing due to subterm in collapse theory " << subject);
	      return false;
	    }
	}
    }
  return true;
}

bool
AU_UnificationSubproblem::checkForCollapseAndNonLinearVariables(UnificationContext& solution)
{
  NatSet seenVariableIndices;

  FOR_EACH(i, Vector<Unification>, unifications)
    {
      AU_DagNode* lhs = safeCast(AU_DagNode*, i->lhs);
      if (!(checkArgumentList(lhs, solution, seenVariableIndices)))
	return false;

      if (i->rhs->symbol() == topSymbol)
	{
	  AU_DagNode* rhs = safeCast(AU_DagNode*, i->rhs);
	  if (!(checkArgumentList(rhs, solution, seenVariableIndices)))
	    return false;
	}
      else
	{
	  VariableDagNode* rhs = safeCast(VariableDagNode*, i->rhs);
	  if (!(checkAndInsertVariable(rhs, solution, seenVariableIndices)))
	    return false;
	}
    }
  return true;
}

bool
AU_UnificationSubproblem::solve(bool findFirst, UnificationContext& solution, PendingUnificationStack& pending)
{
  if (findFirst)
    {
      if (!(checkForCollapseAndNonLinearVariables(solution)))
      	return false;
      //
      //	Save substituion and check point the pending stack because
      //	initial purification might introduce bindings or unification
      //	problems that must be retracted when we exit with failure.
      //
      preSolveSubstitution.clone(solution);
      preSolveState = pending.checkPoint();

      FOR_EACH(i, Vector<Unification>, unifications)
	{
	  AU_DagNode* lhs = safeCast(AU_DagNode*, i->lhs);
	  int nrLhsArgs = lhs->argArray.length();
	  if (i->rhs->symbol() == topSymbol)
	    {
	      //
	      //	Unification of the form f(...) =? f(...)
	      //
	      AU_DagNode* rhs = safeCast(AU_DagNode*, i->rhs);
	      int nrRhsArgs = rhs->argArray.length();
	      i->problem = new SequenceAssignment(nrLhsArgs, nrRhsArgs);

	      for (int j = 0; j < nrLhsArgs; ++j)
		{
		  int bound = findUpperBound(lhs->argArray[j], solution);
		  if (bound != NONE)
		    i->problem->setLhsBound(j, bound);
		}

	      for (int j = 0; j < nrRhsArgs; ++j)
		{
		  int bound = findUpperBound(rhs->argArray[j], solution);
		  if (bound != NONE)
		    i->problem->setRhsBound(j, bound);
		}
	    }
	  else
	    {
	      //
	      //	Unification of the form f(...) =? X with X unbound.
	      //	We purify f(...) and make the assignment.
	      //
	      DebugAdvisory("purifying assoc dag " << lhs);
	      ConnectedComponent* component = topSymbol->rangeComponent();
	      Vector<DagNode*> freshVariables(nrLhsArgs);
	      Vector<DagNode*> freshVariable(1);
	      for (int j = 0; j < nrLhsArgs; ++j)
		{
		  freshVariables[j] = freshVariable[0] = solution.makeFreshVariable(component);
		  resolve(lhs->argArray[j], freshVariable, solution, pending);
		}
	      resolve(i->rhs, freshVariables, solution, pending);
	    }
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
      solution.restoreFromClone(savedSubstitution);
    }

  while (findNextSolution(findFirst))
    {
      if (buildSolution(solution, pending))
	return true;
      //
      //	Restore pending stack and current substitution, implicitly deallocating
      //	any fresh variables we introduced.
      //
      pending.restore(savedPendingState);
      solution.restoreFromClone(savedSubstitution);
      findFirst = false;
    }
  //
  //	No more solutions; retract any unifications and bindings we created during purification.
  //
  pending.restore(preSolveState);
  solution.restoreFromClone(preSolveSubstitution);
  return false;
}

bool
AU_UnificationSubproblem::findNextSolution(bool findFirst)
{
  int nrUnifications = unifications.size();

  if (findFirst)
    {
      //
      //	Find a first solution for each problem.
      //
      for (int i = 0; i < nrUnifications; ++i)
	{
	  SequenceAssignment* problem = unifications[i].problem;
	  if (problem != 0 && !(problem->findNextSolution(true)))
	    return false;  // possible because of bounds
	}
      return true;
    }
  //
  //	Now backtrack, trying to find a problem that has a new solution.
  //
  for (int i = nrUnifications - 1; i >= 0; --i)
    {
      SequenceAssignment* problem = unifications[i].problem;
      if (problem != 0 && problem->findNextSolution(false))
	{
	  //
	  //	We know that each problem has at least one solution since we
	  //	made it to the backtrack case.
	  //
	  for (++i; i < nrUnifications; ++i)
	    {
	      SequenceAssignment* problem = unifications[i].problem;
	      if (problem != 0)
		(void) problem->findNextSolution(true);
	    }
	  return true;
	}
    }

  return false;
}

bool
AU_UnificationSubproblem::buildSolution(UnificationContext& solution, PendingUnificationStack& pending)
{
  FOR_EACH_CONST(i, Vector<Unification>, unifications)
    {
      if (!(buildSolution(*i, solution, pending)))
	return false;
    }
  return true;
}

bool
AU_UnificationSubproblem::buildSolution(const Unification& unification, UnificationContext& solution, PendingUnificationStack& pending)
{
  if (unification.problem == 0)
    return true;

  const SequenceAssignment::Solution& sol = unification.problem->getSolution();
  //
  //	First we allocate a fresh variable for each assignment between the lhs and rhs.
  //
  ConnectedComponent* component = topSymbol->rangeComponent();
  int nrFreshVariables = sol.size() + 1;
  Vector<DagNode*> freshVariables(nrFreshVariables);
  for (int i = 0; i < nrFreshVariables; ++i)
    freshVariables[i] = solution.makeFreshVariable(component);
  //
  //	Now we go through the solution generating bindings to lhs and rhs as we go.
  //
  Vector<DagNode*> lhsVars;
  Vector<DagNode*> rhsVars;
  int varNr = 0;
  int lhsArgNr = 0;
  int rhsArgNr = 0;

  AU_DagNode* lhs = safeCast(AU_DagNode*, unification.lhs);
  AU_DagNode* rhs = safeCast(AU_DagNode*, unification.rhs);

  lhsVars.append(freshVariables[0]);
  rhsVars.append(freshVariables[0]);
  FOR_EACH_CONST(i, SequenceAssignment::Solution, sol)
    {
      if (SequenceAssignment::leftDelta(*i))
	{
	  if (!(resolve(lhs->argArray[lhsArgNr], lhsVars, solution, pending)))
	    return false;
	  ++lhsArgNr;
	  lhsVars.clear();
	}
      if (SequenceAssignment::rightDelta(*i))
	{
	  if (!(resolve(rhs->argArray[rhsArgNr], rhsVars, solution, pending)))
	    return false;
	  ++rhsArgNr;
	  rhsVars.clear();
	}
      ++varNr;
      lhsVars.append(freshVariables[varNr]);
      rhsVars.append(freshVariables[varNr]);
    }
  return resolve(lhs->argArray[lhsArgNr], lhsVars, solution, pending) &&
    resolve(rhs->argArray[rhsArgNr], rhsVars, solution, pending);
}

bool
AU_UnificationSubproblem::resolve(DagNode* subterm, const Vector<DagNode*>& freshVariables, UnificationContext& solution, PendingUnificationStack& pending)
{
  DagNode* d;
  int nrVars = freshVariables.size();
  if (nrVars == 1)
    d = freshVariables[0];
  else
    {
      AU_DagNode* a = new AU_DagNode(topSymbol, nrVars);
      for (int i = 0; i < nrVars; ++i)
	a->argArray[i] = freshVariables[i];
      d = a;
    }

  if (VariableDagNode* varSubterm = dynamic_cast<VariableDagNode*>(subterm))
    {
      //
      //	We need to handle unbound variable subterms that we unify with something in our 
      //	theory ourself to avoid generating another problem in our theory.
      //
      VariableDagNode* repVar = varSubterm->lastVariableInChain(solution);
      if (solution.value(repVar->getIndex()) == 0)
	{
	  if (!(repVar->equal(d)))
	    solution.unificationBind(repVar, d);
	  return true;
	}
    }
  return subterm->computeSolvedForm(d, solution, pending);
}

int
AU_UnificationSubproblem::findUpperBound(DagNode* subject, UnificationContext& solution)
{
  //
  //	Compute an upper bound on what can be assign to subject in a A unification problem.
  //	We return NONE rather the UNBOUNDED if there is no bound.
  //
  if (VariableDagNode* v = dynamic_cast<VariableDagNode*>(subject))
    {
      VariableDagNode* lv = v->lastVariableInChain(solution);
      VariableSymbol* variableSymbol = safeCast(VariableSymbol*, lv->symbol());
      Sort* variableSort = variableSymbol->getSort();
      int variableSortBound = topSymbol->sortBound(variableSort);
      if (variableSortBound != UNBOUNDED)
	return variableSortBound;

      subject = solution.value(lv->getIndex());
      if (subject == 0)
	return NONE;

      DebugAdvisory("bound variable " << (DagNode*) lv << " << in assoc unification problem");
    }
  //
  //	We only support stable non-variable subterms.
  //
  Symbol* symbol = subject->symbol();
  if (!(symbol->isStable()))
    {
      DebugAdvisory("subject " << subject << " is unstable in assoc unification problem");
      return NONE;
    }
  return 1;
}

void
AU_UnificationSubproblem::markReachableNodes()
{
  //
  //	Protect dags in preSolveSubstitution.
  //
  int nrFragile = preSolveSubstitution.nrFragileBindings();
  for (int i = 0; i < nrFragile; i++)
    {
      DagNode* d = preSolveSubstitution.value(i);
      if (d != 0)
	d->mark();
    }
  //
  //	No need to mark  savedSubstitution since its dags are a subset of those in
  //	the current substitution.
  //
}
