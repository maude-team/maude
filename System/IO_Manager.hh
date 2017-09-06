//
//      Class for managing yucky I/O issues.
//
#ifndef _IO_Manager_hh_
#define _IO_Manager_hh_

struct GetLine;  // to avoid sucking in the tecla header file

class IO_Manager
{
  NO_COPYING(IO_Manager);

public:
  enum Defaults
  {
    MAX_LINE_LENGTH = 1024,
    MAX_HISTORY_LENGTH = 4096,
    DEFAULT_COLUMNS = 80,
    DEFAULT_LINES = 25
  };

  IO_Manager::IO_Manager();

  void setAutoWrap();
  void setCommandLineEditing(size_t maxLineLength = MAX_LINE_LENGTH,
			     size_t maxHistoryLength = MAX_HISTORY_LENGTH);
  void setPrompt(const string& newPrompt);
  void setContPrompt(const string& newContPrompt);
  void startCommand();
  int getInput(char* buf, int maxSize, FILE* stream);

private:
  GetLine* gl;
  const char* line;
  bool contFlag;
  string prompt;
  string contPrompt;
  AutoWrapBuffer* wrapOut;
  AutoWrapBuffer* wrapErr;
};

inline void
IO_Manager::setPrompt(const string& newPrompt)
{
  prompt = newPrompt;
}

inline void
IO_Manager::setContPrompt(const string& newContPrompt)
{
  contPrompt = newContPrompt;
}

inline void
IO_Manager::startCommand()
{
  contFlag = false;
}

#endif
