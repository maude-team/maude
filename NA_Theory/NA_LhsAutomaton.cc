//
//      Implementation for class NA_LhsAutomaton.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"

//      NA theory class definitions
#include "NA_Symbol.hh"
#include "NA_Term.hh"
#include "NA_DagNode.hh"
#include "NA_LhsAutomaton.hh"

NA_LhsAutomaton::NA_LhsAutomaton(NA_Term* term) : term(term)
{
}

bool
NA_LhsAutomaton::match(DagNode* subject,
		       Substitution& /* solution */,
		       Subproblem*& returnedSubproblem,
		       ExtensionInfo* /* extensionInfo */)
{
  returnedSubproblem = 0;
  return term->equal(subject);
}

#ifdef DUMP
void
NA_LhsAutomaton::dump(ostream& s, const VariableInfo& /* variableInfo */, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{NA_LhsAutomaton}\n";
  s << Indent(indentLevel + 1) << "term = " << term << '\n';
  s << Indent(indentLevel) << "End{NA_LhsAutomaton}\n";
}
#endif
