//
//      Class for symbols for built in sort test operations.
//
#ifndef _sortTestSymbol_hh_
#define _sortTestSymbol_hh_
#include "freeSymbol.hh"

class SortTestSymbol : public FreeSymbol
{
public:
  SortTestSymbol(int id,
		 Sort* testSort,
		 FreeSymbol* leq,
		 FreeSymbol* nleq,
		 bool eager);
 
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  bool eager() const;
  const Sort* sort() const;
  //
  //	We don't accept or compile any equations.
  //
  bool acceptEquation(Equation* equation);
  void compileEquations();

private:
  static const Vector<int>& makeLazyStrategy();

  Sort* cmpSort;
  FreeSymbol* leqResult;
  FreeSymbol* notLeqResult;
  bool eagerFlag;
};

inline bool
SortTestSymbol::eager() const
{
  return eagerFlag;
}

inline const Sort*
SortTestSymbol::sort() const
{
  return cmpSort;
}

#endif
