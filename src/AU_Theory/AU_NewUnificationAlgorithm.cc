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
//	Second attempt at associative unification.
//

bool
AU_UnificationSubproblem::solve(bool findFirst, UnificationContext& solution, PendingUnificationStack& pending)
{
  if (findFirst)
    {
      DebugAdvisory("AU_UnificationSubproblem::solve() - initial problem state");
#ifndef NO_ASSERT
      if (globalAdvisoryFlag)
	dump(solution);
#endif
      //
      //	Save substitution and check point the pending stack because
      //	initial purification might introduce bindings or unification
      //	problems that must be retracted when we exit with failure.
      //
      preSolveSubstitution.clone(solution);
      preSolveState = pending.checkPoint();
      //
      //	Compute bounds on representative variables.
      //
      computeBounds(solution);
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
	  DebugAdvisory("bailing due to simpify() failing");
#ifndef NO_ASSERT
	  if (globalAdvisoryFlag)
	    dump(solution);
#endif
	  return false;
	}
      //
      //	Now flatten problems of the form
      //	f(...) =? f(...)
      //
      if (!flattenUnifications(solution))
	{
	  //
	  //	Nonlinearity issue.
	  //
	  pending.restore(preSolveState);
	  solution.restoreFromClone(preSolveSubstitution);
	  DebugAdvisory("bailing due to nonlinearity issue");
#ifndef NO_ASSERT
	  if (globalAdvisoryFlag)
	    dump(solution);
#endif
	  return false;
	}
      //
      //	Now construct SequenceAssignment object for each flattened problem.
      //
      makeSequenceAssignmentProblems(solution);
      //
      //	Save state of the pending stack with the substitution so that
      //	we can restore both in order to undo each of our solutions.
      //
      savedSubstitution.clone(solution);
      savedPendingState = pending.checkPoint();
      
      DebugAdvisory("after creating sequence assignment problems");
#ifndef NO_ASSERT
      if (globalAdvisoryFlag)
	dump(solution);
#endif
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

void
AU_UnificationSubproblem::dump(UnificationContext& solution)
{
  cerr << Tty(Tty::MAGENTA) << "===== Associative unification problem =====" << Tty(Tty::RESET) << endl;
  {
    FOR_EACH(i, Vector<Unification>, unifications)
      cerr << i->lhs << " =? " << i->rhs << endl;
  }
  cerr << Tty(Tty::MAGENTA) << "------------------------------------------------" << Tty(Tty::RESET) << endl;
  {
    int nrFragile = solution.nrFragileBindings();
    for (int i = 0; i < nrFragile; ++i)
      {
	cerr << "index = " << i << "    ";
	DagNode* binding = solution.value(i);
	DagNode* varName = solution.getVariableDagNode(i);
	if (varName == 0)
	  cerr << "(no name)";
	else
	  cerr << varName;
	cerr << " |-> ";
	if (binding == 0)
	  cerr << "(unbound)" << endl;
	else
	  cerr << binding << endl;
      }
  }
  cerr << Tty(Tty::MAGENTA) << "=====================================================" << Tty(Tty::RESET) << endl;
}

void
AU_UnificationSubproblem::makeSequenceAssignmentProblems(UnificationContext& solution)
{
  FOR_EACH(i, Vector<Unification>, unifications)
    {
      Unification& u = *i;
      if (u.rhs->symbol() == topSymbol)
	{
	  DebugAdvisory("making SequenceAssignment for " << i->lhs << " =? " << i->rhs);
	  //
	  //	Unification of the form f(...) =? f(...)
	  //
	  AU_DagNode* lhs = safeCast(AU_DagNode*, i->lhs);
	  int nrLhsArgs = lhs->argArray.length();
	  AU_DagNode* rhs = safeCast(AU_DagNode*, i->rhs);
	  int nrRhsArgs = rhs->argArray.length();
	  i->problem = new SequenceAssignment(nrLhsArgs, nrRhsArgs);

	  for (int j = 0; j < nrLhsArgs; ++j)
	    {
	      int bound = findUpperBound(lhs->argArray[j], solution);
	      DebugAdvisory("lhs " << j << " bound = " << bound);
	      if (bound != UNBOUNDED)
		i->problem->setLhsBound(j, bound);
	    }

	  for (int j = 0; j < nrRhsArgs; ++j)
	    {
	      int bound = findUpperBound(rhs->argArray[j], solution);
	      DebugAdvisory("rhs " << j << " bound = " << bound);
	      if (bound != UNBOUNDED)
		i->problem->setRhsBound(j, bound);
	    }
	}
    }
}

bool
AU_UnificationSubproblem::flattenUnifications(UnificationContext& solution)
{
  //
  //	We look at all unifications of the form f(...) =? f(...), flatten any variables
  //	that are bound in theory and report any nonlinearities remaining.
  //
  NatSet seenVariables;
  FOR_EACH(i, Vector<Unification>, unifications)
    {
      Unification& u = *i;
      if (u.rhs->symbol() == topSymbol)
	{
	  u.lhs = flattenDag(safeCast(AU_DagNode*, u.lhs), solution, seenVariables);
	  u.rhs = flattenDag(safeCast(AU_DagNode*, u.rhs), solution, seenVariables);
	}      
    }
  return true;
}

AU_DagNode*
AU_UnificationSubproblem::flattenDag(AU_DagNode* target, UnificationContext& solution, NatSet& seenVariables)
{
  int nrArgs = target->argArray.length();
  if (hasArgumentBoundInTheory(target, solution))
    {
      //
      //	Need to flatten.
      //
      Vector<DagNode*> flattenedArguments;

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
	      DagNode* binding = solution.value(argVarIndex);
	      if (binding != 0 && binding->symbol() == topSymbol)
		{
		  //
		  //	Variable is bound in theory - need to flatten.
		  //
		  AU_DagNode* b = safeCast(AU_DagNode*, binding);
		  int nrArgs2 = b->argArray.length();
		  for (int j = 0; j < nrArgs2; ++j)
		    {
		      DagNode* subArg = b->argArray[j];
		      if (VariableDagNode* v2 = dynamic_cast<VariableDagNode*>(subArg))
			{
			  VariableDagNode* lv2 = v2->lastVariableInChain(solution);
			  int subArgVarIndex = lv2->getIndex();
			  if (seenVariables.contains(subArgVarIndex))
			    handleNonlinearVariable(lv2);
			  flattenedArguments.append(lv2);
			  seenVariables.insert(subArgVarIndex);
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
		  //	Either variable is unbound or bound to alien.
		  //
		  if (seenVariables.contains(argVarIndex))
		    handleNonlinearVariable(lv);
		  flattenedArguments.append(lv);
		  seenVariables.insert(argVarIndex);
		}
	    }
	  else
	    {
	      //
	      //	Non-variable.
	      //
	      flattenedArguments.append(arg);
	    }
	}
      //
      //	Make a replacement dag.
      //
      int newNrArgs = flattenedArguments.size();
      AU_DagNode* result = new AU_DagNode(topSymbol, newNrArgs);
      for (int i = 0; i < newNrArgs; ++i)
	result->argArray[i] = flattenedArguments[i];
      return result;
    }
  //
  //	No need to flatten; just check for seen variables.
  //
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
	  if (seenVariables.contains(index))
	    handleNonlinearVariable(lv);
	  seenVariables.insert(index);
	}
    }
  return target;
}

