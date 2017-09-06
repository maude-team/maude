//
//	Class for terms containing floating point numbers.
//
#ifndef _floatTerm_hh_
#define _floatTerm_hh_
#include "NA_Term.hh"

class FloatTerm : public NA_Term
{
public:
  FloatTerm(FloatSymbol* symbol, double value);

  Term* deepCopy2(SymbolMap* map) const;
  Term* normalize(bool full, bool& changed);
  int compareArguments(const Term* other) const;
  int compareArguments(const DagNode* other) const;
  void overwriteWithDagNode(DagNode* old) const;
  NA_DagNode* makeDagNode() const;

  double getValue() const;

private:
  const double value;
};

inline double
FloatTerm::getValue() const
{
  return value;
}

#endif
