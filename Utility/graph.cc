//
//      Implementation for class Graph
//
#ifdef __GNUG__
#pragma implementation
#endif
 
#include "macros.hh"
#include "vector.hh"
#include "natSet.hh"
#include "graph.hh"

Graph::Graph(int nrNodes)
  : nodeCount(nrNodes), adjMatrix(nrNodes * nrNodes)
{
  int size = adjMatrix.length();
  for (int i = 0; i < size; i++)
    adjMatrix[i] = false;
}

int
Graph::color(Vector<int>& coloring)
{
  coloring.resize(nodeCount);
  for (int i = 0; i < nodeCount; i++)
    coloring[i] = UNDEFINED;
  int maxColor = UNDEFINED;
  for (int i = 0; i < nodeCount; i++)
    colorNode(i, maxColor, coloring);
  return maxColor + 1;
}

void
Graph::colorNode(int i, int& maxColor, Vector<int>& coloring)
{
  if (coloring[i] != UNDEFINED)
    return;
  NatSet used;
  int offset = i * nodeCount;
  for (int j = 0; j < nodeCount; j++)
    {
      if (adjMatrix[offset + j])
	{
	  int c = coloring[j];
	  if (c != UNDEFINED)
	    used.insert(c);
	}
    }
  for (int c = 0;; c++)
    {
      if (!(used.contains(c)))
	{
	  coloring[i] = c;
	  if (c > maxColor)
	    maxColor = c;
	  break;
	}
    }  
  for (int j = 0; j < nodeCount; j++)
    {
      if (adjMatrix[offset + j])
	colorNode(j, maxColor, coloring);
    }
}

void
Graph::findComponents(Vector<Vector<int> >& components)
{
  NatSet visited;
  for (int i = 0; i < nodeCount; i++)
    {
      if (!visited.contains(i))
	{
	  int nrComponents = components.length();
	  components.expandBy(1);
	  visit(i, components[nrComponents], visited);
	}
    }
}

void
Graph::visit(int i, Vector<int>& component, NatSet& visited)
{
  visited.insert(i);
  component.append(i);
  int base = i * nodeCount;
  for (int j = 0; j < nodeCount; j++)
    {
      if (adjMatrix[base + j] && !(visited.contains(j)))
	visit(j, component, visited);
    }
}

 


