//
//      Implementation for AC/ACU matcher that works on red-black trees.
//

local_inline int
ACU_LhsAutomaton::eliminateBoundVariables(Substitution& solution)
{
  nrUnboundVariables = 0;
  Term* identity = topSymbol->getIdentity();
  FOR_EACH_CONST(i, Vector<TopVariable>, topVariables)
    {
      DagNode* d = solution.value(i->index);
      if (d != 0)
	{
	  if (d->symbol() == topSymbol)
	    return UNDECIDED;
	  if (identity == 0 || !(identity->equal(d)))
	    {
	      ACU_SlowIter j;
	      if (current == 0 || !ACU_RedBlackNode::find(current, d, j))
		return false;
	      int multiplicity = i->multiplicity;
	      if (j.getMultiplicity() < multiplicity)
		return false;
	      current = ACU_RedBlackNode::consDelete(j, multiplicity);
	      matchedMultiplicity += multiplicity;
	    }
	}
      else
	++nrUnboundVariables;
    }
  return true;
}

local_inline bool
ACU_LhsAutomaton::eliminateGroundAliens()
{
  FOR_EACH_CONST(i, Vector<GroundAlien>, groundAliens)
    {
      ACU_SlowIter j;
      if (current == 0 || !ACU_RedBlackNode::find(current, i->term, j))
	return false;
      int multiplicity = i->multiplicity;
      if (j.getMultiplicity() < multiplicity)
	return false;
      current = ACU_RedBlackNode::consDelete(j, multiplicity);
      matchedMultiplicity += multiplicity;
    }
  return true;
}

local_inline bool
ACU_LhsAutomaton::eliminateGroundedOutAliens(Substitution& solution)
{
  FOR_EACH_CONST(i, Vector<NonGroundAlien>, groundedOutAliens)
    {
      Term* t = i->term;
      Assert(t != 0, "shouldn't be running on unstable terms");
      ACU_SlowIter j;
      if (current != 0 &&
	  ACU_RedBlackNode::findFirstPotentialMatch(current, t, solution, j))
	{
	  LhsAutomaton* a = i->automaton;
	  DagNode* d = j.getDagNode();
	  do
	    {
	      Subproblem* sp;
	      if (a->match(d, solution, sp))
		{
		  Assert(sp == 0, "grounded out alien gave rise to subproblem!");
		  int multiplicity = i->multiplicity;
		  if (j.getMultiplicity() < multiplicity)
		    return false;
		  current = ACU_RedBlackNode::consDelete(j, multiplicity);
		  matchedMultiplicity += multiplicity;
		  goto nextGroundedOutAlien;
		}
	      j.next();
	      if (!j.valid())
		break;
	      d = j.getDagNode();
	    }
	  while (t->partialCompare(solution, d) != Term::GREATER);
	}
      return false;
    nextGroundedOutAlien:
      ;
    }
  return true;
}

int
ACU_LhsAutomaton::greedyMatch(ACU_TreeDagNode* subject,
			      Substitution& solution,
			      ACU_ExtensionInfo* extensionInfo)
{
  local.copy(solution);  // greedy matching is speculative so make a copy
  scratch.copy(solution);  // keep a scratch copy as well
  FOR_EACH_CONST(i, Vector<NonGroundAlien>, nonGroundAliens)
    {
      Term* t = i->term;
      Assert(t != 0, "shouldn't be running on unstable terms");
      ACU_SlowIter j;
      if (current != 0 &&
	  ACU_RedBlackNode::findFirstPotentialMatch(current, t, solution, j))
	{
	  int multiplicity = i->multiplicity;
	  LhsAutomaton* a = i->automaton;
	  DagNode* d = j.getDagNode();
	  do
	    {
	      if (j.getMultiplicity() >= multiplicity)
		{
		  Subproblem* sp;
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
		      current = ACU_RedBlackNode::consDelete(j, multiplicity);
		      matchedMultiplicity += multiplicity;
		      goto nextNonGroundAlien;
		    }
		  scratch.copy(local);  // restore scratch copy
		}
	      j.next();
	      if (!j.valid())
		break;
	      d = j.getDagNode();
	    }
	  while (t->partialCompare(solution, d) != Term::GREATER);
	}
      return ((i - nonGroundAliens.begin()) < nrIndependentAliens) ?
	false : UNDECIDED;
    nextNonGroundAlien:
      ;
    }
  if (greedyPureMatch(subject, local, extensionInfo))
    {
      solution.copy(local);
      return true;
    }
  //
  //	When the pure matching step fails we always treat it as
  //	UNDECIDED for safety.
  //
  return UNDECIDED;
}

