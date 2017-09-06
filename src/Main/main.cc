/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2010 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//	main() function and misc functions.
//
#include "sys/param.h"
#ifdef ALPHA
#include <stropts.h>
#endif

//      utility stuff
#include "macros.hh"
#include "vector.hh"
#include "tty.hh"


//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "freeTheory.hh"
#include "builtIn.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"
 
//      interface class definitions
#include "term.hh"
 
//      core class definitions
#include "lineNumber.hh"

//      built in stuff
#include "randomOpSymbol.hh"

//      system class definitions
#include "IO_Manager.hh"

//	mixfix frontend definitions
#include "token.hh"
#include "userLevelRewritingContext.hh"
#include "fileTable.hh"
#include "directoryManager.hh"
#include "mixfixModule.hh"
#include "interpreter.hh"
#include "global.hh"

#ifdef USE_CVC4
#include "cvc4/expr/expr_manager.h"
#include "cvc4/smt/smt_engine.h"

using namespace CVC4;
#endif

#include "pigPug.hh"
#include "wordLevel.hh"
#include "wordSystem.hh"
void
testPigPug()
{
  PigPug::ConstraintMap m(10);
  for (int i = 0; i < 10; ++i)
    m[i] = NONE;

  const int nrLhs = 3;
  PigPug::Word lhs(nrLhs);
  for (int i = 0; i < nrLhs; ++i)
    lhs[i] = i;

  const int nrRhs = 4;
  PigPug::Word rhs(nrRhs);
  for (int i = 0; i < nrRhs; ++i)
    rhs[i] = nrLhs + (i % 2);
  

  PigPug p(lhs, rhs, m, nrLhs + nrRhs, 100);

  PigPug::Subst s;
  int c = 0;
  while (p.getNextUnifier(s) != NONE)
    {
      cout << "found 1" << endl;
      ++c;
    }
  cout << "total = " << c << endl;
}

void
instantiate(PigPug::Word& inst, const PigPug::Word& original, const PigPug::Subst& s)
{
  FOR_EACH_CONST(i, PigPug::Word, original)
    {
      FOR_EACH_CONST(j, PigPug::Word, s[*i])
	inst.append(*j);
    }
}

bool
equal(const PigPug::Word& w1, const PigPug::Word& w2)
{
  int length = w1.length();
  if (length != w2.length())
    return false;
  for (int i = 0; i < length; ++i)
    {
      if (w1[i] != w2[i])
	return false;
    }
  return true;
}

