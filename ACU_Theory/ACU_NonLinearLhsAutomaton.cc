//
//      Implementation for class ACU_NonLinearLhsAutomaton.
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
#include "ACU_Theory.hh"

//      interface class definitions
#include "associativeSymbol.hh"
#include "dagNode.hh"
#include "term.hh"

//      core class definitions
#include "variableInfo.hh"
#include "substitution.hh"

//      variable class definitions
#include "variableSymbol.hh"
#include "variableTerm.hh"

//	ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_NonLinearLhsAutomaton.hh"
#include "ACU_ExtensionInfo.hh"

ACU_NonLinearLhsAutomaton::ACU_NonLinearLhsAutomaton(ACU_Symbol* topSymbol,
						     int varIndex,
						     int multiplicity,
						     Sort* varSort)
  : topSymbol(topSymbol),
    varIndex(varIndex),
    multiplicity(multiplicity),
    varSort(varSort),
    unitSort(topSymbol->sortBound(varSort) == 1)
{
  Assert(unitSort || topSymbol->sortStructure(varSort) == AssociativeSymbol::PURE_SORT,
	 cerr << "bad sort");
}

void
ACU_NonLinearLhsAutomaton::fillOutExtensionInfo(ACU_DagNode* subject,
						int chosen,
						ACU_ExtensionInfo* extensionInfo)
{
  int nrArgs = subject->argArray.length();
  CONST_ARG_VEC_HACK(ACU_DagNode::Pair, args, subject->argArray);
  if (nrArgs == 1 && args[0].multiplicity == multiplicity)
    extensionInfo->setMatchedWhole(true);
  else
    {
      extensionInfo->setMatchedWhole(false);
      extensionInfo->reset();
      for (int i = 0; i < nrArgs; i++)
	{
	  int m = args[i].multiplicity;
	  extensionInfo->setUnmatched(i, i == chosen ? (m - multiplicity) : m);
	}
    }
  extensionInfo->setValidAfterMatch(true);
}
  
bool
ACU_NonLinearLhsAutomaton::match(DagNode* subject,
				 Substitution& solution,
				 Subproblem*& returnedSubproblem,
				 ExtensionInfo* extensionInfo)
{
  if (subject->symbol() != topSymbol)
    return false;
  if (solution.value(varIndex) != 0)
    return fullMatch(subject, solution, returnedSubproblem, extensionInfo);
  returnedSubproblem = 0;
  ACU_DagNode* s = static_cast<ACU_DagNode*>(subject);
  int nrArgs = s->argArray.length();
  CONST_ARG_VEC_HACK(ACU_DagNode::Pair, args, s->argArray);
  int fastMult = multiplicity;  // register copy to avoid reloading after writes
  if (extensionInfo == 0)
    {
      //
      //	Non-extension cases.
      //
      if (nrArgs == 1 && args[0].multiplicity == fastMult)
	{
	  if (args[0].dagNode->leq(varSort))
	    {
	      solution.bind(varIndex, args[0].dagNode);
	      return true;
	    }
	  return false;
	}
      else
	{
	  if (unitSort)
	    return false;
	  for (int i = 0; i < nrArgs; i++)
	    {
	      if (args[i].multiplicity % fastMult != 0 ||
		  !(args[i].dagNode->leq(varSort)))
		return false;
	    }
	  ACU_DagNode* d = new ACU_DagNode(topSymbol, nrArgs);
	  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
	  for (int i = 0; i < nrArgs; i++)
	    {
	      d->argArray[i].dagNode = args[i].dagNode;
	      d->argArray[i].multiplicity = args[i].multiplicity / fastMult;
	    }
	  if (s->isReduced() && topSymbol->sortConstraintFree())
	    {
	      topSymbol->computeBaseSort(d);
	      d->setReduced();
	    }
	  solution.bind(varIndex, d);
	  return true;
	}
    }
  else
    {
      //
      //	Extension cases.
      //
      ACU_ExtensionInfo* e = static_cast<ACU_ExtensionInfo*>(extensionInfo);
      e->setValidAfterMatch(true);
      if (unitSort)
	{
	  for (int i = 0; i < nrArgs; i++)
	    {
	      if (args[i].multiplicity >= fastMult &&
		  args[i].dagNode->leq(varSort))
		{
		  solution.bind(varIndex, args[i].dagNode);
		  fillOutExtensionInfo(s, i, e);
		  return true;
		}
	    }
	  return false;
	}
      else
	{
	  int size = 0;
	  int last = NONE;
	  for (int i = 0; i < nrArgs; i++)
	    {
	      if (args[i].multiplicity >= fastMult &&
		  args[i].dagNode->leq(varSort))
		{
		  ++size;
		  last = i;
		}
	    }
	  if (last != NONE)
	    {
	      if (size == 1 && args[last].multiplicity < 2 * fastMult)
		{
		  solution.bind(varIndex, args[last].dagNode);
		  fillOutExtensionInfo(s, last, e);
		}
	      else
		{
		  ACU_DagNode* d = new ACU_DagNode(topSymbol, size);
		  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
		  int p = 0;
		  e->reset();
		  bool whole = true;
		  for (int i = 0; i < nrArgs; i++)
		    {
		      int m = args[i].multiplicity;
		      if (m >= fastMult && args[i].dagNode->leq(varSort))
			{
			  int rem = m % fastMult;
			  int result = m / fastMult;
			  d->argArray[p].dagNode = args[i].dagNode;
			  d->argArray[p].multiplicity = result;
			  ++p;
			  e->setUnmatched(i, rem);
			  if (rem != 0)
			    whole = false;
			}
		      else
			{
			  e->setUnmatched(i, m);
			  whole = false;
			}
		    }
		  Assert(p == size, cerr << "arg list mismatch");
		  e->setMatchedWhole(whole);
		  e->setValidAfterMatch(true);
		  if (s->isReduced() && topSymbol->sortConstraintFree())
		    {
		      topSymbol->computeBaseSort(d);
		      d->setReduced();
		    }
		  solution.bind(varIndex, d);
		}
	      return true;
	    }
	}
    }
  return false;
}

#ifdef DUMP
void
ACU_NonLinearLhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{ACU_NonLinearLhsAutomaton}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "topSymbol = \"" << topSymbol <<
    "\tvarIndex = " << varIndex << " \"" << variableInfo.index2Variable(varIndex) <<
    "\tmultiplicity = " << multiplicity << '\n';
  s << Indent(indentLevel) << "varSort = " << varSort <<
    "\tunitSort = " << unitSort << '\n';
  HeuristicLhsAutomaton::dump(s, variableInfo, indentLevel);
  s << Indent(indentLevel - 1) << "End{ACU_NonLinearLhsAutomaton}\n";
}
#endif
