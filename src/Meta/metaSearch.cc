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
//	Code for metaSearch()/metaSearchPath() descent functions.
//

local_inline bool
MetaLevelOpSymbol::downSearchType(DagNode* arg, SequenceSearch::SearchType& searchType) const
{
  int qid;
  if (metaLevel->downQid(arg, qid))
    {
      if (qid == Token::encode("+"))
	searchType = SequenceSearch::AT_LEAST_ONE_STEP;
      else if (qid == Token::encode("*"))
	searchType = SequenceSearch::ANY_STEPS;
      else if (qid == Token::encode("!"))
	searchType = SequenceSearch::NORMAL_FORM;
      else
	return false;
      return true;
    }
  return false;
}

local_inline bool
MetaLevelOpSymbol::getCachedRewriteSequenceSearch(MetaModule* m,
						  FreeDagNode* subject,
						  RewritingContext& context,
						  Int64 solutionNr,
						  RewriteSequenceSearch*& search,
						  Int64& lastSolutionNr)
{
  CacheableState* cachedState;
  if (m->remove(subject, cachedState, lastSolutionNr))
    {
      DebugAdvisory("looking for solution #" << solutionNr << " and found cached solution #" << lastSolutionNr);
      if (lastSolutionNr <= solutionNr)
	{
	  search = safeCast(RewriteSequenceSearch*, cachedState);
	  //
	  //	The parent context pointer of the root context in the
	  //	RewriteSequenceSearch object may be stale, since the
	  //	object may have been cached in a different context.
	  //
	  safeCast(UserLevelRewritingContext*, search->getContext())->
	    beAdoptedBy(safeCast(UserLevelRewritingContext*, &context));
	  return true;
	}
      delete cachedState;
    }
  return false;
}

RewriteSequenceSearch*
MetaLevelOpSymbol::makeRewriteSequenceSearch(MetaModule* m,
					     FreeDagNode* subject,
					     RewritingContext& context) const
{
  RewriteSequenceSearch::SearchType searchType;
  int maxDepth;
  if (downSearchType(subject->getArgument(4), searchType) &&
      metaLevel->downBound(subject->getArgument(5), maxDepth))
    {
      Term* s;
      Term* g;
      if (metaLevel->downTermPair(subject->getArgument(1), subject->getArgument(2), s, g, m))
	{
	  Vector<ConditionFragment*> condition;
	  if (metaLevel->downCondition(subject->getArgument(3), m, condition))
	    {
	      m->protect();
	      Pattern* goal = new Pattern(g, false, condition);
	      RewritingContext* subjectContext = term2RewritingContext(s, context);
	      context.addInCount(*subjectContext);
	      return new RewriteSequenceSearch(subjectContext,
					       searchType,
					       goal,
					       maxDepth);
	    }
	  g->deepSelfDestruct();
	  s->deepSelfDestruct();
	}
    }
  return 0;
}

