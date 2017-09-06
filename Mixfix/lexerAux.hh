//
//	Declarations for auxiliary functions needed by lexical analyzer.
//

extern int inStackPtr;
extern YY_BUFFER_STATE inStack[];

void getInput(char* buf, int& result, int max_size);
void lexerIdMode();
void lexerCmdMode();
void lexerOpMode();
void lexerInitialMode();
void lexerFileNameMode();
void lexerStringMode();
bool includeFile(const string& directory, const string& fileName, bool silent, int lineNr);
bool handleEof();
void eatComment(bool firstNonWhite);
void cleanUpLexer();
