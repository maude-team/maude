//
//	Class for terms in the sucessor theory.
//
#ifndef _S_Term_hh_
#define _S_Term_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include <gmpxx.h>
#include "term.hh"

class S_Term : public Term
{
  NO_COPYING(S_Term);

public:
  S_Term(S_Symbol* symbol, const mpz_class& number, Term* arg);
  S_Term(const S_Term& original, SymbolMap* map);
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
  //    Functions specific to S_Term.
  //
  S_Symbol* symbol() const;
  const mpz_class& getNumber() const;
  Term* getArgument() const;

private:
  mpz_class number;
  Term* arg;
  int abstractionVariableIndex;
};

inline S_Symbol*
S_Term::symbol() const
{
  return safeCast(S_Symbol*, Term::symbol());
}

inline const mpz_class&
S_Term::getNumber() const
{
  return number;
}

inline Term*
S_Term::getArgument() const
{
  return arg;
}

#endif
