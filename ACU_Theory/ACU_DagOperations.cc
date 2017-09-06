//
//	Fast operations on ACU dag nodes.
//

int
ACU_DagNode::findFirstOccurrence(Symbol* key) const
{
  CONST_ARG_VEC_HACK(Pair, args, argArray);
  int first = argArray.length();  // return index beyond arg array if no occurrence
  Assert(first > 0, cerr << "no args");
  int upper = first - 1;
  int lower = 0;
  do
    {
      int probe = (upper + lower) / 2;
      int r = key->compare(args[probe].dagNode->symbol());
      if (r > 0)
	lower = probe + 1;
      else
	{
	  if (r == 0)
	    first = probe;
	  upper = probe - 1; 
	}
    }
  while (lower <= upper);
  return first;
}

bool
ACU_DagNode::binarySearch(DagNode* key, int& pos) const
{
  CONST_ARG_VEC_HACK(Pair, args, argArray);
  int upper = argArray.length() - 1;
  Assert(upper >= 0, cerr << "no args");
  int lower = 0;
  do
    {
      int probe = (upper + lower) / 2;
      int r = key->compare(args[probe].dagNode);
      if (r == 0)
	{
	  pos = probe;
	  return true;
	}
      if (r < 0)
	upper = probe - 1;
      else
	lower = probe + 1;
    }
  while (lower <= upper);
  pos = lower;
  return false;
}

bool
ACU_DagNode::binarySearch(Term* key, int& pos) const
{
  CONST_ARG_VEC_HACK(Pair, args, argArray);
  int upper = argArray.length() - 1;
  Assert(upper >= 0, cerr << "no args");
  int lower = 0;
  do
    {
      int probe = (upper + lower) / 2;
      int r = key->compare(args[probe].dagNode);
      if (r == 0)
	{
	  pos = probe;
	  return true;
	}
      if (r < 0)
	upper = probe - 1;
      else
	lower = probe + 1;
    }
  while (lower <= upper);
  pos = lower;
  return false;
}

bool
ACU_DagNode::eliminateSubject(DagNode* target,
			      int multiplicity,
			      Vector<int>& subjectMultiplicity)
{
  ACU_Symbol* topSymbol = symbol();
  Term* identity = topSymbol->getIdentity();
  if (identity != 0 && identity->equal(target))
    return true;
  if (target->symbol() == topSymbol)
    {
      ArgVec<Pair>& args = static_cast<ACU_DagNode*>(target)->argArray;
      int nrArgs = args.length();
      for (int i = 0; i < nrArgs; i++)
        {
          int pos;
          DagNode* d = args[i].dagNode;
          int m = args[i].multiplicity;
          if (!binarySearch(d, pos) || (subjectMultiplicity[pos] -= m * multiplicity) < 0)
            return false;
        }
    }
  else
    {
      int pos;
      if (!binarySearch(target, pos) || (subjectMultiplicity[pos] -= multiplicity) < 0)
        return false;
    }
  return true;
}

bool
ACU_DagNode::eliminateArgument(Term* target)
{
  int pos;
  if (binarySearch(target, pos))
    {
      int nrArgs = argArray.length() - 1;
      for (int i = pos; i < nrArgs; i++)
	argArray[i] = argArray[i + 1];
      if (nrArgs == 0 || (nrArgs == 1 && argArray[0].multiplicity == 1))
	{
	  //
	  //	Eliminating target causes ACU dag node to collapse to its remaining
	  //	argument (or its original argument if only argument was target).
	  //
	  DagNode* remaining = (symbol()->getPermuteStrategy() == BinarySymbol::EAGER) ?
	    argArray[0].dagNode : argArray[0].dagNode->copyReducible();
	  remaining->overwriteWithClone(this);
	  return true;
	}
      argArray.contractTo(nrArgs);
    }
  return false;
}
