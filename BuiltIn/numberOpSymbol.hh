//
//      Class for symbols for built in operations on numbers.
//
#ifndef _numberOpSymbol_hh_
#define _numberOpSymbol_hh_
#include "freeSymbol.hh"
#include "cachedDag.hh"

class NumberOpSymbol : public FreeSymbol
{
public:
  NumberOpSymbol(int id, int arity);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  bool attachTerm(const char* purpose, Term* term);
  void copyAttachments(Symbol* original, SymbolMap* map);

  void postInterSymbolPass();
  void reset();
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  //
  //	Functions special to NumberOpSymbol.
  //
  DagNode* makeNegDag(const mpz_class& integer);
  bool isNeg(const DagNode* dagNode) const;
  const mpz_class& getNeg(const DagNode* dagNode, mpz_class& result) const;

protected:
  SuccSymbol* getSuccSymbol() const;

private:
  enum ImplementationConstants
  {
    EXPONENT_BOUND = 1000000	// max allowed exponent to limit runaway memory use
  };

  int op;
  SuccSymbol* succSymbol;
  MinusSymbol* minusSymbol;
  CachedDag trueTerm;
  CachedDag falseTerm;
};

inline SuccSymbol*
NumberOpSymbol::getSuccSymbol() const
{
  return succSymbol;
}

#endif