local_inline bool
ACU_LhsAutomaton::tryToBindVariable(const TopVariable& tv,
				    Substitution& solution)
{
  //
  //	Try to assign one thing to variable.
  //
  int multiplicity = tv.multiplicity;
  if (multiplicity == 1)
    {
      //
      //	Choose first subject with low enough sort.
      //
      ACU_SlowIter j(current);
      do
	{
	  DagNode* d = j.getDagNode();
	  if (d->leq(tv.sort))
	    {
	      solution.bind(tv.index, d);
	      current = ACU_RedBlackNode::consDelete(j, 1);
	      ++matchedMultiplicity;
	      return true;
	    }
	  j.next();
	}
      while (j.valid());
    }
  else
    {
      //
      //	Try first subject with high enough
      //	multiplicity and give up if sort too big.
      //
      ACU_SlowIter j;
      if (ACU_RedBlackNode::findGeqMult(current, multiplicity, j))
	{
	  DagNode* d = j.getDagNode();
	  if (d->leq(tv.sort))
	    {
	      solution.bind(tv.index, d);
	      current = ACU_RedBlackNode::consDelete(j, multiplicity);
	      matchedMultiplicity += multiplicity;
	      return true;
	    }
	}
    }
  //
  //	If we weren't able to assign a subject we can still
  //	try the identity element.
  //
  if (tv.takeIdentity)
    {
      solution.bind(tv.index, topSymbol->getIdentityDag());
      return true;
    }
  return false;
}

DagNode*
ACU_LhsAutomaton::makeHighMultiplicityAssignment(int multiplicity,
						 Sort* sort,
						 ACU_RedBlackNode*& root)
{
  ACU_SlowIter i;
  if (!ACU_RedBlackNode::findGeqMult(root, multiplicity, i))
    return 0;
  DagNode* d = i.getDagNode();
  int currentSortIndex = d->getSortIndex();
  if (!leq(currentSortIndex, sort))
    return 0;
  //
  //	We have a legal assignment; now try to find a "better" one.
  //
  int m = i.getMultiplicity();
  int a = m / multiplicity;
  Assert(a > 0, "multiplicity error");
  if (a > 1)
    {
      currentSortIndex = topSymbol->computeMultSortIndex(currentSortIndex,
							 currentSortIndex,
							 a - 1);
      if (!leq(currentSortIndex, sort))
	{
	  root = ACU_RedBlackNode::consDelete(i, multiplicity);
	  return d;  // quit trying to improve substitution
	}
    }
  //
  //	We build the details in the reusable matched vector.
  //
  matched.clear();
  do
    {
      matched.append(ACU_DagNode::Pair(d, a));
      root = ACU_RedBlackNode::consDelete(i, a * multiplicity);
      if (root == 0 ||
	  !ACU_RedBlackNode::findGeqMult(root, multiplicity, i))
	break;
      d = i.getDagNode();
      m = i.getMultiplicity();
      a = m / multiplicity;
      Assert(a > 0, "multiplicity error");
      currentSortIndex = topSymbol->computeMultSortIndex(currentSortIndex,
							 d->getSortIndex(),
							 a);
    }
  while (leq(currentSortIndex, sort));
  //
  //	Now make the assignment.
  //
  int nrMatched = matched.length();
  if (nrMatched == 1 && matched[0].multiplicity == 1)
    return matched[0].dagNode;

  ACU_DagNode* d2 = new ACU_DagNode(topSymbol, nrMatched);
  d2->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
  ArgVec<ACU_DagNode::Pair>::iterator dest = d2->argArray.begin();
  FOR_EACH_CONST(i, Vector<ACU_DagNode::Pair>, matched)
    *dest++ = *i;
  return d2;
}

