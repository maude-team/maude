//
//      Class for Tarjan-style Union-Find data structure
//
#ifndef _unionFind_hh_
#define _unionFind_hh_
#ifdef __GNUG__
#pragma interface
#endif

class UnionFind
{
public:
  int makeElement();
  int findRep(int element) const;
  void formUnion(int e1, int e2);
  int elementCount() const;

private:
  struct Element
    {
      int next;
      int rank;
    };

  mutable Vector<Element> vector;
};

inline int
UnionFind::elementCount() const
{
  return vector.length();
}

#endif
