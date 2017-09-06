//
//      Implementation for class ACU_Symbol.
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
#include "variable.hh"
#include "ACU_Theory.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_Term.hh"
#include "ACU_ExtensionInfo.hh"

ACU_Symbol::ACU_Symbol(int id, const Vector<int>& strategy, bool memoFlag, Term* identity)
  : AssociativeSymbol(id, strategy, memoFlag, identity)
{
}

void 
ACU_Symbol::compileOpDeclarations()
{
  commutativeSortCompletion();
  Symbol::compileOpDeclarations();  // do default sort processing
}

void
ACU_Symbol::postOpDeclarationPass()
{
  processIdentity();
  if(getIdentity() != 0)
    {
      leftIdentitySortCheck();
      rightIdentitySortCheck();
    }
}

DagNode*
ACU_Symbol::ruleRewrite(DagNode* subject, RewritingContext& context)
{
  ACU_ExtensionInfo extensionInfo(static_cast<ACU_DagNode*>(subject));
  return applyRules(subject, context, &extensionInfo);
}

Term*
ACU_Symbol::makeTerm(const Vector<Term*>& args)
{
  return new ACU_Term(this, args);
}

DagNode*
ACU_Symbol::makeDagNode(const Vector<DagNode*>& args)
{
  int nrArgs = args.length();
  ACU_DagNode* a = new ACU_DagNode(this, nrArgs);
  ArgVec<ACU_DagNode::Pair>& args2 = a->argArray;
  for (int i = 0; i < nrArgs; i++)
    {
      ACU_DagNode::Pair& p = args2[i];
      p.dagNode = args[i];
      p.multiplicity = 1;
    }
  return a;
}

DagNode*
ACU_Symbol::makeDagNode(const Vector<DagNode*>& args,
			const Vector<int>& multiplicities)
{
  int nrArgs = args.length();
  Assert(multiplicities.length() == nrArgs, cerr << "length mismatch");
  ACU_DagNode* a = new ACU_DagNode(this, nrArgs);
  ArgVec<ACU_DagNode::Pair>& args2 = a->argArray;
  for (int i = 0; i < nrArgs; i++)
    {
      ACU_DagNode::Pair& p = args2[i];
      p.dagNode = args[i];
      p.multiplicity = multiplicities[i];
    }
  return a;
}

bool
ACU_Symbol::reduceArgumentsAndNormalize(DagNode* subject, RewritingContext& context)
{
  ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
  if (s->getNormalizationStatus() != ACU_DagNode::ASSIGNMENT)
    {
      int nrArgs = s->argArray.length();
      if (s->getNormalizationStatus() == ACU_DagNode::EXTENSION)
	{
	  //
	  //	Only last arg may be unreduced and out of place.
	  //
	  s->argArray[nrArgs - 1].dagNode->reduce(context);
	  (void) s->extensionNormalizeAtTop();
	}
      else
	{
	  for (int i = 0; i < nrArgs; i++)
	    s->argArray[i].dagNode->reduce(context);
	  //
	  //	We always need to renormalize at the top because
	  //	shared subterms may have rewritten.
	  //
	  (void) s->normalizeAtTop();
	}
      Term* identity = getIdentity();
      if (identity != 0 && s->eliminateArgument(identity))
	return false;
    }
  return true;
}

bool
ACU_Symbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), cerr << "bad symbol");
  if (standardStrategy())
    {
      ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
      if (s->getNormalizationStatus() != ACU_DagNode::ASSIGNMENT)
	{
	  int nrArgs = s->argArray.length();
	  if (s->getNormalizationStatus() == ACU_DagNode::EXTENSION)
	    {
	      //
	      //	Only last arg may be unreduced and out of place.
	      //
	      s->argArray[nrArgs - 1].dagNode->reduce(context);
	      (void) s->extensionNormalizeAtTop();
	    }
	  else
	    {
	      for (int i = 0; i < nrArgs; i++)
		s->argArray[i].dagNode->reduce(context);
	      //
	      //	We always need to renormalize at the top because
	      //	shared subterms may have rewritten.
	      //
	      (void) s->normalizeAtTop();
	    }
	  Term* identity = getIdentity();
	  if (identity != 0 && s->eliminateArgument(identity))
	    return false;
	  if (equationFree())
	    return false;
	}
      ACU_ExtensionInfo extensionInfo(s);
      return applyReplace(subject, context, &extensionInfo);
    }
  return complexStrategy(subject, context);
}

