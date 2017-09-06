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
//	Implementation for class NarrowingSearchState.
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
#include "rhsAutomaton.hh"
#include "lhsAutomaton.hh"
#include "subproblem.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "equation.hh"
#include "freshVariableGenerator.hh"
#include "dagArgumentIterator.hh"
#include "extensionInfo.hh"

//	variable class definitions
#include "variableDagNode.hh"

//	higher class definitions
#include "narrowingUnificationProblem.hh"
#include "variantNarrowingSearchState.hh"

VariantNarrowingSearchState::VariantNarrowingSearchState(RewritingContext* context,  // contains the variant term
							 const Vector<DagNode*>& variantSubstitution,
							 FreshVariableGenerator* freshVariableGenerator,
							 bool odd,
							 const NarrowingVariableInfo& originalVariables)
  :  PositionState(context->root(), 0, 0, UNBOUNDED),
     context(context),
     variantSubstitution(variantSubstitution),
     freshVariableGenerator(freshVariableGenerator),
     originalVariables(originalVariables),
     module(context->root()->symbol()->getModule())
{
  //
  //	Index all variables occuring in the variant term and the variant subsitution.
  //	These VariableDagNodes are coming from dags that are assumed to be protected by the caller and thus we assume
  //	are safe from garbage collection.
  //
  int firstTargetSlot = module->getMinimumSubstitutionSize();
  context->root()->indexVariables(variableInfo, firstTargetSlot);
  FOR_EACH_CONST(i, Vector<DagNode*>, variantSubstitution)
    (*i)->indexVariables(variableInfo, firstTargetSlot);

  int nrInterestingVariables = variableInfo.getNrVariables();
  unifiers = new UnifierFilter(firstTargetSlot, variableInfo.getNrVariables());
  //
  //	Generate all unifiers between subterms in our variant term and equations in our module and insert them in our unifier filter.
  //
  while (findNextPosition())
    {
      DagNode* d = getDagNode();

      //cout << "looking at subterm: " << d << endl;

      if (dynamic_cast<VariableDagNode*>(d) != 0)
	continue;  // don't unify at variable positions

      int positionIndex = getPositionIndex();
      //cout << "has position " << positionIndex << endl;
      //
      //	If the top symbol is unstable, we need to consider all the equations, rather than just the ones indexed under the top symbol.
      //
      Symbol* s = d->symbol();
      const Vector<Equation*>& equations = s->isStable() ? s->getEquations() : module->getEquations();

      FOR_EACH_CONST(i, Vector<Equation*>, equations)
	{
	  Equation* eq = *i;
	  if (eq->isVariant())
	    {
	      int equationIndex = eq->getIndexWithinModule();
	      NarrowingUnificationProblem* unificationProblem = new NarrowingUnificationProblem(eq,
												d,
												variableInfo,
												freshVariableGenerator,
												odd);
	      while (unificationProblem->findNextUnifier())
		{
		  const Substitution& solution = unificationProblem->getSolution();
		  //
		  //	Unifier filter requires that each interesting variable have the sorts computed in its binding
		  //	so that subsumption checking (matching) can happen.
		  //
		  for (int j = 0; j < nrInterestingVariables; ++j)
		    solution.value(firstTargetSlot + j)->computeTrueSort(*context);
		  unifiers->insertUnifier(solution, positionIndex, equationIndex /*, unificationProblem->getNrFreeVariables() */);
		}
	      delete unificationProblem;
	    }
	}
    }
}

VariantNarrowingSearchState::~VariantNarrowingSearchState()
{
  delete unifiers;
}

bool
VariantNarrowingSearchState::findNextVariant(DagNode*& newVariantTerm, Vector<DagNode*>& newVariantSubstitution /*, int& nrFreeVariables */)
{
  int variantSubstitutionSize = variantSubstitution.size();
  newVariantSubstitution.resize(variantSubstitutionSize);

  Substitution* survivor;
  int positionIndex;
  int equationIndex;
  while (unifiers->getNextSurvivingUnifier(survivor, positionIndex, equationIndex /*, nrFreeVariables */))
    {
      for (int i = 0; i < variantSubstitutionSize; ++i)
	{
	  DagNode* d = variantSubstitution[i]->instantiate(*survivor);
	  if (d == 0)
	    d = variantSubstitution[i];  // no change
	  d->computeTrueSort(*context);  // also handles theory normalization
	  if (reducibleByVariantEquation(d))
	    goto nextUnifier;
	  newVariantSubstitution[i] = d;
	}
      {
	Equation* eq = module->getEquations()[equationIndex];
	DagNode* replacement = eq->getRhsBuilder().construct(*survivor);
	//
	//	Any slots we touched while building at right hand instance we don't care about; they occur after the binding to
	//	the variables in the equation and before the bindings to the variables in the original variant.
	//
	int firstVariantVariable = module->getMinimumSubstitutionSize();
	int lastVariantVariable = firstVariantVariable + variableInfo.getNrVariables() - 1;
	newVariantTerm = rebuildAndInstantiateDag(replacement, *survivor, firstVariantVariable, lastVariantVariable, positionIndex).first;

	if (RewritingContext::getTraceStatus())
	  {
	    context->traceVariantNarrowingStep(eq,
					       variantSubstitution,
					       getDagNode(positionIndex),
					       replacement,
					       variableInfo,
					       survivor,
					       newVariantTerm,
					       newVariantSubstitution,
					       originalVariables);
	    if (context->traceAbort())
	      return false;
	  }
	context->incrementVariantNarrowingCount();

	return true;
      }
    nextUnifier:
      ;
    }
  return false;
}

bool
VariantNarrowingSearchState::reducibleByVariantEquation(DagNode* dag)
{
  //
  //	If it is already reduce wrt all equations it clearly can't be reduced by a variant equation.
  //
  if (dag->isReduced())
    return false;
  //
  //	Naive and inefficient approach.
  //
  for (DagArgumentIterator a(dag); a.valid(); a.next())
    {
      if (reducibleByVariantEquation(a.argument()))
	return true;
    }

  Subproblem* sp;
  ExtensionInfo* extensionInfo = dag->makeExtensionInfo();

  const Vector<Equation*>& equations = dag->symbol()->getEquations();
  FOR_EACH_CONST(i, Vector<Equation*>, equations)
    {
      Equation* eq = *i;
      if (eq->isVariant())
	{
	  int nrVariables = eq->getNrProtectedVariables();
	  context->clear(nrVariables);
	  if (eq->getLhsAutomaton()->match(dag, *context, sp, extensionInfo))
	    {
	      if (sp == 0 || sp->solve(true, *context))
		{
		  delete extensionInfo;
		  delete sp;
		  return true;
		}
	      delete sp;
	    }
	}
    }
  delete extensionInfo;
  return false;
}
