//
//      Class for bag of pointers to terms occurring in patterns or right
//	hand sides that can be reused in building right hand sides to enable
//	common subexpression sharing both within rhs and lhs->rhs.
//
#ifndef _termBag_hh_
#define _termBag_hh_
#include <set>

class TermBag
{
public:
  void insertMatchedTerm(Term* term, bool eagerContext);
  void insertBuiltTerm(Term* term, bool eagerContext);
  Term* findTerm(Term* term, bool eagerContext);

private:
  struct LtTerm
  {
    bool
    operator()(Term* const& t1, Term* const& t2) const
    {
      return t1->compare(t2) < 0;
    }
  };

  typedef set<Term*, LtTerm> TermSet;

  TermSet termsUsableInEagerContext;
  TermSet termsUsableInLazyContext;
};

#endif
