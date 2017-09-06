/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

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
//	Class to solve Diophantine systems associated with AC and ACU unification.
//
//	This version works over bignums and uses the integer Gaussian elimination and
//	extended GCD algorithms to search for solution.
//
//
#include <list>
#include "gmpxx.h"
#include "natSet.hh"

#ifndef _diophantineSystem3_hh_
#define _diophantineSystem3_hh_

class DiophantineSystem3
{
public:
  typedef Vector<mpz_class> IntVec;

  DiophantineSystem3();

  void insertEqn(const IntVec& eqn);
  void setUpperBounds(const IntVec& bounds);
  bool findNextMinimalSolution(IntVec& solution);

private:
  typedef list<IntVec> VecList;

  struct StackEntry
  {
    mpz_class inc;
    mpz_class bound;
    bool zeroSoFar;
  };

  void initialize();
  void integerGaussianElimination();
  void dumpEqns();
  void swapVariables(int u, int v);
  bool solve(mpz_class a,
	     mpz_class b,
	     mpz_class c,
	     bool y_nonneg,
	     const mpz_class& x_bound,
	     const mpz_class& y_bound,
	     mpz_class& x_base,
	     mpz_class& y_base,
	     mpz_class& x_inc,
	     mpz_class& y_inc,
	     mpz_class& bound);
  void takeStep(int varNr,
		mpz_class leftOver,
		const IntVec& residues,
		IntVec& solution,
		bool zeroSoFar);
  void finalStep(mpz_class leftOver,
		 const IntVec& residues,
		 IntVec& solution,
		 bool zeroSoFar);
  bool concensus(const mpz_class& a, const mpz_class& b, const mpz_class& u,
		 const mpz_class& c, const mpz_class& d, const mpz_class& v,
		 mpz_class& e, mpz_class& f, mpz_class& w);
  bool greaterEqual(const IntVec& arg1, const IntVec& arg2);
  bool minimal(const IntVec& arg);


  bool nextSolution(bool first);
  bool fillOutStackEntry(int varNr);
  bool fillOutLastEntry();
  bool solveDiagonal();

  int nrEqns;				// number of equations
  int nrVars;				// number of variables
  VecList eqns;
  IntVec upperBounds;

  Vector<StackEntry> stack;
  IntVec solution;
  IntVec residues;
  mpz_class leftOver;

  mpz_class sumBound;			// bound on sum of components for a minimal solution
  VecList gcds;
  Vector<int> permutation;		// for full pivoting
  VecList solutions;
  Vector<int> lastPrediagNeg;		// index last prediagonal -ve entry in each equation
  Vector<int> lastPrediagNonzero;	// index last prediagonal nonzero entry in each equation
  int firstPrunablePrediag;		// prediagonal greater or equal to this can take one of at most 2 values
  bool pruneLastPrediag;		// true if last prediagonal column is all -ve
};

#endif
