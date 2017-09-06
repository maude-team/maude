//
//	64 bit arithmetic; since it's now practical to deal with quantities
//	of rewrites/matchers/unifiers etc that overflow 32 bits.
//
typedef long long int Int64;

#include <limits>

#ifndef INT64_MAX
#ifdef LLONG_MAX
#define INT64_MAX	LLONG_MAX
#else
#define INT64_MAX	(9223372036854775807LL)
#endif

#ifndef INT64_MIN
#ifdef LLONG_MIN
#define INT64_MIN	LLONG_MIN
#else
#define INT64_MIN	(-INT64_MAX-1LL)
#endif
#define INT64_MIN_STRING	"-9223372036854775808"
