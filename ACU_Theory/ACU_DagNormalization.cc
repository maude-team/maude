//
//	Code for fast normalization of ACU dag nodes. Speed is obtained by considering
//	special cases and extracting order information from the unnormalized dag node
//	where possible to avoid unnecessary comparisons on arguments.
//

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
      //DebugAdvisory("copyAndBinaryInsert() " << pos << " out of " << nrSourceArgs);
      argArray.resizeWithoutPreservation(nrSourceArgs);
      fastCopy(source->argArray.begin(), source->argArray.end(), argArray.begin());
      argArray[pos].multiplicity += multiplicity;
    }
  else
    {
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

bool
ACU_DagNode::extensionNormalizeAtTop()
{
  int last = argArray.length() - 1;
  Assert(argArray[last].multiplicity == 1,
	 "bad multiplicity for replacement term");
  DagNode* replacement = argArray[last].dagNode;
  if (replacement->symbol() == symbol())
    {
      runsBuffer.resize(2);
      runsBuffer[0] = 0;
      runsBuffer[1] = last;

      if (safeCast(ACU_BaseDagNode*, replacement)->isTree())
	{
	  ACU_RedBlackNode* root = safeCast(ACU_TreeDagNode*, replacement)->getRoot();
	  argArray.expandBy(root->getSize() - 1);
	  ACU_FastIter i(root);
	  fastCopy(i, argArray.begin() + last);
	}
      else
	{
	  const ArgVec<Pair>& argArray2 = safeCast(ACU_DagNode*, replacement)->argArray;
	  argArray.expandBy(argArray2.length() - 1);
	  fastCopy(argArray2.begin(), argArray2.end(), argArray.begin() + last);
	}
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
      //DebugAdvisory("binaryInsert() " << pos << " out of " << argArray.length());
      argArray[pos].multiplicity += multiplicity;
    }
  else
    {
      //DebugAdvisory("binaryInsert() " << pos << " out of " << argArray.length());
      int p = argArray.length();
      argArray.expandBy(1);
      for (; p > pos; p--)
	argArray[p] = argArray[p - 1];
      argArray[pos].dagNode = dagNode;
      argArray[pos].multiplicity = multiplicity;
    }
}
