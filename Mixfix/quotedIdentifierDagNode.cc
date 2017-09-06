//
//      Implementation for class QuotedIdentifierDagNode.
//
 
//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"
#include "mixfix.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//      front end class definitions
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierDagNode.hh"
#include "token.hh"

QuotedIdentifierDagNode::QuotedIdentifierDagNode(QuotedIdentifierSymbol* symbol,
						 int idIndex)
  : NA_DagNode(symbol),
    idIndex(idIndex)
{
}

size_t
QuotedIdentifierDagNode::getHashValue()
{
  return hash(symbol()->getHashValue(), idIndex);
}

int
QuotedIdentifierDagNode::compareArguments(const DagNode* other) const
{
  return idIndex - static_cast<const QuotedIdentifierDagNode*>(other)->idIndex;
}
 
void
QuotedIdentifierDagNode::overwriteWithClone(DagNode* old)
{
  QuotedIdentifierDagNode* d =
    new(old) QuotedIdentifierDagNode(safeCast(QuotedIdentifierSymbol*, symbol()),
				     idIndex);
  d->copySetRewritingFlags(this);
  d->setSortIndex(getSortIndex());
}

DagNode*
QuotedIdentifierDagNode::makeClone()
{
  QuotedIdentifierDagNode* d =
    new QuotedIdentifierDagNode(safeCast(QuotedIdentifierSymbol*, symbol()),
				idIndex);
  d->copySetRewritingFlags(this);
  d->setSortIndex(getSortIndex());
  return d;
}
