//
//      Implementation for class VariableInfo.
//

#include "macros.hh"
#include "vector.hh"
#include "graph.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"

//      core class definitions
#include "substitution.hh"
#include "variableInfo.hh"

VariableInfo::VariableInfo()
{
  nrProtectedVariables = 0;
  fragmentNumber = 0;
}

int
VariableInfo::variable2Index(VariableTerm* variable)
{
  Assert(variable != 0, "null term");
  int nrRealVariables = variables.length();
  Assert(nrRealVariables == nrProtectedVariables,
	 "can't add new real variables at this stage");
  for (int i = 0; i < nrRealVariables; i++)
    {
      if (variable->equal(variables[i]))
	return i;
    }
  variables.append(variable);
  ++nrProtectedVariables;
  return nrRealVariables;
}

int
VariableInfo::makeConstructionIndex()
{
  int nrConstructionIndices = constructionIndices.length();
  constructionIndices.expandBy(1);
  constructionIndices[nrConstructionIndices].assignedFragment = fragmentNumber;
  constructionIndices[nrConstructionIndices].lastUseFragment = fragmentNumber;
  return MAX_NR_PROTECTED_VARIABLES + nrConstructionIndices;
}

void
VariableInfo::computeIndexRemapping()
{
  int nrConstructionIndices = constructionIndices.length();
  /*
  cerr << "dumping constructionIndices\n";
  for (int i = 0; i < nrConstructionIndices; i++)
    {
      cerr << i << '\t' <<
	constructionIndices[i].assignedFragment << '\t' <<
	constructionIndices[i].lastUseFragment << '\t' <<
	constructionIndices[i].lastUseTime << endl;
    }
  */

  //
  //	All construction indices that need to be protected between different fragments
  //	get remapped to a new protected variable.
  //
  for (int i = 0; i < nrConstructionIndices; i++)
    {
      if (constructionIndices[i].assignedFragment != constructionIndices[i].lastUseFragment)
	constructionIndices[i].newIndex = makeProtectedVariable();
    }
  //
  //	We now build a graph of conflicts between remaining construction indices.
  //
  Graph conflicts(nrConstructionIndices);
  for (int i = 0; i < nrConstructionIndices; i++)
    {
      if (constructionIndices[i].assignedFragment ==
	  constructionIndices[i].lastUseFragment)
	{
	  //
	  //	A remaining construction index i conflicts with any earlier
	  //	remaining construction index j whose last use is after the
	  //	allocation of construction index i.
	  //
	  for (int j = 0; j < i; j++)
	    {
	      if (constructionIndices[j].assignedFragment ==
		  constructionIndices[j].lastUseFragment &&
		  constructionIndices[j].lastUseTime > i)
		conflicts.insertEdge(i, j);
	    }
	}
    }
  //
  //	We now use graph coloring to remap the remaining construction indices.
  //
  Vector<int> coloring;
  int nrColors = conflicts.color(coloring);
  for (int i = 0; i < nrConstructionIndices; i++)
    {
      if (constructionIndices[i].assignedFragment ==
	  constructionIndices[i].lastUseFragment)
	constructionIndices[i].newIndex = nrProtectedVariables + coloring[i];
    }
  //
  //	Finally, we need to notify class Substitution of the minimum size
  //	of substitution needed.
  //
  /*
  DebugAdvisory("nrProtectedVariables = " << nrProtectedVariables <<
		"\tnrColors = " << nrColors);
  */
  Substitution::notify(nrProtectedVariables + nrColors);
}
