//
//      Implementation for class UnionFind.
//
#include "macros.hh"
#include "vector.hh"
#include "unionFind.hh"

int
UnionFind::makeElement()
{
  int e = vector.length();
  vector.expandBy(1);
  vector[e].next = e;
  vector[e].rank = 0;
  return e;
}

int
UnionFind::findRep(int element) const
{
  //
  //	Find representative
  //
  int r = element;
  while(vector[r].next != r)
    r = vector[r].next;
  //
  //	Compress path
  //
  int j;
  for (int i = element; i != r; i = j)
    {
      j = vector[i].next;
      vector[i].next = r;
    }
  return r;
}

void
UnionFind::formUnion(int e1, int e2)
{
  int r1 = findRep(e1);
  int r2 = findRep(e2);
  if (vector[r1].rank > vector[r2].rank)
    vector[r2].next = r1;
  else
    {
      if (vector[r1].rank == vector[r2].rank)
	++(vector[r2].rank);
      vector[r1].next = r2;
    } 
}
