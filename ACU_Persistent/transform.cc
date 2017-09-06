int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  int index = root->getSortIndex();
  if (index != Sort::SORT_UNKNOWN)
    return index;

  index = root->getDagNode()->getSortIndex();
  Assert(index != Sort::SORT_UNKNOWN, "bad sort");
  index = symbol->computeMultSortIndex(index, index, root->getMultiplicity() - 1);

  if (ACU_RedBlackNode* l = root->getLeft())
    index = symbol->computeSortIndex(index, cbs(symbol, l));
  if (ACU_RedBlackNode* r = root->getRight())
    index = symbol->computeSortIndex(index, cbs(symbol, r));

  root->setSortIndex(index);
  return index;
}


int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  int t = root->getSortIndex();
  if (t != Sort::SORT_UNKNOWN)
    return t;

  if (ACU_RedBlackNode* l = root->getLeft())
    cbs(symbol, l);
  if (ACU_RedBlackNode* r = root->getRight())
    cbs(symbol, r);

  int index;
  int rIndex = root->getDagNode()->getSortIndex();
  Assert(rIndex != Sort::SORT_UNKNOWN, "bad sort");
  int multiplicity = root->getMultiplicity();

  if (ACU_RedBlackNode* l = root->getLeft())
    {
      index = l->getSortIndex();
      if (ACU_RedBlackNode* r = root->getRight())
	index = symbol->computeSortIndex(index, r->getSortIndex());
    }
  else
    {
      if (ACU_RedBlackNode* r = root->getRight())
	index = r->getSortIndex();
      else
	{
	  index = rIndex;
	  --multiplicity;
	}
    }

  int f = symbol->computeMultSortIndex(index, rIndex, root->getMultiplicity() - 1);
  root->setSortIndex(f);
  return f;
}


