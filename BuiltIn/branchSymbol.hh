//
//      Class for symbols for built in branch (if-then-else-fi type) operations.
//
#ifndef _branchSymbol_hh_
#define _branchSymbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "freeSymbol.hh"

class BranchSymbol : public FreeSymbol
{
public:
  BranchSymbol(int id, Vector<Term*>& testValues);
  ~BranchSymbol();

  void fillInSortInfo(Term* subject);
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  void computeBaseSort(DagNode* subject);
  void stackArguments(DagNode* subject,
		      Vector<RedexPosition>& stack,
		      int parentIndex);
  //
  //	Dummy since our sorting function is more complex than can
  //	be specified using standard sort mechanism.
  //
  void compileOpDeclarations();

private:
  Vector<Term*> testTerms;
};

#endif
