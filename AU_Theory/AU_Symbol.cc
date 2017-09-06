//
//      Implementation for class AU_Symbol.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "AU_Theory.hh"

//	AU theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"
#include "AU_Term.hh"
#include "AU_ExtensionInfo.hh"

AU_Symbol::AU_Symbol(int id,
		     const Vector<int>& strategy,
		     bool memoFlag,
		     bool leftId,
		     bool rightId,
		     Term* identity)
  : AssociativeSymbol(id, strategy, memoFlag, identity),
    leftIdFlag(leftId),
    rightIdFlag(rightId),
    oneSidedIdFlag(leftId ^ rightId)
{
}

void
AU_Symbol::postOpDeclarationPass()
{
  processIdentity();
  if (leftIdFlag)
    leftIdentitySortCheck();
  if (rightIdFlag)
    rightIdentitySortCheck();
}

DagNode*
AU_Symbol::ruleRewrite(DagNode* subject, RewritingContext& context)
{
  AU_ExtensionInfo extensionInfo(static_cast<AU_DagNode*>(subject));
  return applyRules(subject, context, &extensionInfo);
}

Term*
AU_Symbol::makeTerm(const Vector<Term*>& args)
{
  return new AU_Term(this, args);
}

DagNode* 
AU_Symbol::makeDagNode(const Vector<DagNode*>& args)
{
  int nrArgs = args.length();
  AU_DagNode* a = new AU_DagNode(this, nrArgs);
  ArgVec<DagNode*>& args2 = a->argArray;
  for (int i = 0; i < nrArgs; i++)
    args2[i] = args[i];
  return a;
}

bool
AU_Symbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  AU_DagNode* s = static_cast<AU_DagNode*>(subject);
  ArgVec<DagNode*>& args = s->argArray;
  if (standardStrategy())
    {
      if (!(s->producedByAssignment()))
	{
	  int nrArgs = args.length();
	  for (int i = 0; i < nrArgs; i++)
	    args[i]->reduce(context);
	  //
	  //	We always need to renormalize at the top because
	  //	shared subterms may have rewritten.
	  //
	  if (s->normalizeAtTop() == AU_DagNode::COLLAPSED)
	    return false;
	  if (equationFree())
	    return false;
	}
    }
  else
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
      if (!(s->producedByAssignment()))
	{
	  int nrArgs = args.length();
	  for (int i = 0; i < nrArgs; i++)
	    args[i]->computeTrueSort(context);
	  //
	  //	If we collapse to one of our subterms which has not been reduced
	  //	we pretend that we did a rewrite so that the reduction process
	  //	continues.
	  //
	  if (s->normalizeAtTop() == AU_DagNode::COLLAPSED)
	    return !(s->isReduced());
	}
      AU_ExtensionInfo extensionInfo(s);
      if (applyReplace(subject, context, &extensionInfo))
	return true;
      if (getPermuteStrategy() == LAZY)
	return false;
      copyAndReduceSubterms(s, context);
      if (s->normalizeAtTop() == AU_DagNode::COLLAPSED)
	return false;
      s->repudiateSortInfo();  // applyReplace() might have left sort behind
    }
  AU_ExtensionInfo extensionInfo(s);
  return applyReplace(subject, context, &extensionInfo);
}

bool
AU_Symbol::memoStrategy(MemoTable::SourceSet& from,
			DagNode* subject,
			RewritingContext& context)
{
  AU_DagNode* s = static_cast<AU_DagNode*>(subject);
  ArgVec<DagNode*>& args = s->argArray;
  PermuteStrategy strat = getPermuteStrategy();
  if (strat == EAGER)
    {
      if (!(s->producedByAssignment()))
	{
	  int nrArgs = args.length();
	  for (int i = 0; i < nrArgs; i++)
	    args[i]->reduce(context);
	  //
	  //	We always need to renormalize at the top because
	  //	shared subterms may have rewritten.
	  //
	  if (s->normalizeAtTop() == AU_DagNode::COLLAPSED)
	    return false;
	}
    }
  else
    {
      if (!(s->producedByAssignment()))
	{
	  int nrArgs = args.length();
	  for (int i = 0; i < nrArgs; i++)
	    args[i]->computeTrueSort(context);
	  //
	  //	If we collapse to one of our subterms which has not been reduced
	  //	we pretend that we did a rewrite so that the reduction process
	  //	continues.
	  //
	  if (s->normalizeAtTop() == AU_DagNode::COLLAPSED)
	    return !(s->isReduced());
	}
      if (memoRewrite(from, subject, context))
	return false;
      AU_ExtensionInfo extensionInfo(s);
      if (applyReplace(subject, context, &extensionInfo))
	{
	  subject->reduce(context);
	  return false;
	}
      if (strat == LAZY)
	return false;
      copyAndReduceSubterms(s, context);
      if (s->normalizeAtTop() == AU_DagNode::COLLAPSED)
	return false;
      s->repudiateSortInfo();  // applyReplace() might have left sort behind
    }
  if (memoRewrite(from, subject, context))
    return false;
  AU_ExtensionInfo extensionInfo(s);
  if (applyReplace(subject, context, &extensionInfo))
    subject->reduce(context);
  return false;
}

