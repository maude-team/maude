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

//#define TRACE(s) (std::cout << s << endl)
#define TRACE(s)

//
//      Implementation for class DiophantineSystem3
//
#include "macros.hh"
#include "vector.hh"
#include "diophantineSystem3.hh"

#include "diophantineSolve.cc"

DiophantineSystem3::DiophantineSystem3()
{
  nrEqns = 0;
}

void
DiophantineSystem3::insertEqn(const IntVec& eqn)
{
  Assert(!eqn.empty(), "empty row");
  if (eqns.empty())
    nrVars = eqn.size();
  else
    Assert(nrVars == eqn.size(), "equation size differs");
  eqns.push_back(eqn);  // deep copy
  ++nrEqns;
}

void
DiophantineSystem3::setUpperBounds(const IntVec& bounds)
{
  Assert(upperBounds.empty(), "bounds already set");
  upperBounds = bounds;  // deep copy
}

void
DiophantineSystem3::dumpEqns()
{
  FOR_EACH_CONST(i, VecList, eqns)
    {
      FOR_EACH_CONST(j, IntVec, *i)
	cout << *j << '\t';
      cout << endl;
    }
  cout << endl;
}

bool
DiophantineSystem3::greaterEqual(const IntVec& arg1, const IntVec& arg2)
{
  IntVec::const_iterator j = arg2.begin();
  FOR_EACH_CONST(i, IntVec, arg1)
    {
      if (*i < *j)
	return false;
      ++j;
    }
  return true;
}

bool
DiophantineSystem3::minimal(const IntVec& arg)
{
  FOR_EACH_CONST(i, VecList, solutions)
    {
      if (greaterEqual(arg, *i))
	return false;
    }
  return true;
}

void
DiophantineSystem3::swapVariables(int u, int v)
{
  const VecList::iterator e = eqns.end();
  for (VecList::iterator i = eqns.begin(); i != e; ++i)
    swap((*i)[u], (*i)[v]);
  swap(upperBounds[u], upperBounds[v]);
  swap(permutation[u], permutation[v]);
}

void 
DiophantineSystem3::integerGaussianElimination()
{
  dumpEqns();
  //
  //	Diagonalize the rhs as much as possible.
  //
  int varNr = nrVars - 1;
  const VecList::iterator e = eqns.end();
  for (VecList::iterator i = eqns.begin(); varNr >= 0 && i != e;)
    {
      const mpz_class& diag = (*i)[varNr];
      if (diag == 0)
	{
	  //
	  //	Permute variables to get a nonzero diagonal element.
	  //
	  for (int j = varNr - 1; j >= 0; --j)
	    {
	      if ((*i)[j] != 0)
		{
		  swapVariables(varNr, j);
		  goto eliminate;
		}
	    }
	  //
	  //	Delete an all zero equation.
	  //
	  i = eqns.erase(i);
	  --nrEqns;
	  DebugAdvisory("deleted all zero equation");
	  continue;
	}
      //
      //	Eliminate variable varNr from all equations other than ith.
      //
    eliminate:
      int diagVar = nrVars - 1;
      for (VecList::iterator j = eqns.begin(); j != e; ++j, --diagVar)
	{
	  if (i != j)
	    {
	      mpz_class&  entry = (*j)[varNr];
	      if (entry != 0)
		{
		  mpz_class g;
		  mpz_gcd(g.get_mpz_t(), diag.get_mpz_t(), entry.get_mpz_t());
		  mpz_class d_mult = entry / g;
		  mpz_class e_mult = diag / g;
		  for (int k = varNr; k >= 0; --k)
		    (*j)[k] = e_mult * (*j)[k] - d_mult * (*i)[k];
		  if (diagVar > varNr)
		    (*j)[diagVar] *= e_mult;
		  entry = 0;
		}
	    }
	}
      --varNr;
      ++i;
  dumpEqns();

    }
  //
  //	Make diagonal +ve.
  //
  varNr = nrVars - 1;
  int nrNonDiagVars = nrVars - nrEqns;
  for (VecList::iterator i = eqns.begin(); varNr >= 0 && i != e; ++i, --varNr)
    {
      mpz_class& diag = (*i)[varNr];
      Assert(diag != 0, "zero diagonal element");
      if (diag < 0)
	{
	  diag = -diag;
	  for (int j = 0; j < nrNonDiagVars; j++)
	    (*i)[j] = -(*i)[j];  // probably a faster way to do this
	}
    }
  dumpEqns();
}

