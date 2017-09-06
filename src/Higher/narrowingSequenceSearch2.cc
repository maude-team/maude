/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2017 SRI International, Menlo Park, CA 94025, USA.

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
//	Implementation for class NarrowingSequenceSearch2.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//	variable class definitions
#include "variableSymbol.hh"
#include "variableDagNode.hh"

//	core class definitions
#include "rewritingContext.hh"

//	higher class definitions
#include "freshVariableGenerator.hh"
#include "narrowingVariableInfo.hh"
#include "narrowingSearchState2.hh"
#include "variantSearch.hh"
#include "narrowingSequenceSearch2.hh"

bool
NarrowingSequenceSearch2::allVariablesBelongToIncomingFamily(const NarrowingVariableInfo& variableInfo)
{
  int nrVariables = variableInfo.getNrVariables();
  for (int i = 0; i < nrVariables; ++i)
    {
      VariableDagNode* v = variableInfo.index2Variable(i);
      if (!freshVariableGenerator->belongsToFamily(v->id(), incomingVariableFamily))
	return false;
    }
  return true;
}

NarrowingSequenceSearch2::NarrowingSequenceSearch2(RewritingContext* initial,
						   SearchType searchType,
						   DagNode* goal,
						   int label,
						   int maxDepth,
						   int narrowingFlags,
						   FreshVariableGenerator* freshVariableGenerator,
						   int incomingVariableFamily)
  : initial(initial),
    goal(goal),
    label(label),
    maxDepth((searchType == ONE_STEP) ? 1 : maxDepth),
    narrowingFlags(narrowingFlags),
    freshVariableGenerator(freshVariableGenerator),
    incomingVariableFamily(incomingVariableFamily),
    needToTryInitialState(searchType == ANY_STEPS),
    normalFormNeeded(searchType == NORMAL_FORM)
{
  incompleteFlag = false;
  unificationProblem = 0;  // not yet started
  stateBeingExpanded = 0;
  expansionFinished = true;
  nextToExpand = 0;
  currentDepth = 0;

  DagNode* dagToNarrow = initial->root();
  //
  //	Check to see if variables in dagToNarrow really come from the
  //	stated variable family and if not, rename them.
  //
  NarrowingVariableInfo variableInfo;
  dagToNarrow->indexVariables(variableInfo, 0);
  if (!allVariablesBelongToIncomingFamily(variableInfo))
    {
      int nrVariables = variableInfo.getNrVariables();
      Substitution s(nrVariables);
      for (int i = 0; i < nrVariables; ++i)
	{
	  Sort* sort = safeCast(VariableSymbol*, variableInfo.index2Variable(i)->symbol())->getSort();
	  VariableDagNode* v = new VariableDagNode(freshVariableGenerator->getBaseVariableSymbol(sort),
						   freshVariableGenerator->getFreshVariableName(i, incomingVariableFamily),
						   i);
	  s.bind(i, v);
	}
     dagToNarrow = dagToNarrow->instantiate(s);
    }
  //
  //	Make initial state.
  //
  nextFrontier.resize(1);
  RewritingContext* reduceContext = initial->makeSubcontext(dagToNarrow);
  reduceContext->reduce();
  initial->transferCount(*reduceContext);
  nextFrontier[0].reducedDagContext = reduceContext;
  nextFrontier[0].variableFamily = incomingVariableFamily;

  Symbol* goalSymbol = goal->symbol();
  Module* module = goalSymbol->getModule();
  ConnectedComponent* range = goal->symbol()->rangeComponent();

  Vector<ConnectedComponent*> domain(2);
  domain[0] = range;
  domain[1] = range;
  unificationPairSymbol = module->createInternalTupleSymbol(domain, range);
}

NarrowingSequenceSearch2::~NarrowingSequenceSearch2()
{
  if (stateBeingExpanded != 0)
    {
      currentFrontier[nextToExpand - 1].reducedDagContext = 0; // responsibility passed to NarrowingSearchState2
      delete stateBeingExpanded;
    }

  const Frontier::iterator currentEnd = currentFrontier.end();
  for (Frontier::iterator i = currentFrontier.begin(); i != currentEnd; ++i)
    delete i->reducedDagContext;

  const Frontier::iterator nextEnd = nextFrontier.end();
  for (Frontier::iterator i = nextFrontier.begin(); i != nextEnd; ++i)
    delete i->reducedDagContext;

  delete unificationProblem;
  delete freshVariableGenerator;
  delete initial;
}

