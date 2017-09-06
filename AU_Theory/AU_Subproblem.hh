//
//	Class for subproblems in the the A, AUl, AUr and AU theories.
//	They consist of a directed acyclic graph and a set of sequence
//	partitioning problems.
//
#ifndef _AU_Subproblem_hh_
#define _AU_Subproblem_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "subproblem.hh"
#include "AU_Layer.hh"

class AU_Subproblem : public Subproblem
{
public:
  AU_Subproblem(AU_DagNode* subject,
		int firstSubterm,
		int lastSubterm,
		int nrBlockPairs,
		AU_ExtensionInfo* extensionInfo);

  bool solve(bool findFirst, RewritingContext& solution);
  void addTopVariable(int layerNr,
		      int index,
		      int lowerBound,
		      int upperBound,
		      Sort* sort);
  void addNode(int layerNr,
	       LocalBinding* difference,
	       Subproblem* subproblem,
	       int firstSubterm,
	       int lastSubterm);
  void complete();

private:
  bool solvePatterns(bool findFirst, RewritingContext& solution);
  bool solveVariables(bool findFirst, RewritingContext& solution);

  AU_ExtensionInfo* const extensionInfo;	// extension information object to be filled in
  Vector<AU_Layer> layers;		// layers of directed acyclic graph
};

inline void
AU_Subproblem::addTopVariable(int layerNr,
			      int index,
			      int lowerBound,
			      int upperBound,
			      Sort* sort)
{
  layers[layerNr].addTopVariable(index, lowerBound, upperBound, sort);
}

inline void
AU_Subproblem::addNode(int layerNr,
		       LocalBinding* difference,
		       Subproblem* subproblem,
		       int firstSubterm,
		       int lastSubterm)
{
  layers[layerNr].addNode(difference, subproblem, firstSubterm, lastSubterm);
}

#endif

