//
//      Class for ACU Non-ground alien stripper-collector algorithm lhs automaton.
//
#ifndef _ACU_NGA_LhsAutomaton_hh_
#define _ACU_NGA_LhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "ACU_CollectorLhsAutomaton.hh"

class ACU_NGA_LhsAutomaton : public ACU_CollectorLhsAutomaton
{
  NO_COPYING(ACU_NGA_LhsAutomaton);

public:
  ACU_NGA_LhsAutomaton(ACU_Symbol* topSymbol,
		       bool collapsePossible,
		       LhsAutomaton* stripperAutomaton,
		       Term* stripperTerm,
		       int nrVariables,
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
  ACU_Symbol* const topSymbol;
  const bool collapsePossible;
  //
  //	The stripper automaton strips off one argument.
  //
  LhsAutomaton* const stripperAutomaton;
  Term* const stripperTerm;
  //
  //	Data storage for match-time use.
  //
  Substitution local;
};

#endif
