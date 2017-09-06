//
//      Implementation for class RhsBuilder.
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

//      interface class definitions
#include "rhsBuilder.hh"

RhsBuilder::~RhsBuilder()
{
  int nrAutomata = automata.length();
  for (int i = 0; i < nrAutomata; i++)
    delete automata[i];
  delete lastAutomaton;
}

void
RhsBuilder::remapIndices(VariableInfo& variableInfo)
{
  int nrAutomata = automata.length();
  for (int i = 0; i < nrAutomata; i++)
    automata[i]->remapIndices(variableInfo);
  if (lastAutomaton != 0)
    lastAutomaton->remapIndices(variableInfo);
}

#ifdef DUMP
void
RhsBuilder::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{FreeRhsAutomaton}\n";
  s << Indent(indentLevel + 1) << "automata:\n";
  int nrAutomata = automata.length();
  for (int i = 0; i < nrAutomata; i++)
    automata[i]->dump(s, variableInfo, indentLevel + 2);
  s << Indent(indentLevel + 1) << "lastAutomata:\n";
  lastAutomaton->dump(s, variableInfo, indentLevel + 2);
  s << Indent(indentLevel) << "End{FreeRhsAutomaton}\n";
}
#endif