bool
ACU_Symbol::complexStrategy(DagNode* subject, RewritingContext& context)
{
  if (isMemoized())
    {
      MemoTable::SourceSet from;
      bool result = memoStrategy(from, subject, context);
      memoEnter(from, subject);
      //
      //	We may need to return true in the case we collapse to a unreduced subterm.
      //
      return result;
    }
  ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
  ArgVec<ACU_DagNode::Pair>& args = s->argArray;  // can't use hack!
  Term* identity = getIdentity();
  if (s->getNormalizationStatus() != ACU_DagNode::ASSIGNMENT)
    {
      int nrArgs = args.length();
      for (int i = 0; i < nrArgs; i++)
	args[i].dagNode->computeTrueSort(context);
      (void) s->normalizeAtTop();
      //
      //	If we collapse to one of our subterms which has not been reduced
      //	we pretend that we did a rewrite so that the reduction process
      //	continues.
      //
      if (identity != 0 && s->eliminateArgument(identity))
	return !(s->isReduced());
    }
  ACU_ExtensionInfo extensionInfo(s);
  if (applyReplace(subject, context, &extensionInfo))
    return true;
  if (getPermuteStrategy() == LAZY)
    return false;
  copyAndReduceSubterms(s, context);
  (void) s->normalizeAtTop();
  if (identity != 0 && s->eliminateArgument(identity))
    return false;
  s->repudiateSortInfo();  // applyReplace() might have left sort behind
  return applyReplace(subject, context, &extensionInfo);
}

bool
ACU_Symbol::memoStrategy(MemoTable::SourceSet& from,
			 DagNode* subject,
			 RewritingContext& context)
{
  ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
  PermuteStrategy strat = getPermuteStrategy();
  if (strat == EAGER)
    {
      if (s->getNormalizationStatus() != ACU_DagNode::ASSIGNMENT)
	{
	  int nrArgs = s->argArray.length();
	  if (s->getNormalizationStatus() == ACU_DagNode::EXTENSION)
	    {
	      //
	      //	Only last arg may be unreduced and out of place.
	      //
	      s->argArray[nrArgs - 1].dagNode->reduce(context);
	      (void) s->extensionNormalizeAtTop();
	    }
	  else
	    {
	      for (int i = 0; i < nrArgs; i++)
		s->argArray[i].dagNode->reduce(context);
	      //
	      //	We always need to renormalize at the top because
	      //	shared subterms may have rewritten.
	      //
	      (void) s->normalizeAtTop();
	    }
	  Term* identity = getIdentity();
	  if (identity != 0 && s->eliminateArgument(identity))
	    return false;
	}
    }
  else
    {
      ArgVec<ACU_DagNode::Pair>& args = s->argArray;  // can't use hack!
      Term* identity = getIdentity();
      if (s->getNormalizationStatus() != ACU_DagNode::ASSIGNMENT)
	{
	  int nrArgs = args.length();
	  for (int i = 0; i < nrArgs; i++)
	    args[i].dagNode->computeTrueSort(context);
	  (void) s->normalizeAtTop();
	  //
	  //	If we collapse to one of our subterms which has not been reduced
	  //	we pretend that we did a rewrite so that the reduction process
	  //	continues.
	  //
	  if (identity != 0 && s->eliminateArgument(identity))
	    return !(s->isReduced());
	}
      if (memoRewrite(from, subject, context))
	return false;
      ACU_ExtensionInfo extensionInfo(s);
      if (applyReplace(subject, context, &extensionInfo))
	{
	  subject->reduce(context);
	  return false;
	}
      if (getPermuteStrategy() == LAZY)
	return false;
      copyAndReduceSubterms(s, context);
      (void) s->normalizeAtTop();
      if (identity != 0 && s->eliminateArgument(identity))
	return false;
      s->repudiateSortInfo();  // applyReplace() might have left sort behind
    }
  if (memoRewrite(from, subject, context))
    return false;
  ACU_ExtensionInfo extensionInfo(s);
  if (applyReplace(subject, context, &extensionInfo))
    subject->reduce(context);
  return false;
}

