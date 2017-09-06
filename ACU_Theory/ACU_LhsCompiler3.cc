//
//	Implementation of match compilation for AC and ACU theories.
//	Part 3: greedy and full cases.
//

void
ACU_Term::compileGreedyAndFullCases(ACU_LhsAutomaton* automaton,
				    const Vector<Pair>& nonGroundAliens,
				    const VariableInfo& variableInfo,
				    NatSet& boundUniquely,
				    bool& subproblemLikely)
{
  int nrNonGroundAliens = nonGroundAliens.length();
  Vector<LhsAutomaton*> subAutomata(nrNonGroundAliens);
  for (int i = 0; i < nrNonGroundAliens; i++)
    {
      NatSet local(boundUniquely);
      bool spl;
      subAutomata[i] = nonGroundAliens[i].term->compileLhs(false, variableInfo, local, spl);
      subproblemLikely = subproblemLikely || spl;
    }
  Vector<int> bestSequence;
  int nrIndependent = 0;
  if (subproblemLikely)
    findFullSequence(nonGroundAliens, boundUniquely, bestSequence);
  else
    nrIndependent = findGreedySequence(nonGroundAliens, bestSequence);
  for (int i = 0; i < nrNonGroundAliens; i++)
    {
      int j = bestSequence[i];
      automaton->addNonGroundAlien(nonGroundAliens[j].term,
				   subAutomata[j],
				   nonGroundAliens[j].multiplicity);
    }
  automaton->complete(subproblemLikely ? ACU_LhsAutomaton::FULL : ACU_LhsAutomaton::GREEDY,
		      nrIndependent);
}

int
ACU_Term::findGreedySequence(const Vector<Pair>& aliens, Vector<int>& sequence)
{
  Vector<Vector<int> > independents;
  findIndependentSets(aliens, independents);
  NatSet used;
  int nrIndependents = independents.length();
  //
  //	For each set of dependent patterns, add the longest sequence
  //	that increases in generality.
  //
  for (int i = 0; i < nrIndependents; i++)
    {
      Vector<int>& set = independents[i];
      if (set.length() == 1)
	{
	  int t = set[0];
	  sequence.append(t);
	  used.insert(t);
	}
      else
	{
	  Vector<int> longest;
	  findLongestIncreasingSequence(aliens, set, longest);
	  int length = longest.length();
	  for (int j = 0; j < length; j++)
	    {
	      int t = set[longest[j]];
	      sequence.append(t);
	      used.insert(t);
	    }
	}
    }
  int nrIndependent = sequence.length();
  //
  //	Now tack on any aliens not yet put in sequence.
  //
  int nrAliens = aliens.length();
  for (int i = 0; i < nrAliens; i++)
    {
      if (!(used.contains(i)))
	sequence.append(i);
    }
  Assert(sequence.length() == aliens.length(), cerr << "length mis-match");
  return nrIndependent;
}

void
ACU_Term::findLongestIncreasingSequence(const Vector<Pair>& aliens,
					Vector<int>& dependents,
					Vector<int>& sequence)
{
  int nrDependents = dependents.length();
  Digraph subsumption(nrDependents);
  for (int i = 0; i < nrDependents; i++)
    {
      Term* t1 = aliens[dependents[i]].term;
      for (int j = 0; j < nrDependents; j++)
	{
	  if (i != j)
	    {
	      Term* t2 = aliens[dependents[j]].term;
	      int m2 = aliens[dependents[j]].multiplicity;
	      if (m2 == 1 && t2->subsumes(t1, true))
		subsumption.insertEdge(i, j);
	    }
	}
    }
  subsumption.findLongestDirectedPath(sequence);
}

void
ACU_Term::findIndependentSets(const Vector<Pair>& aliens,
			      Vector<Vector<int> >& independents)
{
  int nrAliens = aliens.length();
  Graph conflicts(nrAliens);
  //
  //	Check for pairs of aliens that might match the same subject (upto an
  //	unsolved subproblem) and insert them into conflict graph.
  //
  for (int i = 0; i < nrAliens; i++)
    {
      for (int j = 0; j < i; j++)
	{
	  if (!(aliens[i].term->matchIndependent(aliens[j].term)))
	      conflicts.insertEdge(i, j);
	}
    }
  conflicts.findComponents(independents);
}

void
ACU_Term::findFullSequence(const Vector<Pair>& aliens,
			   const NatSet& boundUniquely,
			   Vector<int>& sequence)
{
  int nrAliens = aliens.length();
  sequence.expandTo(nrAliens);
  for (int i = 0; i < nrAliens; i++)
    sequence[i] = i;
  if (nrAliens > 1)
    weakConstraintPropagation(aliens, boundUniquely, 0, sequence);
}
