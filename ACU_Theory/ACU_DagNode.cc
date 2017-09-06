//
//      Implementation for class ACU_DagNode.
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
#include "ACU_Theory.hh"

//      interface class definitions
#include "term.hh"

//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_DagArgumentIterator.hh"
#include "ACU_ExtensionInfo.hh"
#include "ACU_Subproblem.hh"

#include "ACU_DagNormalization.cc"
#include "ACU_DagOperations.cc"

Vector<int> ACU_DagNode::runsBuffer(INITIAL_RUNS_BUFFER_SIZE);

ACU_DagNode::~ACU_DagNode()
{
}

RawDagArgumentIterator*
ACU_DagNode::arguments()
{
  return new ACU_DagArgumentIterator(&argArray);
}

size_t
ACU_DagNode::getHashValue()
{
  size_t hashValue = symbol()->getHashValue();
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    hashValue = hash(hashValue, argArray[i].dagNode->getHashValue(), argArray[i].multiplicity);
  return hashValue;
}

int
ACU_DagNode::compareArguments(const DagNode* other) const
{
  const ArgVec<Pair>& argArray2 = static_cast<const ACU_DagNode*>(other)->argArray;
  Assert(argArray.length() > 0 && argArray2.length() > 0, cerr << "no arguments");
  int i = argArray.length();
  int r = i - argArray2.length();
  if (r != 0)
    return r;
  CONST_ARG_VEC_HACK(Pair, args, argArray);
  CONST_ARG_VEC_HACK(Pair, args2, argArray2);
  do
    {
      --i;
      const Pair& p1 = args[i];
      const Pair& p2 = args2[i];
      r = p1.multiplicity - p2.multiplicity;
      if (r != 0)
	return r;
      r = p1.dagNode->compare(p2.dagNode);
      if (r != 0)
	return r;
    }
  while (i > 0);
  return 0;
}

DagNode*
ACU_DagNode::markArguments()
{
  argArray.evacuate();
  int nrArgs = argArray.length();
  Assert(nrArgs > 0, cerr << "no arguments");
  CONST_ARG_VEC_HACK(Pair, args, argArray);
  --nrArgs;
  int i = 0;
  for (; i < nrArgs; i++)
    args[i].dagNode->mark();
  return args[i].dagNode;
}

DagNode*
ACU_DagNode::copyEagerUptoReduced2()
{
  int nrArgs = argArray.length();
  ACU_Symbol* s = symbol();
  ACU_DagNode* n = new ACU_DagNode(s, nrArgs);
  if (s->getPermuteStrategy() == BinarySymbol::EAGER)
    {
      for (int i = 0; i < nrArgs; i++)
	{
	  n->argArray[i].dagNode = argArray[i].dagNode->copyEagerUptoReduced();
	  n->argArray[i].multiplicity = argArray[i].multiplicity;
	}
    }
  else
    {
      for (int i = 0; i < nrArgs; i++)
	n->argArray[i] = argArray[i];
    }
  return n;
}

void
ACU_DagNode::clearCopyPointers2()
{
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    argArray[i].dagNode->clearCopyPointers();
}

void
ACU_DagNode::overwriteWithClone(DagNode* old)
{
  int nrArgs = argArray.length();
  ACU_DagNode* d = new(old) ACU_DagNode(symbol(), nrArgs);
  d->setTheoryByte(getTheoryByte());
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
  for (int i = 0; i < nrArgs; i++)
    d->argArray[i] = argArray[i];
}

DagNode*
ACU_DagNode::makeClone()
{
  int nrArgs = argArray.length();
  ACU_DagNode* d = new ACU_DagNode(symbol(), nrArgs);
  d->setTheoryByte(getTheoryByte());
  if (isReduced())
    d->setReduced();
  d->setSortIndex(getSortIndex());
  for (int i = 0; i < nrArgs; i++)
    d->argArray[i] = argArray[i];
  return d;
}

DagNode*
ACU_DagNode::copyWithReplacement(int argIndex, DagNode* replacement)
{
  int nrArgs = argArray.length();
  ACU_Symbol* s = symbol();
  ACU_DagNode* n = new ACU_DagNode(s, nrArgs);
  ArgVec<ACU_DagNode::Pair>& args2 = n->argArray;
  int p = 0;

  for (int i = 0; i < nrArgs; i++)
    {
      if (i != argIndex)
	args2[p++] = argArray[i];
      else
	{
	  int m = argArray[i].multiplicity - 1;
	  if (m > 0)
	    {
	      args2[p].dagNode = argArray[i].dagNode;
	      args2[p].multiplicity = m;
	      ++p;
	    }
	}
    }
  Assert(p >= 1, cerr << "no arguments left");
  args2.contractTo(p);
  args2.expandBy(1);
  args2[p].dagNode = replacement;
  args2[p].multiplicity = 1;
  return n;
}

