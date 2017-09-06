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

//
//	Implementation for class StackMachineRhsCompiler
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "symbol.hh"

//	core class definitions
#include "variableInfo.hh"
#include "returnInstruction.hh"
//#include "copyInstruction.hh"
#include "stackMachineRhsCompiler.hh"


void
StackMachineRhsCompiler::recordFunctionEval(Symbol* symbol, int destination, const Vector<int>& argumentSlots, bool needContiguous)
{
  int nrFunctionEvaluations = functionEvaluations.size();
  functionEvaluations.expandBy(1);
  FunctionEval& f = functionEvaluations[nrFunctionEvaluations];

  f.symbol = symbol;
  f.destination = destination;
  f.argumentSlots = argumentSlots;  // deep copy
  f.needContiguous = false /* HACK needContiguous */;
  //f.needContiguous = needContiguous;
  f.contiguousSlot = NONE;
}

Instruction*
StackMachineRhsCompiler::compileInstructionSequence(int& nrSlots)
{
  //
  //	Deal with degenerate case of bare variable.
  //
  FunctionEval& first = functionEvaluations[0];
  if (first.symbol == 0)
    {
      NatSet activeSlots;
      int source = first.argumentSlots[0];
      activeSlots.insert(source);
      Instruction* nextInstruction = new ReturnInstruction(source);
      nextInstruction->setActiveSlots(activeSlots);
      return nextInstruction;
    }
  //
  //	Determine index of defining evaluation for virtual slots and last using evaluation for all slots.
  //
  int nrFunctionEvaluations = functionEvaluations.size();
  for (int i = 0; i < nrFunctionEvaluations; ++i)
    {
      FunctionEval& f = functionEvaluations[i];
      int destination = f.destination;
      if (i != nrFunctionEvaluations - 1)
	{
	  Assert(destination != NONE, "nonfinal evalutation cannot have NONE as destination slot");
	  Assert(!VariableInfo::isReal(destination), "putting result in real slot");

	  VirtualSlot& v = virtualSlots[destination];
	  v.defined = i;
	  v.lastUsed = NONE;
	  v.realSlot = NONE;
	}
      FOR_EACH_CONST(j, Vector<int>, f.argumentSlots)
	{
	  int slot = *j;
	  if (VariableInfo::isReal(slot))
	    lastUsed[slot] = i;
	  else
	    {
	      if (virtualSlots.find(slot) == virtualSlots.end())
		{
		  VariableInfo variableInfo;
		  dump(cerr, variableInfo);
		  cerr << "virtual slot " << slot <<
		     " for argument " << (j - f.argumentSlots.begin()) <<
		     " under " << f.symbol << " is used before it is defined";
		  abort();
		}
	      Assert(virtualSlots.find(slot) != virtualSlots.end(), "virtual slot " << slot <<
		     " for argument " << (j - f.argumentSlots.begin()) <<
		     " under " << f.symbol << " is used before it is defined");
	      virtualSlots[slot].lastUsed = i;
	    }
	}
    }
  //
  //	Now go through evaluation arguments and assign force virtual slots where there are >= arguments and they need to be contiguous.
  //
  for (int i = 0; i < nrFunctionEvaluations; ++i)
    {
      FunctionEval& f = functionEvaluations[i];
      int nrArguments =  f.argumentSlots.size();
      if (f.needContiguous && nrArguments > 1)
	{
	  //
	  //	We look at arguments that have already been placed in real slots, either by matching or assignment of a real
	  //	slot to their virtual slot, and see if it is feasible to position the arguments align to this pairing and
	  //	if so, how many copies does it cost.
	  //
	  int bestForceIndex = NONE;
	  int bestRealSlot = NONE;
	  int bestNrCopies = UNBOUNDED;
	  for (int j = 0; j < nrArguments; ++j)
	    {
	      int slot = f.argumentSlots[j];
	      int source = VariableInfo::isReal(slot) ? slot : virtualSlots[slot].realSlot;
	      if (source != NONE)
		{
		  int nrCopies = feasibleAssignment(i, j, source);
		  if (nrCopies != NONE && nrCopies < bestNrCopies)
		    {
		      bestForceIndex = j;
		      bestRealSlot = source;
		      bestNrCopies = nrCopies;
		    }
		}
	    }
	  DebugAdvisory("symbol = " << f.symbol <<
			"\tbestForceIndex = " << bestForceIndex <<
			"\tbestRealSlot = " << bestRealSlot <<
			"\tbestNrCopies = " << bestNrCopies);

	  //cerr << f.symbol << "\tbestForceIndex = " << bestForceIndex << "\tbestNrCopies = " << bestNrCopies << endl;
	  if (bestForceIndex == NONE)
	    computeUnforcedAssignment(i);  // no arguments in real slots with feasible alignment
	  else
	    computeForcedAssignment(i, bestForceIndex, bestRealSlot);
	}
    }
  //
  //	Now we need to go through virtual slots and assign a real slot to any that haven't had an assignment.
  //
  for (int i = 0; i < nrFunctionEvaluations - 1; ++i)
    {
      FunctionEval& f = functionEvaluations[i];
      int destination = f.destination;
      VirtualSlot& v = virtualSlots[destination];
      if (v.realSlot == NONE)
	{
	  int realSlot = findRealSlot(i);
	  v.realSlot = realSlot;
	  lastUsed[realSlot] = v.lastUsed;
	}
    }
  //
  //	Now build instruction sequence in reverse.
  //
  NatSet activeSlots;
  Instruction* nextInstruction = 0;
  Vector<int> argumentSlots;
  for (int i = nrFunctionEvaluations - 1; i >= 0; --i)
    {
      FunctionEval& f = functionEvaluations[i];
      if (f.symbol == 0)
	{
	  int source = f.argumentSlots[0];
	  activeSlots.insert(source);
	  nextInstruction = new ReturnInstruction(source);
	  nextInstruction->setActiveSlots(activeSlots);
	}
      else
	{
	  int nrArgs = f.argumentSlots.size();
	  argumentSlots.resize(nrArgs);
	  if (f.contiguousSlot == NONE)
	    {
	      for (int j = 0; j < nrArgs; ++j)
		{
		  int slot = f.argumentSlots[j];
		  int source = VariableInfo::isReal(slot) ? slot : virtualSlots[slot].realSlot;
		  argumentSlots[j] = source;
		}
	    }
	  else
	    {
	      for (int j = 0; j < nrArgs; ++j)
		argumentSlots[j] = f.contiguousSlot + j;
	    }
	  int destination = virtualSlots[f.destination].realSlot;
	  //
	  //	If destination is beyond the known slots from matching and previous destinations slots, we need
	  //	to increase nrSlots.
	  //
	  if (destination >= nrSlots)
	    nrSlots = destination + 1;
	  
	  //
	  //	Since we are going to be defining the destination, the slot can't be active unless we need it
	  //	as an argument;
	  //
	  activeSlots.subtract(destination);
	  FOR_EACH_CONST(i, Vector<int>, argumentSlots)
	    activeSlots.insert(*i);
	    
	  nextInstruction = (nextInstruction == 0) ? 
	    f.symbol->generateFinalInstruction(argumentSlots) :
	    f.symbol->generateInstruction(destination, argumentSlots, nextInstruction);

	  if (nextInstruction == 0)
	    return 0;
	  nextInstruction->setActiveSlots(activeSlots);

	  int nrCopies = f.copies.size();
	  Assert(nrCopies == 0, "copies not supported");
	  /*
	  for (int j = nrCopies - 1; j >= 0; --j)
	    {
	      int slot = f.copies[j].source;
	      int source = VariableInfo::isReal(slot) ? slot : virtualSlots[slot].realSlot;
	      int destination = f.copies[j].destination;
	      activeSlots.subtract(destination);
	      activeSlots.insert(source);
	      nextInstruction = 0; new CopyInstruction(destination, source, nextInstruction);
	      nextInstruction->setActiveSlots(activeSlots);
	    }
	  */
      
	}

    }

  return nextInstruction;
}

