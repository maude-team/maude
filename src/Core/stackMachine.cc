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
//      Implementation for class StackMachine.
//

//	utility stuff
#include "macros.hh"
//#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	core declarations
#include "stackMachine.hh"
#include "instruction.hh"

#define STACK_SIZE 1000000

StackMachine::StackMachine()
{
  memoryBase = static_cast<char*>(operator new[](STACK_SIZE));
  //
  //	The stack grows downwards to smaller addresses.
  //
  topFrame = reinterpret_cast<Frame*>(memoryBase + STACK_SIZE);

  rewriteCount = 0;
}

StackMachine::~StackMachine()
{
  delete[] memoryBase;
}

void
StackMachine::execute()
{
  //
  //	Need to figure out termination condition for when last frame is pop'd
  //
  for(;;)
    topFrame->getNextInstruction()->execute(this);
}
