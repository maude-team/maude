//
//	Class for formulae in some propositional logic.
//
#ifndef _logicFormula_hh_
#define _logicFormula_hh_
#ifdef __GNUG__
#pragma interface
#endif

class LogicFormula
{
public:
  enum Op
  {
    //
    //	Primitive
    //
    PROPOSITION,
    TRUE,
    FALSE,
    //
    //	Unary
    //
    NOT,
    NEXT,
    //
    //	Binary
    //
    AND,
    OR,
    UNTIL,
    RELEASE
  };

  int makeProp(int propIndex);
  int makeOp(Op op, int firstArg = NONE, int secondArg = NONE);

  int getProp(int nodeNr) const;
  Op getOp(int nodeNr) const;
  int getArg(int nodeNr, int argNr = 0) const;
  bool isPropositional(int nodeNr) const;
  /*
  bool structuallyImplies(const NatSet& now, const NatSet& next, int candidate) const;
  bool structuallyContradicts(const NatSet& now, const NatSet& next, int candidate) const;
  bool containsNegation(const NatSet& indexSet, int formulaIndex) const;
  bool isNegation(int f1, int f2) const;
  */
  void dump(ostream& s);

private:
  struct Node
  {
    short op;
    Bool propositional;
    int args[2];
  };

  Vector<Node> nodes;
};

inline LogicFormula::Op
LogicFormula::getOp(int nodeNr) const
{
  return static_cast<Op>(nodes[nodeNr].op);
}

inline int
LogicFormula::getProp(int nodeNr) const
{
  return nodes[nodeNr].args[0];
}

inline int
LogicFormula::getArg(int nodeNr, int argNr) const
{
  return nodes[nodeNr].args[argNr];
}

inline bool
LogicFormula::isPropositional(int nodeNr) const
{
  return nodes[nodeNr].propositional;
}

#endif
