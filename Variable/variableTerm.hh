//
//	Class for variable terms.
//
#ifndef _variableTerm_hh_
#define _variableTerm_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "term.hh"
#include "namedEntity.hh"
#include "variableSymbol.hh"

class VariableTerm : public Term, public NamedEntity
{
  NO_COPYING(VariableTerm);

public:
  VariableTerm(VariableSymbol* symbol, int name);

  RawArgumentIterator* arguments();
  void deepSelfDestruct();
  Term* deepCopy2(SymbolMap* map) const;
  Term* normalize(bool full, bool& changed);
  int compareArguments(const Term* other) const;
  int compareArguments(const DagNode* other) const;
  void findEagerVariables(bool atTop, NatSet& eagerVariables) const;
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

  //
  //	Optional stuff that is easy to define for variable terms.
  //
  bool subsumes(const Term* other, bool sameVariableSet) const;
  //
  //	Functions particular to variable terms.
  //
  Sort* getSort() const;
  int getIndex() const;
  void setIndex(int indx);

private:
  int index;
};

inline Sort*
VariableTerm::getSort() const
{
  return safeCast(VariableSymbol*, symbol())->getSort();
}

inline int
VariableTerm::getIndex() const
{
  return index;
}

inline void
VariableTerm::setIndex(int indx)
{
  index = indx;
}

#endif
