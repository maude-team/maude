//
//	Class for symbols belonging to the successor theory.
//
#ifndef _S_Symbol_hh_
#define _S_Symbol_hh_
#include "symbol.hh"

class S_Symbol : public Symbol
{
public:
  S_Symbol(int id, const Vector<int>& strategy = standard, bool memoFlag = false);
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
  //    Member function overiding default handling.
  //
  void compileOpDeclarations();
  //
  //	Member function specific to S_Symbol.
  //
  bool mightCollapseToOurSymbol(const Term* subterm) const;

private:
  struct SortPath
  {
    Vector<int> sortIndices;
    int leadLength;
  };

  void computePath(int sortIndex, SortPath& path);
  void memoStrategy(MemoTable::SourceSet& from,
		    DagNode* subject,
		    RewritingContext& context);
  
  Vector<SortPath> sortPathTable;
};

#endif