void
testPigPug2()
{
  PigPug::ConstraintMap m(1000);
  for (int i = 0; i < 1000; ++i)
    m[i] = NONE;


  /*
  PigPug::ConstraintMap m(10);
  for (int i = 0; i < 10; ++i)
    m[i] = NONE;
  m[0] = PigPug::ELEMENT;
  m[1] = PigPug::ELEMENT;

  const int nrLhs = 4;
  PigPug::Word lhs(nrLhs);
  for (int i = 0; i < nrLhs; ++i)
    lhs[i] = i;

  
  const int nrRhs = 4;
  PigPug::Word rhs(nrRhs);
  rhs[0] = nrLhs;
  rhs[1] = 1;
  rhs[2] = nrLhs;
  rhs[3] = 0;
  */

  /*
  const int nrLhs = 3;
  PigPug::Word lhs(nrLhs);
  for (int i = 0; i < nrLhs; ++i)
    lhs[i] = i;

  const int nrRhs = 4;
  PigPug::Word rhs(nrRhs);
  for (int i = 0; i < nrRhs; ++i)
    rhs[i] = nrLhs + (i % 2);
  */
  /*
  const int nrLhs = 5;
  PigPug::Word lhs(nrLhs);
  for (int i = 0; i < nrLhs; ++i)
    lhs[i] = i;
  m[1] = m[3] = PigPug::ELEMENT;

  const int nrRhs = 2;
  PigPug::Word rhs(6);
  rhs[0] = nrLhs;
  rhs[1] = 3;
  rhs[2] = nrLhs + 1;
  rhs[3] = nrLhs;
  rhs[4] = 1;
  rhs[5] = nrLhs + 1;
  */

  /*
  // cause 2^n growth in failure cases without early failure detection
  const int nrLhs = 98;
  PigPug::Word lhs(nrLhs);
  for (int i = 0; i < nrLhs; ++i)
    lhs[i] = i;
  const int nrRhs = 2;
  PigPug::Word rhs(100);
  for (int i = 0; i < 100; ++i)
    rhs[i] = nrLhs + (i % 2);
  m[nrLhs] = m[nrLhs + 1] = PigPug::ELEMENT;
  */

  /*
  const int nrLhs = 100;
  PigPug::Word lhs(nrLhs);
  for (int i = 0; i < nrLhs; ++i)
    {
      lhs[i] = i;
      m[i] = PigPug::ELEMENT;
    }

  const int nrRhs = 35;
  PigPug::Word rhs(80);
  for (int i = 0; i < 80; ++i)
    rhs[i] = nrLhs + (i % 35);
  */

  const int nrLhs = 3;
  PigPug::Word lhs(nrLhs);
  for (int i = 0; i < nrLhs; ++i)
    lhs[i] = i;

  const int nrRhs = 4;
  PigPug::Word rhs(nrRhs);
  for (int i = 0; i < nrRhs; ++i)
    rhs[i] = nrLhs + i;
  

  /*
  const int nrLhs = 2;
  PigPug::Word lhs(nrLhs);
  for (int i = 0; i < nrLhs; ++i)
    lhs[i] = i;

  const int nrRhs = 3;
  PigPug::Word rhs(nrRhs);
  for (int i = 0; i < nrRhs; ++i)
    rhs[i] = nrLhs + (i % 2);
  */

  PigPug p(lhs, rhs, m, nrLhs + nrRhs, 100);

  PigPug::Subst s;
  int c = 0;
  while (p.getNextUnifier(s) != NONE)
    {
     ++c;
      cout << "Solution " << c << endl;
      int nrVariables = s.size();
      for (int i = 0; i < nrVariables; ++i)
	{
	  cout << "  #" << i << " |->";
	  FOR_EACH_CONST(j, PigPug::Word, s[i])
	    cout << " #" << *j;
	  cout << endl;
	}

      PigPug::Word lhsI;
      instantiate(lhsI, lhs, s);
      PigPug::Word rhsI;
      instantiate(rhsI, rhs, s);

      if (equal(lhsI, rhsI))
	{
	  cout << Tty(Tty::GREEN) << "common instantiation:";
	  FOR_EACH_CONST(i, PigPug::Word, lhsI)
	    cout << " #" << *i;
	  cout << Tty(Tty::RESET) << endl;
	}
      else
	{
	  cout << Tty(Tty::RED) << "!! unsound !!" << endl;
	  {
	    cout << "lhsI: ";
	    FOR_EACH_CONST(i, PigPug::Word, lhsI)
	      cout << " #" << *i;
	    cout << endl;
	  }
	  {
	    cout << "rhsI: ";
	    FOR_EACH_CONST(i, PigPug::Word, rhsI)
	      cout << " #" << *i;
	    cout << Tty(Tty::RESET) << endl;
	  }
	}
      cout << endl;
 
    }
  cout << "total = " << c << endl;
}

#ifdef USE_CVC4
void
testCVC4()
{
  ExprManager em;
  SmtEngine smt(&em);
  Expr onePlusTwo = em.mkExpr(kind::PLUS,
                              em.mkConst(Rational(1)),
                              em.mkConst(Rational(2)));
  std::cout << Expr::setlanguage(language::output::LANG_CVC4)
            << smt.getInfo("name")
            << " says that 1 + 2 = "
            << smt.simplify(onePlusTwo)
            << std::endl;
}

void
test2()
{
  ExprManager em;
  Expr helloworld = em.mkVar("Hello World!", em.booleanType());
  SmtEngine smt(&em);
  std::cout << helloworld << " is " << smt.query(helloworld) << std::endl;
}

