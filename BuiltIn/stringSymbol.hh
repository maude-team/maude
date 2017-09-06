//
//	Class for string symbols.
//
#ifndef _stringSymbol_hh_
#define _stringSymbol_hh_
#include "NA_Symbol.hh"

class StringSymbol : public NA_Symbol
{
public:
  StringSymbol(int id);

  void fillInSortInfo(Term* subject);
  void computeBaseSort(DagNode* subject);
  bool isConstructor(DagNode* subject);
  void compileOpDeclarations();

private:
  Sort* sort;
  Sort* charSort;
};

#endif
