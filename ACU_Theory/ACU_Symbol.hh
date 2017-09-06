//
//	Class for symbols belonging to the AC and ACU theories.
//
#ifndef _ACU_Symbol_hh_
#define _ACU_Symbol_hh_
#include "associativeSymbol.hh"

class ACU_Symbol : public AssociativeSymbol
{
public:
  ACU_Symbol(int id,
	     const Vector<int>& strategy = standard,
	     bool memoFlag = false,
	     Term* identity = 0);
  //
  //	Member functions required by theory interface.
  //
  Term* makeTerm(const Vector<Term*>& args);
  DagNode* makeDagNode(const Vector<DagNode*>& args);
  void computeBaseSort(DagNode* subject);
  void normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context);
  bool eqRewrite(DagNode* subject, RewritingContext& context);  
  DagNode* ruleRewrite(DagNode* subject, RewritingContext& context);
  void stackArguments(DagNode* subject,
		      Vector<RedexPosition>& stack,
		      int parentIndex);
  //
  //	Member functions overiding default handling.
  //
  void compileOpDeclarations();
  void postOpDeclarationPass();

  //
  //	ACU_Symbol specific functions.
  //
  int computeSortIndex(int index1, int index2);
  int computeMultSortIndex(int index1, int index2, int multiplicity);

protected:
  //
  //	For use in derived classes that override eqRewrite() so
  //	they don't have to known about the complexities of normalization.
  //	Only supports standard strategy; does not support memoization.
  //
  bool reduceArgumentsAndNormalize(DagNode* subject, RewritingContext& context);
  //
  //	Alow derived classes to make our dag nodes with resonable efficiency.
  //
  DagNode* makeDagNode(const Vector<DagNode*>& args,
		       const Vector<int>& multiplicities);

private:
  bool rewriteAtTop(DagNode* subject, RewritingContext& context);
  bool complexStrategy(DagNode* subject, RewritingContext& context);
  bool memoStrategy(MemoTable::SourceSet& from, DagNode* subject, RewritingContext& context);
  void copyAndReduceSubterms(ACU_DagNode* subject, RewritingContext& context);
};

inline int
ACU_Symbol::computeSortIndex(int index1, int index2)
{
  return traverse(traverse(0, index1), index2);
}

inline int
ACU_Symbol::computeMultSortIndex(int index1, int index2, int multiplicity)
{
  while (multiplicity > 0)
    {
      if (multiplicity & 1)
	index1 = computeSortIndex(index1, index2);
      multiplicity >>= 1;
      index2 = computeSortIndex(index2, index2);
    }
  return index1;
}

#endif
