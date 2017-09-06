//
//	Class for symbols belonging to theories made from C, Ul, Ur and I axioms.
//
#ifndef _CUI_Symbol_hh_
#define _CUI_Symbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "binarySymbol.hh"

class CUI_Symbol : public BinarySymbol
{
public:
  enum Axioms
  {
    COMM = 1,		// commutativity
    LEFT_ID = 2,	// left identity
    RIGHT_ID = 4,	// right identity
    IDEM = 8		// idempotence
  };

  CUI_Symbol(int id,
	     const Vector<int>& strategy,
	     bool memoFlag,
	     Axioms axioms,
	     Term* identity = 0);
  //
  //	Member functions required by theory interface.
  //
  Term* makeTerm(const Vector<Term*>& args);
  DagNode* makeDagNode(const Vector<DagNode*>& args);
  void computeBaseSort(DagNode* subject);
  void normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context);
  bool eqRewrite(DagNode* subject, RewritingContext& context);  
  void stackArguments(DagNode* subject,
		      Vector<RedexPosition>& stack,
		      int parentIndex);

  //	Member functions overiding default handling.
  //
  void compileOpDeclarations();
  void postOpDeclarationPass();
  void setFrozen(const NatSet& frozen);
  //
  //	Member function specific to CUI specific function CUI_Symbol.
  //
  bool comm() const;
  bool leftId() const;
  bool rightId() const;
  bool idem() const;

private:
  bool memoStrategy(MemoTable::SourceSet& from, DagNode* subject, RewritingContext& context);

  Axioms axioms;
};

inline bool
CUI_Symbol::comm() const
{
  return axioms & COMM;
}

inline bool
CUI_Symbol::leftId() const
{
  return axioms & LEFT_ID;
}

inline bool
CUI_Symbol::rightId() const
{
  return axioms & RIGHT_ID;
}

inline bool
CUI_Symbol::idem() const
{
  return axioms & IDEM;
}

#endif
