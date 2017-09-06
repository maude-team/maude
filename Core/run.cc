void
RewritingContext::reduce()
{
  rootNode->reduce(*this);
}

void
RewritingContext::ruleRewrite(Int64 limit)
{
  Vector<RedexPosition> redexStack;
  for (Int64 nrRewrites = 0;; nrRewrites++)
    {
      reduce();
      if (nrRewrites == limit)
	return;
      redexStack.contractTo(0);
      redexStack.append(RedexPosition(rootNode, UNDEFINED, UNDEFINED));

      int nextToExplore = 0;
      int finish = redexStack.length();
      for (int nextToRewrite = 0;; nextToRewrite++)
	{
	  if (nextToRewrite == finish)
	    {
	      for (;;)
		{
		  if (nextToExplore == finish)
		    return;
		  DagNode* d = redexStack[nextToExplore].node();
		  d->stackArguments(redexStack, nextToExplore, true);
		  ++nextToExplore;
		  int len = redexStack.length();
		  if (len > finish)
		    {
		      finish = len;
		      break;
		    }
		  d->setUnstackable();
		}
	    }

	  DagNode* d = redexStack[nextToRewrite].node();
	  if (d->isUnrewritable())
	    continue;
	  DagNode* r = d->symbol()->ruleRewrite(d, *this);
	  if (r == 0)
	    d->setUnrewritable();
	  else
	    {
	      int argIndex = redexStack[nextToRewrite].argIndex();
	      DagNode* p = r;
	      for (int i = redexStack[nextToRewrite].parentIndex(); i != UNDEFINED;)
		{
		  RedexPosition& rp = redexStack[i];
		  p = rp.node()->copyWithReplacement(argIndex, p);
		  argIndex = rp.argIndex();
		  i = rp.parentIndex();
		}
	      rootNode = p;
	      if (traceFlag)
		{
		  if (traceAbort())
		    return;
		  tracePostRuleRewrite(r);
		}
	      DagNode::okToCollectGarbage();
	      break;
	    }
	}
    }
}

void
RewritingContext::fairRewrite(Int64 limit, Int64 gas)
{
  rewriteLimit = limit;
  gasPerNode = gas;
  currentIndex = 0;
  lazyMarker = NONE;

  reduce();
  redexStack.contractTo(0);
  redexStack.append(RedexPosition(rootNode, UNDEFINED, UNDEFINED, true));

  do
    {
      progress = false;
      if (fairTraversal(true))
	return;
    }
  while(progress);
}

void
RewritingContext::fairContinue(Int64 limit)
{
  if (progress)
    {
      rewriteLimit = limit;
      if (fairTraversal(false))
	return;
      do
	{
	  progress = false;
	  if (fairTraversal(true))
	    return;
	}
      while (progress);
    }
}

bool
RewritingContext::fairTraversal(bool newTraversal)
{
  //
  //	Return true if we stop mid-traversal because of rewrite limit
  //	and false if traversal completed.
  //
  bool argsUnstackable;
  if (newTraversal)
    {
      descend();
      argsUnstackable = true;
      currentGas = gasPerNode;
    }
  else
    argsUnstackable = (redexStack[currentIndex].node()->symbol()->arity() == 0);

  while (!doRewriting(argsUnstackable))  // until we hit rewrite limit
    {
      if (currentIndex == 0)
	return false;  // end of traversal
      //
      //	Check if we are leaving the node pointed at by the
      //	lazy marker.
      //
      if (currentIndex == lazyMarker)
	lazyMarker = NONE;
      //
      //	Find next potentially rewritable node using depth-first
      //	traversal by checking for a right sibling on the stack,
      //	and failing that ascending.
      //
      if (currentIndex + 1 < redexStack.length())
	{
	  Assert(redexStack[currentIndex].parentIndex() ==
		 redexStack[currentIndex + 1].parentIndex(),
		 "redexStack corrupt");
	  ++currentIndex;  // across to sibling
	  descend();
	  argsUnstackable = true;
	}
      else
	argsUnstackable = ascend();
      currentGas = gasPerNode;
    }
  return true;
}