int
StackMachineRhsCompiler::findRealSlot(int evalIndex)
{
  int i = 0;
  for (;; ++i)
    {
      IntMap::const_iterator j = lastUsed.find(i);
      if (j == lastUsed.end() || j->second <= evalIndex)
	break;
    }
  return i;
}

void
StackMachineRhsCompiler::computeForcedAssignment(int evalIndex, int forcedIndex, int realSlot)
{
  //
  //	We can avoid copies by using forcedIndex in situ at realSlot.
  //
  int baseSlot = realSlot - forcedIndex;
  Assert(baseSlot >= 0, "bad base slot; evalIndex: " << evalIndex <<
	 " forcedIndex: " << forcedIndex << 
	 " realSlot: " << realSlot);

  FunctionEval& f = functionEvaluations[evalIndex];
  int nrArguments =  f.argumentSlots.size();
  for (int i = 0; i < nrArguments; ++i)
    {
      if (i == forcedIndex)
	continue;  // argument is properly located
      int slot = f.argumentSlots[i];
      int source = VariableInfo::isReal(slot) ? slot : virtualSlots[slot].realSlot;
      int neededSlot = baseSlot + i;
      if (source == neededSlot)
	continue;  // argument is properly located

      int lastUserOfNeededSlot = NONE;
      if (lastUsed.find(neededSlot) != lastUsed.end())
	{
	  lastUserOfNeededSlot = lastUsed[neededSlot];
	  Assert(lastUserOfNeededSlot < evalIndex, "needed slot " << neededSlot <<
		 " used by " << lastUserOfNeededSlot <<
		 " but needed for " << evalIndex);
	}
      if (source == NONE)
	{
	  //
	  //	We can position source where we want.
	  //
	  if (lastUserOfNeededSlot == NONE || lastUserOfNeededSlot <= virtualSlots[slot].defined)
	    {
	      //
	      //	We can position it in the needed slot at no cost.
	      //	The last user of the virtual slot becomes the last user of the needed slot.
	      //
	      virtualSlots[slot].realSlot = neededSlot;
	      lastUsed[neededSlot] = virtualSlots[slot].lastUsed;
	      continue;
	    }
	  //
	  //	Has to go elsewhere and then get copied to needed slot before our evaluation.
	  //	Leave the decision on elsewhere until later.
	  //	We become the last user of the needed slot so that it can't be reused across us.
	  //
	  f.addCopy(slot, neededSlot);
	  lastUsed[neededSlot] = evalIndex;
	  continue;
	}
      //
      //	Souce is at a fixed position and not where we need it.
      //	We become the last user of the needed slot so that it can't be reused across us.
      //
      f.addCopy(source, neededSlot);
      lastUsed[neededSlot] = evalIndex;
    } 
  f.contiguousSlot = baseSlot;
}

