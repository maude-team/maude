//
//	Class for subproblems to check for equality or inequality of terms,
//	variable bindings and matched portions.
//
#ifndef _equalitySubproblem_hh_
#define _equalitySubproblem_hh_
#include "subproblem.hh"

class EqualitySubproblem : public Subproblem
{
public:
  EqualitySubproblem(int lhsVariable, int rhsVariable, bool checkEqual);
  EqualitySubproblem(const Term* lhsTerm, int rhsVariable, bool checkEqual);
  EqualitySubproblem(int lhsVariable,
		     const ExtensionInfo* rhsExtensionInfo,
		     bool checkEqual);
  EqualitySubproblem(const Term* lhsTerm,
		     const ExtensionInfo* rhsExtensionInfo,
		     bool checkEqual);

  bool solve(bool findFirst, RewritingContext& solution);

private:
  const Term* const lhsTerm;
  const int lhsVariable;
  const ExtensionInfo* const rhsExtensionInfo;
  const int rhsVariable;
  const bool checkEqual;
};

inline
EqualitySubproblem::EqualitySubproblem(int lhsVariable, int rhsVariable, bool checkEqual)
  : lhsTerm(0),
    lhsVariable(lhsVariable),
    rhsExtensionInfo(0),
    rhsVariable(rhsVariable),
    checkEqual(checkEqual)
{
}

inline
EqualitySubproblem::EqualitySubproblem(const Term* lhsTerm, int rhsVariable, bool checkEqual)
  : lhsTerm(lhsTerm),
    lhsVariable(NONE),
    rhsExtensionInfo(0),
    rhsVariable(rhsVariable),
    checkEqual(checkEqual)
{
}

inline
EqualitySubproblem::EqualitySubproblem(int lhsVariable,
				       const ExtensionInfo* rhsExtensionInfo,
				       bool checkEqual)
  : lhsTerm(0),
    lhsVariable(lhsVariable),
    rhsExtensionInfo(rhsExtensionInfo),
    rhsVariable(NONE),
    checkEqual(checkEqual)
{
}

inline
EqualitySubproblem::EqualitySubproblem(const Term* lhsTerm,
				       const ExtensionInfo* rhsExtensionInfo,
				       bool checkEqual)
  : lhsTerm(lhsTerm),
    lhsVariable(NONE),
    rhsExtensionInfo(rhsExtensionInfo),
    rhsVariable(NONE),
    checkEqual(checkEqual)
{
}

#endif
