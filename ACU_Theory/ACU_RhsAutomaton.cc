//
//      Implementation for class ACU_RhsAutomaton.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_Theory.hh"

//      core class definitions
#include "substitution.hh"
#include "variableInfo.hh"

//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_RhsAutomaton.hh"

ACU_RhsAutomaton::ACU_RhsAutomaton(ACU_Symbol* symbol, int nrArgs)
  : topSymbol(symbol),
    arguments(0, nrArgs)
{
}

void
ACU_RhsAutomaton::addArgument(int index, int multiplicity)
{
  int nrArgs = arguments.length();
  arguments.expandBy(1);
  arguments[nrArgs].index = index;
  arguments[nrArgs].multiplicity = multiplicity;
}

void
ACU_RhsAutomaton::close(int destinationIndex)
{
  destination = destinationIndex;
}

void
ACU_RhsAutomaton::remapIndices(VariableInfo& variableInfo)
{
  destination = variableInfo.remapIndex(destination);
  int nrArgs = arguments.length();
  for (int i = 0; i < nrArgs; i++)
    arguments[i].index = variableInfo.remapIndex(arguments[i].index);
}

local_inline void
ACU_RhsAutomaton::buildArguments(ArgVec<ACU_DagNode::Pair>& argArray, Substitution& matcher) const
{
  Vector<Argument>::const_iterator j = arguments.begin();
  const Vector<Argument>::const_iterator e = arguments.end();
  Assert(j != e, cerr << "no args");
  ArgVec<ACU_DagNode::Pair>::iterator i = argArray.begin();
  do
    {
      i->dagNode = matcher.value(j->index);
      i->multiplicity = j->multiplicity;
      ++i;
      ++j;
    }
  while (j != e);
  Assert(i == argArray.end(), cerr << "iterator inconsistent");
}

DagNode*
ACU_RhsAutomaton::construct(Substitution& matcher)
{
  ACU_DagNode* n = new ACU_DagNode(topSymbol, arguments.length());
  buildArguments(n->argArray, matcher);
  matcher.bind(destination, n);
  return n;
}

void
ACU_RhsAutomaton::replace(DagNode* old, Substitution& matcher)
{
  buildArguments((new(old) ACU_DagNode(topSymbol, arguments.length()))->argArray, matcher);
}

#ifdef DUMP
void
ACU_RhsAutomaton::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{ACU_RhsAutomaton}\n";
  ++indentLevel;
  s << Indent(indentLevel) << "[" << destination << "] <= " << topSymbol << '(';
  int nrArgs = arguments.length();
  for (int i = 0; i < nrArgs; i++)
    {
      s << '[' << arguments[i].index << "]^" << arguments[i].multiplicity;
      if (i + 1 < nrArgs)
	s << ", ";
    }
  s << ")\n";
  s << Indent(indentLevel - 1) << "End{ACU_RhsAutomaton}\n";
}
#endif
