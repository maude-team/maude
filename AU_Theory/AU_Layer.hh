//
//	Class for a layer of nodes in an AU_Subproblem.
//
#ifndef _AU_Layer_hh_
#define _AU_Layer_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "sequencePartition.hh"

class AU_Layer
{
public:
  AU_Layer();
  ~AU_Layer();

  void initialize(AU_DagNode* subjectDag);
  void initializeFirst(int first, AU_ExtensionInfo* extension);
  void initializeLast(int last, AU_ExtensionInfo* extension);
  void addTopVariable(int index, int lowerBound, int upperBound, Sort* sort);
  void addNode(LocalBinding* difference,
	       Subproblem* subproblem,
	       int firstSubterm,
	       int lastSubterm);
  void link(AU_Layer& nextLayer);
  void reset();
  bool solvePatterns(bool findFirst, RewritingContext& solution, AU_Layer& nextLayer);
  bool solveVariables(bool findFirst, RewritingContext& solution);

private:
  struct TopVariable
  {
    int index;
    int lowerBound;
    int upperBound;
    Sort* sort;
    //
    //	For solve-time use
    //
    Bool boundByUs;
    Bool extraId;
  };

  struct Node
  {
    LocalBinding* difference;
    Subproblem* subproblem;
    int firstSubterm;
    int lastSubterm;
    int downTarget;
  };

  bool solvePatterns2(bool findFirst, RewritingContext& solution);
  SequencePartition* buildPartition(const Substitution& solution);
  bool solvePartition(bool findFirst);
  bool bindVariables(RewritingContext& solution);
  void unbindVariables(RewritingContext& solution);

  const AU_DagNode* subject;
  int lastSubjectSubterm;		// index of last subterm in subject
  Bool oneSidedId;			// true if subject has a one sided identity
  Bool leftId;				// true if subject has left identity only
  Bool leftExtend;			// have left extension before variable block
  Bool rightExtend;			// have right extension after variable block
  int totalLowerBound;			// sum of lowerBounds for prevVariables 
  int totalUpperBound;			// sum of upperBounds for prevVariables + extension
  AU_ExtensionInfo* extensionInfo;	// for layers with leftExtend/rightExtend only
  Vector<TopVariable> prevVariables;	// variable block before rigid block
  Vector<Node> nodes;			// nodes for a rigid blocks possible matchings
  //
  //	For solve-time use
  //
  int selectedNode;			// currently selected node
  int firstSubterm;			// first subject subterm for variables
  int lastSubterm;			// last subject subterm for variables
  SequencePartition* partition;		// partitioning of subterms amongst variables
};

inline void
AU_Layer::reset()
{
  selectedNode = 0;
}

#endif
