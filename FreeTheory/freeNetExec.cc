//
//	Code for execution of free theory discrimination net.
//
//	We no longer inline this because it would make for large stack frames
//	in eqRewrite() which is highly recursive.
//
#ifdef SPEED_HACKS

bool
FreeNet::applyReplace2(DagNode* subject, RewritingContext& context)
{
  //
  //	First traverse discrimination net to find the sequence of equations
  //	(actually remainder pointers) which match the free symbol skeleton in the
  //	subject.
  //
  int i;
  if (!(net.isNull()))  // at least one pattern has free symbols
    {
      DagNode** topArgArray = static_cast<FreeDagNode*>(subject)->argArray();
      Vector<TestNode>::const_iterator netBase = net.begin();
      Vector<TestNode>::const_iterator n = netBase;
      DagNode* d = topArgArray[n->argIndex];
      Symbol* ds = d->symbol();
      stack[0] = topArgArray;
      for (;;)
	{
	  DagNode*** p;
	  if (ds != n->symbol)
	    {
	      i = n->notEqual[getSignBit(ds->compare(n->symbol))];
	      if (i <= 0)
		{
		  if (i == 0)
		    return false;
		  i = (-1) - i;
		  break;
		}
	      n = netBase + i;
	      p = n->positionPtr;
	      if (p == 0)
		continue;
	    }
	  else
	    {
	      if (n->slotPtr != 0)
		*(n->slotPtr) = static_cast<FreeDagNode*>(d)->argArray();
	      i = n->equal;
	      if (i <= 0)
		{
		  i = (-1) - i;
		  break;
		}
	      n = netBase + i;
	      p = n->positionPtr;
	    }
	  d = (*p)[n->argIndex];
	  ds = d->symbol();
	}
    }
  else
    {
      if (subject->symbol()->arity() != 0)  // top symbol is not a constant
	stack[0] = static_cast<FreeDagNode*>(subject)->argArray();
      i = 0;
    }
  //
  //	Now go through the sequence of remainders, trying to finish the
  //	matching process for each one in turn.
  //
  Vector<FreeRemainder*>::const_iterator p = fastApplicable[i].begin();
  const FreeRemainder* r = *p;
  do
    {
      if (r->fastMatchReplace(subject, context, stack))
	return true;
    }
  while ((r = *(++p)) != 0);
  return false;
}

#else

bool
FreeNet::applyReplace2(DagNode* subject, RewritingContext& context)
{
  //
  //	First traverse discrimination net to find the sequence of equations
  //	(actually equation indices) which match the free symbol skeleton in the
  //	subject.
  //
  int i = 0;
  if (subject->symbol()->arity() != 0)  // top symbol is not a constant
    {
      Vector<DagNode**>& stackBase = stack;
      stackBase[0] = static_cast<FreeDagNode*>(subject)->argArray();
      if (net.length() > 0)  // at least one pattern has free symbols
	{
	  Vector<TestNode>& netBase = net;
	  TestNode* n = &(netBase[0]);
	  DagNode* d = stackBase[0][n->argIndex];
	  Symbol* ds = d->symbol();
	  for (;;)
	    {
	      int p;
	      if (ds != n->symbol)
		{
		  i = n->notEqual[getSignBit(ds->compare(n->symbol))];
		  if (i <= 0)
		    break;
		  n = &(netBase[i]);
		  p = n->position;
		  if (p < 0)
		    continue;
		}
	      else
		{
		  if (n->slot >= 0)
		    stackBase[n->slot] = static_cast<FreeDagNode*>(d)->argArray();
		  i = n->equal;
		  if (i <= 0)
		    break;
		  n = &(netBase[i]);
		  p = n->position;
		}
	      d = stackBase[p][n->argIndex];
	      ds = d->symbol();
	    }
	  if (i == 0)
	    return false;
	  i = (-1) - i;
	}
    }
  //
  //	Now go through the sequence of equations, trying to finish the
  //	matching process for each one in turn.
  //
  const NatSet& eqSet = applicable[i];
  const NatSet::const_iterator e = eqSet.end();
  for (NatSet::const_iterator j = eqSet.begin(); j != e; ++j)
    {
      if (remainders[*j]->fastMatchReplace(subject, context, stack))
	return true;
    }
  return false;
}

#endif
