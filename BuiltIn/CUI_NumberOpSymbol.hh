//
//      Class for symbols for built in CUI operations on numbers.
//
#ifndef _CUI_NumberOpSymbol_hh_
#define _CUI_NumberOpSymbol_hh_
#include "CUI_Symbol.hh"

class CUI_NumberOpSymbol : public CUI_Symbol
{
public:
  CUI_NumberOpSymbol(int id, Axioms axioms);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  void copyAttachments(Symbol* original, SymbolMap* map);

  bool eqRewrite(DagNode* subject, RewritingContext& context);

private:
  int op;
  SuccSymbol* succSymbol;
};

#endif
