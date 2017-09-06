//
//	Implementation file for interface classes that do not really have
//	implementations; needed for virtual tables, inline functions etc.
//
#ifdef __GNUG__
#pragma implementation "lhsAutomaton.hh"
#pragma implementation "rhsAutomaton.hh"
#pragma implementation "rawArgumentIterator.hh"
#pragma implementation "rawDagArgumentIterator.hh"
#pragma implementation "subproblem.hh"
#pragma implementation "extensionInfo.hh"
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "argVec.hh"
#include "symbol.hh"
#include "dagNode.hh"
#include "lhsAutomaton.hh"
#include "rhsAutomaton.hh"
#include "rawArgumentIterator.hh"
#include "rawDagArgumentIterator.hh"
#include "subproblem.hh"
#include "extensionInfo.hh"

#ifdef DUMP
void
Subproblem::dump(ostream& /* s */, const VariableInfo& /* variableInfo */, int /* indentLevel */)
{
  // temporary HACK
}

#endif
