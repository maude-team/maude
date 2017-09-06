//
//	Implementation for class Pattern.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "term.hh"
#include "lhsAutomaton.hh"

//	core class definitions
#include "termBag.hh"
#include "substitution.hh"
#include "pattern.hh"

Pattern::Pattern(Term* patternTerm,
		 bool withExtension,
		 const Vector<ConditionFragment*>& condition)
  : PreEquation(NONE, patternTerm, condition)
{
  NatSet boundVariables;  // variables bound by matching
  check(boundVariables);
  if (!(isBad()))
    {
      preprocess();
      addConditionVariables(getLhs()->occursBelow());
      TermBag availableTerms;  // terms available for reuse
      compileBuild(availableTerms, false);
      compileMatch(true, withExtension);
    }
}

int
Pattern::traceBeginTrial(DagNode* subject, RewritingContext& context) const
{
  return UNDEFINED;
}
