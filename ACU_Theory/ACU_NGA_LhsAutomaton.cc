//
//      Implementation for class ACU_NGA_LhsAutomaton.
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
#include "subproblem.hh"
#include "extensionInfo.hh"

//      core class definitions
#include "substitution.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_NGA_LhsAutomaton.hh"

//	ACU Red-Black class definitions
#include "ACU_TreeDagNode.hh"
#include "ACU_SlowIter.hh"

ACU_NGA_LhsAutomaton::ACU_NGA_LhsAutomaton(ACU_Symbol* topSymbol,
					   bool collapsePossible,
					   LhsAutomaton* stripperAutomaton,
					   Term* stripperTerm,
					   int nrVariables,
					   VariableTerm* collector)
  : ACU_CollectorLhsAutomaton(collector),
    topSymbol(topSymbol),
    collapsePossible(collapsePossible),
    stripperAutomaton(stripperAutomaton),
    stripperTerm(stripperTerm),
    local(nrVariables)
{
}

ACU_NGA_LhsAutomaton::~ACU_NGA_LhsAutomaton()
{
  delete stripperAutomaton;
}

bool
ACU_NGA_LhsAutomaton::match(DagNode* subject,
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
	  if (safeCast(ACU_BaseDagNode*, subject)->isTree())
	    {
	      //
	      //	Red-black case.
	      //
	      ACU_TreeDagNode* s = safeCast(ACU_TreeDagNode*, subject);
	      ACU_SlowIter i;
	      if (ACU_RedBlackNode::findFirstPotentialMatch(s->getRoot(),
							    stripperTerm,
							    solution,
							    i))
		{
		  DagNode* d = i.getDagNode();
		  for(;;)
		    {
		      local.copy(solution);
		      if (stripperAutomaton->match(d, local, returnedSubproblem))
			{
			  if (returnedSubproblem == 0)
			    {
			      if (collect(i, s, local))
				{
				  if (extensionInfo)
				    extensionInfo->setMatchedWhole(true);
				  solution.copy(local);
				  return true;
				}
			    }
			  else
			    delete returnedSubproblem;
			  return fullMatch(subject,
					   solution,
					   returnedSubproblem,
					   extensionInfo);
			}
		      i.next();
		      if (!i.valid())
			break;
		      d = i.getDagNode();
		      if (stripperTerm->partialCompare(solution, d) == Term::GREATER)
			break;
		    }
		}
	      else
		return false;
	    }
	  else
	    {
	      //
	      //	ArgVec case.
	      //
	      ACU_DagNode* s = safeCast(ACU_DagNode*, subject);
	      int nrArgs = s->argArray.length();
	      int i = s->findFirstPotentialMatch(stripperTerm, solution);
	      if (i >= nrArgs)
		return false;
	      DagNode* d = s->argArray[i].dagNode;
	      for (;;)
		{
		  local.copy(solution);
		  if (stripperAutomaton->match(d, local, returnedSubproblem))
		    {
		      if (returnedSubproblem == 0)
			{
			  if (collect(i, s, local))
			    {
			      if (extensionInfo)
				extensionInfo->setMatchedWhole(true);
			      solution.copy(local);
			      return true;
			    }
			}
		      else
			delete returnedSubproblem;
		      return fullMatch(subject, solution, returnedSubproblem, extensionInfo);
		    }
		  ++i;
		  if (i >=  nrArgs)
		    break;
		  d = s->argArray[i].dagNode;
		  if (stripperTerm->partialCompare(solution, d) == Term::GREATER)
		    break;
		}
	      return false;
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
		 cerr << "collapse to top not handled by ACU_NGA_LhsAutomaton");
	  if (!(stripperAutomaton->match(subject, solution, returnedSubproblem)))
	    return false;
	  collapse(topSymbol, solution);
	  return true;
	}
    }
  return fullMatch(subject, solution, returnedSubproblem, extensionInfo);
}

#ifdef DUMP
void
ACU_NGA_LhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{ACU_NGA_LhsAutomaton}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "topSymbol = \"" << topSymbol <<
    "\"\tcollapsePossible = " << collapsePossible << '\n' <<
    "\tstripperTerm = \"" << stripperTerm << "\"\n";
  s << Indent(indentLevel) << "stripperAutomaton =\n";
  stripperAutomaton->dump(s, variableInfo, indentLevel + 1);
  ACU_CollectorLhsAutomaton::dump(s, variableInfo, indentLevel);
  s << Indent(indentLevel - 1) << "End{ACU_NGA_LhsAutomaton}\n";
}
#endif
