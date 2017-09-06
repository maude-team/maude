//
//	main() function and misc global data and functions.
//
#include <unistd.h>
#include "sys/param.h"
#ifdef ALPHA
#include <stropts.h>
#endif

//      utility stuff
#include "macros.hh"
#include "vector.hh"
#include "tty.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "mixfix.hh"
 
//      interface class definitions
#include "term.hh"
 
//      core class definitions
#include "lineNumber.hh"

//      system class definitions
#include "IO_Manager.hh"

//	mixfix frontend definitions
#include "token.hh"
#include "userLevelRewritingContext.hh"
#include "fileTable.hh"
#include "directoryManager.hh"
#include "mixfixModule.hh"
#include "interpreter.hh"
#include "main.hh"

#define PRELUDE_NAME	"prelude.maude"
#define MAUDE_LIB	"MAUDE_LIB"

//
//	Global variables
//
int lineNumber = 1;
FileTable fileTable;
DirectoryManager directoryManager;
Interpreter interpreter;
IO_Manager ioManager;

string executableDirectory;

int
main(int argc, char* argv[])
{
  // extern int yydebug;
  // yydebug = 0;
  void printBanner(ostream& s);
  void createRootBuffer(FILE* fp, bool forceInteractive);
  bool includeFile(const string& directory, const string& fileName, bool silent, int lineNr);
  extern Vector<char*> pendingFiles;
  const char* isFlag(const char* arg, const char* flag);

  //ios::sync_with_stdio(false);
  ioManager.setAutoWrap();
  /*
  for (int i = 0; i < 100; i++)
    {
      cerr << i * i * i << ' ';
      cerr << "aaaaaaaaaa";
      //for (int j = 0; j < 10; j++)
      //cerr << 'a';
    }
  */

  bool handleCtrlC = true;
  bool readPrelude = true;
  bool forceInteractive = false;
  int ansiColor = UNDECIDED;

  for (int i = 1; i < argc; i++)
    {
      char* arg = argv[i];
      if (arg[0] == '-')
	{
	  if (const char* s = isFlag(arg, "-xml-log="))
	    interpreter.beginXmlLog(s);
	  else if (strcmp(arg, "-no-mixfix") == 0)
	    MixfixModule::setPrintMixfix(false);
	  else if (strcmp(arg, "-ansi-color") == 0)
	    ansiColor = true;
	  else if (strcmp(arg, "-no-ansi-color") == 0)
	    ansiColor = false;
	  else if (strcmp(arg, "-no-prelude") == 0)
	    readPrelude = false;
	  else if (strcmp(arg, "-batch") == 0)
	    handleCtrlC = false;
	  else if (strcmp(arg, "-interactive") == 0)
	    forceInteractive = true;
	  else
	    {
	      IssueWarning(LineNumber(FileTable::COMMAND_LINE) <<
			   ": unrecognised flag: " << QUOTE(arg));
	    }
	}
      else
	pendingFiles.append(arg);
    }

  if (ansiColor == UNDECIDED)
    {
      //
      //	By default we allow ANSI escape code unless
      //	environment variable TERM is set to dumb; or
      //	our standard output is not a terminal.
      //
      ansiColor = true;
      const char* term = getenv("TERM");
      if ((term != 0 && strcmp("dumb", term) == 0) ||
	  isatty(STDOUT_FILENO) == 0)
	ansiColor = false;
    }
  Tty::setEscapeSequencesAllowed(ansiColor);

  printBanner(cout);
  createRootBuffer(stdin, forceInteractive);
  UserLevelRewritingContext::setHandlers(handleCtrlC);
  ioManager.setCommandLineEditing();
  directoryManager.initialize();
  string executable(argv[0]);
  findExecutableDirectory(executableDirectory, executable);
  if (readPrelude)
    {
      string directory;
      string fileName(PRELUDE_NAME);
      if (findPrelude(directory, fileName))
	includeFile(directory, fileName, true, FileTable::AUTOMATIC);
    }
  (void) UserLevelRewritingContext::commandLoop();
  return 0;
}

ostream& operator<<(ostream& s, const LineNumber& lineNumber)
{
  fileTable.printLineNumber(s, lineNumber.getLineNumber());
  return s;
}

const char*
isFlag(const char* arg, const char* flag)
{
  char f;
  do
    {
      f = *flag++;
      if (f == 0)
        return arg;
    }
  while (f == *arg++);
  return 0;
}

bool
findExecutableDirectory(string& directory, string& executable)
{
  string::size_type p = executable.rfind('/');
  if (p == string::npos)
    return directoryManager.searchPath("PATH", directory, executable, X_OK);
  else
    {
      directoryManager.realPath(executable.substr(0, p), directory);
      return directoryManager.checkAccess(directory, executable, X_OK);
    }
}

bool
findPrelude(string& directory, string& fileName)
{
  if (directoryManager.searchPath(MAUDE_LIB, directory, fileName, R_OK))
    return true;
  if (!(executableDirectory.empty()) &&
      directoryManager.checkAccess(executableDirectory, fileName, R_OK))
    {
      directory = executableDirectory;
      return true;
    }
  if (directoryManager.checkAccess(".", fileName, R_OK))
    {
      directory = ".";
      return true;
    }
  IssueWarning(LineNumber(FileTable::AUTOMATIC) <<
	       ": unable to locate file: \"" << QUOTE(fileName));
  return false;
}

bool
findFile(const string& userFileName, string& directory, string& fileName, int lineNr)
{
  static char const* const ext[] = {".maude", ".fm", ".obj", 0};

  string::size_type p = userFileName.rfind('/');
  if (p == string::npos)
    {
      fileName = userFileName;
      directory = ".";
      if (directoryManager.checkAccess(directory, fileName, R_OK, ext))
	return true;
      if (directoryManager.searchPath(MAUDE_LIB, directory, fileName, R_OK, ext))
	return true;
      if (!(executableDirectory.empty()) &&
	  directoryManager.checkAccess(executableDirectory, fileName, R_OK, ext))
	{
	  directory = executableDirectory;
	  return true;
	}
    }
  else if (p + 1 < userFileName.length())
    {
      directoryManager.realPath(userFileName.substr(0, p), directory);
      fileName = userFileName.substr(p + 1);
      if (directoryManager.checkAccess(directory, fileName, R_OK, ext))
	return true;
    }
  IssueWarning(LineNumber(lineNr) <<
	       ": unable to locate file: " << QUOTE(userFileName));
  return false;
}