void
test3()
{
  ExprManager em;
  SmtEngine smt(&em);
  smt.setOption("incremental", SExpr("true"));  // Enable incremental solving

  Type real = em.realType();
  Type integer = em.integerType();

  Expr x = em.mkVar("x", integer);
  Expr y = em.mkVar("y", real);

  Expr three = em.mkConst(Rational(3));
  Expr neg2 = em.mkConst(Rational(-2));
  Expr two_thirds = em.mkConst(Rational(2,3));

  Expr three_y = em.mkExpr(kind::MULT, three, y);  // 3y
  Expr diff = em.mkExpr(kind::MINUS, y, x);  // y - x

  Expr x_geq_3y = em.mkExpr(kind::GEQ, x, three_y);  // x >= 3y
  Expr x_leq_y = em.mkExpr(kind::LEQ, x, y);  // x <= y
  Expr neg2_lt_x = em.mkExpr(kind::LT, neg2, x);  // -2 < x

  Expr assumptions = em.mkExpr(kind::AND, x_geq_3y, x_leq_y, neg2_lt_x);  // x >= 3y /\ x <= y /\ -2 < x
  smt.assertFormula(assumptions);

  //smt.push();
  Expr diff_leq_two_thirds = em.mkExpr(kind::LEQ, diff, two_thirds);   // y - x <= 2/3
  cout << "Prove that " << diff_leq_two_thirds << " with CVC4." << endl;
  cout << "CVC4 should report VALID." << endl;
  cout << "Result from CVC4 is: " << smt.query(diff_leq_two_thirds) << endl;
  //smt.pop();

  smt.push();
  Expr diff_is_two_thirds = em.mkExpr(kind::EQUAL, diff, two_thirds);  // y - x = 2/3
  smt.assertFormula(diff_is_two_thirds);
  cout << "Show that the asserts are consistent with " << endl;
  cout << diff_is_two_thirds << " with CVC4." << endl;
  cout << "CVC4 should report SAT." << endl;
  cout << "Result from CVC4 is: " << smt.checkSat(em.mkConst(true)) << endl;
  smt.pop();

}


void
test4()
{
  ExprManager em;
  SmtEngine smt(&em);
  smt.setOption("incremental", SExpr("true"));  // Enable incremental solving

  Type integer = em.integerType();

  Expr x = em.mkVar("x", integer);
  Expr y = em.mkVar("y", integer);
  
  Expr x_geq_y = em.mkExpr(kind::GEQ, x, y);
  Expr max_x_y = em.mkExpr(kind::ITE, x_geq_y, x, y);

  Expr max_x_y_geq_x = em.mkExpr(kind::GEQ, max_x_y, x);

  cout << "valid = " << smt.query(max_x_y_geq_x) << endl;

  smt.push();
  smt.assertFormula(max_x_y_geq_x);
  cout << "sat = " << smt.checkSat(em.mkConst(true)) << endl;
  smt.pop();

}
#endif

void
testWordLevel()
{
  WordLevel l(10, 1);
  for (int i = 0; i < 5; ++i)
    l.addConstraint(i, NONE);
  for (int i = 5; i < 7; ++i)
    l.addConstraint(i, PigPug::ELEMENT);
  for (int i = 7; i < 10; ++i)
    l.addConstraint(i, i);

  WordLevel::Word w0;
  w0.append(3); w0.append(6);
  l.addAssignment(0, w0);

  WordLevel::Word w2;
  w2.append(4); w2.append(7); w2.append(4);
  l.addAssignment(2, w2);

  WordLevel::Word w6;
  w6.append(8);
  l.addAssignment(6, w6);

  WordLevel::Word l0;
  l0.append(0); l0.append(1);
  WordLevel::Word r0;
  r0.append(2); r0.append(2);
  l.addEquation(0, l0, r0);

  l.dump(cout);
  cout << "simplify returns " << l.simplify() << endl;
  l.dump(cout);
}

