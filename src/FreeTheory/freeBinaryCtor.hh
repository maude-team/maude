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
//      Stack machine instruction for a free binary symbol with no equations that is not
//	the final instruction for a rhs.
//
#ifndef _freeBinaryCtor_hh_
#define _freeBinaryCtor_hh_
#include "instruction.hh"

class FreeBinaryCtor : public Instruction
{
  NO_COPYING(FreeBinaryCtor);

public:
  void execute(StackMachine* machine) const;

private:
  FreeSymbol* symbol;  // our symbol
  //
  //	Our arguments are in consecutive slots in the top frame, starting from this index.
  //
  int argIndex;
  //
  //	Slot to write our result to.
  //
  int destIndex;
  //
  //	Next instruction in our rhs sequence.
  //
  Instruction* nextInstruction;  // next instruction in the sequence
};

#endif
