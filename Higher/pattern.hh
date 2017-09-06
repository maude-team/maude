//
//	Patterns for matching.
//
#ifndef _pattern_hh_
#define _pattern_hh_
#include "preEquation.hh"

class Pattern : public PreEquation
{
public:
  Pattern(Term* patternTerm,
	  bool withExtension,
	  const Vector<ConditionFragment*>& condition = noCondition);

private:
  int traceBeginTrial(DagNode* subject, RewritingContext& context) const;
};

#endif
