//
//	Functions for rebuilding a the spine of a red-black tree.
//

ACU_RedBlackNode*
ACU_RedBlackNode::copy(ACU_Stack& path,
		       ACU_RedBlackNode* n,
		       ACU_RedBlackNode* old)
{
  //
  //	The sizes on the spine will change by -delta.
  //
  int delta = old->getSize();
  int maxMult = 0;
  if (n != 0)
    {
      delta -= n->getSize();
      maxMult = n->getMaxMult();
    }
  //
  //	Rebuild spine.
  //
  while (!(path.empty()))
    {
      ACU_RedBlackNode* parent = path.pop();
      ACU_RedBlackNode* l = parent->getLeft();
      if (parent->getMaxMult() > maxMult)
	{
	  //
	  //	Slow case; need to recalculate maxMult.
	  //
	  int t = parent->getMultiplicity();
	  if (t > maxMult)
	    {
	      maxMult = t;
	      if (maxMult > SAT_MULT)
		maxMult = SAT_MULT;
	    }
	  if (l == old)
	    {
	      l = n;
	      n = parent->getRight();
	      if (n != 0)
		{
		  t = n->getMaxMult();
		  if (t > maxMult)
		    maxMult = t;
		}
	    }
	  else
	    {
	      if (l != 0)
		{
		  t = l->getMaxMult();
		  if (t > maxMult)
		    maxMult = t;
		}
	    }
	}
      else
	{
	  //
	  //	Fast case.
	  //
	  if (l == old)
	    {
	      l = n;
	      n = parent->getRight();
	    }
	}
      
      n = new ACU_RedBlackNode(parent->getDagNode(),
			       parent->getMultiplicity(),
			       l,
			       n,
			       parent->getSize() - delta,
			       maxMult);
      if (parent->isRed())
	n->makeRed();  // would like to copy flags
      old = parent;
    }
  return n;
}

ACU_RedBlackNode*
ACU_RedBlackNode::copy(ACU_Stack& path,
		       ACU_RedBlackNode* n,
		       ACU_RedBlackNode* old,
		       ACU_RedBlackNode* victim,
		       ACU_RedBlackNode* surrogate)
{
  //
  //	The sizes on the spine will change by -delta.
  //
  int delta = old->getSize();
  int maxMult = 0;
  if (n != 0)
    {
      delta -= n->getSize();
      maxMult = n->getMaxMult();
    }
  //
  //	Rebuild spine replacing victim data with surrogate data.
  //
  while (!(path.empty()))
    {
      ACU_RedBlackNode* parent = path.pop();
      ACU_RedBlackNode* l = parent->getLeft();

      ACU_RedBlackNode* source = parent;
      if (source == victim)
	{
	  source = surrogate;
	  //
	  //	surrogate is a descendant of parent.
	  //	Thus parent->getMaxMult() will be at least as
	  //	large as max(surrogate->getMultiplicity(), SAT_MULT)
	  //
	}

      if (parent->getMaxMult() > maxMult)
	{
	  //
	  //	Slow case; need to recalculate maxMult.
	  //
	  int t = source->getMultiplicity();
	  if (t > maxMult)
	    {
	      maxMult = t;
	      if (maxMult > SAT_MULT)
		maxMult = SAT_MULT;
	    }
	  if (l == old)
	    {
	      l = n;
	      n = parent->getRight();
	      if (n != 0)
		{
		  t = n->getMaxMult();
		  if (t > maxMult)
		    maxMult = t;
		}
	    }
	  else
	    {
	      if (l != 0)
		{
		  t = l->getMaxMult();
		  if (t > maxMult)
		    maxMult = t;
		}
	    }
	}
      else
	{
	  //
	  //	Fast case.
	  //
	  if (l == old)
	    {
	      l = n;
	      n = parent->getRight();
	    }
	}

      n = new ACU_RedBlackNode(source->getDagNode(),
			       source->getMultiplicity(),
			       l,
			       n,
			       parent->getSize() - delta,
			       maxMult);
      if (parent->isRed())
	n->makeRed();
      old = parent;
    }
  return n;
}
