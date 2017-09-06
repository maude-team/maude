//
//	Code for fast normalization of ACU dag nodes. Speed is obtained by considering
//	special cases and extracting order information from the unnormalized dag node
//	where possible to avoid unnecessary comparisons on arguments.
//

void
ACU_DagNode::mergeSortAndUniquize()
{
  int nrArgs = argArray.length();
  int nrRuns = runsBuffer.length();
  ArgVec<Pair> mergeBuffer(nrArgs);

  while (nrRuns > 1)
    {
      int d = 0;
      int rd = 0;
      int i = 0;
      for (; i < nrRuns - 1; i += 2)
	{
	  //
	  //	Merge runs i and i+1
	  //
	  int p1 = runsBuffer[i];
	  int e1 = runsBuffer[i + 1];
	  int p2 = runsBuffer[i + 1];
	  int e2 = i + 2 < nrRuns ? runsBuffer[i + 2] : nrArgs;
	  runsBuffer[rd++] = d;  // save start of merged run we are creating
	  for(;;)
	    {
	      int r = argArray[p1].dagNode->compare(argArray[p2].dagNode);
	      if (r < 0)
		{
		  mergeBuffer[d++] = argArray[p1++];
		  if (p1 == e1)
		    {
		      p1 = p2;
		      e1 = e2;
		      break;
		    }
		}
	      else if (r > 0)
		{
		  mergeBuffer[d++] = argArray[p2++];
		  if (p2 == e2)
		    break;
		}
	      else
		{
		  mergeBuffer[d].dagNode = argArray[p1].dagNode;
		  mergeBuffer[d++].multiplicity =
		    argArray[p1++].multiplicity + argArray[p2++].multiplicity;
		  if (p1 == e1)
		    {
		      p1 = p2;
		      e1 = e2;
		      break;
		    }
		  if (p2 == e2)
		    break;
		}
	    }
	  while (p1 < e1)
	    mergeBuffer[d++] = argArray[p1++];
	}
      if (i < nrRuns)
	{
	  Assert(rd < i, cerr << "floor(nrRuns/2) >= nrRuns - 1");
	  runsBuffer[rd++] = d;  // Assert guarantees we don't overwrite runsBuffer[i]
	  //
	  //	Copy odd run into merge buffer
	  //
	  for (int p = runsBuffer[i]; p < nrArgs; p++)
	    mergeBuffer[d++] = argArray[p];
	}
      nrArgs = d;
      nrRuns = rd;
      argArray.swap(mergeBuffer);
    }
  argArray.contractTo(nrArgs);  // merging may have shrunk number of arguments
}

void
ACU_DagNode::sortAndUniquize()
{
  // cout << " sortAndUniquize()\n";
  int nrArgs = argArray.length();
  for (int i = 1; i < nrArgs; i++)
    {
      int r = argArray[i - 1].dagNode->compare(argArray[i].dagNode);
      if (r >= 0)
	{
	  runsBuffer.contractTo(1);
	  int lastRun = 0;
	  runsBuffer[0] = lastRun;
	  int d = i - 1;
	  for(;;)
	    {
	      if (r == 0)
		argArray[d].multiplicity += argArray[i].multiplicity;
	      else if (r < 0)
		argArray[++d] = argArray[i];
	      else
		{
		  if (lastRun == d)  // don't make a run of length 1
		    {
		      Pair t(argArray[d]);
		      argArray[d] = argArray[i];
		      argArray[++d] = t;
		    }
		  else
		    {
		      argArray[++d] = argArray[i];
		      lastRun = d;
		      runsBuffer.append(lastRun);
		    }
		}
	      if (++i == nrArgs)
		break;
	      r = argArray[d].dagNode->compare(argArray[i].dagNode);
	    }
	  argArray.contractTo(d + 1);
	  if (runsBuffer.length() > 1)
	    mergeSortAndUniquize();
	  break;
	}
    }
}

