//
//	Abstract base class for terms in the NA theory.
//
#ifndef _NA_Term_hh_
#define _NA_Term_hh_
#include "term.hh"

class NA_Term : public Term
{
public:
  NA_Term(NA_Symbol* symbol);
  //
  //    Functions required by theory interface.
  //
  //	The following functions are left to the derived class to handle:
  //
  //	int compareArguments(const Term* other) const
  //	int compareArguments(const DagNode* other) const
  //
  RawArgumentIterator* arguments();
  void deepSelfDestruct();
  void findEagerVariables(bool atTop, NatSet& eagerVariables) const;
  void analyseConstraintPropagation(NatSet& BoundUniquely) const;
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
  //	The following pure virtual functions are particular to NA_Term
  //	and must be defined by the derived class.
  //
  virtual void overwriteWithDagNode(DagNode* old) const = 0;
  virtual NA_DagNode* makeDagNode() const = 0;
};

#endif
