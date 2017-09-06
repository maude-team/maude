//
//	Implementation for class FreeNet.
//
#ifdef __GNUG__
#pragma implementation "freeNet.hh"
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "graph.hh"
#include "pointerSet.hh"
#include "natSet.hh"
#include "indent.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "fullCompiler.hh"
#include "freeTheory.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"
#include "lhsAutomaton.hh"
#include "rhsAutomaton.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "equation.hh"

//	full compiler class definitions
#include "compilationContext.hh"

//	variable class definitions
#include "variableTerm.hh"

//	free theory class definitions
#include "freeNet.hh"
#include "freeSymbol.hh"
#include "freeDagNode.hh"
#include "freeOccurrence.hh"
#include "freeLhsAutomaton.hh"
#include "freeRhsAutomaton.hh"
#include "freeTerm.hh"
#include "freeRemainder.hh"

#include "freeNetExec.cc"

FreeNet::~FreeNet()
{
  int nrRemainders = remainders.length();
  for (int i = 0; i < nrRemainders; i++)
    delete remainders[i];
}

int
FreeNet::allocateNode(int nrMatchArcs)
{
  int len = net.length();
  net.resize(len + nrMatchArcs);
  return len;
}

void
FreeNet::fillOutNode(int nodeNr,
		     int position,
		     int argIndex,
		     const Vector<Symbol*>& symbols,
		     const Vector<int>& targets,
		     const Vector<int>& slots,
		     int neqTarget)
{
  int nrSymbols = symbols.length();
  Vector<Triple> triples(nrSymbols);
  for (int i = 0; i < nrSymbols; i++)
    {
      Assert(symbols[i] != 0, cerr << "null symbol");
      triples[i].symbol = symbols[i];
      triples[i].slot = slots[i];
      triples[i].subtree = targets[i];
    }
  sort(triples.begin(), triples.end(), tripleLt);
  buildTernaryTree(nodeNr,
		   triples,
		   0,
		   nrSymbols - 1,
		   neqTarget,
		   position,
		   argIndex);
}

int
FreeNet::addRemainderList(const NatSet& liveSet)
{
  applicable.append(liveSet);
  return - applicable.length();
}

void
FreeNet::translateSlots(int nrRealSlots, const Vector<int>& slotTranslation)
{
  stack.expandTo(nrRealSlots);
  int nrNodes = net.length();
  for (int i = 0; i < nrNodes; i++)
    {
#ifndef SPEED_HACKS
      if (net[i].slot != NONE)
	net[i].slot = slotTranslation[net[i].slot];
      if (net[i].position != NONE)
	net[i].position = slotTranslation[net[i].position];
#else
      //
      //	Pointerize slots and positions for added speed.
      //
      net[i].slotPtr = (net[i].slot == NONE) ? 0 : &(stack[slotTranslation[net[i].slot]]);
      net[i].positionPtr = (net[i].position == NONE) ? 0 :
	&(stack[slotTranslation[net[i].position]]);
#endif
    }
}

void
FreeNet::buildRemainders(const Vector<Equation*>& equations,
			 const NatSet& patternsUsed,
			 const Vector<int>& slotTranslation)
{
  int nrEquations = equations.length();
  remainders.expandTo(nrEquations);
  for (int i = 0; i < nrEquations; i++)
    {
      Equation* e = equations[i];
      if (patternsUsed.contains(i))
	{
	  if (FreeTerm* f = dynamic_cast<FreeTerm*>(e->getLhs()))
	    remainders[i] = f->compileRemainder(e, slotTranslation);
	  else
	    remainders[i] = new FreeRemainder(e);  // remainder for "foreign" equation
	}
      else 
	remainders[i] = 0;
    }
#ifdef SPEED_HACKS
  //
  //	Build null terminated pointer version of applicable for added speed.
  //
  int nrApplicables = applicable.length();
  fastApplicable.resize(nrApplicables);
  for (int i = 0; i < nrApplicables; i++)
    {
      NatSet& live = applicable[i];
      Vector<FreeRemainder*>& rems = fastApplicable[i];
      rems.resize(live.size() + 1);
      Vector<FreeRemainder*>::iterator r = rems.begin();
      const NatSet::const_iterator e = live.end();
      for (NatSet::const_iterator j = live.begin(); j != e; ++j)
	*r++ = remainders[*j];
      *r = 0;
    }
#endif
}

