//
//	Class for fast left hand side automata in the AC and ACU theories
//	when there is just a variable of multiplicity >= 2 with pure,
//	limit or unit sort which cannot take identity, at the top.
//
#ifndef _ACU_NonLinearLhsAutomaton_hh_
#define _ACU_NonLinearLhsAutomaton_hh_
#include "ACU_LhsAutomaton.hh"

class ACU_NonLinearLhsAutomaton : public ACU_LhsAutomaton
{
  NO_COPYING(ACU_NonLinearLhsAutomaton);

public:
  ACU_NonLinearLhsAutomaton(ACU_Symbol* symbol,
			    int nrVariables,
			    int varIndex,
			    int multiplicity,
			    Sort* varSort);
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
  void fillOutExtensionInfo(ACU_DagNode* subject,
			    const ArgVec<ACU_DagNode::Pair>::const_iterator chosen,
			    ACU_ExtensionInfo* extensionInfo);

  const int varIndex;
  const int multiplicity;
  Sort* const varSort;
  const Bool unitSort;
  const Bool pureSort;
};

#endif
