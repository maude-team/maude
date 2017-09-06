/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2006 SRI International, Menlo Park, CA 94025, USA.

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
//      Implementation for abstract class Strategy.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "strategyLanguage.hh"

//	interface class definitions
#include "term.hh"

//	strategy language class definitions
#include "strategyExpression.hh"
#include "applicationSetGenerator.hh"

ApplicationSetGenerator::ApplicationSetGenerator(DagNode* start,
						 RewritingContext& context,
						 int label,
						 const Vector<Term*>& variables,
						 Vector<CachedDag>& values)
  : context(context),
    initial(context.makeSubcontext(start)),
    rewriteState(initial, label, RewriteSearchState::ALLOW_NONEXEC)
{
  int nrValues = values.size();
  if (nrValues > 0)
    {
      Vector<Term*> tmpVariables(variables);
      int nrValues = values.size();
      Vector<DagRoot*> tmpValues(nrValues);
      for (int i = 0; i < nrValues; ++i)
	tmpValues[i] = values[i].getDagRoot();
      rewriteState.setInitialSubstitution(tmpVariables, tmpValues);
    }
}

ApplicationSetGenerator::~ApplicationSetGenerator()
{
  delete initial;
}

DagNode*
ApplicationSetGenerator::findNextSolution()
{
  if (!(rewriteState.findNextRewrite()))
    return 0;

  rewriteState.transferCount(context);
  Rule* rule = rewriteState.getRule();
  bool trace = RewritingContext::getTraceStatus();
  if (trace)
    {
      context.tracePreRuleRewrite(rewriteState.getDagNode(), rule);
      if (context.traceAbort())
	return 0;
    }

  DagNode* replacement = rewriteState.getReplacement();
  DagNode* r = rewriteState.rebuildDag(replacement);
  RewritingContext* c = context.makeSubcontext(r);
  context.incrementRlCount();
  if (trace)
    {
      c->tracePostRuleRewrite(replacement);
      if (c->traceAbort())
	{
	  delete c;
	  return 0;
	}
    }
  c->reduce();
  if (c->traceAbort())
    {
      delete c;
      return 0;
    }
  context.addInCount(*c);
  delete c;
  return r;
}
