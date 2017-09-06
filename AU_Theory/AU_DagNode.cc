//
//      Implementation for class AU_DagNode.
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
#include "AU_Theory.hh"
 
//      interface class definitions
#include "term.hh"

//      AU theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"
#include "AU_DagArgumentIterator.hh"
#include "AU_ExtensionInfo.hh"
#include "AU_Subproblem.hh"

#include "AU_DagOperations.cc"

AU_DagNode::~AU_DagNode()
{
}

RawDagArgumentIterator*
AU_DagNode::arguments()
{
  return new AU_DagArgumentIterator(argArray);
}

size_t
AU_DagNode::getHashValue()
{
  size_t hashValue = symbol()->getHashValue();
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    hashValue = hash(hashValue, argArray[i]->getHashValue());
  return hashValue;
}

int
AU_DagNode::compareArguments(const DagNode* other) const
{
  int nrArgs = argArray.length();
  const ArgVec<DagNode*>& argArray2 = static_cast<const AU_DagNode*>(other)->argArray;
  int nrArgs2 = argArray2.length();
  int limit = min(nrArgs, nrArgs2);
  Assert(limit >= 1, cerr << "no arguments");
  
  ArgVec<DagNode*>::const_iterator i = argArray.begin();
  ArgVec<DagNode*>::const_iterator j = argArray2.begin();
  do
    {
      int r = (*i)->compare(*j);
      if (r != 0)
	return r;
      ++i;
      ++j;
    }
  while (--limit > 0);
  return nrArgs - nrArgs2;
}

DagNode*
AU_DagNode::markArguments()
{
  argArray.evacuate();
  int nrArgs = argArray.length();
  Assert(nrArgs > 0, cerr << "no arguments");

  ArgVec<DagNode*>::const_iterator i = argArray.begin();
  while (--nrArgs > 0)
    {
      (*i)->mark();
      ++i;
    }
  return *i;
}

DagNode*
AU_DagNode::copyEagerUptoReduced2()
{
  int nrArgs = argArray.length();
  AU_Symbol* s = static_cast<AU_Symbol*>(symbol());
  AU_DagNode* n = new AU_DagNode(s, nrArgs);
  if (s->getPermuteStrategy() == BinarySymbol::EAGER)
    {
      for (int i = 0; i < nrArgs; i++)
	  n->argArray[i] = argArray[i]->copyEagerUptoReduced();
    }
  else
    {
      for (int i = 0; i < nrArgs; i++)
	n->argArray[i] = argArray[i];
    }
  return n;
}

void
AU_DagNode::clearCopyPointers2()
{
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    argArray[i]->clearCopyPointers();
}

void
AU_DagNode::overwriteWithClone(DagNode* old)
{
  int nrArgs = argArray.length();
  AU_DagNode* d = new(old) AU_DagNode(symbol(), nrArgs);
  d->setTheoryByte(getTheoryByte());
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
  for (int i = 0; i < nrArgs; i++)
    d->argArray[i] = argArray[i];
}

DagNode*
AU_DagNode::makeClone()
{
  int nrArgs = argArray.length();
  AU_DagNode* d = new AU_DagNode(symbol(), nrArgs);
  d->setTheoryByte(getTheoryByte());
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
  for (int i = 0; i < nrArgs; i++)
    d->argArray[i] = argArray[i];
  return d;
}

AU_DagNode::NormalizationResult
AU_DagNode::normalizeAtTop()
{
  AU_Symbol* s = symbol();
  Term* identity = s->getIdentity();
  int nrArgs = argArray.length();
  int expansion = 0;
  int nrIdentities = 0;
  //
  //	First examine the argument list looking for either our top symbol
  //	or our identity.
  //
  if (identity == 0)
    {
      for (int i = 0; i < nrArgs; i++)
	{
	  DagNode* d = argArray[i];
	  if (d->symbol() == s)
	    expansion += static_cast<AU_DagNode*>(d)->argArray.length() - 1;
	}
    }
  else
    {
      for (int i = 0; i < nrArgs; i++)
	{
	  DagNode* d = argArray[i];
	  if (d->symbol() == s)
	    expansion += static_cast<AU_DagNode*>(d)->argArray.length() - 1;
	  else if (identity->equal(d) &&
		   ((i > 0 && s->rightId()) || (i < nrArgs - 1 && s->leftId())))
	    ++nrIdentities;
	}
    }
  // cout << "this = " << this << "\tnrIdentities = " << nrIdentities <<
  //  "\texpansion = " << expansion << '\n';
  //
  //	Now deal efficiently with all the special cases.
  //
  if (nrIdentities == 0)
    {
      if (expansion == 0)
	return NORMAL;
      //
      //	Flattening but no identities.
      //
      argArray.expandBy(expansion);
      int p = nrArgs + expansion - 1;
      for (int i = nrArgs - 1; i >= 0; i--)
	{
	  Assert(p >= i, cerr << "loop invarient failed");
	  DagNode* d = argArray[i];
	  if (d->symbol() == s)
	    {
	      ArgVec<DagNode*>& argArray2 = static_cast<AU_DagNode*>(d)->argArray;
	      for (int j = argArray2.length() - 1; j >= 0; j--)
		argArray[p--] = argArray2[j];
	    }
	  else
	    argArray[p--] = argArray[i];
	}
      Assert(p == -1, cerr << "bad argArray length");
      DagNode::okToCollectGarbage();  // needed because of pathological nesting
      return FLATTENED;
    }
  if (expansion == 0)
    {
      //
      //	Identities but no flattening.
      //
      int p = 0;
      for (int i = 0; i < nrArgs; i++)
	{
	  DagNode* d = argArray[i];
	  if (!(identity->equal(d) &&
		((i > 0 && s->rightId()) || (i < nrArgs - 1 && s->leftId()))))
	    argArray[p++] = d;
	}
      if (p < 2)
	{
	  //
	  //	Eliminating identity causes AU dag node to collapse to its
	  //	remaining argument or 1st argument of all arguments were
	  //	identity.
	  //
	  DagNode* remaining = (s->getPermuteStrategy() == BinarySymbol::EAGER) ?
	    argArray[0] : argArray[0]->copyReducible();
	  remaining->overwriteWithClone(this);
	  return COLLAPSED;
	}
      argArray.contractTo(p);
      return NORMAL;
    }
  //
  //	Flattening and identities.
  //
  ArgVec<DagNode*> buffer(nrArgs + expansion - nrIdentities);
  int p = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* d = argArray[i];
      if (d->symbol() == s)
	{
	  ArgVec<DagNode*>& argArray2 = static_cast<AU_DagNode*>(d)->argArray;
	  int nrArgs2 = argArray2.length();
	  for (int j = 0; j < nrArgs2; j++)
	    buffer[p++] = argArray2[j];
	}
      else if (!(identity->equal(d) &&
		 ((i > 0 && s->rightId()) || (i < nrArgs - 1 && s->leftId()))))
	buffer[p++] = d;
    }
  Assert(p == nrArgs + expansion - nrIdentities, cerr << "bad buffer size");
  argArray.swap(buffer);
  DagNode::okToCollectGarbage();  // needed because of pathological nesting
  return FLATTENED;
}

