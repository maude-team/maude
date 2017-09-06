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

#define PRINT(v) (std::cout << #v << " = " << v << '\t')
#define PRINT_NL(v) (std::cout << #v << " = " << v << '\n')
//
//      Implementation for class DiophantineSystem2
//
#include "macros.hh"
#include "vector.hh"
#include "diophantineSystem2.hh"

void
DiophantineSystem2::insertRow(const Vector<int>& row)
{
  Assert(!row.empty(), "empty row");
  if (rows.empty())
    nrColumns = row.size();
  else
    Assert(nrColumns == row.size(), "row size differs");
  rows.push_back(row);  // deep copy
}

void
DiophantineSystem2::setUpperBounds(const Vector<int>& bounds)
{
  upperBounds = bounds;
}


static void
dumpVec(const Vector<int>& values)
{
  FOR_EACH_CONST(i, Vector<int>, values)
    cout << "\t" << *i;
  cout << endl;
}

void
DiophantineSystem2::dumpMatrix()
{
  FOR_EACH_CONST(i, VecList, rows)
    {
      FOR_EACH_CONST(j, Vector<int>, *i)
	cout << "\t" << *j;
      cout << endl;
    }
}

void 
DiophantineSystem2::integerGaussianElimination()
{
  dumpMatrix();
  int column = nrColumns;
  const VecList::iterator e = rows.end();
  for (VecList::iterator i = rows.begin(); i != e; ++i)
    {
      --column;
      if (column < 0)
	break;
      int diag = (*i)[column];
      if (diag == 0)
	{
	  cout << "pivoting" << endl;
	  VecList::iterator j = i;
	  for (++j; j != e; ++j)
	    {
	      diag = (*j)[column];
	      if (diag != 0)
		{
		  i->swap(*j);
		  goto ok;
		}
	    }
	  cout << "failed" << endl;
	  dumpMatrix();
	  return;
	ok:
	  ;
	}
      for (VecList::iterator j = rows.begin(); j != e; ++j)
	{
	  if (i != j)
	    {
	      int entry = (*j)[column];
	      if (entry != 0)
		{
		  int u;
		  int v;
		  int g = extendedGcd(diag, entry, u, v);
		  int d_mult = entry / g;
		  int e_mult = diag / g;
		  (*j)[column] = 0;
		  for (int k = column - 1; k >= 0; --k)
		    (*j)[k] = e_mult * (*j)[k] - d_mult * (*i)[k];
		  for (int k = column + 1; k < nrColumns; ++k)
		    (*j)[k] *= e_mult;
		}
	    }
	}
    }
  dumpMatrix();
}

void
DiophantineSystem2::initialize()
{
  if (upperBounds.empty())
    {
      upperBounds.resize(nrColumns);
      Vector<int>::iterator e = upperBounds.end();
      for (Vector<int>::iterator i = upperBounds.begin(); i != e; ++i)
	*i = UNBOUNDED;
    }
  else
    Assert(nrColumns == upperBounds.size(), "row size differs");

  {
    sumBound = 1;
    FOR_EACH_CONST(i, VecList, rows)
      {
	int sum = 1;
	FOR_EACH_CONST(j, Vector<int>, *i)
	  {
	    int t = *j;
	    sum += (t < 0) ? -t : t;
	  }
	sumBound *= sum;
      }
  }
  cout << "sum bound = " << sumBound << endl;

  integerGaussianElimination();
  newSolve();
  states.resize(nrColumns);
  NatSet frozen;
  for (int i = 0; i < nrColumns; ++i)
    {
      State& s = states[i];
      {
	s.assignment.resize(nrColumns);
	Vector<int>::iterator e = s.assignment.end();
	for (Vector<int>::iterator j = s.assignment.begin(); j != e; ++j)
	  *j = 0;
	s.assignment[i] = 1;
      }
      {
	s.residue.resize(rows.size());
	Vector<int>::iterator k = s.residue.begin();
	FOR_EACH_CONST(j, VecList, rows)
	  {
	    *k = (*j)[i];
	    ++k;
	  }
      }
      if (upperBounds[i] == 1)
	frozen.insert(i);  // common case
      s.frozen = frozen;
      frozen.insert(i);
    }
  current.residue.resize(rows.size());
  stackPointer = nrColumns;
}

