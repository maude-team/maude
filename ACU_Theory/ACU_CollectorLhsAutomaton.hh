//
//      Abstract base class for ACU stripper-collector algorithm left hand side automata.
//
#ifndef _ACU_CollectorLhsAutomaton_hh_
#define _ACU_CollectorLhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "heuristicLhsAutomaton.hh"

class ACU_CollectorLhsAutomaton : public HeuristicLhsAutomaton
{
  NO_COPYING(ACU_CollectorLhsAutomaton);

public:
  ACU_CollectorLhsAutomaton(VariableTerm* collector);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

protected:
  bool collectorFree(Substitution& solution) const;
  bool collect(int stripped, ACU_DagNode* subject, Substitution& solution) const;
  bool collect(ACU_Stack& stripped,  // destroyed
	       ACU_TreeDagNode* subject,
	       Substitution& solution) const;
  void collapse(ACU_Symbol* topSymbol, Substitution& solution) const;

private:
  //
  //	The stripper variable/automaton/term in the derived class
  //	strips off one argument.
  //	The collector variable collects all the other arguments.
  //
  const int collectorVarIndex;
  //
  //	The collector sort must be limit or pure w.r.t. topSymbol; If it is
  //	the unique maximal sort of an error free component we set it to 0
  //	to switch off sort checks since they should always succeed.
  //
  const Sort* collectorSort;
};

inline bool
ACU_CollectorLhsAutomaton::collectorFree(Substitution& solution) const
{
  return solution.value(collectorVarIndex) == 0;
}

inline void
ACU_CollectorLhsAutomaton::collapse(ACU_Symbol* topSymbol, Substitution& solution) const
{
  solution.bind(collectorVarIndex, topSymbol->getIdentityDag());
}

#endif
