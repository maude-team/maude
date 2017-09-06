//
//      Implementation for class PointerSet
//
#include "macros.hh"
#include "vector.hh"
#include "pointerSet.hh"

PointerSet::~PointerSet()
{
}

inline int
PointerSet::localHash(unsigned int rawHashValue)
{
  return rawHashValue ^ (rawHashValue >> 2);
}
 
inline int
PointerSet::localHash2(unsigned int rawHashValue)
{
  //
  //	Second local hash function must always return an odd value.
  //
  return (rawHashValue ^ (rawHashValue >> (WORD_SIZE / 2))) | 1;
}

local_inline bool
PointerSet::isEqual(const Pair& pair, void* p, unsigned int rawHashValue) const
{
  return pair.rawHashValue == rawHashValue && isEqual(pair.pointer, p);
}

unsigned int
PointerSet::hash(void* pointer) const
{
  return reinterpret_cast<unsigned long>(pointer) >> NR_PTR_LOSE_BITS;
}

bool 
PointerSet::isEqual(void* pointer1, void* pointer2) const
{
  return pointer1 == pointer2;
}

int
PointerSet::insert(void* p, unsigned int rawHashValue)
{
  if (pointerTable.length() == 0)
    resize(STARTING_HASH_TABLE_SIZE);
  int i = findEntry(p, rawHashValue);
  int j = hashTable[i];
  if (j == UNUSED)
    {
      j = pointerTable.length();
      pointerTable.expandBy(1);
      Pair& pair = pointerTable[j];
      pair.pointer = p;
      pair.rawHashValue = rawHashValue;
      int size = 2 * (j + 1);
      //if (size > 2000)
      //  cerr << "size = " << size << '\n';
      if (size > hashTable.length())
	resize(size);
      else
	hashTable[i] = j;
    }
  return j;
}

void
PointerSet::insert(const PointerSet& other)
{
  int size = 2 * (pointerTable.length() + other.pointerTable.length());
  if (size > hashTable.length())
    resize(size);  // pre-emptively resize hash table based on estimate
  for (int i = other.pointerTable.length() - 1; i >= 0; i--)
    {
      const Pair& pair = other.pointerTable[i];
      void* p = pair.pointer;
      unsigned int rawHashValue = pair.rawHashValue;
      int j = findEntry(p, rawHashValue);
      if (hashTable[j] == UNUSED)
	{
	  int k = pointerTable.length();
	  pointerTable.expandBy(1);
	  Pair& pair2 = pointerTable[k];
	  pair2.pointer = p;
	  pair2.rawHashValue = rawHashValue;
	  hashTable[j] = k;
	}
    }
}

void
PointerSet::subtract(void* p, unsigned int rawHashValue)
{
  int n = pointerTable.length();
  if (n == 0)
    return;
  int i = findEntry(p, rawHashValue);
  int j = hashTable[i];
  if (j == UNUSED)
    return;
  --n;
  pointerTable[j] = pointerTable[n];
  pointerTable.contractTo(n);
  rehash();  // removing an element is expensive
}
  
void
PointerSet::subtract(const PointerSet& other)
{
  int n = pointerTable.length();
  if (n == 0 || other.pointerTable.length() == 0)
    return;
  int j = 0;
  for (int i = 0; i < n; i++)
    {
      Pair& pair = pointerTable[i];
      void* p = pair.pointer;
      unsigned int rawHashValue = pair.rawHashValue;
      if (other.hashTable[other.findEntry(p, rawHashValue)] == UNUSED)
	{
	  Pair& pair2 = pointerTable[j++];
	  pair2.pointer = p;
	  pair.rawHashValue = rawHashValue;
	}
    }
  if (j != n)
    {
      pointerTable.contractTo(j);
      rehash();
    }
}

void
PointerSet::intersect(const PointerSet& other)
{
  int n = pointerTable.length();
  if (n == 0)
    return;
  if (other.pointerTable.length() == 0)
    {
      pointerTable.contractTo(0);
      hashTable.contractTo(0);
      return;
    }
  int j = 0;
  for (int i = 0; i < n; i++)
    {
      Pair& pair = pointerTable[i];
      void* p = pair.pointer;
      unsigned int rawHashValue = pair.rawHashValue;
      if (other.hashTable[other.findEntry(p, rawHashValue)] != UNUSED)
	{
	  Pair& pair2 = pointerTable[j++];
	  pair2.pointer = p;
	  pair.rawHashValue = rawHashValue;
	}
    }
  if (j != n)
    {
      pointerTable.contractTo(j);
      rehash();
    }
}
 
bool
PointerSet::contains(const PointerSet& other) const
{
  int i = other.pointerTable.length();
  if (i == 0)
    return true;
  if (pointerTable.length() < i)
    return false;
  for (i--; i >= 0; i--)
    {
      const Pair& pair = other.pointerTable[i];
      if (hashTable[findEntry(pair.pointer, pair.rawHashValue)] == UNUSED)
	return false;
    }
  return true;
}

bool
PointerSet::disjoint(const PointerSet& other) const
{
  int i = other.pointerTable.length();
  if (i == 0 || pointerTable.length() == 0)
    return true;
  for (i--; i >= 0; i--)
    {
      const Pair& pair = other.pointerTable[i];
      if (hashTable[findEntry(pair.pointer, pair.rawHashValue)] != UNUSED)
	return false;
    }
  return true;
}

int
PointerSet::findEntry(void* p, unsigned int rawHashValue) const
{
  Assert(hashTable.length() != 0, "zero length hash table");
  int mask = hashTable.length() - 1;
  int i = localHash(rawHashValue) & mask;
  int j = hashTable[i];
  if (j != UNUSED && !(isEqual(pointerTable[j], p, rawHashValue)))
    {
      int step = localHash2(rawHashValue);
      do
	{
	  i = (i + step) & mask;
	  j = hashTable[i];
	}
      while (j != UNUSED && !(isEqual(pointerTable[j], p, rawHashValue)));
    }
  return i;
}

void
PointerSet::resize(int minSize)
{
  int n = hashTable.length();
  n = (n == 0) ? STARTING_HASH_TABLE_SIZE : 2 * n;
  while (n < minSize)
    n *= 2;
  hashTable.expandTo(n);
  rehash();
}

void
PointerSet::rehash()
{
  int n = hashTable.length();
  for (int i = 0; i < n; i++)
    hashTable[i] = UNUSED;
  int mask = n - 1;
  for (int i = pointerTable.length() - 1; i >= 0; i--)
    {
      unsigned int rawHashValue = pointerTable[i].rawHashValue;
      int j = localHash(rawHashValue) & mask;
      if (hashTable[j] != UNUSED)
	{
	  int step = localHash2(rawHashValue);
	  do
	    j = (j + step) & mask;
	  while (hashTable[j] != UNUSED);
	}
      hashTable[j] = i;
    }
}