DagNode*
ACU_DagNode::copyWithReplacement(Vector<RedexPosition>& redexStack,
				 int first,
				 int last)
{
  //
  //	We need to build a copy of our dag node, replacing those
  //	arguments that were stacked with those on the stack between
  //	first and last. Unfortunately, unstackable flags are not
  //	a reliable guide to which arguments were stacked since they
  //	may have become true since the arguments were stacked.
  //
  int nrArgs = argArray.length();
  //
  //	The first task is to calculate the number of physical arguments
  //	in the new dag node.
  //
  int nrNewArgs = 0;
  {
    int j = first;
    int argNr = 0;  // notional argument number
    int nextReplacementIndex = redexStack[j].argIndex();
    for (int i = 0; i < nrArgs; i++)
      {
	int m = argArray[i].multiplicity;
	//
	//	We figure out if this block of m identical arguments was
	//	stacked by checking if our notional arg number matches
	//	the next stacked arg number.
	//
	if (argNr == nextReplacementIndex)
	  {
	    nrNewArgs += m;  // stacked so each will need a slot in new arg array
	    j += m;
	    if (j <= last)
	      nextReplacementIndex = redexStack[j].argIndex();
	    else
	      {
		//
		//	No more stacked arguments; each remaining physical
		//	argument will use one slot in new arg array.
		//
		nrNewArgs += nrArgs - (i + 1);
		break;
	      }
	  }
	else
	  ++nrNewArgs;  // not stacked so they will use a single slot in new arg array
	argNr += m;
      }
  }
  //
  //	Now make the new node.
  //
  ACU_DagNode* n = new ACU_DagNode(symbol(), nrNewArgs);
  {
    ArgVec<ACU_DagNode::Pair>& args = n->argArray;
    int j = first;
    int k = 0;  // new physical arg number
    int argNr = 0;  // notional argument number
    int nextReplacementIndex = redexStack[j].argIndex();
    for (int i = 0; i < nrArgs; i++)
      {
	int m = argArray[i].multiplicity;
	if (argNr == nextReplacementIndex)
	  {
	    for (int n = 0; n < m ; n++)
	      {
		args[k].dagNode = redexStack[j].node();
		args[k].multiplicity = 1;
		++j;
		++k;
	      }
	    nextReplacementIndex = (j <= last) ?
	      redexStack[j].argIndex() : NONE;
	  }
	else
	  {
	    args[k].dagNode = argArray[i].dagNode;
	    args[k].multiplicity = m;
	    ++k;
	  }
	argNr += m;
      }
  }
  return n;
}

void
ACU_DagNode::stackArguments(Vector<RedexPosition>& stack,
			    int parentIndex,
			    bool respectFrozen)
{
  if (respectFrozen && !(symbol()->getFrozen().empty()))
    return;
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* d = argArray[i].dagNode;
      if (!(d->isUnstackable()))
	stack.append(RedexPosition(d, parentIndex, i));
    }
}

void
ACU_DagNode::partialReplace(DagNode* replacement, ExtensionInfo* extensionInfo)
{
  ACU_ExtensionInfo* e = static_cast<ACU_ExtensionInfo*>(extensionInfo);
  int nrArgs = argArray.length();
  Assert(nrArgs > 0, cerr << "no arguments");
  ARG_VEC_HACK(Pair, args, argArray);

  int p = 0;
  int i = 0;
  do
    {
      int m = e->getUnmatched(i);
      if (m > 0)
	{
	  args[p].dagNode = args[i].dagNode;
	  args[p].multiplicity = m;
	  ++p;
	}
    }
  while (++i < nrArgs);
  Assert(p >= 1, cerr << "no arguments left");
  argArray.contractTo(p);
  argArray.expandBy(1);
  argArray[p].dagNode = replacement;
  argArray[p].multiplicity = 1;
  repudiateSortInfo();
  setNormalizationStatus(EXTENSION);
}

DagNode*
ACU_DagNode::partialConstruct(DagNode* replacement, ExtensionInfo* extensionInfo)
{
  ACU_ExtensionInfo* e = static_cast<ACU_ExtensionInfo*>(extensionInfo);
  int nrArgs = argArray.length();
  ACU_Symbol* s = symbol();
  ACU_DagNode* n = new ACU_DagNode(s, nrArgs + 1);
  ArgVec<ACU_DagNode::Pair>& args2 = n->argArray;

  int p = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      int m = e->getUnmatched(i);
      if (m > 0)
	{
	  args2[p].dagNode = argArray[i].dagNode;
	  args2[p].multiplicity = m;
	  ++p;
	}
    }
  Assert(p >= 1, cerr << "no arguments left");
  args2.contractTo(p);
  args2.expandBy(1);
  args2[p].dagNode = replacement;
  args2[p].multiplicity = 1;
  return n;
}

ExtensionInfo*
ACU_DagNode::makeExtensionInfo()
{
  return new ACU_ExtensionInfo(this);
}

bool
ACU_DagNode::matchVariableWithExtension(int index,
					const Sort* sort,
					Substitution& /* solution */,
					Subproblem*& returnedSubproblem,
					ExtensionInfo* extensionInfo)
{
  //
  //	This code could be much more sophisticated: in particular we look for
  //	the variable having too smaller sort and return false; the subject having
  //	total subterm multiplicity of 2 and return unique solution.
  //
  //	There is also the possibility that our variable could be bound; in this case
  //	we could avoid generating and solving the subproblem. But this case is so
  //	rare because the extension means we matching at the top, the binding would
  //	have had to be made by some external agency (e.g. a meta level). 
  //	The extra code needed to do the optimal thing with extension is not
  //	worth the performance gain.
  //
  //	May use runsBuffer
  //
  ACU_ExtensionInfo* e = static_cast<ACU_ExtensionInfo*>(extensionInfo);
  int totalSubjectMultiplicity = 0;
  int nrArgs = argArray.length();
  Vector<int> currentMultiplicity(nrArgs);
  for (int i = 0; i < nrArgs; i++)
    {
      int m = argArray[i].multiplicity;
      currentMultiplicity[i] = m;
      totalSubjectMultiplicity += m;
    }
  e->setUpperBound(totalSubjectMultiplicity - 2);

  ACU_Subproblem* subproblem = new ACU_Subproblem(this, currentMultiplicity, e);
  subproblem->addTopVariable(index, 1, 2, UNBOUNDED, sort);
  returnedSubproblem = subproblem;
  extensionInfo->setValidAfterMatch(false);
  return true;
}
