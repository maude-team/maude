//
//      Implementation for class ACU_CollectorLhsAutomaton.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "indent.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
#include "heuristicLhsAutomaton.hh"

HeuristicLhsAutomaton::~HeuristicLhsAutomaton()
{
  delete fullAutomaton;
}

#ifdef DUMP
void
HeuristicLhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "fullAutomaton =\n";
  fullAutomaton->dump(s, variableInfo, indentLevel + 1);
}
#endif