int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;

 down:
  int t = root->getSortIndex();
  if (t != Sort::SORT_UNKNOWN)
    return t;

  if (ACU_RedBlackNode* l = root->getLeft())
    {
      s.push(root);
      root = l;
      goto down;
    }
 tryRight:
  if (ACU_RedBlackNode* r = root->getRight())
    {
      s.push(root);
      root = r;
      goto down;
    }

  int index;
  int rIndex = root->getDagNode()->getSortIndex();
  Assert(rIndex != Sort::SORT_UNKNOWN, "bad sort");
  int multiplicity = root->getMultiplicity();

 doSelf:
  if (ACU_RedBlackNode* l = root->getLeft())
    {
      index = l->getSortIndex();
      if (ACU_RedBlackNode* r = root->getRight())
	index = symbol->computeSortIndex(index, r->getSortIndex());
    }
  else
    {
      if (ACU_RedBlackNode* r = root->getRight())
	index = r->getSortIndex();
      else
	{
	  index = rIndex;
	  --multiplicity;
	}
    }
  int f = symbol->computeMultSortIndex(index, rIndex, root->getMultiplicity() - 1);
  root->setSortIndex(f);

  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      goto doSelf;
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;

  for(;;)
    {
      int t = root->getSortIndex();
      if (t != Sort::SORT_UNKNOWN)
	goto up;
      
      if (ACU_RedBlackNode* l = root->getLeft())
	{
	  s.push(root);
	  root = l;
	}
      else
	{
	tryRight:
	  if (ACU_RedBlackNode* r = root->getRight())
	    {
	      s.push(root);
	      root = r;
	    }
	  else
	    break;
	}
    }

  int index;
  int rIndex = root->getDagNode()->getSortIndex();
  Assert(rIndex != Sort::SORT_UNKNOWN, "bad sort");
  int multiplicity = root->getMultiplicity();

 doSelf:
  if (ACU_RedBlackNode* l = root->getLeft())
    {
      index = l->getSortIndex();
      if (ACU_RedBlackNode* r = root->getRight())
	index = symbol->computeSortIndex(index, r->getSortIndex());
    }
  else
    {
      if (ACU_RedBlackNode* r = root->getRight())
	index = r->getSortIndex();
      else
	{
	  index = rIndex;
	  --multiplicity;
	}
    }
  int f = symbol->computeMultSortIndex(index, rIndex, root->getMultiplicity() - 1);
  root->setSortIndex(f);

 up:
  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      goto doSelf;
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n != 0 && n->getSortIndex() == Sort::SORT_UNKNOWN)
	{
	  s.push(root);
	  root = n;
	}
      else
	{
	tryRight:
	  n = root->getRight();
	  if (n != 0 && n->getSortIndex() == Sort::SORT_UNKNOWN)
	    {
	      s.push(root);
	      root = n;
	    }
	  else
	    break;
	}
    }

  int index;
  int rIndex = root->getDagNode()->getSortIndex();
  Assert(rIndex != Sort::SORT_UNKNOWN, "bad sort");
  int multiplicity = root->getMultiplicity();

 doSelf:
  if (ACU_RedBlackNode* l = root->getLeft())
    {
      index = l->getSortIndex();
      if (ACU_RedBlackNode* r = root->getRight())
	index = symbol->computeSortIndex(index, r->getSortIndex());
    }
  else
    {
      if (ACU_RedBlackNode* r = root->getRight())
	index = r->getSortIndex();
      else
	{
	  index = rIndex;
	  --multiplicity;
	}
    }
  int f = symbol->computeMultSortIndex(index, rIndex, root->getMultiplicity() - 1);
  root->setSortIndex(f);

 up:
  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      goto doSelf;
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n != 0 && n->getSortIndex() == Sort::SORT_UNKNOWN)
	{
	}
      else
	{
	tryRight:
	  n = root->getRight();
	  if (n != 0 && n->getSortIndex() == Sort::SORT_UNKNOWN)
	    {
	    }
	  else
	    break;
	}
      s.push(root);
      root = n;
    }

  int index;
  int rIndex = root->getDagNode()->getSortIndex();
  Assert(rIndex != Sort::SORT_UNKNOWN, "bad sort");
  int multiplicity = root->getMultiplicity();

 doSelf:
  if (ACU_RedBlackNode* l = root->getLeft())
    {
      index = l->getSortIndex();
      if (ACU_RedBlackNode* r = root->getRight())
	index = symbol->computeSortIndex(index, r->getSortIndex());
    }
  else
    {
      if (ACU_RedBlackNode* r = root->getRight())
	index = r->getSortIndex();
      else
	{
	  index = rIndex;
	  --multiplicity;
	}
    }
  int f = symbol->computeMultSortIndex(index, rIndex, root->getMultiplicity() - 1);
  root->setSortIndex(f);

 up:
  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      goto doSelf;
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }


  int f;
 doSelf:
  {
    int index;
    int rIndex = root->getDagNode()->getSortIndex();
    Assert(rIndex != Sort::SORT_UNKNOWN, "bad sort");
    int multiplicity = root->getMultiplicity();
    
    if (ACU_RedBlackNode* l = root->getLeft())
      {
	index = l->getSortIndex();
	if (ACU_RedBlackNode* r = root->getRight())
	  index = symbol->computeSortIndex(index, r->getSortIndex());
      }
    else
      {
	if (ACU_RedBlackNode* r = root->getRight())
	  index = r->getSortIndex();
	else
	  {
	    index = rIndex;
	    --multiplicity;
	  }
      }
    f = symbol->computeMultSortIndex(index, rIndex, root->getMultiplicity() - 1);
    root->setSortIndex(f);
  }

  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      goto doSelf;
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }


  int f;
 doSelf:
  {
    int index;
    int rIndex = root->getDagNode()->getSortIndex();
    int multiplicity = root->getMultiplicity();
    
    if (ACU_RedBlackNode* r = root->getRight())
      {
	index = r->getSortIndex();
	if (ACU_RedBlackNode* l = root->getLeft())
	  index = symbol->computeSortIndex(index, l->getSortIndex());
      }
    else
      {
	if (ACU_RedBlackNode* l = root->getLeft())
	  index = l->getSortIndex();
	else
	  {
	    index = rIndex;
	    --multiplicity;
	  }
      }
    f = symbol->computeMultSortIndex(index, rIndex, multiplicity);
    root->setSortIndex(f);
  }

  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      goto doSelf;
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }


  int f;
  int index;
  int rIndex;
  int multiplicity;

  rIndex = root->getDagNode()->getSortIndex();
  multiplicity = root->getMultiplicity();

 doSelf:
  {  
    if (ACU_RedBlackNode* r = root->getRight())
      {
	index = r->getSortIndex();
	if (ACU_RedBlackNode* l = root->getLeft())
	  index = symbol->computeSortIndex(index, l->getSortIndex());
      }
    else
      {
	if (ACU_RedBlackNode* l = root->getLeft())
	  index = l->getSortIndex();
	else
	  {
	    index = rIndex;
	    --multiplicity;
	  }
      }
    f = symbol->computeMultSortIndex(index, rIndex, multiplicity);
    root->setSortIndex(f);
  }

  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      {
        rIndex = root->getDagNode()->getSortIndex();
	multiplicity = root->getMultiplicity();
	goto doSelf;
      }
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }


  int f;
  int index;
  int rIndex;
  int multiplicity;

  rIndex = root->getDagNode()->getSortIndex();
  multiplicity = root->getMultiplicity();
  if (ACU_RedBlackNode* r = root->getRight())
    {
      index = r->getSortIndex();
      if (ACU_RedBlackNode* l = root->getLeft())
	index = symbol->computeSortIndex(index, l->getSortIndex());
    }
  else
    {
      if (ACU_RedBlackNode* l = root->getLeft())
	index = l->getSortIndex();
      else
	{
	  index = rIndex;
	  --multiplicity;
	}
    }

 doSelf:
  {  
    f = symbol->computeMultSortIndex(index, rIndex, multiplicity);
    root->setSortIndex(f);
  }

  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      {
        rIndex = root->getDagNode()->getSortIndex();
	multiplicity = root->getMultiplicity();
	index = f;
	if (ACU_RedBlackNode* l = root->getLeft())
	  index = symbol->computeSortIndex(index, l->getSortIndex());
	goto doSelf;
      }
    }

  return f;
}


