//
//      Class for table of files that we have seen.
//
#ifndef _fileTable_hh_
#define _fileTable_hh_
#include "stringTable.hh"
#include "token.hh"

class FileTable
{
public:
  enum SpecialLineNumbers
  {
    SYSTEM_CREATED = -1,	// line number for things created by the system
    META_LEVEL_CREATED = -2,	// line number for things created in the metalevel
    COMMAND_LINE = -3,		// line number for command line argument
    AUTOMATIC = -1,
  };

  FileTable();

  void openFile(int lineNumber, const char* name, bool silent);
  void closeFile(int lineNumber);
  void beginModule(Token type, Token name);
  void endModule(int lineNumber);
  void abortEverything(int lineNumber);
  void printLineNumber(ostream& s, int lineNumber);
  bool outputLine();

private:
  NO_COPYING(FileTable);

  struct Entry
  {
    int absoluteLineNumber;
    union
    {
      int fileNameIndex;
      int moduleNameIndex;
    };
    union
    {
      int relativeLineNumber;
      int moduleTypeIndex;
    };
  };

  int binarySearch(Vector<Entry>& table, int lineNumber);

  StringTable fileNames;
  Vector<Entry> fileChanges;
  Vector<Entry> moduleChanges;
  Vector<int> fileStack;
  Vector<int> moduleStack;
  int firstSilent;
};

#endif