void
testWordLevel2()
{
  WordLevel l(10, 1);
  for (int i = 0; i < 5; ++i)
    l.addConstraint(i, NONE);
  for (int i = 5; i < 7; ++i)
    l.addConstraint(i, PigPug::ELEMENT);
  for (int i = 7; i < 10; ++i)
    l.addConstraint(i, i);

  WordLevel::Word w0;
  w0.append(1); w0.append(2);
  l.addAssignment(0, w0);

  WordLevel::Word w1;
  w1.append(7); w1.append(8);
  l.addAssignment(1, w1);

  WordLevel::Word w2;
  w2.append(8); w2.append(8);
  l.addAssignment(2, w2);

  WordLevel::Word w3;
  w3.append(0); w3.append(4);
  l.addAssignment(3, w3);

  WordLevel::Word w4;
  w4.append(5); w4.append(0);
  l.addAssignment(4, w4);


  WordLevel::Word l0;
  l0.append(5); l0.append(6);
  WordLevel::Word r0;
  r0.append(8); r0.append(9);
  l.addEquation(0, l0, r0);

  l.dump(cout);
  cout << "simplify returns " << l.simplify() << endl;
  l.dump(cout);
}

void
testWordLevel3()
{
  WordLevel l(10, 3);
  for (int i = 0; i < 5; ++i)
    l.addConstraint(i, NONE);
  for (int i = 5; i < 7; ++i)
    l.addConstraint(i, PigPug::ELEMENT);
  for (int i = 7; i < 10; ++i)
    l.addConstraint(i, i);

  WordLevel::Word l0;
  l0.append(1); l0.append(1); l0.append(3);
  WordLevel::Word r0;
  r0.append(2); r0.append(4); r0.append(4);
  l.addEquation(0, l0, r0);

  WordLevel::Word l1;
  l1.append(0); l1.append(1);
  WordLevel::Word r1;
  r1.append(5); r1.append(2);
  l.addEquation(1, l1, r1);

  WordLevel::Word l2;
  l2.append(0); l2.append(5);
  WordLevel::Word r2;
  r2.append(6); r2.append(7);
  l.addEquation(2, l2, r2);


  l.dump(cout);
  cout << "simplify returns " << l.simplify() << endl;
  l.dump(cout);
}

void
testWordLevel4()
{
  WordLevel l(10, 1);
  for (int i = 0; i < 5; ++i)
    l.addConstraint(i, NONE);
  for (int i = 5; i < 7; ++i)
    l.addConstraint(i, PigPug::ELEMENT);
  for (int i = 7; i < 10; ++i)
    l.addConstraint(i, i);
  //
  //	x8 x0 =? x9 x1 theory clash
  //
  WordLevel::Word l0;
  l0.append(8); l0.append(0);
  WordLevel::Word r0;
  r0.append(9); r0.append(1);
  l.addEquation(0, l0, r0);

  l.dump(cout);
  cout << "simplify returns " << l.simplify() << endl;
  l.dump(cout);
}

void
testWordLevel5()
{
  WordLevel l(10, 1);
  for (int i = 0; i < 5; ++i)
    l.addConstraint(i, NONE);
  for (int i = 5; i < 7; ++i)
    l.addConstraint(i, PigPug::ELEMENT);
  for (int i = 7; i < 10; ++i)
    l.addConstraint(i, i);
  //
  //  x0 |-> x1 x2
  //  x1 |-> x2 x3
  //  x2 |-> x3 x0
  //
  WordLevel::Word w0;
  w0.append(1); w0.append(2);
  l.addAssignment(0, w0);

  WordLevel::Word w1;
  w1.append(2); w1.append(3);
  l.addAssignment(1, w1);

  WordLevel::Word w2;
  w2.append(3); w2.append(0);
  l.addAssignment(2, w2);
  //
  // x0 x3 =? x1 x4
  //
  WordLevel::Word l0;
  l0.append(0); l0.append(3);
  WordLevel::Word r0;
  r0.append(1); r0.append(4);
  l.addEquation(0, l0, r0);
  l.dump(cout);
  cout << "simplify returns " << l.simplify() << endl;
  l.dump(cout);
}

