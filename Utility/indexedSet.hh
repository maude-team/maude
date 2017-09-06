//
//	Class template for (constructive) indexed sets.
//
#ifndef _indexedSet_hh_
#define _indexedSet_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include <map>
#include <vector>

template<class T>
class IndexedSet
{
public:
  //
  //	The pupose of FastPair is to allow an insert() which avoids copying
  //	the inserted element if it is already in the indexed set.
  //	We assume T is a complex data type for which copies, compares
  //	and destructs are relatively expensive. A less ugly method would
  //	be to do a find() before inserting but this would cost a second
  //	round of compares if we actually had to do the insert().
  //
  typedef pair<T, int> FastPair;

  void clear();
  int insert(const T& element);
  int insert(const FastPair& fastPair);
  int find(const T& element) const;
  const T& ithElement(int i) const;
  int size() const;
  void swap(IndexedSet& other);

private:
  typedef map<T, int> EltMap;
  typedef vector<typename EltMap::const_iterator> IndexMap;

  EltMap eltMap;
  IndexMap indexMap;
};

template<class T>
inline void
IndexedSet<T>::clear()
{
  indexMap.clear();
  eltMap.clear();
}

template<class T>
inline void
IndexedSet<T>::swap(IndexedSet& other)
{
  indexMap.swap(other.indexMap);
  eltMap.swap(other.eltMap);
}

template<class T>
inline int
IndexedSet<T>::insert(const T& element)
{
  pair<typename EltMap::iterator, bool> p =
    eltMap.insert(EltMap::value_type(element, indexMap.size()));
  if (p.second)
    indexMap.push_back(p.first);
  return p.first->second;
}

template<class T>
inline int
IndexedSet<T>::insert(const FastPair& fastPair)
{
  pair<typename EltMap::iterator, bool> p = eltMap.insert(fastPair);
  if (p.second)
    {
      p.first->second = indexMap.size();
      indexMap.push_back(p.first);
    }
  return p.first->second;
}

template<class T>
inline int
IndexedSet<T>::find(const T& element) const
{
  typename EltMap::const_iterator i = eltMap.find(element);
  return (i == eltMap.end()) ? -1 : i->second;
}

template<class T>
inline const T&
IndexedSet<T>::ithElement(int i) const
{
  return indexMap[i]->first;
}

template<class T>
inline int
IndexedSet<T>::size() const
{
  return indexMap.size();
}

#endif
