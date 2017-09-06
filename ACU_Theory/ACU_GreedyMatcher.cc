//
//      Implementation for greedy AC/ACU matcher.
//

int
ACU_LhsAutomaton::greedyMatch(ACU_DagNode* subject,
			      Substitution& solution,
			      ACU_ExtensionInfo* extensionInfo)
{
  ArgVec<ACU_DagNode::Pair>& args = subject->argArray;
  int nrArgs = args.length();
  local.copy(solution);  // greedy matching is speculative so make a copy
  scratch.copy(solution);  // keep a scratch copy as well
  int nrNonGroundAliens = nonGroundAliens.length();
  for (int i = 0; i < nrNonGroundAliens; i++)
    {
      NonGroundAlien& nga = nonGroundAliens[i];
      Term* t = nga.term;
      LhsAutomaton* a = nga.automaton;
      int m = nga.multiplicity;
      for (int j = (t == 0) ? 0 : subject->findFirstPotentialMatch(t, solution);
	   j < nrArgs; j++)
	{
	  DagNode* d = args[j].dagNode;
	  if (t != 0 && t->partialCompare(solution, d) == Term::GREATER)
	    break;
	  if (subjects[j].multiplicity >= m)
	    {
	      Subproblem *sp;
	      if (a->match(d, scratch, sp))
		{
		  if (sp != 0)
		    {
		      //
		      //	On a hiding to nothing so pack up and go home.
		      //
		      delete sp;
		      return UNDECIDED;
		    }
		  local.copy(scratch);  // preserve any new bindings
		  subjects[j].multiplicity -= m;
		  goto nextNonGroundAlien;
		}
	      scratch.copy(local);  // restore scratch copy
	    }
	}
      return (i < nrIndependentAliens) ? false : int(UNDECIDED);
    nextNonGroundAlien:
      ;
    }
  if (greedyPureMatch(subject, local, extensionInfo, true) == true)
    {
      solution.copy(local);
      return true;
    }
  return UNDECIDED;
}

