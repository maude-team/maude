ROOT_DIR := ..

include $(ROOT_DIR)/MakeOptions

MODULES =	AU_Symbol.o \
		AU_DagNode.o \
		AU_Term.o \
		AU_DagArgumentIterator.o \
		AU_ExtensionInfo.o \
		AU_RhsAutomaton.o \
		AU_LhsAutomaton.o \
		AU_ArgumentIterator.o \
		AU_Layer.o \
		AU_Subproblem.o \

IFLAGS =        -I$(ROOT_DIR)/Core \
                -I$(ROOT_DIR)/Interface \
		-I$(ROOT_DIR)/AU_Theory \
		-I$(ROOT_DIR)/Utility \
		-I$(ROOT_DIR)/Variable \
		-I$(ROOT_DIR)/FullCompiler

CXXFLAGS =      $(DFLAGS) $(IFLAGS)

libAU_Theory.a : $(MODULES)
	$(AR) $(ARFLAGS) libAU_Theory.a $(MODULES)

AU_DagNode.o : AU_DagOperations.cc

AU_Term.o : AU_LhsCompiler.cc

AU_LhsAutomaton.o : AU_Matcher.cc AU_CollapseMatcher.cc AU_FullMatcher.cc AU_GreedyMatcher.cc

clean:
	rm *.o *.a
