//
//	Implementation for class BinBuf.
//
#include "macros.hh"
#include "binBuf.hh"

void
BinBuf::init(Uint64 bits, int leadingZeros)
{
  Assert(leadingZeros <= 32 * (MAX_WORDS - 2),
	 "too many leading zeros" << leadingZeros);
  int zeroWords = leadingZeros >> 5;
  int rightShift = leadingZeros & 31;
  //
  //	Nonzero part will lie in buf[begin],...,buf[end - 1].
  //
  end = MAX_WORDS - zeroWords;
  begin = end - 2;
  buf[end - 1] = bits >> (rightShift + 32);
  buf[begin] = (bits >> rightShift) & 0xffffffff;
  if (rightShift > 0)
    buf[--begin] = (bits << (32 - rightShift)) & 0xffffffff;
}

int
BinBuf::times10()
{
  int c = 0;
  for (int i = begin; i < end; i++)
    {
      Uint64 r = (10ULL * buf[i]) + c;
      Uint32 t = r & 0xffffffff;
      if (i == begin & t == 0)
	++begin;
      else
	buf[i] = t;
      c = r >> 32;
    }
  if (c > 0 && end < MAX_WORDS)
    {
      buf[end] = c;
      ++end;
      c = 0;
    }
  return c;
}

bool
BinBuf::gtZero()
{
   for (int i = begin; i < end; i++)
    {
      if (buf[i] > 0)
	return true;
    }
   return false;
}

int
BinBuf::cmpHalf()
{
  if (end < MAX_WORDS || begin == end)
    return -1;
  if (buf[end - 1] < 0x80000000)
    return -1;
  if (buf[end - 1] > 0x80000000)
    return 1;
  for (int i = begin; i < end - 1; i++)
    {
      if (buf[i] > 0)
	return 1;
    }
  return 0;
}
