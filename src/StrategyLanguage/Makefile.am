noinst_LIBRARIES = libstrategyLanguage.a

libstrategyLanguage_a_CPPFLAGS = \
	-I$(top_srcdir)/src/Utility \
	-I$(top_srcdir)/src/Interface \
	-I$(top_srcdir)/src/Variable \
	-I$(top_srcdir)/src/Core \
	-I$(top_srcdir)/src/Higher \
	-I$(top_srcdir)/src/FullCompiler

libstrategyLanguage_a_SOURCES = \
	trivialStrategy.cc \
	trivialSetGenerator.cc \
	applicationStrategy.cc \
	applicationSetGenerator.cc \
	concatenationStrategy.cc \
	concatenationSetGenerator.cc \
	iterationStrategy.cc \
	iterationSetGenerator.cc \
	branchStrategy.cc \
	branchSetGenerator.cc \
	unionStrategy.cc \
	unionSetGenerator.cc \
	unaryStrategy.cc \
	unarySetGenerator.cc \
	stateCache.cc

noinst_HEADERS = \
	strategyLanguage.hh \
	strategyExpression.hh \
	setGenerator.hh \
	trivialStrategy.hh \
	trivialSetGenerator.hh \
	applicationStrategy.hh \
	applicationSetGenerator.hh \
	concatenationStrategy.hh \
	concatenationSetGenerator.hh \
	iterationStrategy.hh \
	iterationSetGenerator.hh \
	branchStrategy.hh \
	branchSetGenerator.hh \
	unionStrategy.hh \
	unionSetGenerator.hh \
	unaryStrategy.hh \
	unarySetGenerator.hh \
	stateCache.hh
