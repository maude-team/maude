//
//      Class for condition fragment supporting sort test.
//
#ifndef _sortTestConditionFragment_hh_
#define _sortTestConditionFragment_hh_
#include "conditionFragment.hh"
#include "rhsBuilder.hh"

class SortTestConditionFragment : public ConditionFragment
{
  NO_COPYING(SortTestConditionFragment);

public:
  SortTestConditionFragment(Term* lhs, Sort* sort);
  ~SortTestConditionFragment();

  void check(VariableInfo& varInfo, NatSet& boundVariables);
  void preprocess();
  void compileBuild(VariableInfo& variableInfo, TermBag& availableTerms);
  void compileMatch(VariableInfo& variableInfo, NatSet& boundUniquely);
  bool solve(bool findFirst,
	     RewritingContext& solution,
	     stack<ConditionState*>& state);

  Term* getLhs() const;
  Sort* getSort() const;

private:
  Term* lhs;
  Sort* sort;
  RhsBuilder builder;
  int lhsIndex;
};

inline Term*
SortTestConditionFragment::getLhs() const
{
  return lhs;
}

inline Sort*
SortTestConditionFragment::getSort() const
{
  return sort;
}

#endif
