//
//	Class for terms in the A, AUl, AUr and AU theories.
//
#ifndef _AU_Term_hh_
#define _AU_Term_hh_
#include "term.hh"
#include "variable.hh"
#include "AU_Symbol.hh"
 
class AU_Term : public Term
{
  NO_COPYING(AU_Term);

public:
  AU_Term(AU_Symbol* symbol, const Vector<Term*>& arguments);
  //
  //    Functions required by theory interface.
  //
  RawArgumentIterator* arguments();
  void deepSelfDestruct();
  Term* deepCopy2(SymbolMap* map) const;
  Term* normalize(bool full, bool& changed);
  int compareArguments(const Term* other) const;
  int compareArguments(const DagNode* other) const;
  void findEagerVariables(bool atTop, NatSet& eagerVariables) const;
  void analyseConstraintPropagation(NatSet& boundUniquely) const;
  void analyseCollapses2();
  void insertAbstractionVariables(VariableInfo& variableInfo);
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
  //	Functions particular to AU_Term.
  //
  AU_Symbol* symbol() const;
  bool idPossible(int index) const;
private:
  struct Tuple
  {
    Term* term;
    short abstractionVariableIndex;	// if subterm could enter our theory we abstract it
    Bool collapseToOurSymbol;		// 1st possible reason for variable abstraction
    Bool matchOurIdentity;		// 2nd possible reason for variable abstraction
  };

  struct CP_Sequence;

  AU_Term(const AU_Term& original, SymbolMap* map);
  bool unitVariable(VariableTerm* vt, int index) const;
  void findConstraintPropagationSequence(const NatSet& boundUniquely,
					 CP_Sequence& bestSequence) const;
  void findConstraintPropagationSequence(const Vector<Bool>& currentSequence,
					 const NatSet& boundUniquely,
					 int leftPos,
					 int rightPos,
					 CP_Sequence& bestSequence) const;
  void addFixedLengthBlock(AU_LhsAutomaton* a,
			   int blockStart,
			   int blockEnd,
			   const VariableInfo& variableInfo,
			   const NatSet& boundUniquely,
			   bool& subproblemLikely);

  Vector<Tuple> argArray;
  int uniqueCollapseSubtermIndex;

  friend class AU_ArgumentIterator;
};

inline AU_Symbol*
AU_Term::symbol() const
{
  return static_cast<AU_Symbol*>(Term::symbol());
}

inline bool
AU_Term::idPossible(int index) const
{
  return (index > 0 && symbol()->rightId()) ||
    (index < argArray.length() - 1 && symbol()->leftId());
}

#endif
