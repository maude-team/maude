//
//      Class for symbols for built in LTL satisfiability solving.
//
#ifndef _satSolverSymbol_hh_
#define _satSolverSymbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "temporalSymbol.hh"
#include "cachedDag.hh"

class SatSolverSymbol : public TemporalSymbol
{
  NO_COPYING(SatSolverSymbol);

public:
  SatSolverSymbol(int id);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  bool attachTerm(const char* purpose, Term* term);
  void copyAttachments(Symbol* original, SymbolMap* map);
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  void postInterSymbolPass();
  void reset();

private:
  DagNode* makeModel(const DagNodeSet& propositions,
		     const list<Bdd>& leadIn,
		     const list<Bdd>& cycle) const;
  DagNode* makeFormulaList(const DagNodeSet& propositions,
			   const list<Bdd>& bddList) const;
  DagNode* makeFormula(const DagNodeSet& propositions,
		       const Bdd& formula) const;

  //
  //	Symbols needed for returning models.
  //
  Symbol* formulaListSymbol;
  Symbol* nilFormulaListSymbol;
  Symbol* modelSymbol;

  CachedDag falseTerm;
};

#endif
