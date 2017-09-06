//
//      Implementation for class S_DagNode.
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
#include "S_Theory.hh"
 
//      interface class definitions
#include "term.hh"

//      S theory class definitions
#include "S_Symbol.hh"
#include "S_DagNode.hh"
#include "S_DagArgumentIterator.hh"
#include "S_ExtensionInfo.hh"

S_DagNode::S_DagNode(S_Symbol* symbol, const mpz_class& number, DagNode* arg)
  : DagNode(symbol),
    number(new mpz_class(number)),
    arg(arg)
{
  setCallDtor();  // need our dtor called when garbage collected to destruct number
}

S_DagNode::~S_DagNode()
{
  delete number;
}

RawDagArgumentIterator*
S_DagNode::arguments()
{
  return new S_DagArgumentIterator(arg);
}

size_t
S_DagNode::getHashValue()
{
  return hash(symbol()->getHashValue(),
	      arg->getHashValue(),
	      mpz_tdiv_ui(number->get_mpz_t(), INT_MAX));
}

int
S_DagNode::compareArguments(const DagNode* other) const
{
  const S_DagNode* d = safeCast(const S_DagNode*, other);
  int r = cmp(*number, *(d->number));
  return (r == 0) ? arg->compare(d->arg) : r;
}

DagNode*
S_DagNode::markArguments()
{
  return arg;
}

DagNode*
S_DagNode::copyEagerUptoReduced2()
{
  S_Symbol* s = symbol();
  DagNode* argCopy = (s->standardStrategy()) ? arg->copyEagerUptoReduced() : arg;
  return new S_DagNode(s, *number, argCopy);
}

void
S_DagNode::clearCopyPointers2()
{
  arg->clearCopyPointers();
}

void
S_DagNode::overwriteWithClone(DagNode* old)
{
  S_DagNode* d = new(old) S_DagNode(symbol(), *number, arg);
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
}

DagNode*
S_DagNode::makeClone()
{
  S_DagNode* d = new S_DagNode(symbol(), *number, arg);
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
  return d;
}

void
S_DagNode::normalizeAtTop()
{
  if (arg->symbol() == symbol())
    {
      S_DagNode* a = safeCast(S_DagNode*, arg);
      *number += *(a->number);
      arg = a->arg;
    }
}

DagNode*
S_DagNode::copyWithReplacement(int argIndex, DagNode* replacement)
{
  Assert(argIndex == 0, cerr << "bad arg index");
  return new S_DagNode(symbol(), *number, replacement);
}

DagNode*
S_DagNode::copyWithReplacement(Vector<RedexPosition>& redexStack,
			       int first,
			       int last)
{
  Assert(first == last, cerr << "nrArgs clash");
  return new S_DagNode(symbol(), *number, redexStack[first].node());
}

void
S_DagNode::stackArguments(Vector<RedexPosition>& stack,
			  int parentIndex,
			  bool respectFrozen)
{
  if (!(respectFrozen && symbol()->getFrozen().contains(0)) &&
      !(arg->isUnstackable()))
    stack.append(RedexPosition(arg, parentIndex, 0));
}

void
S_DagNode::partialReplace(DagNode* replacement, ExtensionInfo* extensionInfo)
{
  *number = safeCast(S_ExtensionInfo*, extensionInfo)->getUnmatched();
  arg = replacement;
  repudiateSortInfo();
}

DagNode*
S_DagNode::partialConstruct(DagNode* replacement, ExtensionInfo* extensionInfo)
{
  return new S_DagNode(symbol(),
		       safeCast(S_ExtensionInfo*, extensionInfo)->getUnmatched(),
		       replacement);
}

ExtensionInfo*
S_DagNode::makeExtensionInfo()
{
  return new S_ExtensionInfo(this);
}


bool
S_DagNode::matchVariableWithExtension(int index,
				      const Sort* sort,
				      Substitution&  solution ,
				      Subproblem*& returnedSubproblem,
				      ExtensionInfo* extensionInfo)
{
  Assert(false, cerr << "not supported");
  return false;
}
