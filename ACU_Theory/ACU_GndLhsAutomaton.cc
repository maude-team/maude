//
//      Implementation for class ACU_GndLhsAutomaton.
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

//      interface class definitions
#include "associativeSymbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "extensionInfo.hh"

//      core class definitions
//#include "variableInfo.hh"
#include "substitution.hh"

//      variable class definitions
//#include "variableSymbol.hh"
//#include "variableTerm.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_GndLhsAutomaton.hh"

ACU_GndLhsAutomaton::ACU_GndLhsAutomaton(ACU_Symbol* topSymbol,
					 bool collapsePossible,
					 Term* stripperTerm,
					 VariableTerm* collector)
  : ACU_CollectorLhsAutomaton(collector),
    topSymbol(topSymbol),
    collapsePossible(collapsePossible),
    stripperTerm(stripperTerm)
{
}

bool
ACU_GndLhsAutomaton::match(DagNode* subject,
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
	  ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
	  int pos;
	  if (!(s->binarySearch(stripperTerm, pos)))
	    return false;
	  if (collect(pos, s, solution))
	    {
	      returnedSubproblem = 0;
	      if (extensionInfo)
		extensionInfo->setMatchedWhole(true);
	      return true;
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
		 cerr << "collapse to top not handled by ACU_GndLhsAutomaton");
	  if (!(stripperTerm->equal(subject)))
	    return false;
	  returnedSubproblem = 0;
	  collapse(topSymbol, solution);
	  return true;
	}
    }
  return fullMatch(subject, solution, returnedSubproblem, extensionInfo);
}

#ifdef DUMP
void
ACU_GndLhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{ACU_GndLhsAutomaton}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "topSymbol = \"" << topSymbol <<
    "\"\tcollapsePossible = " << collapsePossible << '\n' <<
    "stripperTerm = \"" << stripperTerm << "\"\n";
  ACU_CollectorLhsAutomaton::dump(s, variableInfo, indentLevel);
  s << Indent(indentLevel - 1) << "End{ACU_GndLhsAutomaton}\n";
}
#endif

