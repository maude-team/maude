//
//      Implementation for class IntSet.
//
#include "macros.hh"
#include "vector.hh"
#include "intSet.hh"

inline int
IntSet::hash(int i)
{
  return i ^ (i >> 4);
}
 
inline int
IntSet::hash2(int i)  // 2nd hash function must always return an odd value
{
  return (i ^ (i >> 8)) | 1;
}

int
IntSet::insert(int k)
{
  if (intTable.length() == 0)
    resize(STARTING_HASH_TABLE_SIZE);
  int i = findEntry(k);
  int j = hashTable[i];
  if (j == UNUSED)
    {
      j = intTable.length();
      intTable.append(k);
      int size = 2 * (j + 1);
      if (size > hashTable.length())
	resize(size);
      else
	hashTable[i] = j;
    }
  return j;
}

void
IntSet::insert(const IntSet& other)
{
  int size = 2 * (intTable.length() + other.intTable.length());
  if (size > hashTable.length())
    resize(size);  // pre-emptively resize hash table based on estimate
  for (int i = other.intTable.length() - 1; i >= 0; i--)
    {
      int k = other.intTable[i];
      int j = findEntry(k);
      if (hashTable[j] == UNUSED)
	{
	  hashTable[j] = intTable.length();
	  intTable.append(k);
	}
    }
}

void
IntSet::subtract(int k)
{
  int n = intTable.length();
  if (n == 0)
    return;
  int i = findEntry(k);
  int j = hashTable[i];
  if (j == UNUSED)
    return;
  --n;
  intTable[j] = intTable[n];
  intTable.contractTo(n);
  rehash();  // removing an element is expensive
}
  
void
IntSet::subtract(const IntSet& other)
{
  int n = intTable.length();
  if (n == 0 || other.intTable.length() == 0)
    return;
  int j = 0;
  for (int i = 0; i < n; i++)
    {
      int k = intTable[i];
      if (other.hashTable[other.findEntry(k)] == UNUSED)
	intTable[j++] = k;
    }
  if (j != n)
    {
      intTable.contractTo(j);
      rehash();
    }
}

void
IntSet::intersect(const IntSet& other)
{
  int n = intTable.length();
  if (n == 0)
    return;
  if (other.intTable.length() == 0)
    {
      intTable.contractTo(0);
      hashTable.contractTo(0);
      return;
    }
  int j = 0;
  for (int i = 0; i < n; i++)
    {
      int k = intTable[i];
      if (other.hashTable[other.findEntry(k)] != UNUSED)
	intTable[j++] = k;
    }
  if (j != n)
    {
      intTable.contractTo(j);
      rehash();
    }
}
 
bool
IntSet::contains(const IntSet& other) const
{
  int i = other.intTable.length();
  if (i == 0)
    return true;
  if (intTable.length() < i)
    return false;
  for (i--; i >= 0; i--)
    {
      if (hashTable[findEntry(other.intTable[i])] == UNUSED)
	return false;
    }
  return true;
}

bool
IntSet::disjoint(const IntSet& other) const
{
  int i = other.intTable.length();
  if (i == 0 || intTable.length() == 0)
    return true;
  for (i--; i >= 0; i--)
    {
      if (hashTable[findEntry(other.intTable[i])] != UNUSED)
	return false;
    }
  return true;
}

int
IntSet::findEntry(int k) const
{
  Assert(hashTable.length() != 0, "zero length hash table");
  int mask = hashTable.length() - 1;
  int i = hash(k) & mask;
  int j = hashTable[i];
  if (j != UNUSED && intTable[j] != k)
    {
      int step = hash2(k);
      do
	{
	  i = (i + step) & mask;
	  j = hashTable[i];
	}
      while (j != UNUSED && intTable[j] != k);
    }
  return i;
}

void
IntSet::resize(int minSize)
{
  int n = hashTable.length();
  n = (n == 0) ? STARTING_HASH_TABLE_SIZE : 2 * n;
  while (n < minSize)
    n *= 2;
  hashTable.expandTo(n);
  rehash();
}

void
IntSet::rehash()
{
  int n = hashTable.length();
  for (int i = 0; i < n; i++)
    hashTable[i] = UNUSED;
  int mask = n - 1;
  for (int i = intTable.length() - 1; i >= 0; i--)
    {
      int k = intTable[i];
      int j = hash(k) & mask;
      if (hashTable[j] != UNUSED)
	{
	  int step = hash2(k);
	  do
	    j = (j + step) & mask;
	  while (hashTable[j] != UNUSED);
	}
      hashTable[j] = i;
    }
}
