//
//	Abstract base class for heuristic left hand side automata.
//	These try to pick off easy cases in a cheap way and contain a pointer
//	to a full automaton for when they fail.
//
#ifndef _heuristicLhsAutomaton_hh_
#define _heuristicLhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "lhsAutomaton.hh"

class HeuristicLhsAutomaton : public LhsAutomaton
{
public:
  ~HeuristicLhsAutomaton();
  void complete(LhsAutomaton* automaton);
  bool fullMatch(DagNode* subject,
		 Substitution& solution,
		 Subproblem*& returnedSubproblem,
		 ExtensionInfo* extensionInfo);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel = 0);
#endif

private:
  LhsAutomaton* fullAutomaton;
};

inline void
HeuristicLhsAutomaton::complete(LhsAutomaton* automaton)
{
  fullAutomaton = automaton;
}

inline bool
HeuristicLhsAutomaton::fullMatch(DagNode* subject,
				 Substitution& solution,
				 Subproblem*& returnedSubproblem,
				 ExtensionInfo* extensionInfo)
{
  return fullAutomaton->match(subject, solution, returnedSubproblem, extensionInfo);
}

#endif
