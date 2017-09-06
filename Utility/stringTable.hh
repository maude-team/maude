//
//	Class for dynamic string tables
//
#ifndef _stringTable_hh_
#define _stringTable_hh_
#ifdef __GNUG__
#pragma interface
#endif

class StringTable
{
public:
  StringTable(int size = 1024);
  ~StringTable();
  int encode(const char* name);
  const char* name(int code) const;

private:
  static int hash(const char* name);
  static int hash2(const char* name);
  void resize();

  Vector<char*> stringTable;
  Vector<int> hashTable;
};

inline const char*
StringTable::name(int code) const
{
  return stringTable[code];
}

#endif
