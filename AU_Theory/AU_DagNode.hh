//
//	Class for DAG nodes in the A, AUl, AUr and AU theories.
//
#ifndef _AU_DagNode_hh_
#define _AU_DagNode_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "dagNode.hh"
#include "argVec.hh"

class AU_DagNode : public DagNode
{
public:
  AU_DagNode(AU_Symbol* symbol, int size);
  ~AU_DagNode();
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
  AU_Symbol* symbol() const;
  int nrArgs() const;
  DagNode* getArgument(int i) const;
  bool producedByAssignment() const;
  void setProducedByAssignment();
  
private:
  enum NormalizationResult
  {
    COLLAPSED = 0,
    NORMAL,
    FLATTENED
  };

  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();
  void clearCopyPointers2();
  NormalizationResult normalizeAtTop();
  bool eliminateForward(const DagNode* target, int& pos, int limit) const;
  bool eliminateBackward(const DagNode* target, int& pos, int limit) const;
  DagNode* makeFragment(int start, int nrSubterms, bool extraId) const;

  ArgVec<DagNode*> argArray;

  friend class AU_Symbol;           	// to reduce subterms prior to rewrite, normalization
  friend class AU_Term;          	// for term->DAG conversion & comparison
  friend class AU_LhsAutomaton;	      	// for matching DAG subject
  friend class AU_RhsAutomaton;		// for constructing replacement DAG
  friend class AU_Layer;		// for constructing substitution
  friend class AU_Subproblem;		// for constructing substitution
  friend class AU_ExtensionInfo;	// for constructing matched portion
};

inline
AU_DagNode::AU_DagNode(AU_Symbol* symbol, int size)
: DagNode(symbol), argArray(size)
{
  setTheoryByte(false);
}

inline AU_Symbol*
AU_DagNode::symbol() const
{
  return static_cast<AU_Symbol*>(DagNode::symbol());
}

inline int
AU_DagNode::nrArgs() const
{
  return argArray.length();
}

inline DagNode*
AU_DagNode::getArgument(int i) const
{
  return argArray[i];
}

inline bool
AU_DagNode::producedByAssignment() const
{
  return getTheoryByte();
}

inline void
AU_DagNode::setProducedByAssignment()
{
  setTheoryByte(true);
}

#endif
