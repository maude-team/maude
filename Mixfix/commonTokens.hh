//
//      Class to hold token codes.
//
#ifndef _commonTokens_hh_
#define _commonTokens_hh_
#ifdef __GNUG__
#pragma interface
#endif

class CommonTokens
{
public:
  CommonTokens();

protected:
  static int leftParen;
  static int rightParen;
  static int leftBracket;
  static int rightBracket;
  static int leftBrace;
  static int rightBrace;
  static int comma;
  static int underscore;
  static int dot;
  static int equals;
  static int assign;
  static int arrow;
  static int arrowOne;
  static int arrowPlus;
  static int arrowStar;
  static int arrowBang;
  static int suchThat;
  static int such;
  static int that;
  static int mb;
  static int cmb;
  static int eq;
  static int ceq;
  static int rl;
  static int crl;
  static int cq;
  static int ifToken;
  static int colon;
  static int colon2;
  static int colon3;
  static int wedge;
  static int label;
  static int metadata;
  static int nonexec;
  static int otherwise;
  static int owise;
};

#endif
