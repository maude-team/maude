/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2012 SRI International, Menlo Park, CA 94025, USA.

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
//	Implementation for class VariantSearch.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "higher.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "lhsAutomaton.hh"
#include "subproblem.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "subproblemAccumulator.hh"
#include "variableInfo.hh"
#include "freshVariableGenerator.hh"
#include "dagArgumentIterator.hh"

//	variable class definitions
#include "variableDagNode.hh"

//	higher class definitions
#include "variantSearch.hh"
#include "variantNarrowingSearchState.hh"

VariantSearch::VariantSearch(RewritingContext* context,
			     const Vector<DagNode*>& blockerDags,
			     FreshVariableGenerator* freshVariableGenerator,
			     bool unificationMode)
  : context(context),
    blockerDags(blockerDags),  // shallow copy
    freshVariableGenerator(freshVariableGenerator),
    unificationMode(unificationMode)
{
  //
  //	Index variables in initial dag. We don't want to do reduction on initial dag for two reasons:
  //	(1) We rely on variable dags not going away to protect variable dags in variableInfo from GC.
  //	(2) Rewriting could introduce new ground terms that don't have their ground flag set, breaking instantiation.
  //
  context->root()->indexVariables(variableInfo, 0);
  //
  //	Check that variable names don't clash with the range we're going to use for fresh variables.
  //
  int nrVariantVariables = variableInfo.getNrVariables();
  for (int i = 0; i < nrVariantVariables; ++i)
    {
      VariableDagNode* v = variableInfo.index2Variable(i);
      if (freshVariableGenerator->variableNameConflict(v->id()))
	{
	  DagNode* d = v;
	  IssueWarning("unsafe variable name " << QUOTE(d) << " in variant " <<
		       (unificationMode ? "unification" : "narrowing") << " problem.");
	  return;
	}
    }
  {
    //
    //	Index and normalize and compute sorts for blocker dags. They could conceivable have previously unseen variables,
    //	but we don't care about the actual names of such variables since they will only be used in the subject side of
    //	matching and will behave as fresh constants.
    //	If one of the blocker dags is already reducible, we count that as an immediate fail.
    //
    FOR_EACH_CONST(i, Vector<DagNode*>, blockerDags)
      {
	DagNode* d = *i;
	d->indexVariables(variableInfo, 0);
	d->computeTrueSort(*context);  // also handles theory normalization
	if (d->reducibleByVariantEquation(*context))
	  {
	    IssueAdvisory("Irreducibility constraint " << d << " is itself reducible by a variant equation.");
	    return;
	  }
      }
  }
  //
  //	Allocate a fresh even variable for each original variable.
  //
  protectedVariant.resize(nrVariantVariables);
  Substitution s(nrVariantVariables);
  for (int i = 0; i < nrVariantVariables; ++i)
    {
      Sort* sort = safeCast(VariableSymbol*, variableInfo.index2Variable(i)->symbol())->getSort();
      VariableDagNode* v = new VariableDagNode(freshVariableGenerator->getBaseVariableSymbol(sort),
					       freshVariableGenerator->getFreshVariableName(i, false),
					       i);
      protectedVariant[i] = v;
      s.bind(i, v);
    }
  //
  //	Make a copy of the initial dag with the variables replaced by fresh ones.
  //
  DagNode* newDag = context->root()->instantiate(s);  // not safe if we haven't determined ground terms in context->root()
  if (newDag == 0)
    newDag = context->root();
  //
  //	Now we can safely reduce newDag - we have replace all the variables are we no longer care about in place rewriting on ground terms.
  //
  RewritingContext* redContext = context->makeSubcontext(newDag);
  redContext->reduce();

  DagNode* r = redContext->root();
  if (unificationMode)
    {
      DagArgumentIterator a(r);
      Assert(a.valid(), "bad 1st argument in unification mode");
      DagNode* lhs = a.argument();
      a.next();
      Assert(a.valid(), "bad 2nd argument in unification mode");
      if (lhs->equal(a.argument()))
	{
	  unifierCollection.insertVariant(protectedVariant, 0, NONE);
	  protectedVariant.clear();  // remove GC protection
	  context->addInCount(*redContext);
	  //context->incrementEqCount();  // notional equational rewrite to true
	  delete redContext;
	  return;  // no point in looking for other unifiers
	}
    }
  protectedVariant.append(r);
  context->addInCount(*redContext);
  delete redContext;
  //
  //	Insert this initial variant in to collection, and initialize variables for search.
  //
  variantCollection.insertVariant(protectedVariant, 0, NONE);
  protectedVariant.clear();  // remove GC protection
  frontier.append(0);
  currentIndex = 1;
  unifierIndex = 0;  // HACK - need a unique index for each unifier
  //
  //	Breadthfirst search for new variants. Variants indexed by the frontier can disappear if they become covered by
  //	later variants, or were descendents of variants that became covered.
  //
  bool odd = true;
  for (;;)
    {
      FOR_EACH_CONST(i, VariantIndexVec, frontier)
	{
	  int index = *i;
	  const Vector<DagNode*>* variant = variantCollection.getVariant(index);
	  if (variant != 0)
	    {
	      expand(*variant, index, odd);
	      if (context->traceAbort())
		return;
	    }
	}
      if (newFrontier.empty())
	return;
      frontier.swap(newFrontier);
      newFrontier.clear();
      odd = !odd;
    }
}