local_inline bool
FreeNet::tripleLt(const Triple& p1, const Triple& p2)
{
#ifdef SPEED_HACKS
  //	
  //	Comparing pointers that don't point into the same array is undefined
  //	according to the C++ standard, but works on reasonable architecture.
  //
  return p1.symbol < p2.symbol;
#else
  return p1.symbol->compare(p2.symbol) < 0;
#endif
}

void
FreeNet::buildTernaryTree(int& nodeIndex,
			  Vector<Triple>& triples,
			  int first,
			  int last,
			  int defaultSubtree,
			  int position,
			  int argIndex)
{
  int sum = first + last;
  int testSymbol = sum / 2;
  if ((sum & 1) && moreImportant(triples[testSymbol + 1].symbol, triples[testSymbol].symbol))
    ++testSymbol;
  int i = nodeIndex++;
  net[i].position = position;
  net[i].argIndex = argIndex;
  net[i].symbol = triples[testSymbol].symbol;
  net[i].slot = triples[testSymbol].slot;
  net[i].equal = triples[testSymbol].subtree;
  if (first < testSymbol)
    {
      net[i].less = nodeIndex;
      buildTernaryTree(nodeIndex, triples, first, testSymbol - 1, defaultSubtree, NONE, NONE);
    }
  else
    net[i].less = defaultSubtree;
  if (last > testSymbol)
    {
      net[i].greater = nodeIndex;
      buildTernaryTree(nodeIndex, triples, testSymbol + 1, last, defaultSubtree, NONE, NONE);
    }
  else
    net[i].greater = defaultSubtree;
}

bool
FreeNet::moreImportant(Symbol* first, Symbol* second)
{
  //
  //	Heuristic to decide which symbol is more importent and thus
  //	should have the fastest matching.
  //
  FreeSymbol* f = dynamic_cast<FreeSymbol*>(first);
  FreeSymbol* s = dynamic_cast<FreeSymbol*>(second);
  if (f != 0 && s == 0)
    return true;
  if (f == 0 && s != 0)
    return false;
  return first->arity() > second->arity();
}

#ifdef DUMP
void
FreeNet::dump(ostream& s, int indentLevel)
{
  if (applicable.length() == 0)
    {
      s << Indent(indentLevel) << "Empty FreeNet\n";
      return;
    }
  s << Indent(indentLevel) << "Begin{FreeNet}\n";
  ++indentLevel;

  s << Indent(indentLevel) << "testNodes:\n";
  ++indentLevel;
  for (int i = 0; i < net.length(); i++)
    {
      s << Indent(indentLevel) << "Node " << i <<
#ifndef SPEED_HACKS
	": position " << net[i].position <<
#else
	": position " << net[i].positionPtr - &(stack[0]) <<
#endif
	", argIndex " << net[i].argIndex <<
	", symbol \"" << net[i].symbol <<
#ifndef SPEED_HACKS
	"\", slot " << net[i].slot <<
#else
	"\", slot " << net[i].slotPtr - &(stack[0]) <<
#endif
	", equal " << net[i].equal <<
	", less " << net[i].less <<
	", greater " << net[i].greater << '\n';
    }

  s << Indent(indentLevel - 1) << "applicable:\n";
  for (int i = 0; i < applicable.length(); i++)
    {
      s << Indent(indentLevel) << "Applicable sequence " << -1 - i << ": " << 
	applicable[i] << '\n';
    }

  s << Indent(indentLevel - 1) << "remainders:\n";
  for (int i = 0; i < remainders.length(); i++)
    {
      s << Indent(indentLevel) << "Remainder " << i << '\n';
      if (remainders[i] != 0)
	remainders[i]->dump(s, indentLevel);
      else
	s << Indent(indentLevel) << "(not generated due to subsumption)\n";
    }

  s << Indent(indentLevel - 2) << "End{FreeNet}\n";
}
#endif
