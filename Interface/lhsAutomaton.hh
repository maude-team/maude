//
//	Abstract base class for left hand side automata.
//
#ifndef _lhsAutomaton_hh_
#define _lhsAutomaton_hh_

class LhsAutomaton
{
public:
  virtual ~LhsAutomaton() {}

  virtual bool match(DagNode* subject,
		     Substitution& solution,
		     Subproblem*& returnedSubproblem,
		     ExtensionInfo* extensionInfo = 0) = 0;

#ifdef DUMP
  virtual void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel = 0) = 0;
#endif

};

#endif