void
testWordLevel6()
{
  WordLevel l(10, 1);
  for (int i = 0; i < 5; ++i)
    l.addConstraint(i, NONE);
  for (int i = 5; i < 7; ++i)
    l.addConstraint(i, PigPug::ELEMENT);
  for (int i = 7; i < 10; ++i)
    l.addConstraint(i, i);
  //
  //  x0 |-> x1 x2
  //  x1 |-> x2 x3
  //  x2 |-> x3 x0
  //
  WordLevel::Word w0;
  w0.append(1); w0.append(4);
  l.addAssignment(0, w0);

  WordLevel::Word w1;
  w1.append(2); w1.append(3);
  l.addAssignment(1, w1);

  WordLevel::Word w2;
  w2.append(3); w2.append(0);
  l.addAssignment(2, w2);
  //
  // x0 x3 =? x1 x4
  //
  WordLevel::Word l0;
  l0.append(0); l0.append(3);
  WordLevel::Word r0;
  r0.append(1); r0.append(4);
  l.addEquation(0, l0, r0);
  l.dump(cout);
  cout << "simplify returns " << l.simplify() << endl;
  l.dump(cout);
}

void
testWordLevel7()
{
  WordLevel l(10, 1);
  for (int i = 0; i < 5; ++i)
    l.addConstraint(i, NONE);
  for (int i = 5; i < 7; ++i)
    l.addConstraint(i, PigPug::ELEMENT);
  for (int i = 7; i < 10; ++i)
    l.addConstraint(i, i);
  //
  // x5 x0 =? x7 x1 x0 x2
  //
  WordLevel::Word l0;
  l0.append(5); l0.append(0);
  WordLevel::Word r0;
  r0.append(7); r0.append(1); r0.append(0); r0.append(2);
  l.addEquation(0, l0, r0);
  l.dump(cout);
  cout << "simplify returns " << l.simplify() << endl;
  l.dump(cout);
}

void
testWordLevel8()
{
  WordLevel l(10, 1);
  for (int i = 0; i < 5; ++i)
    l.addConstraint(i, NONE);
  for (int i = 5; i < 7; ++i)
    l.addConstraint(i, PigPug::ELEMENT);
  for (int i = 7; i < 10; ++i)
    l.addConstraint(i, i);
  //
  // x5 x6 =? x7 x0 x2
  //
  WordLevel::Word l0;
  l0.append(5); l0.append(6);
  WordLevel::Word r0;
  r0.append(7); r0.append(0); r0.append(2);
  l.addEquation(0, l0, r0);
  l.dump(cout);
  cout << "simplify returns " << l.simplify() << endl;
  l.dump(cout);
}

void
testWordSystem1()
{
  WordSystem s(10, 2);
  for (int i = 0; i < 10; ++i)
    s.addConstraint(i, NONE);
 
  WordLevel::Word l0;
  l0.append(0); l0.append(1);
  WordLevel::Word r0;
  r0.append(2); r0.append(3);
  s.addEquation(0, l0, r0);

  WordLevel::Word r1;
  r1.append(4); r1.append(5);
  s.addEquation(1, l0, r1);

  int solNr = 0;
  while(s.findNextSolution())
    {
      cout << "Solution " << ++solNr << endl;
      for (int i = 0; i <= 5; ++i)
	{
	  cout << "x" << i << " |-> ";
	  const WordSystem::Word& w = s.getAssignment(i);
	  FOR_EACH_CONST(j, WordSystem::Word, w)
	    cout << " x" << *j;
	  cout << endl;
	}
    }
  cout << "no more solutions" << endl;
}

