//
//	Class for subproblems where we have to match the matched portion of a subject
//	given by extension information agaisnt a second pattern.
//
#ifndef _extensionMatchSubproblem_hh_
#define _extensionMatchSubproblem_hh_
#include "subproblem.hh"
#include "dagRoot.hh"
#include "substitution.hh"

class ExtensionMatchSubproblem : public Subproblem
{
public:
  ExtensionMatchSubproblem(LhsAutomaton* pattern,
			   ExtensionInfo* extensionInfo,
			   int nrVariables);
  ~ExtensionMatchSubproblem();

  bool solve(bool findFirst, RewritingContext& solution);

private:
  LhsAutomaton* const pattern;
  ExtensionInfo* const extensionInfo;
  DagRoot matchedPortion;
  LocalBinding* difference;
  Subproblem* subproblem;
  Substitution local;
};

#endif
