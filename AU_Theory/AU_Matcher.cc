//
//	Implementation for common parts of A/AU matcher.
//

bool
AU_LhsAutomaton::match(DagNode* subject,
		       Substitution& solution,
		       Subproblem*& returnedSubproblem,
		       ExtensionInfo* extensionInfo)
{
  if (subject->symbol() != topSymbol)
    {
      if (collapsePossible)
        return collapseMatch(subject, solution, returnedSubproblem, extensionInfo);
      return false;
    }
  Assert(matchAtTop == (extensionInfo != 0), cerr << "matchAtTop disagreement");
  
  AU_DagNode* s = static_cast<AU_DagNode*>(subject);
  int nrArgs = s->argArray.length();
  if (nrArgs < wholeLowerBound || nrArgs > wholeUpperBound)
    return false;
  leftPos = 0;
  rightPos = nrArgs - 1;
  flexLeftPos = 0;
  flexRightPos = flexPart.length() - 1;

  SubproblemAccumulator subproblems;
  AU_ExtensionInfo* e = static_cast<AU_ExtensionInfo*>(extensionInfo);
  if (e == 0)
    {
      if (!matchRigidPart(s, solution, subproblems) ||
	  (flexPart.length() != 0 &&
	   !checkForRigidEnds(s, solution, subproblems)))
	return false;
      int flexRemaining = flexRightPos - flexLeftPos + 1;
      if (flexRemaining == 0)
	{
	  DebugAdvisoryCheck(matchStrategy == GROUND_OUT,
			     cerr << "match strategy changed from " << matchStrategy <<
			     " to GROUND_OUT at match time (top symbol = \"" <<
			     topSymbol << "\")");
	  if (rightPos - leftPos + 1 != 0)
	    return false;
	  goto success;
	}
      if (flexRemaining == 1 && !(topSymbol->oneSidedId()))
	{
	  DebugAdvisoryCheck(matchStrategy == LONE_VARIABLE ||
			     matchStrategy == FAST_LONE_VARIABLE,
			     cerr << "match strategy changed from " << matchStrategy <<
			     " to LONE_VARIABLE at match time (top symbol = \"" <<
			     topSymbol << "\")");
	  Subproblem* sp;
	  if (!forcedLoneVariableCase(s, solution, sp))
	    return false;
	  subproblems.add(sp);
	  goto success;
	}
    }
  Assert(matchStrategy != GROUND_OUT &&
	 matchStrategy != LONE_VARIABLE &&
	 matchStrategy != FAST_LONE_VARIABLE, cerr << "bad strategy");
  determineRigidBlocks(solution);
  if (matchStrategy == GREEDY)
    {
      int r = greedyMatch(s, solution, e);
      if (r == false)
	return false;
      if (r == true)
	goto success;
    }
  if (!fullMatch(s, solution, subproblems, e))
    return false;
success:
  returnedSubproblem = subproblems.extractSubproblem();
  return true;
}

