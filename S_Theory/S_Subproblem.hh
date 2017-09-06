//
//      Class for subproblems in the S theory.
//
#ifndef _S_Subproblem_hh_
#define _S_Subproblem_hh_
#include <gmpxx.h>
#include "subproblem.hh"

class S_Subproblem : public Subproblem
{
  NO_COPYING(S_Subproblem);

public:
  S_Subproblem(S_DagNode* subject,
	       const mpz_class& leftOver,
	       int varIndex,
	       const Sort* varSort,
	       S_ExtensionInfo* extension);
  //
  //	Member functions required by theory interface.
  //
  bool solve(bool findFirst, RewritingContext& solution);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  S_DagNode* const subject;
  const mpz_class leftOver;
  S_ExtensionInfo* const extensionInfo;
  const int varIndex;
  const Sort* const varSort;
};

#endif