bool
StackMachineRhsCompiler::isOK(int evalIndex, int baseSlot)
{
  //
  //	Determine if doing evaluation evalIndex, with arguments starting form baseSlot is OK or will is cause a clash on slots.
  //
  FunctionEval& f = functionEvaluations[evalIndex];
  int nrArguments =  f.argumentSlots.size();
  SlotSet tempMappedVirtualSlots;  // keep track of virtual slots that we've hypothetically mapped
  for (int i = 0; i < nrArguments; ++i)
    {
      int neededSlot = baseSlot + i;
      int lastUserOfNeededSlot = NONE;
      if (lastUsed.find(neededSlot) != lastUsed.end())
	lastUserOfNeededSlot = lastUsed[neededSlot];

      int slot = f.argumentSlots[i];
      int source = VariableInfo::isReal(slot) ? slot : virtualSlots[slot].realSlot;
      if (source == NONE && tempMappedVirtualSlots.find(slot) == tempMappedVirtualSlots.end())
	{
	  if (lastUserOfNeededSlot == NONE || lastUserOfNeededSlot <= virtualSlots[slot].defined)
	    tempMappedVirtualSlots.insert(slot);  // OK
	  else
	    return false;  // can't assign virtual slot to needed slot because needed slot is in use
	}
      else
	{
	  if (lastUserOfNeededSlot < evalIndex)
	    ;  // OK
	  else
	    return false;  // can't copy to needed slot because needed slot is in use
	}
    }
  return true;
}

void
StackMachineRhsCompiler::computeUnforcedAssignment(int evalIndex)
{
  //
  //	No copies can be avoided using a previously determined real slot. Each argument
  //	needs to be either assigned a slot or copied to a slot to obtain them in a contiguous
  //	sequence.
  //
  int baseSlot = 0;
  while (!isOK(evalIndex, baseSlot))
    ++baseSlot;

  FunctionEval& f = functionEvaluations[evalIndex];
  int nrArguments =  f.argumentSlots.size();
  for (int i = 0; i < nrArguments; ++i)
    {
      int neededSlot = baseSlot + i;

      int slot = f.argumentSlots[i];
      int source = VariableInfo::isReal(slot) ? slot : virtualSlots[slot].realSlot;
      if (source == NONE)
	{
	  virtualSlots[slot].realSlot = neededSlot;
	  lastUsed[neededSlot] = virtualSlots[slot].lastUsed;
	}
      else
	{
	  f.addCopy(source, neededSlot);
	  lastUsed[neededSlot] = evalIndex;
	}
    }
  f.contiguousSlot = baseSlot;
}