void
AU_Symbol::copyAndReduceSubterms(AU_DagNode* subject, RewritingContext& context)
{
  ArgVec<DagNode*>& args = subject->argArray;
  int nrArgs = args.length();
  for (int i = 0; i < nrArgs; i++)
    args[i] = args[i]->copyAndReduce(context);
}

void
AU_Symbol::computeBaseSort(DagNode* subject)
{
  Assert(this == subject->symbol(), "bad symbol");
  AU_DagNode* s = static_cast<AU_DagNode*>(subject);
  ArgVec<DagNode*>& args = s->argArray;
  int nrArgs = args.length();
  //
  //	If symbol has a uniform sort structure do a fast sort computation.
  //
  const Sort* uniSort = uniformSort();
  if (uniSort != 0)
    {
      if (!(uniSort->component()->errorFree()))
	{
	  //
	  //	Check we're not in the error sort.
	  //
	  int lastIndex = Sort::SORT_UNKNOWN;
	  for (int i = 0; i < nrArgs; i++)
	    {
	      int index = args[i]->getSortIndex();
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
  //	Consider subterms until we find a union sort.
  //
  int sortIndex = Sort::SORT_UNKNOWN;
  for (int i = 0; i < nrArgs; i++)
    {
      int t = args[i]->getSortIndex();
      Assert(t >= 0, "bad sort index");
      sortIndex = (sortIndex == Sort::SORT_UNKNOWN) ? t : traverse(traverse(0, sortIndex), t);
    }
  subject->setSortIndex(sortIndex);
}

void
AU_Symbol::normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  AU_DagNode* s = static_cast<AU_DagNode*>(subject);
  ArgVec<DagNode*>& args = s->argArray;
  int nrArgs = args.length();
  //
  //	Make sure each subterm has a sort,
  //
  for (int i = 0; i < nrArgs; i++)
    args[i]->computeTrueSort(context);
  //
  //    Put subject in normal form (could collapse to a subterm).
  //
  if (s->normalizeAtTop() == AU_DagNode::COLLAPSED)
    return;
  //
  //	Finally compute subjects true sort.
  //
  fastComputeTrueSort(subject, context);
}

int
AU_Symbol::calculateNrSubjectsMatched(DagNode* d,
				      bool leftEnd,  // match starts at left extreme
				      bool rightEnd,  // match end at right extreme
				      bool& nasty)
{
  nasty = false;
  Term* identity = getIdentity();
  if (d->symbol() == this)
    {
      ArgVec<DagNode*>& args = static_cast<AU_DagNode*>(d)->argArray;
      int nrArgs = args.length();
      if (oneSidedIdFlag)
	{
	  if (rightIdFlag)
	    {
	      if (identity->equal(args[0]))
		{
		  if (leftEnd)
		    nasty = true;
		  else
		    --nrArgs;  // identity may not match anything
		}
	    }
	  else
	    {
	      if (identity->equal(args[nrArgs - 1]))
		{
		  if (rightEnd)
		    nasty = true;
		  else
		    --nrArgs;  // identity may not match anything
		}
	    }
	}
      return nrArgs;
    }
  if (identity != 0 && identity->equal(d))
    {
      if (!(oneSidedIdFlag && (rightIdFlag ? leftEnd : rightEnd)))
	return 0;
      nasty = true;
    }
  return 1;
}

void
AU_Symbol::stackArguments(DagNode* subject,
			  Vector<RedexPosition>& stack,
			  int parentIndex)
{
  if (!(getFrozen().empty()))
    return;
  bool eager = (getPermuteStrategy() == EAGER);
  ArgVec<DagNode*>& args = safeCast(AU_DagNode*, subject)->argArray;
  int nrArgs = args.length();
  for (int i = 0; i < nrArgs; i++)
    {
      DagNode* d = args[i];
      if (!(d->isUnstackable()))
	stack.append(RedexPosition(d, parentIndex, i, eager));
    }
}
