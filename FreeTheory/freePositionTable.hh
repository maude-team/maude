//
//	Class for table of positions in free skeletons.
//
//	It is maintained as a digital search tree with each node containing
//	the full path to nodes as a Vector for fast index to path conversion.
//
#ifndef _freePositionTable_hh_
#define _freePositionTable_hh_

class FreePositionTable
{
public:
  const Vector<int>& index2Position(int index) const;
  int position2Index(const Vector<int>& position);
  int parentIndex(int index) const;

private:
  struct Pair
  {
    Vector<int> position;
    Vector<int> arcs;
  };

  int build(const Vector<int>& position, int start);

  Vector<Pair> table;
};

inline const Vector<int>&
FreePositionTable::index2Position(int index) const
{
  return table[index].position;
}

#endif
