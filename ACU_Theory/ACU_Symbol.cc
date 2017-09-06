//
//      Implementation for class ACU_Symbol.
//
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "ACU_Theory.hh"
#include "ACU_RedBlack.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_TreeDagNode.hh"
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
  ACU_ExtensionInfo extensionInfo(getACU_DagNode(subject));
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
  Assert(multiplicities.length() == nrArgs, "length mismatch");
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
  ACU_DagNode* s = getACU_DagNode(subject);
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
	  if (s->normalizeAtTop())
	    return false;
	}
      Term* identity = getIdentity(); // FIX
      if (identity != 0 && s->eliminateArgument(identity))
	return false;
    }
  return true;
}

bool
ACU_Symbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  if (standardStrategy())
    {
      if (safeCast(ACU_BaseDagNode*, subject)->isTree())
	{
	treeCase:
	  if (equationFree())
	    return false;
	  ACU_ExtensionInfo extensionInfo(safeCast(ACU_BaseDagNode*, subject));
	  return applyReplace(subject, context, &extensionInfo);
	}
      else
	{
	  ACU_DagNode* s = safeCast(ACU_DagNode*, subject);
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
		  Term* identity = getIdentity();
		  if (identity != 0 && s->eliminateArgument(identity))
		    return false;
		}
	      else
		{
		  for (int i = 0; i < nrArgs; i++)
		    s->argArray[i].dagNode->reduce(context);
		  //
		  //	We always need to renormalize at the top because
		  //	shared subterms may have rewritten.
		  //
		  if (s->normalizeAtTop())
		    return false;
		}
	      if (safeCast(ACU_BaseDagNode*, subject)->isTree())
		goto treeCase;   // may have been converted
	      if (equationFree())
		return false;
	    }
	  //
	  //	We don't test for equation-freeness here
	  //	because if we were produced by an assignment
	  //	and our symbol is equation-free, our reduced flag
	  //	would be set (since we don't have a complex
	  //	strategy) and we wouldn't be here.
	  //
	  ACU_ExtensionInfo extensionInfo(s);
	  return applyReplace(subject, context, &extensionInfo);
	}
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
      //	We may need to return true in the case we collapse
      //	to a unreduced subterm.
      //
      return result;
    }
  ACU_DagNode* s = getACU_DagNode(subject);
  ArgVec<ACU_DagNode::Pair>& args = s->argArray;  // can't use iterator
  if (s->getNormalizationStatus() != ACU_DagNode::ASSIGNMENT)
    {
      int nrArgs = args.length();
      for (int i = 0; i < nrArgs; i++)
	args[i].dagNode->computeTrueSort(context);
      //
      //	If we collapse to one of our subterms which has not been reduced
      //	we pretend that we did a rewrite so that the reduction process
      //	continues.
      //
      if (s->normalizeAtTop())
	return !(s->isReduced());
    }
  ACU_ExtensionInfo extensionInfo(s);
  if (applyReplace(subject, context, &extensionInfo))
    return true;
  if (getPermuteStrategy() == LAZY)
    return false;
  copyAndReduceSubterms(s, context);
  if (s->normalizeAtTop())
    return false;
  s->repudiateSortInfo();  // applyReplace() might have left sort behind
  return applyReplace(subject, context, &extensionInfo);
}

bool
ACU_Symbol::memoStrategy(MemoTable::SourceSet& from,
			 DagNode* subject,
			 RewritingContext& context)
{
  ACU_DagNode* s = getACU_DagNode(subject);
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
	      if (s->normalizeAtTop())
		return false;
	    }
	  Term* identity = getIdentity();  // FIX
	  if (identity != 0 && s->eliminateArgument(identity))
	    return false;
	}
    }
  else
    {
      ArgVec<ACU_DagNode::Pair>& args = s->argArray;  // can't use hack!
     if (s->getNormalizationStatus() != ACU_DagNode::ASSIGNMENT)
	{
	  int nrArgs = args.length();
	  for (int i = 0; i < nrArgs; i++)
	    args[i].dagNode->computeTrueSort(context);
	  //
	  //	If we collapse to one of our subterms which has not been reduced
	  //	we pretend that we did a rewrite so that the reduction process
	  //	continues.
	  //
	  if (s->normalizeAtTop())
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
      if (s->normalizeAtTop())
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
  Assert(this == subject->symbol(), "bad symbol");

  subject->setSortIndex((safeCast(ACU_BaseDagNode*, subject)->
			 getNormalizationStatus() == ACU_BaseDagNode::TREE) ?
			safeCast(ACU_TreeDagNode*, subject)->treeComputeBaseSort() :
			safeCast(ACU_DagNode*, subject)->argVecComputeBaseSort());
}

void
ACU_Symbol::normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  ACU_DagNode* s = getACU_DagNode(subject);
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
  if (s->normalizeAtTop())
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
  ArgVec<ACU_DagNode::Pair>& args = getACU_DagNode(subject)->argArray;
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
