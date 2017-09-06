ROOT_DIR := ..

include $(ROOT_DIR)/MakeOptions

MODULES =	macros.o \
		preVector.o \
		intSet.o \
		pointerSet.o \
		stringTable.o \
		graph.o \
		digraph.o \
		unionFind.o \
		diophantineSystem.o \
		natSet.o \
		pointerMap.o \
		sequencePartition.o \
		indent.o \
		binBuf.o \
		decBuf.o \
		bddUser.o \
		tty.o \
		bdd.o \
		timer.o

IFLAGS =	-I$(GMP_INCLUDE) \
		-I$(ROOT_DIR)/Utility

CXXFLAGS =	$(DFLAGS) $(IFLAGS)


libutility.a : $(MODULES)
	$(AR) $(ARFLAGS) libutility.a $(MODULES)

nsTest: nsTest.o libutility.a
	$(CXX) $(DFLAGS) $(LFLAGS) nsTest.o libutility.a -o nsTest

vectorTest: vectorTest.o libutility.a
	$(CXX) $(DFLAGS) $(LFLAGS) vectorTest.o libutility.a -o vectorTest

clean:
	rm *.o *.a
