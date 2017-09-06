//
//	Abstract base class for subproblems during matching.
//
#ifndef _subproblem_hh_
#define _subproblem_hh_

class Subproblem
{
public:
  virtual ~Subproblem() {}  // deep
  virtual bool solve(bool findFirst, RewritingContext& solution) = 0;

#ifdef DUMP
  virtual void dump(ostream& s,
		    const VariableInfo& variableInfo,
		    int indentLevel = 0) {}  // HACK
#endif

};

#endif
