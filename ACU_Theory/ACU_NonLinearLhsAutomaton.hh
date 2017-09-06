//
//	Class for fast left hand side automata in the AC and ACU theories when there
//	there is just a variable of multiplicity >= 2 with pure or unit sort which cannot
//	take identity.
//
#ifndef _ACU_NonLinearLhsAutomaton_hh_
#define _ACU_NonLinearLhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "heuristicLhsAutomaton.hh"

class ACU_NonLinearLhsAutomaton : public HeuristicLhsAutomaton
{
  NO_COPYING(ACU_NonLinearLhsAutomaton);

public:
  ACU_NonLinearLhsAutomaton(ACU_Symbol* topSymbol,
			    int varIndex,
			    int multiplicity,
			    Sort* varSort);
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
  void fillOutExtensionInfo(ACU_DagNode* subject,
			    const ArgVec<ACU_DagNode::Pair>::const_iterator chosen,
			    ACU_ExtensionInfo* extensionInfo);

  bool treeMatch(ACU_TreeDagNode* subject,
		 Substitution& solution,
		 Subproblem*& returnedSubproblem,
		 ACU_ExtensionInfo* extensionInfo);

  ACU_Symbol* const topSymbol;
  const int varIndex;
  const int multiplicity;
  Sort* const varSort;
  const bool unitSort;
  //
  //	Data storage for match-time use
  //
  Vector<ACU_DagNode::Pair> matched;
};

#endif
