//
//	Class for terms belonging to theories made from C, Ul, Ur and I axioms.
//
#ifndef _CUI_Term_hh_
#define _CUI_Term_hh_
#include "term.hh"

class CUI_Term : public Term
{
  NO_COPYING(CUI_Term);

public:
  CUI_Term(CUI_Symbol* symbol, const Vector<Term*>& arguments);
  //
  //    Member functions required by theory interface.
  //
  RawArgumentIterator* arguments();
  void deepSelfDestruct();
  Term* deepCopy2(SymbolMap* map) const;
  Term* normalize(bool full, bool& changed);
  int compareArguments(const Term* other) const;
  int compareArguments(const DagNode* other) const;
  void findEagerVariables(bool atTop, NatSet& eagerVariables) const;
  void analyseCollapses2();
  void analyseConstraintPropagation(NatSet& boundUniquely) const;
  LhsAutomaton* compileLhs2(bool matchAtTop,
			    const VariableInfo& variableInfo,
			    NatSet& boundUniquely,
			    bool& subproblemLikely);
  void markEagerArguments(int nrVariables,
                          const NatSet& eagerVariables,
                          Vector<int>& problemVariables);
  DagNode* dagify2();

  void findAvailableTerms(TermBag& availableTerms, bool eagerContext, bool atTop);
  int compileRhs2(RhsBuilder& rhsBuilder,
		  VariableInfo& variableInfo,
		  TermBag& availableTerms,
		  bool eagerContext);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

  //
  //    Functions particular to CUI_Term.
  //
  CUI_Symbol* symbol() const;

private:
  CUI_Term(const CUI_Term& original, SymbolMap* map);
  
  bool betterToReverseOrder(NatSet& boundUniquely) const;
  Term* collapseTo(int argNr);

  Vector<Term*> argArray;
  //
  //	Flags for compiling patterns.
  //
  bool id0CollapsePossible;   // possible collapse to argArray[1]
  bool id1CollapsePossible;   // possible collapse to argArray[0]
  bool idemCollapsePossible;  // possible collapse with argArray[0] = argArray[1] 
};

inline CUI_Symbol*
CUI_Term::symbol() const
{
  return static_cast<CUI_Symbol*>(Term::symbol());
}

#endif
