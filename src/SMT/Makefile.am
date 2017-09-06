noinst_LIBRARIES = libSMT.a

libSMT_a_CPPFLAGS = \
	-I$(top_srcdir)/src/Utility \
	-I$(top_srcdir)/src/Interface \
	-I$(top_srcdir)/src/Core \
	-I$(top_srcdir)/src/Variable \
	-I$(top_srcdir)/src/FullCompiler \
	-I$(top_srcdir)/src/NA_Theory \
	-I$(top_srcdir)/src/FreeTheory \
	-I$(top_srcdir)/src/BuiltIn

libSMT_a_SOURCES = \
	SMT_Symbol.cc \
	SMT_NumberSymbol.cc \
	SMT_NumberDagNode.cc \
	SMT_NumberTerm.cc

EXTRA_DIST =

noinst_HEADERS = \
	SMT.hh \
	SMT_Base.hh \
	SMT_Symbol.hh \
	SMT_NumberSymbol.hh \
	SMT_NumberDagNode.hh \
	SMT_NumberTerm.hh
