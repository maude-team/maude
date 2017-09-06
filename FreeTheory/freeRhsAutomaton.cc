//
//	Implementation for class FreeRhsAutomaton.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//	core class definitions
#include "substitution.hh"
#include "variableInfo.hh"

//	free theory class definitions
#include "freeDagNode.hh"
#include "freeRhsAutomaton.hh"

void
FreeRhsAutomaton::addFree(Symbol* symbol,
			  int destination,
			  const Vector<int>& sources)
{
  int i = instructions.length();
  instructions.expandBy(1);
  instructions[i].symbol = symbol;
  instructions[i].destination = destination;
  instructions[i].sources = sources;  // deep copy
}

void
FreeRhsAutomaton::remapIndices(VariableInfo& variableInfo)
{
  int nrInstructions = instructions.length();
  for (int i = 0; i < nrInstructions; i++)
    {
      Instruction& instr = instructions[i];
      instr.destination = variableInfo.remapIndex(instr.destination);
      int nrArgs = instr.sources.length();
      for (int j = 0; j < nrArgs; j++)
	instr.sources[j] = variableInfo.remapIndex(instr.sources[j]);
    }
}

local_inline void
FreeRhsAutomaton::fillOutArgs(int nrArgs,
			      const Instruction& instr,
			      Substitution& matcher,
			      FreeDagNode* d)
{
  if (nrArgs > 0)
    {
      DagNode** args = d->argArray();
      Vector<int>::const_iterator j = instr.sources.begin();
      Vector<int>::const_iterator e = instr.sources.end();
      do
	*args++ = matcher.value(*j);
      while (++j != e);
    }
}

DagNode*
FreeRhsAutomaton::construct(Substitution& matcher)
{
  FreeDagNode* d;
  const Vector<Instruction>& t = instructions;
  Vector<Instruction>::const_iterator k = t.begin();
  Vector<Instruction>::const_iterator e = t.end();
  do
    {
      int nrArgs = k->symbol->arity();
      d = new FreeDagNode(k->symbol);
      fillOutArgs(nrArgs, *k, matcher, d);
      matcher.bind(k->destination, d);
    }
  while (++k != e);
  return d;
}

void
FreeRhsAutomaton::replace(DagNode* old, Substitution& matcher)
{
  const Vector<Instruction>& t = instructions;
  Vector<Instruction>::const_iterator e = t.end() - 1;
  for (Vector<Instruction>::const_iterator i = t.begin();; ++i)
    {
      int nrArgs = i->symbol->arity();
      if (i == e)
	{
	  FreeDagNode* d = new(old) FreeDagNode(i->symbol);
	  fillOutArgs(nrArgs, *i, matcher, d);
	  break;
	}
      else
	{
	  FreeDagNode* d = new FreeDagNode(i->symbol);
	  fillOutArgs(nrArgs, *i, matcher, d);
	  matcher.bind(i->destination, d);
	}
    }
}

#ifdef DUMP
void
FreeRhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{FreeRhsAutomaton}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "Instructions:\n";
  ++indentLevel;
  int nrInstructions = instructions.length();
  for (int i = 0; i < nrInstructions; i++)
    {
      s << Indent(indentLevel) << "[" << instructions[i].destination << "] <= "
	<< instructions[i].symbol << '(';
      int nrArgs = instructions[i].symbol->arity();
      for (int j = 0; j < nrArgs; j++)
	{
	  s << '[' << instructions[i].sources[j] << ']';
	  if (j + 1 < nrArgs)
	    s << ", ";
	}
      s << ")\n";
    }
  s << Indent(indentLevel - 2) << "End{FreeRhsAutomaton}\n";
}
#endif
