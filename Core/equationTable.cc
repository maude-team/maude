//
//      Implementation for abstract class EquationTable.
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
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "subproblem.hh"
#include "extensionInfo.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "lhsAutomaton.hh"
#include "rhsAutomaton.hh"
//#include "variableInfo.hh"
#include "equation.hh"
#include "equationTable.hh"

void
EquationTable::compileEquations()
{
  int nrEquations = equations.length();
  for (int i = 0; i < nrEquations; i++)
    equations[i]->compile(true);
}

bool
EquationTable::applyReplace(DagNode* subject,
			    RewritingContext& context,
			    ExtensionInfo* extensionInfo)
{
  Vector<Equation*>::iterator e = equations.end();
  for (Vector<Equation*>::iterator i = equations.begin(); i != e; ++i)
   {
      Subproblem* sp;
      Equation* eq = *i;
      int nrVariables = eq->fastNrVariables();
      if (nrVariables >= 0)
	{
	  //
	  //	Fast case.
	  //
	  context.clear(nrVariables);
	  if (eq->getLhsAutomaton()->match(subject, context, sp, extensionInfo))
	    {
	      if (sp != 0 || RewritingContext::getTraceStatus())
		goto slowCase;
	      if (extensionInfo == 0 || extensionInfo->matchedWhole())
		eq->getRhsBuilder().replace(subject, context);
	      else
		{
		  subject->partialReplace(eq->getRhsBuilder().construct(context),
					  extensionInfo);
		}
	      context.incrementEqCount();
	      context.finished();
	      DagNode::okToCollectGarbage();
	      return true;
	    }
	}
      else
	{
	  //
	  //	General case.
	  //
	  nrVariables = eq->getNrProtectedVariables();
	  context.clear(nrVariables);
	  if (eq->getLhsAutomaton()->match(subject, context, sp, extensionInfo))
	    {
	    slowCase:
	      if (sp == 0 || sp->solve(true, context))
		{
		  if (!(eq->hasCondition()) || eq->checkCondition(subject, context, sp))
		    {
		      bool trace = RewritingContext::getTraceStatus();
		      if (trace)
			{
			  context.tracePreEqRewrite(subject, eq, RewritingContext::NORMAL);
			  if (context.traceAbort())
			    {
			      delete sp;
			      context.finished();
			      break;
			    }
			}
		      if (extensionInfo == 0 || extensionInfo->matchedWhole())
			eq->getRhsBuilder().replace(subject, context);
		      else
			{
			  subject->partialReplace(eq->getRhsBuilder().construct(context),
						  extensionInfo);
			}
		      context.incrementEqCount();
		      if (trace)
			context.tracePostEqRewrite(subject);
		      delete sp;
		      context.finished();
		      MemoryCell::okToCollectGarbage();
		      return true;
		    }
		}
	      delete sp;
	    }
	}
      context.finished();
      MemoryCell::okToCollectGarbage();  // matching process may create new DAG nodes
    }
  return false;
}

#ifdef DUMP
void
EquationTable::dumpEquationTable(ostream& s, int indentLevel)
{
  for (int i = 0; i < equations.length(); i++)
    {
      LhsAutomaton* a = equations[i]->getLhsAutomaton();
      if (a != 0)
	a->dump(s, *(equations[i]), indentLevel);
    }
}
#endif
