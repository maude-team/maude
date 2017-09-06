//
//	Class for slightly enhanced BDDs.
//
//	Most importantly Bdds are totally ordered by operator< and
//	can therefore be used a keys in set<>s and map<>s. 
//
#ifndef _bdd_hh_
#define _bdd_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "bdd.h"

class Bdd : public bdd
{
public:
  Bdd();
  Bdd(const bdd& other);

  const Bdd& operator=(const bdd& other);
  bool operator<(const Bdd& other) const;
  bool implies(const Bdd& other) const;
  Bdd extractPrimeImplicant() const;
};

inline
Bdd::Bdd()
{
}

inline
Bdd::Bdd(const bdd& other)
  : bdd(other)
{
} 

inline const Bdd&
Bdd::operator=(const bdd& other)
{
  bdd::operator=(other);
  return *this;
}

inline bool
Bdd::operator<(const Bdd& other) const
{
  return id() < other.id();
}

inline bool
Bdd::implies(const Bdd& other) const
{
  return bdd_imp(*this, other) == bdd_true();
}

#endif
