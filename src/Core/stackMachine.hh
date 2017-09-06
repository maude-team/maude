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
//      Class for excution frames on the stack machine.
//
#ifndef _stackMachine_hh_
#define _stackMachine_hh_
#include "frame.hh"

class StackMachine
{
  NO_COPYING(StackMachine);

public:
  StackMachine();
  ~StackMachine();

  Frame* getTopFrame() const;
  Frame* newFrame(int nrSlots);
  void popDeadFrames();
  //
  //	To quit the top frame when it is not yet complete.
  //
  void popToFrame(Frame* frame);
  
  void execute();
  void incrementEqCount();

private:
  Frame* topFrame;
  char* memoryBase;

  Int64 rewriteCount;
};

inline Frame*
StackMachine::getTopFrame() const
{
  return topFrame;
}

inline Frame*
StackMachine::newFrame(int nrSlots)
{
  //
  //	Frames can't have ctors or dtors.
  //
  char* m = reinterpret_cast<char*>(topFrame);
  topFrame = reinterpret_cast<Frame*>(m - (sizeof(Frame) + sizeof(DagNode*) * nrSlots));
  return topFrame;
}

inline void
StackMachine::popDeadFrames()
{
  topFrame = topFrame->getAncestorWithValidNextInstruction();
}

inline void
StackMachine::popToFrame(Frame* frame)
{
  topFrame = frame;
}

inline void
StackMachine::incrementEqCount()
{
  ++rewriteCount;
}

#endif
