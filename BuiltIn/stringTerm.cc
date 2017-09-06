//
//      Implementation for class StringTerm
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
#include "stringSymbol.hh"
#include "stringTerm.hh"
#include "stringDagNode.hh"

#ifdef ALPHA
//
//	This explicit template instantiation seems to be necessary to create
//	rope<char, allocator<char> >::_S_min_len
//
template class rope<char>;
#endif

StringTerm::StringTerm(StringSymbol* symbol, const crope& value)
  : NA_Term(symbol),
    value(value)
{
}

Term*
StringTerm::deepCopy2(SymbolMap* map) const
{
  return new StringTerm(static_cast<StringSymbol*>(map == 0 ? symbol() :
						   map->translate(symbol())),
			value);
}

Term*
StringTerm::normalize(bool /* full */, bool& changed)
{
  changed = false;
  int hashValue = 0;
  for (crope::const_iterator i(value.begin()); i != value.end(); i++)
    hashValue = (hashValue << 1) + *i;
  setHashValue(hash(symbol()->getHashValue(), hashValue));
  return this;
}

int
StringTerm::compareArguments(const Term* other) const
{
  return value.compare(static_cast<const StringTerm*>(other)->value);
}

int
StringTerm::compareArguments(const DagNode* other) const
{
  return value.compare(static_cast<const StringDagNode*>(other)->getValue());
}

void
StringTerm::overwriteWithDagNode(DagNode* old) const
{
  (void) new(old) StringDagNode(static_cast<StringSymbol*>(symbol()), value);
}

NA_DagNode*
StringTerm::makeDagNode() const
{
  return new StringDagNode(static_cast<StringSymbol*>(symbol()), value);
}