int
ACU_LhsAutomaton::greedyPureMatch(ACU_DagNode* subject,
				  Substitution& solution,
				  ACU_ExtensionInfo* extensionInfo,
				  bool returnUndecidedOnFail)
{
  ArgVec<ACU_DagNode::Pair>& args = subject->argArray;
  int nrArgs = args.length();
  //
  //	Try to find at least one subject assignable to each variable.
  //
  {
    int nrTopVariables = topVariables.length();
    for (int i = 0; i < nrTopVariables; i++)
      {
	TopVariable& tv = topVariables[i];
	if (solution.value(tv.index) == 0)
	  {
	    int m = tv.multiplicity;
	    for (int j = 0; j < nrArgs; j++)
	      {
		if (subjects[j].multiplicity >= m &&
		    args[j].dagNode->leq(tv.sort))
		  {
		    subjects[j].multiplicity -= m;
		    tv.firstSubject = j;
		    tv.nrSubjects = 1;
		    goto nextVariable;
		  }
	      }
	    if (tv.takeIdentity)
	      {
		tv.firstSubject = NONE;
		tv.nrSubjects = 0;
	      }
	    else
	      {
		//
		//	If we fail on some variable which cannot take identity we
		//	have to return UNDECIDED unless:
		//	(1) all variables upto the present one have sorts in increasing
		//	    order and have either pure sorts or sorts with bound 1; and
		//	(2) the variable we fail on has multiplicity 1.
		//
		if (returnUndecidedOnFail || m != 1 ||
		    (tv.structure != AssociativeSymbol::PURE_SORT && tv.upperBound != 1))
		  return UNDECIDED;
		Sort* nextSort = tv.sort;
	        for (i--; i >= 0; i--)
		  {
		    TopVariable& tv = topVariables[i];
		    if (solution.value(tv.index) == 0)
		      {
			if (tv.structure != AssociativeSymbol::PURE_SORT && tv.upperBound != 1)
			  return UNDECIDED;
			if (!(leq(tv.sort, nextSort)))
			  return UNDECIDED;
			nextSort = tv.sort;
		      }
		  }
		return false;
	      }
	  }
      nextVariable:
	;
      }
  }
  //
  //	Now we have to deal with any unassigned subjects.
  //
  int extensionAssignments = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      int sm = subjects[i].multiplicity;
      if (sm > 0)
	{
	  DagNode* d = args[i].dagNode;
	  for (int j = lastUnboundVariable; j != NONE;)
	    {
	      TopVariable& tv = topVariables[j];
	      int m = tv.multiplicity;
	      if (tv.structure >= AssociativeSymbol::LIMIT_SORT &&
		  d->leq(tv.sort) &&
		  (m == 1 || (sm % m) == 0))
		{
		  subjects[i].assignee = j;
		  if (tv.firstSubject == i)
		    {
		      //
		      //	Slight of hand to make building normal form
		      //	substitutions easier in this tricky special case
		      //
		      tv.firstSubject = NONE;
		      subjects[i].multiplicity += m;
		    }
		  else
		    ++tv.nrSubjects;
		  goto nextSubject;
		}
	      j = tv.prevUnbound;
	    }
	  //
	  //	Need to fix failure mode
	  //
	  if (extensionInfo != 0)
	    {
	      extensionAssignments += sm;
	      if (extensionAssignments <= extensionInfo->getUpperBound())
		{
		  subjects[i].assignee = NONE;
		  goto nextSubject;
		}
	    }
	  //
	  //	If we fail to assign a subject to some variable or the extension we
	  //	have to return UNDECIDED unless:
	  //	(1) all variables have either pure sorts or sorts with bound 1; and
	  //	(2) for every pure sorted variable with multiplicity > 1 there is
	  //	    a variable of multiplicity 1 with greater or equal sort.
	  //
	  //	For implementation purposes we simplify (2) by insisting that
	  //	all pure sorted variables have multiplicity 1.
	  //
	  if (returnUndecidedOnFail)
	    return UNDECIDED;
	  for (int j = lastUnboundVariable; j != NONE; j = topVariables[j].prevUnbound)
	    {
	      TopVariable& tv = topVariables[j];
	      if (tv.upperBound != 1 &&
		  !(tv.structure == AssociativeSymbol::PURE_SORT && tv.multiplicity == 1))
		return UNDECIDED;
	    }
	  return false;
	}
    nextSubject:
      ;
    }
  //
  //	Now we actually build the assignments we computed in the two previous steps.
  //
  bool buildReducedNodes = subject->isReduced() && topSymbol->sortConstraintFree();
  for (int i = lastUnboundVariable; i != NONE; i = topVariables[i].prevUnbound)
    {
      TopVariable& tv = topVariables[i];
      int index = tv.index;
      int firstSubject = tv.firstSubject;
      int nrSubjects = tv.nrSubjects;
      Assert(solution.value(index) == 0, cerr << "unbound variable is bound");
      if (nrSubjects == 1 && firstSubject != NONE)
	solution.bind(index, args[firstSubject].dagNode);
      else if (nrSubjects == 0)
	solution.bind(index, topSymbol->getIdentityDag());
      else
	{     
	  int m = tv.multiplicity;
	  ACU_DagNode* d = new ACU_DagNode(topSymbol, nrSubjects);
	  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
	  int pos = 0;
	  for (int j = 0; j < nrArgs; j++)
	    {
	      Subject& s = subjects[j];
	      int sm = s.multiplicity;
	      if (sm > 0 && s.assignee == i)
		{
		  ACU_DagNode::Pair& p = d->argArray[pos];
		  p.dagNode = args[j].dagNode;
		  p.multiplicity = (m == 1) ? sm : (sm / m);
		  ++pos;
		}
	      else if (j == firstSubject)
		{
		  ACU_DagNode::Pair& p = d->argArray[pos];
		  p.dagNode = args[j].dagNode;
		  p.multiplicity = 1;
		  ++pos;
		}
	    }
	  Assert(pos == nrSubjects, cerr << "inconsistant number of subjects");
	  if (buildReducedNodes)  // really want to check that variable occurs in rhs/cond
	    {
	      //
	      //	This is an optimization; if the ACU subject is fully reduced then
	      //	any piece of it is also fully reduced and if there are no
	      //	sort constraints applicable to the top symbol we can compute the
	      //	true sort and mark the new node as reduced to avoid wasted future
	      //	normalization and matching attempts.
	      //
	      topSymbol->computeBaseSort(d);
	      d->setReduced();
	    }
	  solution.bind(index, d);
	}
    }
  //
  //	Finally we build extension info if it is needed/
  //
  if (extensionInfo != 0)
    {
      extensionInfo->setValidAfterMatch(true);
      extensionInfo->setMatchedWhole(true);
      bool partial = false;
      for (int i = 0; i < nrArgs; i++)
	{
	  int m = subjects[i].multiplicity;
	  if (m > 0 && subjects[i].assignee == NONE)
	    {
	      if (!partial)
		{
		  extensionInfo->setMatchedWhole(false);
		  extensionInfo->clear();
		  partial = true;
		}
	      extensionInfo->setUnmatched(i, m);
	    }
	}
    }
  return true;
}
