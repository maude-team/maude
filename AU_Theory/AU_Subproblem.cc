//
//      Implementation for class AU_Subproblem.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "sequencePartition.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "AU_Theory.hh"

//      interface class definitions
#include "symbol.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "localBinding.hh"

//	AU theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"
#include "AU_ExtensionInfo.hh"
#include "AU_Subproblem.hh"

AU_Subproblem::AU_Subproblem(AU_DagNode* subject,
			     int firstSubterm,
			     int lastSubterm,
			     int nrLayers,
			     AU_ExtensionInfo* extensionInfo)
  : extensionInfo(extensionInfo),
    layers(nrLayers)
{
  Assert(extensionInfo == 0 ||
	 (firstSubterm == 0 && lastSubterm == subject->argArray.length() - 1),
	 "extension disagreement");
  for (int i = 0; i < nrLayers; i++)
    layers[i].initialize(subject);
  layers[0].initializeFirst(firstSubterm, extensionInfo);
  layers[nrLayers - 1].initializeLast(lastSubterm, extensionInfo);
}

void
AU_Subproblem::complete()
{
  int nrPatternLayers = layers.length() - 1;  // last layer has no patterns
  for (int i = 1; i < nrPatternLayers; i++)
    layers[i - 1].link(layers[i]);
}

bool
AU_Subproblem::solve(bool findFirst, RewritingContext& solution)
{
  if (!findFirst && solveVariables(false, solution))
    return true;
  for (;;)
    {
      if (!solvePatterns(findFirst, solution))
        return false;
      if (solveVariables(true, solution))
        return true;
      findFirst = false;
    }
}

bool
AU_Subproblem::solvePatterns(bool findFirst, RewritingContext& solution)
{
  int nrPatternLayers = layers.length() - 1;  // last layer has no patterns
  if (nrPatternLayers == 0)
    return findFirst;
  int i = findFirst ? 0 : nrPatternLayers - 1;
  if (findFirst)
    layers[0].reset();
  for(;;)
    {
      findFirst = layers[i].solvePatterns(findFirst, solution, layers[i + 1]);
      if (findFirst)
	{
	  if (++i == nrPatternLayers)
	    break;
	}
      else
	{
	  if (--i < 0)
	    break;
	}
    }
  return findFirst;
}

bool
AU_Subproblem::solveVariables(bool findFirst, RewritingContext& solution)
{
  int nrVariableLayers = layers.length();
  int i = findFirst ? 0 : nrVariableLayers - 1;
  for(;;)
    {
      findFirst = layers[i].solveVariables(findFirst, solution);
      if (findFirst)
        {
          if (++i == nrVariableLayers)
	    {
	      if (extensionInfo == 0 ||extensionInfo->bigEnough())
		return true;
	      --i;
	      findFirst = false;
	    }
        }
      else
        {
          if (--i < 0)
            break;
        }
    }
  return false;
}
