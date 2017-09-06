//
//	Class for digraphs.
//
#ifndef _digraph_hh_
#define _digraph_hh_

class Digraph
{
public:
  Digraph(int nrNodes);

  void insertEdge(int from, int to);
  void findLongestDirectedPath(Vector<int>& path);

private:
  void extendPath(int i, Vector<int>& current, Vector<int>& longest);

  const int nodeCount;
  Vector<Bool> adjMatrix;
};

inline void
Digraph::insertEdge(int from, int to)
{
  adjMatrix[from * nodeCount + to] = true;
}

#endif

