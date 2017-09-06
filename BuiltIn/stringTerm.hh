//
//	Class for terms containing strings.
//
#ifndef _stringTerm_hh_
#define _stringTerm_hh_
#ifdef __GNUG__
#pragma interface
#endif
#ifdef LIBv3
#include <ext/rope>
#else
#include <rope>
#endif
#include "NA_Term.hh"

class StringTerm : public NA_Term
{
public:
  StringTerm(StringSymbol* symbol, const crope& value);

  Term* deepCopy2(SymbolMap* map) const;
  Term* normalize(bool full, bool& changed);
  int compareArguments(const Term* other) const;
  int compareArguments(const DagNode* other) const;
  void overwriteWithDagNode(DagNode* old) const;
  NA_DagNode* makeDagNode() const;

  const crope& getValue() const;

private:
  const crope value;
};


inline const crope&
StringTerm::getValue() const
{
  return value;
}

#endif
