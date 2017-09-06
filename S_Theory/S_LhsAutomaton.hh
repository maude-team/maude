//
//      Class for left hand side automata for S theory.
//
#ifndef _S_LhsAutomaton_hh_
#define _S_LhsAutomaton_hh_
#include <gmpxx.h>
#include "lhsAutomaton.hh"

class S_LhsAutomaton : public LhsAutomaton
{
  NO_COPYING(S_LhsAutomaton);

public:
  S_LhsAutomaton(S_Symbol* symbol,
		 const mpz_class& number,
		 bool matchAtTop);
  ~S_LhsAutomaton();
  bool addSubpattern(Term* term,
		     int abstractionVariableIndex,
		     const VariableInfo& variableInfo,
		     NatSet& boundUniquely);
  //
  //    Functions required by theory interface.
  //
  bool match(DagNode* subject,
             Substitution& solution,
             Subproblem*& returnedSubproblem,
             ExtensionInfo* extensionInfo);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  enum PatternType
  {
    GROUND_ALIEN,
    VARIABLE,
    NON_GROUND_ALIEN,
    ABSTRACTED_NON_GROUND_ALIEN,
  };

  bool matchEq(DagNode* arg,
	       Substitution& solution,
	       Subproblem*& returnedSubproblem);
  bool nonExtMatchGt(DagNode* subject,
		     DagNode* arg,
		     const mpz_class& subjectNumber,
		     Substitution& solution,
		     Subproblem*& returnedSubproblem);
  bool extMatchGt(S_DagNode* subject,
		  DagNode* arg,
		  const mpz_class& subjectNumber,
		  Substitution& solution,
		  Subproblem*& returnedSubproblem,
		  S_ExtensionInfo* extensionInfo);

  S_Symbol* const topSymbol;
  const mpz_class number;
  const bool matchAtTop;
  //
  //	Stuff for argument.
  //
  PatternType type;
  union
  {
    Term* groundTerm;		// GROUND_ALIEN cases
    LhsAutomaton* automaton;	// NON_GROUND_ALIEN & ABSTRACTED_NON_GROUND_ALIEN cases
  };
  int varIndex;			// VARIABLE & ABSTRACTED_NON_GROUND_ALIEN cases
  Sort* sort;			// VARIABLE & ABSTRACTED_NON_GROUND_ALIEN cases
};

#endif