bool
AU_LhsAutomaton::matchRigidPart(AU_DagNode* subject,
				Substitution& solution,
				SubproblemAccumulator& subproblems)
{
  ArgVec<DagNode*>& args = subject->argArray;
  int nrRigid = rigidPart.length();
  for (int i = 0; i < nrRigid; i++)
    {
      Subterm& r = rigidPart[i];
      switch (r.type)
	{
	case VARIABLE:
	  {
	    TopVariable& tv = r.variable;
	    DagNode* b = solution.value(tv.index);
	    if (b != 0)
	      {
		//
		//	Bound variable case.
		//
		if (r.leftEnd)
		  {
		    if (!(subject->eliminateForward(b, leftPos, rightPos - flexLowerBound)))
		      return false;
		  }
		else
		  {
		    if (!(subject->eliminateBackward(b, rightPos, leftPos + flexLowerBound)))
		      return false;
		  }
	      }
	    else
	      {
		//
		//	Unbound non-identity unit variable case.
		//
		Assert(tv.upperBound == 1,
		       cerr << "unbound non-unit variable in rigid part");
		Assert(!(tv.takeIdentity),
		       cerr << "unbound variable which can take identity in rigid part");
		if (rightPos - leftPos < flexLowerBound)
		  return false;
		DagNode* d = args[r.leftEnd ? leftPos++ : rightPos--];
		if (!(d->leq(tv.sort)))
		  return false;
		solution.bind(tv.index, d);
	      }
	    break;
	  }
	case GROUND_ALIEN:
	  {
	    if (rightPos - leftPos < flexLowerBound ||
		!(r.groundAlien->equal(args[r.leftEnd ? leftPos++ : rightPos--])))
	      return false;
	    break;
	  }
	case NON_GROUND_ALIEN:
	  {
	    Subproblem* sp;
	    if (rightPos - leftPos < flexLowerBound ||
		!(r.alienAutomaton->
		  match(args[r.leftEnd ? leftPos++ : rightPos--], solution, sp)))
	      return false;
	    subproblems.add(sp);
	    break;
	  }
	}
    }
  return  rightPos - leftPos + 1 <= flexUpperBound;
}

bool
AU_LhsAutomaton::checkForRigidEnds(AU_DagNode* subject,
				   Substitution& solution,
				   SubproblemAccumulator& subproblems)
{
  int mustLeave = flexLowerBound;
  bool leftStalled = false;
  bool rightStalled = false;
  for(;;)
    {
      switch(checkLeftEnd(subject, solution, subproblems, mustLeave, rightStalled))
	{
	case false:
	  return false;
	case true:
	  {
	    if (flexLeftPos++ == flexRightPos)
	      return true;
	    break;
	  }
	case STALLED:
	  {
	    if (rightStalled)
	      return true;
	    leftStalled = true;
	    break;
	  }
	}
      switch(checkRightEnd(subject, solution, subproblems, mustLeave, leftStalled))
	{
	case false:
	  return false;
	case true:
	  {
	    if (flexLeftPos == flexRightPos--)
	      return true;
	    break;
	  }
	case STALLED:
	  {
	    if (leftStalled)
	      return true;
	    rightStalled = true;
	    break;
	  }
	}
    }
}

int
AU_LhsAutomaton::checkLeftEnd(AU_DagNode* subject,
			      Substitution& solution,
			      SubproblemAccumulator& subproblems,
			      int& mustLeave,
			      bool& rightStalled)
{
  Subterm& f = flexPart[flexLeftPos];
  switch (f.type)
    {
    case VARIABLE:
      {
	TopVariable& tv = f.variable;
	DagNode* b = solution.value(tv.index);
	if (b != 0)
	  {
	    if (!tv.takeIdentity)
	      --mustLeave;
	    return subject->eliminateForward(b, leftPos, rightPos - mustLeave);
	  }
	else if (tv.upperBound == 1 && !(tv.takeIdentity))
	  {
	    if (rightPos - leftPos < --mustLeave)
	      return false;
	    DagNode* d = subject->argArray[leftPos++];
	    if (!(d->leq(tv.sort)))
	      return false;
	    solution.bind(tv.index, d);
	    break;
	  }
	return STALLED;
      }
    case GROUND_ALIEN:
      {
	return rightPos - leftPos >= --mustLeave &&
	  f.groundAlien->equal(subject->argArray[leftPos++]);
      }
    case NON_GROUND_ALIEN:
      {
	Subproblem* sp;
	if (rightPos - leftPos < --mustLeave ||
	    !(f.alienAutomaton->match(subject->argArray[leftPos++], solution, sp)))
	  return false;
	subproblems.add(sp);
	rightStalled = false;  // we may have bound variable stalling right end
	break;
      }
    }
  return true;
}

