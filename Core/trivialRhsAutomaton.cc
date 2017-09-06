//
//	Implementation for TrivialRhsAutomaton.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//	core class definitions
//#include "variableSymbol.hh"
#include "variableInfo.hh"
#include "substitution.hh"
#include "trivialRhsAutomaton.hh"

TrivialRhsAutomaton::TrivialRhsAutomaton(int index)
  : index(index)
{
}

void
TrivialRhsAutomaton::remapIndices(VariableInfo& variableInfo)
{
  index = variableInfo.remapIndex(index);
}

DagNode*
TrivialRhsAutomaton::construct(Substitution& matcher)
{
  return matcher.value(index);
}

void
TrivialRhsAutomaton::replace(DagNode* old, Substitution& matcher)
{
  matcher.value(index)->overwriteWithClone(old);
}

#ifdef DUMP
void
TrivialRhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{TrivialRhsAutomaton}\n";
  s << Indent(indentLevel + 1) << "index = " << index << "\n";
  s << Indent(indentLevel) << "End{TrivialRhsAutomaton}\n";
}
#endif
