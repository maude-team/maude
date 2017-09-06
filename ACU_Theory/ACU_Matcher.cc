//
//      Implementation for main AC/ACU matcher
//

local_inline bool
ACU_LhsAutomaton::multiplicityChecks(ACU_DagNode* subject)
{
  //
  //	Copy argument multiplicities and check for trivial failure.
  //	Because this turns out to be one of the most expensive steps for
  //	AC/ACU rewriting we use hacks.
  //
  int nrArgs = subject->argArray.length();
  CONST_ARG_VEC_HACK(ACU_DagNode::Pair, args, subject->argArray);
  if (maxPatternMultiplicity > 1)
    {
      //
      //	Because failure here is common we check this first.
      //
      for (int i = 0; i < nrArgs; i++)
	{
	  if (args[i].multiplicity >= maxPatternMultiplicity)
	    goto okay;
	}
      return false;
    }
okay:
  currentMultiplicity.resize(nrArgs);
  Vector<int>::iterator cm = currentMultiplicity.begin();
  int totalSubjectMultiplicity = 0;
  for (int i = 0; i < nrArgs; i++, ++cm)
    {
      int m = args[i].multiplicity;
      *cm = m;
      totalSubjectMultiplicity += m;
    }
  if (totalSubjectMultiplicity < totalLowerBound ||
      totalSubjectMultiplicity > totalUpperBound)
    return false;
  totalMultiplicity = totalSubjectMultiplicity;
  return true;
}

local_inline bool
ACU_LhsAutomaton::eliminateGroundAliens(ACU_DagNode* subject)
{
  int nrGroundAliens = groundAliens.length();
  for (int i = 0; i < nrGroundAliens; i++)
    {
      int pos;
      if (!(subject->binarySearch(groundAliens[i].term , pos)) ||
	  (currentMultiplicity[pos] -= groundAliens[i].multiplicity) < 0)
	return false;
    }
  return true;
}

local_inline bool
ACU_LhsAutomaton::eliminateBoundVariables(ACU_DagNode* subject,
					  Substitution& solution)
{
  int nrTopVariables = topVariables.length();
  lastUnboundVariable = NONE;
  for (int i = 0; i < nrTopVariables; i++)
    {
      DagNode* d = solution.value(topVariables[i].index);
      if (d != 0)
	{
	  if (!(subject->
		eliminateSubject(d, topVariables[i].multiplicity, currentMultiplicity)))
	    return false;
	}
      else
	{
	  topVariables[i].prevUnbound = lastUnboundVariable;
	  lastUnboundVariable = i;
	}
    }
  return true;
}

local_inline bool
ACU_LhsAutomaton::eliminateGroundedOutAliens(ACU_DagNode* subject,
					     Substitution& solution)
{
  ArgVec<ACU_DagNode::Pair>& args = subject->argArray;
  int nrArgs = args.length();
  int nrGroundedOutAliens = groundedOutAliens.length();
  for (int i = 0; i < nrGroundedOutAliens; i++)
    {
      NonGroundAlien& goa = groundedOutAliens[i];
      Symbol* s = goa.topSymbol;
      LhsAutomaton* a = goa.automaton;
      int m = goa.multiplicity;
      Subproblem* sp;
      for (int j = (s == 0) ? 0 : subject->findFirstOccurrence(s); j < nrArgs; j++)
	{
	  DagNode* d = args[j].dagNode;
	  if (d->symbol() != s && s != 0)
	    break;
	  if (currentMultiplicity[j] >= m && a->match(d, solution, sp))
	    {
	      Assert(sp == 0, cerr << "grounded out alien gave rise to subproblem!");
	      currentMultiplicity[j] -= m;
	      goto nextGroundedOutAlien;
	    }
	}
      return false;
    nextGroundedOutAlien:
      ;
    }
  return true;
}

