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
#include "higher.hh"
#include "strategyLanguage.hh"

//	interface class definitions
#include "term.hh"

//	core class definitions
#include "cachedDag.hh"
#include "rule.hh"

//	higher class definitions
#include "assignmentConditionFragment.hh"
#include "rewriteConditionFragment.hh"

//	strategy language class definitions
#include "strategicSearch.hh"
#include "strategyExpression.hh"
#include "applicationStrategy.hh"
#include "applicationProcess.hh"
#include "decompositionProcess.hh"

ApplicationProcess::ApplicationProcess(StrategicSearch& searchObject,
				       DagNode* start,
				       ApplicationStrategy* strategy,
				       const StrategyStack& pending,
				       StrategicExecution* taskSibling,
				       StrategicProcess* insertionPoint)


  : StrategicProcess(taskSibling, insertionPoint),
    initial(searchObject.getContext()->makeSubcontext(start)),
    rewriteState(initial,
		 strategy->getLabel(),
		 RewriteSearchState::ALLOW_NONEXEC /*  | RewriteSearchState::IGNORE_CONDITION */,
		 0,
		 strategy->getTop() ? NONE : UNBOUNDED),
    pending(pending),
    strategy(strategy)
{
  Vector<CachedDag>& values = strategy->getValues();
  int nrValues = values.size();
  if (nrValues > 0)
    {
      Vector<Term*> tmpVariables(strategy->getVariables());
      Vector<DagRoot*> tmpValues(nrValues);
      for (int i = 0; i < nrValues; ++i)
	tmpValues[i] = values[i].getDagRoot();
      rewriteState.setInitialSubstitution(tmpVariables, tmpValues);
    }
}

ApplicationProcess::~ApplicationProcess()
{
  //cout << "ApplicationProcess::~ApplicationProcess(): pending size: " << pending.size() << endl;
  delete initial;
}

StrategicExecution::Survival
ApplicationProcess::run(StrategicSearch& searchObject)
{
  if (rewriteState.findNextRewrite())
    {
      if (0 /*rewriteState.getRule()->hasCondition()*/)
	{
	  //
	  //	We need to check the condition in a fair way, given
	  //	that rewrite conditions may have to follow a given strategy
	  //	may not terminate. Also processing the condition may
	  //	bind substitution entries needed to build an instance of
	  //	the rhs of the rule.
	  //
	  return resolveRemainingConditionFragments(searchObject,
						    rewriteState,
						    0,
						    strategy->getStrategies(),
						    0,
						    pending,
						    this,
						    this);
	}
      else
	{
	  if (DagNode* r = doRewrite(rewriteState, *(searchObject.getContext())))
	    {
	      r = searchObject.index2DagNode(searchObject.insert(r));  // protect r from garbage collection
	      (void) new DecompositionProcess(r, pending, this, this);
	      return SURVIVE;  // stick around to look for another rewrite
	    }
	}
    }
  finished(this);
  return DIE;  // request deletion
}

DagNode*
ApplicationProcess::doRewrite(RewriteSearchState& rewriteState,
			      RewritingContext& context)
{
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
  //cout << "ApplicationProcess::doRewrite(): solution: "  << r << endl;

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


StrategicExecution::Survival
ApplicationProcess::resolveRemainingConditionFragments(StrategicSearch& searchObject,
						       RewriteSearchState& rewriteState,
						       int fragmentNr,
						       const Vector<StrategyExpression*>& strategies,
						       int strategyNr,
						       const StrategyStack& pending,
						       StrategicExecution* taskSibling,
						       StrategicProcess* other)
{
  Rule* rule = rewriteState.getRule();
  const Vector<ConditionFragment*>& fragments = rule->getCondition();
  int nrFragments = fragments.size();
  for (;;)
    {
      ConditionFragment* fragment = fragments[fragmentNr];
      if (RewriteConditionFragment* rf = dynamic_cast<RewriteConditionFragment*>(fragment))
	{
	  // need to do a fair search
	  return SURVIVE;
	}
      else if (AssignmentConditionFragment* af = dynamic_cast<AssignmentConditionFragment*>(fragment))
	{
	  // need to do a fair match
	  return SURVIVE;
	}
      //
      //	Since we don't recognize the fragment as needing special treatment, assume it
      //	is branch free and evaluate with a dummy state stack.
      //
      stack<ConditionState*> dummy;
      if (fragment->solve(true, *(rewriteState.getContext()), dummy))
	{
	  ++fragmentNr;
	  if (fragmentNr == nrFragments)
	    {
	      //
	      //	The condition succeeded so now we need to do the rewrite and
	      //	resume the strategy.
	      //
	      if (DagNode* r = doRewrite(rewriteState, *(searchObject.getContext())))
		{
		  r = searchObject.index2DagNode(searchObject.insert(r));  // protect r from garbage collection
		  (void) new DecompositionProcess(r, pending, taskSibling, other);
		  return SURVIVE;  // stick around to look for another rewrite
		}
	      else
		return DIE;
	    }
	}
      else
	break;
    }
  return SURVIVE;;
}
