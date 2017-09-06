//
// 	Abstract base class for binary symbols with attributes.
//	This class adds extra functionality needed by:
//	(1) commutative function symbols;
//	(2) idempotent function symbols; and
//	(3) function symbols with an identity.
//
#ifndef _binarySymbol_hh_
#define _binarySymbol_hh_
#include "symbol.hh"
#include "term.hh"
#include "cachedDag.hh"

class BinarySymbol : public Symbol
{
public:
  //
  //	Distinguishing arguments for permutative function symbols is not possible
  //	so only three strategies make sense.
  //
  enum PermuteStrategy
  {
    EAGER,              // [strat (1 2 0)]
    SEMI_EAGER,         // [strat (0 1 2 0)]
    LAZY                // [strat (0)]
  };

  BinarySymbol(int id, bool memoFlag, Term* identity = 0);

  void setPermuteStrategy(const Vector<int>& userStrategy);
  PermuteStrategy getPermuteStrategy() const;
  void setPermuteFrozen(const NatSet& frozen);
  void setIdentity(Term* id);
  Term* getIdentity() const;
  DagNode* getIdentityDag();
  bool mightMatchOurIdentity(const Term* subterm) const;
  bool takeIdentity(const Sort* sort);
  bool interSymbolPass();
  void reset();

protected:
  void commutativeSortCompletion();
  void idempotentSortCheck();
  void processIdentity();
  void leftIdentitySortCheck();
  void rightIdentitySortCheck();

private:
  enum IdentityStatus
  {
    NOT_NORMALIZED,
    IN_PROCESS,
    NORMALIZED
  };

  PermuteStrategy permuteStrategy;
  CachedDag identityTerm;
};

inline BinarySymbol::PermuteStrategy
BinarySymbol::getPermuteStrategy() const
{
  return permuteStrategy;
}

inline void
BinarySymbol::setIdentity(Term* id)
{
  Assert(identityTerm.getTerm() == 0, "overwriting identity for " << this);
  identityTerm.setTerm(id);
}

inline Term*
BinarySymbol::getIdentity() const
{
  return identityTerm.getTerm();
}

inline bool
BinarySymbol::takeIdentity(const Sort* sort)
{
  Term* id = identityTerm.getTerm();
  return id != 0 && id->leq(sort);
}

inline DagNode*
BinarySymbol::getIdentityDag()
{
  Assert(identityTerm.getTerm() != 0, "null identity for symbol " << this);
  return identityTerm.getDag();
}


#endif
