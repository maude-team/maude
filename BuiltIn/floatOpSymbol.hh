//
//      Class for symbols for built in operations on floating point numbers.
//
#ifndef _FloatOpSymbol_hh_
#define _FloatOpSymbol_hh_
#include "freeSymbol.hh"
#include "cachedDag.hh"

class FloatOpSymbol : public FreeSymbol
{
public:
  FloatOpSymbol(int id, int arity);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  bool attachTerm(const char* purpose, Term* term);
  void copyAttachments(Symbol* original, SymbolMap* map);
  void postInterSymbolPass();
  void reset();
  bool eqRewrite(DagNode* subject, RewritingContext& context);

private:
  int isOdd(double n);
  double safePow(double a1, double a2, bool& defined);

  int op;
  FloatSymbol* floatSymbol;
  SuccSymbol* succSymbol;
  MinusSymbol* minusSymbol;
  DivisionSymbol* divisionSymbol;
  CachedDag trueTerm;
  CachedDag falseTerm;
};

#endif
