//
//      Class for variable symbols.
//
#ifndef _variableSymbol_hh_
#define _variableSymbol_hh_
#include "symbol.hh"

class VariableSymbol : public Symbol
{
  NO_COPYING(VariableSymbol);

public:
  VariableSymbol(int id);

  Term* makeTerm(const Vector<Term*>& args);
  DagNode* makeDagNode(const Vector<DagNode*>& args);
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  void computeBaseSort(DagNode* subject);
  void normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context);
  void stackArguments(DagNode* subject,
		      Vector<RedexPosition>& stack,
		      int parentIndex);
  //
  //	VariableSymbol specific functions.
  //
  Sort* getSort();
};

inline Sort*
VariableSymbol::getSort()
{
  //
  //	Temporary hack until sorts mechanism revised.
  //
  const Vector<OpDeclaration>& s = getOpDeclarations();
  Assert(s.length() == 1, "s.length() != 1");
  const Vector<Sort*>& v = s[0].getDomainAndRange();
  Assert(v.length() == 1, "v.length() != 1");
  return v[0];
}

#endif
