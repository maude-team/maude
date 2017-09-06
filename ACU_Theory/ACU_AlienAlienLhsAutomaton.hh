//
//      Class for fast left hand side automata in the AC and ACU theories when there
//	are two stable alien subterms with multiplicity 1.
//
#ifndef _ACU_AlienAlienLhsAutomaton_hh_
#define _ACU_AlienAlienLhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "heuristicLhsAutomaton.hh"

class ACU_AlienAlienLhsAutomaton : public HeuristicLhsAutomaton
{
  NO_COPYING(ACU_AlienAlienLhsAutomaton);

public:
  ACU_AlienAlienLhsAutomaton(ACU_Symbol* topSymbol,
			     Symbol* firstSymbol,
			     LhsAutomaton* firstAutomaton,
			     Symbol* secondSymbol,
			     LhsAutomaton* secondAutomaton,
			     int nrVariables);
  ~ACU_AlienAlienLhsAutomaton();
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
  Symbol* firstSymbol;
  LhsAutomaton* firstAutomaton;
  Symbol* secondSymbol;
  LhsAutomaton* secondAutomaton;
  //
  //	Data storage for match-time use
  //
  Substitution local;
  Substitution local2;
};

#endif