bool
RewritingContext::ascend()
{
  //
  //	Go up one node.
  //	Return true if new current node is guaranteed to have all args unstackable.
  //
  //	Because we only ascend when we have no right sibling on the stack
  //	we can assume current node is the last stacked argument of its parent.
  //
  int last = currentIndex;
  //
  //	Parent becomes current.
  //
  currentIndex = redexStack[currentIndex].parentIndex();
  //
  //	Now we need to find first stacked argument of parent node.
  //
  int first = last;
  while (redexStack[first - 1].parentIndex() == currentIndex)
    --first;
  //
  //	Rebuild parent node if it is stale.
  //
  RedexPosition& rp = redexStack[currentIndex];
  if (staleMarker == currentIndex)
    {
      rp.replaceNode(rp.node()->copyWithReplacement(redexStack, first, last));
      staleMarker = rp.parentIndex();  // our parent now becomes stale
      DagNode::okToCollectGarbage();
    }
  //
  //	Reduce node if needed and check for unstackable args.
  //
  DagNode* d = rp.node();
  bool argsUnstackable;
  if (lazyMarker != NONE || d->isReduced())
    {
      argsUnstackable = true;
      for (int i = first; i <= last; i++)
	{
	  if (!(redexStack[i].node()->isUnstackable()))
	    {
	      argsUnstackable = false;
	      break;
	    }
	}
    }
  else
    {
      d->reduce(*this);
      argsUnstackable = (d->symbol()->arity() == 0);
    }
  //
  //	Remove arguments of new current node from the stack.
  //
  redexStack.contractTo(first);
  return argsUnstackable;
}

void
RewritingContext::descend()
{
  //
  //	Finds leftmost leaf (or quasi-leaf) below currentIndex.
  //	Updates redexStack, currentIndex and lazyMarker.
  //
  for (;;)
    {
      DagNode* d = redexStack[currentIndex].node();
      //
      //	Whenever we arrive at a non-eager node, if the lazy
      //	marker is not set, we point it at this node. Then
      //	until we leave this node and its descendents we must not
      //	do equational rewriting.
      //
      if (lazyMarker == NONE && !(redexStack[currentIndex].isEager()))
	lazyMarker = currentIndex;
      //
      //	We ask the dag nodes symbol to stack those arguments
      //	which are not either frozen or unstackable.
      //
      int first = redexStack.length();
      d->symbol()->stackArguments(d, redexStack, currentIndex);
      //
      //	If no new dag nodes were stacked we hit a quasi-leaf.
      //
      if (first == redexStack.length())
	break;
      //
      //	Otherwise set current node to the first (leftmost)
      //	stacked argument and continue down the term.
      //
      currentIndex = first;
    }
}

bool
RewritingContext::doRewriting(bool argsUnstackable)
{
  //
  //	Tries to rewrite node at currentIndex.
  //	Returns true if we stop because of rewrite limit.
  //	Return false we stop because we ran out of gas or because
  //	no more rewrites are possible.
  //	Updates redexStack, currentGas, nrRewritesAllowed, progress.
  //	Only routine in fair rewriting that sets unrewritable/unstackable
  //	flags.
  //
  DagNode* d = redexStack[currentIndex].node();
  if (d->isUnrewritable())
    {
      //
      //	*d's unrewritable flag could have been set in an
      //	earlier traversal when it had a stackable argument.
      //	If no rewrites occurred in this stackable argument it
      //	would eventually become unstackable and *d would never
      //	become stale and never be replaced. So we need to check
      //	for this case.
      //
      if (argsUnstackable)
	d->setUnstackable();
    }
  else
    {
      Symbol* s = d->symbol();
      while (currentGas > 0)
	{
	  DagNode* r = s->ruleRewrite(d, *this);
	  if (r == 0)
	    {
	      //
	      //	Always set unrewritable flag, even if we are
	      //	also unstackable since *d may have been
	      //	stacked multiple times along different paths.
	      //
	      d->setUnrewritable();
	      if (argsUnstackable)
		d->setUnstackable();
	      break;
	    }
	  progress = true;
	  d = r;
	  redexStack[currentIndex].replaceNode(r);
	  staleMarker = redexStack[currentIndex].parentIndex();
	  DagNode::okToCollectGarbage();
	  if (traceFlag)
	    {
	      if (traceAbort())
		return true;  // pretend we hit rewrite limit
	      tracePostRuleRewrite(r);
	    }
	  if (lazyMarker == NONE)
	    d->reduce(*this);
	  --currentGas;
	  if (rewriteLimit != NONE && --rewriteLimit == 0)
	    return true;
	  s = d->symbol();
	  argsUnstackable = (s->arity() == 0);
	}
    }
  return false;
}
