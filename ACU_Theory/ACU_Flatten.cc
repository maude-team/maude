//
//	Flatten nested ACU arguments lists running the mergesort algorithm.
//

void
ACU_DagNode::flattenSortAndUniquize(int expansion)
{
  Symbol* s = symbol();
  int nrArgs = argArray.length();
  ArgVec<Pair> newArray(nrArgs + expansion);
  runsBuffer.contractTo(1);
  int lastRun = 0;
  runsBuffer[0] = lastRun;
  int d = -1;  // HACK: should use iterators for everything

  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* n = argArray[i].dagNode;
      if (n->symbol() == s)
	{
	  //
	  //	Need to flatten in subterm.
	  //
	  int m = argArray[i].multiplicity;
	  if (d >= 0)
	    {
	      lastRun = d + 1;
	      runsBuffer.append(lastRun);
	    }
	  ArgVec<Pair>::iterator dest = newArray.begin() + (d + 1);

	  if (safeCast(ACU_BaseDagNode*, n)->isTree())
	    {
	      ACU_RedBlackNode* root = safeCast(ACU_TreeDagNode*, n)->getRoot();
	      ACU_FastIter i(root);
	      do       
		{
		  dest->dagNode = i.getDagNode();
		  dest->multiplicity = m * i.getMultiplicity();
		  ++dest;
		  i.next();
		}
	      while (i.valid());
	      d += root->getSize();
	    }
	  else
	    {
	      const ArgVec<Pair>& argArray2 = safeCast(ACU_DagNode*, n)->argArray;
	      ArgVec<Pair>::const_iterator i = argArray2.begin();
	      const ArgVec<Pair>::const_iterator e = argArray2.end();
	      do       
		{
		  dest->dagNode = i->dagNode;
		  dest->multiplicity = m * i->multiplicity;
		  ++dest;
		  ++i;
		}
	      while (i != e);
	      d += argArray2.length();
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
