//
//      Implementation for class CUI_Symbol.
//
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "CUI_Theory.hh"
 
//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "lhsAutomaton.hh"
#include "rhsAutomaton.hh"
#include "subproblem.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "variableInfo.hh"
 
//	CUI theory class definitions
#include "CUI_Symbol.hh"
#include "CUI_DagNode.hh"
#include "CUI_Term.hh"

CUI_Symbol::CUI_Symbol(int id,
		       const Vector<int>& strategy,
		       bool memoFlag,
		       Axioms axioms,
		       Term* identity)
  : BinarySymbol(id, memoFlag, identity),
    axioms(axioms)
{
  if (axioms & COMM)
    setPermuteStrategy(strategy);
  else
    setStrategy(strategy, 2, memoFlag);
}

void 
CUI_Symbol::compileOpDeclarations()
{
  if (axioms & COMM)
    commutativeSortCompletion();
  Symbol::compileOpDeclarations();  // do default sort processing
  if (axioms & IDEM)
    idempotentSortCheck();
}

void 
CUI_Symbol::postOpDeclarationPass()
{
  processIdentity();
  if (axioms & LEFT_ID)
    leftIdentitySortCheck();
  if (axioms & RIGHT_ID)
    rightIdentitySortCheck();
}

Term*
CUI_Symbol::makeTerm(const Vector<Term*>& args)
{
  return new CUI_Term(this, args);
}

DagNode*
CUI_Symbol::makeDagNode(const Vector<DagNode*>& args)
{
  CUI_DagNode* c = new CUI_DagNode(this);
  c->argArray[0] = args[0];
  c->argArray[1] = args[1];
  return c;
}

bool
CUI_Symbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  CUI_DagNode* s = static_cast<CUI_DagNode*>(subject);
  DagNode** args = s->argArray;
  if (standardStrategy())
    {
      args[0]->reduce(context);
      args[1]->reduce(context);
      if (s->normalizeAtTop())
	return false;
      return !(equationFree()) && applyReplace(s, context);
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
      //
      //	Execute user supplied strategy.
      //
      const Vector<int>& userStrategy = getStrategy();
      int stratLen = userStrategy.length();
      bool seenZero = false;
      for (int i = 0; i < stratLen; i++)
        {
          int a = userStrategy[i];
          if(a == 0)
            {
              if (!seenZero)
                {
		  args[0]->computeTrueSort(context);
		  args[1]->computeTrueSort(context);
		  seenZero = true;
		}
	      //
	      //	If we collapse to one of our subterms which has not been
	      //	reduced we pretend that we did a rewrite so that the
	      //	reduction process continues.
	      //
	      if (s->normalizeAtTop())
		return !(s->isReduced());
              if (applyReplace(s, context))
                return true;
            }
          else
            {
              --a;  // real arguments start at 0 not 1
              if (seenZero)
                {
                  args[a] = args[a]->copyReducible();
                  //
                  //    A previous call to applyReplace() may have
                  //    computed a true sort for our subject which will be
                  //    invalidated by the reduce we are about to do.
                  //
                  s->repudiateSortInfo();
                }
              args[a]->reduce(context);
            }
        }
      return false;
    }
}

bool
CUI_Symbol::memoStrategy(MemoTable::SourceSet& from,
			 DagNode* subject,
			 RewritingContext& context)
{
  CUI_DagNode* s = static_cast<CUI_DagNode*>(subject);
  DagNode** args = s->argArray;
  //
  //	Execute user supplied strategy.
  //
  const Vector<int>& userStrategy = getStrategy();
  int stratLen = userStrategy.length();
  bool seenZero = false;
  for (int i = 0; i < stratLen; i++)
    {
      int a = userStrategy[i];
      if(a == 0)
	{
	  if (!seenZero)
	    {
	      args[0]->computeTrueSort(context);
	      args[1]->computeTrueSort(context);
	      seenZero = true;
	    }
	  //
	  //	If we collapse to one of our subterms which has not been
	  //	reduced we pretend that we did a rewrite so that the
	  //	reduction process continues.
	  //
	  if (s->normalizeAtTop())
	    return !(s->isReduced());
	  if (memoRewrite(from, subject, context))
	    return false;
	  if (applyReplace(s, context))
	    {
	      subject->reduce(context);
	      return false;
	    }
	}
      else
	{
	  --a;  // real arguments start at 0 not 1
	  if (seenZero)
	    {
	      args[a] = args[a]->copyReducible();
	      //
	      //    A previous call to applyReplace() may have
	      //    computed a true sort for our subject which will be
	      //    invalidated by the reduce we are about to do.
	      //
	      s->repudiateSortInfo();
	    }
	  args[a]->reduce(context);
	}
    }
  return false;
}

void
CUI_Symbol::computeBaseSort(DagNode* subject)
{
  Assert(this == subject->symbol(), "bad symbol");
  DagNode** args = static_cast<CUI_DagNode*>(subject)->argArray;
  int i0 = args[0]->getSortIndex();
  int i1 = args[1]->getSortIndex();
  Assert(i0 >= 0 && i1 >= 0, "bad sort index");
  subject->setSortIndex(traverse(traverse(0, i0), i1));
}

void
CUI_Symbol::normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  CUI_DagNode* s = static_cast<CUI_DagNode*>(subject);
  DagNode** args = s->argArray;
  //
  //	Make sure each subterm has a sort.
  //
  args[0]->computeTrueSort(context);
  args[1]->computeTrueSort(context);
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
CUI_Symbol::stackArguments(DagNode* subject,
			   Vector<RedexPosition>& stack,
			   int parentIndex)
{
  DagNode** args = safeCast(CUI_DagNode*, subject)->argArray;
  const NatSet& frozen = getFrozen();

  DagNode* d = args[0];
  if (!(frozen.contains(0)) && !(d->isUnstackable()))
    stack.append(RedexPosition(args[0], parentIndex, 0, eagerArgument(0)));

  d = args[1];
  if (!(frozen.contains(1)) && !(d->isUnstackable()))
    stack.append(RedexPosition(args[1], parentIndex, 1, eagerArgument(1)));
}

void
CUI_Symbol::setFrozen(const NatSet& frozen)
{
  if (axioms & COMM)
    setPermuteFrozen(frozen);
  else
    BinarySymbol::setFrozen(frozen);
}