void
ACU_DagNode::flattenSortAndUniquize(int expansion)
{
  Symbol* s = symbol();
  int nrArgs = argArray.length();
  ArgVec<Pair> newArray(nrArgs + expansion);
  runsBuffer.contractTo(1);
  int lastRun = 0;
  runsBuffer[0] = lastRun;
  int d = -1;

  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* n = argArray[i].dagNode;
      if (n->symbol() == s)
	{
	  int m = argArray[i].multiplicity;
	  ArgVec<Pair>& argArray2 = static_cast<ACU_DagNode*>(n)->argArray;
	  int j = 0;
	  if (d >= 0)
	    {
	      int r = newArray[d].dagNode->compare(argArray2[0].dagNode);
	      if (r == 0)
		{
		  newArray[d].multiplicity += m * argArray2[0].multiplicity;
		  j = 1;
		}
	      else if (r > 0)
		{
		  lastRun = d + 1;
		  runsBuffer.append(lastRun);
		}
	    }
	  int nrArgs2 = argArray2.length();
	  for (; j < nrArgs2; j++)
	    {
	      ++d;
	      newArray[d].dagNode = argArray2[j].dagNode;
	      newArray[d].multiplicity = m * argArray2[j].multiplicity;
	    }
	}
      else
	{
	  if (d >= 0)
	    {
	      int r = newArray[d].dagNode->compare(n);
	      if (r == 0)
		{
		  newArray[d].multiplicity += argArray[i].multiplicity;
		  continue;
		}
	      else if (r > 0)
		{
		  if (lastRun == d)  // don't make a run of length 1
		    {
		      newArray[d + 1] = newArray[d];
		      newArray[d] = argArray[i];
		      ++d;
		      continue;
		    }
		  else
		    {
		      lastRun = d + 1;
		      runsBuffer.append(lastRun);
		    }
		}
	    }
	  newArray[++d] = argArray[i];
	}
    }
  /*
  cout << " flattenSortAndUniquize() runs buffer: ";
  for (int i = 0; i < runsBuffer.length(); i++)
    cout << runsBuffer[i] << ' ';
  cout << " nrArgs = " << newArray.length() << '\n';
  */
  newArray.contractTo(d + 1);
  argArray.swap(newArray);
  if (runsBuffer.length() > 1)
    mergeSortAndUniquize();
}

bool
ACU_DagNode::normalizeAtTop()
{
  Symbol* s = symbol();
  int nrArgs = argArray.length();
  // cout << "normalizeAtTop() nrArgs = " << nrArgs;

  if (nrArgs == 2)
    {
      //
      //	This is the usual case so we heavily optimize it.
      //
      DagNode* d0 = argArray[0].dagNode;
      DagNode* d1 = argArray[1].dagNode;
      if (d0->symbol() != s)
	{
	  if (d1->symbol() != s)
	    {
	      int r = d0->compare(d1);
	      if (r < 0)
		return false;  // most common case
	      else if (r > 0)
		{
		  int m = argArray[1].multiplicity;
		  argArray[1].multiplicity = argArray[0].multiplicity;
		  argArray[1].dagNode = d0;
		  argArray[0].dagNode = d1;
		  argArray[0].multiplicity = m;
		}
	      else
		{
		  argArray[0].multiplicity += argArray[1].multiplicity;
		  argArray.contractTo(1);
		}
	      return false;
	    }
	  else
	    {
	      if (argArray[1].multiplicity == 1)
		{
		  copyAndBinaryInsert(static_cast<ACU_DagNode*>(d1),
				      d0,
				      argArray[0].multiplicity);
		}
	      else
		flattenSortAndUniquize(static_cast<ACU_DagNode*>(d1)->argArray.length() - 1);
	      return true;
	    }
	}
      else
	{
	  if (d1->symbol() != s)
	    {
	      if (argArray[0].multiplicity == 1)
		{
		  copyAndBinaryInsert(static_cast<ACU_DagNode*>(d0),
				      d1,
				      argArray[1].multiplicity);
		}
	      else
		flattenSortAndUniquize(static_cast<ACU_DagNode*>(d0)->argArray.length() - 1);
	    }
	  else
	    {
	      if (argArray[0].multiplicity == 1 && argArray[1].multiplicity == 1)
		fastMerge(static_cast<ACU_DagNode*>(d0), static_cast<ACU_DagNode*>(d1));
	      else
		{  
		  flattenSortAndUniquize(static_cast<ACU_DagNode*>(d0)->argArray.length() +
					 static_cast<ACU_DagNode*>(d1)->argArray.length() - 2);
		}
	    }
	  return true;
	}
    }
  //
  //	General case.
  //
  int expansion = 0;
  bool needToFlatten = false;
  
  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* n = argArray[i].dagNode;
      if (n->symbol() == s)
	{
	  expansion += static_cast<ACU_DagNode*>(n)->argArray.length() - 1;
	  needToFlatten = true;  // expansion due to flattening could be zero 
	}
    }
  if (needToFlatten)
    flattenSortAndUniquize(expansion);
  else
    sortAndUniquize();
  return needToFlatten;
}


inline ArgVec<ACU_DagNode::Pair>::iterator
ACU_DagNode::fastCopy(ArgVec<Pair>::const_iterator i,
		      ArgVec<Pair>::const_iterator e,
		      ArgVec<Pair>::iterator d)
{
  //
  //	This beats the STL copy() algorithm because the latter maintains
  //	a counter.
  //
  while (i != e)
    {
      *d = *i;
      ++d;
      ++i;
    }
  return d;
}

/*
void
check(int pos, int end)
{
  if (pos == 0)
    cerr << "left\n";
  else if (pos == end)
    cerr << "right\n";
  else
    cerr << "middle\n";
}
*/