local_inline bool
ACU_LhsAutomaton::tryToBindLastVariable(ACU_TreeDagNode* subject,
					const TopVariable& tv,
					Substitution& solution)
{
  int multiplicity = tv.multiplicity;
  if (multiplicity == 1)
    {
      if (current->getSize() == 1 && current->getMultiplicity() == 1)
	{
	  //
	  //	Just one subject left so try to assign it.
	  //
	  DagNode* d = current->getDagNode();
	  if (d->leq(tv.sort))
	    {
	      solution.bind(tv.index, d);
	      current = 0;  // no need to update matchedMultiplicity
	      return true;
	    }
	}
      else
	{
	  {
	    //
	    //	First see if we can give it everything.
	    //
	    ACU_TreeDagNode* t = new ACU_TreeDagNode(topSymbol, current);
	    int index = t->treeComputeBaseSort();
	    if (leq(index, tv.sort))
	      {
		if (subject->isReduced() && topSymbol->sortConstraintFree())
		  {
		    t->setSortIndex(index);
		    t->setReduced();
		  }
		solution.bind(tv.index, t);
		current = 0;  // no need to update matchedMultiplicity
		return true;
	      }
	  }
	  if (matchAtTop && matchedMultiplicity >= 1)
	    {
	      //
	      //	Plan B: We must have extension so try assigning
	      //	just one subject.
	      //
	      ACU_SlowIter j(current);
	      do
		{
		  DagNode* d = j.getDagNode();
		  if (d->leq(tv.sort))
		    {
		      solution.bind(tv.index, d);
		      current = ACU_RedBlackNode::consDelete(j, 1);
		      ++matchedMultiplicity;
		      return true;
		    }
		  j.next();
		}
	      while (j.valid());
	    }
	}
    }
  else
    {
      //
      //	Last unbound variable has multiplicity >= 2.
      //
      if (matchAtTop)
	{
	  DagNode* d = makeHighMultiplicityAssignment(multiplicity,
						      tv.sort,
						      current);
	  if (d != 0)
	    {
	      solution.bind(tv.index, d);
	      matchedMultiplicity = 2;  // wrong but good enough
	      return true;
	    }
	}
      else
	{
	  int size = current->getSize();
	  if (size == 1 && current->getMultiplicity() == multiplicity)
	    {
	      DagNode* d = current->getDagNode();
	      if (d->leq(tv.sort))
		{
		  solution.bind(tv.index, d);
		  current = 0;  // no need to update matchedMultiplicity
		  return true;
		}
	      return false;
	    }

	  ACU_DagNode* d = new ACU_DagNode(topSymbol, current->getSize());
	  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
	  ArgVec<ACU_DagNode::Pair>::iterator dest = d->argArray.begin();
	  ACU_SlowIter i(current); 
	  do
	    {
	      int m = i.getMultiplicity();
	      if (m % multiplicity != 0)
		return false;
	      dest->dagNode = i.getDagNode();
	      dest->multiplicity = m / multiplicity;
	      ++dest;
	      i.next();
	    }
	  while (i.valid());
	  int index = d->argVecComputeBaseSort();
	  if (!leq(index, tv.sort))
	    return false;
	  if (subject->isReduced() && topSymbol->sortConstraintFree())
	    {
	      d->setSortIndex(index);
	      d->setReduced();
	    }
	  solution.bind(tv.index, d);
	  current = 0;  // no need to update matchedMultiplicity
	  return true;
	}
    }
  //
  //	Last hope: see if we can assign the identity.
  //
  if (matchAtTop && matchedMultiplicity >= 2 && tv.takeIdentity)
    {
      solution.bind(tv.index, topSymbol->getIdentityDag());
      return true;
    }
  return false;
}

