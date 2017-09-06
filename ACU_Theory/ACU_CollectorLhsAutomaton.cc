//
//      Implementation for class ACU_CollectorLhsAutomaton.
//

//	utility stuff
#include "macros.hh"
#include "indent.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_RedBlack.hh"
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
#include "ACU_TreeDagNode.hh"
#include "ACU_CollectorLhsAutomaton.hh"

ACU_CollectorLhsAutomaton::ACU_CollectorLhsAutomaton(ACU_Symbol* symbol,
						     bool matchAtTop,
						     bool collapsePossible,
						     int nrVariables,
						     VariableTerm* collector)
  : ACU_LhsAutomaton(symbol, matchAtTop, collapsePossible, nrVariables),
    collectorVarIndex(collector->getIndex())
{
  Assert(symbol->sortConstraintFree(), "not sort constraint free");

  collectorSort = collector->getSort();
  Assert(symbol->sortBound(collectorSort) == UNBOUNDED,
	 "collector must have unbounded sort");

  int index = collectorSort->index();
  if (index == 0)
    collectorSort = 0;  // kind can take anything
  else if (index == 1)
    {
      ConnectedComponent* c = collectorSort->component();
      if (c->nrMaximalSorts() == 1 && c->errorFree())
	collectorSort = 0;  // top sort in an error-free component can take anything
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
  //
  //	Make binding for collector variable.
  //
  ArgVec<ACU_DagNode::Pair>::const_iterator source = subject->argArray.begin();
  const ArgVec<ACU_DagNode::Pair>::const_iterator e = subject->argArray.end();
  const ArgVec<ACU_DagNode::Pair>::const_iterator victim = source + stripped;
  int strippedMultiplicity = victim->multiplicity - 1;
  if (strippedMultiplicity == 0)
    --nrArgs;
  ACU_Symbol* topSymbol = subject->symbol();
  ACU_DagNode* d = new ACU_DagNode(topSymbol, nrArgs);
  ArgVec<ACU_DagNode::Pair>::iterator dest = d->argArray.begin();
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
  Assert(dest == d->argArray.end(), "iterators inconsistant");
  //
  //	Do any sort calculations needed.
  //
  const Sort* cs = collectorSort;
  if (cs == 0)
    {
      if (subject->isReduced())
	{
	  int index = topSymbol->getUniqueSortIndex();
	  Assert(index != 0, "bad uniqueSortIndex");
	  if (index < 0)
	    index = d->argVecComputeBaseSort();
	  d->setSortIndex(index);
	  d->setReduced();
	}
    }
  else
    {
      int index = d->argVecComputeBaseSort();
      if (!leq(index, cs))
	return false;
      if (subject->isReduced())
	{
	  d->setSortIndex(index);
	  d->setReduced();
	}
    }
  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
  solution.bind(collectorVarIndex, d);
  return true;
}

bool
ACU_CollectorLhsAutomaton::collect(ACU_Stack& stripped,  // destroyed
				   ACU_TreeDagNode* subject,
				   Substitution& solution) const
{
  ACU_RedBlackNode* n = ACU_RedBlackNode::consDelete(stripped, 1);
  DagNode* d;
  const Sort* cs = collectorSort;
  if (n->getSize() == 1 && n->getMultiplicity() == 1)
    {
      //
      //	Only one argument left for collector.
      //
      d = n->getDagNode();
      if (cs != 0 && !leq(d->getSortIndex(), cs))
	return false;
    }
  else
    {
      ACU_Symbol* topSymbol = subject->symbol();
      ACU_TreeDagNode* t = new ACU_TreeDagNode(topSymbol, n);
      if (cs == 0)
	{
	  if (subject->isReduced())
	    {
	      int index = topSymbol->getUniqueSortIndex();
	      Assert(index != 0, "bad uniqueSortIndex");
	      if (index < 0)
		index = t->treeComputeBaseSort();
	      t->setSortIndex(index);
	      t->setReduced();
	    }
	}
      else
	{
	  int index = t->treeComputeBaseSort();
	  if (!leq(index, cs))
	    return false;
	  if (subject->isReduced())
	    {
	      t->setSortIndex(index);
	      t->setReduced();
	    }
	}
      d = t;
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
  ACU_LhsAutomaton::dump(s, variableInfo, indentLevel);
}
#endif
