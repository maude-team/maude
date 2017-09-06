/*

    This file is part of the Maude 2 interpreter.

    Copyright 2014 SRI International, Menlo Park, CA 94025, USA.

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
//      Class for searching for 1-step rewrites modulo SMT.
//
#ifndef _SMT_RewriteSearchState_hh_
#define _SMT_RewriteSearchState_hh_
#include "gmpxx.h"
#include "cacheableState.hh"
#include "simpleRootContainer.hh"
#include "natSet.hh"

class SMT_RewriteSearchState :
  public CacheableState, // HACK
  private SimpleRootContainer
{
public:
  enum Flags
  {
    GC_CONTEXT = 2,		// delete context in our dtor
    GC_ENGINE = 4		// delete SMT engine in our dtor
  };

  SMT_RewriteSearchState(RewritingContext* context,
			 const SMT_Info& smtInfo,
			 SMT_VariableManager& variableManager,
			 const mpz_class& avoidVariableNumber = 0,  // variable numbers <= this will be avoided
			 int flags = 0 /* UGLY HACK */);
  ~SMT_RewriteSearchState();

  bool findNextRewrite();
  DagNode* getNewPair() const;
  const mpz_class& getMaxVariableNumber() const;  // max variable number in new pair
  RewritingContext* getContext() const;

private:
  void markReachableNodes();

  bool checkAndConvertState();
  bool nextSolution();
  bool checkConsistancy();
  bool instantiateCondition(const Vector<ConditionFragment*>& condition, DagNode*& instantiation);

  RewritingContext* const context;  // context with substitution
  const SMT_Info& smtInfo;  // information about SMT sort; might get folded into wrapper
  SMT_VariableManager& variableManager;  // wrapper to call the SMT engine
  const mpz_class avoidVariableNumber;
  //
  //	Information extracted from starting pair.
  //
  DagNode* state;
  DagNode* constraint;
  FreeSymbol* pairingSymbol;  // determined from initial state
  //
  //	Current state of search.
  //
  int ruleIndex;  // index of rule currently being consisdered
  Rule* currentRule;  // pointer to rule currently being considered
  Subproblem* matchingSubproblem;  // matching subproblem associated with current rule
  NatSet boundToFresh;  // indices of variables that are currently bound to freshly created variables
  //
  //	Most recent result.
  //
  mpz_class newVariableNumber;  // number that is greater than that of any generated variable in nextPair
  DagNode* nextPair;  // valid after findNextRewrite() returns true
  //
  //	Temporary Hack
  //
  const int flags;
};

inline RewritingContext*
SMT_RewriteSearchState::getContext() const
{
  return context;
}

inline DagNode*
SMT_RewriteSearchState::getNewPair() const
{
  return nextPair;
}

inline const mpz_class&
SMT_RewriteSearchState::getMaxVariableNumber() const
{
  return newVariableNumber;
}

#endif
