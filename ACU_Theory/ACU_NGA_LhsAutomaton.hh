//
//      Class for ACU non-ground alien stripper-collector algorithm lhs automaton.
//
#ifndef _ACU_NGA_LhsAutomaton_hh_
#define _ACU_NGA_LhsAutomaton_hh_
#include "ACU_CollectorLhsAutomaton.hh"

class ACU_NGA_LhsAutomaton : public ACU_CollectorLhsAutomaton
{
  NO_COPYING(ACU_NGA_LhsAutomaton);

public:
  ACU_NGA_LhsAutomaton(ACU_Symbol* symbol,
		       bool matchAtTop,
		       bool collapsePossible,
		       int nrVariables,
		       LhsAutomaton* stripperAutomaton,
		       Term* stripperTerm,
		       VariableTerm* collector);
  ~ACU_NGA_LhsAutomaton();
  //
  //	Standard LhsAutomaton operations.
  //
  bool match(DagNode* subject,
             Substitution& solution,
             Subproblem*& returnedSubproblem,
             ExtensionInfo* extensionInfo);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  //
  //	The stripper automaton strips off one argument; it must be
  //	non-ground and stable.
  //
  LhsAutomaton* const stripperAutomaton;
  Term* const stripperTerm;
};

#endif