void
DiophantineSystem3::initialize()
{
  Assert(!eqns.empty(), "no equations");

  if (upperBounds.empty())
    {
      upperBounds.resize(nrVars);
      for (int i = 0; i < nrVars; ++i)
	upperBounds[i] = NONE;
    }
  else
    Assert(upperBounds.size() == nrVars, "bounds size differs");
  
  {
    sumBound = 1;
    FOR_EACH_CONST(i, VecList, eqns)
      {
	mpz_class sum = 1;
	FOR_EACH_CONST(j, IntVec, *i)
	  sum += abs(*j);
	sumBound *= sum;
      }
  }
  PRINT_NL(sumBound);

  permutation.resize(nrVars);
  for (int i = 0; i < nrVars; ++i)
    permutation[i] = i;

  integerGaussianElimination();
  lastPrediagNeg.resize(nrEqns);
  lastPrediagNonzero.resize(nrEqns);
  pruneLastPrediag = true;
  {
    int varNr = nrVars - 1;
    int nrGcds = nrVars - nrEqns - 1;
    int eqnNr = 0;
    FOR_EACH_CONST(i, VecList, eqns)
      {
	gcds.push_back(IntVec());
	if (nrGcds > 0)
	  {
	    IntVec& v = gcds.back();
	    v.resize(nrGcds);
	    mpz_gcd(v[nrGcds - 1].get_mpz_t(), (*i)[nrGcds].get_mpz_t(), (*i)[varNr].get_mpz_t());
	    for (int j = nrGcds - 1; j > 0; --j)
	      mpz_gcd(v[j - 1].get_mpz_t(), (*i)[j].get_mpz_t(), v[j].get_mpz_t());
	    FOR_EACH_CONST(j, IntVec, v)
	      cout << *j << '\t';
	    cout << endl;
	  }

	for (int j = nrGcds; j >= 0; --j)
	  {
	    if ((*i)[j] < 0)
	      {
		lastPrediagNeg[eqnNr] = j;
		goto ok;
	      }
	  }
	// should fail here
      ok:
	for (int j = nrGcds; j >= 0; --j)
	  {
	    if ((*i)[j] != 0)
	      {
		lastPrediagNonzero[eqnNr] = j;
		goto ok2;
	      }
	  }
      ok2:
	--varNr;
	++eqnNr;
      }
  }

  {
    firstPrunablePrediag = nrVars;  // assume no prunable prediagonal variables
    NatSet used;
    for (int i = nrVars - nrEqns - 1; i >= 0; i--)
      {
	int eqnNr = 0;
	FOR_EACH_CONST(j, VecList, eqns)
	  {
	    if ((*j)[i] > 0)
	      goto done;
	    if ((*j)[i] < 0)
	      {
		if (used.contains(eqnNr))
		  goto done;
		used.insert(eqnNr);
	      }
	    ++eqnNr;
	  }
	firstPrunablePrediag = i;
      }
  done:
    ;
    PRINT_NL(firstPrunablePrediag);
  }
}

bool
DiophantineSystem3::findNextMinimalSolution(IntVec& /* solution */)
{
  initialize();
  //IntVec residues(nrEqns);
  residues.resize(nrEqns);
  {
    const IntVec::iterator e = residues.end();
    for (IntVec::iterator i = residues.begin(); i != e; ++i)
      *i = 0;
  }
  solution.resize(nrVars);
  {
    const IntVec::iterator e = solution.end();
    for (IntVec::iterator i = solution.begin(); i != e; ++i)
      *i = 0;
  }
  stack.resize(nrVars - nrEqns);
  stack[0].zeroSoFar = true;

  leftOver = sumBound;
  //takeStep(0, sumBound, residues, solution, true);
  if (nextSolution(true))
    while (nextSolution(false));

  return false;
}