local_inline bool
ACU_LhsAutomaton::forcedLoneVariableCase(ACU_DagNode* subject,
					 Substitution& solution,
					 Subproblem*& returnedSubproblem)
{
  TopVariable& loneVariable = topVariables[lastUnboundVariable];
  int m = loneVariable.multiplicity;
  //
  //	Locate remaining subterms
  //
  int nrArgs = currentMultiplicity.length();
  int nrSubterms = 0;
  int lastSubterm = UNDEFINED;
  for (int i = 0; i < nrArgs; i++)
    {
      int cm = currentMultiplicity[i];
      if (cm > 0)
	{
	  if (cm % m > 0)
	    return false;
	  ++nrSubterms;
	  lastSubterm = i;
	}
    }
  Assert(nrSubterms > 0, cerr << "no subterms");
  //
  //	Build assignment for lone variable
  //
  ArgVec<ACU_DagNode::Pair>& args = subject->argArray;
  if (nrSubterms == 1 && currentMultiplicity[lastSubterm] == m)
    {
      //
      //	Special case: one subterm left which has same multiplicity as variable
      //
      DagNode* d = args[lastSubterm].dagNode;
      solution.bind(loneVariable.index, d);
      if (loneVariable.abstracted != 0)
	return loneVariable.abstracted->match(d, solution, returnedSubproblem);
      return d->leq(loneVariable.sort);
    }
  else
    {
      //
      //	General case
      //
      ACU_DagNode* d = new ACU_DagNode(topSymbol, nrSubterms);
      int pos = 0;
      for (int i = 0; i < nrArgs; i++)
	{
	  int cm = currentMultiplicity[i];
	  if (cm > 0)
	    {
	      d->argArray[pos].dagNode = args[i].dagNode;
	      d->argArray[pos].multiplicity = cm / m;
	      ++pos;
	    }
	}
      Assert(pos == nrSubterms, cerr << "inconsistant number of subterms");
      solution.bind(loneVariable.index, d);
      if (loneVariable.abstracted != 0)
	return loneVariable.abstracted->match(d, solution, returnedSubproblem);
      if (d->checkSort(loneVariable.sort, returnedSubproblem))
	{
	  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
	  if (subject->isReduced() && d->getSortIndex() != Sort::SORT_UNKNOWN)
	    d->setReduced();  // not worth checking if variable is useful
	  return true;
	}
      return false;
    }
}

local_inline bool 
ACU_LhsAutomaton::aliensOnlyMatch(ACU_DagNode* subject,
				  Substitution& solution,
				  Subproblem*& returnedSubproblem)
{
  ArgVec<ACU_DagNode::Pair>& args = subject->argArray;
  int nrArgs = args.length();
  SubproblemAccumulator subproblems;
  if (nrIndependentAliens > 0)
    {
      //
      //	Anything matched by an independent alien can be "forced"
      //	since it can't be matched by another alien (except one that
      //	subsumes the first) and there are no variables or extension
      //
      local.copy(solution);  // make a local copy of solution
      for (int i = 0; i < nrIndependentAliens; i++)
	{
	  NonGroundAlien& nga = nonGroundAliens[i];
	  Symbol* s = nga.topSymbol;
	  LhsAutomaton* a = nga.automaton;
	  int m = nga.multiplicity;
	  for (int j = (s == 0) ? 0 : subject->findFirstOccurrence(s); j < nrArgs; j++)
	    {
	      DagNode* d = args[j].dagNode;
	      if (d->symbol() != s && s != 0)
		break;
	      if (currentMultiplicity[j] >= m)
		{
		  Subproblem* sp;
		  if (a->match(d, local, sp))
		    {
		      solution.copy(local);
		      currentMultiplicity[j] -= m;
		      subproblems.add(sp);
		      goto nextIndependentAlien;
		    }
		  local.copy(solution);  // restore local copy of solution
		}
	    }
	  return false;
	nextIndependentAlien:
	  ;
	}
    }

  if (nonGroundAliens.length() > nrIndependentAliens)
    {
      //
      //	Need to build bipartite graph for remaining aliens as usual
      //
      ACU_Subproblem* sp = buildBipartiteGraph(subject, solution, 0, nrIndependentAliens);
      if (sp == 0)
	return false;
      subproblems.add(sp);
    }

  returnedSubproblem = subproblems.extractSubproblem();
  return true;
}

local_inline void
ACU_LhsAutomaton::copyMultiplicity()
{
  int nrArgs = currentMultiplicity.length();
  subjects.resize(nrArgs);
  for (int i = 0; i < nrArgs; i++)
    subjects[i].multiplicity = currentMultiplicity[i];
}

local_inline int
ACU_LhsAutomaton::computeTotalMultiplicity()
{
  int totalSubjectMultiplicity = 0;
  int nrArgs = currentMultiplicity.length();
  for (int i = 0; i < nrArgs; i++)
    totalSubjectMultiplicity += currentMultiplicity[i];
  return totalSubjectMultiplicity;
}

