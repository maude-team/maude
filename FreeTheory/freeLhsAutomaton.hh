//
//      Class for left hand side automata in the free theory.
//
#ifndef _freeLhsAutomaton_hh_
#define _freeLhsAutomaton_hh_
#include "lhsAutomaton.hh"
#include "freeLhsStructs.hh"

class FreeLhsAutomaton : public LhsAutomaton, private FreeLhsStructs
{
  NO_COPYING(FreeLhsAutomaton);

public:
  FreeLhsAutomaton(const Vector<FreeOccurrence>& freeSymbols,
		   const Vector<FreeOccurrence>& uncertainVars,
		   const Vector<FreeOccurrence>& boundVars,
		   const Vector<FreeOccurrence>& gndAliens,
		   const Vector<FreeOccurrence>& nonGndAliens,
		   const Vector<int>& bestSequence,
		   const Vector<LhsAutomaton*>& subAutomata);
  ~FreeLhsAutomaton();

  bool match(DagNode* subject,
	     Substitution& solution,
	     Subproblem*& returnedSubproblem,
	     ExtensionInfo* extensionInfo);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  struct FreeSubterm
    {
      int position;
      int argIndex;
      Symbol* symbol;
      int saveIndex;  // for left->right sharing
    };

  Symbol* topSymbol;
  Vector<DagNode**> stack;
  Vector<FreeSubterm> freeSubterms;
  Vector<FreeVariable> uncertainVariables;
  Vector<BoundVariable> boundVariables;
  Vector<GroundAlien> groundAliens;
  Vector<NonGroundAlien> nonGroundAliens;
};

#endif
