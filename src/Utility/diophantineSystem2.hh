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
//	Based on:
//	  Evelyn Contejean and Herve Devie,
//	  "An efficient incremental algorithm for solving systems of linear diophantine equations",
//	  Information and Computation 113, pp143-172, 1994.
//
//	We use the non-incremental version of their algorithm with the >q ordering.
//
#include <list>
#include "natSet.hh"

#ifndef _diophantineSystem2_hh_
#define _diophantineSystem2_hh_

class DiophantineSystem2
{
public:  
  void insertRow(const Vector<int>& row);
  void setUpperBounds(const Vector<int>& bounds);
  bool findNextMinimalSolution(Vector<int>& solution);

private:
  struct State
  {
    Vector<int> assignment;
    Vector<int> residue;
    NatSet frozen;
  };

  typedef Vector<State> StateStack;
  typedef list<Vector<int> > VecList;


  static bool isZero(const Vector<int>& arg);
  static bool greaterEqual(const Vector<int>& arg1, const Vector<int>& arg2);

  void initialize();
  int scalerProduct(const Vector<int>& arg, int columnNr);
  bool minimal(const Vector<int>& arg);
  bool solve(int a, int b, int c,
	     bool y_nonneg, int x_bound, int y_bound,
	     int& x_base, int& y_base,
	     int& x_inc, int& y_inc,
	     int& bound);
  int extendedGcd(int a0, int b0, int& u, int& v);
  void integerGaussianElimination();
  void dumpMatrix();
  void newSolve();
  int gcd(int a, int b);
  bool concensus(int a, int b, int u,
		 int c, int d, int v,
		 int& e, int& f, int& w);
  void finalStep(int leftOver, const Vector<int>& residues, Vector<int>& sol);
  void takeStep(const VecList& g,
		int varNr,
		int leftOver,
		const Vector<int>& residues,
		Vector<int>& sol);

  int nrColumns;		// number of variables
  VecList rows;			// Diophantine system
  Vector<int> upperBounds;	// upper bounds for each variable
  VecList solutions;		// minimal solutions found so far
  StateStack states;		// stack of search tree states
  int stackPointer;
  int sumBound;			// bound on sum of components for a minimal solution
  //
  //	Pre-allocated temporary storage.
  //
  State current;
};

#endif
