//
//      Implementation for class BranchSymbol.
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
#include "freeTheory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"
 
//      core class definitions
#include "argumentIterator.hh"
#include "rewritingContext.hh"
 
//      free theory class definitions
#include "freeDagNode.hh"
 
//      built in class definitions
#include "branchSymbol.hh"

BranchSymbol::BranchSymbol(int id, Vector<Term*>& testValues)
  : FreeSymbol(id, testValues.length() + 1)
{
  testTerms = testValues;  // deep copy
}

BranchSymbol::~BranchSymbol()
{
  //  int nrTestTerms = testTerms.length();
  //for (int i = 0; i < nrTestTerms; i++)
  //  testTerms[i]->deepSelfDestruct();
}

void
BranchSymbol::fillInSortInfo(Term* subject)
{
  ArgumentIterator a(*subject);
  Assert(a.valid(), cerr << "invalid first subterm");
  Term* t = a.argument();
  t->symbol()->fillInSortInfo(t);
  Assert(t->getComponent() == domainComponent(0), cerr << "bad 1st component");

  a.next();
  Assert(a.valid(), cerr << "invalid second subterm");
  Term* t2 = a.argument();
  t2->symbol()->fillInSortInfo(t2);
  ConnectedComponent* component = t2->getComponent();
  Assert(component == domainComponent(1), cerr << "bad 2nd component");
  
  NatSet leqSorts(component->getLeqSorts(t2->getSortIndex()));
  for (a.next(); a.valid(); a.next())
    {
      t2 = a.argument();
      t2->symbol()->fillInSortInfo(t2);
      Assert(t2->getComponent() == component, cerr << "bad component");
      leqSorts.insert(component->getLeqSorts(t2->getSortIndex()));
    }
  subject->setSortInfo(component,
		       t->leq(getOpDeclarations()[0].getDomainAndRange()[0]) ?
		       component->findIndex(leqSorts) : Sort::ERROR_SORT);
}

bool
BranchSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), cerr << "Bad symbol");
  FreeDagNode* f = static_cast<FreeDagNode*>(subject);
  DagNode *e = f->getArgument(0);
  e->reduce(context);

  int nrTerms = testTerms.length();
  for (int i = 0; i < nrTerms; i++)
    {
      if(testTerms[i]->equal(e))
	return context.builtInReplace(subject, f->getArgument(i + 1));
    }
  //
  //	First argument failed to match any of our test terms. We now need to reduce
  //	all other arguments.
  //
  for (int i = 1; i <= nrTerms; i++)
    f->getArgument(i)->reduce(context);
  return FreeSymbol::eqRewrite(subject, context);
}

void 
BranchSymbol::computeBaseSort(DagNode* subject)
{
  Assert(this == subject->symbol(), cerr << "Bad symbol");
  FreeDagNode* f = static_cast<FreeDagNode*>(subject);
  
  if (f->getArgument(0)->leq(getOpDeclarations()[0].getDomainAndRange()[0]))
    {
      ConnectedComponent* range = rangeComponent();  // should be const
      NatSet unionSoFar(range->getLeqSorts(f->getArgument(1)->getSortIndex()));
      int nrArgs = arity();
      for (int i = 2; i < nrArgs; i++)
	unionSoFar.insert(range->getLeqSorts(f->getArgument(i)->getSortIndex()));
      subject->setSortIndex(range->findIndex(unionSoFar));
    }
  else
    subject->setSortIndex(Sort::ERROR_SORT);
}

void
BranchSymbol::compileOpDeclarations()
{
}

void
BranchSymbol::stackArguments(DagNode* subject,
			     Vector<RedexPosition>& stack,
			     int parentIndex)
{
  const NatSet& frozen = getFrozen();
  FreeDagNode* f = safeCast(FreeDagNode*, subject);
  DagNode* d = f->getArgument(0);
  if (!(frozen.contains(0)) && !(d->isUnstackable()))
    stack.append(RedexPosition(d, parentIndex, 0, true));
  int nrTerms = testTerms.length();
  for (int i = 1; i <= nrTerms; i++)
    {
      d = f->getArgument(i);
      if (!(frozen.contains(i)) && !(d->isUnstackable()))
      stack.append(RedexPosition(d, parentIndex, i, false));
    }
}
