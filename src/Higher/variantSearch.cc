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
//	Implementation for class VariantFolder.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"

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

//	variable class definitions
#include "variableDagNode.hh"

//	higher class definitions
#include "variantSearch.hh"
#include "variantNarrowingSearchState.hh"

VariantSearch::VariantSearch(RewritingContext* context, FreshVariableGenerator* freshVariableGenerator)
  : context(context),
    freshVariableGenerator(freshVariableGenerator)
{
  Module* module = context->root()->symbol()->getModule();
  int firstTargetSlot = module->getMinimumSubstitutionSize();
  //
  //	Only ground terms from the original dag can rewrite in place - non-ground terms will have instantiated copies made before rewriting.
  //
  context->root()->indexVariables(variableInfo, firstTargetSlot);
  // context->reduce();  // can introduce ground variables that won't have their flag set

  int nrVariables = variableInfo.getNrVariables();
  for (int i = 0; i < nrVariables; ++i)
    {
      VariableDagNode* v = variableInfo.index2Variable(i);
      if (freshVariableGenerator->variableNameConflict(v->id()))
	{
	  DagNode* d = v;
	  IssueWarning("unsafe variable name " << QUOTE(d) << " in variant narrowing problem.");
	  return;
	}
    }

  //Vector<DagNode*> firstVariant(nrVariables + 1);

  //
  //	Rename variables.
  //
  protectedVariant.resize(nrVariables);
  Substitution s(firstTargetSlot + nrVariables);
  for (int i = 0; i < nrVariables; ++i)
    {
      Sort* sort = safeCast(VariableSymbol*, variableInfo.index2Variable(i)->symbol())->getSort();
      VariableDagNode* v = new VariableDagNode(freshVariableGenerator->getBaseVariableSymbol(sort),
					       freshVariableGenerator->getFreshVariableName(i),
					       firstTargetSlot + i);
      protectedVariant[i] = v;
      s.bind(firstTargetSlot + i, v);
    }

  DagNode* newDag = context->root()->instantiate(s);  // not safe if we haven't determined ground terms in context->root()
  if (newDag == 0)
    newDag = context->root();
  
  RewritingContext* redContext = context->makeSubcontext(newDag);
  redContext->reduce();
  protectedVariant.append(redContext->root());
  context->addInCount(*redContext);
  delete redContext;

  //firstVariant[nrVariables] = newDag;
  // dumpVariant(firstVariant, 0, NONE);
  variantCollection.insertVariant(protectedVariant, 0, NONE);
  protectedVariant.resize(0);  // remove GC protection
  frontier.insert(0);
  currentIndex = 1;

  bool odd = true;
  for (;;)
    {
      FOR_EACH_CONST(i, VariantIndexSet, frontier)
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
  //  int nrVariables = variableInfo.getNrVariables();
  //  for (int i = 0; i < nrVariables; ++i)
  //    variableInfo.index2Variable(i)->mark();
  int substSize = protectedVariant.size();
  for (int i = 0; i < substSize; ++i)
    protectedVariant[i]->mark();
}

void
VariantSearch::expand(const Vector<DagNode*>& variant, int index, bool odd)
{
  int substSize = variant.size() - 1;
  RewritingContext* newContext = context->makeSubcontext(variant[substSize]);
  //
  //	We don't need to protect the DagNodes in this local copy since the are already protected
  //	by the VariantCollection.
  //
  Vector<DagNode*> variantSubstitution(substSize);
  for (int i = 0; i < substSize; ++i)
    variantSubstitution[i] = variant[i];

  VariantNarrowingSearchState vnss(newContext, variantSubstitution, freshVariableGenerator, odd, variableInfo);
  DagNode* variantTerm;
  Vector<DagNode*> newVariantSubstitution;

  //int nrFreeVariables;
  while (vnss.findNextVariant(variantTerm, newVariantSubstitution /*, nrFreeVariables */))
    {
      protectedVariant = newVariantSubstitution;  // deep copy to protect bindings from GC

      RewritingContext* redContext = context->makeSubcontext(variantTerm);
      redContext->reduce();
      int newIndex = currentIndex;
      ++currentIndex;

      protectedVariant.append(redContext->root());

      //dumpVariant(newVariant, newIndex, index);
      if (variantCollection.insertVariant(protectedVariant, newIndex, index))
	newFrontier.insert(newIndex);
      protectedVariant.resize(0);  // remove GC protection

      context->addInCount(*redContext);
      delete redContext;
    }
  context->addInCount(*newContext);
  delete newContext;
}

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