bool
ACU_LhsAutomaton::match(DagNode* subject,
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
  ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
  if (!multiplicityChecks(s) || !eliminateGroundAliens(s) ||
      !eliminateBoundVariables(s, solution) || !eliminateGroundedOutAliens(s, solution))
    return false;

  returnedSubproblem = 0;
  if (extensionInfo == 0)
    {
      //
      //	Matching without extension special cases:
      //
      if (lastUnboundVariable == NONE)
	{
	  if (totalNonGroundAliensMultiplicity != computeTotalMultiplicity())
	    return false;
	  if (totalNonGroundAliensMultiplicity == 0)
	    return true;
	  if (matchStrategy == ALIENS_ONLY)
	    return aliensOnlyMatch(s, solution, returnedSubproblem);
	}
      else
	{
	  Assert(matchStrategy != GROUND_OUT, cerr << "didn't ground out");
	  Assert(matchStrategy != ALIENS_ONLY, cerr << "variable left");
	  TopVariable& tv = topVariables[lastUnboundVariable];
	  if (tv.prevUnbound == NONE)
	    {
	      int needed = totalNonGroundAliensMultiplicity;
	      if (!(tv.takeIdentity))
		needed += tv.multiplicity;
	      int available = computeTotalMultiplicity();
	      if (available < needed)
		return false;
	      if (totalNonGroundAliensMultiplicity == 0)
		{
		  if (available == 0)
		    {
		      Assert(tv.takeIdentity, cerr << "can't take identity");
		      solution.bind(tv.index, topSymbol->getIdentityDag());
		      if (tv.abstracted != 0)
			{
			  return tv.abstracted->match(solution.value(tv.index),
						      solution,
						      returnedSubproblem);
			}
		      return true;
		    }
		  else
		    return forcedLoneVariableCase(s, solution, returnedSubproblem);
		}
	    }
	  Assert(matchStrategy != LONE_VARIABLE, cerr << "> 1 variable left");
	}
    }

  //
  //	If we have are matching with extension we have to insure that at least
  //	two real subterms are actually matched; i.e. extension cannot be whole subject
  //	or whole subject except for one alien subterm.
  //
  ACU_ExtensionInfo* e = static_cast<ACU_ExtensionInfo*>(extensionInfo);
  if (e != 0)
    e->setUpperBound(totalMultiplicity - 2);

  if (matchStrategy == GREEDY)
    {
      //
      //	Greedy matching special cases:
      //
      copyMultiplicity();
      int r = (totalNonGroundAliensMultiplicity != 0) ?
	greedyMatch(s, solution, e) : greedyPureMatch(s, solution, e, false);
      if (r != UNDECIDED)
	return r;
    }
  //
  //	If all else fails...
  //
  return fullMatch(s, solution, returnedSubproblem, e);
}

bool
ACU_LhsAutomaton::fullMatch(ACU_DagNode* subject,
			    Substitution& solution,
			    Subproblem*& returnedSubproblem,
			    ACU_ExtensionInfo* extensionInfo)
{
  
  ACU_Subproblem* subproblem = buildBipartiteGraph(subject, solution, extensionInfo, 0);
  if (subproblem == 0)
    return false;
  SubproblemAccumulator subproblems;
  subproblems.add(subproblem);
  int nrVariables = solution.nrFragileBindings();
  int nrTopVariables = topVariables.length();
  for (int i = 0; i < nrTopVariables; i++)
    {
      TopVariable& tv = topVariables[i];
      int index = tv.index;
      if (solution.value(index) == 0)
	{
	  subproblem->addTopVariable(index,
				     tv.multiplicity,
				     tv.takeIdentity ? 0 : 1,
				     tv.upperBound,
				     tv.sort);
	  if (tv.abstracted != 0)
	    {
	      subproblems.add(new VariableAbstractionSubproblem(tv.abstracted,
								index,
								nrVariables));
	    }
	}
    }
  returnedSubproblem = subproblems.extractSubproblem();
  if (extensionInfo != 0)
    extensionInfo->setValidAfterMatch(false);  // extension info will not be valid until solve
  return true;
}

ACU_Subproblem*
ACU_LhsAutomaton::buildBipartiteGraph(ACU_DagNode* subject,
				      Substitution& solution,
				      ACU_ExtensionInfo* extensionInfo,
				      int firstAlien)
{
  ArgVec<ACU_DagNode::Pair>& args = subject->argArray;
  int nrArgs = args.length();
  ACU_Subproblem* subproblem =
    new ACU_Subproblem(subject, currentMultiplicity, extensionInfo);
  int nrNonGroundAliens = nonGroundAliens.length();
  for (int i = firstAlien; i < nrNonGroundAliens; i++)
    {
      bool matchable = false;
      NonGroundAlien& nga = nonGroundAliens[i];
      Symbol* s = nga.topSymbol;
      LhsAutomaton* a = nga.automaton;
      int m = nga.multiplicity;
      subproblem->addPatternNode(m);
      for (int j = (s == 0) ? 0 : subject->findFirstOccurrence(s); j < nrArgs; j++)
        {
	  DagNode* d = args[j].dagNode;
	  if (d->symbol() != s && s != 0)
	    break;
          if (currentMultiplicity[j] >= m)
            {
              local.copy(solution);
              Subproblem* sp;
              if (a->match(d, local, sp))
                {
                  subproblem->addEdge(i - firstAlien, j, solution, local, sp);
                  matchable = true;
                }
            }
        }
      if (!matchable)
        {
          delete subproblem;
          return 0;
        }
    }
  return subproblem;
}
