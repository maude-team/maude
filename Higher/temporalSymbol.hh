//
//      Abstract base class for symbols that need to manipulate LTL formulae.
//
#ifndef _temporalSymbol_hh_
#define _temporalSymbol_hh_
#include "freeSymbol.hh"
#include "dagNodeSet.hh"
#include "bddUser.hh"

class TemporalSymbol : public FreeSymbol
{
  NO_COPYING(TemporalSymbol);

public:
  TemporalSymbol(int id, int arity);

  bool attachSymbol(const char* purpose, Symbol* symbol);
  void copyAttachments(Symbol* original, SymbolMap* map);

protected:
  int build(LogicFormula& formula, DagNodeSet& propositions, DagNode* dagNode) const;
  // DagNode* formula2Dag(Bdd formula, DagNodeSet& propositions) const;
  DagNode* negate(DagNode* original) const;
  DagNode* conjunct(Vector<DagNode*>& args) const;

private:
  //
  //	Symbols need for LTL formulae.
  //
  Symbol* trueSymbol;
  Symbol* falseSymbol;
  Symbol* notSymbol;
  Symbol* nextSymbol;
  Symbol* andSymbol;
  Symbol* orSymbol;
  Symbol* untilSymbol;
  Symbol* releaseSymbol;
};

inline DagNode*
TemporalSymbol::negate(DagNode* original) const
{
  static Vector<DagNode*> arg(1);
  arg[0] = original;
  return notSymbol->makeDagNode(arg);
}

#endif
