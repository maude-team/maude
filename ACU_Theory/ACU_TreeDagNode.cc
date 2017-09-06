//
//	Implementation for class ACU_TreeDagNode.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_RedBlack.hh"
#include "ACU_Theory.hh"

//	ACU Red-Black class definitions
#include "ACU_RedBlackNode.hh"
#include "ACU_FastIter.hh"

//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_ExtensionInfo.hh"
#include "ACU_TreeDagArgumentIterator.hh"
#include "ACU_TreeDagNode.hh"

RawDagArgumentIterator*
ACU_TreeDagNode::arguments()
{
  return new ACU_TreeDagArgumentIterator(root);
}

size_t
ACU_TreeDagNode::getHashValue()
{
  size_t hashValue = symbol()->getHashValue();
  for (ACU_FastIter i(root); i.valid(); i.next())
    hashValue = hash(hashValue, i.getDagNode()->getHashValue(), i.getMultiplicity());
  return hashValue;  // should cache this
}

int 
ACU_TreeDagNode::compareArguments(const DagNode* other) const
{
  const ACU_BaseDagNode* d = safeCast(const ACU_BaseDagNode*, other);
  if (d->isTree())
    {
      const ACU_TreeDagNode* d2 = safeCast(const ACU_TreeDagNode*, d);
      int r = root->getSize() - d2->root->getSize();
      if (r != 0)
	return r;
      ACU_FastIter i(root);
      ACU_FastIter j(d2->root);
      do
	{
	  r = i.getMultiplicity() - j.getMultiplicity();
	  if (r != 0)
	    return r;
	  r = i.getDagNode()->compare(j.getDagNode());
	  if (r != 0)
	    return r;
	  j.next();
	  i.next();
	}
      while (i.valid());
      return 0;
    }
  return - other->compareArguments(this);
}

void
ACU_TreeDagNode::overwriteWithClone(DagNode* old)
{
  ACU_TreeDagNode* d = new(old) ACU_TreeDagNode(symbol(), root);
  d->setTheoryByte(getTheoryByte());
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
}

DagNode* 
ACU_TreeDagNode::makeClone()
{
  ACU_TreeDagNode* d = new ACU_TreeDagNode(symbol(), root);
  d->setTheoryByte(getTheoryByte());
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
  return d;
}

DagNode*
ACU_TreeDagNode::copyWithReplacement(int argIndex, DagNode* replacement)
{
  return treeToArgVec(this)->copyWithReplacement(argIndex, replacement);  // HACK
}

DagNode*
ACU_TreeDagNode::copyWithReplacement(Vector<RedexPosition>& redexStack,
				     int first,
				     int last)
{
  return treeToArgVec(this)->copyWithReplacement(redexStack, first, last);
}

void
ACU_TreeDagNode::stackArguments(Vector<RedexPosition>& stack,
				int parentIndex,
				bool respectFrozen)
{
  if (respectFrozen && !(symbol()->getFrozen().empty()))
    return;
  int j = 0;
  for (ACU_FastIter i(root); i.valid(); i.next(), ++j)
    {
      DagNode* d = i.getDagNode();
      if (!(d->isUnstackable()))
	stack.append(RedexPosition(d, parentIndex, j));
    }
}

bool
ACU_TreeDagNode::matchVariableWithExtension(int index,
				const Sort* sort,
				Substitution& solution,
				Subproblem*& returnedSubproblem,
				ExtensionInfo* extensionInfo)
{
  return treeToArgVec(this)->matchVariableWithExtension(index,
							sort,
							solution,
							returnedSubproblem,
							extensionInfo);
}

void
ACU_TreeDagNode::partialReplace(DagNode* replacement, ExtensionInfo* extensionInfo)
{
  ArgVec<ACU_DagNode::Pair>& args = (new(this) ACU_DagNode(symbol(), 2))->argArray;
  args[0].dagNode = safeCast(ACU_ExtensionInfo*, extensionInfo)->getUnmatched();
  args[0].multiplicity = 1;
  args[1].dagNode = replacement;
  args[1].multiplicity = 1;
}

DagNode*
ACU_TreeDagNode::partialConstruct(DagNode* replacement, ExtensionInfo* extensionInfo)
{
  ACU_DagNode* n = new ACU_DagNode(symbol(), 2);
  ArgVec<ACU_DagNode::Pair>& args = n->argArray;
  args[0].dagNode = safeCast(ACU_ExtensionInfo*, extensionInfo)->getUnmatched();
  args[0].multiplicity = 1;
  args[1].dagNode = replacement;
  args[1].multiplicity = 1;
  return n;
}

DagNode*
ACU_TreeDagNode::markArguments()
{
  //
  //	Preorder traversal of unmarked nodes in red-black tree.
  //
  ACU_Stack i;
  ACU_RedBlackNode* n = root;
  for(;;)
    {
      while (n != 0 && !(n->isMarked()))
	{
	  n->setMarked();
	  n->getDagNode()->mark();
	  i.push(n);
	  n = n->getLeft();
	}
      if (i.empty())
	break;
      n = i.pop()->getRight();
    }
  return 0;
}

DagNode*
ACU_TreeDagNode::copyEagerUptoReduced2()
{
  return treeToArgVec(this)->copyEagerUptoReduced2();
}

void
ACU_TreeDagNode::clearCopyPointers2()
{
  CantHappen("Should not be copying on ACU_TreeDagNode");
}

int
ACU_TreeDagNode::treeComputeBaseSort()
{
  return recComputeBaseSort(symbol(), root);
}

int
ACU_TreeDagNode::recComputeBaseSort(ACU_Symbol* symbol, ACU_RedBlackNode* root)
{
  // CANDIDATE FOR RECURSION ELIMINATION
  int index = root->getSortIndex();
  if (index != Sort::SORT_UNKNOWN)
    return index;

  index = root->getDagNode()->getSortIndex();
  Assert(index != Sort::SORT_UNKNOWN, "bad sort");
  index = symbol->computeMultSortIndex(index, index, root->getMultiplicity() - 1);

  if (ACU_RedBlackNode* l = root->getLeft())
    index = symbol->computeSortIndex(index, recComputeBaseSort(symbol, l));
  if (ACU_RedBlackNode* r = root->getRight())
    index = symbol->computeSortIndex(index, recComputeBaseSort(symbol, r));

  root->setSortIndex(index);
  return index;
}

ACU_DagNode*
ACU_TreeDagNode::treeToArgVec(ACU_TreeDagNode* original)
{
  //cerr << "in:  " << original << endl;

  ACU_RedBlackNode* t = original->root;
  ACU_Symbol* s = original->symbol();
  //
  //	Now we overwrite original.
  //
  int sortIndex = original->getSortIndex();
  bool redFlag = original->isReduced();
  ACU_DagNode* d = new(original) ACU_DagNode(s, t->getSize());
  ArgVec<ACU_DagNode::Pair>::iterator j = d->argArray.begin();

  for (ACU_FastIter i(t); i.valid(); i.next(), ++j)
    {
      j->dagNode = i.getDagNode();
      j->multiplicity = i.getMultiplicity();
    }

  Assert(j == d->argArray.end(), "iterators inconsistant");
  //cerr << "out: " << d << endl;

  d->setSortIndex(sortIndex);
  if (redFlag)
    d->setReduced();

  return d;
}
