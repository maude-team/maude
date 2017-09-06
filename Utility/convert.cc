//#include <math.h>
//#include <ieeefp.h>
#include "macros.hh"
#include "decBuf.hh"
#include "binBuf.hh"

void
correctEcvt(double d, int nrDigits, char buffer[], int& decPt, int& sign)
{
  union Bits
  {
    Uint64 i;
    double d;
  };
  
  const Uint64 bit52 = (1ULL << 52);
  const Uint64 topBit = (1ULL << 63);
  
  //
  //	Break IEEE-754 double into sign/exponent/mantissa.
  //
  Bits bits;
  bits.d = d;
  sign = bits.i >> 63;  // top bit
  Uint64 mantissa = bits.i & (bit52 - 1);  // 52 LSBs
  int exponent = (static_cast<int>(bits.i >> 52) & 0x7FF);  // remaining 11 bits
  if (exponent == 2047)
    {
      strcpy(buffer, (mantissa == 0) ? "Infinity" : "NaN");
      decPt = 0;
      return;
    }
  if (exponent == 0)
    {
      if (mantissa == 0)  // +/- zero
	{
	  for (int i = 0; i < nrDigits; i++)
	    buffer[i] = '0';
	  buffer[nrDigits] = '\0';
	  decPt = 0;
	  return;
	}
      exponent = -1022;  // denormalized number
    }
  else
    {
      exponent -= 1023;  // unbiased exponent
      mantissa |= bit52;  // implied leading 1
    }
  DecBuf dec;
  BinBuf bin;
  dec.zero();
  mantissa <<= 11;  // now the 53 MSBs
  ++exponent;  // number of bits to the left of the binary point
  if (exponent > 0)
    {
      //
      //	Case 1: Integer part which is converted by shift and add
      //	on a decimal buffer; plus a possible fraction part.
      //	We convert integer part of exponent bits, 60 bits at a time
      //	because 10 * 2^60 < 2^64.
      //
      {
	int shift = min(exponent, 60);
	dec.shiftAndAdd(shift, mantissa >> (64 - shift));
	mantissa <<= shift;
	exponent -= shift;
      }
      while (exponent > 0)
	{
	  int shift = min(exponent, 60);
	  dec.shiftAndAdd(shift, 0);
	  exponent -= shift;
	}
      if (nrDigits <= 0)  // exact conversion
	{
	  decPt = dec.nrDigits();  // can't increase because we don't round
	  if (mantissa == 0)
	    dec.ascii(buffer, decPt - dec.nrTrailingZeros());
	  else
	    {
	      bin.init(mantissa, 0);
	      do
		dec.insertDigit(bin.times10());
	      while (bin.gtZero());
	      dec.ascii(buffer, dec.nrDigits());
	    }
	}
      else  // round to nrDigits using IEEE-754 "round to nearest" convention
	{
	  int extraDigitsNeeded = nrDigits - dec.nrDigits();
	  if (extraDigitsNeeded <= 0)
	    {
	      //
	      //	We have enough digits so round using fractional part
	      //	of mantissa.
	      //
	      int cmpHalf = (mantissa == topBit) ? 0 : ((mantissa < topBit) ? -1 : 1);
	      dec.round(nrDigits, mantissa > 0, cmpHalf);
	      decPt = dec.nrDigits();
	    }
	  else
	    {
	      //
	      //	Make more digits by converting fraction.
	      //
	      bin.init(mantissa, 0);
	      for (int i = 0; i < extraDigitsNeeded; i++)
		dec.insertDigit(bin.times10());
	      //
	      //	Round using part of fraction left in bin.
	      //
	      dec.round(nrDigits, bin.gtZero(), bin.cmpHalf());
	      decPt = dec.nrDigits() - extraDigitsNeeded;
	    }
	  dec.ascii(buffer, nrDigits);
	}
    }
  else
    {
      //
      //	Case 2: No integer part. Fraction is converted by
      //	repeatedly multiplying it by 10.
      //
      bin.init(mantissa, -exponent);
      decPt = 1;
      int digit;
      do
	{
	  digit = bin.times10();
	  --decPt;
	}
      while (digit == 0);
      dec.insertDigit(digit);
      if (nrDigits <= 0)  // exact conversion
	{
	  while (bin.gtZero())
	    dec.insertDigit(bin.times10());
	  dec.ascii(buffer, dec.nrDigits());
	}
      else  // round to nrDigits using IEEE-754 "round to nearest" convention
	{
	  for (int i = 1; i < nrDigits; i++)
	    dec.insertDigit(bin.times10());
	  //
	  //	Round using part of fraction left in bin.
	  //
	  dec.round(nrDigits, bin.gtZero(), bin.cmpHalf());
	  decPt += (dec.nrDigits() - nrDigits);  // rounding may have given us an extra digit
	  dec.ascii(buffer, nrDigits);
	}
    }
}
