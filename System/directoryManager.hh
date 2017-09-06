//
//      Class for managing current directory stack.
//
#ifndef _directoryManager_hh_
#define _directoryManager_hh_
#include "stringTable.hh"

class DirectoryManager
{
public:
  void initialize();
  bool cd(const string& directory);
  int pushd(const string& directory);
  const char* popd(int prevLength = UNDEFINED);
  const char* getCwd();

  bool checkAccess(const string& directory,
		   string& fileName,
		   int mode,
		   char const* const ext[] = 0);
  bool searchPath(const char* pathVar,
		  string& directory,
		  string& fileName,
		  int mode,
		  char const* const ext[] = 0);
  void realPath(const string& path, string& resolvedPath);

private:
  StringTable directoryNames;
  Vector<int> directoryStack;
};

#endif
