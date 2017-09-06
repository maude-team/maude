//
//	Implementation file for free theory classes that do not really have
//	implementations; needed for virtual tables, inline functions etc.
//
#ifdef __GNUG__
#pragma implementation "freeOccurrence.hh"
#pragma implementation "freeLhsStructs.hh"
#ifdef COMPILER
#pragma implementation "freeSubterm.hh"
#endif
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"

//	interface class definitions
#include "rhsAutomaton.hh"

//      free theory class definitions
#include "freeOccurrence.hh"
#include "freeSubterm.hh"
#include "freeRhsAutomaton.hh"
