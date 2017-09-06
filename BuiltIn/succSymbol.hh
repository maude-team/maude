//
//      Class for symbols for successor operation.
//
#ifndef _succSymbol_hh_
#define _succSymbol_hh_
#include <gmpxx.h>
#include "S_Symbol.hh"
#include "cachedDag.hh"

class SuccSymbol : public S_Symbol
{
public:
  SuccSymbol(int id);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachTerm(const char* purpose, Term* term);
  void copyAttachments(Symbol* original, SymbolMap* map);

  void postInterSymbolPass();
  void reset();
  //
  //	Functions special to SuccSymbol.
  //
  Term* makeNatTerm(const mpz_class& nat);
  DagNode* makeNatDag(const mpz_class& nat);
  bool isNat(const Term* term) const;
  bool isNat(const DagNode* dagNode) const;
  const mpz_class& getNat(const Term* term) const;
  const mpz_class& getNat(const DagNode* dagNode) const;
  bool getSignedInt(const DagNode* dagNode, int& value) const;
  bool getSignedInt64(const DagNode* dagNode, Int64& value) const;
  bool rewriteToNat(DagNode* subject, RewritingContext& context, const mpz_class& result);

private:
  CachedDag zeroTerm;
};

#endif
