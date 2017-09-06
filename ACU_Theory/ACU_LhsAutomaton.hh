//
//      Class for left hand side automata in the AC and ACU theories.
//
#ifndef _ACU_LhsAutomaton_hh_
#define _ACU_LhsAutomaton_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "lhsAutomaton.hh"

class ACU_LhsAutomaton : public LhsAutomaton
{
  NO_COPYING(ACU_LhsAutomaton);

public:
  enum MatchStrategy
  {
    //
    //	Ground out case: no extension and everthing grounds out;
    //	return fail if any subjects left.
    //
    GROUND_OUT,
    //
    //	Lone variable case: no extension, no aliens, 1 unbound variable which is forced
    //	to match remaining subjects.
    //
    LONE_VARIABLE,
    //
    //	Aliens only case: no extension, all top variables are guaranteed to be
    //	bound on entry to matcher. Alien sequence will be ordered:
    //		(1) to optimize strong constraint propagation (match independent aliens)
    //		(2) to "force" as many aliens as possible (subsumptive aliens)
    //		(3) to optimize weak constraint propagation (aliens left over)
    //	The field nrIndependents holds the total number in parts (1) and (2) of
    //	alien sequence.
    //
    ALIENS_ONLY,
    //
    //	Greedy case: the intersection of each subterm's variables with union of
    //	its context variables and the condition variables contains only variables
    //	guaranteed to be bound on entry to matcher. Alien sequence will be ordered
    //	to maximize the chance that greedy failure is true failure. The field
    //	nrIndependents holds the number of aliens for which greedy failure is true
    //	failure. The top variable sequence will be ordered to maximize the chance of
    //	finding a greedy match, and in the pure greedy case, to maximize the chance
    //	that pure greedy failure is true failure.
    //
    GREEDY,
    //
    //	Full case: if other cases don't apply. Alien sequence will be ordered to
    //	optimize solve-time weak constraint propagation. The field nrIndependents
    //	is unused.
    //
    FULL
  };
  //
  //	Operations to build an ACU_LhsAutomaton
  //
  ACU_LhsAutomaton(ACU_Symbol* symbol,
		   bool matchAtTop,
		   bool collapsePossible,
		   LhsAutomaton* uniqueCollapseAutomaton,
		   int nrVariables);
  ~ACU_LhsAutomaton();

  void addTopVariable(const VariableTerm* variable, int multiplicity);
  void addAbstractionVariable(int index,
			      Sort* sort,
			      int upperBound,
			      bool takeIdentity,
			      LhsAutomaton* abstracted,
			      int multiplicity);
  void addGroundAlien(Term* alien, int multiplicity);
  void addGroundedOutAlien(Term* alien, LhsAutomaton* automaton, int multiplicity);
  void addNonGroundAlien(Term* alien, LhsAutomaton* automaton, int multiplicity);
  void complete(MatchStrategy strategy, int nrIndependent);
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
  struct TopVariable
  {
    int index;
    int multiplicity;
    Sort* sort;
    int upperBound;
    AssociativeSymbol::Structure structure;
    bool takeIdentity;
    LhsAutomaton* abstracted;	// automaton for abstracted term
    //
    //	Data storage for match-time use
    //
    int prevUnbound;	// back pointer to last unbound variable
    int firstSubject;	// first subject heuristically assigned to variable
    int nrSubjects;	// number of subjects heuristically assigned to variable
  };

  struct GroundAlien
  {
    Term* term;
    int multiplicity;
  };

  struct NonGroundAlien
  {
    Symbol* topSymbol;	// 0 if not stable
    LhsAutomaton* automaton;
    int multiplicity;
  };

  struct Subject
  {
    int multiplicity;
    int assignee;
  };

  static bool topVariableLt(const TopVariable& t1, const TopVariable& t2);

  void updateTotals(int min, int max);
  bool multiplicityChecks(ACU_DagNode* subject);
  bool eliminateGroundAliens(ACU_DagNode* subject);
  bool eliminateBoundVariables(ACU_DagNode* subject, Substitution& solution);
  bool eliminateGroundedOutAliens(ACU_DagNode* subject, Substitution& solution);
  bool forcedLoneVariableCase(ACU_DagNode* subject,
			      Substitution& solution,
			      Subproblem*& returnedSubproblem);
  bool aliensOnlyMatch(ACU_DagNode* subject,
		       Substitution& solution,
		       Subproblem*& returnedSubproblem);
  ACU_Subproblem* buildBipartiteGraph(ACU_DagNode* subject,
				     Substitution& solution,
				     ACU_ExtensionInfo* extensionInfo,
				     int firstAlien);
  bool handleElementVariables(ACU_DagNode* subject,
			      Substitution& solution,
			      ACU_Subproblem* subproblem);
  void copyMultiplicity();
  int computeTotalMultiplicity();
  int greedyMatch(ACU_DagNode* subject,
		  Substitution& solution,
		  ACU_ExtensionInfo* extensionInfo);
  int greedyPureMatch(ACU_DagNode* subject,
		      Substitution& solution,
		      ACU_ExtensionInfo* extensionInfo,
		      bool returnUndecidedOnFail);
  void bindUnboundVariablesToIdentity(Substitution& solution, int exception);
  bool uniqueCollapseMatch(DagNode* subject,
			   Substitution& solution,
			   Subproblem*& returnedSubproblem,
			   ExtensionInfo* extensionInfo);
  bool multiwayCollapseMatch(DagNode* subject,
			     Substitution& solution,
			     Subproblem*& returnedSubproblem,
			     ExtensionInfo* extensionInfo);
  bool collapseMatch(DagNode* subject,
		     Substitution& solution,
		     Subproblem*& returnedSubproblem,
		     ExtensionInfo* extensionInfo);
  bool fullMatch(ACU_DagNode* subject,
		 Substitution& solution,
		 Subproblem*& returnedSubproblem,
		 ACU_ExtensionInfo* extensionInfo);

  ACU_Symbol* const topSymbol;
  const Bool matchAtTop;
  const Bool collapsePossible;
  Byte matchStrategy;
  int totalLowerBound;  // must have at least this total mutiplicity of subjects
  int totalUpperBound;	// can't have more than this total mutiplicity of subjects
  int maxPatternMultiplicity;  // must have at least on subject with >= this multiplicity
  int totalNonGroundAliensMultiplicity;
  int nrIndependentAliens;
  LhsAutomaton* uniqueCollapseAutomaton;
  Vector<TopVariable> topVariables;
  Vector<GroundAlien> groundAliens;
  Vector<NonGroundAlien> groundedOutAliens;
  Vector<NonGroundAlien> nonGroundAliens;
  //
  //	Data storage for match-time use
  //
  int lastUnboundVariable;
  int totalMultiplicity;
  Vector<int> currentMultiplicity;
  Substitution local;
  Substitution scratch;
  Vector<Subject> subjects;
};

#ifdef DUMP
ostream& operator<<(ostream& s, ACU_LhsAutomaton::MatchStrategy strategy);
#endif

#endif
