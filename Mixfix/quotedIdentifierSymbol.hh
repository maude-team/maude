//
//	Class for quoted identifier symbols.
//
#ifndef _quotedIdentifierSymbol_hh_
#define _quotedIdentifierSymbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "NA_Symbol.hh"

class QuotedIdentifierSymbol : public NA_Symbol
{
public:
  QuotedIdentifierSymbol(int id);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  void copyAttachments(Symbol* original, SymbolMap* map);
  void fillInSortInfo(Term* subject);
  void computeBaseSort(DagNode* subject);
  bool isConstructor(DagNode* subject);
  void compileOpDeclarations();

private:
  Sort* determineSort(int idIndex);

  Sort* baseSort;
  Sort* constantSort;
  Sort* variableSort;
  Sort* sortSort;
  Sort* kindSort;
};

#endif