void
testWordSystem2()
{
  WordSystem s(10, 2);
  for (int i = 0; i < 10; ++i)
    s.addConstraint(i, NONE);
 
  WordLevel::Word l0;
  l0.append(0); l0.append(1);
  WordLevel::Word r0;
  r0.append(2); r0.append(3); r0.append(2);
  s.addEquation(0, l0, r0);

  WordLevel::Word l1;
  l1.append(4); l1.append(5);
  WordLevel::Word r1;
  r1.append(0); r1.append(3); r1.append(1);
  s.addEquation(1, l1, r1);

  int solNr = 0;
  while(s.findNextSolution())
    {
      cout << "Solution " << ++solNr << endl;
      for (int i = 0; i <= 5; ++i)
	{
	  cout << "x" << i << " |-> ";
	  const WordSystem::Word& w = s.getAssignment(i);
	  FOR_EACH_CONST(j, WordSystem::Word, w)
	    cout << " x" << *j;
	  cout << endl;
	}
    }
  cout << "no more solutions" << endl;
}


int
main(int argc, char* argv[])
{
  //testWordSystem2(); exit(0);
  //void testSeq();

  //testPigPug2();
  //testSeq();
  //testCVC4();
  //test2();
  //test3();
  //test4();
  //
  //	Global function declatations
  //
  void printBanner(ostream& s);
  void printHelp(const char* name);
  void printVersion();
  void createRootBuffer(FILE* fp, bool forceInteractive);
  bool includeFile(const string& directory, const string& fileName, bool silent, int lineNr);
  extern Vector<char*> pendingFiles;
  const char* isFlag(const char* arg, const char* flag);
  bool findExecutableDirectory(string& directory, string& executable);
  bool findPrelude(string& directory, string& fileName);
  void checkForPending();

  bool lineWrapping = true;
  bool handleCtrlC = true;
  bool readPrelude = true;
  bool forceInteractive = false;
  bool outputBanner = true;
  int ansiColor = UNDECIDED;
  int useTecla = UNDECIDED;

  for (int i = 1; i < argc; i++)
    {
      char* arg = argv[i];
      if (arg[0] == '-')
	{
	  if (const char* s = isFlag(arg, "-xml-log="))
	    interpreter.beginXmlLog(s);
	  else if (const char* s = isFlag(arg, "-random-seed="))
	    RandomOpSymbol::setGlobalSeed(strtoul(s, 0, 0));
	  else if (strcmp(arg, "--help") == 0)
	    printHelp(argv[0]);
	  else if (strcmp(arg, "--version") == 0)
	    printVersion();
	  else if (strcmp(arg, "-no-mixfix") == 0)
	    interpreter.setPrintFlag(Interpreter::PRINT_MIXFIX, false);
	  else if (strcmp(arg, "-ansi-color") == 0)
	    ansiColor = true;
	  else if (strcmp(arg, "-no-ansi-color") == 0)
	    ansiColor = false;
	  else if (strcmp(arg, "-tecla") == 0)
	    useTecla = true;
	  else if (strcmp(arg, "-no-tecla") == 0)
	    useTecla = false;
	  else if (strcmp(arg, "-no-prelude") == 0)
	    readPrelude = false;
	  else if (strcmp(arg, "-no-banner") == 0)
	    outputBanner = false;
	  else if (strcmp(arg, "-no-advise") == 0)
	    {
	      if (!alwaysAdviseFlag)
		globalAdvisoryFlag = false;
	    }
	  else if (strcmp(arg, "-always-advise") == 0)
	    {
	      alwaysAdviseFlag = true;
	      globalAdvisoryFlag = true;
	    }
	  else if (strcmp(arg, "-no-wrap") == 0)
	    lineWrapping = false;
	  else if (strcmp(arg, "-batch") == 0)
	    handleCtrlC = false;
	  else if (strcmp(arg, "-interactive") == 0)
	    forceInteractive = true;
	  else
	    {
	      IssueWarning(LineNumber(FileTable::COMMAND_LINE) <<
			   ": unrecognised flag: " << QUOTE(arg));
	    }
	}
      else
	pendingFiles.append(arg);
    }

  if (lineWrapping)
    ioManager.setAutoWrap();

  if (ansiColor == UNDECIDED)
    {
      //
      //	By default we allow ANSI escape codes unless
      //	environment variable TERM is set to dumb; or
      //	our standard output is not a terminal.
      //
      ansiColor = true;
      const char* term = getenv("TERM");
      if ((term != 0 && strcmp("dumb", term) == 0) ||
	  isatty(STDOUT_FILENO) == 0)
	ansiColor = false;
    }
  Tty::setEscapeSequencesAllowed(ansiColor);

  if (useTecla == UNDECIDED)
    {
      //
      //	By default we use tecla for input unless
      //	environment variable TERM is set to emacs or dumb;
      //	or our standard input is not a terminal.
      //
      useTecla = true;
      const char* term = getenv("TERM");
      if ((term != 0 && (strcmp("emacs", term) == 0 ||
			 strcmp("dumb", term) == 0)) ||
	  isatty(STDIN_FILENO) == 0)
	useTecla = false;
    }

  if (outputBanner)
    printBanner(cout);
  createRootBuffer(stdin, forceInteractive);
  UserLevelRewritingContext::setHandlers(handleCtrlC);
  if (useTecla)
    ioManager.setCommandLineEditing();
  directoryManager.initialize();
  string executable(argv[0]);
  findExecutableDirectory(executableDirectory, executable);
  if (readPrelude)
    {
      string directory;
      string fileName(PRELUDE_NAME);
      if (findPrelude(directory, fileName))
	includeFile(directory, fileName, true, FileTable::AUTOMATIC);
    }
  else
    checkForPending();  // because we won't hit an EOF
  (void) UserLevelRewritingContext::commandLoop();
  return 0;
}