void
ACU_DagNode::copyAndBinaryInsert(const ACU_DagNode* source,
				 DagNode* dagNode,
				 int multiplicity)
{
  //
  //	Copy source's argArray into our argArray, inserting dagNode
  //	in the correct place.
  //
  int pos;
  int nrSourceArgs = source->argArray.length();
  if (source->binarySearch(dagNode, pos))
    {
      //check(pos, nrSourceArgs);
      //DebugAdvisory("copyAndBinaryInsert() " << pos << " out of " << nrSourceArgs);
      argArray.resizeWithoutPreservation(nrSourceArgs);
      if (nrSourceArgs > 1)
	{
	  fastCopy(source->argArray.begin(), source->argArray.end(), argArray.begin());
	  argArray[pos].multiplicity += multiplicity;
	}
      else
	{
	  argArray[0].dagNode = dagNode;
	  argArray[0].multiplicity = multiplicity + source->argArray[0].multiplicity;
	}
    }
  else
    {
      //check(pos, nrSourceArgs);
      //DebugAdvisory("copyAndBinaryInsert() " << pos << " out of " << nrSourceArgs);
      argArray.resizeWithoutPreservation(nrSourceArgs + 1);
      const ArgVec<Pair>::const_iterator i = source->argArray.begin();
      const ArgVec<Pair>::const_iterator p = i + pos;
      const ArgVec<Pair>::iterator j = fastCopy(i, p, argArray.begin());
      j->dagNode = dagNode;
      j->multiplicity = multiplicity;
      fastCopy(p, source->argArray.end(), j + 1);
    }
}

void
ACU_DagNode::fastMerge(const ACU_DagNode* source0, const ACU_DagNode* source1)
{
  //
  //	Merge the argArrays from source0 and source1 into our argArray.
  //
  argArray.resizeWithoutPreservation(source0->argArray.length() +
				     source1->argArray.length());
  
  ArgVec<Pair>::const_iterator s0 = source0->argArray.begin();
  const ArgVec<Pair>::const_iterator e0 = source0->argArray.end();
  ArgVec<Pair>::const_iterator s1 = source1->argArray.begin();
  const ArgVec<Pair>::const_iterator e1 = source1->argArray.end();
  ArgVec<Pair>::iterator d = argArray.begin();
  for(;;)
    {
      int r = s0->dagNode->compare(s1->dagNode);
      if (r < 0)
	{
	  *d = *s0;
	  ++d;
	  ++s0;
	  if (s0 == e0)
	    goto source0Exhausted;
	}
      else if (r > 0)
	{
	  *d = *s1;
	  ++d;
	  ++s1;
	  if (s1 == e1)
	    goto source1Exhausted;
	}
      else
	{
	  d->dagNode = s0->dagNode;
	  d->multiplicity = s0->multiplicity + s1->multiplicity;
	  ++d;
	  ++s0;
	  ++s1;
	  if (s0 == e0)
	    {
	    source0Exhausted:
	      d = fastCopy(s1, e1, d);
	      break;
	    }
	  if (s1 == e1)
	    {
	    source1Exhausted:
	      d = fastCopy(s0, e0, d);
	      break;
	    }
	}
    }
  argArray.contractTo(d - argArray.begin());
}

bool
ACU_DagNode::extensionNormalizeAtTop()
{
  int last = argArray.length() - 1;
  Assert(argArray[last].multiplicity == 1,
	 cerr << "bad multiplicity for replacement term");
  DagNode* replacement = argArray[last].dagNode;
  if (replacement->symbol() == symbol())
    {
      runsBuffer.resize(2);
      runsBuffer[0] = 0;
      runsBuffer[1] = last;

      ArgVec<Pair> argArray2 = static_cast<ACU_DagNode*>(replacement)->argArray;
      int nrArgs2 = argArray2.length();
      argArray.expandBy(nrArgs2 - 1);
      for (int i = 0; i < nrArgs2; i++)
	argArray[last++] = argArray2[i];
      mergeSortAndUniquize();
      return true;
    }
  else
    {
      argArray.contractTo(last);
      binaryInsert(replacement, 1);
      return false;
    }
}

void
ACU_DagNode::binaryInsert(DagNode* dagNode, int multiplicity)
{
  int pos;
  if (binarySearch(dagNode, pos))
    {
      //check(pos, argArray.length());
      //DebugAdvisory("binaryInsert() " << pos << " out of " << argArray.length());
      argArray[pos].multiplicity += multiplicity;
    }
  else
    {
      //check(pos, argArray.length());
      //DebugAdvisory("binaryInsert() " << pos << " out of " << argArray.length());
      int p = argArray.length();
      argArray.expandBy(1);
      for (; p > pos; p--)
	argArray[p] = argArray[p - 1];
      argArray[pos].dagNode = dagNode;
      argArray[pos].multiplicity = multiplicity;
    }
}
