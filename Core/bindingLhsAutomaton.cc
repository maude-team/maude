//
//      Implementation for class BindingLhsAutomaton.
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
#include "symbol.hh"
#include "dagNode.hh"

//      core class definitions
#include "substitution.hh"
#include "bindingLhsAutomaton.hh"

BindingLhsAutomaton::BindingLhsAutomaton(int variableIndex, LhsAutomaton* realLhsAutomaton)
  : variableIndex(variableIndex),
    realLhsAutomaton(realLhsAutomaton)
{
}

BindingLhsAutomaton::~BindingLhsAutomaton()
{
  delete realLhsAutomaton;
}

bool
BindingLhsAutomaton::match(DagNode* subject,
			   Substitution& solution,
			   Subproblem*& returnedSubproblem,
			   ExtensionInfo* extensionInfo)
{
  if (realLhsAutomaton->match(subject, solution, returnedSubproblem, extensionInfo))
    {
      solution.bind(variableIndex, subject);
      return true;
    }
  return false;
}

#ifdef DUMP
void
BindingLhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{BindingLhsAutomaton}\n";
  s << Indent(indentLevel + 1) << "variableIndex = " << variableIndex << '\n';
  s << Indent(indentLevel + 1) << "realLhsAutomaton =\n";
  realLhsAutomaton->dump(s, variableInfo, indentLevel + 2);
  s << Indent(indentLevel) << "End{BindingLhsAutomaton}\n";
}
#endif