void
DiophantineSystem2::newSolve()
{
  VecList g;
  {
    FOR_EACH_CONST(i, VecList, rows)
      {
	g.push_back(Vector<int>());
	Vector<int>& v = g.back();
	v.resize(nrColumns - 2);
	v[nrColumns - 3] = gcd((*i)[nrColumns - 2], (*i)[nrColumns - 1]);
	for (int j = nrColumns - 4; j >= 0; --j)
	  v[j] = gcd((*i)[j + 1], v[j + 1]);
	for (int j = 0; j < nrColumns - 2; ++j )
	  cout << v[j] << '\t';
	cout << endl;
      }
  }
  Vector<int> sol(nrColumns);
  int nrRows = rows.size();
  Vector<int> residues(nrRows);
  for(int i = 0; i < nrRows; ++i)
    residues[i] = 0;
  takeStep(g, 0, sumBound, residues, sol);
}

void
DiophantineSystem2::finalStep(int leftOver, const Vector<int>& residues, Vector<int>& sol)
{
  int varNr = nrColumns - 2;
  int base;
  int inc;
  int bound;
  int u1 = upperBounds[varNr];
  if (leftOver < u1)
    u1 = leftOver;
  int u2 = upperBounds[varNr + 1];
  if (leftOver < u2)
    u2 = leftOver;
  //
  //	Find a concensus solution for variable.
  //
  int row = 0;
  bool first = true;
  FOR_EACH_CONST(i, VecList, rows)
    {
      int residue = residues[row];
      ++row;
      int a = (*i)[varNr];
      int b = (*i)[varNr + 1];
      if (a != 0)
	{
	  int x_base;
	  int x_inc;
	  int k_bound;
	  if (b != 0)
	    {
	      int y_base;
	      int y_inc;
	      if (solve(a, b, residue,
			true, u1, u2,
			x_base, y_base, x_inc, y_inc, k_bound))
		{
		}
	      else
		{
		  cout << "no solution" << endl;
		  return;
		}
	    }
	  else
	    {
	      if (residue % a != 0)
		{
		  cout << "not divisible" << endl;
		  return;
		}
	      x_base = -residue / a;
	      if (x_base < 0 || x_base > u1)
		{
		  cout << "out of bounds" << endl;
		  return;
		}
	      x_inc = 1;  // fudge
	      k_bound = 0;
	    }
	  cout << "final x = " << x_base << " + " << x_inc << "k for k = 0,..., " << k_bound << endl;
	  if (first)
	    {
	      base = x_base;
	      inc = x_inc;
	      bound = k_bound;
	      first = false;
	    }
	  else
	    {
	      int c_base;
	      int c_inc;
	      int c_bound;
	      if (concensus(base, inc, bound,
			    x_base, x_inc, k_bound,
			    c_base, c_inc, c_bound))
		{
		  base = c_base;
		  inc = c_inc;
		  bound = c_bound;
		  cout << "final concensus: x = " << c_base << " + " << c_inc << "k for k = 0,..., " << c_bound << endl;
		}
	      else
		{
		  cout << "no concensus" << endl;
		  return;
		}
	    }
	}
      else
	{
	  //
	  //	a zero - do nothing.
	  //
	  cout << "no insight" << endl;
	}
    }
  //
  //	Now try values for variable
  //
  for (int k = 0; k <= bound; ++k)
    {
      int val = base + inc * k;
      int row = 0;
      int val2 = -1;
      FOR_EACH_CONST(i, VecList, rows)
	{
	  int residue = residues[row] + (*i)[varNr] * val;
	  ++row;
	  int b = (*i)[varNr + 1];
	  if (residue * b > 0)
	    goto fail;
	  if (b == 0)
	    {
	      if (residue != 0)
		goto fail;
	    }
	  else
	    {
	      if ((residue % b) != 0)
		goto fail;
	      int t = -residue / b;
	      if (val2 != -1 && val2 != t)
		goto fail;
	      val2 = t;
	    }
	}
      sol[varNr] = val;
      sol[varNr + 1] = val2;
      cout << "**********************************************solution***\n";
      dumpVec(sol);
    fail:
      ;
    }
}

