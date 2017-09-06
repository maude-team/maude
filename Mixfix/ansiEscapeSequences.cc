//
//	List of ANSI Escape sequences - used to generate branching
//	code in various places. Format is
//	  MACRO(Maude name, class Tty name)
//	We don't include reset because it is special.
//
  MACRO('!', BRIGHT)
  MACRO('?', DIM)
  MACRO('u', UNDERLINE)
  MACRO('f', BLINK)
  MACRO('x', REVERSE)
  MACRO('h', HIDDEN)

  MACRO('p', BLACK)  // pitch black - b is for blue
  MACRO('r', RED)
  MACRO('g', GREEN)
  MACRO('y', YELLOW)
  MACRO('b', BLUE)
  MACRO('m', MAGENTA)
  MACRO('c', CYAN)
  MACRO('w', WHITE)

  MACRO('P', BKGD_BLACK)
  MACRO('R', BKGD_RED)
  MACRO('G', BKGD_GREEN)
  MACRO('Y', BKGD_YELLOW)
  MACRO('B', BKGD_BLUE)
  MACRO('M', BKGD_MAGENTA)
  MACRO('C', BKGD_CYAN)
  MACRO('W', BKGD_WHITE)
