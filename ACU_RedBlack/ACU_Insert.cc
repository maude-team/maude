//
//	Persistent insert into ACU red-black tree argument list.
//
//	We use the algorithm from:
//	  Chris Okasaki,
//	  "Functional Pearl: Red-black trees in a functional setting",
//	  Journal of Functional Programming, 9(4):471-477, July 1999.
//

ACU_RedBlackNode*
ACU_RedBlackNode::consInsert(ACU_RedBlackNode* p, DagNode* argument, int multiplicity)

#ifdef CHECK_RED_BLACK

{
  if (!(p->checkRedBlackProperty()))
    abort();
  ACU_RedBlackNode* n = consInsert2(p, argument, multiplicity);
  if (!(n->checkRedBlackProperty()))
    {
      cerr << "argument = " << argument << endl;
      cerr << "multiplicity = " << multiplicity << endl;
      p->dump(cerr, 0);
      abort();
    }
  return n;
}

ACU_RedBlackNode*
ACU_RedBlackNode::consInsert2(ACU_RedBlackNode* p, DagNode* argument, int multiplicity)

#endif

{
  Assert(p != 0, "inserting into empty tree not allowed");

  ACU_Stack path;
  bool goLeft;
  {
    //
    //	First figure out where to insert new argument.
    //
    int r;
    do
      {
	r = argument->compare(p->getDagNode());
	if (r == 0)
	  {
	    int newMult = p->getMultiplicity() + multiplicity;
	    int maxMult = p->getMaxMult();
	    if (newMult > maxMult)
	      {
		maxMult = newMult;
		if (maxMult > SAT_MULT)
		  maxMult = SAT_MULT;
	      }
	    ACU_RedBlackNode* n =
	      new ACU_RedBlackNode(p->getDagNode(),
				   newMult,
				   p->getLeft(),
				   p->getRight(),
				   p->getSize(),
				   maxMult);
	    if (path.empty())
	      return n;
	    if (p->isRed())
	      n->makeRed();  // would like to copy flags
	    return copy(path, n, p);
	  }
	path.push(p);
	p = (r < 0) ? p->getLeft() : p->getRight();
      }
    while (p != 0);
    goLeft = (r < 0);
  }
  //
  //	Now insert and copy spine, rebalancing as we go.
  //
  ACU_RedBlackNode* parent = path.pop();
  ACU_RedBlackNode* left = 0;
  ACU_RedBlackNode* right = 0;
  while (parent->isRed())
    {
      //
      //	Resolve red-red conflict using Okisaka's balancing scheme.
      //
      ACU_RedBlackNode* grandParent = path.pop();  // red nodes always have a parent
      if (goLeft)
	{
	  if (grandParent->getLeft() == parent)
	    {
	      left = new ACU_RedBlackNode(argument, multiplicity, left, right);
	      right = blackNode(grandParent,
				parent->getRight(),
				grandParent->getRight());
	      argument = parent->getDagNode();
	      multiplicity = parent->getMultiplicity();
	    }
	  else
	    {
	      left = blackNode(grandParent, grandParent->getLeft(), left);
	      right = blackNode(parent, right, parent->getRight());
	    }
	}
      else
	{
	  if (grandParent->getLeft() == parent)
	    {
	      left = blackNode(parent, parent->getLeft(), left);
	      right = blackNode(grandParent, right, grandParent->getRight());
	    }
	  else
	    {
	      right = new ACU_RedBlackNode(argument, multiplicity, left, right);
	      left = blackNode(grandParent,
			       grandParent->getLeft(),
			       parent->getLeft());
	      argument = parent->getDagNode();
	      multiplicity = parent->getMultiplicity();
	    }
	}
      if (path.empty())
	{
	  //
	  //	New root must be black.
	  //
	  return new ACU_RedBlackNode(argument, multiplicity, left, right);
	}
      parent = path.pop();
      goLeft = (parent->getLeft() == grandParent);
    }
  //
  //	Create red node.
  //
  ACU_RedBlackNode* n = new ACU_RedBlackNode(argument, multiplicity, left, right);
  n->makeRed();
  //
  //	Copy rest of spine without rebalancing.
  //
  ACU_RedBlackNode* newRoot = goLeft ?
    blackNode(parent, n, parent->getRight()) :
    blackNode(parent, parent->getLeft(), n);
  return copy(path, newRoot, parent);
}
