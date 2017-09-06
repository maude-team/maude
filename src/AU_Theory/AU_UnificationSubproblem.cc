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
AU_UnificationSubproblem::hasArgumentBoundInTheory(AU_DagNode* target, UnificationContext& solution)
{
  int nrArgs = target->argArray.length();
  for (int i = 0; i < nrArgs; ++i)
    {
      DagNode* arg = target->argArray[i];
      if (VariableDagNode* v = dynamic_cast<VariableDagNode*>(arg))
	{
	  //
	  //	Argument is a variable - see if it is bound in theory.
	  //
	  VariableDagNode* lv = v->lastVariableInChain(solution);
	  int index = lv->getIndex();
	  DagNode* binding = solution.value(index);
	  if (binding != 0 && binding->symbol() == topSymbol)
	    return true;
	}
    }
  return false;
}

AU_DagNode*
AU_UnificationSubproblem::flatten(int index, AU_DagNode* target, UnificationContext& solution)
{
  Vector<DagNode*> flattenedArguments;
  //
  //	Flatten in arguments that are bound in theory. If we flatten in variable with given
  //	index, return null to indicate an occurrs check failure.
  //
  int nrArgs = target->argArray.length();
  for (int i = 0; i < nrArgs; ++i)
    {
      DagNode* arg = target->argArray[i];
      if (VariableDagNode* v = dynamic_cast<VariableDagNode*>(arg))
	{
	  //
	  //	Argument is a variable - see if it is bound in theory.
	  //
	  VariableDagNode* lv = v->lastVariableInChain(solution);
	  int argVarIndex = lv->getIndex();
	  Assert(argVarIndex != index, "variable " << arg <<
		 " is equivalent to variable with index " << index);  // binding should not contain an occurs check failure
	  DagNode* binding = solution.value(argVarIndex);
	  if (binding != 0 && binding->symbol() == topSymbol)
	    {
	      AU_DagNode* b = safeCast(AU_DagNode*, binding);
	      int nrArgs2 = b->argArray.length();
	      for (int j = 0; j < nrArgs2; ++j)
		{
		  DagNode* subArg = b->argArray[j];
		  if (VariableDagNode* v2 = dynamic_cast<VariableDagNode*>(subArg))
		    {
		      VariableDagNode* lv2 = v2->lastVariableInChain(solution);
		      if (lv2->getIndex() == index)
			{
			  DebugAdvisory("occur check failure while trying to purify " << static_cast<DagNode*>(target) <<
					" because of " << static_cast<DagNode*>(v) <<
					" bound to " << static_cast<DagNode*>(subArg) <<
					" containing " << static_cast<DagNode*>(v2));
			  return 0;
			}
		      flattenedArguments.append(lv2);  // variable in binding
		    }
		  else
		    {
		      CantHappen("non-variable " << subArg <<
				 " seen in binding " << binding <<
				 " for variable " << arg <<
				 " while flattening " << target);
		    }
		}
	    }
	  else
	    {
	      //
	      //	Either the variable is unbound or bound to an alien. Either way it is good as it is.
	      //
	      flattenedArguments.append(lv);
	    }
	}
      else
	{
	  //
	  //	This case should not arise if we are flattening a binding, since bindings are supposed to be pure.
	  //
	  Assert(index == NONE, "binding " << target << " for variable with index " << index << " has subterm " << arg);
	  flattenedArguments.append(arg);
	}
    }
  int newNrArgs = flattenedArguments.size();
  AU_DagNode* result = new AU_DagNode(topSymbol, newNrArgs);
  for (int i = 0; i < newNrArgs; ++i)
    result->argArray[i] = flattenedArguments[i];
  return result;
}

bool
AU_UnificationSubproblem::interflattenBindings(UnificationContext& solution)
{
  int nrFragile = solution.nrFragileBindings();
  bool didFlatten;
  do
    {
      didFlatten = false;
      for (int i = 0; i < nrFragile; ++i)
	{
	  DagNode* binding = solution.value(i);
	  if (binding != 0 && binding->symbol() == topSymbol)
	    {
	      //
	      //	Binding belongs to our theory - need to check it.
	      //
	      AU_DagNode* a = safeCast(AU_DagNode*, binding);
	      if (hasArgumentBoundInTheory(a, solution))
		{
		  AU_DagNode* f = flatten(i, a, solution);
		  if (f == 0)
		    return false;  // occurs check failure
		  VariableDagNode* v = solution.getVariableDagNode(i);
		  solution.unificationBind(v, f);
		  DebugAdvisory("for variable " << static_cast<DagNode*>(v) <<
				": flattened " << binding <<
				" to " << static_cast<DagNode*>(f));
		  didFlatten = true;
		}
	    }
	}
    }
  while (didFlatten);  // to fixed point
  return true;
}

