//
//      Class for ACU variable stripper-collector lhs automaton.
//
#ifndef _ACU_VarLhsAutomaton_hh_
#define _ACU_VarLhsAutomaton_hh_
#include "ACU_CollectorLhsAutomaton.hh"

class ACU_VarLhsAutomaton : public ACU_CollectorLhsAutomaton
{
  NO_COPYING(ACU_VarLhsAutomaton);

public:
  ACU_VarLhsAutomaton(ACU_Symbol* symbol,
		      bool matchAtTop,
		      bool collapsePossible,
		      int nrVariables,
		      VariableTerm* stripper,
		      VariableTerm* collector);
  //
  //	Standard ACU_LhsAutomaton operations.
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
  //	The stripper variable strips off one argument. It must not
  //	be able to take the identity.
  //
  const int stripperVarIndex;
  Sort* const stripperSort;
  //
  //	If stripper variable can take only one thing or it has a pure sort
  //	then if there exists any assignment there will exist a singleton
  //	assignment. Thus if we can't find a singleton assignment we can
  //	return false.
  //
  const bool trueFailure;
};

#endif
