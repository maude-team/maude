//
//      Class for symbols for exact division operation on numbers.
//
#ifndef _divisionSymbol_hh_
#define _divisionSymbol_hh_
#include "freeSymbol.hh"
#include "cachedDag.hh"

class DivisionSymbol : public FreeSymbol
{
public:
  DivisionSymbol(int id);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  void copyAttachments(Symbol* original, SymbolMap* map);

  bool eqRewrite(DagNode* subject, RewritingContext& context);
  //
  //	Functions special to DivisionSymbol.
  //
  DagNode* makeRatDag(const mpz_class& nr, const mpz_class& dr);
  bool isRat(const DagNode* dagNode) const;
  const mpz_class& getRat(const DagNode* dagNode, mpz_class& numerator) const;
  Term* makeRatTerm(const mpz_class& nr, const mpz_class& dr);
  bool isRat(/* const */ Term* term) const;
  const mpz_class& getRat(/* const */ Term* term, mpz_class& numerator) const;
 
  SuccSymbol* succSymbol;
  MinusSymbol* minusSymbol;
};

#endif
