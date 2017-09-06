//
//      Implementation for class Indent
//
#ifdef __GNUG__
#pragma implementation
#endif

#include "macros.hh"
#include "indent.hh"

ostream&
operator<<(ostream& s, const Indent& indent)
{
  for (int i = 0; i < indent.level; i++)
    s << INDENT_STRING;
  return s;
}
