## MAUDE + HOOKS (LTLR and LMC)

This branch contains the original Maude sources with the hooks for the Maude LTLR and LMC model checkers,
in addition to the Termination Checker hooks for Maude Formal Environment.

### Configuration

The LTLR and LMC model checkers need c++11. For gcc 4.8, CXXFLAGS should include the option '-std=c++11'.
For example, the binary can be configured in MacOSX as follows, where the MacPorts installed:

~~~
./configure \
CC=/opt/local/bin/gcc-mp-4.8 \
CXX=/opt/local/bin/g++-mp-4.8 \
FLEX=/opt/local/bin/flex \
BISON=/opt/local/bin/bison \
CFLAGS="-Wall -Wno-deprecated -O2 -static-libstdc++ -static-libgcc -fno-crossjumping -fno-stack-protector -fstrict-aliasing -mmacosx-version-min=10.5 -finline-limit=10000" \
CXXFLAGS="-std=c++11 -Wall -Wno-deprecated -O2 -static-libstdc++ -static-libgcc -fno-crossjumping -fno-stack-protector -fstrict-aliasing -mmacosx-version-min=10.5 -finline-limit=10000" \
CPPFLAGS="-I/opt/local/include" \
LDFLAGS="-L/opt/local/lib" \
BUDDY_LIB="/opt/local/lib/libbdd.a" \
TECLA_LIBS="/opt/local/lib/libtecla.a /usr/lib/libncurses.dylib" \
LIBSIGSEGV_LIB="/opt/local/lib/libsigsegv.a" \
GMP_LIBS="/opt/local/lib/libgmp.a /opt/local/lib/libgmpxx.a" 
~~~

### Changes

The source files for the model checker extensions are included in the directory src/ModelChecker.
As usual, the following files are modified to incorporate the new hooks:

~~~
./configure.ac
./src/Makefile.am
./src/Main/Makefile.am
./src/Mixfix/Makefile.am
./src/Mixfix/entry.cc
./src/Mixfix/mixfixModule.cc
./src/Mixfix/specialSymbolTypes.cc
./src/Mixfix/symbolType.hh
./src/Mixfix/banner.cc
~~~

In addition, for C++11 and Mac OS X, the following files are changed:

~~~
./src/BuiltIn/terminationCheckerSymbol.hh
@@ -42,6 +42,11 @@
 #include "term.hh"
 #include "cachedDag.hh"
 
+// fix for mac os x
+#if defined(DARWIN)
+#include <signal.h>
+#endif
+
 #include <vector>
 #include <map>
 using namespace std;

./src/Utility/macros.cc
@@ -180,7 +180,7 @@ doubleToString(double d)
 {
   if (!finite(d))
     {
-      if (isnan(d))
+      if (std::isnan(d))
    return "NaN";
       else
    return (d < 0) ? "-Infinity" : "Infinity";

./src/Utility/mathStuff.hh
@@ -34,7 +34,7 @@
 //
 // Darwin fix from Fabricio Chalub <fc@gnu.org>
 //
-#if defined(DARWIN) && !defined(isnan)
+#if defined(DARWIN) && !defined(isnan) && !defined(__GXX_EXPERIMENTAL_CXX0X__)
 extern "C" int isnan(double);
 #endif
 #endif
~~~