int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }


  int f;
  int rIndex;
  int multiplicity;

  rIndex = root->getDagNode()->getSortIndex();
  multiplicity = root->getMultiplicity();
  if (ACU_RedBlackNode* r = root->getRight())
    {
      f = r->getSortIndex();
      if (ACU_RedBlackNode* l = root->getLeft())
	f = symbol->computeSortIndex(f, l->getSortIndex());
    }
  else
    {
      if (ACU_RedBlackNode* l = root->getLeft())
	f = l->getSortIndex();
      else
	{
	  f = rIndex;
	  --multiplicity;
	}
    }

 doSelf:
  {  
    f = symbol->computeMultSortIndex(f, rIndex, multiplicity);
    root->setSortIndex(f);
  }

  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      {
        rIndex = root->getDagNode()->getSortIndex();
	multiplicity = root->getMultiplicity();
	if (ACU_RedBlackNode* l = root->getLeft())
	  f = symbol->computeSortIndex(f, l->getSortIndex());
	goto doSelf;
      }
    }

  return f;
}


int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }


  int f;
  int index;
  int multiplicity;

  index = root->getDagNode()->getSortIndex();
  multiplicity = root->getMultiplicity();
  if (ACU_RedBlackNode* r = root->getRight())
    {
      f = r->getSortIndex();
      if (ACU_RedBlackNode* l = root->getLeft())
	f = symbol->computeSortIndex(f, l->getSortIndex());
    }
  else
    {
      if (ACU_RedBlackNode* l = root->getLeft())
	f = l->getSortIndex();
      else
	{
	  f = index;
	  --multiplicity;
	}
    }

 doSelf:
  {  
    f = symbol->computeMultSortIndex(f, index, multiplicity);
    root->setSortIndex(f);
  }

  if (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      {
        index = root->getDagNode()->getSortIndex();
	multiplicity = root->getMultiplicity();
	if (ACU_RedBlackNode* l = root->getLeft())
	  f = symbol->computeSortIndex(f, l->getSortIndex());
	goto doSelf;
      }
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }


  int f;
  int index;
  int multiplicity;

  index = root->getDagNode()->getSortIndex();
  multiplicity = root->getMultiplicity();
  if (ACU_RedBlackNode* r = root->getRight())
    {
      f = r->getSortIndex();
      if (ACU_RedBlackNode* l = root->getLeft())
	f = symbol->computeSortIndex(f, l->getSortIndex());
    }
  else
    {
      if (ACU_RedBlackNode* l = root->getLeft())
	f = l->getSortIndex();
      else
	{
	  f = index;
	  --multiplicity;
	}
    }

  for (;;)
    {
      f = symbol->computeMultSortIndex(f, index, multiplicity);
      root->setSortIndex(f);
      if (s.empty())
	break;

      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;

      index = root->getDagNode()->getSortIndex();
      multiplicity = root->getMultiplicity();
      if (ACU_RedBlackNode* l = root->getLeft())
	f = symbol->computeSortIndex(f, l->getSortIndex());
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }
  int f;
  {
    int index = root->getDagNode()->getSortIndex();
    int multiplicity = root->getMultiplicity();
    if (ACU_RedBlackNode* r = root->getRight())
      {
	f = r->getSortIndex();
	if (ACU_RedBlackNode* l = root->getLeft())
	  f = symbol->computeSortIndex(f, l->getSortIndex());
      }
    else
      {
	if (ACU_RedBlackNode* l = root->getLeft())
	  f = l->getSortIndex();
	else
	  {
	    f = index;
	    --multiplicity;
	  }
      }
    f = symbol->computeMultSortIndex(f, index, multiplicity);
    root->setSortIndex(f);
  }
  while (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      if (ACU_RedBlackNode* l = root->getLeft())
	f = symbol->computeSortIndex(f, l->getSortIndex());
      f = symbol->computeMultSortIndex(f,
				       root->getDagNode()->getSortIndex(),
				       root->getMultiplicity());
      root->setSortIndex(f);
    }

  return f;
}


