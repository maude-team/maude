//
//      Implementation for class NA_RhsAutomaton.
//
#ifdef __GNUG__
#pragma implementation
#endif

//      utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"

//      core class definitions
#include "substitution.hh"
#include "variableInfo.hh"

//      NA theory class definitions
#include "NA_Symbol.hh"
#include "NA_Term.hh"
#include "NA_DagNode.hh"
#include "NA_RhsAutomaton.hh"

NA_RhsAutomaton::NA_RhsAutomaton(NA_Term* term, int destination)
  : term(term),
    destination(destination)
{
}

void
NA_RhsAutomaton::remapIndices(VariableInfo& variableInfo)
{
  destination = variableInfo.remapIndex(destination);
}

DagNode*
NA_RhsAutomaton::construct(Substitution& matcher)
{
  NA_DagNode* d = term->makeDagNode();
  matcher.bind(destination, d);
  return d;
}

void
NA_RhsAutomaton::replace(DagNode* old, Substitution& /* matcher */)
{
  term->overwriteWithDagNode(old);
}

#ifdef DUMP
void
NA_RhsAutomaton::dump(ostream& s, const VariableInfo& /* variableInfo */, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{NA_RhsAutomaton}\n";
  s << Indent(indentLevel + 1) << "[" << destination << "] <= " << term << '\n';
  s << Indent(indentLevel) << "End{NA_RhsAutomaton}\n";
}
#endif
