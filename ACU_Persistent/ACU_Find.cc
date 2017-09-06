//
//	Find functions for ACU red-black tree argument lists.
//

bool
ACU_RedBlackNode::find(ACU_RedBlackNode* root,
		       DagNode* dagNode,
		       ACU_Stack& path)
{
  do
    {
      path.push(root);
      int r = dagNode->compare(root->getDagNode());
      if (r == 0)
	return true;
      root = root->getChild(r);
    }
  while (root != 0);
  return false;
}

bool
ACU_RedBlackNode::find(ACU_RedBlackNode* root,
		       Term* term,
		       ACU_Stack& path)
{
  do
    {
      path.push(root);
      int r = term->compare(root->getDagNode());
      if (r == 0)
	return true;
      root = root->getChild(r);
    }
  while (root != 0);
  return false;
}

bool
ACU_RedBlackNode::findFirstPotentialMatch(ACU_RedBlackNode* root,
					  Term* key,
					  const Substitution& partial,
					  ACU_Stack& path)
{
  int explore = 0;
  do
    {
      path.push(root);
      ++explore;
      int r = key->partialCompare(partial, root->getDagNode());
      switch (r)
	{
	case Term::GREATER:
	  {
	    root = root->getRight();
	    break;
	  }
	case Term::EQUAL:
	  {
	    return true;
	  }
	case Term::LESS:
	  {
	    root = root->getLeft();
	    break;
	  }
	case Term::UNKNOWN:
	  {
	    explore = 0;  // so we can retreat to this node
	    root = root->getLeft();
	    break;
	  }
	}
    }
  while (root != 0);
  path.multiPop(explore);  // retreat the last place we zero'd explore
  return !path.empty();
}

bool
ACU_RedBlackNode::findGeqMult(ACU_RedBlackNode* root,
			      int multiplicity,
			      ACU_Stack& path)
{
  if (root->getMaxMult() >= multiplicity)
    {
      for(;;)
	{
	  path.push(root);
	  ACU_RedBlackNode* l = root->getLeft();
	  if (l != 0 && l->getMaxMult() >= multiplicity)
	    root = l;
	  else if (root->getMultiplicity() >= multiplicity)
	    break;
	  else
	    {
	      root = root->getRight();
	      Assert(root != 0 && root->getMaxMult() >= multiplicity,
		     "maxMult invariant failed");
	    }
	}
      return true;
    }
  return false;
}
