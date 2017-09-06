//
//      Class for terms containing quoted identifiers (references to real identifiers).
//
#ifndef _quotedIdentifierTerm_hh_
#define _quotedIdentifierTerm_hh_
#include "NA_Term.hh"

class QuotedIdentifierTerm : public NA_Term
{
public:
  QuotedIdentifierTerm(QuotedIdentifierSymbol* symbol, int idIndex);

  Term* deepCopy2(SymbolMap* map) const;
  Term* normalize(bool full, bool& changed);
  int compareArguments(const Term* other) const;
  int compareArguments(const DagNode* other) const;
  void overwriteWithDagNode(DagNode* old) const;
  NA_DagNode* makeDagNode() const;

  int getIdIndex() const;

private:
  NO_COPYING(QuotedIdentifierTerm);

  const int idIndex;
};

inline int
QuotedIdentifierTerm::getIdIndex() const
{
  return idIndex;
}

#endif
