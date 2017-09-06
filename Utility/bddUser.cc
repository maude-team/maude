//
//	Implementation for class BddUser.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "bddUser.hh"

int BddUser::nrUsers = 0;

BddUser::BddUser()
{
  if (nrUsers == 0)
    {
      bdd_init(DEFAULT_NODE_SIZE, DEFAULT_CACHE_SIZE);
      bdd_setvarnum(DEFAULT_NR_VARIABLES);
    }
  ++nrUsers;
}

void
BddUser::setNrVariables(int nrVariables)
{
  if (nrVariables > bdd_varnum())
    bdd_setvarnum(nrVariables);
}

BddUser::~BddUser()
{
  --nrUsers;
  if (nrUsers == 0)
    bdd_done();
}

void
BddUser::dump(ostream& s, bdd root)
{
  if (root == bdd_false())
    s << "false";
  else if (root == bdd_true())
    s << "true";
  else
    {
      int var = bdd_var(root);
      bdd lo = bdd_low(root);
      if (lo != bdd_false())
	{
	  s << "~x" << var;
	  if (lo != bdd_true())
	    {
	      s << ".(";
	      dump(s, lo);
	      s << ')';
	    }
	}
      bdd hi = bdd_high(root);
      if (hi != bdd_false())
	{
	  if (lo != bdd_false())
	    s << " + ";
	  s << "x" << var;
	  if (hi != bdd_true())
	    {
	      s << ".(";
	      dump(s, hi);
	      s << ')';
	    }
	}
    }
}
