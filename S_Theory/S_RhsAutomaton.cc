//
//      Implementation for class S_RhsAutomaton.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "S_Theory.hh"

//      core class definitions
#include "substitution.hh"
#include "variableInfo.hh"

//      S theory class definitions
#include "S_Symbol.hh"
#include "S_DagNode.hh"
#include "S_RhsAutomaton.hh"

S_RhsAutomaton::S_RhsAutomaton(S_Symbol* symbol, mpz_class& number, int source, int destination)
  : topSymbol(symbol),
    number(number),
    source(source),
    destination(destination)
{
}

void
S_RhsAutomaton::remapIndices(VariableInfo& variableInfo)
{
  source = variableInfo.remapIndex(source);
  destination = variableInfo.remapIndex(destination);
}

DagNode*
S_RhsAutomaton::construct(Substitution& matcher)
{
  S_DagNode* n = new S_DagNode(topSymbol, number, matcher.value(source));
  matcher.bind(destination, n);
  return n;
}

void
S_RhsAutomaton::replace(DagNode* old, Substitution& matcher)
{
  (void) new(old) S_DagNode(topSymbol, number, matcher.value(source));
}

#ifdef DUMP
void
S_RhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{S_RhsAutomaton}\n";
  s << Indent(indentLevel + 1) << "[" << destination << "] <= " << topSymbol <<
    '^' << number << '(' << '[' << source << "])\n";
  s << Indent(indentLevel) << "End{S_RhsAutomaton}\n";
}
#endif