void
DiophantineSystem2::takeStep(const VecList& g,
			     int varNr,
			     int leftOver,
			     const Vector<int>& residues,
			     Vector<int>& sol)
{
  cout << "\nsolving for x" << varNr << "\n" << endl;
  if (varNr == nrColumns - 2)
    {
      finalStep(leftOver, residues, sol);
      return;
    }
  int base;
  int inc;
  int bound;
  int u = upperBounds[varNr];
  if (leftOver < u)
    u = leftOver;
  //
  //	Find a concensus solution for variable.
  //
  bool first = true;
  int row = 0;
  VecList::const_iterator j = g.begin();
  FOR_EACH_CONST(i, VecList, rows)
    {
      int residue = residues[row];
      ++row;
      int a = (*i)[varNr];
      int g = (*j)[varNr];
      ++j;
      if (a != 0)
	{
	  int x_base;
	  int x_inc;
	  int k_bound;
	  if (g != 0)
	    {
	      int y_base;
	      int y_inc;
	      if (solve(a, g, -residue,
			false, u, -1,
			x_base, y_base, x_inc, y_inc, k_bound))
		{
		}
	      else
		{
		  cout << "no solution" << endl;
		  return;
		}
	    }
	  else
	    {
	      if (residue % a != 0)
		{
		  cout << "not divisible" << endl;
		  return;
		}
	      x_base = -residue / a;
	      if (x_base < 0 || x_base > u)
		{
		  cout << "out of bounds" << endl;
		  return;
		}
	      x_inc = 1;  // fudge
	      k_bound = 0;
	    }
	  cout << "x = " << x_base << " + " << x_inc << "k for k = 0,..., " << k_bound << endl;
	  if (first)
	    {
	      base = x_base;
	      inc = x_inc;
	      bound = k_bound;
	      first = false;
	    }
	  else
	    {
	      int c_base;
	      int c_inc;
	      int c_bound;
	      if (concensus(base, inc, bound,
			    x_base, x_inc, k_bound,
			    c_base, c_inc, c_bound))
		{
		  base = c_base;
		  inc = c_inc;
		  bound = c_bound;
		  cout << "concensus: x = " << c_base << " + " << c_inc << "k for k = 0,..., " << c_bound << endl;
		}
	      else
		{
		  cout << "no concensus" << endl;
		  return;
		}
	    }
	}
      else
	{
	  //
	  //	Since coefficient is zero in this equation it provides us with no
	  //	constraint on variable.
	  //
	  cout << "no info" << endl;
	}
    }
  //
  //	Now try values for variable
  //
  for (int k = 0; k <= bound; ++k)
    {
      int val = base + inc * k;
      int row = 0;
      Vector<int> newRes(residues);
      FOR_EACH_CONST(i, VecList, rows)
	{
	  newRes[row] = residues[row] + (*i)[varNr] * val;
	  ++ row;
	}
      sol[varNr] = val;
      takeStep(g, varNr + 1, leftOver - sol[varNr], newRes, sol);
    }
}


local_inline bool
DiophantineSystem2::greaterEqual(const Vector<int>& arg1, const Vector<int>& arg2)
{
  Vector<int>::const_iterator j = arg2.begin();
  FOR_EACH_CONST(i, Vector<int>, arg1)
    {
      if (*i < *j)
	return false;
      ++j;
    }
  return true;
}

local_inline bool
DiophantineSystem2::minimal(const Vector<int>& arg)
{
  FOR_EACH_CONST(i, VecList, solutions)
    {
      if (greaterEqual(arg, *i))
	return false;
    }
  return true;
}

local_inline bool
DiophantineSystem2::isZero(const Vector<int>& arg)
{
  FOR_EACH_CONST(i, Vector<int>, arg)
    {
      if (*i != 0)
	return false;
    }
  return true;
}

local_inline int
DiophantineSystem2::scalerProduct(const Vector<int>& arg, int columnNr)
{
  Assert(arg.size() == rows.size(), "size clash");
  int sum = 0;
  Vector<int>::const_iterator j = arg.begin();
  FOR_EACH_CONST(i, VecList, rows)
    {
      sum += (*i)[columnNr] * *j;
      ++j;
    }
  return sum;
}

