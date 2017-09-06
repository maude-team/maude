//
//	Implementation for A/AU matcher that works on deques.
//

int
AU_LhsAutomaton::dequeMatch(AU_DequeDagNode* subject,
			    Substitution& solution,
			    Subproblem*& returnedSubproblem)
{
  //
  //	We only handle lone variable case.
  //
  Assert(flexPart.length() == 1, "bad flex part length " << flexPart.length());
  Assert(flexPart[0].type == VARIABLE, "flex part not a variable");
  //
  //	First match rigid part.
  //
  AU_Deque remainder(subject->getDeque());
  int nrArgs = remainder.length();
  if (nrArgs < wholeLowerBound || nrArgs > wholeUpperBound)
    return false;

  SubproblemAccumulator subproblems;
  Term* identity = topSymbol->getIdentity();

  FOR_EACH_CONST(i, Vector<Subterm>, rigidPart)
    {
      switch (i->type)
	{
	case VARIABLE:
	  {
	    const TopVariable& tv = i->variable;
	    DagNode* b = solution.value(tv.index);
	    if (b != 0)
	      {
		//
		//	Bound variable case.
		//
		if (b->symbol() == topSymbol)
		  return UNDECIDED;
		if (identity == 0 || !(identity->equal(b)))
		  {
		    if (tv.takeIdentity)
		      {
			//
			//	Need to redo bounds check as something that
			//	might have taken identity used up an argument.
			//
			--nrArgs;
			if (nrArgs < wholeLowerBound)
			  return false;
		      }
		    if (i->leftEnd)
		      {
			if (b->equal(remainder.topLeft()))
			  remainder.popLeft();
			else
			  return false;
		      }
		    else
		      {
			if (b->equal(remainder.topRight()))
			  remainder.popRight();
			else
			  return false;
		      }
		  }
	      }
	    else
	      {
		//
		//	Unbound non-identity unit variable case.
		//
		Assert(tv.upperBound == 1,
		       "unbound non-unit variable in rigid part");
		Assert(!(tv.takeIdentity),
		       "unbound variable which can take identity in rigid part");
		DagNode* d;
		if (i->leftEnd)
		  {
		    d = remainder.topLeft();
		    if (!(d->leq(tv.sort)))
		      return false;
		    remainder.popLeft();
		  }
		else
		  {
		    d = remainder.topRight();
		    if (!(d->leq(tv.sort)))
		      return false;
		    remainder.popRight();
		  }
		solution.bind(tv.index, d);
	      }
	    break;
	  }
	case GROUND_ALIEN:
	  {
	    if (i->leftEnd)
	      {
		if (i->groundAlien->equal(remainder.topLeft()))
		  remainder.popLeft();
		else
		  return false;
	      }
	    else
	      {
		if (i->groundAlien->equal(remainder.topRight()))
		  remainder.popRight();
		else
		  return false;
	      }
	    break;
	  }
	case NON_GROUND_ALIEN:
	  {
	    Subproblem* sp;
	    if (i->leftEnd)
	      {
		if (i->alienAutomaton->match(remainder.topLeft(), solution, sp))
		  remainder.popLeft();
		else
		  return false;
	      }
	    else
	      {
		if (i->alienAutomaton->match(remainder.topRight(), solution, sp))
		  remainder.popRight();
		else
		  return false;
	      }
	    subproblems.add(sp);
	    break;
	  }
	}
    }
  //
  //	Now deal with flex part.
  //
  Assert(remainder.length() >= flexLowerBound, "lower bound problem");
  if (remainder.length() > flexUpperBound)
    return false;
  DagNode* d;
  switch (remainder.length())
    {
    case 0:
      {
	Assert(identity != 0, "no identity");
	d = topSymbol->getIdentityDag();
	break;
      }
    case 1:
      {
	d = remainder.topLeft();
	break;
      }
    default:
      {
	d = new AU_DequeDagNode(topSymbol, remainder);
	break;
      }
    }
  
  TopVariable& tv = flexPart[0].variable;
  DagNode* b = solution.value(tv.index);
  if (b == 0)
    {
      Subproblem* sp;
      if (tv.abstracted != 0)
	{
	  if (!(tv.abstracted->match(d, solution, sp)))
	    return false;
	}
      else
	{
	  if (!(d->checkSort(tv.sort, sp)))
	    return false;
	  if (subject->isReduced() && d->getSortIndex() != Sort::SORT_UNKNOWN)
	    d->setReduced();
	  solution.bind(tv.index, d);
	}
      subproblems.add(sp);
    }
  else
    {
      if (!(b->equal(d)))
	return false;
    }
  returnedSubproblem = subproblems.extractSubproblem();
  return true;
}