int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }
  int f;
  {
    int index = root->getDagNode()->getSortIndex();
    int multiplicity = root->getMultiplicity();
    if (ACU_RedBlackNode* r = root->getRight())
      {
	f = r->getSortIndex();
	if (ACU_RedBlackNode* l = root->getLeft())
	  f = symbol->computeSortIndex(f, l->getSortIndex());
      }
    else
      {
	if (ACU_RedBlackNode* l = root->getLeft())
	  f = l->getSortIndex();
	else
	  {
	    f = index;
	    --multiplicity;
	  }
      }
    f = symbol->computeMultSortIndex(f, index, multiplicity);
    root->setSortIndex(f);
  }
  while (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      n = root->getLeft();
      if (n == oldRoot)
	goto tryRight;
      if (n != 0)
	f = symbol->computeSortIndex(f, n->getSortIndex());
      f = symbol->computeMultSortIndex(f,
				       root->getDagNode()->getSortIndex(),
				       root->getMultiplicity());
      root->setSortIndex(f);
    }

  return f;
}


int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }
  int f;
  {
    f = root->getDagNode()->getSortIndex();
    f = symbol->computeMultSortIndex(f, f, root->getMultiplicity() - 1);
    if (ACU_RedBlackNode* l = root->getLeft())
      f = symbol->computeSortIndex(f, l->getSortIndex());
    if (ACU_RedBlackNode* r = root->getRight())
      f = symbol->computeSortIndex(f, r->getSortIndex());
    root->setSortIndex(f);
  }
  while (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      n = root->getLeft();
      if (n == oldRoot)
	goto tryRight;
      if (n != 0)
	f = symbol->computeSortIndex(f, n->getSortIndex());
      f = symbol->computeMultSortIndex(f,
				       root->getDagNode()->getSortIndex(),
				       root->getMultiplicity());
      root->setSortIndex(f);
    }

  return f;
}



int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  ACU_Stack s;
  ACU_RedBlackNode* n;

  for(;;)
    {
      n = root->getLeft();
      if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	{
	tryRight:
	  n = root->getRight();
	  if (n == 0 || n->getSortIndex() != Sort::SORT_UNKNOWN)
	    break;
	}
      s.push(root);
      root = n;
    }

  int f = root->getDagNode()->getSortIndex();
  f = symbol->computeMultSortIndex(f, f, root->getMultiplicity() - 1);
  n = root->getLeft();
  if (n != 0)
    f = symbol->computeSortIndex(f, n->getSortIndex());
  n = root->getRight();
  if (n != 0)
    f = symbol->computeSortIndex(f, n->getSortIndex());
  root->setSortIndex(f);

  while (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      n = root->getLeft();
      if (n == oldRoot)
	goto tryRight;
      if (n != 0)
	f = symbol->computeSortIndex(f, n->getSortIndex());
      f = symbol->computeMultSortIndex(f,
				       root->getDagNode()->getSortIndex(),
				       root->getMultiplicity());
      root->setSortIndex(f);
    }

  return f;
}


