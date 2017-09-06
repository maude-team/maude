//
//	Class for floating point number symbols.
//
#ifndef _floatSymbol_hh_
#define _floatSymbol_hh_
#include "NA_Symbol.hh"

class FloatSymbol : public NA_Symbol
{
public:
  FloatSymbol(int id);

  void fillInSortInfo(Term* subject);
  void computeBaseSort(DagNode* subject);
  void compileOpDeclarations();
  bool isConstructor(DagNode* subject);
  bool rewriteToFloat(DagNode* subject,
		      RewritingContext& context,
		      double result);

private:
  Sort* sort;
  Sort* finiteSort;
};

#endif
