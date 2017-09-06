//
//	Persistent delete from ACU red-black tree argument list.
//

ACU_RedBlackNode*
ACU_RedBlackNode::consDelete(ACU_Stack& path, int multiplicity, int& delta)
{
  
  ACU_RedBlackNode* victim = path.pop();
  int newMult = victim->getMultiplicity() - multiplicity;
  Assert(newMult >= 0, "-ve newMult");

  if (newMult > 0)
    {
      delta = 0;
      ACU_RedBlackNode* n = new ACU_RedBlackNode(victim->getDagNode(),
						 newMult,
						 victim->getLeft(),
						 victim->getRight());
      n->makeRedIfRed(victim);
      return copy(path, n, victim);
    }
  //
  //	Need to do a red-black delete.
  //
  delta = -1;
  ACU_RedBlackNode* child = victim->getLeft();
  if (child != 0)
    {
      ACU_RedBlackNode* n = victim->getRight();
      if (n != 0)
	{
	  //
	  //	Victim has two children; need to replace it with
	  //	successor.
	  //
	  path.unpop();
	  do
	    {
	      path.push(n);
	      n = n->getLeft();
	    }
	  while (n != 0);

	  ACU_RedBlackNode* surrogate = path.pop();
	  child = surrogate->getRight();  // might be null

	  if (surrogate->isRed())
	    {
	      //
	      //	Surrogate is replaced by it's only child, and victim
	      //	is replaced by surrogate.
	      //
	      return copy(path, child, surrogate, victim, surrogate);
	    }
	  else if (isRed(child))
	    {
	      //
	      //	Surrogate is replaced by a black copy of it's
	      //	only child, and victim is replaced by surrogate.
	      //
	      return copy(path,
			  blackNode(child, child->getLeft(), child->getRight()),
			  surrogate,
			  victim,
			  surrogate);
	    }
	  //
	  //	Need to increase black length for child.
	  //
	  return copyRebalance(path, child, surrogate, victim, surrogate);
	}
    }
  else
    child = victim->getRight();
  //
  //	Victim has no children or one child only.
  //
  if (path.empty())
    {
      return isRed(child) ?
	blackNode(child, child->getLeft(), child->getRight()) :
	child;
    }

  if (victim->isRed())
    return copy(path, child, victim);
  else if (isRed(child))
    return copy(path, blackNode(child, child->getLeft(), child->getRight()), victim);
  //
  //	Need to increase black length for child.
  //
  return copyRebalance(path, child, victim, 0, 0);
}
