//
//      Class for condition fragment supporting rewrite search.
//
#ifndef _rewriteConditionFragment_hh_
#define _rewriteConditionFragment_hh_
#include "conditionFragment.hh"
#include "rhsBuilder.hh"

class RewriteConditionFragment : public ConditionFragment
{
  NO_COPYING(RewriteConditionFragment);

public:
  RewriteConditionFragment(Term* lhs, Term* rhs);
  ~RewriteConditionFragment();

  void check(VariableInfo& varInfo, NatSet& boundVariables);
  void preprocess();
  void compileBuild(VariableInfo& variableInfo, TermBag& availableTerms);
  void compileMatch(VariableInfo& variableInfo, NatSet& boundUniquely);
  bool solve(bool findFirst,
	     RewritingContext& solution,
	     stack<ConditionState*>& state);

  Term* getLhs() const;
  Term* getRhs() const;

private:
  Term* lhs;
  Term* rhs;
  RhsBuilder builder;
  int lhsIndex;
  LhsAutomaton* rhsMatcher;
};

inline Term*
RewriteConditionFragment::getLhs() const
{
  return lhs;
}

inline Term*
RewriteConditionFragment::getRhs() const
{
  return rhs;
}

#endif
