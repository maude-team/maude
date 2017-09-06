//
//	Macros, typedefs, enums and includes.
//
#ifndef _macros_hh_
#define _macros_hh_
#ifdef __GNUG__
#pragma interface
#endif
//
//	C stuff.
//
using namespace std;

#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
//
//	C++ stuff.
//
#include <new>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

//#include <strstream.h>

//
//	Forward declarations for utility classes.
//
class NatSet;
class Graph;
class Digraph;
class UnionFind;
class DiophantineSystem;
class SequencePartition;
class StringTable;
class SymbolTable;
class PointerMap;
class PointerSet;
class BddUser;
class Bdd;
class Tty;
class Timer;
class FlagSet;

//
//	Types for storage efficiency.
//
typedef char Bool;
typedef signed char Byte;
typedef unsigned char Ubyte;
//
//	Shorthand.
//
typedef unsigned int Uint;
//
//	64 bit arithmetic; since it's now practical to deal with quantities
//	of rewrites/matchers/unifiers etc that overflow 32 bits.
//
typedef long long int Int64;
#ifdef INT64_MAX
#undef INT64_MAX
#endif
#ifdef INT64_MIN
#undef INT64_MIN
#endif
typedef unsigned long long int Uint64;
//
//	gcc needs the LL suffix to do the right thing; and these are too big to be enums.
//
#define INT64_MAX		(9223372036854775807LL)
#define INT64_MIN		(-INT64_MAX-1)
#define INT64_MIN_STRING	"-9223372036854775808"
//
//	32 bit arithmetic; sometime we need guarentee of left truncation.
//
typedef int Int32;
typedef unsigned int Uint32;
//
//	floating point
//
//	This is the largest integer such that all integers in the range
//	-INT_DOUBLE_MAX, ..., INT_DOUBLE_MAX
//	can be represented exactly.
#define INT_DOUBLE_MAX		(1LL << 53)

//
//	Macro to forbid default copy ctor and assignment operator
//
#define NO_COPYING(c)	c(const c&); c& operator=(const c&)

//
//	Casting which is checked if debugging and fast otherwise.
//
#ifndef NO_ASSERT
#define safeCast(T, P) \
  ((P != 0 && dynamic_cast<T>(P) == 0) ? \
    ((cerr << "cast error: "<< __FILE__ << ':' << __LINE__ << '\n'), abort(), static_cast<T>(0)) : \
    static_cast<T>(P))
#else
#define safeCast(T, P)	static_cast<T>(P)
#endif

enum SpecialConstants
{
  NR_PTR_LOSE_BITS = 3,		// number of rhs bits to chop when hashing a pointer
  WORD_SIZE = 32,		// bits per machine word
  LOG_WORD_SIZE = 5,		// log_2 (WORD_SIZE)
  UNBOUNDED = INT_MAX,		// integer used as stand-in for +infinity
  INT_TEXT_SIZE = 11,		// max chars for text representation of an int (INT_MIN)
  INT64_TEXT_SIZE = 20,		// max chars for text representation of a 64 bit int (INT64_MIN)
  DOUBLE_TEXT_SIZE = 24,	// max chars for text representation of a double in
  				// in scientific format with 17 significant figures
  				// -1.2345678901234567e-123
  //
  //	-1 get used for lots of "out-of-band" purposes.
  //
  UNDEFINED = -1,
  UNDECIDED = -1,		// for true, false, dunno situtations
  UNUSED = -1,
  NONE = -1,
  DEFAULT = -1,
  //
  //	For bit twiddling; things will probably break if bytes are ever
  //	longer or shorter than 8 bits.
  //
  BITS_PER_BYTE = 8,
  BITS_PER_INT = BITS_PER_BYTE * sizeof(int),
  BITS_PER_UINT = BITS_PER_BYTE * sizeof(unsigned int)
};

#ifdef NO_IMPLEMENT_INLINES
//#define inline extern __inline__
#endif

#ifdef LOCAL_INLINES
#define local_inline extern __inline__
#else
#define local_inline
#endif

#ifndef NO_ASSERT

#define \
Assert(condition, action) \
if (!(condition)) \
((cerr << "ASSERT FAILED: " << __FILE__ << ':' << __LINE__ << '\n'), \
(action), (cerr << '\n'), abort())