VariantSearch::~VariantSearch()
{
  delete freshVariableGenerator;
  delete context;
}

void
VariantSearch::markReachableNodes()
{
  //
  //	We don't mark the variable dag nodes in variableInfo - we rely on these existing in the original dag protected by the
  //	original context.
  //
  int substSize = protectedVariant.size();
  for (int i = 0; i < substSize; ++i)
    protectedVariant[i]->mark();
  FOR_EACH_CONST(i, Vector<DagNode*>, blockerDags)
    (*i)->mark();
}

void
VariantSearch::expand(const Vector<DagNode*>& variant, int index, bool odd)
{
  //cout << "expanding internal " << index << endl;
  int substSize = variant.size() - 1;
  RewritingContext* newContext = context->makeSubcontext(variant[substSize]);
  //
  //	We don't need to protect the DagNodes in this local copy since the are already protected
  //	by the VariantCollection.
  //
  Vector<DagNode*> variantSubstitution(substSize);
  for (int i = 0; i < substSize; ++i)
    variantSubstitution[i] = variant[i];
  //
  //	Create a search state for one step variant narrowings. We pass variableInfo because original
  //	variable names are needed for tracing, and total number of variables is needed for unification.
  //
  VariantNarrowingSearchState vnss(newContext, variantSubstitution, blockerDags, freshVariableGenerator, odd, variableInfo, unificationMode);
  //
  //	Extract each new variant.
  //
  DagNode* variantTerm;
  Vector<DagNode*> newVariantSubstitution;
  while (vnss.findNextVariant(variantTerm, newVariantSubstitution))
    {
      protectedVariant = newVariantSubstitution;  // deep copy to protect bindings from GC
      //
      //	Check to see if we generated a unifier.
      //
      if (variantTerm == 0)
	{
	  Assert(unificationMode, "null variant term and we're not in unification mode");
	  unifierCollection.insertVariant(protectedVariant, unifierIndex, NONE);
	  ++unifierIndex; // HACK
	  protectedVariant.clear();  // remove GC protection
	  continue;
	}
      //
      //	Reduce dag part of new variant.
      //
      RewritingContext* redContext = context->makeSubcontext(variantTerm);
      redContext->reduce();
      protectedVariant.append(redContext->root());
      //
      //	Give new variant a unique index.
      //
      int newIndex = currentIndex;
      ++currentIndex;
      //
      //	Insert new variant in to collection and if it sticks, insert its index into the new frontier.
      //
      //cout << "inserting internal " << newIndex << endl;
      if (variantCollection.insertVariant(protectedVariant, newIndex, index))
	{
	  //cout << "added variant\n";
	  DagNode* d = protectedVariant[substSize];
	  //cout << d->getSort() << ": " << d << '\n';
	  for (int i = 0; i < substSize; ++i)
	    {
	      DagNode* v = variableInfo.index2Variable(i);
	      //cout << v << " --> " << protectedVariant[i] << endl;
	    }
	  //cout << endl;

	  newFrontier.append(newIndex);
	}
      protectedVariant.clear();  // remove GC protection
      //
      //	Move rewrite count from reduction to original context.
      //
      context->addInCount(*redContext);
      delete redContext;
    }
  //
  //	Move rewrite count from narrowing to original context.
  //
  context->addInCount(*newContext);
  delete newContext;
}

#ifdef DUMP
void
VariantSearch::dumpVariant(const Vector<DagNode*>& variant, int index,  int parentIndex)
{
  int nrVariables = variant.size() - 1;
  cout << "\nInserted variant\n";

  cout << "index = " << index << endl;
  cout << "parentIndex = " << parentIndex << endl;
  cout << "term = " << variant[nrVariables] << endl;

  for (int i = 0; i < nrVariables; ++i)
    {
      DagNode* v = variableInfo.index2Variable(i);
      cout << v << " |-> " << variant[i] << endl;
    }
  cout << endl;
}
#endif
