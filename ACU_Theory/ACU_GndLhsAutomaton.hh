//
//      Class for ACU ground alien stripper-collector algorithm lhs automaton.
//
#ifndef _ACU_GndLhsAutomaton_hh_
#define _ACU_GndLhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "ACU_CollectorLhsAutomaton.hh"

class ACU_GndLhsAutomaton : public ACU_CollectorLhsAutomaton
{
  NO_COPYING(ACU_GndLhsAutomaton);

public:
  ACU_GndLhsAutomaton(ACU_Symbol* topSymbol,
		      bool collapsePossible,
		      Term* stripperTerm,
		      VariableTerm* collector);
  //
  //	Standard LhsAutomaton operations
  //
  bool match(DagNode* subject,
             Substitution& solution,
             Subproblem*& returnedSubproblem,
             ExtensionInfo* extensionInfo);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  ACU_Symbol* const topSymbol;
  const bool collapsePossible;
  //
  //	The stripper term strips off one argument.
  //
  Term* const stripperTerm;		// must be ground
};

#endif
