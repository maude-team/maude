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
ACU_NonLinearLhsAutomaton::
fillOutExtensionInfo(ACU_DagNode* subject,
		     const ArgVec<ACU_DagNode::Pair>::const_iterator chosen,
		     ACU_ExtensionInfo* extensionInfo)
{
  int nrArgs = subject->argArray.length();
  ArgVec<ACU_DagNode::Pair>::const_iterator args = subject->argArray.begin();

  if (nrArgs == 1 && args->multiplicity == multiplicity)
    extensionInfo->setMatchedWhole(true);
  else
    {
      extensionInfo->setMatchedWhole(false);
      extensionInfo->reset();
      for (int i = 0; i < nrArgs; i++, ++args)
	{
	  int m = args->multiplicity;
	  extensionInfo->setUnmatched(i, args == chosen ? (m - multiplicity) : m);
	}
      Assert(args == subject->argArray.end(), cerr << "iterator inconsistent");
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
  int fastMult = multiplicity;  // register copy to avoid reloading after writes
  if (extensionInfo == 0)
    {
      //
      //	Non-extension cases.
      //
      const ArgVec<ACU_DagNode::Pair>::const_iterator b = s->argArray.begin();
      if (nrArgs == 1 && b->multiplicity == fastMult)
	{
	  if (b->dagNode->leq(varSort))
	    {
	      solution.bind(varIndex, b->dagNode);
	      return true;
	    }
	  return false;
	}
      else
	{
	  if (unitSort)
	    return false;
	  const ArgVec<ACU_DagNode::Pair>::const_iterator ei = s->argArray.end();
	  for (ArgVec<ACU_DagNode::Pair>::const_iterator i = b; i != ei; ++i)
	    {
	      if (i->multiplicity % fastMult != 0 ||
		  !(i->dagNode->leq(varSort)))
		return false;
	    }
	  ACU_DagNode* d = new ACU_DagNode(topSymbol, nrArgs);
	  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
	  ArgVec<ACU_DagNode::Pair>::iterator j = d->argArray.begin();
	  for (ArgVec<ACU_DagNode::Pair>::const_iterator i = b; i != ei; ++i, ++j)
	    {
	      j->dagNode = i->dagNode;
	      j->multiplicity = i->multiplicity / fastMult;
	    }
	  Assert(j == d->argArray.end(), cerr << "arg list mismatch");
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
      const ArgVec<ACU_DagNode::Pair>::const_iterator ei = s->argArray.end();
      ACU_ExtensionInfo* e = static_cast<ACU_ExtensionInfo*>(extensionInfo);
      e->setValidAfterMatch(true);
      if (unitSort)
	{
	  for (ArgVec<ACU_DagNode::Pair>::const_iterator i = s->argArray.begin();
	       i != ei; ++i)
	    {
	      if (i->multiplicity >= fastMult &&
		  i->dagNode->leq(varSort))
		{
		  solution.bind(varIndex, i->dagNode);
		  fillOutExtensionInfo(s, i, e);
		  return true;
		}
	    }
	  return false;
	}
      else
	{
	  int size = 0;
	  ArgVec<ACU_DagNode::Pair>::const_iterator last;
	  for (ArgVec<ACU_DagNode::Pair>::const_iterator i = s->argArray.begin();
	       i != ei; ++i)
	    {
	      if (i->multiplicity >= fastMult &&
		  i->dagNode->leq(varSort))
		{
		  ++size;
		  last = i;
		}
	    }
	  if (size > 0)
	    {
	      if (size == 1 && last->multiplicity < 2 * fastMult)
		{
		  solution.bind(varIndex, last->dagNode);
		  fillOutExtensionInfo(s, last, e);
		}
	      else
		{
		  ACU_DagNode* d = new ACU_DagNode(topSymbol, size);
		  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
		  ArgVec<ACU_DagNode::Pair>::iterator j = d->argArray.begin();
		  e->reset();
		  bool whole = true;
		  for (ArgVec<ACU_DagNode::Pair>::const_iterator i = s->argArray.begin();
		       i != ei; ++i)
		    {
		      int m = i->multiplicity;
		      if (m >= fastMult && i->dagNode->leq(varSort))
			{
			  int rem = m % fastMult;
			  int result = m / fastMult;
			  j->dagNode = i->dagNode;;
			  j->multiplicity = result;
			  ++j;
			  e->setUnmatched(i - s->argArray.begin(), rem);
			  if (rem != 0)
			    whole = false;
			}
		      else
			{
			  e->setUnmatched(i - s->argArray.begin(), m);
			  whole = false;
			}
		    }
		  Assert(j == d->argArray.end(), cerr << "arg list mismatch");
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
