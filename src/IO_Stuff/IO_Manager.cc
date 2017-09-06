/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//      Implementation for class IO_Manager.
//

#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <errno.h>

//      utility stuff
#include "macros.hh"
#include "rope.hh"

//	line editing stuff
#ifdef USE_TECLA
#if HAVE_SYS_TERMIOS_H
#include <sys/termios.h>
#endif
#include "libtecla.h"
#endif

//	IO Stuff class definitions
#include "autoWrapBuffer.hh"
#include "IO_Manager.hh"

IO_Manager::IO_Manager()
{
  gl = 0;
  line = 0;
  usePromptsAnyway = false;
  contFlag = false;
  wrapOut = 0;
  wrapErr = 0;
}

void
IO_Manager::setCommandLineEditing(size_t lineLength, size_t historyLength)
{
#ifdef USE_TECLA
  gl = new_GetLine(lineLength, historyLength);
  gl_trap_signal(gl, SIGINT, 0, GLS_ABORT, EINTR);
#endif
}

void
IO_Manager::setAutoWrap()
{
  //
  //	Set up autowrapping of standard output and standard error.
  //
  winsize w;

  int columns = DEFAULT_COLUMNS;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0 && w.ws_col > 0)
    columns = w.ws_col;
  // cout << "out columns " << columns << '\n';
  wrapOut = new AutoWrapBuffer(cout.rdbuf(), columns);
  (void) cout.rdbuf(wrapOut);

  columns = DEFAULT_COLUMNS;
  if (ioctl(STDERR_FILENO, TIOCGWINSZ, &w) == 0 && w.ws_col > 0)
    columns = w.ws_col;
  // cout << "err columns " << columns << '\n';
  wrapErr = new AutoWrapBuffer (cerr.rdbuf(), columns);
  (void) cerr.rdbuf(wrapErr);
}

ssize_t
IO_Manager::getInput(char* buf, size_t maxSize, FILE* stream)
{
  if (stream != stdin)
    {
      //
      //	Some stdio libraries (notably that of linux) have a nasty habit
      //	of restarting slow system calls aborted by signals. We avoid
      //	this behaviour by doing input directly from the OS.
      //
      return read(fileno(stream), buf, maxSize);
    }

#ifdef USE_TECLA
  if (gl != 0)
    {
      if (line == 0)
	{
	  
	  line = gl_get_line(gl,
			     contFlag ? contPrompt.c_str() : prompt.c_str(),
			     NULL,
			     -1);
	  GlTerminalSize ts = gl_terminal_size(gl, DEFAULT_COLUMNS, DEFAULT_LINES);
	  if (wrapOut != 0)
	    wrapOut->setLineWidth(ts.ncolumn);
	  if (wrapErr != 0)
	    wrapErr->setLineWidth(ts.ncolumn);
	  contFlag = true;
	  if (line == 0)
	    return 0;
	}
      
      size_t n;
      for (n = 0;; n++)
	{
	  char c = *line;
	  if (c == '\0')
	    {
	      line = 0;
	      break;
	    }
	  if (n == maxSize)
	    break;
	  *buf++ = c;
	  ++line;
	}
      return n;
    }
#endif
  //
  //	Read from stdin without using tecla.
  //	It's important that we only read a line at a time from stdin,
  //	now that we allow Maude programs to read from stdin. Otherwise
  //	characters past \n could be buffered by the lexer.
  //
  if (usePromptsAnyway)
    {
      fputs(contFlag ? contPrompt.c_str() : prompt.c_str(), stdout);  // HACK: bypass line wrapper
      fflush(stdout);
      contFlag = true;
    }
  return boundedGetLine(buf, maxSize, stdin);
}

ssize_t
IO_Manager::boundedGetLine(char* buf, size_t maxSize, FILE* stream)
{
  //
  //	This is a hybrid between read() that reads a bounded number
  //	of characters but will read past \n, and getline() that only
  //	reads up to \n but will reallocate() (requiring that buf was
  //	malloc()'d) to return any number of characters, and null
  //	terminating.
  //
  //	We read up to and including the \n OR the bound, which ever
  //	is reached first. Null termination is not added to we can
  //	read nulls OK.
  //
  size_t index = 0;
  for (;;)
    {
      int c = getc(stream);
      if (c == EOF)
	return (index > 0) ? index : EOF;
      buf[index] = c;
      ++index;
      if (c == '\n' || index == maxSize)
	break;
    }
  return index;
}

Rope
IO_Manager::getLine(const Rope& prompt, FILE* stream)
{
  //cerr << "getLine() prompt = " << prompt << endl;
  //
  //	Get a line as a Rope, possibly using Tecla.
  //
#ifdef USE_TECLA
  if (gl != 0 && isatty(fileno(stream)))
    {
      char* promptString = prompt.makeZeroTerminatedString();
      line = gl_get_line(gl, promptString, NULL, -1);  //  ignore any partial line left in line
      delete [] promptString;
      if (line == 0)
	return Rope();  // return empty rope on error or eof
      Rope result(line);
      line = 0;
      return result;
    }
#endif
  //cerr << "Non tecla case" << endl;
  //
  //	Non-Tecla case. Either Tecla not compiled it, or disabled or
  //	we are getting the line from a file.
  //
  char* promptString = prompt.makeZeroTerminatedString();
  fputs(promptString, stdout);  // HACK: bypass line wrapper
  fflush(stdout);
  delete [] promptString;

  char* localLine = 0;
  size_t n = 0;
  ssize_t nrRead = getline(&localLine, &n, stream);
  //cerr << "nrRead = " << nrRead << endl;
  if (nrRead == -1)
    {
      if (localLine != 0)
	free(localLine);  // getline() might have realloc()'d memory
      return Rope();  // return empty rope on error or eof
    }
  Rope result(localLine, nrRead);
  if (localLine != 0)
    free(localLine);
  return result;
}
