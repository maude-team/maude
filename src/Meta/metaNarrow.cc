/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

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
//	Code for metaNarrow descent function.
//

local_inline bool
MetaLevelOpSymbol::getCachedNarrowingSequenceSearch(MetaModule* m,
						    FreeDagNode* subject,
						    RewritingContext& context,
						    Int64 solutionNr,
						    NarrowingSequenceSearch*& search,
						    Int64& lastSolutionNr)
{
  CacheableState* cachedState;
  if (m->remove(subject, cachedState, lastSolutionNr))
    {
      if (lastSolutionNr <= solutionNr)
	{
	  search = safeCast(NarrowingSequenceSearch*, cachedState);
	  //
	  //	The parent context pointer of the root context in the
	  //	NarrowingSequenceSearch is possibly stale.
	  //
	  safeCast(UserLevelRewritingContext*, search->getContext())->
	    beAdoptedBy(safeCast(UserLevelRewritingContext*, &context));
	  return true;
	}
      delete cachedState;
    }
  return false;
}

NarrowingSequenceSearch*
MetaLevelOpSymbol::makeNarrowingSequenceSearch(MetaModule* m,
					       FreeDagNode* subject,
					       RewritingContext& context) const
{
  RewriteSequenceSearch::SearchType searchType;
  int maxDepth;
  if (downSearchType(subject->getArgument(3), searchType) &&
      metaLevel->downBound(subject->getArgument(4), maxDepth))
    {
      Term* s;
      Term* g;
      if (metaLevel->downTermPair(subject->getArgument(1), subject->getArgument(2), s, g, m))
	{
	  m->protect();
	  Pattern* goal = new Pattern(g, false);
	  RewritingContext* subjectContext = term2RewritingContext(s, context);
	  context.addInCount(*subjectContext);
	  return new NarrowingSequenceSearch(subjectContext,
					     searchType,
					     goal,
					     maxDepth,
					     NarrowingSearchState::ALLOW_NONEXEC,
					     new FreshVariableSource(m, 0));
	  // not needed unless we support conditions
	  //g->deepSelfDestruct();
	  //s->deepSelfDestruct();
	}
    }
  return 0;
}

bool
MetaLevelOpSymbol::metaNarrow(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaNarrow : Module Term Term Qid Bound Nat ~> ResultTriple? .
  //
  if (MetaModule* m = metaLevel->downModule(subject->getArgument(0)))
    {
      Int64 solutionNr;
      if (metaLevel->downSaturate64(subject->getArgument(5), solutionNr) &&
	  solutionNr >= 0)
	{
	  NarrowingSequenceSearch* state;
	  Int64 lastSolutionNr;
	  if (getCachedNarrowingSequenceSearch(m, subject, context, solutionNr, state, lastSolutionNr))
	    m->protect();  // Use cached state
	  else if ((state = makeNarrowingSequenceSearch(m, subject, context)))
	    lastSolutionNr = -1;
	  else
	    return false;

	  DagNode* result;
	  while (lastSolutionNr < solutionNr)
	    {
	      bool success = state->findNextMatch();
	      //state->transferCount(context);
	      if (!success)
		{
		  result = metaLevel->upFailureTriple(state->isIncomplete());
		  delete state;
		  goto fail;
		}
	      ++lastSolutionNr;
	    }
	  m->insert(subject, state, solutionNr);
	  {
	    result = metaLevel->upResultTriple(state->getStateDag(),
					       *(state->getSubstitution()),
					       *(state->getGoal()),
					       m);
	  }
	fail:
	  (void) m->unprotect();
	  return context.builtInReplace(subject, result);
	}
    }
  return false;
}

NarrowingSequenceSearch*
MetaLevelOpSymbol::makeNarrowingSequenceSearch2(MetaModule* m,
						FreeDagNode* subject,
						RewritingContext& context) const
{
  RewriteSequenceSearch::SearchType searchType;
  int maxDepth;
  bool singlePosition;
  if (downSearchType(subject->getArgument(2), searchType) &&
      metaLevel->downBound(subject->getArgument(3), maxDepth) &&
      metaLevel->downBool(subject->getArgument(4), singlePosition))
    {
      if (Term* s = metaLevel->downTerm(subject->getArgument(1), m))
	{
	  m->protect();
	  RewritingContext* subjectContext = term2RewritingContext(s, context);
	  context.addInCount(*subjectContext);
	  return new NarrowingSequenceSearch(subjectContext,
					     searchType,
					     0,
					     maxDepth,
					     (singlePosition ?
					     NarrowingSearchState::ALLOW_NONEXEC | NarrowingSearchState::SINGLE_POSITION :
					     NarrowingSearchState::ALLOW_NONEXEC),
					     new FreshVariableSource(m, 0));
	}
    }
  return 0;
}

