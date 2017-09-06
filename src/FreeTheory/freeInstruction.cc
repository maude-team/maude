/*

    This file is part of the Maude 2 interpreter.

    Copyright 2013 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//	Implementation for class FreeInstruction.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "freeTheory.hh"

//	interface class definitions
#include "symbol.hh"

//      core class definitions
#include "frame.hh"
#include "stackMachine.hh"
#include "returnInstruction.hh"

//	free theory class definitions
#include "freeSymbol.hh"
#include "freeDagNode.hh"
#include "freeNet.hh"
#include "freeNetExec.hh"
#include "freeRemainder.hh"
#include "freeNullarySymbol.hh"

#include "freeInstruction.hh"
#include "freeFastInstruction.hh"

FreeInstruction::FreeInstruction(FreeSymbol* symbol, int destinationIndex, Instruction* nextInstruction)
  : NonFinalExtor(destinationIndex, nextInstruction),
    symbol(symbol)
{
}	       

//
//	Turn repeated blocks of code into macros to allow for easy modification
//

//
//	Need to place next instruction in frame, and frame in stack machine before
//	we can safely do a garbage collect.
//
#define OK_TO_COLLECT_GARBAGE()			\
  {						\
    if (MemoryCell::wantToCollectGarbage())	\
      {						\
	frame->setNextInstruction(n);		\
	machine->setTopFrame(frame);		\
	MemoryCell::collectGarbage();		\
      }						\
  }

//
//	Next instruction is already in frame; need to palce frame in stack machine before
//	we can safely do a garbage collect.
//
#define OK_TO_COLLECT_GARBAGE2()		\
  {						\
    if (MemoryCell::wantToCollectGarbage())	\
      {						\
	machine->setTopFrame(frame);		\
	MemoryCell::collectGarbage();		\
      }						\
  }

#define WIN()								\
  {									\
    frame->setNextInstruction(i->getNextInstruction());			\
    nextFrame->setReturnAddress(frame, i->getDestinationIndex());	\
    n = r->getFirstInstruction();					\
    nextFrame->setAncestorWithValidNextInstruction(frame);		\
    frame = nextFrame;							\
    machine->incrementEqCount();					\
    JUMP();								\
  }

#define NEXT()						\
  {							\
    frame->setSlot(i->getDestinationIndex(), d);	\
    n = i->getNextInstruction();			\
    OK_TO_COLLECT_GARBAGE();				\
    JUMP();						\
  }

#define NEXT_NO_GC()					\
  {							\
    frame->setSlot(i->getDestinationIndex(), d);	\
    n = i->getNextInstruction();			\
    JUMP();						\
  }

#define TRY_REMAINDERS()						\
  {									\
    if (index >= 0)							\
      {									\
	Frame* nextFrame = i->fastPushFrame(frame);			\
	DagNode** binding = nextFrame->getArgumentListPtr();		\
	Vector<FreeRemainder*>::const_iterator p = net.fastApplicable[index].begin(); \
	const FreeRemainder* r = *p;					\
	do								\
	  {								\
	    if (r->fastCheckAndBind(binding, net.stack))		\
	      WIN();							\
	  }								\
	while ((r = *(++p)) != 0);					\
      }									\
  }

#define END_FRAME()				\
  {						\
    frame->returnValue(d);			\
    frame = frame->fastPop();			\
    n = frame->getNextInstruction();		\
    OK_TO_COLLECT_GARBAGE2();			\
    JUMP();					\
  }

#define END_FRAME_NO_GC()			\
  {						\
    frame->returnValue(d);			\
    frame = frame->fastPop();			\
    n = frame->getNextInstruction();		\
    JUMP();					\
  }

#define NULLARY_CTOR()							\
  {									\
    if (d == 0)								\
      {									\
	d = new(NONE) FreeDagNode(s, NONE /* HACK */);			\
	s->setNode(d);							\
      }									\
  }

