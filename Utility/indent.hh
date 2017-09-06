//
//	Class to make generating indentation easy
//
#ifndef _indent_hh_
#define _indent_hh_
#ifdef __GNUG__
#pragma interface
#endif

//#define INDENT_STRING	": "
#define INDENT_STRING	"  "

class Indent
{
public:
  Indent(int level);

private:
  const int level;

  friend ostream& operator<<(ostream& s, const Indent& c);
};

inline
Indent::Indent(int level)
  : level(level)
{
}
 
#endif



  
