//
//      Class for ACU variable stripper-collector algorithm lhs automaton.
//
#ifndef _ACU_VarLhsAutomaton_hh_
#define _ACU_VarLhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "ACU_CollectorLhsAutomaton.hh"

class ACU_VarLhsAutomaton : public ACU_CollectorLhsAutomaton
{
  NO_COPYING(ACU_VarLhsAutomaton);

public:
  ACU_VarLhsAutomaton(ACU_Symbol* topSymbol,
		      bool collapsePossible,
		      VariableTerm* stripper,
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
  ACU_Symbol* const topSymbol;
  const bool collapsePossible;
  //
  //	The stripper variable strips off one argument.
  //
  const int stripperVarIndex;
  Sort* const stripperSort;		// must be unit or pure w.r.t. topSymbol
};

#endif