bool
DiophantineSystem2::findNextMinimalSolution(Vector<int>& solution)
{
  if (states.isNull())
    initialize();
  while (stackPointer > 0)
    {
      --stackPointer;
      State& s = states[stackPointer];
      if (isZero(s.residue))
	{
	  solutions.push_back(s.assignment);
	  solution = s.assignment;
	  return true;
	}
      else
	{
	  //
	  //	Check that each equation has a non-frozen coefficient left that will
	  //	move the residue in the right direction. Also see if we have forced assignments to a variable.
	  //
	retry:
	  Vector<int>::const_iterator res = s.residue.begin();
	  FOR_EACH_CONST(j, VecList, rows)
	    {
	      int d = *res;
	      ++res;
	      bool ok = (d == 0);
	      int nfnzCount = 0;
	      int lastNfnz;
	      for (int i = 0; i < nrColumns; ++i)
		{
		  if (!(s.frozen.contains(i)))
		    {
		      int c = (*j)[i] ;
		      if (c != 0)
			{
			  ++nfnzCount;
			  lastNfnz = i;
			  if (d * c < 0)
			    ok = true;
			}
		    }
		}
	      if (!ok)
		goto skip;
	      if (nfnzCount == 1)
		{
		  if (d == 0)
		    {
		      //cout << "freezing " << lastNfnz << endl;
		      s.frozen.insert(lastNfnz);
		      goto retry;
		    }
		  //
		  //	We can force a variable.
		  //
		  //cout << "one var " << lastNfnz << endl;
		  int c = (*j)[lastNfnz];
		  if (d % c == 0)
		    {
		      int delta = -d / c;
		      //cout << "div ok delta = " << delta << endl;
		      Assert(delta > 0, "delta = " << delta);
		      s.assignment[lastNfnz] += delta;
		      if (s.assignment[lastNfnz] <= upperBounds[lastNfnz] && minimal(s.assignment))
			{
			  Vector<int>::iterator res2 = s.residue.begin();
			  FOR_EACH_CONST(k, VecList, rows)
			    {
			      *res2 += delta * (*k)[lastNfnz] ;
			      ++res2;
			    }
			  //cout << "forced " << lastNfnz << " by " << delta << endl;
			  s.frozen.insert(lastNfnz);
			  ++stackPointer;
			}
		    }
		  goto skip;
		}
	    }
	  current.assignment.swap(s.assignment);
	  current.residue.swap(s.residue);
	  current.frozen.swap(s.frozen);
	  for (int i = 0; i < nrColumns; ++i)
	    {
	      if (!(current.frozen.contains(i)) &&
		  current.assignment[i] < upperBounds[i] &&
		  scalerProduct(current.residue, i) < 0)
		{
		  int& component = current.assignment[i];
		  ++component;
		  if (minimal(current.assignment))
		    {
		      State& n = states[stackPointer];
		      n.assignment = current.assignment;
		      n.residue = current.residue;
		      Vector<int>::const_iterator from = current.residue.begin();
		      Vector<int>::iterator to = n.residue.begin();
		      FOR_EACH_CONST(j, VecList, rows)
			{
			  *to = *from + (*j)[i];
			  ++from;
			  ++to;
			}
		      if  (component == upperBounds[i])
			current.frozen.insert(i);
		      n.frozen = current.frozen;
		      ++stackPointer;
		    }
		  --component;
		  current.frozen.insert(i);  // freeze in remaining decendents whether minimal or not
		}
	    }
	}
	skip:
	  ;
    }
  return false;
}

/*
int
DiophantineSystem2::extendedGcd(int a, int b, int& u, int& v)
{
  int p = 1;
  int q = 0;
  int r = 0;
  int s = 1;

  while (b != 0)
    {
      int quot = a / b;
      //
      //	Classic Euclid.
      //
      int rem = a % b;
      a = b;
      b = rem;
      //
      //	Extended Euclid.
      //
      int new_r = p - quot * r;
      p = r;
      r = new_r;

      int new_s = q - quot * s;
      q = s;
      s = new_s;
    }
  u = p;
  v = q;
  return a;
}
*/

bool
DiophantineSystem2::concensus(int a, int b, int u,
			      int c, int d, int v,
			      int& e, int& f, int& w)
{
  //
  //	Given two general solutions for x:
  //	  x = a + ib for i = 0,..., u
  //	  x = c + jd for j = 0,..., v
  //	compute a concensus solution:
  //	  x = e + kf for k = 0,..., w
  //	Any of u, v and w may be -1 to indicate unbounded.
  //	Assume b != 0 and d != 0.
  //
  Assert(b != 0, "b zero");
  Assert(d != 0, "d zero");
  int i_base;
  int i_inc;
  int j_base;
  int j_inc;
  if (solve(b, -d, c - a, true, u, v, i_base, j_base, i_inc, j_inc, w))
    {
      e = a + i_base * b;
      f = i_inc * b;
      Assert(e == c + j_base * d, "base conflict " << e << " vs " << c + j_base * d);
      Assert(f == j_inc * d, "inc conflict");
      return true;
    }
  return false;
}

