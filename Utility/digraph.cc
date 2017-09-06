//
//      Implementation for class Digraph
//
#ifdef __GNUG__
#pragma implementation
#endif
 
#include "macros.hh"
#include "vector.hh"
#include "digraph.hh"

Digraph::Digraph(int nrNodes)
  : nodeCount(nrNodes), adjMatrix(nrNodes * nrNodes)
{
  int size = adjMatrix.length();
  for (int i = 0; i < size; i++)
    adjMatrix[i] = false;
}

void
Digraph::findLongestDirectedPath(Vector<int>& path)
{
  Vector<int> current;
  for (int i = 0; i < nodeCount; i++)
    extendPath(i, current, path);
}

void
Digraph::extendPath(int i, Vector<int>& current, Vector<int>& longest)
{
  current.append(i);
  int pathLength = current.length();
  bool extended = false;
  int base = i * nodeCount;
  for (int j = 0; j < nodeCount; j++)
    {
      if (adjMatrix[base + j])
	{
	  for (int k = 0; k < pathLength; k++)
	    {
	      if (current[k] == j)
		goto nextEdge;
	    }
	  extendPath(j, current, longest);
	  extended = true;
	}
    nextEdge:
      ;
    }
  if (!extended)
    {
      if (pathLength > longest.length())
	longest = current;  // deep copy
    }
  current.contractTo(pathLength - 1);
}


 


