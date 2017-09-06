//
//      Class for maps from pointers to pointers
//
#ifndef _pointerMap_hh_
#define _pointerMap_hh_

class PointerMap
{
public:
  PointerMap(int size = 8);

  void* setMap(void* from, void* to);
  void* getMap(void* from) const;

private:
  struct Pair
  {
    void* from;
    void* to;
  };

  static int hash(void* pointer);
  static int hash2(void* pointer);
  int findEntry(void* from) const;
  void resize();

  int used;
  Vector<Pair> hashTable;
};

#endif

