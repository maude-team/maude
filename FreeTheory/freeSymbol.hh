//
//	Class for symbols belonging to the free theory.
//
#ifndef _freeSymbol_hh_
#define _freeSymbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "symbol.hh"
#include "freeNet.hh"

class FreeSymbol : public Symbol
{
  NO_COPYING(FreeSymbol);

public:
  FreeSymbol(int id, int arity, const Vector<int>& strategy = standard, bool memoFlag = false);
  static FreeSymbol* newFreeSymbol(int id,
				   int arity,
				   const Vector<int>& strategy = standard,
				   bool memoFlag = false);

  Term* makeTerm(const Vector<Term*>& args);
  DagNode* makeDagNode(const Vector<DagNode*>& args);
  void compileEquations();
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  void computeBaseSort(DagNode* subject);
  void normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context);
  void stackArguments(DagNode* subject,
		      Vector<RedexPosition>& stack,
		      int parentIndex);

#ifdef COMPILER
  void generateCode(CompilationContext& context) const;
  void generateCons(CompilationContext& context, int indentLevel) const;
#endif

#ifdef DUMP
  void dump(ostream& s, int indentLevel = 0);
#endif

private:
  bool complexStrategy(DagNode* subject, RewritingContext& context);
  void memoStrategy(MemoTable::SourceSet& from, DagNode* subject, RewritingContext& context);

protected:
  FreeNet discriminationNet;
};

#endif
