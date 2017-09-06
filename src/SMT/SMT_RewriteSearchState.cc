/*

    This file is part of the Maude 2 interpreter.

    Copyright 2014 SRI International, Menlo Park, CA 94025, USA.

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
//      Implementation for class SMT_RewriteSearchState.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "variable.hh"
#include "higher.hh"
#include "SMT.hh"

//      interface class definitions
#include "term.hh"
#include "subproblem.hh"
#include "lhsAutomaton.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "symbolMap.hh"
#include "rule.hh"

//      variable class definitions
#include "variableSymbol.hh"
#include "variableDagNode.hh"

//      higher class definitions
#include "equalityConditionFragment.hh"

//      free theory class definitions
#include "freeDagNode.hh"

//	SMT stuff
#include "SMT_Info.hh"
#include "SMT_VariableManager.hh"
#include "SMT_RewriteSearchState.hh"

SMT_RewriteSearchState::SMT_RewriteSearchState(RewritingContext* context,
					       const SMT_Info& smtInfo,
					       SMT_VariableManager& variableManager,
					       const mpz_class& avoidVariableNumber,
					       int flags)
  : context(context),
    smtInfo(smtInfo),
    variableManager(variableManager),
    avoidVariableNumber(avoidVariableNumber),
    flags(flags)
{
  ruleIndex = -1;
  matchingSubproblem = 0;
  nextPair = 0;
}


SMT_RewriteSearchState::~SMT_RewriteSearchState()
{
  delete matchingSubproblem;
  if (flags & GC_ENGINE)
    delete &variableManager;
  if (flags & GC_CONTEXT)
    delete context;
}

void
SMT_RewriteSearchState::markReachableNodes()
{
  if (nextPair)
    nextPair->mark();
}

bool
SMT_RewriteSearchState::findNextRewrite()
{
  if (ruleIndex > -1)
    {
      //
      //	We already selected a rule and matched it in at least one way; see if
      //	it can be matched in another way.
      //
      if (nextSolution())
	return true;
      ++ruleIndex;
    }
  else
    {
      //
      //	Starting from scratch.
      //
      if (!checkAndConvertState())
	{
	  DebugAdvisory("failed to convert initial state");
	  return false;
	}
      DebugAdvisory("converted state = " << state << " constraint = " << constraint);
      ruleIndex = 0;
    }

  Symbol* topSymbol = state->symbol();
  const Vector<Rule*>& rules = topSymbol->getRules();
  for (int nrRules = rules.length(); ruleIndex < nrRules; ++ruleIndex)
    {
      currentRule = rules[ruleIndex];
      DebugAdvisory("Considering rule: " << currentRule);
      context->clear(currentRule->getNrProtectedVariables());
      LhsAutomaton* a = currentRule->getNonExtLhsAutomaton();
      if (a->match(state, *context, matchingSubproblem, 0))
	{
	  if (matchingSubproblem == 0 || matchingSubproblem->solve(true, *context))
	    {
	      if (checkConsistancy())
		return true;
	      DebugAdvisory("first match failed consistancy check");
	      if (nextSolution())
		return true;
	    }
	  else
	    DebugAdvisory("solve() failed");
	}
      else
	DebugAdvisory("match() failed");
    }
  return false;
}

bool
SMT_RewriteSearchState::nextSolution()
{
  //
  //	Clear bindings of variables that were bound to fresh variables.
  //
  FOR_EACH_CONST(i, NatSet, boundToFresh)
    context->bind(*i, 0);
  boundToFresh.clear();
  //
  //	If we had a matching problem we may be able to solve it in a new way.
  //
  if (matchingSubproblem != 0)
    {
      while (matchingSubproblem->solve(false, *context))
	{
	  if (checkConsistancy())
	    return true;
	  DebugAdvisory("next match failed consistancy check");
	  //
	  //	Clear bindings of variables that were bound to fresh variables.
	  //
	  FOR_EACH_CONST(i, NatSet, boundToFresh)
	    context->bind(*i, 0);
	  boundToFresh.clear();
	}
      delete matchingSubproblem;
      matchingSubproblem = 0;
    }
  return false;
}

bool
SMT_RewriteSearchState::checkConsistancy()
{
  //
  //	First we find all unbound variables occuring in the rule and
  //	bind them to fresh variables.
  //
  int nrRealVariables = currentRule->getNrRealVariables();
  newVariableNumber = avoidVariableNumber;
  for (int i = 0; i < nrRealVariables; ++i)
    {
      DagNode* binding = context->value(i);
      if (binding == 0)
	{
	  ++newVariableNumber;
	  DagNode* newVariable = variableManager.makeFreshVariable(currentRule->index2Variable(i), newVariableNumber);
	  context->bind(i, newVariable);
	  DebugAdvisory("variable " << currentRule->index2Variable(i) << " is unbound and so is bound to fresh variable " << newVariable);
	  boundToFresh.insert(i);
	}
      else
	DebugAdvisory("variable " << currentRule->index2Variable(i) << " is bound to " << binding);
    }
  //
  //	There is no requirement that a rule has a condition. But if it has we need to instantiate it
  //	and check it.
  //
  DagNode* condition = 0;
  if (currentRule->hasCondition())
    {
      if (!instantiateCondition(currentRule->getCondition(), condition))
	return false;
      //
      //	If condition was optimized away it will be zero.
      //
      if (condition != 0 && variableManager.checkDag(condition) != SMT_VariableManager::SAT)
	return false;
    }
  //
  //	Either there was no condition or the new constraint which it generated was satisfiable in the presence
  //	of the accumulated constraints to date. We need to generate a new pair consisting of the rewritten
  //	state and conjuncted state.
  //
  Symbol* pairingSymbol = context->root()->symbol();
  Vector<DagNode*> args(2);
  args[1] = constraint;
  if (condition != 0)
    {
      if (constraint->symbol() == smtInfo.getTrueSymbol())
	{
	  //
	  //	Replace true clause by condition.
	  //
	  args[1] = condition;
	}
      else
	{
	  //
	  //	Conjunct constraint and condition.
	  //
	  args[0] = condition;
	  DebugAdvisory("condition = " << args[0]);
	  DebugAdvisory("old constraint = " << args[1]);
	  args[1] = smtInfo.getConjunctionOperator()->makeDagNode(args);
	  DebugAdvisory("New constraint = " << args[1]);
	}
    }
  args[0] = currentRule->getRhsBuilder().construct(*context);
  //
  //	Finally we form a new <state, constraint> pair.
  //
  nextPair = pairingSymbol->makeDagNode(args);
  DebugAdvisory("New state = " << args[0]);
  DebugAdvisory("New constraint = " << args[1]);
  DebugAdvisory("Result = " << nextPair);
  nextPair->computeTrueSort(*context);
  DebugAdvisory("After normalization = " << nextPair);
  //
  //	No equation rewriting should happen during rewriting module SMT so we
  //	call garbage collector here if needed.
  //
  MemoryCell::okToCollectGarbage();
  return true;
}

bool
SMT_RewriteSearchState::checkAndConvertState()
{
  DagNode* root = context->root();
  root->computeTrueSort(*context);
  //
  //	Pair needs to be a free binary symbol. First argument is assumed to be state
  //	where we will attempt a rewrite at top. Second argument is assumed to be
  //	an SMT constraint that we will use to initialize an SMT engine instance.
  //
  if (FreeDagNode* pair = dynamic_cast<FreeDagNode*>(root))
    {
      pairingSymbol = pair->symbol();
      if (pairingSymbol->arity() == 2)
	{
	  state = pair->getArgument(0);
	  constraint = pair->getArgument(1);
	  return variableManager.assertDag(constraint) == SMT_VariableManager::SAT;
	}
    }
  IssueWarning("Expecting an SMT rewriting pair but saw " << QUOTE(root) << '.');
  return false;
}

bool
SMT_RewriteSearchState::instantiateCondition(const Vector<ConditionFragment*>& condition, DagNode*& instantiation)
{
  //
  //	Build a dag that representing the SMT conjunction of the instantiated condition fragments.
  //	Null dag pointer represents trivially true condition.
  //	Return true on success and false if there was a problem.
  //
  instantiation = 0;
  FOR_EACH_CONST(i, Vector<ConditionFragment*>, condition)
    {
      EqualityConditionFragment* cf = dynamic_cast<EqualityConditionFragment*>(*i);
      if (cf == 0)
	{
	  IssueWarning("non-equality condition fragment");
	  return false;
	}
      
      DagNode* lhs;
      DagNode* rhs;
      cf->buildInstances(*context, lhs, rhs);
      if (lhs->equal(rhs))
	continue;  // optimize out equal dags

      DagNode* clause;
      if (rhs->symbol() == smtInfo.getTrueSymbol())
	clause = lhs;  // optimize QF = true
      else if (lhs->symbol() == smtInfo.getTrueSymbol())
	clause = rhs;  // optimize true = QF
      else
	{
	  Symbol* eqOp = smtInfo.getEqualityOperator(lhs, rhs);
	  if (eqOp == 0)
	    {
	      IssueWarning("bad equality condition fragment");
	      return false;
	    }
	  Vector<DagNode*> args(2);
	  args[0] = lhs;
	  args[1] = rhs;
	  clause = eqOp->makeDagNode(args);
	}
      if (instantiation == 0)
	instantiation = clause;
      else
	{
	  Vector<DagNode*> args(2);
	  args[0] = instantiation;
	  args[1] = clause;
	  instantiation = smtInfo.getConjunctionOperator()->makeDagNode(args);
	}
    }
  return true;
}
