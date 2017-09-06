//
//	Base class for non-algebraic built-in constant symbols.
//
#ifndef _NA_Symbol_hh_
#define _NA_Symbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "symbol.hh"

class NA_Symbol : public Symbol
{
public:
  NA_Symbol(int id);

  Term* makeTerm(const Vector<Term*>& args);
  DagNode* makeDagNode(const Vector<DagNode*>& args);
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  void computeBaseSort(DagNode* subject);
  void normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context);
  void stackArguments(DagNode* subject,
		      Vector<RedexPosition>& stack,
		      int parentIndex);
};

#endif
