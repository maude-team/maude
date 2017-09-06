//
//	Class for DAG nodes in the A, AUl, AUr and AU theories.
//
#ifndef _AU_DagNode_hh_
#define _AU_DagNode_hh_
#include "AU_BaseDagNode.hh"
#include "argVec.hh"

class AU_DagNode : public AU_BaseDagNode
{
  NO_COPYING(AU_DagNode);

public:
  AU_DagNode(AU_Symbol* symbol, int size);
  //
  //	Functions required by theory interface.
  //
  RawDagArgumentIterator* arguments();
  size_t getHashValue();
  int compareArguments(const DagNode* other) const;
  void overwriteWithClone(DagNode* old);
  DagNode* makeClone();
  DagNode* copyWithReplacement(int argIndex, DagNode* replacement);
  DagNode* copyWithReplacement(Vector<RedexPosition>& redexStack,
			       int first,
			       int last);
  void stackArguments(Vector<RedexPosition>& stack,
		      int parentIndex,
		      bool respectFrozen);
  //
  //	Functions required to handle extension information.
  //
  bool matchVariableWithExtension(int index,
				  const Sort* sort,
				  Substitution& solution,
				  Subproblem*& returnedSubproblem,
				  ExtensionInfo* extensionInfo);
  void partialReplace(DagNode* replacement, ExtensionInfo* extensionInfo);
  DagNode* partialConstruct(DagNode* replacement, ExtensionInfo* extensionInfo);
  ExtensionInfo* makeExtensionInfo();
  //
  //	Functions particular to AU_DagNode.
  //
  void setProducedByAssignment();
  
private:
  enum NormalizationResult
  {
    COLLAPSED,
    DEQUED,
    NORMAL,
    FLATTENED
  };
  //
  //	Functions required by theory interface.
  //
  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();
  void clearCopyPointers2();
  //
  //	Functions particular to AU_DagNode.
  //
  bool disappear(AU_Symbol* s, ArgVec<DagNode*>::const_iterator i);
  NormalizationResult normalizeAtTop();
  bool eliminateForward(DagNode* target, int& pos, int limit) const;
  bool eliminateBackward(DagNode* target, int& pos, int limit) const;
  DagNode* makeFragment(int start, int nrSubterms, bool extraId) const;

  ArgVec<DagNode*> argArray;

  friend class AU_Symbol;           	// to reduce subterms prior to rewriting
  friend class AU_Term;          	// for term->DAG conversion & comparison
  friend class AU_LhsAutomaton;	      	// for matching DAG subject
  friend class AU_RhsAutomaton;		// for constructing replacement DAG
  friend class AU_Layer;		// for constructing substitution
  friend class AU_Subproblem;		// for constructing substitution
  friend class AU_ExtensionInfo;	// for constructing matched portion
  friend class AU_DequeDagNode;		// for conversion & comparison
};

AU_DagNode* getAU_DagNode(DagNode* dagNode);

inline
AU_DagNode::AU_DagNode(AU_Symbol* symbol, int size)
  : AU_BaseDagNode(symbol),
    argArray(size)
{
  setNormalizationStatus(FRESH);
}

inline void
AU_DagNode::setProducedByAssignment()
{
  setNormalizationStatus(ASSIGNMENT);
}

#endif