int
StackMachineRhsCompiler::feasibleAssignment(int evalIndex, int forcedIndex, int realSlot)
{
  //
  //	Find base slot and check that it is is non-negative.
  //
  int baseSlot = realSlot - forcedIndex;
  if (baseSlot < 0)
    return NONE;

  int nrCopiesNeeded = 0;
  SlotSet tempMappedVirtualSlots;  // keep track of virtual slots that we've hypothetically mapped
  FunctionEval& f = functionEvaluations[evalIndex];
  int nrArguments =  f.argumentSlots.size();
  //
  //	Check arguments. If we get alignment, it's a fail before the forced index since we will
  //	have already checked this alignment. After the index it is a freebie.
  //	We also check that needed slot is available and if the source is an unmapped virtual slot
  //	we try to map it to avoid the copy.
  //
  for (int i = 0; i < nrArguments; ++i)
    {
      if (i == forcedIndex)
	continue;  // this one is free

      int slot = f.argumentSlots[i];
      int source = VariableInfo::isReal(slot) ? slot : virtualSlots[slot].realSlot;
      int neededSlot = baseSlot + i;
      if (source == neededSlot)
	{
	  if (i < forcedIndex)
	    return NONE;  // must have considered this alignment before
	  else
	    continue;  // freebie
	}

      int lastUserOfNeededSlot = NONE;
      if (lastUsed.find(neededSlot) != lastUsed.end())
	{
	  //
	  //	The needed slot has been used; need to make sure we don't conflict.
	  //
	  lastUserOfNeededSlot = lastUsed[neededSlot];
	  if (lastUserOfNeededSlot >= evalIndex)
	    return NONE;
	}
	
      if (source == NONE && tempMappedVirtualSlots.find(slot) == tempMappedVirtualSlots.end())
	{
	  //
	  //	The virtual slot holding our argument is unmapped; maybe we can map it so as to avoid the copy.
	  //
	  if (lastUserOfNeededSlot == NONE || lastUserOfNeededSlot <= virtualSlots[slot].defined)
	    {
	      //
	      //	Yes! we can map slot to neededSlot in the evalutation that produced slot; we must make
	      //	sure we don't map it again in the case that it appears as an argument more than once.
	      //
	      tempMappedVirtualSlots.insert(slot);
	      continue;  // win
	    }
	}
      ++nrCopiesNeeded;  // normal case is we need to copy the argument to the neededSlot
    }
  return nrCopiesNeeded;
}

void
StackMachineRhsCompiler::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{StackMachineRhsCompiler}\n";
  FOR_EACH_CONST(i, Vector<FunctionEval>, functionEvaluations)
    {
      FOR_EACH_CONST(j, Vector<Copy>, i->copies)
	s << Indent(indentLevel + 1) << "copy " << j->source << " to " << j->destination << endl;
      s << Indent(indentLevel + 1);
      if (i->symbol == 0)
	s << "(return)\t";
      else
	s << i->symbol << "\t";
      s << "contiguousSlot = " << i->contiguousSlot << "\t";
      FOR_EACH_CONST(k, Vector<int>, i->argumentSlots)
	s << *k << ' ';
      s << "\tdest: " << i->destination << "\tcontig: " << i->needContiguous << endl;
    }

  int nrEvaluations = functionEvaluations.size();
  for (int i = 0; i < nrEvaluations; ++i)
    {
      FunctionEval& f = functionEvaluations[i];
      FOR_EACH_CONST(j, Vector<Copy>, f.copies)
	s << Indent(indentLevel + 1) << j->destination << " <- " << j->source << endl;
      s << Indent(indentLevel + 1);
      if (i == nrEvaluations - 1)
	s << "return ";
      else
	s << virtualSlots[f.destination].realSlot << " <- ";
      if (f.symbol == 0)
	s << f.argumentSlots[0];
      else
	{
	  s << f.symbol;
	  int nrArgs = f.argumentSlots.size();
	  if (nrArgs > 0)
	    {
	      s << '(';
	      if (f.contiguousSlot == NONE)
		{
		  for (int j = 0; j < nrArgs; ++j)
		    {
		      int slot = f.argumentSlots[j];
		      int source = VariableInfo::isReal(slot) ? slot : virtualSlots[slot].realSlot;
		      s << source;
		      if (j != nrArgs - 1)
			s << ", ";
		    }
		}
	      else
		{
		  for (int j = 0; j < nrArgs; ++j)
		    {
		      int source = f.contiguousSlot + j;
		      s << source;
		      if (j != nrArgs - 1)
			s << ", ";
		    }
		}
	      s << ')';
	    }
	}
      s << endl;
    }

  FOR_EACH_CONST(j, VirtualSlotMap, virtualSlots)
    {
      s << Indent(indentLevel + 1) << "virtual slot: " << j->first <<
	"\tdefined: " << j->second.defined <<
	"\tlastUsed: " << j->second.lastUsed <<
	"\trealSlot: " << j->second.realSlot << endl;
    }

  FOR_EACH_CONST(k, IntMap, lastUsed)
    {
      s << Indent(indentLevel + 1) << "real slot: " << k->first <<
	"\tlastUsed: " << k->second << endl;
    }

  s << Indent(indentLevel) << "End{StackMachineRhsCompiler}\n";
}
