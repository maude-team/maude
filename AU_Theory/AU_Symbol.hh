//
//	Class for symbols belonging to the A, AUl, AUr and AU theories.
//
#ifndef _AU_Symbol_hh_
#define _AU_Symbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "associativeSymbol.hh"

class AU_Symbol : public AssociativeSymbol
{
public:
  AU_Symbol(int id,
	    const Vector<int>& strategy,
	    bool memoFlag,
	    bool leftId = false,
	    bool rightId = false,
	    Term* identity = 0);
  //
  //    Member functions required by theory interface.
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
  //    Member functions overiding default handling.
  //
  void postOpDeclarationPass();
  //
  //	Member functions particular to AU_Symbol.
  //
  bool leftId() const;
  bool rightId() const;
  bool oneSidedId() const;
  int calculateNrSubjectsMatched(DagNode* d,
				 bool leftEnd,  // match starts at left extreme
				 bool rightEnd,  // match end at right extreme
				 bool& nasty);

private:
  bool memoStrategy(MemoTable::SourceSet& from, DagNode* subject, RewritingContext& context);
  void copyAndReduceSubterms(AU_DagNode* subject, RewritingContext& context);

  const Bool leftIdFlag;
  const Bool rightIdFlag;
  const Bool oneSidedIdFlag;
};

inline bool
AU_Symbol::leftId() const
{
  return leftIdFlag;
}

inline bool
AU_Symbol::rightId() const
{
  return rightIdFlag;
}

inline bool
AU_Symbol::oneSidedId() const
{
  return oneSidedIdFlag;
}

#endif
