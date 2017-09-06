//
//      Implementation for class ACU_VarLhsAutomaton.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "indent.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "ACU_Theory.hh"
#include "ACU_RedBlack.hh"

//      interface class definitions
#include "associativeSymbol.hh"
#include "dagNode.hh"
//#include "term.hh"
#include "extensionInfo.hh"

//      core class definitions
#include "variableInfo.hh"
#include "substitution.hh"

//      variable class definitions
#include "variableSymbol.hh"
#include "variableTerm.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_VarLhsAutomaton.hh"

//	ACU Red-Black class definitions
#include "ACU_TreeDagNode.hh"
#include "ACU_SlowIter.hh"

ACU_VarLhsAutomaton::ACU_VarLhsAutomaton(ACU_Symbol* topSymbol,
					 bool collapsePossible,
					 VariableTerm* stripper,
					 VariableTerm* collector)
  : ACU_CollectorLhsAutomaton(collector),
    topSymbol(topSymbol),
    collapsePossible(collapsePossible),
    stripperVarIndex(stripper->getIndex()),
    stripperSort(stripper->getSort())
{
}

bool
ACU_VarLhsAutomaton::match(DagNode* subject,
			   Substitution& solution,
			   Subproblem*& returnedSubproblem,
			   ExtensionInfo* extensionInfo)
{
  if (collectorFree(solution))
    {
      if (subject->symbol() == topSymbol)
	{
	  //
	  //	Non-collapse case.
	  //
	  if (solution.value(stripperVarIndex) == 0)
	    {
	      if (safeCast(ACU_BaseDagNode*, subject)->isTree())
		{
		  ACU_TreeDagNode* s = safeCast(ACU_TreeDagNode*, subject);
		  ACU_SlowIter i(s->getRoot());
		  do
		    {
		      DagNode* d = i.getDagNode();
		      if (d->leq(stripperSort))
			{
			  if (collect(i, s, solution))
			    {
			      solution.bind(stripperVarIndex, d);
			      returnedSubproblem = 0;
			      if (extensionInfo)
				extensionInfo->setMatchedWhole(true);
			      return true;
			    }
			}
		      i.next();
		    }
		  while (i.valid());
		  return false;
		}
	      else
		{
		  ACU_DagNode* s = safeCast(ACU_DagNode*, subject);
		  int nrArgs = s->argArray.length();
		  for (int i = 0; i < nrArgs; i++)
		    {
		      DagNode* d = s->argArray[i].dagNode;
		      if (d->leq(stripperSort))
			{
			  if (collect(i, s, solution))
			    {
			      solution.bind(stripperVarIndex, d);
			      returnedSubproblem = 0;
			      if (extensionInfo)
				extensionInfo->setMatchedWhole(true);
			      return true;
			    }
			  return fullMatch(subject, solution, returnedSubproblem, extensionInfo);
			}
		    }
		  return false;
		}
	    }
	}
      else
	{
	  //
	  //	Collapse case.
	  //
	  if (!collapsePossible)
	    return false;
	  Assert(extensionInfo == 0 &&
		 subject->getSortIndex() != Sort::SORT_UNKNOWN,
		 cerr << "collapse to top not handled by ACU_VarLhsAutomaton");
	  DagNode* d = solution.value(stripperVarIndex);
	  if (d == 0)
	    {
	      if (!(subject->leq(stripperSort)))
		return false;
	      solution.bind(stripperVarIndex, subject);
	    }
	  else
	    {
	      if (!(d->equal(subject)))
		return false;
	    }
	  returnedSubproblem = 0;
	  collapse(topSymbol, solution);
	  return true;
	}
    }
  return fullMatch(subject, solution, returnedSubproblem, extensionInfo);
}

#ifdef DUMP
void
ACU_VarLhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{ACU_VarLhsAutomaton}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "topSymbol = \"" << topSymbol <<
    "\"\tcollapsePossible = " << collapsePossible << '\n' <<
    "stripperVarIndex = " << stripperVarIndex <<
    " \"" << variableInfo.index2Variable(stripperVarIndex) << '"' <<
    "\tstripperSort = \"" << stripperSort << "\"\n";
  ACU_CollectorLhsAutomaton::dump(s, variableInfo, indentLevel);
  s << Indent(indentLevel - 1) << "End{ACU_VarLhsAutomaton}\n";
}
#endif
