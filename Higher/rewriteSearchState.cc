//
//	Implementation for class RewriteSearchState.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//	core class definitions
#include "rewritingContext.hh"
#include "rhsAutomaton.hh"
#include "rule.hh"
#include "rewriteSearchState.hh"

RewriteSearchState::RewriteSearchState(RewritingContext* context,
				       int label,
				       int flags,
				       int minDepth,
				       int maxDepth)
  : SearchState(context, flags | RESPECT_FROZEN, minDepth, maxDepth),
    label(label),
    withExtension(maxDepth >= 0)
{
  ruleIndex = -1;
}

bool
RewriteSearchState::findNextRewrite()
{
  if (ruleIndex > -1)
    {
      if (findNextSolution())
	return true;
    }
  else
    {
      if (!findNextPosition())
	return false;
    }
  ++ruleIndex;
  bool allowNonexec = getFlags() & ALLOW_NONEXEC;
  do
    {
      const Vector<Rule*>& rules = getDagNode()->symbol()->getRules();
      for (int nrRules = rules.length(); ruleIndex < nrRules; ruleIndex++)
	{
	  Rule* rl = rules[ruleIndex];
	  if ((allowNonexec || !(rl->isNonexec())) &&
	      (label == UNDEFINED || rl->getLabel().id() == label))
	    {
	      LhsAutomaton* a = withExtension ? rl->getExtLhsAutomaton() :
		rl->getNonExtLhsAutomaton();
	      if (findFirstSolution(rl, a))
		return true;
	    }
	}
      ruleIndex = 0;
    }
  while (findNextPosition());
  return false;
}

Rule*
RewriteSearchState::getRule() const
{
  return (getDagNode()->symbol()->getRules())[ruleIndex];
}

DagNode*
RewriteSearchState::getReplacement() const
{
  return getRule()->getRhsBuilder().construct(*(getContext()));
}
