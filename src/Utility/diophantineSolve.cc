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

//	Iterative GCD method.

bool
DiophantineSystem3::nextSolution(bool first)
{
  int nrFreeVariables = nrVars - nrEqns;
  int sp;

  if (first)
    {
      sp = 0;
    forwards:
      for (; sp < nrFreeVariables - 1; ++sp)
	{
	  if (!fillOutStackEntry(sp))
	    goto backwards;
	}
      if (!fillOutLastEntry())
	goto backwards;
      if (solveDiagonal())
	return true;
      goto redo_last;
    }
  else
    {
      sp = nrFreeVariables;
    backwards:
      if (--sp < 0)
	return false;
    redo_last:
      StackEntry& st = stack[sp];
      if (solution[sp] == st.bound)
	{
	  leftOver += solution[sp];
	  int eqnNr = 0;
	  FOR_EACH_CONST(i, VecList, eqns)
	    {
	      residues[eqnNr] -= (*i)[sp] * solution[sp];
	      ++eqnNr;
	    }
	  solution[sp]= 0;
	  goto backwards;
	}
      else
	{
	  //
	  //	Update leftover, residues and solution.
	  //
	  leftOver -= st.inc;
	  int eqnNr = 0;
	  FOR_EACH_CONST(i, VecList, eqns)
	    {
	      residues[eqnNr] += (*i)[sp] * st.inc;
	      ++eqnNr;
	    }
	  solution[sp] += st.inc;
	  if (sp == nrFreeVariables - 1)
	    {
	      if (solveDiagonal())
		return true;
	      goto redo_last;
	    }
	  ++sp;
	  stack[sp].zeroSoFar = false;
	  goto forwards;
	}
    }

  return false; // never reached
}

bool
DiophantineSystem3::fillOutStackEntry(int varNr)
{
  TRACE(" solving x" << varNr);
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
	      TRACE("no solution");
	      return false;
	    }
	  TRACE("x" << varNr << " = " << x_base << " + " << x_inc << "k for k = 0,..., " << k_bound);

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
		  TRACE("concensus: x" << varNr << " = " << c_base << " + " << c_inc << "k for k = 0,..., " << c_bound);
		}
	      else
		{
		  TRACE("no concensus");
		  return false;
		}
	    }
	}
      else
	{
	  //
	  //	Since coefficient is zero in this equation it provides us with no
	  //	constraint on variable.
	  //
	  TRACE("no info");
	}
      ++j;
      ++row;
    }
  //
  //	Correct bound for zero inc, prunable variable and zero so far situations.
  //
  StackEntry& st = stack[varNr];
  if (inc == 0)
    bound = 0;
  else
    {
      if (varNr >= firstPrunablePrediag)
	{
	  bound = 0;
	  if (st.zeroSoFar && base == 0)
	    bound = 1;
	}
    }
  TRACE("corrected: x" << varNr << " = " << base << " + " << inc << "k for k = 0,..., " << bound);
  //
  //	Set up stack entry and give variable it's first value;
  //	update leftOver, residues and zeroSoFar
  //
  st.inc = inc;
  st.bound = base + bound * inc;
  if (base != 0)
    {
      leftOver -= base;
      int eqnNr = 0;
      FOR_EACH_CONST(i, VecList, eqns)
	{
	  residues[eqnNr] += (*i)[varNr] * base;
	  ++eqnNr;
	}
      solution[varNr] = base;
      stack[varNr + 1].zeroSoFar = false;
    }
  else
    stack[varNr + 1].zeroSoFar = st.zeroSoFar;

  return true;
}

bool
DiophantineSystem3::fillOutLastEntry()
{
  TRACE("solving prediagonal");
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
	      TRACE("no solution");
	      return false;
	    }
	  TRACE("x = " << x_base << " + " << x_inc << "k for k = 0,..., " << k_bound);

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
		  TRACE("concensus: x = " << c_base << " + " << c_inc << "k for k = 0,..., " << c_bound);
		}
	      else
		{
		  TRACE("no concensus");
		  return false;
		}
	    }
	}
      else
	{
	  //
	  //	Since coefficient is zero in this equation it provides us with no
	  //	constraint on variable.
	  //
	  TRACE("no info");
	}
    }
  //
  //	Correct start bound for zero inc, prunable variable and zero so far situations.
  //
  StackEntry& st = stack[prediag];
  mpz_class start = 0;
  if (st.zeroSoFar && base == 0)
    {
      if (bound == 0)
	return false;
      start = 1;  // avoid the trivial solution
    }

  if (prediag >= firstPrunablePrediag)
    bound = start;  // only first solution can be minimal
  //
  //	Set up stack entry and give variable it's first value;
  //	update leftOver, residues
  //
  st.inc = inc;
  st.bound = base + bound * inc;
  solution[prediag] = base + start * inc;

  if (solution[prediag] != 0)
    {
      leftOver -= solution[prediag];
      int eqnNr = 0;
      FOR_EACH_CONST(i, VecList, eqns)
	{
	  residues[eqnNr] += (*i)[prediag] * solution[prediag];
	  ++eqnNr;
	}
    }

  return true;
}

bool
DiophantineSystem3::solveDiagonal()
{
  int eqnNr = 0;
  FOR_EACH_CONST(i, VecList, eqns)
    {
      int varNr = nrVars - eqnNr - 1;
      mpz_class q;
      mpz_class r;
      mpz_class res = - residues[eqnNr];
      mpz_fdiv_qr(q.get_mpz_t(), r.get_mpz_t(), res.get_mpz_t(), (*i)[varNr].get_mpz_t());
      Assert(r == 0, "divisability error " << res << ' ' << (*i)[varNr]);
      Assert(upperBounds[varNr] < 0 || q <= upperBounds[varNr],
	     "bounds error" << upperBounds[varNr] << ' ' << q);
      Assert(q >= 0, "sign error " << q);
      solution[varNr] = q;
      ++eqnNr;
    }
  if (minimal(solution))
    {
      cout << "*** Solution " << solutions.size() + 1 << " ***\n";
      FOR_EACH_CONST(j, IntVec, solution)
	cout << *j << '\t';
      cout << endl;
      solutions.push_back(solution);
      return true;
    }
  return false;
}
