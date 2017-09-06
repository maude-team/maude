//
//      Class for streambuf with automatic line wrapping.
//
//	The basic idea is when we see a legal place to insert a \n
//	we put subsequent chars into a pending buffer until we known
//	whether to use this place.
//
//	Decisions on legal places are complicated by "strings",
//	ESC ... m sequences and backquotes.
//
//	Decisions on whether we need to insert a \n depend on width
//	calculations which are complicated by tabs and ESC ... m sequences.
//
#ifndef _autoWrapBuf_hh_
#define _autoWrapBuf_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include <string>

class AutoWrapBuffer : public std::streambuf
{
  NO_COPYING(AutoWrapBuffer);

public:
  AutoWrapBuffer(streambuf* outputBuffer, int lineWidth);

  void setLineWidth(int lineWidth);
  //
  //	Member functions we need to override from streambuf to get
  //	hold of raw characters.
  //
  int sync();
  int overflow(int ch);

private:
  enum Options
  {
    LEFT_MARGIN = 4,
    RIGHT_MARGIN = 1
  };

  void handleChar(int ch);
  void handleEscapeSequenceChar(int ch);
  int nextTabPosition(int pos);
  void dumpBuffer();
  void decideOnBreak();
  void legalPositionToBreak();

  streambuf* outputBuffer;
  int lineWidth;		// width of output device
  int cursorPosition;		// cursor position if we were to print pendingBuffer
  Bool seenBackQuote;		// last char was a `
  Bool seenBackSlash;		// inside a "string" and last char was an unescaped
  				// backslash
  Bool inString;		// inside a "string"
  Bool inEscape;		// inside an ESC sequence
  string pendingBuffer;
  int pendingWidth;		// number of chars in buffer excluding \t and ESC sequences
};

inline void
AutoWrapBuffer::setLineWidth(int lineWidth)
{
  AutoWrapBuffer::lineWidth = lineWidth;
}

inline int
AutoWrapBuffer::nextTabPosition(int pos)
{
  return (pos + 8) & ~7;
}

#endif