void
ACU_Symbol::copyAndReduceSubterms(ACU_DagNode* subject, RewritingContext& context)
{
  ArgVec<ACU_DagNode::Pair>& args = subject->argArray;
  int nrArgs = args.length();
  for (int i = 0; i < nrArgs; i++)
    args[i].dagNode = args[i].dagNode->copyAndReduce(context);
}

void
ACU_Symbol::computeBaseSort(DagNode* subject)
{
  Assert(this == subject->symbol(), cerr << "bad symbol");
  ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
  ArgVec<ACU_DagNode::Pair>& args = s->argArray;
  int nrArgs = args.length();
  //
  //	If symbol has a uniform sort structure do a fast sort computation.
  //
  const Sort* uniSort = uniformSort();
  if (uniSort != 0)
    {
      if (s->getNormalizationStatus() != ACU_DagNode::ASSIGNMENT)
	{
	  //
	  //	Check we're not in the error sort.
	  //
	  int lastIndex = Sort::SORT_UNKNOWN;
	  for (int i = 0; i < nrArgs; i++)
	    {
	      int index = args[i].dagNode->getSortIndex();
	      Assert(index != Sort::SORT_UNKNOWN, cerr << "bad sort");
	      if (index != lastIndex)
		{
		  if (!(leq(index, uniSort)))
		    {
		      subject->setSortIndex(Sort::ERROR_SORT);
		      return;
		    }
		  lastIndex = index;
		}
	    }
        }
      subject->setSortIndex(uniSort->index());
      return;
    }
  //
  //	Standard sort calculation.
  //
  int sortIndex = Sort::SORT_UNKNOWN;
  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* d = args[i].dagNode;
      int t = d->getSortIndex();
      Assert(t >= 0, cerr << "bad sort index");
      int m = args[i].multiplicity;
      if (sortIndex == Sort::SORT_UNKNOWN)
	{
	  sortIndex = t;
	  if (--m == 0)
	    continue;
	}
      int state = traverse(0, t);  // commutative optimization for m > 1
      for (int j = 0; j < m; j++)
	sortIndex = traverse(state, sortIndex);
    }
  subject->setSortIndex(sortIndex);
}

void
ACU_Symbol::normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), cerr << "bad symbol");
  ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
  ArgVec<ACU_DagNode::Pair>& args = s->argArray;
  int nrArgs = args.length();
  //
  //	Make sure each subterm has a sort.
  //
  for (int i = 0; i < nrArgs; i++)
    args[i].dagNode->computeTrueSort(context);
  //
  //	Put subject in normal form (could collapse to a subterm).
  //
  (void) s->normalizeAtTop();
  Term* identity = getIdentity();
  if (identity != 0 && s->eliminateArgument(identity))
    return;
  //
  //	Finally compute subjects true sort.
  //
  fastComputeTrueSort(subject, context);
}

void
ACU_Symbol::stackArguments(DagNode* subject,
			   Vector<RedexPosition>& stack,
			   int parentIndex)
{
  //cerr << "stackArguments(" << subject << ",..., " << parentIndex << ")\n";
  if (!(getFrozen().empty()))
    return;
  bool eager = (getPermuteStrategy() == EAGER);
  ArgVec<ACU_DagNode::Pair>& args = safeCast(ACU_DagNode*, subject)->argArray;
  int nrArgs = args.length();
  int argNr = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* d = args[i].dagNode;
      int m = args[i].multiplicity;
      if (d->isUnstackable())
	argNr += m;
      else
	{
	  for (int j = m; j > 0; j--)
	    {
	      stack.append(RedexPosition(d, parentIndex, argNr, eager));
	      ++argNr;
	      //cerr << "stacking " << d << endl;
	    }
	}
    }
}
