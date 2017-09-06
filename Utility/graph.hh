//
//	Class for graphs.
//
#ifndef _graph_hh_
#define _graph_hh_

class Graph
{
public:
  Graph(int nrNodes);

  void insertEdge(int n1, int n2);
  int color(Vector<int>& coloring);  // node 0 is guaranteed to get color 0
  void findComponents(Vector<Vector<int> >& components);

private:
  void colorNode(int i, int& maxColor, Vector<int>& coloring);
  void visit(int i, Vector<int>& component, NatSet& visited);

  const int nodeCount;
  Vector<Bool> adjMatrix;
};

inline void
Graph::insertEdge(int n1, int n2)
{
  adjMatrix[n1 * nodeCount + n2] = true;
  adjMatrix[n2 * nodeCount + n1] = true;
}

#endif

