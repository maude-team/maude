//
//      Base class for ACU stripper-collector left hand side automata.
//
#ifndef _ACU_CollectorLhsAutomaton_hh_
#define _ACU_CollectorLhsAutomaton_hh_
#include "ACU_LhsAutomaton.hh"

class ACU_CollectorLhsAutomaton : public ACU_LhsAutomaton
{
  NO_COPYING(ACU_CollectorLhsAutomaton);

public:
  ACU_CollectorLhsAutomaton(ACU_Symbol* symbol,
			    bool matchAtTop,
			    bool collapsePossible,
			    int nrVariables,
			    VariableTerm* collector);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

protected:
  bool collectorFree(Substitution& solution) const;
  bool collect(int stripped, ACU_DagNode* subject, Substitution& solution) const;
  bool collect(ACU_Stack& stripped,  // destroyed
	       ACU_TreeDagNode* subject,
	       Substitution& solution) const;
  void collapse(Substitution& solution) const;

private:
  //
  //	The stripper variable/automaton/term in the derived class
  //	strips off one argument.
  //	The collector variable collects all the other arguments.
  //
  const int collectorVarIndex;
  //
  //	The collector sort must be unbounded. If it is the error sort
  //	or the unique maximal sort of an error free component we set
  //	it to 0 to switch off sort checks since they should always succeed.
  //
  const Sort* collectorSort;
};

inline bool
ACU_CollectorLhsAutomaton::collectorFree(Substitution& solution) const
{
  return solution.value(collectorVarIndex) == 0;
}

inline void
ACU_CollectorLhsAutomaton::collapse(Substitution& solution) const
{
  solution.bind(collectorVarIndex, getSymbol()->getIdentityDag());
}

#endif
