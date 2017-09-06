int
ACU_Tree::cbs(BinarySymbol* symbol, int index, ACU_RedBlackNode* root)
{
  int k = root->getSortIndex();
  if (k != Sort::SORT_UNKNOWN)
    return symbol->computeSortIndex(index, k);

  int t = root->getDagNode()->getSortIndex();
  Assert(index != Sort::SORT_UNKNOWN, "bad sort");
  index = symbol->computeMultSortIndex(index, t, root->getMultiplicity());

  if (ACU_RedBlackNode* l = root->getLeft())
    index = symbol->cbs(symbol, index, l);
      
  if (ACU_RedBlackNode* r = root->getRight())
    index = symbol->cbs(symbol, index, r)

  root->setSortIndex(index);
  return index;
}

int
ACU_Tree::cbs(BinarySymbol* symbol, int index, ACU_RedBlackNode* root)
{
  ACU_Stack s;

 down:
  int k = root->getSortIndex();
  if (k != Sort::SORT_UNKNOWN)
    {
      index = symbol->computeSortIndex(index, k);
      goto up;
    }

  int t = root->getDagNode()->getSortIndex();
  Assert(index != Sort::SORT_UNKNOWN, "bad sort");
  index = symbol->computeMultSortIndex(index, t, root->getMultiplicity());

  if (ACU_RedBlackNode* l = root->getLeft())
    {
      s.push(root);
      root = l;
      goto down;
    }
  else
    goto right;

 up:
  u = s.top();
  if (u->getLeft() == root)  // up from left branch
    {
      root = u;
      
    right:
      if (ACU_RedBlackNode* r = u->getRight())
	{
	  root = r;
	  goto down;
	}
    }
  root = s.pop();
  root->setSortIndex(index);
  s.pop();
  if (!empty())
    goto up;

  return index;
}

int
ACU_Tree::cbs(BinarySymbol* symbol, int index, ACU_RedBlackNode* root)
{
  ACU_Stack s;

 down:
  int k = root->getSortIndex();
  if (k != Sort::SORT_UNKNOWN)
    {
      index = symbol->computeSortIndex(index, k);
      goto up;
    }

  int t = root->getDagNode()->getSortIndex();
  Assert(index != Sort::SORT_UNKNOWN, "bad sort");
  index = symbol->computeMultSortIndex(index, t, root->getMultiplicity());

  if (ACU_RedBlackNode* l = root->getLeft())
    {
      s.push(root);
      root = l;
      goto down;
    }
  else
    {
    right:
      if (ACU_RedBlackNode* r = root->getRight())
	{
	  s.push(root);
	  root = r;
	  goto down;
	}
      else
	goto up;
    }

 up:
  ACU_RedBlackNode* root oldRoot = root;
  root = s.pop();
  if (root->getLeft() == oldRoot)
    goto right;

  root->setSortIndex(index);
  if (!(s.empty()))
    goto up;

  return index;
}


int
ACU_Tree::cbs(BinarySymbol* symbol, ACU_RedBlackNode* root)
{
  int index = root->getDagNode()->getSortIndex();
  Assert(index != Sort::SORT_UNKNOWN, "bad sort");
  index = symbol->computeMultSortIndex(index, index, root->getMultiplicity() - 1);

  ACU_Stack s;
  
  for (;;)
    {
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

      int t = root->getSortIndex();
      if (t != Sort::SORT_UNKNOWN)
	{
	  index = symbol->computeSortIndex(index, t);
	  break;
	}
      
      t = root->getDagNode()->getSortIndex();
      Assert(index != Sort::SORT_UNKNOWN, "bad sort");
      index = symbol->computeMultSortIndex(index, t, root->getMultiplicity());
    }

  while (!(s.empty()))
    {
      int oldRoot = root;
      root = s.pop();
      if (root->getLeft() == oldRoot)
	goto tryRight;
      root->setSortIndex(index);
    }

  return index;  // Wrong because we tried to use indices from above
}
