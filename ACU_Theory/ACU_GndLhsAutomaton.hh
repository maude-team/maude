//
//      Class for ACU ground alien stripper-collector algorithm lhs automaton.
//
#ifndef _ACU_GndLhsAutomaton_hh_
#define _ACU_GndLhsAutomaton_hh_
#include "ACU_CollectorLhsAutomaton.hh"

class ACU_GndLhsAutomaton : public ACU_CollectorLhsAutomaton
{
  NO_COPYING(ACU_GndLhsAutomaton);

public:
  ACU_GndLhsAutomaton(ACU_Symbol* symbol,
		      bool matchAtTop,
		      bool collapsePossible,
		      int nrVariables,
		      Term* stripperTerm,
		      VariableTerm* collector);
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
  //	The stripper term strips off one argument; it must be ground.
  //
  Term* const stripperTerm;
};

#endif
