//
//      Implementation for class AutoWrapBuffer.
//
#ifdef __GNUG__
#pragma implementation
#endif

//      utility stuff
#include "macros.hh"

//	system class definitions
#include "autoWrapBuffer.hh"

AutoWrapBuffer::AutoWrapBuffer(streambuf* outputBuffer, int lineWidth)
  : outputBuffer(outputBuffer), lineWidth(lineWidth)
{
  pendingWidth = UNDEFINED;
  cursorPosition = 0;
  seenBackQuote = false;
  seenBackSlash = false;
  inString = false;
  inEscape = false;
}

int
AutoWrapBuffer::sync()
{
  Assert(pptr() - pbase() == 0, cerr << "not supposed to have a buffer");
  //
  //	We don't dump the pending buffer here because stderr sync()s all
  //	the time and we would lose our opportunities for inserting a \n.
  //
#ifdef LIBv3
  return outputBuffer->pubsync();
#else
  return outputBuffer->sync();
#endif
}

void
AutoWrapBuffer::dumpBuffer()
{
  if (!(pendingBuffer.empty()))
    {
      outputBuffer->sputn(pendingBuffer.data(), pendingBuffer.size());
      pendingBuffer.erase();
    }
}

void
AutoWrapBuffer::handleEscapeSequenceChar(int ch)
{
  if (pendingWidth == UNDEFINED)
    outputBuffer->sputc(ch);  // buffering disabled
  else
    pendingBuffer.push_back(ch);
}

void
AutoWrapBuffer::handleChar(int ch)
{
  if (pendingWidth == UNDEFINED)
    outputBuffer->sputc(ch);  // buffering disabled
  else
    {
      pendingBuffer.push_back(ch);
      ++pendingWidth;
      if (pendingWidth > lineWidth - RIGHT_MARGIN - LEFT_MARGIN)
	{
	  //
	  //	Even inserting a \n before the characters in pendingBuffer
	  //	would not avoid a hard-wrapped token, so we don't bother.
	  //
	  dumpBuffer();
	  pendingWidth = UNDEFINED;  // disable buffering
	}
    }
}

void
AutoWrapBuffer::decideOnBreak()
{
  if (pendingWidth != UNDEFINED)
    {
      if (cursorPosition > lineWidth - RIGHT_MARGIN)
	{
	  outputBuffer->sputc('\n');
	  for (int i = 0; i < LEFT_MARGIN; i++)
	    outputBuffer->sputc(' ');
	  int nrPending = pendingBuffer.size();
	  cursorPosition = LEFT_MARGIN;
	  if (nrPending > 0)
	    {
	      int t = (pendingBuffer[0] == ' ');  // need to skip leading space
	      if (nrPending - t > 0)
		{
		  outputBuffer->sputn(pendingBuffer.data() + t, nrPending - t);
		  if (pendingBuffer[0] == '\t')
		    cursorPosition = nextTabPosition(cursorPosition) + pendingWidth;
		  else
		    cursorPosition += pendingWidth - t;
		}
	      pendingBuffer.erase();
	    }
	}
      else
	dumpBuffer();
      pendingWidth = UNDEFINED;  // disable buffering
    }
}

void
AutoWrapBuffer::legalPositionToBreak()
{
  //
  //	We just ecountered a legal position to insert a \n so we place
  //	subsequent characters in pendingBuffer and make sure cursor
  //	position is in range.
  //
  pendingWidth = 0;
  cursorPosition %= lineWidth;
}

int
AutoWrapBuffer::overflow(int ch)
{
  Assert(pptr() - pbase() == 0, cerr << "not supposed to have a buffer");
  if (ch == EOF)
    return EOF;
  if (inEscape)
    {
      handleEscapeSequenceChar(ch);
      if (ch == 'm')
	inEscape = false;
      return 0;
    }
  if (!isprint(ch))
    inString = false;
  switch (ch)
    {
    case '"':
      {
	if (!seenBackSlash)
	  inString = !inString;
	goto normal;
      }
    case '\033':
      {
	inEscape = true;
	handleEscapeSequenceChar(ch);
	break;
      }
    case '\n':
      {
	decideOnBreak();
	outputBuffer->sputc(ch);
	cursorPosition = 0;
	break;
      }
    case '\t':
      {
	decideOnBreak();
	legalPositionToBreak();
	handleEscapeSequenceChar(ch);
	cursorPosition = nextTabPosition(cursorPosition);
	break;
      }
    case ' ':
      {
	if (!inString)
	  {
	    decideOnBreak();
	    legalPositionToBreak();
	  }
	goto normal;
      }
#ifdef WRAP_BEFORE_CLOSING
    case ')':
    case ']':
    case '}':
      {
	if (!inString && !seenBackQuote)
	  {
	    //
	    //	ok to add new line before this character
	    //
	    decideOnBreak();
	    legalPositionToBreak();
	  }
	goto normal;
      }
#endif
    case ',':
    case '(':
    case '[':
    case '{':
      {
	if (!inString && !seenBackQuote)
	  {
	    //
	    //	ok to add new line after this character
	    //
	    handleChar(ch);
	    ++cursorPosition;
	    decideOnBreak();
	    legalPositionToBreak();
	    break;
	  }
	//
	//	If we have just seen a backquote or we are in a string,
	//	,([{ lose their special properties and we fall thru
	//	into default case.
	//
      }
    default:
      {
    normal:
	handleChar(ch);
	++cursorPosition;
	break;
      }
    }
  seenBackQuote = (ch == '`');
  seenBackSlash = inString && !seenBackSlash && (ch == '\\');
  return 0;
}
