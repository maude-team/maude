//
//	Class for DAG nodes belonging to theories made from C, Ul, Ur and I axioms.
//
#ifndef _CUI_DagNode_hh_
#define _CUI_DagNode_hh_
#include "dagNode.hh"

class CUI_DagNode : public DagNode
{
public:
  CUI_DagNode(CUI_Symbol* symbol);
  //
  //	Member functions required by theory interface.
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
  //    Functions particular to CUI_DagNode.
  //
  CUI_Symbol* symbol() const;
  DagNode* getArgument(int i) const;

private:
  //
  //	Theory interface functions.
  //
  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();
  void clearCopyPointers2();
  //
  //	Normalization functions.
  //
  void collapseTo(int argNr);
  bool normalizeAtTop();
  //
  //	Arguments under CUI symbol.
  //
  DagNode* argArray[2];
  //
  //	Slot for caching hash value.
  //
  size_t hashCache;
  //
  //	Most related classes need direct access to our argument list for efficiency.
  //
  friend class CUI_Symbol;		// to reduce subterms prior to rewrite, normalization
  friend class CUI_Term;		// for term->DAG conversion & comparison
  friend class CUI_LhsAutomaton;	// for matching DAG subject
  friend class CUI_RhsAutomaton;	// for constructing replacement DAG
};

inline
CUI_DagNode::CUI_DagNode(CUI_Symbol* symbol)
  : DagNode(symbol)
{ 
}

inline CUI_Symbol*
CUI_DagNode::symbol() const
{
  return static_cast<CUI_Symbol*>(DagNode::symbol());
}

inline DagNode*
CUI_DagNode::getArgument(int i) const
{
  Assert(i == 0 || i == 1, "bad argument index");
  return argArray[i];
}

#endif
