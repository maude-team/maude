//
//	Class for terms in the AC and ACU theories.
//
#ifndef _ACU_Term_hh_
#define _ACU_Term_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "ACU_Symbol.hh"
#include "term.hh"

class ACU_Term : public Term
{
  NO_COPYING(ACU_Term);

public:
  ACU_Term(ACU_Symbol* symbol, const Vector<Term*>& arguments);
  //
  //    Member functions required by theory interface
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
  //
  //    Functions particular to ACU_Term
  //
  ACU_Symbol* symbol() const;

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  struct Pair  // misnomer!
    {
      Term* term;
      int multiplicity;
      short abstractionVariableIndex;	// if subterm could enter our theory we abstract it
      Bool collapseToOurSymbol;		// first possible reason for variable abstraction
      Bool matchOurIdentity;		// second possible reason for variable abstraction
    };

  struct CP_Sequence;

  ACU_Term(const ACU_Term& original, SymbolMap* map);
  bool normalizeAliensAndFlatten();
  ACU_NonLinearLhsAutomaton* tryToMakeNonLinearLhsAutomaton(bool matchAtTop,
							    const VariableInfo& variableInfo,
							    NatSet& boundUniquely);
  ACU_AlienAlienLhsAutomaton* tryToMakeAlienAlienLhsAutomaton(const VariableInfo& variableInfo,
							      NatSet& boundUniquely);
  ACU_CollectorLhsAutomaton* tryToMakeCollectorLhsAutomaton(bool matchAtTop,
							    const VariableInfo& variableInfo,
							    NatSet& boundUniquely,
							    int collectorCandidate);
  static bool pairLt(const Pair& p1, const Pair& p2);
  static void weakConstraintPropagation(const Vector<Pair>& aliens,
					const NatSet& boundUniquely,
					int step,
					Vector<int>& sequence);
  ACU_LhsAutomaton* compileLhs3(bool matchAtTop,
				const VariableInfo& variableInfo,
				NatSet& boundUniquely,
				bool& subproblemLikely);
  //
  //	Functions needed to compile aliens only case matching.
  //
  static void compileAliensOnlyCase(ACU_LhsAutomaton* automaton,
				    const Vector<Pair>& nonGroundAliens,
				    const VariableInfo& variableInfo,
				    NatSet& boundUniquely,
				    bool& subproblemLikely);
  static void findConstraintPropagationSequence(const Vector<Pair>& aliens,
						const NatSet& boundUniquely,
						CP_Sequence& bestSequence);
  static void findConstraintPropagationSequence(const Vector<Pair>& aliens,
						const Vector<int>& currentSequence,
						const NatSet& boundUniquely,
						int step,
						CP_Sequence& bestSequence);
  static void addIndependentAliens(const Vector<Pair>& aliens,
				   CP_Sequence& bestSequence);
  //
  //	Functions needed to compile full and greedy case matching.
  //
  static void compileGreedyAndFullCases(ACU_LhsAutomaton* automaton,
					const Vector<Pair>& nonGroundAliens,
					const VariableInfo& variableInfo,
					NatSet& boundUniquely,
					bool& subproblemLikely);
  static int findGreedySequence(const Vector<Pair>& aliens, Vector<int>& sequence);
  static void findIndependentSets(const Vector<Pair>& aliens,
				  Vector<Vector<int> >& independents);
  static void findLongestIncreasingSequence(const Vector<Pair>& aliens,
					    Vector<int>& dependents,
					    Vector<int>& sequence);
  static void findFullSequence(const Vector<Pair>& aliens,
			       const NatSet& boundUniquely,
			       Vector<int>& sequence);

  Vector<Pair> argArray;
  int uniqueCollapseSubtermIndex;

  friend class ACU_ArgumentIterator;
};

inline ACU_Symbol*
ACU_Term::symbol() const
{
  return safeCast(ACU_Symbol*, Term::symbol());
}

#endif
