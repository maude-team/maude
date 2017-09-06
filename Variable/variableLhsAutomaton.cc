//
//      Implementation for VariableLhsAutomaton.
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
 
//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "lhsAutomaton.hh"
 
//      core class definitions
#include "variableSymbol.hh"
#include "variableInfo.hh"
#include "substitution.hh"
#include "variableLhsAutomaton.hh"
 
VariableLhsAutomaton::VariableLhsAutomaton(int index,
					   const Sort* sort,
					   bool copyToAvoidOverwriting)
  : index(index),
    sort(sort),
    copyToAvoidOverwriting(copyToAvoidOverwriting)
{
}

bool
VariableLhsAutomaton::match(DagNode* subject,
			    Substitution& solution,
			    Subproblem*& returnedSubproblem,
			    ExtensionInfo* extensionInfo)
{
  return subject->matchVariable(index,
				sort,
				copyToAvoidOverwriting,
				solution,
				returnedSubproblem,
				extensionInfo);
}

#ifdef DUMP
void
VariableLhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{VariableLhsAutomaton}\n";
  s << Indent(indentLevel + 1) << "index = " << index <<
    " \"" << variableInfo.index2Variable(index) <<
    "\"\tsort = " <<  sort <<
    "\tcopyToAvoidOverwriting = " << copyToAvoidOverwriting << '\n';
  s << Indent(indentLevel) << "End{VariableLhsAutomaton}\n";
}
#endif
