//
//	Class for fractional binary to decimal conversion.
//
#ifndef _binBuf_hh_
#define _binBuf_hh_

class BinBuf
{
public:
  void init(Uint64 bits, int leadingZeros);
  int times10();
  int cmpHalf();
  bool gtZero();

private:
  enum Sizes
  {
    //
    //	A double could have 52 + 1022 = 1074 bits following the binary point so
    //	we need at most ceiling(1074 / 32) = 34 32-bit words to hold the fixed point
    //	binary fraction.
    //
    MAX_WORDS = 34
  };

  Uint32 buf[MAX_WORDS];
  int begin;
  int end;
};

#endif