bool
ACU_LhsAutomaton::greedyPureMatch(ACU_TreeDagNode* subject,
				  Substitution& solution,
				  ACU_ExtensionInfo* extensionInfo)
{
  //
  //	Greedy pure matching can fail for so many reasons
  //	in the red-black case, we don't bother trying to
  //	detect true failure: false always means UNDECIDED.
  //
  FOR_EACH_CONST(i, Vector<TopVariable>, topVariables)
    {
      if (solution.value(i->index) == 0)
	{
	  --nrUnboundVariables;
	  if (current == 0)
	    {
	      if (!(i->takeIdentity))
		return false;
	      solution.bind(i->index, topSymbol->getIdentityDag());
	      if (nrUnboundVariables == 0)
		break;
	    }
	  else
	    {
	      if (nrUnboundVariables == 0)
		{
		  if (!tryToBindLastVariable(subject, *i, solution))
		    return false;
		  break;
		}
	      else
		{
		  if (!tryToBindVariable(*i, solution))
		    return false;
		}
	    }
	}
    }

  if (current == 0)
    {
      //
      //	Everything matched; fill out empty extension if needed.
      //
      if (extensionInfo != 0)
	{
	  extensionInfo->setValidAfterMatch(true);
	  extensionInfo->setMatchedWhole(true);
	}
    }
  else
    {
      //
      //	Stuff left over; see if we can put it in the extension.
      //
      if (extensionInfo != 0 && matchedMultiplicity >= 2)
	{
	  extensionInfo->setValidAfterMatch(true);
	  extensionInfo->setMatchedWhole(false);
	  if (current->getSize() == 1 && current->getMultiplicity() == 1)
	    extensionInfo->setUnmatched(current->getDagNode());
	  else
	    extensionInfo->setUnmatched(new ACU_TreeDagNode(topSymbol, current));
	}
      else
	return false;
    }
  return true;
}

int
ACU_LhsAutomaton::redBlackMatch(ACU_TreeDagNode* subject,
				Substitution& solution,
				Subproblem*& returnedSubproblem,
				ACU_ExtensionInfo* extensionInfo)
{
  Assert(maxPatternMultiplicity <= ACU_RedBlackNode::SAT_MULT,
	 "shouldn't be running with maxPatternMultiplicity of " <<
	 maxPatternMultiplicity);
  
  current = subject->getRoot();
  if (current->getMaxMult() < maxPatternMultiplicity)
    return false;
  //
  //	Eliminate subpatterns that must match a specific subterm
  //	in the subject.
  //
  matchedMultiplicity = 0;  // so we know when we've matched at least 2 subjects
  int r = eliminateBoundVariables(solution);
  if (r != true)
    return r;
  if (!eliminateGroundAliens() || !eliminateGroundedOutAliens(solution))
    return false;
  if (extensionInfo == 0 && nrUnboundVariables == 1 && nonGroundAliens.empty())
    {
      //
      //	Forced lone variable case.
      //
      FOR_EACH_CONST(i, Vector<TopVariable>, topVariables)
	{
	  if (solution.value(i->index) == 0)
	    return forcedLoneVariableCase(subject, *i, solution, returnedSubproblem);
	}
      CantHappen("didn't find unbound variable");
    }
  //
  //	Match everything else using greedy algorithms.
  //
  return greedyMatch(subject, solution, extensionInfo);
}

bool
ACU_LhsAutomaton::forcedLoneVariableCase(ACU_TreeDagNode* subject,
					 const TopVariable& tv,
					 Substitution& solution,
					 Subproblem*& returnedSubproblem)
{
  if (current == 0)
    {
      //
      //	Special case: assign identity.
      //
      if (tv.takeIdentity)
	{
	  solution.bind(tv.index, topSymbol->getIdentityDag());
	  return true;
	}
      return false;
    }

  int multiplicity = tv.multiplicity;
  if (current->getSize() == 1 && current->getMultiplicity() == multiplicity)
    {
      //
      //	Special case: assign one subject.
      //
      DagNode* d = current->getDagNode();
      if (d->leq(tv.sort))
	{
	  solution.bind(tv.index, d);
	  return true;
	}
      return false;
    }
  //
  //	General case: need to assign everything.
  //
  ACU_BaseDagNode* b;
  if (multiplicity == 1)
    b = new ACU_TreeDagNode(topSymbol, current);
  else
    {
      ACU_DagNode* d = new ACU_DagNode(topSymbol, current->getSize());
      ArgVec<ACU_DagNode::Pair>::iterator dest = d->argArray.begin();
      ACU_SlowIter i(current); 
      do
	{
	  int m = i.getMultiplicity();
	  if (m % multiplicity != 0)
	    return false;
	  dest->dagNode = i.getDagNode();
	  dest->multiplicity = m / multiplicity;
	  ++dest;
	  i.next();
	}
      while (i.valid());
      d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
      b = d;
    }
  if (b->checkSort(tv.sort, returnedSubproblem))
    {
      solution.bind(tv.index, b);
      if (subject->isReduced() && b->getSortIndex() != Sort::SORT_UNKNOWN)
	b->setReduced();
      return true;
    }
  return false;
}