ostream& operator<<(ostream& s, const LineNumber& lineNumber)
{
  fileTable.printLineNumber(s, lineNumber.getLineNumber());
  return s;
}

const char*
isFlag(const char* arg, const char* flag)
{
  char f;
  do
    {
      f = *flag++;
      if (f == 0)
        return arg;
    }
  while (f == *arg++);
  return 0;
}

void
printHelp(const char* name)
{
  cout <<
    "Maude interpreter\n" <<
    "Usage: " << name << " [options] [files]\n" <<
    "Options:\n" <<
    "  --help\t\tDisplay this information\n" <<
    "  --version\t\tDisplay version number\n" <<
    "  -no-prelude\t\tDo not read in the standard prelude\n" <<
    "  -no-banner\t\tDo not output banner on startup\n" <<
    "  -no-advise\t\tNo advisories on startup\n" <<
    "  -always-advise\t\tAlways show advisories regardless" <<
    "  -no-mixfix\t\tDo not use mixfix notation for output\n" <<
    "  -no-wrap\t\tDo not automatic line wrapping for output\n" <<
    "  -ansi-color\t\tUse ANSI control sequences\n" <<
    "  -no-ansi-color\tDo not use ANSI control sequences\n" <<
    "  -tecla\t\tUse tecla command line editing\n" <<
    "  -no-tecla\t\tDo not use tecla command line editing\n" <<
    "  -batch\t\tRun in batch mode\n" <<
    "  -interactive\t\tRun in interactive mode\n" <<
    "  -random-seed=<int>\tSet seed for random number generator\n" <<
    "  -xml-log=<filename>\tSet file in which to produce an xml log\n" <<
    "\n" <<
    "Send bug reports to: " << PACKAGE_BUGREPORT << endl;
  exit(0);
}

void
printVersion()
{
  cout << PACKAGE_VERSION << endl;
  exit(0);
}

bool
findExecutableDirectory(string& directory, string& executable)
{
  string::size_type p = executable.rfind('/');
  if (p == string::npos)
    return directoryManager.searchPath("PATH", directory, executable, X_OK);
  else
    {
      directoryManager.realPath(executable.substr(0, p), directory);
      return directoryManager.checkAccess(directory, executable, X_OK);
    }
}

