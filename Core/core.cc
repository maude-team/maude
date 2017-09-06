//
//	Implementation file for core classes that do not really have
//	implementations; needed for virtual function tables, inline functions etc.
//
#ifdef __GNUG__
#pragma implementation "namedEntity.hh"
#pragma implementation "moduleItem.hh"
#pragma implementation "lineNumber.hh"
#pragma implementation "badFlag.hh"
#pragma implementation "argumentIterator.hh"
#pragma implementation "dagArgumentIterator.hh"
#pragma implementation "subproblemAccumulator.hh"
#pragma implementation "redexPosition.hh"
#pragma implementation "label.hh"
#pragma implementation "symbolMap.hh"
#pragma implementation "simpleRootContainer.hh"
#pragma implementation "conditionFragment.hh"
#pragma implementation "conditionState.hh"
#pragma implementation "opDeclaration.hh"
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "subproblem.hh"

//	core class definitions
#include "namedEntity.hh"
#include "moduleItem.hh"
#include "lineNumber.hh"
#include "badFlag.hh"
#include "sort.hh"
#include "subproblemSequence.hh"
#include "subproblemAccumulator.hh"
#include "redexPosition.hh"
#include "label.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "rawArgumentIterator.hh"
#include "rawDagArgumentIterator.hh"

//	core class definitions
#include "argumentIterator.hh"
#include "dagArgumentIterator.hh"
#include "symbolMap.hh"
#include "simpleRootContainer.hh"
#include "conditionFragment.hh"
#include "conditionState.hh"
#include "opDeclaration.hh"
