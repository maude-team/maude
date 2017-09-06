//
//	Code for metaSearch descent function.
//

local_inline bool
MetaLevelOpSymbol::downSearchType(DagNode* arg,
				  RewriteSequenceSearch::SearchType& searchType) const
{
  int qid;
  if (metaLevel->downQid(arg, qid))
    {
      if (qid == Token::encode("+"))
	searchType = RewriteSequenceSearch::AT_LEAST_ONE_STEP;
      else if (qid == Token::encode("*"))
	searchType = RewriteSequenceSearch::ANY_STEPS;
      else if (qid == Token::encode("!"))
	searchType = RewriteSequenceSearch::NORMAL_FORM;
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
  if (solutionNr > 0)
    {
      if (m->remove(subject, context, search, lastSolutionNr))
	{
	  if (lastSolutionNr < solutionNr)
	    return true;
	  delete search;
	}
    }
  return false;
}

local_inline RewriteSequenceSearch*
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
