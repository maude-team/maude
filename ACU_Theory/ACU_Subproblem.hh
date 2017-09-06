//
//      Class for subproblems in the AC and ACU theories;
//	they consist of a bipartite graph matching 
//	problem and (possibly) a diophantine system
//
#ifndef _ACU_Subproblem_hh_
#define _ACU_Subproblem_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "subproblem.hh"

class ACU_Subproblem : public Subproblem
{
  NO_COPYING(ACU_Subproblem);

public:
  ACU_Subproblem(ACU_DagNode* subjectDagNode,
		 Vector<int>& multiplicity,
		 ACU_ExtensionInfo* extension);
  ~ACU_Subproblem();

  void addPatternNode(int multiplicity);
  void addEdge(int pattern,
	       int target,
	       const Substitution& global,
	       const Substitution& local,
	       Subproblem* subproblem);
  void addTopVariable(int index,
		      int multiplicity,
		      int lowerBound,
		      int upperBound,
		      const Sort* sort);
  bool solve(bool findFirst, RewritingContext& solution);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  struct TopVariable
    {
      int index;
      int multiplicity;
      int lowerBound;
      int upperBound;
      const Sort* sort;
    };

  struct Edge
    {
      int target;
      LocalBinding* difference;
      Subproblem* subproblem;
    };

  struct PatternNode
    {
      bool solve(bool findFirst,
		 RewritingContext& solution,
		 Vector<int>& currentMultiplicity);

      int multiplicity;
      Vector<Edge> edges;
      int selectedEdge;
    };

  bool solvePatterns(bool findFirst, RewritingContext& solution);
  bool solveVariables(bool findFirst, RewritingContext& solution);
  bool oneVariableCase(TopVariable& tv, RewritingContext& solution);
  bool extractDiophantineSystem(RewritingContext& solution);
  DagNode* computeAssignment(int row);
  void fillOutExtensionInfo();

  ACU_DagNode* const subject;
  ACU_ExtensionInfo* const extensionInfo;
  Vector<int> currentMultiplicity;
  Vector<TopVariable> topVariables;
  Vector<PatternNode> patternNodes;
  //
  //	Structures needed for building and solving diophantine problem
  //
  DiophantineSystem* system;
  Vector<int> variableMap;
  Vector<int> subjectMap;
  Vector<int> afterMultiplicity;
};

#endif
