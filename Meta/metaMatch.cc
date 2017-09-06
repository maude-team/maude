//
//	Code for metaMatch and metaXmatch descent functions.
//

local_inline bool
MetaLevelOpSymbol::getCachedMatchSearchState(MetaModule* m,
					     FreeDagNode* subject,
					     RewritingContext& context,
					     Int64 solutionNr,
					     MatchSearchState*& state,
					     Int64& lastSolutionNr)
{
  if (solutionNr > 0)
    {
      SearchState* s;
      if (m->remove(subject, context, s, lastSolutionNr))
	{
	  if (lastSolutionNr < solutionNr)
	    {
	      state = safeCast(MatchSearchState*, s);
	      return true;
	    }
	  delete s;
	}
    }
  return false;
}

local_inline MatchSearchState* 
MetaLevelOpSymbol::makeMatchSearchState(MetaModule* m,
					FreeDagNode* subject,
					RewritingContext& context) const
{
  Term* p;
  Term* s;
  if (metaLevel->downTermPair(subject->getArgument(1), subject->getArgument(2), p, s, m))
    {
      Vector<ConditionFragment*> condition;
      if (metaLevel->downCondition(subject->getArgument(3), m, condition))
	{
	  m->protect();
	  Pattern* pattern = new Pattern(p, false, condition);
	  RewritingContext* subjectContext = term2RewritingContext(s, context);
	  subjectContext->root()->computeTrueSort(*subjectContext);
	  context.addInCount(*subjectContext);
	  return new MatchSearchState(subjectContext,
				      pattern,
				      MatchSearchState::GC_PATTERN |
				      MatchSearchState::GC_CONTEXT |
				      MatchSearchState::GC_SUBSTITUTION);
	}
      s->deepSelfDestruct();
      p->deepSelfDestruct();
    }
  return 0;
}

bool
MetaLevelOpSymbol::metaMatch(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaMatch : Module Term Term Condition Nat ~> Substitution? .
  //
  Int64 solutionNr;
  if (MetaModule* m = metaLevel->downModule(subject->getArgument(0)))
    {
      if (metaLevel->downSaturate64(subject->getArgument(4), solutionNr))
	{
	  MatchSearchState* state;
	  Int64 lastSolutionNr;
	  if (getCachedMatchSearchState(m, subject, context, solutionNr, state, lastSolutionNr))
	    m->protect();  // Use cached state
	  else if ((state = makeMatchSearchState(m, subject, context)))
	    lastSolutionNr = -1;
	  else
	    return false;

	  DagNode* result;
	  while (lastSolutionNr < solutionNr)
	    {
	      bool success = state->findNextMatch();
	      state->transferCount(context);
	      if (!success)
		{
		  delete state;
		  result = metaLevel->upNoMatchSubst();
		  goto fail;
		}
	      ++lastSolutionNr;
	    }
	  m->insert(subject, state, solutionNr);
	  {
	    VariableInfo* variableInfo = state->getPattern();
	    Substitution* substitution = state->getContext();
	    PointerMap qidMap;
	    PointerMap dagNodeMap;
	    result = metaLevel->upSubstition(*substitution,
					     *variableInfo,
					     m,
					     qidMap,
					     dagNodeMap);
	  }
	fail:
	  (void) m->unprotect();
	  return context.builtInReplace(subject, result);
	}
    }
  return false;
}

local_inline MatchSearchState*
MetaLevelOpSymbol::makeMatchSearchState2(MetaModule* m,
                                         FreeDagNode* subject,
                                         RewritingContext& context) const
{
  int minDepth;
  int maxDepth;
  if (metaLevel->downSaturate(subject->getArgument(4), minDepth) &&
      metaLevel->downBound(subject->getArgument(5), maxDepth))
    {
      if (Term* p = metaLevel->downTerm(subject->getArgument(1), m))
        {
          if (Term* s = metaLevel->downTerm(subject->getArgument(2), m))
            {
              Vector<ConditionFragment*> condition;
              if (metaLevel->downCondition(subject->getArgument(3), m, condition))
                {
                  if (maxDepth == NONE)
                    maxDepth = UNBOUNDED;  // NONE means no extension for MatchSearchState
                  m->protect();
                  Pattern* pattern = new Pattern(p, true, condition);
                  RewritingContext* subjectContext = term2RewritingContext(s, context);
                  subjectContext->root()->computeTrueSort(*subjectContext);
                  context.addInCount(*subjectContext);
                  return new MatchSearchState(subjectContext,
                                              pattern,
                                              MatchSearchState::GC_PATTERN |
                                              MatchSearchState::GC_CONTEXT |
                                              MatchSearchState::GC_SUBSTITUTION,
                                              minDepth,
                                              maxDepth);
                }
              s->deepSelfDestruct();
            }
          p->deepSelfDestruct();
        }
    }
  return false;
}

bool
MetaLevelOpSymbol::metaXmatch(FreeDagNode* subject, RewritingContext& context)
{
  //
  //	op metaXmatch : Module Term Term Condition Nat Bound Nat ~> MatchPair? .
  //
  if (MetaModule* m = metaLevel->downModule(subject->getArgument(0)))
    {
      Int64 solutionNr;
      if (metaLevel->downSaturate64(subject->getArgument(6), solutionNr) &&
	  solutionNr >= 0)
	{
	  MatchSearchState* state;
	  Int64 lastSolutionNr;
	  if (getCachedMatchSearchState(m, subject, context, solutionNr, state, lastSolutionNr))
	    m->protect();  // Use cached state
	  else if ((state = makeMatchSearchState2(m, subject, context)))
	    lastSolutionNr = -1;
	  else
	    return false;

	  DagNode* result;
	  while (lastSolutionNr < solutionNr)
	    {
	      bool success = state->findNextMatch();
	      state->transferCount(context);
	      if (!success)
		{
		  delete state;
		  result = metaLevel->upNoMatchPair();
		  goto fail;
		}
	      ++lastSolutionNr;
	    }
	  m->insert(subject, state, solutionNr);
	  {
	    Pattern* pattern = state->getPattern();
	    Substitution* substitution = state->getContext();
	    Sort* sort = pattern->getLhs()->getSort();  // HACK
	    VariableSymbol* vs = safeCast(VariableSymbol*, m->instantiateVariable(sort));
	    DagNode* hole = new VariableDagNode(vs, 0);
	    DagNode* top = state->rebuildDag(hole);
	    result = metaLevel->upMatchPair(*substitution,
					    *pattern,
					    top,
					    hole,
					    m);
	  }
	fail:
	  (void) m->unprotect();
	  return context.builtInReplace(subject, result);
	}
    }
  return false;
}
