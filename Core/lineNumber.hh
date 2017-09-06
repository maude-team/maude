//
//      Class for line numbers.
//
#ifndef _lineNumber_hh_
#define _lineNumber_hh_

class LineNumber
{
public:
  LineNumber(int lineNumber = UNDEFINED);
  int getLineNumber() const;
  void setLineNumber(int lineNr);

private:
  int lineNumber;
};

inline
LineNumber::LineNumber(int lineNumber)
  : lineNumber(lineNumber)
{
}

inline int
LineNumber::getLineNumber() const
{
  return lineNumber;
}

inline void
LineNumber::setLineNumber(int lineNr)
{
  lineNumber = lineNr;
}

//
//	Output function for LineNumber must be defined by library user.
//
ostream& operator<<(ostream& s, const LineNumber& lineNumber);

#endif
