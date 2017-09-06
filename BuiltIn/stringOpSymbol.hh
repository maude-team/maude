//
//      Class for symbols for built in operations on strings.
//
#ifndef _stringOpSymbol_hh_
#define _stringOpSymbol_hh_
#ifdef LIBv3
#include <ext/rope>
#else
#include <rope>
#endif
#include "freeSymbol.hh"
#include "cachedDag.hh"

class StringOpSymbol : public FreeSymbol
{
public:
  StringOpSymbol(int id, int arity);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  bool attachTerm(const char* purpose, Term* term);
  void copyAttachments(Symbol* original, SymbolMap* map);

  bool eqRewrite(DagNode* subject, RewritingContext& context);
  void postInterSymbolPass();
  void reset();

private:
  enum
  {
    //
    //	Tha actual maximum number of significant digits in the exact
    //	decimal represention of a IEEE-754 double is hard to calculate
    //	but must be < 1074 since there can be at most 1074 binary places
    //	and with 1074 binary places the first multiplications will produce
    //	leading zeros.
    //
    MAX_FLOAT_DIGITS = 1074
  };
  bool rewriteToString(DagNode* subject, RewritingContext& context, const crope& result);
  static bool ropeToNumber(const crope& subject,
			   int base,
			   mpz_class& numerator,
			   mpz_class& denominator);
  static crope substring(const crope& subject, crope::size_type index, crope::size_type length);
  static int fwdFind(const crope& subject, const crope& pattern, crope::size_type start);
  static int revFind(const crope& subject, const crope& pattern, crope::size_type start);

  int op;
  StringSymbol* stringSymbol;
  SuccSymbol* succSymbol;
  MinusSymbol* minusSymbol;
  DivisionSymbol* divisionSymbol;
  FloatSymbol* floatSymbol;
  Symbol* decFloatSymbol;
  CachedDag trueTerm;
  CachedDag falseTerm;
  CachedDag notFoundTerm;
};

#endif