void
AU_UnificationSubproblem::handleNonlinearVariable(VariableDagNode* v)
{
  DebugAdvisory("saw nonlinear variable " << static_cast<DagNode*>(v));
  if (bounds[v->getIndex()] == 1)
    {
      DebugAdvisory("OK - we already computed unit bound for it");
      return;
    }

  Sort* variableSort = safeCast(VariableSymbol*, v->symbol())->getSort();
  if (topSymbol->sortBound(variableSort) == 1)
    {
      DebugAdvisory("OK - it has element sort");
      return;
    }
  //
  //	OK we're screwed; fess up and recover by turn it into a unit variable.
  //
  IssueWarning("Nonlinear variable seen under associative symbol cannot be handled by current associative unification algorithm. Recovering by restricting variable - some unifiers will probably be lost.");
  bounds[v->getIndex()] = 1;
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
  //	Flatten in arguments that are bound in theory. If we flatten-in a variable with given
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

void
AU_UnificationSubproblem::computeBounds(UnificationContext& solution)
{
  //
  //	We only worry about variables that are bound or are representing at least one
  //	other variable (we can't get a dag node for unbound lone variables).
  //
  int nrFragile = solution.nrFragileBindings();
  bounds.expandTo(nrFragile);
  for (int i = 0; i < nrFragile; ++i)
    bounds[i] = UNBOUNDED;
  for (int i = 0; i < nrFragile; ++i)
    {
      if (solution.value(i) != 0)
	{
	  VariableDagNode* v = solution.getVariableDagNode(i);
	  VariableDagNode* lv = v->lastVariableInChain(solution);
	  int repIndex = lv->getIndex();
	  DagNode* subject = solution.value(repIndex);
	  if (subject != 0 && subject->symbol() != topSymbol && subject->symbol()->isStable())
	    bounds[repIndex] = 1;
	  else
	    {
	      //
	      //	See if our sort can tighten a bound on our representative variable.
	      //
	      Sort* variableSort = safeCast(VariableSymbol*, v->symbol())->getSort();
	      int variableSortBound = topSymbol->sortBound(variableSort);
	      if (variableSortBound < bounds[repIndex])
		bounds[repIndex] = variableSortBound;
	    }
	}
    }
}

void
AU_UnificationSubproblem::updateBounds(int freshVariableIndex, int bound)
{
  //
  //	If a fresh variable is added, at some point we may want to look up its bound so we
  //	need to update the bounds vector.
  //
  int firstNew = bounds.length();
  bounds.expandTo(freshVariableIndex + 1);
  for (int i = firstNew; i < freshVariableIndex; ++i)
    bounds[i] = UNBOUNDED;
  bounds[freshVariableIndex] = bound;
}

int
AU_UnificationSubproblem::findUpperBound(DagNode* subject, UnificationContext& solution)
{
  //
  //	Compute an upper bound on what can be assign to subject in a A unification problem.
  //
  if (VariableDagNode* v = dynamic_cast<VariableDagNode*>(subject))
    {
      VariableDagNode* lv = v->lastVariableInChain(solution);
      int repIndex = lv->getIndex();
      Sort* variableSort = safeCast(VariableSymbol*, lv->symbol())->getSort();
      int variableSortBound = topSymbol->sortBound(variableSort);
      return min(bounds[repIndex], variableSortBound);
    }
  //
  //	We only support stable non-variable subterms.
  //
  return subject->symbol()->isStable() ? 1 : UNBOUNDED;
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
  while (didFlatten);  // iterate to fixed point
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
	  VariableDagNode* freshVariable = solution.makeFreshVariable(component);
	  if (!(arg->computeSolvedForm(freshVariable, solution, pending)))
	    {
	      DebugAdvisory("unexpected failure of " << arg << " =? " << static_cast<DagNode*>(freshVariable) << " during purification");
	      return false;
	    }
	  updateBounds(freshVariable->getIndex(), arg->symbol()->isStable() ? 1 : UNBOUNDED);
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
AU_UnificationSubproblem::constrained(AU_DagNode* target, UnificationContext& solution)
{
  int nrArgs = target->argArray.length();
  for (int i = 0; i < nrArgs; ++i)
    {
      if (findUpperBound(target->argArray[i], solution) != 1)
	return false;  // argument isn't constrained
    }
  return true;
}

bool
AU_UnificationSubproblem::simplify(UnificationContext& solution, PendingUnificationStack& pending)
{
  //
  //	We assume that any bindings X |-> f(...) in our theory are in normal form.
  //	Unifications f(...) =? X can only be solved binding X to something that unifies with f(...)
  //	so we solve those unifications first.
  //
  bool madeBinding = false;
  int nrUnifications = unifications.size();
  NatSet handled;
  //
  //	We prefer to bind X to f(...) where the arguments are constrained to unify with only one thing
  //	since this will no throw up hard nonlinearities if we need to unify > 2 things with X.
  //
  for (int i = 0; i < nrUnifications; ++i)
    {
      Unification& u = unifications[i];
      if (u.rhs->symbol() != topSymbol)
	{
	  AU_DagNode* lhs = safeCast(AU_DagNode*, u.lhs);	  
	  if (constrained(lhs, solution))
	    {
	      DebugAdvisory(static_cast<DagNode*>(lhs) << " was constrained");
	      //
	      //	The argument list is fully constrained so we prefer it.
	      //
	      VariableDagNode* rhs = safeCast(VariableDagNode*, u.rhs);
	      VariableDagNode* lv = rhs->lastVariableInChain(solution);
	      int index = lv->getIndex();
	      DagNode* binding = solution.value(index);
	      //
	      //	We make the binding on top of anything that is there already.
	      //
	      if (!purifyAndBind(lv, safeCast(AU_DagNode*, u.lhs), solution, pending))
		{
		  DebugAdvisory(Tty(Tty::MAGENTA) << "purifyAndBind failed on " << (DagNode*) lv <<
				" originally " << u.rhs <<
				" trying to bind to purification of " << u.lhs << Tty(Tty::RESET));
		  return false;  // must have been occurs check failure
		}
	      madeBinding = true;
	      //
	      //	If we had a binding already we must now deal with it.
	      //
	      if (binding != 0)
		{
		  if (binding->symbol() == topSymbol)
		    {
		      int nrUnifications = unifications.size();
		      unifications.expandTo(nrUnifications + 1);
		      unifications[nrUnifications].lhs = solution.value(index);  // purified version of u.lhs
		      unifications[nrUnifications].rhs = binding;
		      unifications[nrUnifications].problem = 0;
		    }
		  else
		    {
		      //
		      //	Theory clash - punt on it.
		      //
		      if (!(u.lhs->computeSolvedForm(binding, solution, pending)))
			{
			  DebugAdvisory(Tty(Tty::MAGENTA) << "computeSolvForm failed on " << u.lhs <<  " vs " << binding << Tty(Tty::RESET));
			  return false;  // must have been theory clash failure
			}
		    }
		}
	      handled.insert(i);
	    }
	}
    }
  //
  //	Now we do the same thing with unifications f(...) =? X where the arguments are unconstrained.
  //
  for (int i = 0; i < nrUnifications; ++i)
    {
      if (!(handled.contains(i)))
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
		    {
		      DebugAdvisory(Tty(Tty::MAGENTA) << "purifyAndBind failed on " << (DagNode*) lv <<
				    " originally " << u.rhs <<
				    " trying to bind to purification of " << u.lhs << Tty(Tty::RESET));
		      return false;  // must have been occurs check failure
		    }
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
			{
			  DebugAdvisory(Tty(Tty::MAGENTA) << "computeSolvForm failed on " << u.lhs <<  " vs " << binding << Tty(Tty::RESET));
			  return false;  // must have been theory clash failure
			}
		    }
		}
	    }
	}
    }
  return !madeBinding || interflattenBindings(solution);
}