DagNode*
AU_DagNode::copyWithReplacement(int argIndex, DagNode* replacement)
{
  int nrArgs = argArray.length();
  AU_DagNode* n = new AU_DagNode(symbol(), nrArgs);
  ArgVec<DagNode*>& args2 = n->argArray;
  for (int i = 0; i < nrArgs; i++)
    args2[i] = (i == argIndex) ? replacement : argArray[i];
  return n;
}

DagNode*
AU_DagNode::copyWithReplacement(Vector<RedexPosition>& redexStack,
				int first,
				int last)
{
  int nrArgs = argArray.length();
  AU_DagNode* n = new AU_DagNode(symbol(), nrArgs);
  ArgVec<DagNode*>& args = n->argArray;
  int nextReplacementIndex = redexStack[first].argIndex();
  for (int i = 0; i < nrArgs; i++)
    {
      if (i == nextReplacementIndex)
	{
	  args[i] = redexStack[first].node();
	  ++first;
	  nextReplacementIndex = (first <= last) ?
	    redexStack[first].argIndex() : NONE;
	}
      else
	args[i] = argArray[i];
    }
  return n;
}

void
AU_DagNode::stackArguments(Vector<RedexPosition>& stack,
			   int parentIndex,
			   bool respectFrozen)
{
  if (respectFrozen && !(symbol()->getFrozen().empty()))
    return;
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* d = argArray[i];
      if (!(d->isUnstackable()))
	stack.append(RedexPosition(d, parentIndex, i));
    }
}

void
AU_DagNode::partialReplace(DagNode* replacement, ExtensionInfo* extensionInfo)
{
  AU_ExtensionInfo* e = static_cast<AU_ExtensionInfo*>(extensionInfo);
  int first = e->firstMatched();
  int last = e->lastMatched();
  argArray[first++] = replacement;
  int nrArgs = argArray.length();
  for (last++; last < nrArgs; last++)
    argArray[first++] = argArray[last];
  argArray.contractTo(first);
  repudiateSortInfo();
}

DagNode*
AU_DagNode::partialConstruct(DagNode* replacement, ExtensionInfo* extensionInfo)
{
  AU_ExtensionInfo* e = static_cast<AU_ExtensionInfo*>(extensionInfo);
  int first = e->firstMatched();
  int last = e->lastMatched();
  int nrArgs = argArray.length();
  AU_DagNode* n = new AU_DagNode(symbol(), nrArgs + first - last);
  ArgVec<DagNode*>& args2 = n->argArray;
  for (int i = 0; i < first; i++)
    args2[i] = argArray[i]; 
  args2[first++] = replacement;
  for (last++; last < nrArgs; last++)
    args2[first++] = argArray[last]; 
  return n;
}

ExtensionInfo*
AU_DagNode::makeExtensionInfo()
{
  return new AU_ExtensionInfo(this);
}

bool
AU_DagNode::matchVariableWithExtension(int index,
				      const Sort* sort,
				      Substitution& /* solution */,
				      Subproblem*& returnedSubproblem,
				      ExtensionInfo* extensionInfo)
{
  //
  //    This code could be much more sophisticated: in particular we could look for
  //    the variable having too smaller sort and return false; the subject having
  //    total subterm multiplicity of 2 and return unique solution.
  //
  AU_ExtensionInfo* e = static_cast<AU_ExtensionInfo*>(extensionInfo);
  AU_Subproblem* subproblem = new AU_Subproblem(this, 0, argArray.length() - 1, 1, e);
  int min = symbol()->oneSidedId() ? 1 : 2;
  subproblem->addTopVariable(0, index, min, UNBOUNDED, const_cast<Sort*>(sort));  // HACK
  subproblem->complete();
  returnedSubproblem = subproblem;
  extensionInfo->setValidAfterMatch(false);
  return true;
}
