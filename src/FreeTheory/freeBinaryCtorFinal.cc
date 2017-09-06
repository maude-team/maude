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
//	Implementation for class FreeBinaryCtorFinal.
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
#include "freeBinaryCtorFinal.hh"

void
FreeBinaryCtorFinal::execute(StackMachine* machine) const
{
  //
  //    Get the stack frame containing the pointer to us.
  //
  Frame* frame = machine->getTopFrame();
  //
  //    Get two arguments into local variables.
  //
  DagNode *a0 = frame->getSlot(argIndex);
  DagNode *a1 = frame->getSlot(argIndex + 1);
  //
  //    Now construct the node with its symbol and arguments.
  //
  FreeSymbol* s = symbol;
  DagNode* d = new FreeDagNode(s, a0, a1);
  d->setReduced();
  //
  //    Look up the sort for the new node.
  //
  int sortIndex = s->traverse(s->traverse(0, a0->getSortIndex()), a1->getSortIndex());
  //
  //	Fill out sort and return result.
  //
  d->setSortIndex(sortIndex);
  frame->returnValue(d);
  //
  //    Remove top frame and any other dead frames from the stack.
  //
  machine->popDeadFrames();
}
