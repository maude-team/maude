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
	applicationStrategy.cc \
	strategySequence.cc \
	iterationStrategy.cc \
	branchStrategy.cc \
	unionStrategy.cc \
	trivialSetGenerator.cc \
	sequenceSetGenerator.cc \
	iterationSetGenerator.cc \
	applicationSetGenerator.cc \
	branchSetGenerator.cc \
	unionSetGenerator.cc

noinst_HEADERS = \
	strategyLanguage.hh \
	strategyExpression.hh \
	trivialStrategy.hh \
	applicationStrategy.hh \
	strategySequence.hh \
	iterationStrategy.hh \
	branchStrategy.hh \
	unionStrategy.hh \
	setGenerator.hh \
	trivialSetGenerator.hh \
	sequenceSetGenerator.hh \
	iterationSetGenerator.hh \
	applicationSetGenerator.hh \
	branchSetGenerator.hh \
	unionSetGenerator.hh
