//
//      Class for hash table based sets of ints.
//

#ifndef _intSet_hh_
#define _intSet_hh_
#ifdef __GNUG__
#pragma interface
#endif

class IntSet
{
public:
  IntSet();
  IntSet(const IntSet& original);

  int insert(int k);  // return index of inserted int
  void subtract(int i);
  bool contains(int i) const;
  int int2Index(int i) const;
  void makeEmpty();
  void insert(const IntSet& other);
  void subtract(const IntSet& other);
  void intersect(const IntSet& other);
  IntSet& operator=(const IntSet& original);
  bool empty() const;
  bool contains(const IntSet& other) const;
  bool disjoint(const IntSet& other) const;
  int cardinality() const;
  bool operator==(const IntSet& other) const;
  bool operator!=(const IntSet& other) const;
  int index2Int(int i) const;

private:
  enum Parameters
  {
    STARTING_HASH_TABLE_SIZE = 8
  };

  static int hash(int i);
  static int hash2(int i);
  int findEntry(int i) const;
  void resize(int minSize);
  void rehash();

  Vector<int> intTable;
  Vector<int> hashTable;
};

inline
IntSet::IntSet()
{
}

inline
IntSet::IntSet(const IntSet& original)
  : intTable(original.intTable),
    hashTable(original.hashTable)
{
}

inline bool
IntSet::contains(int i) const
{
  return intTable.length() != 0 && hashTable[findEntry(i)] != UNUSED;
}

inline int
IntSet::int2Index(int i) const
{
  return (intTable.length() != 0) ? hashTable[findEntry(i)] : NONE;
} 

inline void
IntSet::makeEmpty()
{
  intTable.contractTo(0);
  hashTable.contractTo(0);
}

inline IntSet&
IntSet::operator=(const IntSet& original)
{
  intTable = original.intTable;  // deep copy
  hashTable = original.hashTable;  // deep copy
  return *this;
}

inline bool
IntSet::empty() const
{
  return intTable.length() == 0;
}

inline int
IntSet::cardinality() const
{
  return intTable.length();
}

inline bool
IntSet::operator==(const IntSet& other) const
{
  return intTable.length() == other.intTable.length() && contains(other);
}

inline bool
IntSet::operator!=(const IntSet& other) const
{
  return !(*this == other);
}

inline int
IntSet::index2Int(int i) const
{
  return intTable[i];
}

#endif
