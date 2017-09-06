//
//	Global variables
//
extern int lineNumber;
extern FileTable fileTable;
extern DirectoryManager directoryManager;
//int yylex(YYSTYPE* lvalp);
extern Interpreter interpreter;
#include "IO_Manager.hh"  // HACK
extern IO_Manager ioManager;

bool
findPrelude(string& directory, string& fileName);

bool
findFile(const string& userFileName, string& directory, string& fileName, int lineNr);

bool findExecutableDirectory(string& directory, string& executable);
