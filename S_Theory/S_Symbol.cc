//
//      Implementation for class S_Symbol
//
#ifdef __GNUG__
#pragma implementation
#endif
#include <map>

//	utility stuff
#include "macros.hh"
#include "vector.hh"
 
//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "S_Theory.hh"

//	successor theory class definitions
#include "S_Symbol.hh"
#include "S_DagNode.hh"
#include "S_Term.hh"
#include "S_ExtensionInfo.hh"

S_Symbol::S_Symbol(int id, const Vector<int>& strategy, bool memoFlag)
  : Symbol(id, 1, memoFlag)
{
  setStrategy(strategy, 1, memoFlag);
}

void 
S_Symbol::compileOpDeclarations()
{
  Symbol::compileOpDeclarations();  // do default sort processing
  const ConnectedComponent* kind = rangeComponent();
  int nrSorts =  kind->nrSorts();
  sortPathTable.resize(nrSorts);
  for (int i = 0; i < nrSorts; i++)
    computePath(i, sortPathTable[i]);
}

void 
S_Symbol::computePath(int sortIndex, SortPath& path)
{
  map<int, int> seen;
  Vector<int> indices;
  for (;;)
    {
      sortIndex = traverse(0, sortIndex);
      if (seen.find(sortIndex) != seen.end())
	{
	  path.leadLength = seen[sortIndex];
	  break;
	}
      seen[sortIndex] = indices.length();
      indices.append(sortIndex);
    }
  path.sortIndices = indices;
}

DagNode*
S_Symbol::ruleRewrite(DagNode* subject, RewritingContext& context)
{
  S_ExtensionInfo extensionInfo(safeCast(S_DagNode*, subject));
  return applyRules(subject, context, &extensionInfo);
}

Term*
S_Symbol::makeTerm(const Vector<Term*>& args)
{
  Assert(args.length() == 1, cerr << "bad number of arguments");
  Assert(args[0] != 0, cerr << "null argument");
  return new S_Term(this, 1, args[0]);
}

DagNode*
S_Symbol::makeDagNode(const Vector<DagNode*>& args)
{
  Assert(args.length() == 1, cerr << "bad number of arguments");
  Assert(args[0] != 0, cerr << "null argument");
  return new S_DagNode(this, 1, args[0]);
}

bool
S_Symbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), cerr << "bad symbol");
  S_DagNode* s = safeCast(S_DagNode*, subject);
  if (standardStrategy())
    {
      //
      //	Fast eager strategy case.
      //
      s->arg->reduce(context);
      s->normalizeAtTop();  // always needed because shared node may have rewritten
      if (equationFree())
	return false;
      S_ExtensionInfo extensionInfo(s);
      return applyReplace(subject, context, &extensionInfo);
    }
  if (isMemoized())
    {
      //
      //	Memoized case - get the reduced form and enter
      //	it in the memoization table.
      //
      MemoTable::SourceSet from;
      memoStrategy(from, subject, context);
      memoEnter(from, subject);
      return false;
    }
  //
  //	Complex strategy case.
  //
  S_ExtensionInfo extensionInfo(s);
  const Vector<int>& userStrategy = getStrategy();
  int stratLen = userStrategy.length();
  bool seenZero = false;

  for (int i = 0; i < stratLen; i++)
    {
      if(userStrategy[i] == 0)
	{
	  if (!seenZero)
	    {
	      s->arg->computeTrueSort(context);
	      seenZero = true;
	    }
	  s->normalizeAtTop();
	  if (applyReplace(subject, context, &extensionInfo))
	      return true;
	}
      else
	{
	  if (seenZero)
	    {
	      s->arg->copyReducible();
	      //
	      //	A previous call to applyReplace() may have
	      //	computed a true sort for our subject which will be
	      //	invalidated by the reduce we are about to do.
	      //
	      subject->repudiateSortInfo();
	    }
	  s->arg->reduce(context);
	}
    }
  return false;
}

void
S_Symbol::memoStrategy(MemoTable::SourceSet& from,
		       DagNode* subject,
		       RewritingContext& context)
{
  S_DagNode* s = safeCast(S_DagNode*, subject);
  //
  //	Execute user supplied strategy.
  //
  const Vector<int>& userStrategy = getStrategy();
  int stratLen = userStrategy.length();
  bool seenZero = false;
  for (int i = 0; i < stratLen; i++)
    {
      if(userStrategy[i] == 0)
	{
	  if (!seenZero)
	    {
	      s->arg->computeTrueSort(context);
	      seenZero = true;
	    }
	  s->normalizeAtTop();
	  if (memoRewrite(from, subject, context))
	    return;
	  S_ExtensionInfo extensionInfo(s);
	  if (applyReplace(subject, context, &extensionInfo))
	    {
	      subject->reduce(context);
	      return;
	    }
	}
      else
	{
	  if (seenZero)
	    {
	      s->arg->copyReducible();
	      //
	      //	A previous call to applyReplace() may have
	      //	computed a true sort for our subject which will be
	      //	invalidated by the reduce we are about to do.
	      //
	      subject->repudiateSortInfo();
	    }
	  s->arg->reduce(context);
	}
    }
}

void
S_Symbol::computeBaseSort(DagNode* subject)
{
  Assert(this == subject->symbol(), cerr << "bad symbol");
  S_DagNode* s = safeCast(S_DagNode*, subject);
  const SortPath& path = sortPathTable[s->arg->getSortIndex()];
  const mpz_class& number = *(s->number);
  int pathLength = path.sortIndices.length();
  if (number <= pathLength)
    {
      //
      //	No cycle case.
      //
      s->setSortIndex(path.sortIndices[number.get_si() - 1]);
    }
  else
    {
      //
      //	Cycle case.
      //
      int cycleLength = pathLength - path.leadLength;
      mpz_class cycleSteps = number - (path.leadLength + 1);
      int remainder = mpz_tdiv_ui(cycleSteps.get_mpz_t(), cycleLength);
      s->setSortIndex(path.sortIndices[path.leadLength + remainder]);
    }
  return;
}

void
S_Symbol::normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), cerr << "bad symbol");
  S_DagNode* s = safeCast(S_DagNode*, subject);
  s->arg->computeTrueSort(context);
  s->normalizeAtTop();
  fastComputeTrueSort(subject, context);
}

void
S_Symbol::stackArguments(DagNode* subject,
			 Vector<RedexPosition>& stack,
			 int parentIndex)
{
  DagNode* arg = safeCast(S_DagNode*, subject)->arg;
  if (!(getFrozen().contains(0)) && !(arg->isUnstackable()))
    stack.append(RedexPosition(arg, parentIndex, 0, eagerArgument(0)));
}

bool
S_Symbol::mightCollapseToOurSymbol(const Term* subterm) const
{
  const PointerSet& cs = subterm->collapseSymbols();
  int nrSymbols = cs.cardinality();
  for (int i = 0; i < nrSymbols; i++)
    {
      Symbol* s = static_cast<Symbol*>(cs.index2Pointer(i));
      if (static_cast<const Symbol*>(s) == this)
        return true;
      VariableSymbol* vs = dynamic_cast<VariableSymbol*>(s);
      if (vs != 0)  // might want to check that vs has big enough sort
        return true;
    }
  return false;
}
