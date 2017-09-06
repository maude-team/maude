//
//	Class to abstract tty attributes.
//
#ifndef _tty_hh_
#define _tty_hh_

class Tty
{
public:
  enum Attribute
  {
    RESET,
    BRIGHT,
    DIM,
    UNDERLINE,
    BLINK,
    REVERSE,
    HIDDEN,
    
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    
    BKGD_BLACK,
    BKGD_RED,
    BKGD_GREEN,
    BKGD_YELLOW,
    BKGD_BLUE,
    BKGD_MAGENTA,
    BKGD_CYAN,
    BKGD_WHITE
  };

  Tty(Attribute attr);

private:
  static const char* const ansiCodes[];
  static bool allowedFlag;
  const Attribute attr;

  friend ostream& operator<<(ostream& s, const Attribute& c);
};

inline
Tty::Tty(Attribute attr)
  : level(level)
{
}

#endif
