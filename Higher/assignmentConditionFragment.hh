//
//      Class for condition fragment supporting assignment via pattern matching.
//
#ifndef _assignmentConditionFragment_hh_
#define _assignmentConditionFragment_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "conditionFragment.hh"
#include "rhsBuilder.hh"

class AssignmentConditionFragment : public ConditionFragment
{
  NO_COPYING(AssignmentConditionFragment);

public:
  AssignmentConditionFragment(Term* lhs, Term* rhs);
  ~AssignmentConditionFragment();

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
  LhsAutomaton* lhsMatcher;
  int rhsIndex;
};

inline Term*
AssignmentConditionFragment::getLhs() const
{
  return lhs;
}

inline Term*
AssignmentConditionFragment::getRhs() const
{
  return rhs;
}

#endif