bool
MetaLevelOpSymbol::metaSearch(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaSearch : Module Term Term Condition Qid Bound Nat ~> ResultTriple? .
  //
  if (MetaModule* m = metaLevel->downModule(subject->getArgument(0)))
    {
      Int64 solutionNr;
      if (metaLevel->downSaturate64(subject->getArgument(6), solutionNr) &&
	  solutionNr >= 0)
	{
	  RewriteSequenceSearch* state;
	  Int64 lastSolutionNr;
	  if (getCachedRewriteSequenceSearch(m, subject, context, solutionNr, state, lastSolutionNr))
	    m->protect();  // Use cached state
	  else if ((state = makeRewriteSequenceSearch(m, subject, context)))
	    lastSolutionNr = -1;
	  else
	    return false;

	  DagNode* result;
	  while (lastSolutionNr < solutionNr)
	    {
	      bool success = state->findNextMatch();
	      state->transferCount(context);
	      Verbose("metaSearch: visited " << state->getNrStates() << " states.");
	      if (!success)
		{
		  delete state;
		  result = metaLevel->upFailureTriple();
		  goto fail;
		}
	      ++lastSolutionNr;
	    }
	  m->insert(subject, state, solutionNr);
	  {
	    result = metaLevel->upResultTriple(state->getStateDag(state->getStateNr()),
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

bool
MetaLevelOpSymbol::metaSearchPath(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaSearchPath : Module Term Term Condition Qid Bound Nat ~> Trace? .
  //
  if (MetaModule* m = metaLevel->downModule(subject->getArgument(0)))
    {
      Int64 solutionNr;
      if (metaLevel->downSaturate64(subject->getArgument(6), solutionNr) &&
	  solutionNr >= 0)
	{
	  RewriteSequenceSearch* state;
	  Int64 lastSolutionNr;
	  if (getCachedRewriteSequenceSearch(m, subject, context, solutionNr, state, lastSolutionNr))
	    m->protect();  // Use cached state
	  else if ((state = makeRewriteSequenceSearch(m, subject, context)))
	    lastSolutionNr = -1;
	  else
	    return false;

	  DagNode* result;
	  while (lastSolutionNr < solutionNr)
	    {
	      bool success = state->findNextMatch();
	      state->transferCount(context);
	      Verbose("metaSearchPath: visited " << state->getNrStates() << " states.");
	      if (!success)
		{
		  delete state;
		  result = metaLevel->upFailureTrace();
		  goto fail;
		}
	      ++lastSolutionNr;
	    }
	  m->insert(subject, state, solutionNr);
	  result = metaLevel->upTrace(*state, m);
	fail:
	  (void) m->unprotect();
	  return context.builtInReplace(subject, result);
	}
    }
  return false;
}

#include "SMT_Info.hh"
#include "variableGenerator.hh"
#include "SMT_RewriteSearchState.hh"

local_inline bool
MetaLevelOpSymbol::getCachedSMT_RewriteSearchState(MetaModule* m,
						   FreeDagNode* subject,
						   RewritingContext& context,
						   Int64 solutionNr,
						   SMT_RewriteSearchState*& search,
						   Int64& lastSolutionNr)
{
  CacheableState* cachedState;
  if (m->remove(subject, cachedState, lastSolutionNr))
    {
      if (lastSolutionNr <= solutionNr)
	{
	  search = safeCast(SMT_RewriteSearchState*, cachedState);
	  //
	  //	The parent context pointer of the root context in the
	  //	NarrowingSequenceSearch is possibly stale.
	  //
	  // FIX ME
	  safeCast(UserLevelRewritingContext*, search->getContext())->
	    beAdoptedBy(safeCast(UserLevelRewritingContext*, &context));
	  DebugAdvisory("   !!! Found cached SMT_RewriteSearchState !!!");
	  return true;
	}
      delete cachedState;
    }
  return false;
}

SMT_RewriteSearchState*
MetaLevelOpSymbol::makeSMT_RewriteSearchState(MetaModule* m,
					      FreeDagNode* subject,
					      RewritingContext& context) const
{
  DagNode* metaVarNumber = subject->getArgument(3);
  RewriteSequenceSearch::SearchType searchType;  // HACK
  int maxDepth;
  if (metaLevel->isNat(metaVarNumber) &&
      downSearchType(subject->getArgument(2), searchType) &&
      searchType == RewriteSequenceSearch::AT_LEAST_ONE_STEP &&  // HACK
      metaLevel->downBound(subject->getArgument(4), maxDepth) &&
      maxDepth == 1)
    {
      if (Term* term = metaLevel->downTerm(subject->getArgument(1), m))
	{
	  m->protect();
	  const mpz_class& varNumber = metaLevel->getNat(metaVarNumber);
	  RewritingContext* subjectContext = term2RewritingContext(term, context);

	  const SMT_Info& smtInfo = m->getSMT_Info();
	  VariableGenerator* vg = new VariableGenerator(smtInfo);
	  DebugAdvisory("   !!! Made cached SMT_RewriteSearchState !!!");
	  return new SMT_RewriteSearchState(subjectContext,
					    smtInfo,
					    *vg,
					    varNumber,
					    SMT_RewriteSearchState::GC_ENGINE | SMT_RewriteSearchState::GC_CONTEXT);
	}
    }
  return 0;
}

bool
MetaLevelOpSymbol::metaSmtSearch(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaSmtSearch : Module Term Qid Nat Bound Nat ~> SmtResult? 
  //
  if (MetaModule* m = metaLevel->downModule(subject->getArgument(0)))
    {
      if (m->validForSMT_Rewriting())
	{
	  Int64 solutionNr;
	  if (metaLevel->downSaturate64(subject->getArgument(5), solutionNr) &&
	      solutionNr >= 0)
	    {
	      SMT_RewriteSearchState* smtState;
	      Int64 lastSolutionNr;
	      if (getCachedSMT_RewriteSearchState(m, subject, context, solutionNr, smtState, lastSolutionNr))
		m->protect();  // Use cached state
	      else if ((smtState = makeSMT_RewriteSearchState(m, subject, context)))
		lastSolutionNr = -1;
	      else
		return false;

	      DagNode* result;
	      while (lastSolutionNr < solutionNr)
		{
		  bool success = smtState->findNextRewrite();
		  if (!success)
		    {
		      delete smtState;
		      result = metaLevel->upSmtFailure();
		      goto fail;
		    }
		  context.incrementRlCount();
		  ++lastSolutionNr;
		}
	      m->insert(subject, smtState, solutionNr);
	      {
		result = metaLevel->upSmtResult(smtState->getNewPair(),
						smtState->getMaxVariableNumber(),
						m);
	      }
	    fail:
	      (void) m->unprotect();
	      return context.builtInReplace(subject, result);
	    }
	}
    }
  return false;
}
