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
//	Implementation for class FreeBinaryCtor.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

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

//	free theory class definitions
#include "freeSymbol.hh"
#include "freeDagNode.hh"
#include "freeBinaryFastExtor.hh"
#include "freeNet.hh"
#include "freeNetExec.hh"
#include "freeRemainder.hh"

#define FRAME_SIZE_HACK 50

void
FreeBinaryFastExtor::execute(StackMachine* machine) const
{
  //
  //    Get the stack frame containing the pointer to us.
  //
  Frame* frame = machine->getTopFrame();
  long index = net->findRemainderListIndex(frame->getArgumentListPtr() + argIndex);
  if (index >= 0)
    {
      Frame* nextFrame = machine->newFrame(FRAME_SIZE_HACK);
      DagNode** binding = nextFrame->getArgumentListPtr();

      Vector<FreeRemainder*>::const_iterator p = net->fastApplicable[index].begin();
      const FreeRemainder* r = *p;
      do
	{
	  if (r->fastCheckAndBind(binding, net->stack))
	    {
	      //
	      //	Successful match. We complete the rewrite by:
	      //	(1) recording the old frame pointer in the new frame so we can pop to it;
	      //	(2) recording the start of the rhs instruction sequence in the new frame;
	      //	(3) recording the return address in the new frame;
	      //	(4) moving the instruction pointer in the old frame forwards.
	      //	(5) incrementing the rewrite count.
	      //
	      nextFrame->setAncestorWithValidNextInstruction(frame);
	      nextFrame->setReturnAddress(frame, destIndex);
	      nextFrame->setNextInstruction(r->getFirstInstruction());
	      frame->setNextInstruction(nextInstruction);
	      machine->incrementEqCount();
	      return;
	    }
	}
      while ((r = *(++p)) != 0);
      //
      //	Couldn't finish matching any equation; restore stack to where we were.
      //
      machine->popToFrame(frame);
    }
  //
  //	Failed to rewrite - construct the reduced node as if we were a ctor instruction
  //

  //
  //    Get two arguments into local variables.
  //
  DagNode *a0 = frame->getSlot(argIndex);
  DagNode *a1 = frame->getSlot(argIndex + 1);
  //
  //    Now construct the node with its symbol and arguments.
  //    into stack frame.
  //
  FreeSymbol* s = symbol;
  DagNode* d = new FreeDagNode(s, a0, a1);
  d->setReduced();
  //
  //    Look up the sort for the new node.
  //
  int sortIndex = s->traverse(s->traverse(0, a0->getSortIndex()), a1->getSortIndex());
  //
  //	Preload destination index and next instruction pointer.
  //
  int di = destIndex;
  Instruction* ni = nextInstruction;
  //
  //	Fill out sort and store result in destination slot.
  //
  d->setSortIndex(sortIndex);
  frame->setSlot(di, d);
  //
  //    Move instruction pointer to next instruction in our sequence.
  //
  frame->setNextInstruction(ni);
}
