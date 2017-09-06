//
//      Implementation for class CUI_DagNode.
//
#ifdef __GNUG__
#pragma implementation
#endif
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "CUI_Theory.hh"
 
//      interface class definitions
#include "binarySymbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "rawDagArgumentIterator.hh"
#include "lhsAutomaton.hh"
#include "rhsAutomaton.hh"
#include "subproblem.hh"
#include "extensionInfo.hh"
 
//      core class definitions
#include "substitution.hh"
#include "rewritingContext.hh"

//      CUI theory class definitions
#include "CUI_Symbol.hh"
#include "CUI_DagNode.hh"
#include "CUI_DagArgumentIterator.hh"

RawDagArgumentIterator*
CUI_DagNode::arguments()
{
  return new CUI_DagArgumentIterator(argArray);
}

size_t
CUI_DagNode::getHashValue()
{
  if (isHashValid())
    return hashCache;
  size_t hashValue = hash(hash(symbol()->getHashValue(), argArray[0]->getHashValue()),
			  argArray[1]->getHashValue());
  hashCache = hashValue;
  setHashValid();
  return hashValue;
}

int
CUI_DagNode::compareArguments(const DagNode* other) const
{
  const CUI_DagNode* d = static_cast<const CUI_DagNode*>(other);
  int r = argArray[0]->compare(d->argArray[0]);
  if (r != 0)
    return r;
  return argArray[1]->compare(d->argArray[1]);
}

DagNode*
CUI_DagNode::markArguments()
{
  argArray[0]->mark();
  return argArray[1];
}

DagNode*
CUI_DagNode::copyEagerUptoReduced2()
{
  CUI_Symbol* s = symbol();
  CUI_DagNode* n = new CUI_DagNode(s);
  n->argArray[0] = s->eagerArgument(0) ? argArray[0]->copyEagerUptoReduced() : argArray[0];
  n->argArray[1] = s->eagerArgument(1) ? argArray[1]->copyEagerUptoReduced() : argArray[1];
  return n;
}

void
CUI_DagNode::clearCopyPointers2()
{
  argArray[0]->clearCopyPointers();
  argArray[1]->clearCopyPointers();
}

void
CUI_DagNode::overwriteWithClone(DagNode* old)
{
  CUI_DagNode* d = new(old) CUI_DagNode(symbol());
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
  d->argArray[0] = argArray[0];
  d->argArray[1] = argArray[1];
}

DagNode*
CUI_DagNode::makeClone()
{
  CUI_DagNode* d = new CUI_DagNode(symbol());
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
  d->argArray[0] = argArray[0];
  d->argArray[1] = argArray[1];
  return d;
}

DagNode*
CUI_DagNode::copyWithReplacement(int argIndex, DagNode* replacement)
{
  CUI_DagNode* d = new CUI_DagNode(symbol());
  if (argIndex == 0)
    {
      d->argArray[0] = replacement;
      d->argArray[1] = argArray[1];
    }
  else
    {
      Assert(argIndex == 1, cerr << "bad argument index");
      d->argArray[0] = argArray[0];
      d->argArray[1] = replacement;
    }
  return d;
}

DagNode*
CUI_DagNode::copyWithReplacement(Vector<RedexPosition>& redexStack,
				 int first,
				 int last)
{
  if (first == last)
    return copyWithReplacement(redexStack[first].argIndex(), redexStack[first].node());

  Assert(first + 1 == last, cerr << "nrArgs clash");
  CUI_DagNode* d = new CUI_DagNode(symbol());
  d->argArray[0] = redexStack[first].node();
  d->argArray[1] = redexStack[last].node();
  return d;
}

void
CUI_DagNode::stackArguments(Vector<RedexPosition>& stack,
			    int parentIndex,
			    bool respectFrozen)
{
  const NatSet& frozen = symbol()->getFrozen();
  DagNode* d = argArray[0];
  if (!(respectFrozen && frozen.contains(0)) && !(d->isUnstackable()))
    stack.append(RedexPosition(d, parentIndex, 0));
  d = argArray[1];
  if (!(respectFrozen && frozen.contains(1)) && !(d->isUnstackable()))
    stack.append(RedexPosition(d, parentIndex, 1));
}

void
CUI_DagNode::collapseTo(int argNr)
{
  DagNode* remaining = (symbol()->eagerArgument(argNr)) ?
    argArray[argNr] : argArray[argNr]->copyReducible();
  remaining->overwriteWithClone(this);
}

bool
CUI_DagNode::normalizeAtTop()
{
  CUI_Symbol* s = symbol();
  Term* identity = s->getIdentity();
  if (identity != 0)
    {
      if (s->leftId() && identity->equal(argArray[0]))
	{
	  collapseTo(1);
	  return true;
	}
      if (s->rightId() && identity->equal(argArray[1]))
	{
	  collapseTo(0);
	  return true;
	}
    }
  if (s->comm() || s->idem())
    {
      int r = argArray[0]->compare(argArray[1]);
      if (s->idem() && r == 0)
	{
	  collapseTo(0);
	  return true;
	}
      if (s->comm() && r > 0)
	{
	  DagNode* t = argArray[0];
	  argArray[0] = argArray[1];
	  argArray[1] = t;
	}
    }
  return false;
}

