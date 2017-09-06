//
//      Implementation for class QuotedIdentifierTerm.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"
#include "stringTable.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"
#include "mixfix.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//	core class definitions
#include "symbolMap.hh"

//	front end class definitions
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierTerm.hh"
#include "quotedIdentifierDagNode.hh"
#include "token.hh"


QuotedIdentifierTerm::QuotedIdentifierTerm(QuotedIdentifierSymbol* symbol, int idIndex)
  : NA_Term(symbol),
    idIndex(idIndex)
{
}

Term*
QuotedIdentifierTerm::deepCopy2(SymbolMap* map) const
{
  return new QuotedIdentifierTerm(static_cast<QuotedIdentifierSymbol*>(map == 0 ? symbol() :
								       map->translate(symbol())),
				  idIndex);
}

Term*
QuotedIdentifierTerm::normalize(bool /* full */, bool& changed)
{
  changed = false;
  setHashValue(hash(symbol()->getHashValue(), idIndex));
  return this;
}

int
QuotedIdentifierTerm::compareArguments(const Term* other) const
{
  return idIndex - static_cast<const QuotedIdentifierTerm*>(other)->idIndex;
}

int
QuotedIdentifierTerm::compareArguments(const DagNode* other) const
{
  return idIndex - static_cast<const QuotedIdentifierDagNode*>(other)->getIdIndex();
}

void
QuotedIdentifierTerm::overwriteWithDagNode(DagNode* old) const
{
  (void) new(old) QuotedIdentifierDagNode(static_cast<QuotedIdentifierSymbol*>(symbol()), idIndex);
}

NA_DagNode*
QuotedIdentifierTerm::makeDagNode() const
{
  return new QuotedIdentifierDagNode(static_cast<QuotedIdentifierSymbol*>(symbol()), idIndex);
}