int
AU_LhsAutomaton::checkRightEnd(AU_DagNode* subject,
			       Substitution& solution,
			       SubproblemAccumulator& subproblems,
			       int& mustLeave,
			       bool& leftStalled)
{
  Subterm& f = flexPart[flexRightPos];
  switch (f.type)
    {
    case VARIABLE:
      {
	TopVariable& tv = f.variable;
	DagNode* b = solution.value(tv.index);
	if (b != 0)
	  {
	    if (!tv.takeIdentity)
	      --mustLeave;
	    return subject->eliminateBackward(b, rightPos, leftPos + mustLeave);
	  }
	else if (tv.upperBound == 1 && !(tv.takeIdentity))
	  {
	    if (rightPos - leftPos < --mustLeave)
	      return false;
	    DagNode* d = subject->argArray[rightPos--];
	    if (!(d->leq(tv.sort)))
	      return false;
	    solution.bind(tv.index, d);
	    break;
	  }
	return STALLED;
      }
    case GROUND_ALIEN:
      {
	return rightPos - leftPos >= --mustLeave &&
	  f.groundAlien->equal(subject->argArray[rightPos--]);
      }
    case NON_GROUND_ALIEN:
      {
	Subproblem* sp;
	if (rightPos - leftPos < --mustLeave ||
	    !(f.alienAutomaton->match(subject->argArray[rightPos--], solution, sp)))
	  return false;
	leftStalled = false;  // we may have bound variable stalling left end
	subproblems.add(sp);
	break;
      }
    }
  return true;
}

bool
AU_LhsAutomaton::forcedLoneVariableCase(AU_DagNode* subject,
					Substitution& solution,
					Subproblem*& returnedSubproblem)
{
  Assert(flexPart[flexLeftPos].type == VARIABLE, cerr << "lone variable is not a variable");
  returnedSubproblem = 0;
  ArgVec<DagNode*>& args = subject->argArray;
  int nrSubjectsRemaining = rightPos - leftPos + 1;
  TopVariable& loneVariable = flexPart[flexLeftPos].variable;
  Assert(solution.value(loneVariable.index) == 0, cerr << "lone variable bound");

  if (nrSubjectsRemaining == 0)
    {
      if (!(loneVariable.takeIdentity))
	return false;
      DagNode* d = topSymbol->getIdentityDag();
      solution.bind(loneVariable.index, d);
      return (loneVariable.abstracted == 0) ? true :
	loneVariable.abstracted->match(d, solution, returnedSubproblem);
    }
  else if (nrSubjectsRemaining == 1)
    {
      DagNode* d = args[leftPos];
      solution.bind(loneVariable.index, d);
      return (loneVariable.abstracted == 0) ?
	(d->leq(loneVariable.sort)) :
	loneVariable.abstracted->match(d, solution, returnedSubproblem);
    }
  else if (matchStrategy != FAST_LONE_VARIABLE)
    {
      AU_DagNode* d = new AU_DagNode(topSymbol, nrSubjectsRemaining);
      int pos = 0;
      for (int i = leftPos; i <= rightPos; i++)
	d->argArray[pos++] = args[i];
      Assert(pos == nrSubjectsRemaining, cerr << "inconsistant number of subterms");
      solution.bind(loneVariable.index, d);
      if (loneVariable.abstracted != 0)
	return loneVariable.abstracted->match(d, solution, returnedSubproblem);
      if (d->checkSort(loneVariable.sort, returnedSubproblem))
	{
	  d->setProducedByAssignment();
	  if (subject->isReduced() && d->getSortIndex() != Sort::SORT_UNKNOWN)
	    d->setReduced();
	  return true;
	}
    }
  else
    {
      AU_DagNode* d = new AU_DagNode(topSymbol, nrSubjectsRemaining);
      d->setProducedByAssignment();
#ifdef SPEED_HACKS
      DagNode** source = args.rawBasePointer();
      DagNode** dest = d->argArray.rawBasePointer();
#else
      ArgVec<DagNode*>& source = args;
      ArgVec<DagNode*>& dest = d->argArray;
#endif
      int lastIndex = Sort::SORT_UNKNOWN;
      const Sort* cs = loneVariable.sort;
      int pos = 0;
      for (int i = leftPos; i <= rightPos; i++)
	{
	  DagNode* sd = source[i];
	  int index = sd->getSortIndex();
	  Assert(index != Sort::SORT_UNKNOWN, cerr << "bad sort");
	  if (index != lastIndex)
	    {
	      if (!(leq(index, cs)))
		return false;
	      lastIndex = index;
	    }
	  dest[pos++] = sd;
	}
      if (subject->isReduced() && topSymbol->sortConstraintFree())
	{
	  topSymbol->computeBaseSort(d);
	  d->setReduced();
	}
      solution.bind(loneVariable.index, d);
      return true;
    }
  return false;
}