bool
MetaLevelOpSymbol::metaNarrow2(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaNarrow : Module Term Qid Bound Bool Nat ~> ResultPair? .
  //
  if (MetaModule* m = metaLevel->downModule(subject->getArgument(0)))
    {
      Int64 solutionNr;
      if (metaLevel->downSaturate64(subject->getArgument(5), solutionNr) &&
	  solutionNr >= 0)
	{
	  NarrowingSequenceSearch* state;
	  Int64 lastSolutionNr;
	  if (getCachedNarrowingSequenceSearch(m, subject, context, solutionNr, state, lastSolutionNr))
	    m->protect();  // Use cached state
	  else if ((state = makeNarrowingSequenceSearch2(m, subject, context)))
	    lastSolutionNr = -1;
	  else
	    return false;

	  DagNode* result;
	  while (lastSolutionNr < solutionNr)
	    {
	      bool success = state->findNextMatch();
	      //state->transferCount(context);
	      if (!success)
		{
		  delete state;
		  result = metaLevel->upFailurePair();
		  goto fail;
		}
	      ++lastSolutionNr;
	    }
	  m->insert(subject, state, solutionNr);
	  //
	  //	We up the dag using variable mapping so each result gets previously unused variables.
	  //
	  metaLevel->startVariableMapping(state->getVariableTotalForPreviouslyReturnedStates() - m->getMinimumSubstitutionSize(),
					  state->getFreshVariableGenerator());
	  result = metaLevel->upResultPair(state->getStateDag(), m);
	  metaLevel->stopVariableMapping();

	fail:
	  (void) m->unprotect();
	  return context.builtInReplace(subject, result);
	}
    }
  return false;
}

local_inline bool
MetaLevelOpSymbol::getCachedNarrowingSearchState2(MetaModule* m,
						  FreeDagNode* subject,
						  RewritingContext& context,
						  Int64 solutionNr,
						  NarrowingSearchState2*& search,
						  Int64& lastSolutionNr)
{
  CacheableState* cachedState;
  if (m->remove(subject, cachedState, lastSolutionNr))
    {
      if (lastSolutionNr <= solutionNr)
	{
	  search = safeCast(NarrowingSearchState2*, cachedState);
	  //
	  //	The parent context pointer of the root context in the
	  //	NarrowingSequenceSearch is possibly stale.
	  //
	  safeCast(UserLevelRewritingContext*, search->getContext())->
	    beAdoptedBy(safeCast(UserLevelRewritingContext*, &context));
	  return true;
	}
      delete cachedState;
    }
  return false;
}

NarrowingSearchState2*
MetaLevelOpSymbol::makeNarrowingSearchState2(MetaModule* m,
					     FreeDagNode* subject,
					     RewritingContext& context) const
{
  int label;
  int variableFamilyName;
  if (metaLevel->downQid(subject->getArgument(2), label) &&
      metaLevel->downQid(subject->getArgument(4), variableFamilyName))
    {
      int variableFamily = FreshVariableSource::getFamily(variableFamilyName);
      if (variableFamily == NONE)
	return 0;

      if (Term* t = metaLevel->downTerm(subject->getArgument(1), m))
	{
	  Vector<Term*> blockerTerms;
	  if (!metaLevel->downTermList(subject->getArgument(3), m, blockerTerms))
	    {
	      t->deepSelfDestruct();
	      return 0;
	    }

	  m->protect();

	  RewritingContext* subjectContext = term2RewritingContext(t, context);
	  subjectContext->reduce();
	  context.addInCount(*subjectContext);

	  Vector<DagNode*> blockerDags; 
	  FOR_EACH_CONST(i, Vector<Term*>, blockerTerms)
	    {
	      Term* t = *i;
	      t = t->normalize(true);  // we don't really need to normalize but we do need to set hash values
	      blockerDags.append(t->term2Dag());
	      t->deepSelfDestruct();
	    }

	  return new NarrowingSearchState2(subjectContext,
					   blockerDags,
					   new FreshVariableSource(m, 0),
					   variableFamily,
					   label);
	}
    }
  return 0;
}

