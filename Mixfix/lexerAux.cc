//
//	Auxiliary functions and data needed by lexical analyzer.
//
#ifdef SUNOS
extern "C" int isatty(int fd);
#endif
#define MAX_IN_DEPTH	10

int inStackPtr = 0;
YY_BUFFER_STATE inStack[MAX_IN_DEPTH];
int dirMarkerStack[MAX_IN_DEPTH];
Vector<char*> pendingFiles;
int nrPendingRead = 0;
bool rootInteractive = false;

void
getInput(char* buf, int& result, int max_size)
{
  static bool fakeNewline = false;  // fake \n for files that don't end with \n

  result = 0;
  if (UserLevelRewritingContext::interrupted())
    fakeNewline = false;
  else
    {
      int n = ioManager.getInput(buf, max_size, yyin);
      if (UserLevelRewritingContext::interrupted())
	fakeNewline = false;
      else
	{
	  if (n > 0)
	    {
	      result = n;
	      fakeNewline = (buf[n - 1] != '\n');
	    }
	  else
	    {
	      if (fakeNewline && max_size > 0)
		{
		  buf[0] = '\n';
		  result = 1;
		  fakeNewline = false;
		}
	    }
	}
    }
}

void
cleanUpLexer()
{
  if (inStackPtr > 0)
    {
      IssueAdvisory("closing open files.");
      while (inStackPtr > 0)
	{
	  fclose(yyin);
	  yy_delete_buffer(YY_CURRENT_BUFFER);
	  --inStackPtr;
	  yy_switch_to_buffer(inStack[inStackPtr]);
	}
      directoryManager.popd(dirMarkerStack[0]);
      UserLevelRewritingContext::setInteractive(rootInteractive);
    }
  fileTable.abortEverything(lineNumber);
  nrPendingRead = pendingFiles.length();  // avoid any further reading of pending files
  BEGIN(INITIAL);
}

void
lexerIdMode()
{
  BEGIN(ID_MODE);
}

void
lexerCmdMode()
{
  BEGIN(CMD_MODE);
}

void
lexerInitialMode()
{
  BEGIN(INITIAL);
}

void
lexerFileNameMode()
{
  yy_push_state(FILE_NAME_MODE);
}

void
lexerStringMode()
{
  yy_push_state(STRING_MODE);
}

void
lexerLatexMode()
{
  braceCount = 0;
  parenCount = 1;
  latexCode.erase();
  yy_push_state(LATEX_MODE);
}

void
createRootBuffer(FILE* fp, bool forceInteractive)
{
  yy_switch_to_buffer(yy_create_buffer(fp, YY_BUF_SIZE));
  rootInteractive = forceInteractive || (isatty(fileno(fp)) > 0);
  UserLevelRewritingContext::setInteractive(rootInteractive);
}

bool
includeFile(const string& directory, const string& fileName, bool silent, int lineNr)
{
  if (inStackPtr >= MAX_IN_DEPTH)
    {
      IssueWarning(LineNumber(lineNr) <<
		   ": ins nested too deeply - couldn't open file " <<
		   QUOTE(fileName));
      return false;
    }
  int dirMarker = directoryManager.pushd(directory.c_str());
  if (dirMarker == UNDEFINED)
    {
      IssueWarning(LineNumber(lineNr) << ": couldn't chdir to " <<
		   QUOTE(directory));
      return false;
    }
  FILE* fp = fopen(fileName.c_str(), "r");
  if (fp == 0)
    {
      IssueWarning(LineNumber(lineNr) << ": couldn't open file " <<
		   QUOTE(fileName));
      directoryManager.popd(dirMarker);
      return false;
    }
  dirMarkerStack[inStackPtr] = dirMarker;
  inStack[inStackPtr] = YY_CURRENT_BUFFER;
  ++inStackPtr;
  yyin = fp;
  fileTable.openFile(lineNumber, fileName.c_str(), silent);
  yy_switch_to_buffer(yy_create_buffer(yyin, YY_BUF_SIZE));
  UserLevelRewritingContext::setInteractive(false);
  return true;
}

bool
handleEof()
{
  if (inStackPtr == 0)
    return false;
  --inStackPtr;
  fclose(yyin);
  fileTable.closeFile(lineNumber);
  yy_delete_buffer(YY_CURRENT_BUFFER);
  yy_switch_to_buffer(inStack[inStackPtr]);
  directoryManager.popd(dirMarkerStack[inStackPtr]);
  if (inStackPtr == 0)
    {
      if (nrPendingRead < pendingFiles.length())
	{
	  string directory;
	  string fileName;
	  if (findFile(pendingFiles[nrPendingRead++], directory, fileName, FileTable::COMMAND_LINE) &&
	      includeFile(directory, fileName, true, FileTable::COMMAND_LINE))
	    return true;
	  nrPendingRead = pendingFiles.length();  // avoid any futher reading of pending files
	}
      UserLevelRewritingContext::setInteractive(rootInteractive);
    }
  return true;
}

void
eatComment(bool firstNonWhite)
{
  bool passThrough = !firstNonWhite && fileTable.outputLine();
  bool parenMode = false;
  int parenCount = 0;
  bool backquoteSeen = false;
  for (;;)
    {
      int c = yyinput();
      switch(c)
	{
	case ' ':
	case '\t':
	case '\r':
	  break;
	case '\n':
	case '\f':
	  {
            ++lineNumber;
	    if (!parenMode)
	      {
		if (passThrough)
		  cout << endl;
		return;
	      }
	    break;
	  }
	case '(':
	  {
	    if (firstNonWhite)
	      {
		firstNonWhite = false;
		parenMode = true;
		parenCount = 1;
	      }
	    else
	      {
		if (parenMode && !backquoteSeen)
		  ++parenCount;
	      }
	    break;
	  }
	case ')':
	  {
	    if (parenMode && !backquoteSeen)
	      {
		--parenCount;
		if (parenCount == 0)
		  return;
	      }
	    break;
	  }
	case EOF:
	  return;
	default:
	  firstNonWhite = false;
	}
      backquoteSeen = (c == '`');
      if (passThrough)
	cout << static_cast<char>(c);
    }
}