bool
DiophantineSystem2::solve(int a, int b, int c,
			  bool y_nonneg, int x_bound, int y_bound,
			  int& x_base, int& y_base,
			  int& x_inc, int& y_inc,
			  int& bound)
{
  PRINT(a); PRINT(b); PRINT(c);  PRINT(y_nonneg);  PRINT(x_bound); PRINT_NL(y_bound);
  //
  //	For integers a, b, c with a != 0 and b != 0, generate the set of solutions to
  //	ax + by = c
  //	where x is nonnegative and bounded by x_bound (>= 0, -1 indicates unbounded)
  //	and y is nonnegaive if y_nonneg flag set and bounded by y_bound (>= 0, -1 indicates unbounded)
  //	encoded as (x_base, y_base) + k (x_inc, y_inc) for
  //	k = 0, 1,..., bound
  //	where bound may be -1 to represent unbounded.
  //
  Assert(a != 0, "a zero");
  Assert(b != 0, "b zero");
  if (b < 0)
    {
      a = -a;
      b = -b;
      c = -c;
    }
  int slope = -1;
  bool neg_a = false;
  if (a < 0)
    {
      a = -a;
      slope = 1;
      neg_a = true;
    }
  int u;
  int v;
  int g = extendedGcd(a, b, u, v);
  PRINT(slope); PRINT(a); PRINT(b); PRINT(g); PRINT(u); PRINT_NL(v);
  if (neg_a)
    u = -u;
  if (c % g != 0)
    return false;  // c not in the additive group generated by a and b
  int cs = c / g;
  x_inc = b / g;
  y_inc = a / g;
  if (slope == -1)
    y_inc = -y_inc;
  int x_start = u * cs;
  int y_start = v * cs;
  PRINT(cs); PRINT(x_start); PRINT_NL(y_start); 
  //
  //	We now have a general solution over the integers; we need to clip it
  //	to respect nonnegativity and upper bounds.
  //
  //	t = least k such that x_start + k * x_inc >= 0;
  //
  int t = ceilingDivision(- x_start, x_inc);
  if (slope == 1)
    {
      if (y_nonneg)
	{
	  //
	  //	y_k = least k such that y_start + k * y_inc >= 0
	  //
	  int y_k = ceilingDivision(- y_start, y_inc);
	  if (y_k > t)
	    t = y_k;
	}
      x_start += t * x_inc;
      y_start += t * y_inc;
      bound = -1;
      if (x_bound >= 0)
	{
	  //
	  //	bound = greatest k such that x_start + k * x_inc <= x_bound
	  //
	  bound = floorDivision(x_bound - x_start, x_inc);
	  if (bound < 0)
	    return false;
	}
      if (y_bound >= 0)
	{
	  //
	  //	y_k = greatest k such that y_start + k * y_inc <= y_bound
	  //
	  int y_k = floorDivision(y_bound - y_start, y_inc);
	  if (y_k < 0)
	    return false;
	  if (bound == -1 || y_k < bound)
	    bound = y_k;
	}
    }
  else
    {
      if (y_bound >= 0)
	{
	  //
	  //	y = least k such that y_start + k * y_inc <= y_bound
	  //
	  int y_k = ceilingDivision(y_bound - y_start, y_inc);
	  if (y_k > t)
	    t = y_k;
	}
      x_start += t * x_inc;
      y_start += t * y_inc;
      bound = -1;
      if (x_bound >= 0)
	{
	  //
	  //	bound = greatest k such that x_start + k * x_inc <= x_bound
	  //
	  bound = floorDivision(x_bound - x_start, x_inc);
	  if (bound < 0)
	    return false;
	}
      if (y_nonneg)
	{
	  //
	  //	y_k = greatest k such that y_start + k * y_inc >= 0
	  //
	  int y_k = floorDivision(- y_start, y_inc);
	  if (y_k < 0)
	    return false;
	  if (bound == -1 || y_k < bound)
	    bound = y_k;
	}
    }
  x_base = x_start;
  y_base = y_start;
  PRINT(x_base); PRINT(y_base); PRINT(x_inc);  PRINT(y_inc);  PRINT_NL(bound);
  return true;
}

int
DiophantineSystem2::extendedGcd(int a0, int b0, int& u, int& v)
{
  //
  //	Assume a0, b0 > 0.
  //
  int a = a0;
  int b = b0;
  int p = 1;
  int r = 0;

  while (b != 0)
    {
      int quot = a / b;
      //
      //	Classic Euclid.
      //
      int rem = a % b;
      a = b;
      b = rem;
      //
      //	Extended Euclid.
      //
      int new_r = p - quot * r;
      p = r;
      r = new_r;
    }
  u = p;
  v = (a - p * a0) / b0;
  return a;
}

int
DiophantineSystem2::gcd(int a, int b)
{
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  while (b != 0)
    {
      int rem = a % b;
      a = b;
      b = rem;
    }
  return a;
}