bool
AU_UnificationSubproblem::purifyAndBind(VariableDagNode* variable, AU_DagNode* target, UnificationContext& solution, PendingUnificationStack& pending)
{
  DebugAdvisory("purifying assoc dag " << static_cast<DagNode*>(target) << " and binding to variable " << static_cast<DagNode*>(variable));
  //
  //	Arguments can only be variables - aliens must be replaced by variables.
  //
  int index = variable->getIndex();
  int nrArgs = target->argArray.length();
  AU_DagNode* purified = new AU_DagNode(topSymbol, nrArgs);
  for (int i = 0; i < nrArgs; ++i)
    {
      DagNode* arg = target->argArray[i];
      Assert(arg->symbol() != topSymbol, "target " << target << " not flattened");

      if (VariableDagNode* v = dynamic_cast<VariableDagNode*>(arg))
	{
	  //
	  //	Argument is a variable - find current representative.
	  //
	  VariableDagNode* lv = v->lastVariableInChain(solution);
	  int argVarIndex = lv->getIndex();
	  if (argVarIndex == index)
	    {
	      DebugAdvisory("occur check failure while trying to purify " << static_cast<DagNode*>(target) <<
			    " because of " << static_cast<DagNode*>(v));
	      return false;
	    }
	  purified->argArray[i] = lv;
	}
      else
	{
	  //
	  //	Argument is an alien - introduce a new variable to purify it.
	  //
	  ConnectedComponent* component = topSymbol->rangeComponent();
	  DagNode* freshVariable = solution.makeFreshVariable(component);
	  if (!(arg->computeSolvedForm(freshVariable, solution, pending)))
	    {
	      DebugAdvisory("unexpected failure of " << arg << " =? " << freshVariable << " during purification");
	      return false;
	    }
	  purified->argArray[i] = freshVariable;
	}
    }
  //
  //	When we bind a variable X to a purified form f(..., Y, ...) we still have potential problems that
  //	(1) X may occur in some other binding Z |-> f(..., X, ...) which is now unflattened; and
  //	(2) Y may be bound Y |-> f(...) in which case we are creating an unflat binding.
  //	We fix up these situations by a mutual flattening proceedure later on.
  //
  solution.unificationBind(variable, purified);
  DebugAdvisory("bound " << static_cast<DagNode*>(variable) << " to " << static_cast<DagNode*>(purified));
  return true;
}

bool
AU_UnificationSubproblem::simplify(UnificationContext& solution, PendingUnificationStack& pending)
{
  //
  //	We assume that any bindings X = f(...) in our theory are in normal form.
  //	Unifications f(...) =? X can only be solved binding X to something that unifies with f(...)
  //	so we solve those unifications first.
  //
  bool madeBinding = false;
  int nrUnifications = unifications.size();
  for (int i = 0; i < nrUnifications; ++i)
    {
      Unification& u = unifications[i];
      if (u.rhs->symbol() != topSymbol)
	{
	  VariableDagNode* rhs = safeCast(VariableDagNode*, u.rhs);
	  VariableDagNode* lv = rhs->lastVariableInChain(solution);
	  int index = lv->getIndex();
	  DagNode* binding = solution.value(index);
	  if (binding == 0)
	    {
	      if (!purifyAndBind(lv, safeCast(AU_DagNode*, u.lhs), solution, pending))
		return false;  // must have been occurs check failure
	      madeBinding = true;
	    }
	  else
	    {
	      //
	      //	X is already bound - either we have a new f(...) =? f(...) problem or
	      //	a theory clash.
	      //
	      if (binding->symbol() == topSymbol)
		{
		  int nrUnifications = unifications.size();
		  unifications.expandTo(nrUnifications + 1);
		  unifications[nrUnifications].lhs = u.lhs;
		  unifications[nrUnifications].rhs = binding;
		  unifications[nrUnifications].problem = 0;
		}
	      else
		{
		  //
		  //	Theory clash - punt on it.
		  //
		  if (!(u.lhs->computeSolvedForm(binding, solution, pending)))
		    return false;  // must have been theory clash failure
		}
	    }
	}
    }
  return !madeBinding || interflattenBindings(solution);
}

#if 0

bool
AU_UnificationSubproblem::solve(bool findFirst, UnificationContext& solution, PendingUnificationStack& pending)
{
  if (findFirst)
    {
      //
      //	Save substituion and check point the pending stack because
      //	initial purification might introduce bindings or unification
      //	problems that must be retracted when we exit with failure.
      //
      preSolveSubstitution.clone(solution);
      preSolveState = pending.checkPoint();
      //
      //	We first attempt to solve any unification problems of the form
      //	f(...) =? X
      //	This may increase the number of unification problems.
      //
      if (!simplify(solution, pending))
	{
	  //
	  //	Occur check failure or theory clash failure - anyway we need to restore
	  //	state and quit.
	  //
	  pending.restore(preSolveState);
	  solution.restoreFromClone(preSolveSubstitution);
	}
    }
}


#endif

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
  //
  //	Solve an original subterm against a lone fresh variable like #1 or a term composed from fresh variables like f(#1, #2, #3).
  //	If subterm is a representative of an unbound variable, we bind the variable otherwise we pass the buck to computeSolvedForm().
  //
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
	  //
	  //	Check for the case that repVar is in fact the lone fresh variable we wanted to bind to it.
	  //	We don't handle this case in ACU because all subterms have been uniquified. Should only
	  //	happen if we have non-linear variables, say if we allow non-linear element variables.
	  //
	  if (!(repVar->equal(d)))
	    solution.unificationBind(repVar, d);
	  else
	    DebugAdvisory("AU_UnificationSubproblem::resolve(): repVar and fresh var are both " << d);
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