bool
NarrowingSequenceSearch2::findNextInterestingState()
{
  if (needToTryInitialState)
    {
      //
      //	Special case: return the initial state.
      //
      needToTryInitialState = false;  // don't do this again
      return true;
    }

  if (!expansionFinished)
    {
    tryToExpand:
      for (;;)
	{
	  bool success = stateBeingExpanded->findNextNarrowing();
	  initial->transferCount(*(stateBeingExpanded->getContext())); // transfer count whether we succeeded or not
	  if (stateBeingExpanded->isIncomplete())
	    incompleteFlag = true;

	  if (success)
	    {
	      if (normalFormNeeded && currentDepth == maxDepth + 1)
		{
		  //
		  //	The new state will be at maxDepth + 1 so need not be considered. It's
		  //	enough to know that the parent state has a successor and thus isn't
		  //	in normal form.
		  //
		  break;
		}
	      expansionSuccessful = true;  // current state can't be a normal form
	      int nextFrontierSize = nextFrontier.size();
	      nextFrontier.resize(nextFrontierSize + 1);

	      DagNode* replacement;
	      DagNode* replacementContextDummy;
	      DagNode* newState = stateBeingExpanded->getNarrowedDag(replacement, replacementContextDummy);
	      //
	      //	Do tracing if we care about it.
	      //
	      if (RewritingContext::getTraceStatus())
		{
		  //
		  //	These should differ not from their "active" versions since we aren't allowing
		  //	NarrowingSearchState2() to rename the variables in the start state.
		  //
		  RewritingContext* context = stateBeingExpanded->getContext();
		  const NarrowingVariableInfo& variableInfo = stateBeingExpanded->getVariableInfo();

		  context->traceNarrowingStep(stateBeingExpanded->getRule(),
					      stateBeingExpanded->getReplacedDag(),
					      replacement,
					      &variableInfo,
					      &(stateBeingExpanded->getSubstitution()),
					      newState);
		  if (context->traceAbort())
		    return false;
		}
	      initial->incrementNarrowingCount();
	      //
	      //	Reduce new state dag.
	      //
	      RewritingContext* reduceContext = initial->makeSubcontext(newState);
	      reduceContext->reduce();
	      initial->transferCount(*reduceContext);
	      nextFrontier[nextFrontierSize].reducedDagContext = reduceContext;
	      nextFrontier[nextFrontierSize].variableFamily = stateBeingExpanded->getVariableFamily();

	      if (!normalFormNeeded)
		return true;
	    }
	  else
	    {
	      expansionFinished = true;  // no more successors
	      //
	      //	State is in normal form if we failed to expand it.
	      //
	      if (normalFormNeeded && !expansionSuccessful)
		return true;
	      break;
	    }
	}
    }

  if (stateBeingExpanded != 0)
    {
      //
      //	Delete last state we tried to expand.
      //
      currentFrontier[nextToExpand - 1].reducedDagContext = 0; // responsibility passed to stateBeingExpanded
      delete stateBeingExpanded;
      stateBeingExpanded = 0;
    }

  int currentFrontierSize = currentFrontier.size();
  if (nextToExpand >= currentFrontierSize)
    {
      //
      //	All current states expanded, try next frontier.
      //
      if (nextFrontier.empty())
	return false;
      if (!normalFormNeeded && currentDepth == maxDepth)
	return false;

      currentFrontier.clear();
      currentFrontier.swap(nextFrontier);
      nextToExpand = 0;
      ++currentDepth;
    }

  stateBeingExpanded = new NarrowingSearchState2(currentFrontier[nextToExpand].reducedDagContext,
						 freshVariableGenerator,
						 currentFrontier[nextToExpand].variableFamily,
						 label,
						 NarrowingSearchState2::ALLOW_NONEXEC | PositionState::RESPECT_FROZEN);
  expansionSuccessful = false;
  expansionFinished = false;
  ++nextToExpand;
  goto tryToExpand;
				     
  return false;
}

bool
NarrowingSequenceSearch2::findNextUnifier()
{
  for (;;)
    {
      if (unificationProblem != 0)
	{
	  currentUnifier = unificationProblem->getNextUnifier(nrFreeVariablesInUnifier, variableFamilyInUnifier);
	  initial->transferCount(*(unificationProblem->getContext()));
	  if (unificationProblem->isIncomplete())
	    incompleteFlag = true;

	  if (currentUnifier != 0)
	    return true;
	  delete unificationProblem;
	  unificationProblem = 0;
	}

      if (!findNextInterestingState())
	break;
      //
      //	Need to variant unify the narrrowed dag in this state with the goal dag.
      //
      Vector<DagNode*> args(2);
      args[0] = goal.getNode();
      args[1] = getStateDag();
      DagNode* pairDag = unificationPairSymbol->makeDagNode(args);
      RewritingContext* pairContext = initial->makeSubcontext(pairDag);

      const Vector<DagNode*> dummy;
      unificationProblem = new VariantSearch(pairContext,  // will be deleted by VariantSearch
					     dummy,
					     freshVariableGenerator,
					     true,
					     false,
					     false,
					     getStateVariableFamily(),
					     false);
    }
  return false;
}
