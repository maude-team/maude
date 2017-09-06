//
//      Implementation for abstract class RuleTable.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
//#include "symbol.hh"
//#include "dagNode.hh"
#include "term.hh"
#include "subproblem.hh"
#include "extensionInfo.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "lhsAutomaton.hh"
#include "rhsAutomaton.hh"
#include "rule.hh"
#include "ruleTable.hh"

RuleTable::RuleTable()
{
  nextRule = 0;
}

void
RuleTable::compileRules()
{
  int nrRules = rules.length();
  for (int i = 0; i < nrRules; i++)
    rules[i]->compile(true);
  nextRule = 0;
}

DagNode*
RuleTable::ruleRewrite(DagNode* subject, RewritingContext& context)
{
  return applyRules(subject, context, 0);
}

DagNode*
RuleTable::applyRules(DagNode* subject,
		      RewritingContext& context,
		      ExtensionInfo* extensionInfo)
{
  Assert(subject->getSortIndex() != Sort::SORT_UNKNOWN, cerr << "sort unknown");
  int nrRules = rules.length();
  int n = nextRule;
  for (int i = 0; i < nrRules; i++, n++)
    {
      if (n >= nrRules)
	n = n - nrRules;
      Rule* rl = rules[n];
      if (!(rl->getUnboundVariables().empty()))
	continue;
      int nrVariables = rl->getNrProtectedVariables();
      context.clear(nrVariables);
      Subproblem* sp;
      if (rl->getLhsAutomaton()->match(subject, context, sp, extensionInfo))
	{
	  if (sp == 0 || sp->solve(true, context))
	    {
	      if (!(rl->hasCondition()) || rl->checkCondition(subject, context, sp))
		{
		  DagNode* r;
		  if (RewritingContext::getTraceStatus())
		    {
		      context.tracePreRuleRewrite(subject, rl);
		      if (context.traceAbort())
			{
			  delete sp;
			  context.finished();
			  return subject;
			}
		    }
		  if (extensionInfo == 0 || extensionInfo->matchedWhole())
		    r =  rl->getRhsBuilder().construct(context);
		  else
		    {
		      r = subject->partialConstruct(rl->getRhsBuilder().construct(context),
						    extensionInfo);
		    }
		  context.incrementRlCount();
		  delete sp;
		  context.finished();
		  nextRule = n + 1;
		  return r;
		}
	    }
	  delete sp;
	}
      context.finished();
    }
  return 0;
}
