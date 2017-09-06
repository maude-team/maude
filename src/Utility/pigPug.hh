/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2014 SRI International, Menlo Park, CA 94025, USA.

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
//	Class to implement a modified PIG-PUG to solve strict left-linear
//	associative unification problems with constraints on variables.
//
//	Variables in lhs must have a constraint other than NONE or must occur
//	exactly once in the equation.
//

#ifndef _pigPug_hh_
#define _pigPug_hh_
//#include <map>
#include <list>
#include "natSet.hh"

class PigPug
{
public:
  enum Constraints
    {
      ELEMENT = -2,
    };
  //
  //	Constraint for each variable is ELEMENT, NONE or non-negative integer indexing a (collapse-free) theory.
  //
  typedef Vector<int> ConstraintMap;

  typedef Vector<int> Word;
  typedef Vector<Word> Subst;

  PigPug(const Word& lhs,
	 const Word& rhs,
	 const ConstraintMap& constraintMap,
	 int lastOriginalVariable,
	 int freshVariableStart);

  //
  //	Returns NONE, or the index for the next unused variable, and fills out unifier.
  //
  int getNextUnifier(Subst& unifier);

private:
  enum Moves
    {
      INC_RHS = 1,
      INC_LHS = 2,
      MOVES = INC_RHS | INC_LHS,
      //
      //	3 basic moves.
      //
      RHS_PEEL = 1,
      LHS_PEEL = 2,
      EQUATE = 3,
      //
      //	We OR this flag with EQUATE to indicate that the rhs variable
      //	was instantiated rather than the lhs variable (the usual case).
      //	This happens when the rhs variable is strictly less constrained
      //	than the lhs variable.
      //
      RHS_ASSIGN = 4,
      //
      //	We OR this flag with RHS_PEEL or EQUATE to record the fact
      //	that a modified lhs unificand was pushed on the stack.
      //
      PUSH_LHS = 8,
      //
      //	We OR this flag with LHS_PEEL or EQUATE to record the fact
      //	that a modified rhs unificand was pushed on the stack.
      //
      PUSH_RHS = 16
    };

  enum Result
    {
      FAIL = 0,		// move failed
      LHS_DONE = 1,	// move reduced lhs (and possibly rhs) to a single variable
      RHS_DONE = 2,	// move reduced rhs (but not lhs) to a single variable
      OK = 4		// move succeeded without hitting an end case
    };

  struct Unificand
  {
    int index;
    Word word;
  };

  typedef list<Unificand> UnificandStack;
  typedef Vector<int> Path;
  typedef Vector<int> VariableRenaming;

  Result rhsPeel();
  bool checkUnificand(UnificandStack& unificandStack, int oldVar, int newVar);
  Result equate();
  bool checkUnificand2(UnificandStack& unificandStack, int oldVar, int newVar);
  Result lhsPeel();
  Result cancel();

  bool fullyConstrained(const Unificand& unificand);
  bool feasible();

  int undoMove();
  int firstMove();
  int nextMove();
  int completed(int status);
  int run(int result);

  int extractUnifier(Subst& unifier);
  void compose(Subst& subst, int oldVar, int replacement);
  void compose2(Subst& subst, int oldVar, int replacement);
  void compose(Subst& subst, int oldVar, const Word& replacement, int index);
  void renameVariables(Subst& subst, const VariableRenaming& variableRenaming);
  void collectRangeVariables(const Subst& subst, NatSet& occursInRange);

  void dump(Subst& s);

  const ConstraintMap& constraintMap;
  int lastOriginalVariable;
  int freshVariableStart;

  UnificandStack lhsStack;
  UnificandStack rhsStack;
  Path path;
};

#endif
