//
//	Class for integer Bin->Dec conversion by multiply and add.
//
#ifndef _decBuf_hh_
#define _decBuf_hh_
#include <deque>

class DecBuf
{
public:
  void zero();
  void insertDigit(int d);
  int nrDigits();
  int nrTrailingZeros();
  void shiftAndAdd(int shift, Uint64 c);
  void ascii(char* s, int length);
  void round(int roundTo, bool fracGtZero, int fracCmpHalf);

private:
  void increment(int startDigit);

  deque<char> buf;
};

inline void
DecBuf::zero()
{
  buf.clear();
}

inline void
DecBuf::insertDigit(int d)
{
  Assert(d >= 0 && d <= 9, cerr << "bad digit");
  buf.push_front(d);
}

inline int
DecBuf::nrDigits()
{
  return buf.size();
}

#endif
