//
//      Implementation for class TermBag
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "term.hh"

//	core class definitions
#include "termBag.hh"

void
TermBag::insertMatchedTerm(Term* term, bool eagerContext)
{
  //
  //	New matched terms can never replace built terms (which are available at
  //	zero cost) nor existing matched terms (for which the cost of storing
  //	the extra pointer may already have been paid).
  //
  termsUsableInLazyContext.insert(term);
  if (eagerContext)
    termsUsableInEagerContext.insert(term);
}

void
TermBag::insertBuiltTerm(Term* term, bool eagerContext)
{
  //
  //	New built terms should not arise if there is an existing
  //	usable term in the appropriate context.
  //
  if (eagerContext)
    {
      pair<TermSet::iterator, bool> p = termsUsableInEagerContext.insert(term);
      Assert(p.second, cerr << "re-insertion of " << term);
    }
  else
    {
      pair<TermSet::iterator, bool> p = termsUsableInLazyContext.insert(term);
      Assert(p.second, cerr << "re-insertion of " << term);
    }
}

Term*
TermBag::findTerm(Term* term, bool eagerContext)
{
  if (eagerContext)
    {
      TermSet::iterator i = termsUsableInEagerContext.find(term);
      if (i != termsUsableInEagerContext.end())
	return *i;
    }
  else
    {
      TermSet::iterator i = termsUsableInLazyContext.find(term);
      if (i != termsUsableInLazyContext.end())
	return *i;
    }
  return 0;
}
