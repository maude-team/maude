//
//	Class to manage a single BDD package for multiple users.
//
#ifndef _bddUser_hh_
#define _bddUser_hh_
#include "bdd.h"

class BddUser
{
public:
  BddUser();
  ~BddUser();

  static bdd ithvar(int i);
  static bdd nithvar(int i);
  static void setNrVariables(int nrVariables);
  static void dump(ostream& s, bdd root);

private:
  enum Constants
  {
    DEFAULT_NODE_SIZE = 1000,
    DEFAULT_CACHE_SIZE = 100,
    DEFAULT_NR_VARIABLES = 10
  };

  static int nrUsers;
};

inline bdd
BddUser::ithvar(int i)
{
  if (i >= bdd_varnum())
    bdd_setvarnum(i + 1);
  return bdd_ithvar(i);
}

inline bdd
BddUser::nithvar(int i)
{
  if (i >= bdd_varnum())
    bdd_setvarnum(i + 1);
  return bdd_nithvar(i);
}

#endif
