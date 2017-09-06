/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2013 SRI International, Menlo Park, CA 94025, USA.

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
#include <map>
#include <set>

//
//	Class for compiling rhs side of an equation to a sequence of stack machine instructions.
//
#ifndef _stackMachineRhsCompiler_hh_
#define _stackMachineRhsCompiler_hh_

class StackMachineRhsCompiler
{
public:
  void recordFunctionEval(Symbol* symbol, int destination, const Vector<int>& argumentSlots, bool needContiguous);
  Instruction* compileInstructionSequence(int& nrSlots);

  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel = 0);

private:
  struct Copy
  {
    int source;  // might be virtual
    int destination;  // must be real
  };

  struct FunctionEval
  {
    void addCopy(int source, int destination);

    Symbol* symbol;
    int destination;
    Vector<int> argumentSlots;
    bool needContiguous;
    int contiguousSlot;
    //
    //	Compile time stuff.
    //
    Vector<Copy> copies;
  };

  struct VirtualSlot
  {
    int defined;
    int lastUsed;
    int realSlot;
  };

  //
  //	Map virtual slot indicies to information.
  //
  typedef map<int, VirtualSlot> VirtualSlotMap;

  typedef map<int, int> IntMap;
  typedef set<int> SlotSet;

  int feasibleAssignment(int evalIndex, int forcedIndex, int realSlot);
  void computeUnforcedAssignment(int evalIndex);
  void computeForcedAssignment(int evalIndex, int forcedIndex, int realSlot);
  bool isOK(int evalIndex, int baseSlot);
  int findRealSlot(int evalIndex);

  Vector<FunctionEval> functionEvaluations;
  VirtualSlotMap virtualSlots;
  IntMap lastUsed;  // for real slots
};

inline void
StackMachineRhsCompiler::FunctionEval::addCopy(int source, int destination)
{
  int nrCopies = copies.size();
  copies.resize(nrCopies + 1);
  Copy& copy = copies[nrCopies];
  copy.source = source;
  copy.destination = destination;
}

#endif