#define TRY_REMAINDERS_FINAL()						\
  {									\
    FREE_NET& net = i->symbol->GET_NET();				\
    long index = net.findRemainderListIndex(localArgList);		\
    if (index >= 0)							\
      {									\
	DagNode** binding = frame->getArgumentListPtr();		\
	Vector<FreeRemainder*>::const_iterator p = net.fastApplicable[index].begin(); \
	const FreeRemainder* r = *p;					\
	do								\
	  {								\
	    if (r->fastCheckAndBind(binding, net.stack))		\
	      {								\
		n = r->getFirstInstruction();				\
		machine->incrementEqCount();				\
		JUMP();							\
	      }								\
	  }								\
	while ((r = *(++p)) != 0);					\
      }									\
  }

#define JUMP() \
  goto *(jumpTable[n->getOpCode()]);

void
FreeInstruction::execute(StackMachine* machine) const
{
  static void* jumpTable[] =
    {
      &&nullaryCtor, &&unaryCtor, &&binaryCtor, &&ternaryCtor,
      &&nullaryExtor, &&unaryExtor, &&binaryExtor, &&ternaryExtor,
      &&nullaryCtorFinal, &&unaryCtorFinal, &&binaryCtorFinal, &&ternaryCtorFinal,
      &&nullaryExtorFinal, &&unaryExtorFinal, &&binaryExtorFinal, &&ternaryExtorFinal,
      
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,

      &&returnInstruction, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,

      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,

      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
      &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
    };

  DagNode* localArgList[3];
  Frame* frame = machine->getTopFrame();
  const Instruction* n = this;
  JUMP();

 nullaryCtor:
  {
    const FreeInstruction* i = static_cast<const FreeInstruction*>(n);
    FreeNullarySymbol* s = static_cast<FreeNullarySymbol*>(i->symbol);
    DagNode* d = s->getNode();
    NULLARY_CTOR();
    NEXT_NO_GC();
  }

 unaryCtor:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    DagNode* d = new(NONE) FreeDagNode(i->symbol,
				       frame->getSlot(i->argIndex0));
    NEXT();
  }

 binaryCtor:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    DagNode* d = new(NONE) FreeDagNode(i->symbol,
				       frame->getSlot(i->argIndex0),
				       frame->getSlot(i->argIndex1));
    NEXT();
  }

 ternaryCtor:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    DagNode* d = new(NONE) FreeDagNode(i->symbol,
				       frame->getSlot(i->argIndex0),
				       frame->getSlot(i->argIndex1),
				       frame->getSlot(i->argIndex2));
    NEXT();
  }

 nullaryExtor:
  {
    const FreeInstruction* i = static_cast<const FreeInstruction*>(n);
    FREE_NET& net = i->symbol->GET_NET();
    Frame* nextFrame = i->fastPushFrame(frame);
    const FreeRemainder* r = net.fastApplicable[0][0];
    WIN();
  }

 unaryExtor:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    FREE_NET& net = i->symbol->GET_NET();
    long index = net.findRemainderListIndex(frame->getArgumentListPtr() + i->argIndex0);
    TRY_REMAINDERS();

    DagNode* d = new(NONE) FreeDagNode(i->symbol,
				       frame->getSlot(i->argIndex0));
    NEXT();
  }

 binaryExtor:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    localArgList[0] = frame->getSlot(i->argIndex0);
    localArgList[1] = frame->getSlot(i->argIndex1);

    FREE_NET& net = i->symbol->GET_NET();
    long index = net.findRemainderListIndex(localArgList);
    TRY_REMAINDERS();
    DagNode* d = new(NONE) FreeDagNode(i->symbol, localArgList[0], localArgList[1]);
    NEXT();
  }

 ternaryExtor:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    localArgList[0] = frame->getSlot(i->argIndex0);
    localArgList[1] = frame->getSlot(i->argIndex1);
    localArgList[2] = frame->getSlot(i->argIndex2);

    FREE_NET& net = i->symbol->GET_NET();
    long index = net.findRemainderListIndex(localArgList);
    TRY_REMAINDERS();
    DagNode* d = new(NONE) FreeDagNode(i->symbol, localArgList[0], localArgList[1], localArgList[2]);
    NEXT();
  }

 nullaryCtorFinal:
  {
    const FreeInstruction* i = static_cast<const FreeInstruction*>(n);
    FreeNullarySymbol* s = static_cast<FreeNullarySymbol*>(i->symbol);
    DagNode* d = s->getNode();
    NULLARY_CTOR();
    END_FRAME_NO_GC();
  }

 unaryCtorFinal:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    FreeSymbol* s = i->symbol;
    DagNode* d = new(NONE) FreeDagNode(s,
				       frame->getSlot(i->argIndex0));
    END_FRAME();
  }

 binaryCtorFinal:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    FreeSymbol* s = i->symbol;
    DagNode* d = new(NONE) FreeDagNode(s,
				       frame->getSlot(i->argIndex0),
				       frame->getSlot(i->argIndex1));
    END_FRAME();
  }

 ternaryCtorFinal:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    FreeSymbol* s = i->symbol;
    DagNode* d = new(NONE) FreeDagNode(s,
				       frame->getSlot(i->argIndex0),
				       frame->getSlot(i->argIndex1),
				       frame->getSlot(i->argIndex2));
    END_FRAME();
  }

 nullaryExtorFinal:
  {
    const FreeInstruction* i = static_cast<const FreeInstruction*>(n);
    FREE_NET& net = i->symbol->GET_NET();
    const FreeRemainder* r = net.fastApplicable[0][0];
    n = r->getFirstInstruction();
    machine->incrementEqCount();
    JUMP();
  }

 unaryExtorFinal:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    localArgList[0] = frame->getSlot(i->argIndex0);
    TRY_REMAINDERS_FINAL();
    DagNode* d = new(NONE) FreeDagNode(i->symbol, localArgList[0]);
    END_FRAME();
  }

 binaryExtorFinal:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    localArgList[0] = frame->getSlot(i->argIndex0);
    localArgList[1] = frame->getSlot(i->argIndex1);
    TRY_REMAINDERS_FINAL();
    DagNode* d = new(NONE) FreeDagNode(i->symbol, localArgList[0], localArgList[1]);
    END_FRAME();
  }

 ternaryExtorFinal:
  {
    const FreeFastInstruction* i = static_cast<const FreeFastInstruction*>(n);
    localArgList[0] = frame->getSlot(i->argIndex0);
    localArgList[1] = frame->getSlot(i->argIndex1);
    localArgList[2] = frame->getSlot(i->argIndex2);
    TRY_REMAINDERS_FINAL();
    DagNode* d = new(NONE) FreeDagNode(i->symbol, localArgList[0], localArgList[1], localArgList[2]);
    END_FRAME();
  }

 returnInstruction:
  {
    const ReturnInstruction* i = static_cast<const ReturnInstruction*>(n);
    DagNode* d = frame->getSlot(i->getReturnSlot());
    END_FRAME_NO_GC();
  }

 other:
  {
    //cout << "other " << endl;
    //
    //	Save next instruction in current frame.
    //
    frame->setNextInstruction(n);
    //
    //	Update stack machine with current frame.
    //
    machine->setTopFrame(frame);
    return;
  }
}

#ifdef DUMP

void
FreeInstruction::dump(ostream& s, int indentLevel)
{
  s << Indent(indentLevel) << "FreeInstruction " << getOpCode() << " : "<< symbol;
  int nrArgs = symbol->arity();
  if (nrArgs > 0)
    {
      s << "(";
      /*
      for (int i = 0; i < nrArgs; ++i)
	s << argIndex[i] << ((i == nrArgs - 1) ? ")" : ", ");
      */
    }
  if (getNextInstruction() != 0)
    s << " -> " << getDestinationIndex();
  s << endl;
}

#endif
