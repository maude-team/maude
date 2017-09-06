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
  int nrArgs2 = nrArgs;
  int strippedMultiplicity = subject->argArray[stripped].multiplicity - 1;
  if (strippedMultiplicity == 0)
    --nrArgs2;
  ACU_Symbol* topSymbol = subject->symbol();

  //cout << nrArgs2 << ' ';

  ACU_DagNode* d = new ACU_DagNode(topSymbol, nrArgs2);
  d->setNormalizationStatus(ACU_DagNode::ASSIGNMENT);
  CONST_ARG_VEC_HACK(ACU_DagNode::Pair, source, subject->argArray);
  ARG_VEC_HACK(ACU_DagNode::Pair, dest, d->argArray);
  int i = 0;
  const Sort* cs = collectorSort;
  if (cs == 0)
    {
      for (; i < stripped; i++)
	dest[i] = source[i];
      int j = i;
      if (strippedMultiplicity > 0)
	{
	  dest[i].dagNode = source[i].dagNode;
	  dest[i].multiplicity = strippedMultiplicity;
	  ++j;
	}
      for (i++; i < nrArgs; i++, j++)
	dest[j] = source[i];
      Assert(j == nrArgs2, cerr << "bad number of arguments");
    }
  else
    {
      int lastIndex = Sort::SORT_UNKNOWN;
      for (; i < stripped; i++)
	{
	  DagNode* sd = source[i].dagNode;
	  int sm = source[i].multiplicity;
	  int index = sd->getSortIndex();
	  Assert(index != Sort::SORT_UNKNOWN, cerr << "bad sort");
	  if (index != lastIndex)
	    {
	      if (!(leq(index, cs)))
		return false;
	      lastIndex = index;
	    }
	  dest[i].dagNode = sd;
	  dest[i].multiplicity = sm;
	}
      int j = i;
      if (strippedMultiplicity > 0)
	{
	  DagNode* sd = source[i].dagNode;
	  int index = sd->getSortIndex();
	  Assert(index != Sort::SORT_UNKNOWN, cerr << "bad sort");
	  if (index != lastIndex)
	    {
	      if (!(leq(index, cs)))
		return false;
	      lastIndex = index;
	    }
	  dest[i].dagNode = sd;
	  dest[i].multiplicity = strippedMultiplicity;
	  ++j;
	}
      for (i++; i < nrArgs; i++, j++)
	{
	  DagNode* sd = source[i].dagNode;
	  int sm = source[i].multiplicity;
	  int index = sd->getSortIndex();
	  Assert(index != Sort::SORT_UNKNOWN, cerr << "bad sort");
	  if (index != lastIndex)
	    {
	      if (!(leq(index, cs)))
		return false;
	      lastIndex = index;
	    }
	  dest[j].dagNode = sd;
	  dest[j].multiplicity = sm;
	}
      Assert(j == nrArgs2, cerr << "bad number of arguments");
    }
  
  if (subject->isReduced() && topSymbol->sortConstraintFree())
    {
      topSymbol->computeBaseSort(d);
      d->setReduced();
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
