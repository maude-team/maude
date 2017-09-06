//
//      Class for symbols for built in model checking.
//
#ifndef _modelCheckerSymbol_hh_
#define _modelCheckerSymbol_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "temporalSymbol.hh"
#include "cachedDag.hh"
#include "modelChecker2.hh"
#include "dagNodeSet.hh"
#include "stateTransitionGraph3.hh"

class ModelCheckerSymbol : public TemporalSymbol
{
  NO_COPYING(ModelCheckerSymbol);

public:
  ModelCheckerSymbol(int id);

  bool attachData(const Vector<Sort*>& opDeclaration,
		  const char* purpose,
		  const Vector<const char*>& data);
  bool attachSymbol(const char* purpose, Symbol* symbol);
  bool attachTerm(const char* purpose, Term* term);
  void copyAttachments(Symbol* original, SymbolMap* map);
  bool eqRewrite(DagNode* subject, RewritingContext& context);
  void postInterSymbolPass();
  void reset();

private:
  struct SystemAutomaton  : public ModelChecker2::System
  {
    int getNextState(int stateNr, int transitionNr);
    bool checkProposition(int stateNr, int propositionIndex) const;

    DagNodeSet propositions;
    Symbol* satisfiesSymbol;
    RewritingContext* parentContext;
    DagNode* trueTerm;
    StateTransitionGraph3* systemStates;
  };

  void dump(const StateTransitionGraph3& states, const list<int>& path);
  DagNode* makeTransition(const StateTransitionGraph3& states, int stateNr, int target);
  DagNode* makeTransitionList(const StateTransitionGraph3& states,
			      const list<int>& path,
			      int lastTarget);
  DagNode* makeCounterexample(const StateTransitionGraph3& states, const ModelChecker2& mc);

  Symbol* satisfiesSymbol;
  //
  //	Symbols needed for returning counterexamples.
  //
  QuotedIdentifierSymbol* qidSymbol;
  Symbol* unlabeledSymbol;
  Symbol* deadlockSymbol;
  Symbol* transitionSymbol;
  Symbol* transitionListSymbol;
  Symbol* nilTransitionListSymbol;
  Symbol* counterexampleSymbol;

  CachedDag trueTerm;
};

#endif
