//
//      Implementation for class ACU_GndLhsAutomaton.
//

//	utility stuff
#include "macros.hh"
#include "indent.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "ACU_Persistent.hh"
#include "ACU_Theory.hh"

//      interface class definitions
#include "associativeSymbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "extensionInfo.hh"

//      core class definitions
#include "substitution.hh"

//	ACU Red-Black class definitions
#include "ACU_SlowIter.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_GndLhsAutomaton.hh"
#include "ACU_TreeDagNode.hh"

ACU_GndLhsAutomaton::ACU_GndLhsAutomaton(ACU_Symbol* symbol,
					 bool matchAtTop,
					 bool collapsePossible,
					 int nrVariables,
					 Term* stripperTerm,
					 VariableTerm* collector)
  : ACU_CollectorLhsAutomaton(symbol,
			      matchAtTop,
			      collapsePossible,
			      nrVariables,
			      collector),
  stripperTerm(stripperTerm)
{
  Assert(stripperTerm->ground(), "stripper term must be ground");
}

bool
ACU_GndLhsAutomaton::match(DagNode* subject,
			   Substitution& solution,
			   Subproblem*& returnedSubproblem,
			   ExtensionInfo* extensionInfo)
{
  if (collectorFree(solution))
    {
      if (subject->symbol() == getSymbol())
	{
	  //
	  //	Non-collapse case.
	  //
	  if (safeCast(ACU_BaseDagNode*, subject)->isTree())
	    {
	      //
	      //	Red-black case.
	      //
	      ACU_TreeDagNode* s = safeCast(ACU_TreeDagNode*, subject);
	      ACU_SlowIter i;
	      if (!(s->getTree().find(stripperTerm, i)))
		return false;
	      if (collect(i, s, solution))
		{
		  returnedSubproblem = 0;
		  if (extensionInfo)
		    {
		      extensionInfo->setValidAfterMatch(true);
		      extensionInfo->setMatchedWhole(true);
		    }
		  return true;
		}
	    }
	  else
	    {
	      //
	      //	ArgVec case.
	      //
	      ACU_DagNode* s = safeCast(ACU_DagNode*, subject);
	      int pos;
	      if (!(s->binarySearch(stripperTerm, pos)))
		return false;
	      if (collect(pos, s, solution))
		{
		  returnedSubproblem = 0;
		  if (extensionInfo)
		    {
		      extensionInfo->setValidAfterMatch(true);
		      extensionInfo->setMatchedWhole(true);
		    }
		  return true;
		}
	    }
	  if (extensionInfo == 0)
	    return false;  // no extension implies true failure
	}
      else
	{
	  //
	  //	Collapse case.
	  //
	  if (!getCollapsePossible())
	    return false;
	  Assert(extensionInfo == 0 &&
		 subject->getSortIndex() != Sort::SORT_UNKNOWN,
		 "collapse to top not handled by ACU_GndLhsAutomaton");
	  if (!(stripperTerm->equal(subject)))
	    return false;
	  returnedSubproblem = 0;
	  collapse(solution);
	  return true;
	}
    }
  return ACU_LhsAutomaton::match(subject, solution, returnedSubproblem, extensionInfo);
}

#ifdef DUMP
void
ACU_GndLhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{ACU_GndLhsAutomaton}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "stripperTerm = \"" << stripperTerm << '\n';
  ACU_CollectorLhsAutomaton::dump(s, variableInfo, indentLevel);
  s << Indent(indentLevel - 1) << "End{ACU_GndLhsAutomaton}\n";
}
#endif
