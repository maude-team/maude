//
//	Specialized mergesort algorithm for ACU argument lists.
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
  //
  //	ACU argument lists tend to have long runs of in order
  //	arguments so we discover these runs first befor running
  //	the mergesort algorithm.
  //
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