void
AU_LhsAutomaton::determineRigidBlocks(Substitution& solution)
{
  RigidBlock r;
  r.start = NONE;
  r.nrSubjectsForUs = 0;
  r.nrSubjectsToLeave = 0;
  rigidBlocks.contractTo(0);
  nrSubjectsUsed = 0;
  int lastFlexPart = flexPart.length() - 1;
  int skip;
  for (int i = flexLeftPos; i <= flexRightPos; i += skip)
    {
      Subterm& f = flexPart[i];
      skip = f.blockLength;
      if (skip == NOT_FIXED)
	{
	  skip = 1;
	  f.variable.nastyBinding = NONE;
	  DagNode* d = solution.value(f.variable.index);
	  if (d == 0)
	    {
	      //
	      //	Unbound variable terminates current rigid block (if there is one).
	      //	We treat variables with nasty bindings as being unbound
	      //	since we can't be sure how many subjects they will match.
	      //
	      if (r.start != NONE)
		{
		  r.end = i - 1;
		  rigidBlocks.append(r);
		  r.start = NONE;
		  r.nrSubjectsForUs = 0;
		  r.nrSubjectsToLeave = 0;
		}
	      if (!(f.variable.takeIdentity))
		{
		  ++r.nrSubjectsToLeave;  // for this unbound variable
		  ++nrSubjectsUsed;
		}
	    }
	  else
	    {
	      bool nasty;
	      int n = topSymbol->
		calculateNrSubjectsMatched(d, i == 0, i == lastFlexPart, nasty);
	      nrSubjectsUsed += n;
	      if (nasty)
		{
		  DebugAdvisoryCheck(false, cerr << "nasty binding of " << d <<
				     " to variable with index " << f.variable.index <<
				     " detected in match phase");
		  Assert(matchAtTop,
			 cerr << "can't have nasty binding without extension");
		  //
		  //	Unbound variable terminates current rigid block (if there is one).
		  //	We treat variables with nasty bindings as being unbound
		  //	since we can't be sure how many subjects they will match.
		  //
		  if (r.start != NONE)
		    {
		      r.end = i - 1;
		      rigidBlocks.append(r);
		      r.start = NONE;
		      r.nrSubjectsForUs = 0;
		      r.nrSubjectsToLeave = 0;
		    }
		  r.nrSubjectsToLeave += n;
		  f.variable.nastyBinding = n;
		}
	      else
		{
		  r.nrSubjectsForUs += n;
		  if (r.start == NONE)
		    r.start = i;
		}
	    }
	}
      else
	{
	  r.nrSubjectsForUs += skip;
	  nrSubjectsUsed += skip;
	  if (r.start == NONE)
	    r.start = i;
	}   
    }
  //
  //	End of flex part terminates current rigid block (if there is one).
  //
  if (r.start != NONE)
    {
      Assert(matchAtTop, cerr << "missing extension");
      r.end = flexRightPos;
      rigidBlocks.append(r);
      nrSubjectsForRightVars = 0;
    }
  else
    nrSubjectsForRightVars = r.nrSubjectsToLeave;
}
