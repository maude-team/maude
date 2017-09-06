//
//      Class for building instances of right hand sides.
//
#ifndef _rhsBuilder_hh_
#define _rhsBuilder_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "rhsAutomaton.hh"

class RhsBuilder
{
public:
  RhsBuilder();
  ~RhsBuilder();

  void addRhsAutomaton(RhsAutomaton* automaton);
  bool empty();
  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher) const;
  void safeConstruct(Substitution& matcher) const;
  void replace(DagNode* old, Substitution& matcher) const;

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel = 0);
#endif

private:
  Vector<RhsAutomaton*> automata;
  RhsAutomaton* lastAutomaton;
};

inline
RhsBuilder::RhsBuilder()
{
  lastAutomaton = 0;
}

inline bool
RhsBuilder::empty()
{
  return lastAutomaton == 0;
}

inline void
RhsBuilder::addRhsAutomaton(RhsAutomaton* automaton)
{
  if (lastAutomaton != 0)
    automata.append(lastAutomaton);
  lastAutomaton = automaton;
}

inline DagNode*
RhsBuilder::construct(Substitution& matcher) const
{
  if (!automata.isNull())
    {
      int nrAutomata = automata.length();
      int i = 0;
      do
	(void) automata[i]->construct(matcher);
      while (++i < nrAutomata);
    }
  return lastAutomaton->construct(matcher);
}

inline void
RhsBuilder::safeConstruct(Substitution& matcher) const
{
  if (!automata.isNull())
    {
      int nrAutomata = automata.length();
      int i = 0;
      do
	(void) automata[i]->construct(matcher);
      while (++i < nrAutomata);
    }
  if (lastAutomaton != 0)
    (void) lastAutomaton->construct(matcher);
}

inline void
RhsBuilder::replace(DagNode* old, Substitution& matcher) const
{
  if (!automata.isNull())
    {
      int nrAutomata = automata.length();
      int i = 0;
      do
	(void) automata[i]->construct(matcher);
      while (++i < nrAutomata);
    }
  lastAutomaton->replace(old, matcher);
}

#endif
