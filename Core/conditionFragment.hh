//
//	Abstract base class for condition fragments.
//
#ifndef _conditionFragment_hh_
#define _conditionFragment_hh_
#include <stack>
#include "rhsBuilder.hh"
#include "conditionState.hh"

class ConditionFragment
{
public:
  virtual ~ConditionFragment() {}

  virtual void check(VariableInfo& varInfo, NatSet& boundVariables) = 0;
  virtual void preprocess() = 0;
  virtual void compileBuild(VariableInfo& variableInfo, TermBag& availableTerms) = 0;
  virtual void compileMatch(VariableInfo& variableInfo, NatSet& boundUniquely) = 0;
  virtual bool solve(bool findFirst,
		     RewritingContext& solution,
		     stack<ConditionState*>& state) = 0;
};

//
//      Output function for ConditionFragment must be defined by library user.
//
ostream& operator<<(ostream& s, const ConditionFragment* c);

#endif

