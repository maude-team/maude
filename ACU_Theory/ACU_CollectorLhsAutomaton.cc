//
//      Implementation for class ACU_CollectorLhsAutomaton.
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
#include "ACU_RedBlack.hh"

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
#include "ACU_CollectorLhsAutomaton.hh"

//	ACU Red-Black class definitions
//#include "ACU_FastIter.hh"
//#include "ACU_SlowIter.hh"
//#include "ACU_RedBlackNode.hh"
//#include "ACU_TreeDagArgumentIterator.hh"
#include "ACU_TreeDagNode.hh"

ACU_CollectorLhsAutomaton::ACU_CollectorLhsAutomaton(VariableTerm* collector)
  : collectorVarIndex(collector->getIndex())
{
  collectorSort = collector->getSort();
  if (collectorSort->index() == 1)
    {
      ConnectedComponent* c = collectorSort->component();
      if (c->nrMaximalSorts() == 1 && c->errorFree())
	collectorSort = 0;
    }
}

bool
ACU_CollectorLhsAutomaton::collect(int stripped,
				   ACU_DagNode* subject,
				   Substitution& solution) const
{
  int nrArgs = subject->argArray.length();
  if (nrArgs <= 2)
    {
      //
      //	Check for case where there's only one arg left after stripping.
      //
      int m = subject->argArray[0].multiplicity;
      int t = 0;
      if (nrArgs == 2)
	{
	  m += subject->argArray[1].multiplicity;
	  t = 1 - stripped;
	}
      if (m == 2)
	{
	  DagNode* sd = subject->argArray[t].dagNode;
	  if (collectorSort == 0 || sd->leq(collectorSort))
	    {
	      solution.bind(collectorVarIndex, sd);
	      return true;
	    }
	  else
	    return false;
	}
    }

  ArgVec<ACU_DagNode::Pair>::const_iterator source = subject->argArray.begin();
  const ArgVec<ACU_DagNode::Pair>::const_iterator e = subject->argArray.end();
  const ArgVec<ACU_DagNode::Pair>::const_iterator victim = source + stripped;
  int strippedMultiplicity = victim->multiplicity - 1;
  if (strippedMultiplicity == 0)
    --nrArgs;
  ACU_Symbol* topSymbol = subject->symbol();

  //cout << nrArgs << ' ';

  ACU_DagNode* d = new ACU_DagNode(topSymbol, nrArgs);
  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);

  ArgVec<ACU_DagNode::Pair>::iterator dest = d->argArray.begin();
  const Sort* cs = collectorSort;
  if (cs == 0)
    {
      //
      //	No sort check case.
      //
      for (; source != victim; ++dest, ++source)
	*dest = *source;
      if (strippedMultiplicity > 0)
	{
	  dest->dagNode = source->dagNode;
	  dest->multiplicity = strippedMultiplicity;
	  ++dest;
	}
      for (++source; source != e; ++dest, ++source)
	*dest = *source;
      Assert(dest == d->argArray.end(), cerr << "iterators inconsistant");
    }
  else
    {
      //
      //	Check each sort to see that it is lower than collector sort.
      //
      int lastIndex = Sort::SORT_UNKNOWN;
      for (; source != victim; ++dest, ++source)
	{
	  DagNode* sd = source->dagNode;
	  int index = sd->getSortIndex();
	  Assert(index != Sort::SORT_UNKNOWN, cerr << "bad sort");
	  if (index != lastIndex)
	    {
	      if (!(leq(index, cs)))
		return false;
	      lastIndex = index;
	    }
	  dest->dagNode = sd;
	  dest->multiplicity = source->multiplicity;
	}
      if (strippedMultiplicity > 0)
	{
	  DagNode* sd = source->dagNode;
	  int index = sd->getSortIndex();
	  Assert(index != Sort::SORT_UNKNOWN, cerr << "bad sort");
	  if (index != lastIndex)
	    {
	      if (!(leq(index, cs)))
		return false;
	      lastIndex = index;
	    }
	  dest->dagNode = sd;
	  dest->multiplicity = strippedMultiplicity;
	  ++dest;
	}
      for (++source; source != e; ++dest, ++source)
	{
	  DagNode* sd = source->dagNode;
	  int index = sd->getSortIndex();
	  Assert(index != Sort::SORT_UNKNOWN, cerr << "bad sort");
	  if (index != lastIndex)
	    {
	      if (!(leq(index, cs)))
		return false;
	      lastIndex = index;
	    }
	  dest->dagNode = sd;
	  dest->multiplicity = source->multiplicity;
	}
      Assert(dest == d->argArray.end(), cerr << "iterators inconsistant");
    }

  if (subject->isReduced() && topSymbol->sortConstraintFree())
    {
      topSymbol->computeBaseSort(d);
      d->setReduced();
    }
  solution.bind(collectorVarIndex, d);
  return true;
}

bool
ACU_CollectorLhsAutomaton::collect(ACU_Stack& stripped,  // destroyed
				   ACU_TreeDagNode* subject,
				   Substitution& solution) const
{
  DagNode* d = subject->makeDelete(stripped, 1);
  const Sort* cs = collectorSort;
  if (cs == 0)
    {
      if (subject->isReduced() && d->symbol()->sortConstraintFree())
	{
	  d->symbol()->computeBaseSort(d);
	  d->setReduced();
	}
    }
  else
    {
      d->symbol()->computeBaseSort(d);
      if (!leq(d->getSortIndex(), cs))
	return false;
      if (subject->isReduced() && d->symbol()->sortConstraintFree())
	d->setReduced();
      else
	d->repudiateSortInfo();
    }
  solution.bind(collectorVarIndex, d);
  return true;
}

#ifdef DUMP
void
ACU_CollectorLhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "collectorVarIndex = " << collectorVarIndex <<
    " \"" << variableInfo.index2Variable(collectorVarIndex) <<
    "\"\tcollectorSort = ";
  if (collectorSort == 0)
    s << "(sort checks off)\n";
  else
    s << collectorSort << '\n';
  HeuristicLhsAutomaton::dump(s, variableInfo, indentLevel);
}
#endif
