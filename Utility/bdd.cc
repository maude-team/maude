//
//	Implementation for class Bdd.
//

//	utility stuff
#include "macros.hh"
#include "bdd.hh"

Bdd
Bdd::extractPrimeImplicant() const
{
  if (*this == bdd_false() || *this == bdd_true())
    return *this;

  Bdd hi = bdd_high(*this);
  Bdd lo = bdd_low(*this);
  int var = bdd_var(*this);

  if (hi == bdd_false())
    return bdd_nithvar(var) & lo.extractPrimeImplicant();
  
  Bdd pi = hi.extractPrimeImplicant();
  if (bdd_restrict(lo, pi) == bdd_true())
    return pi;

  return bdd_ithvar(var) & pi;
}