bool
findPrelude(string& directory, string& fileName)
{
  if (directoryManager.searchPath(MAUDE_LIB, directory, fileName, R_OK))
    return true;
  if (!(executableDirectory.empty()) &&
      directoryManager.checkAccess(executableDirectory, fileName, R_OK))
    {
      directory = executableDirectory;
      return true;
    }
  if (directoryManager.checkAccess(".", fileName, R_OK))
    {
      directory = ".";
      return true;
    }
  IssueWarning(LineNumber(FileTable::AUTOMATIC) <<
	       ": unable to locate file: " << QUOTE(fileName));
  return false;
}

#include "sequenceAssignment.hh"

int delannoy(int m, int n);
int countAssignments(int nrLhsVars, int nrRhsVars);

void
testSeq()
{
  int lhsMax = 10;
  int rhsMax = 10;

  for (int i = 0; i < lhsMax; ++i)
    {
      for (int j = 0; j < rhsMax; ++j)
	{
	  int d = delannoy(i, j);
	  int a = countAssignments(i + 1, j + 1);
	  if (a == d)
	    cout << "correct " << d << endl;
	  else
	    cout << "fail " << a << " vs " << d << endl;
	}
      cout << endl;
    }
}


int
countAssignments(int nrLhsVars, int nrRhsVars)
{
  SequenceAssignment s(nrLhsVars, nrRhsVars);

  int nrSols = 0;
  while (s.findNextSolution(nrSols == 0))
    ++nrSols;

  return nrSols;
}

  /*
  int nrLhsVars = 5;
  int nrRhsVars = 4;

  SequenceAssignment s(nrLhsVars, nrRhsVars);

  s.setLhsBound(2, 1);
  s.setRhsBound(1, 1);
  s.setRhsBound(2, 1);

  int solNr = 1;
  while (s.findNextSolution())
    {
      Vector<Vector<int> > lhsAssign(nrLhsVars);
      Vector<Vector<int> > rhsAssign(nrRhsVars);

      int freeVarIndex = 0;
      int lIndex = 0;
      int rIndex = 0;

      lhsAssign[lIndex].append(freeVarIndex);
      rhsAssign[rIndex].append(freeVarIndex);

      const SequenceAssignment::Solution& sol = s.getSolution();
      cout << "(sol " << solNr << ") ";
      FOR_EACH_CONST(i, SequenceAssignment::Solution, sol)
	{
	  cout << " " << *i;
	  ++freeVarIndex;
	  lIndex += SequenceAssignment::leftDelta(*i);
	  rIndex += SequenceAssignment::rightDelta(*i);
	  lhsAssign[lIndex].append(freeVarIndex);
	  rhsAssign[rIndex].append(freeVarIndex);
	}
      cout << endl;
      {
	int v = 0;
	FOR_EACH_CONST(j, Vector<Vector<int> >, lhsAssign)
	  {
	    cout << "L" << v << " <-";
	    FOR_EACH_CONST(k, Vector<int>, *j)
	      cout << " X" << *k;
	    cout << endl;
	    ++v;
	  }
      }
      {
	int v = 0;
	FOR_EACH_CONST(j, Vector<Vector<int> >, rhsAssign)
	  {
	    cout << "R" << v << " <-";
	    FOR_EACH_CONST(k, Vector<int>, *j)
	      cout << " X" << *k;
	    cout << endl;
	    ++v;
	  }
      }

      cout << endl;
      ++solNr;
    }
  */

#include <map>

int
delannoy(int m, int n)
{
  typedef pair<int, int> Pair;
  typedef map<Pair, int> Memo;
  static Memo memo;

  if (m == 0 || n == 0)
    return 1;

  Pair p(m, n);
  Memo::const_iterator i = memo.find(p);
  if (i != memo.end())
    return i->second;

  int d = delannoy(m - 1, n) + delannoy(m - 1, n - 1) + delannoy(m, n - 1);
  memo.insert(Memo::value_type(p, d));
  return d;
}

