//
//      Implementation for class FloatTerm.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//	core class definitions
#include "symbolMap.hh"

//	built in class definitions
#include "floatSymbol.hh"
#include "floatTerm.hh"
#include "floatDagNode.hh"

FloatTerm::FloatTerm(FloatSymbol* symbol, double value)
  : NA_Term(symbol),
    value((value == 0.0) ? 0.0 : value)  // don't allow IEEE-754 -0.0
{
}

Term*
FloatTerm::deepCopy2(SymbolMap* map) const
{
  return new FloatTerm(static_cast<FloatSymbol*>(map == 0 ? symbol() :
						 map->translate(symbol())),
		       value);
}

Term*
FloatTerm::normalize(bool /* full */, bool& changed)
{
  changed = false;
  Int64 bitPattern = *(reinterpret_cast<const Int64*>(&value));
  setHashValue(hash(symbol()->getHashValue(), bitPattern ^ (bitPattern >> 32)));
  return this;
}

int
FloatTerm::compareArguments(const Term* other) const
{
  double otherValue = static_cast<const FloatTerm*>(other)->value;
  //
  //	Straight forward subtraction might fail for values near +- 2^63
  //
  return (value == otherValue) ? 0 : ((value > otherValue) ? 1 : -1);
}

int
FloatTerm::compareArguments(const DagNode* other) const
{
  double otherValue = static_cast<const FloatDagNode*>(other)->value;
  //
  //	Straight forward subtraction might fail for values near +- 2^63
  //
  return (value == otherValue) ? 0 : ((value > otherValue) ? 1 : -1);
}

void
FloatTerm::overwriteWithDagNode(DagNode* old) const
{
  (void) new(old) FloatDagNode(static_cast<FloatSymbol*>(symbol()), value);
}

NA_DagNode*
FloatTerm::makeDagNode() const
{
  return new FloatDagNode(static_cast<FloatSymbol*>(symbol()), value);
}