#define \
CantHappen(message) \
((cerr << "CAN'T HAPPEN: " << \
__FILE__ << ':' << __LINE__ << '\n' << message << endl), \
abort())

#define \
DebugAdvisoryCheck(condition, action)\
if (!(condition)) \
((cerr << "DEBUG ADVISORY: "), (action), (cerr << endl))

#define \
DebugAdvisory(message) \
(cerr << "DEBUG ADVISORY: " << message << endl)

#else

#define Assert(condition, action)
#define CantHappen(message)
#define DebugAdvisoryCheck(condition, action)
#define DebugAdvisory(message)

#endif

#include "tty.hh"
#define WARNING_HEADER	Tty(Tty::RED) << "Warning: " << Tty(Tty::RESET)
#define ADVISORY_HEADER	Tty(Tty::GREEN) << "Advisory: " << Tty(Tty::RESET)
#define BEGIN_QUOTE	Tty(Tty::MAGENTA)
#define END_QUOTE	Tty(Tty::RESET)
#define QUOTE(s)	BEGIN_QUOTE << s << END_QUOTE

#define \
WarningCheck(condition, message)\
if (!(condition)) \
(cerr << WARNING_HEADER << message << endl)

#define \
AdvisoryCheck(condition, message)\
if (!(condition) && globalAdvisoryFlag) \
(cerr << ADVISORY_HEADER << message << endl)

#define \
IssueWarning(message) \
(cerr << WARNING_HEADER << message << endl)

#define \
IssueAdvisory(message)\
if (globalAdvisoryFlag) \
(cerr << ADVISORY_HEADER << message << endl)

#define \
Verbose(output) \
if (globalVerboseFlag) \
(cout << output << '\n')

extern bool globalAdvisoryFlag;
extern bool globalVerboseFlag;

//
//	A machine word should be about to hold any pointer, int or size
//	(but not necessarily an Int64)
//
union MachineWord
{
  void* pointer;
  int integer;
  size_t size;
};

inline void
swap(int& a, int& b)
{
  int t = a;
  a = b;
  b = t;
}

inline int
uplus(int a, int b)
{
  return (a == UNBOUNDED || b == UNBOUNDED) ? UNBOUNDED : (a + b);
}

inline int
min(int a, int b)
{
  return a < b ? a : b;
}

inline int
max(int a, int b)
{
  return a > b ? a : b;
}

inline int
floorDivision(int dividend, int divisor)
{
  if (divisor > 0)
    {
      return (dividend >= 0) ? (dividend / divisor)
	: -((divisor - dividend - 1) / divisor);
    }
  else
    {
      Assert(divisor < 0, cerr << "zero divisor");
      return (dividend >= 0) ? -((dividend - divisor - 1) / (-divisor))
	: ((-dividend) / (-divisor));
    }
}

inline int
ceilingDivision(int dividend, int divisor)
{
  if (divisor > 0)
    {
      return (dividend >= 0) ? ((dividend + divisor - 1) / divisor)
	: -((-dividend) / divisor);
    }
  else
    {
      Assert(divisor < 0, cerr << "zero divisor");
      return (dividend >= 0) ? -(dividend / (-divisor))
	: (((-dividend) + (-divisor) - 1) / (-divisor));
    }
}

inline const char*
pluralize(int quantity)
{
  return (quantity == 1) ? "" : "s";
}

//
//	Branch free conditional assignments. These use bit twiddling rather
//	than branches and are intended for performance critical loops
//	where the branch would be unpredicatable. Executing a couple of extra
//	instructions is better than having a high rate of mispredicts on
//	modern superpipelined architectures.
//

inline void
setOnLs(int& d, int v, int t)
{
  //
  //	set d to v iff t < 0
  //
  d += (t >> (BITS_PER_INT - 1)) & (v - d);
}

inline void
setOnGeq(int& d, int v, int t)
{
  //
  //	set d to v iff t >= 0
  //
  d += (~(t >> (BITS_PER_INT - 1))) & (v - d);
}

const char* int64ToString(Int64 i, int base = 10);
Int64 stringToInt64(const char* s, bool& error, int base = 10);
bool looksLikeFloat(const char* s);
const char* doubleToString(double d);
double stringToDouble(const char* s, bool& error);
void correctEcvt(double d, int nrDigits, char buffer[], int& decPt, int& sign);

#endif