bool
DiophantineSystem3::solve(mpz_class a,
			  mpz_class b,
			  mpz_class c,
			  bool y_nonneg,
			  const mpz_class& x_bound,
			  const mpz_class& y_bound,
			  mpz_class& x_base,
			  mpz_class& y_base,
			  mpz_class& x_inc,
			  mpz_class& y_inc,
			  mpz_class& bound)
{
  //PRINT(a); PRINT(b); PRINT(c);  PRINT(y_nonneg);  PRINT(x_bound); PRINT_NL(y_bound);
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
  bool neg_slope = true;
  bool neg_a = false;
  if (a < 0)
    {
      a = -a;
      neg_a = true;
      neg_slope = false;
    }
  {
    mpz_class g;
    mpz_class u;
    mpz_class v;
    mpz_gcdext(g.get_mpz_t(), u.get_mpz_t(), v.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
 
    //PRINT(neg_slope); PRINT(a); PRINT(b); PRINT(g); PRINT(u); PRINT_NL(v);

    if (!mpz_divisible_p(c.get_mpz_t(), g.get_mpz_t()))
      return false;  // c not in the additive group generated by a and b
    mpz_class cs;
    mpz_divexact(cs.get_mpz_t(), c.get_mpz_t(), g.get_mpz_t());
    mpz_divexact(x_inc.get_mpz_t(), b.get_mpz_t(), g.get_mpz_t());
    mpz_divexact(y_inc.get_mpz_t(), a.get_mpz_t(), g.get_mpz_t());
    if (neg_slope)
      y_inc = -y_inc;
    if (neg_a)
      u = -u;
    x_base = u * cs;
    y_base = v * cs;
    //PRINT(cs); PRINT(x_base); PRINT_NL(y_base); 
  }
  //
  //	We now have a general solution over the integers; we need to clip it
  //	to respect nonnegativity and upper bounds.
  //
  //	t = least k such that x_base + k * x_inc >= 0;
  //
  mpz_class t;
  mpz_class m_x_base = -x_base;
  mpz_cdiv_q(t.get_mpz_t(), m_x_base.get_mpz_t(), x_inc.get_mpz_t());
  if (!neg_slope)
    {
      if (y_nonneg)
	{
	  //
	  //	y_k = least k such that y_base + k * y_inc >= 0
	  //
	  mpz_class y_k;
	  mpz_class m_y_base = -y_base;
	  mpz_cdiv_q(y_k.get_mpz_t(), m_y_base.get_mpz_t(), y_inc.get_mpz_t());
	  if (y_k > t)
	    t = y_k;
	}
      x_base += t * x_inc;
      y_base += t * y_inc;
      bound = -1;
      if (x_bound >= 0)
	{
	  //
	  //	bound = greatest k such that x_base + k * x_inc <= x_bound
	  //
	  mpz_class x_diff = x_bound - x_base;
	  mpz_fdiv_q(bound.get_mpz_t(), x_diff.get_mpz_t(), x_inc.get_mpz_t());
	  if (bound < 0)
	    return false;
	}
      if (y_bound >= 0)
	{
	  //
	  //	y_k = greatest k such that y_base + k * y_inc <= y_bound
	  //
	  mpz_class y_k;
	  mpz_class y_diff = y_bound - y_base;
	  mpz_fdiv_q(y_k.get_mpz_t(), y_diff.get_mpz_t(), y_inc.get_mpz_t());
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
	  //	y_k = least k such that y_base + k * y_inc <= y_bound
	  //
	  mpz_class y_k;
	  mpz_class y_diff = y_bound - y_base;
	  mpz_cdiv_q(y_k.get_mpz_t(), y_diff.get_mpz_t(), y_inc.get_mpz_t());
	  if (y_k > t)
	    t = y_k;
	}
      x_base += t * x_inc;
      y_base += t * y_inc;
      bound = -1;
      if (x_bound >= 0)
	{
	  //
	  //	bound = greatest k such that x_base + k * x_inc <= x_bound
	  //
	  mpz_class x_diff = x_bound - x_base;
	  mpz_fdiv_q(bound.get_mpz_t(), x_diff.get_mpz_t(), x_inc.get_mpz_t());
	  if (bound < 0)
	    return false;
	}
      if (y_nonneg)
	{
	  //
	  //	y_k = greatest k such that y_base + k * y_inc >= 0
	  //
	  mpz_class y_k;
	  mpz_class m_y_base = -y_base;
	  mpz_fdiv_q(y_k.get_mpz_t(), m_y_base.get_mpz_t(), y_inc.get_mpz_t());
	  if (y_k < 0)
	    return false;
	  if (bound == -1 || y_k < bound)
	    bound = y_k;
	}
    }
  //PRINT(x_base); PRINT(y_base); PRINT(x_inc);  PRINT(y_inc);  PRINT_NL(bound);
  return true;
}

void
DiophantineSystem3::takeStep(int varNr,
			     mpz_class leftOver,
			     const IntVec& residues,
			     IntVec& solution,
			     bool zeroSoFar)
{
  //cout << "\nsolving for x" << varNr << "\n" << endl;
  if (varNr == nrVars - nrEqns - 1)  // the last pre-diagonal variable?
    {
      finalStep(leftOver, residues, solution, zeroSoFar);
      return;
    }
  mpz_class base;
  mpz_class inc;
  mpz_class bound;
  mpz_class u = upperBounds[varNr];
  if (u < 0 || leftOver < u)
    u = leftOver;
  //
  //	Find a concensus solution for variable.
  //
  bool first = true;
  int row = 0;
  VecList::const_iterator j = gcds.begin();
  FOR_EACH_CONST(i, VecList, eqns)
    {
      const mpz_class& a = (*i)[varNr];
      if (a != 0)
	{
	  const mpz_class& residue = residues[row];
	  const mpz_class& g = (*j)[varNr];
	  mpz_class x_base;
	  mpz_class y_base;
	  mpz_class x_inc;
	  mpz_class y_inc;
	  mpz_class k_bound;
	  Assert(g != 0, "zero gcd");
	  if (!solve(a, g, -residue,
		     varNr == lastPrediagNeg[row], u, -1,
		     x_base, y_base, x_inc, y_inc, k_bound))
	    {
	      //cout << "no solution" << endl;
	      return;
	    }
	  //cout << "x = " << x_base << " + " << x_inc << "k for k = 0,..., " << k_bound << endl;

	  if (first)
	    {
	      base = x_base;
	      inc = x_inc;
	      bound = k_bound;
	      first = false;
	    }
	  else
	    {
	      mpz_class c_base;
	      mpz_class c_inc;
	      mpz_class c_bound;
	      if (concensus(base, inc, bound,
			    x_base, x_inc, k_bound,
			    c_base, c_inc, c_bound))
		{
		  base = c_base;
		  inc = c_inc;
		  bound = c_bound;
		  //cout << "concensus: x = " << c_base << " + " << c_inc << "k for k = 0,..., " << c_bound << endl;
		}
	      else
		{
		  //cout << "no concensus" << endl;
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
	  //cout << "no info" << endl;
	}
      ++j;
      ++row;
    }
  //
  //	Now try values for variable
  //
  if (inc == 0)
    bound = 0;
  else
    {
      if (varNr >= firstPrunablePrediag)
	{
	  bound = 0;
	  if (zeroSoFar && base == 0)
	    bound = 1;
	}
    }

  for (mpz_class k = 0; k <= bound; ++k)
    {
      mpz_class val = base + inc * k;
      solution[varNr] = val;
      if (!minimal(solution))
	break;
      int row = 0;
      IntVec newRes(residues);
      FOR_EACH_CONST(i, VecList, eqns)
	{
	  newRes[row] = residues[row] + (*i)[varNr] * val;
	  ++ row;
	}
      takeStep(varNr + 1, leftOver - val, newRes, solution, (zeroSoFar && val == 0));
    }
  solution[varNr] = 0;  // zero out unbound variable
}

void
DiophantineSystem3::finalStep(mpz_class leftOver,
			      const IntVec& residues,
			      IntVec& solution,
			      bool zeroSoFar)
{
  //
  //	We solve each equation for the last prediagonal variable
  //	and its diagonal variable and try to find a consensus on the
  //	last prediagonal variable.
  //
  int prediag = nrVars - nrEqns - 1;
  mpz_class base;
  mpz_class inc;
  mpz_class bound;
  mpz_class u = upperBounds[prediag];
  if (u < 0 || leftOver < u)
    u = leftOver;
  //
  //	Find a concensus solution for last prediagonal variable.
  //
  bool first = true;
  int row = 0;
  FOR_EACH_CONST(i, VecList, eqns)
    {
      const mpz_class& residue = residues[row];
      ++row;
      const mpz_class& a = (*i)[prediag];
      int diag = nrVars - row;
      const mpz_class& b = (*i)[diag];
      if (a != 0)
	{
	  mpz_class x_base;
	  mpz_class y_base;
	  mpz_class x_inc;
	  mpz_class y_inc;
	  mpz_class k_bound;
	  Assert(b != 0, "zero diag");
	  mpz_class u2 = upperBounds[diag];
	  if (u2 < 0 || leftOver < u2)
	    u2 = leftOver;
	  if (!solve(a, b, -residue,
		    true, u, u2,
		    x_base, y_base, x_inc, y_inc, k_bound))
	    {
	      //cout << "no solution" << endl;
	      return;
	    }
	  //cout << "x = " << x_base << " + " << x_inc << "k for k = 0,..., " << k_bound << endl;

	  if (first)
	    {
	      base = x_base;
	      inc = x_inc;
	      bound = k_bound;
	      first = false;
	    }
	  else
	    {
	      mpz_class c_base;
	      mpz_class c_inc;
	      mpz_class c_bound;
	      if (concensus(base, inc, bound,
			    x_base, x_inc, k_bound,
			    c_base, c_inc, c_bound))
		{
		  base = c_base;
		  inc = c_inc;
		  bound = c_bound;
		  //cout << "concensus: x = " << c_base << " + " << c_inc << "k for k = 0,..., " << c_bound << endl;
		}
	      else
		{
		  //cout << "no concensus" << endl;
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
	  //cout << "no info" << endl;
	}
    }
  //
  //	Now try values for last prediagonal variable.
  //
  mpz_class start = 0;
  if (zeroSoFar && base == 0)
    start = 1;  // avoid the trivial solution

  if (prediag >= firstPrunablePrediag)
    bound = start;  // only first solution can be minimal

  for (mpz_class k = start; k <= bound; ++k)
    {
      mpz_class val = base + inc * k;
      solution[prediag] = val;
      int row = 0;
      FOR_EACH_CONST(i, VecList, eqns)
	{
	  mpz_class res = -(residues[row] + (*i)[prediag] * val);
	  ++row;
	  int diag = nrVars - row;
	  mpz_class q;
	  mpz_class r;
	  mpz_fdiv_qr(q.get_mpz_t(), r.get_mpz_t(), res.get_mpz_t(), (*i)[diag].get_mpz_t());
	  Assert(r == 0, "divisability error " << res.get_mpz_t() << (*i)[diag].get_mpz_t());
	  if (upperBounds[diag] < 0 || q <= upperBounds[diag])
	    solution[diag] = q;
	  else
	    goto fail;
	}
      if (minimal(solution))
	{
	  cout << "***Solution***\n";
	  FOR_EACH_CONST(j, IntVec, solution)
	    cout << *j << '\t';
	  cout << endl;
	  solutions.push_back(solution);
	}
    fail:
      ;
    }
  for (int i = prediag; i < nrVars; ++i)
    solution[i] = 0;
}

bool
DiophantineSystem3::concensus(const mpz_class& a, const mpz_class& b, const mpz_class& u,
			      const mpz_class& c, const mpz_class& d, const mpz_class& v,
			      mpz_class& e, mpz_class& f, mpz_class& w)
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
  mpz_class i_base;
  mpz_class i_inc;
  mpz_class j_base;
  mpz_class j_inc;
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
