//
//      Class for symbols for the unary minus operation.
//
#ifndef _minusSymbol_hh_
#define _minusSymbol_hh_
#include "numberOpSymbol.hh"

class MinusSymbol : public NumberOpSymbol
{
public:
  MinusSymbol(int id);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  //
  //	Functions special to MinusSymbol.
  //
  DagNode* makeNegDag(const mpz_class& integer);
  bool isNeg(const DagNode* dagNode) const;
  const mpz_class& getNeg(const DagNode* dagNode, mpz_class& result) const;
  Term* makeIntTerm(const mpz_class& integer);
  bool isNeg(/* const */ Term* term) const;
  const mpz_class& getNeg(/* const */ Term* term, mpz_class& result) const;
};

#endif
