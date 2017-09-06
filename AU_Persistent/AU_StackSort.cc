//
//	Sort computations on presistent stacks.
//

int
AU_StackNode::fwdComputeBaseSort(Symbol* symbol)
{
  AU_StackNode* p = this;
  AU_StackNode* n;
  //
  //	First we perform pointer reversal on all nodes except the first
  //	that need their sort calculated.
  //
  for (AU_StackNode* i = p->next;
       i != 0 && i->getSortIndex() == Sort::SORT_UNKNOWN;
       i = n)
    {
      n = i->next;
      i->next = p;
      p = i;
    }
  //
  //	Now we traverse the reversed linked list, filling in sort
  //	information and restoring next pointers.
  //
  //	p points to the last node that needs to have its sort calculated 
  //	and next pointer restored. n is the old next pointer value that
  //	needs to be restored.
  //
  int index = Sort::SORT_UNKNOWN;
  for (AU_StackNode* i = p; i != this; i = p)
    {
      int index2 = i->args[ELEMENTS_PER_NODE - 1]->getSortIndex();
      index = (index == Sort::SORT_UNKNOWN) ? index2 :
	symbol->traverse(symbol->traverse(0, index2), index);
      for (int j = ELEMENTS_PER_NODE - 2; j >= 0; --j)
	{
	  int index2 = i->args[j]->getSortIndex();
	  index = symbol->traverse(symbol->traverse(0, index2), index);
	}
      i->setSortIndex(index);
	
      p = i->next;
      i->next = n;
      n = i;
    }
  //
  //	Compute sort for this node.
  //
  int index2 = args[ELEMENTS_PER_NODE - 1]->getSortIndex();
  index = (index == Sort::SORT_UNKNOWN) ? index2 :
	symbol->traverse(symbol->traverse(0, index2), index);
  for (int j = ELEMENTS_PER_NODE - 2; j >= 0; --j)
    {
      DagNode* d = args[j];
      if (d == 0)
	break;
      int index2 = d->getSortIndex();
      index = symbol->traverse(symbol->traverse(0, index2), index);
    }
  setSortIndex(index);
  return index;
}

int
AU_StackNode::revComputeBaseSort(Symbol* symbol)
{
  //
  //	This function is symmetric to the above - we just swap the args
  //	to the sort calculation function.
  //
  AU_StackNode* p = this;
  AU_StackNode* n;
  //
  //	First we perform pointer reversal on all nodes except the first
  //	that need their sort calculated.
  //
  for (AU_StackNode* i = p->next;
       i != 0 && i->getSortIndex() == Sort::SORT_UNKNOWN;
       i = n)
    {
      n = i->next;
      i->next = p;
      p = i;
    }
  //
  //	Now we traverse the reversed linked list, filling in sort
  //	information and restoring next pointers.
  //
  //	p points to the last node that needs to have its sort calculated 
  //	and next pointer restored. n is the old next pointer value that
  //	needs to be restored.
  //
  int index = Sort::SORT_UNKNOWN;
  for (AU_StackNode* i = p; i != this; i = p)
    {
      int index2 = i->args[ELEMENTS_PER_NODE - 1]->getSortIndex();
      index = (index == Sort::SORT_UNKNOWN) ? index2 :
	symbol->traverse(symbol->traverse(0, index), index2);
      for (int j = ELEMENTS_PER_NODE - 2; j >= 0; --j)
	{
	  int index2 = i->args[j]->getSortIndex();
	  index = symbol->traverse(symbol->traverse(0, index), index2);
	}
      i->setSortIndex(index);
	
      p = i->next;
      i->next = n;
      n = i;
    }
  //
  //	Compute sort for this node.
  //
  int index2 = args[ELEMENTS_PER_NODE - 1]->getSortIndex();
  index = (index == Sort::SORT_UNKNOWN) ? index2 :
	symbol->traverse(symbol->traverse(0, index), index2);
  for (int j = ELEMENTS_PER_NODE - 2; j >= 0; --j)
    {
      DagNode* d = args[j];
      if (d == 0)
	break;
      int index2 = d->getSortIndex();
      index = symbol->traverse(symbol->traverse(0, index), index2);
    }
  setSortIndex(index);
  return index;
}
