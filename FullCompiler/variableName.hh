//
//	Class for C++ variable names composed of a one character base and a short index.
//
#ifndef _variableName_hh_
#define _variableName_hh_
#ifdef __GNUG__
#pragma interface
#endif

class VariableName
{
public:
  VariableName();
  VariableName(char base, short index);

private:
  int combined;
  friend ostream& operator<<(ostream& s, VariableName v);
};

inline
VariableName::VariableName()
{
}

inline
VariableName::VariableName(char base, short index)
{
  combined = (base << 16) | index;
}

inline ostream&
operator<<(ostream& s, VariableName v)
{
  s << static_cast<char>(v.combined >> 16) << (v.combined & 0xffff);
  return s;
}

#endif
