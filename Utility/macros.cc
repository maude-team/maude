//
//	Implementation for macros; needed so that we can still link
//	even when macros are not inlined (eg when compiling with
//	optimization off).
//
#ifdef __GNUG__
#pragma implementation "macros.hh"
#pragma implementation "flagSet.hh"
#endif
#include <math.h>
#ifdef SOLARIS
#include <ieeefp.h>
#endif
#include <strstream>

#include "macros.hh"
#include "vector.hh"
#include "decBuf.hh"
#include "binBuf.hh"
#include "flagSet.hh"

bool globalAdvisoryFlag = true;
bool globalVerboseFlag = false;

const char*
int64ToString(Int64 i, int base)
{
  Assert(base >= 2 && base <= 36, cerr << "bad base");
  const int MAX_STRING_SIZE = 64 + 1;  // 64 bits + sign
  const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  static char text[MAX_STRING_SIZE + 1];
  char* p = text + MAX_STRING_SIZE;
  bool negative = false;
  Uint64 u = i;
  if (i < 0)
    {
      u = static_cast<Uint64>(- (i + 1)) + 1;
      negative = true;
    }
  do
    {
      *(--p) = digits[u % base];
      u /= base;
    }
  while (u > 0);
  if (negative)
    *(--p) = '-';
  return p;
}

Int64
stringToInt64(const char* s, bool& error, int base)
{
  Assert(base >= 2 && base <= 36, cerr << "bad base");
  error = true;
  bool negative = false;
  switch (*s)
    {
    case '-':
      negative = true;
      // fall thru
    case '+':
      ++s;
    }
  Int64 r = 0;
  for (;;)
    {
      char c = *s++;
      if (c == '\0')
	break;
      int v;
      if (isdigit(c))
	v = c - '0';
      else if (isupper(c))
	v = c - 'A' + 10;
      else if (islower(c))
	v = c - 'a' + 10;
      else
	{
	  error = true;
	  break;
	}
      if (v >= base)
	{
	  error = true;
	  break;
	}
      if (r > (INT64_MAX - v) / base)
	{
	  if (negative && *s == '\0')  // check for INT64_MIN
	    {
	      Int64 t = -(INT64_MIN + base + v);
	      if (t % base == 0 && t / base == r - 1)
		return INT64_MIN;
	    }
	  error = true;
	  break;
	}
      r = r * base + v;
      error = false;
    }
  return negative ? -r : r;
}

bool
looksLikeFloat(const char* s)
{
  bool digits = false;
  bool dot = false;
  char c = *s++;
  if (c == '+' || c == '-')
    c = *s++;
  if (strcmp(s - 1, "Infinity") == 0)
    return true;
  if (isdigit(c))
    {
      digits = true;
      do
	c = *s++;
      while (isdigit(c));
    }
  if (c == '.')
    {
      dot = true;
      c = *s++;
      if (isdigit(c))
	{
	  digits = true;
	  do
	    c = *s++;
	  while (isdigit(c));
	}
    }
  if (!digits)
    return false;
  if (c == 'e' || c == 'E')
    {
      c = *s++;
      if (c == '+' || c == '-')
	c = *s++;
      if (!isdigit(c))
	return false;
      do
	c = *s++;
      while (isdigit(c));
    }
  else
    {
      if (!dot)
	return false;
    }
  return c == '\0';
}

const char*
doubleToString(double d)
{
  if (!finite(d))
    {
      if (isnan(d))
	return "NaN";
      else
	return (d < 0) ? "-Infinity" : "Infinity";
    }
  static char buffer[DOUBLE_TEXT_SIZE + 1];
  ostrstream s(buffer, DOUBLE_TEXT_SIZE + 1);
  s.setf(ios::scientific);
  s.precision(16);
  s << d << '\0';
  //
  //	Now clean number up by removing extraneous trailing 0s from mantissa
  //	and leading 0s from exponent. If exponent is zero remove it altogether.
  //
  int dp = 1;
  if (buffer[dp] != '.')
    {
      ++dp;
      if (buffer[dp] != '.')
	return buffer;  // must be special representation
    }
  int lastNonzero = dp + 16;
  while (lastNonzero > dp + 1 && buffer[lastNonzero] == '0')
    --lastNonzero;
  int exponentStart = dp + 17;
  Assert(buffer[exponentStart] == 'e', cerr << "misplaced exponent");
  int exponentFirstDigit = exponentStart + 1;
  if (!isdigit(buffer[exponentFirstDigit]))
    ++exponentFirstDigit;  // skip sign
  int firstNonzero = exponentFirstDigit;
  while (buffer[firstNonzero] == '0')
    ++firstNonzero;
  if (buffer[firstNonzero] == '\0')
    buffer[lastNonzero + 1] = '\0';  // lose exponent
  else
    {
      char* p = buffer + lastNonzero + 1;
      for (int i = exponentStart; i < exponentFirstDigit; i++)
	*p++ = buffer[i];
      for (int i = firstNonzero; (*p++ = buffer[i]); i++)
	;
    }
  return buffer;
}

double
stringToDouble(const char* s, bool& error)
{
  if (looksLikeFloat(s))
    {
      error = false;
      return atof(s);
    }
  else
    {
      error = true;
      return 0;
    }
}

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
  sign = (bits.i >> 63) ? -1 : 1;  // top bit = 1 -> -ve
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
	  sign = 0;
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
