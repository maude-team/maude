//
//      Class for symbols for built in operations on quoted identifiers.
//
#ifndef _quotedIdentifierOpSymbol_hh_
#define _quotedIdentifierOpSymbol_hh_
#include "freeSymbol.hh"

class QuotedIdentifierOpSymbol : public FreeSymbol
{
public:
  QuotedIdentifierOpSymbol(int id, int nrArgs);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  void copyAttachments(Symbol* original, SymbolMap* map);
  bool eqRewrite(DagNode* subject, RewritingContext& context);

private:
  NO_COPYING(QuotedIdentifierOpSymbol);

#ifdef MOS
  static int counter;
#endif

  int op;
  QuotedIdentifierSymbol* quotedIdentifierSymbol;
  StringSymbol* stringSymbol;
};

#endif
