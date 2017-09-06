//
//      Class for building instances of right hand sides.
//
#ifndef _rhsBuilder_hh_
#define _rhsBuilder_hh_
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
      Vector<RhsAutomaton*>::const_iterator i = automata.begin();
      const Vector<RhsAutomaton*>::const_iterator e = automata.end();
      do
	(void) (*i)->construct(matcher);
      while (++i != e);
    }
  return lastAutomaton->construct(matcher);
}

inline void
RhsBuilder::safeConstruct(Substitution& matcher) const
{
  if (!automata.isNull())
    {
      Vector<RhsAutomaton*>::const_iterator i = automata.begin();
      const Vector<RhsAutomaton*>::const_iterator e = automata.end();
      do
	(void) (*i)->construct(matcher);
      while (++i != e);
    }
  if (lastAutomaton != 0)
    (void) lastAutomaton->construct(matcher);
}

inline void
RhsBuilder::replace(DagNode* old, Substitution& matcher) const
{
  if (!automata.isNull())
    {
      Vector<RhsAutomaton*>::const_iterator i = automata.begin();
      const Vector<RhsAutomaton*>::const_iterator e = automata.end();
      do
	(void) (*i)->construct(matcher);
      while (++i != e);
    }
  lastAutomaton->replace(old, matcher);
}

#endif
