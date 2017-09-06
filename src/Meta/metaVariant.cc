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
//	Code for variant narrowing descent functions.
//
#include "variantSearch.hh"

local_inline bool
MetaLevelOpSymbol::getCachedVariantSearch(MetaModule* m,
					  FreeDagNode* subject,
					  RewritingContext& context,
					  Int64 solutionNr,
					  VariantSearch*& search,
					  Int64& lastSolutionNr)
{
  if (solutionNr > 0)
    {
      CacheableState* cachedState;
      if (m->remove(subject, cachedState, lastSolutionNr))
	{
	  if (lastSolutionNr <= solutionNr)
	    {
	      search = safeCast(VariantSearch*, cachedState);
	      //
	      //	The parent context pointer of the root context in the VariantSearch is possibly
	      //	stale since it points the context from a different descent function call.
	      //
	      safeCast(UserLevelRewritingContext*, search->getContext())->
		beAdoptedBy(safeCast(UserLevelRewritingContext*, &context));
	      return true;
	    }
	  delete cachedState;
	}
    }
  return false;
}

bool
MetaLevelOpSymbol::metaGenerateVariant(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaGenerateVariant : Module Term Nat Nat ~> Variant? .
  //
  if (MetaModule* m = metaLevel->downModule(subject->getArgument(0)))
    {
      DagNode* metaVarIndex = subject->getArgument(2);
      Int64 solutionNr;
      if (metaLevel->isNat(metaVarIndex) &&
	  metaLevel->downSaturate64(subject->getArgument(3), solutionNr) &&
	  solutionNr >= 0)
	{
	  const mpz_class& varIndex = metaLevel->getNat(metaVarIndex);

	  VariantSearch* vs;
	  Int64 lastSolutionNr;
	  if (getCachedVariantSearch(m, subject, context, solutionNr, vs, lastSolutionNr))
	    m->protect();  // Use cached state
	  else if (Term* start = metaLevel->downTerm(subject->getArgument(1),  m))
	    {
	      m->protect();
	      RewritingContext* startContext = term2RewritingContext(start, context);
	      vs = new VariantSearch(startContext, new FreshVariableSource(m, varIndex));
	      lastSolutionNr = -1;
	    }
	  else
	    return false;

	  DagNode* result;
	  const Vector<DagNode*>* variant;
	  int nrFreeVariables;
	  while (lastSolutionNr < solutionNr)
	    {
	      variant = vs->getNextVariant(nrFreeVariables);
	      if (variant == 0)
		{
		  delete vs;
		  result = metaLevel->upNoVariant();
		  goto fail;
		}

	      context.transferCount(*(vs->getContext()));
	      ++lastSolutionNr;
	    }
	  {
	    m->insert(subject, vs, solutionNr);
	    mpz_class lastVarIndex = varIndex + nrFreeVariables;
	    result = metaLevel->upVariant(*variant, vs->getVariableInfo(), lastVarIndex, m);
	  }
	fail:
	  (void) m->unprotect();
	  return context.builtInReplace(subject, result);
	}
    }
  return false;
}

bool
MetaLevelOpSymbol::metaVariantUnify(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaVariantUnify : Module UnificationProblem Nat Nat ~> UnificationPair? .
  //
  return context.builtInReplace(subject, metaLevel->upNoUnifierPair());  // stub
}

bool
MetaLevelOpSymbol::metaVariantDisjointUnify(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaVariantDisjointUnify : Module UnificationProblem Nat Nat ~> UnificationTriple? .
  //
  return context.builtInReplace(subject, metaLevel->upNoUnifierTriple());  // stub
}
