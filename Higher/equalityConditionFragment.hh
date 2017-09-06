//
//      Class for condition fragment supporting equality test.
//
#ifndef _equalityConditionFragment_hh_
#define _equalityConditionFragment_hh_
#include "conditionFragment.hh"
#include "rhsBuilder.hh"

class EqualityConditionFragment : public ConditionFragment
{
  NO_COPYING(EqualityConditionFragment);

public:
  EqualityConditionFragment(Term* lhs, Term* rhs);
  ~EqualityConditionFragment();

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
  int rhsIndex;
};

inline Term*
EqualityConditionFragment::getLhs() const
{
  return lhs;
}

inline Term*
EqualityConditionFragment::getRhs() const
{
  return rhs;
}

#endif