bool
MetaLevelOpSymbol::metaNarrowingApply(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaNarrowingApply : Module Term Qid TermList Qid Nat -> NarrowingResult?
  //
  //	Arguments:
  //	  Module to work in
  //	  Term to narrow (after reducing)
  //	  Qid giving label of rules to use
  //	  TermList of blocker terms for variant unification
  //	  Qid giving fresh variable family that might appear in Term (and which will be avoided for result)
  //	  Nat giving which of many solutions is wanted
  //
  //	A successful narrowing application yields a 6-tuple:
  //	  op {_,_,_,_,_,_} : Term Type Substitution Substitution Context Qid -> NarrowingResult [ctor] .
  //	where the arguments are:
  //	  Term after narrowing and reducing
  //	  Type of Term
  //	  Substitution into the original term
  //	  Substitution into the rule used for narrowing
  //	  Context in the original term where narrowing took place
  //	  Qid giving fresh variable family used to express result Term and Substitutions
  //
  if (MetaModule* m = metaLevel->downModule(subject->getArgument(0)))
    {
      Int64 solutionNr;
      if (metaLevel->downSaturate64(subject->getArgument(5), solutionNr) &&
	  solutionNr >= 0)
	{
	  NarrowingSearchState2 *state;
	  Int64 lastSolutionNr;
	  if (getCachedNarrowingSearchState2(m, subject, context, solutionNr, state, lastSolutionNr))
	    m->protect(); 
	  else if ((state = makeNarrowingSearchState2(m, subject, context)))
	    lastSolutionNr = -1;
	  else
	    return false;

	  DagNode* result;
	  bool actualStep = lastSolutionNr < solutionNr;
	  while (lastSolutionNr < solutionNr)
	    {
	      bool success = state->findNextNarrowing();
	      context.transferCount(*(state->getContext()));
	      if (!success)
		{
		  result = metaLevel->upNarrowingFailure(state->isIncomplete());
		  delete state;
		  goto fail;
		}
	      ++lastSolutionNr;
	    }
	  m->insert(subject, state, solutionNr);
	  {
	    const Substitution& unifier = state->getSubstitution();
	    //
	    //	getNarrowedDag() guarantees that hole appears exactly once
	    //	in the returned dag, even if the rule used had a bare variable
	    //	for its rhs, and that bare variable could share its binding
	    //	with other variables in the dag being narrowed.
	    //
	    DagNode* hole;
	    DagNode* replacementContext;
	    DagNode* narrowedDag = state->getNarrowedDag(hole, replacementContext);
	    //
	    //	If we're going to trace, we show the trace of the narrowing
	    //	step before any reductions we do on it.
	    //
	    if (actualStep)
	      {
		context.incrementNarrowingCount();
		if (RewritingContext::getTraceStatus())
		  {
		    //
		    //	We pass the active term and variable info. This means
		    //	the version with (potentially) renamed variables. We do this for
		    //	consistancy since the replaced dag will be expressed in those
		    //	same variables.
		    //
		    RewritingContext* subjectContext = state->getActiveContext();
		    const NarrowingVariableInfo& narrowingVariableInfo = state->getActiveVariableInfo();
		    subjectContext->traceNarrowingStep(state->getRule(),
						       state->getReplacedDag(),
						       hole,  // replacement
						       &narrowingVariableInfo,  // original variable names
						       &unifier,
						       narrowedDag);
		    if (subjectContext->traceAbort())
		      {
			(void) m->unprotect();
			return false;
		      }
		  }
	      }
	    //
	    //	Can't use dagNodeMap after reduce since the from dagNodes might be
	    //	garbage collected or even rewritten in place.
	    //
	    PointerMap qidMap;
	    PointerMap dagNodeMap;
	    DagRoot metaContext(metaLevel->upContext(replacementContext, m, hole, qidMap, dagNodeMap));
	    //
	    //	Need to reduce narrowedDag.
	    //
	    RewritingContext* resultContext =
	      context.makeSubcontext(narrowedDag, UserLevelRewritingContext::META_EVAL);
	    resultContext->reduce();
	    context.addInCount(*resultContext);
	    //
	    //	unifier is a mapping from slots to bindings.
	    //	ruleVariableInfo maps between slots and rule variables.
	    //	narrowingVariableInfo maps between slots and original target variables.
	    //
	    const NarrowingVariableInfo& narrowingVariableInfo = state->getVariableInfo();
	    const VariableInfo* ruleVariableInfo = state->getRule();
	    int variableFamily = state->getVariableFamily();
	    int variableFamilyName = FreshVariableSource::getBaseName(variableFamily);
	    result = metaLevel->upNarrowingResult(resultContext->root(),
						  metaContext.getNode(),
						  unifier,
						  *ruleVariableInfo,
						  narrowingVariableInfo,
						  variableFamilyName,
						  m);
	    delete resultContext;
	  }
	fail:
	  (void) m->unprotect();
	  return context.builtInReplace(subject, result);
	}
    }
  return false;
}
