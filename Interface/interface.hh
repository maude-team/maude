//
//	Forward declarations for equational theory interface classes.
//
#ifndef _interface_hh_
#define _interface_hh_

//
//	These classes must be derived from for all equational theories.
//
class Symbol;		// or
class BinarySymbol;	// or
class AssociativeSymbol;
class Term;
class RawArgumentIterator;
class DagNode;
class RawDagArgumentIterator;
class LhsAutomaton;
class RhsAutomaton;
//
//	These classes must be derived from for equational theories that
//	need to generate matching subproblems or pass back extension
//	information respectively.
//
class Subproblem;
class ExtensionInfo;

#endif
