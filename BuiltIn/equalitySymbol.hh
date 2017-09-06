//
//      Class for symbols for built in equality operations.
//
#ifndef _equalitySymbol_hh_
#define _equalitySymbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "freeSymbol.hh"
#include "cachedDag.hh"
#include "fullCompiler.hh"

class EqualitySymbol : public FreeSymbol
{
public:
  EqualitySymbol(int id,
		 Term* eq,
		 Term* neq,
		 const Vector<int>& strategy);
  ~EqualitySymbol();

  void postInterSymbolPass();
  void reset();
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  //
  //	We don't accept or compile any equations.
  //
  bool acceptEquation(Equation* equation);
  void compileEquations();
#ifdef COMPILER
  void generateCode(CompilationContext& context) const;
#endif

private:
  CachedDag equalTerm;
  CachedDag notEqualTerm;
};

#endif
