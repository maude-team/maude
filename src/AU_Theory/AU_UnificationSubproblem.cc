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
//      Implementation for class ACU_UnificationSubproblem2.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "AU_Persistent.hh"
#include "AU_Theory.hh"

//      interface class definitions
#include "argVec.hh"
#include "associativeSymbol.hh"
#include "dagNode.hh"
#include "subproblem.hh"

//      core class definitions
#include "variableInfo.hh"
#include "unificationContext.hh"
#include "localBinding.hh"

//	variable class definitions
#include "variableSymbol.hh"
#include "variableDagNode.hh"

//	AU theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"
#include "AU_UnificationSubproblem.hh"

#define FOR_EACH(var, conType, container) \
const conType::iterator var##_end = (container).end(); \
for (conType::iterator var = (container).begin(); var != var##_end; ++var)


AU_UnificationSubproblem::AU_UnificationSubproblem(AU_Symbol* topSymbol)
  : topSymbol(topSymbol),
    preSolveSubstitution(0),
    savedSubstitution(0)
{
}

AU_UnificationSubproblem::~AU_UnificationSubproblem()
{
  FOR_EACH_CONST(i, Vector<Unification>, unifications)
    delete i->problem;
}

void
AU_UnificationSubproblem::addUnification(DagNode* lhs, DagNode* rhs, bool marked, UnificationContext& solution)
{
  Assert(lhs->symbol() == topSymbol, "bad lhs dag " << lhs);
  Assert(topSymbol->hasIdentity() ||
	 rhs->symbol() == topSymbol ||
	 dynamic_cast<VariableDagNode*>(rhs) != 0, "bad rhs for for non-collapse theory " << rhs);
  Assert(topSymbol->hasIdentity() || !marked, "bad mark for non-collapse theory");

  int nrUnifications = unifications.size();
  unifications.expandTo(nrUnifications + 1);
  unifications[nrUnifications].lhs = lhs;
  unifications[nrUnifications].rhs = rhs;
  unifications[nrUnifications].problem = 0;
}

void
AU_UnificationSubproblem::markReachableNodes()
{
  //
  //	New unification algorithm creates new local problems and replaces dags in
  //	old unification problems. Thus we can't rely on the pending unification stack
  //	for protection of dag nodes in problems.
  //
  FOR_EACH_CONST(i, Vector<Unification>, unifications)
    {
      i->lhs->mark();
      i->rhs->mark();
    }
  //
  //	Protect dags in preSolveSubstitution.
  //
  int nrFragile = preSolveSubstitution.nrFragileBindings();
  for (int i = 0; i < nrFragile; i++)
    {
      DagNode* d = preSolveSubstitution.value(i);
      if (d != 0)
	d->mark();
    }
  //
  //	No need to mark savedSubstitution since its dags are a subset of those in
  //	the current substitution.
  //
}

#include "AU_OldUnificationAlgorithm.cc"
#include "AU_NewUnificationAlgorithm.cc"
