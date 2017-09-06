//
//	Class for rewrite rules
//
#ifndef _rule_hh_
#define _rule_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "preEquation.hh"
#include "rhsBuilder.hh"

class Rule : public PreEquation
{
public:
  Rule(int label,
       Term* lhs,
       Term* rhs,
       const Vector<ConditionFragment*>& condition = noCondition);
  ~Rule();

  Term* getRhs() const;
  void check();
  void preprocess();
  void compile(bool compileLhs);
  const RhsBuilder& getRhsBuilder() const;
  LhsAutomaton* getNonExtLhsAutomaton();
  LhsAutomaton* getExtLhsAutomaton();

private:
  int traceBeginTrial(DagNode* subject, RewritingContext& context) const;

  Term* rhs;
  RhsBuilder builder;
  LhsAutomaton* nonExtLhsAutomaton;
  LhsAutomaton* extLhsAutomaton;
};

inline Term*
Rule::getRhs() const
{
  return rhs;
}

inline const RhsBuilder&
Rule::getRhsBuilder() const
{
  return builder;
}

//
//      Output function for Rule must be defined by library user
//
ostream& operator<<(ostream& s, const Rule* rule);
 
#endif
