//
//      Class for sort constraints.
//
#ifndef _sortConstraint_hh_
#define _sortConstraint_hh_
#include "preEquation.hh"

class SortConstraint : public PreEquation
{
public:
  SortConstraint(int label,
		 Term* lhs,
		 Sort* sort,
		 const Vector<ConditionFragment*>& condition = noCondition);

  Sort* getSort() const;
  void check();
  void preprocess();
  void compile(bool compileLhs);

private:
  int traceBeginTrial(DagNode* subject, RewritingContext& context) const;

  Sort* sort;
};

inline Sort*
SortConstraint::getSort() const
{
  return sort;
}

//
//      Output function for SortConstraint must be defined by library user
//
ostream& operator<<(ostream& s, const SortConstraint* sortConstraint);

#endif
