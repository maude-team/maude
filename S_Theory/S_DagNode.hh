//
//	Class for DAG nodes in the successor theory.
//
#ifndef _S_DagNode_hh_
#define _S_DagNode_hh_
#include <gmpxx.h>
#include "dagNode.hh"

class S_DagNode : public DagNode
{
  NO_COPYING(S_DagNode);

public:
  S_DagNode(S_Symbol* symbol, const mpz_class& number, DagNode* arg);
  ~S_DagNode();
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
  //	Functions specific to S_DagNode.
  //
  S_Symbol* symbol() const;
  const mpz_class& getNumber() const;
  DagNode* getArgument() const;

private:
  //
  //	Functions required by theory interface.
  //
  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();
  void clearCopyPointers2();
  //
  //	Normalization functions.
  //
  void normalizeAtTop();

  mpz_class* number;
  DagNode* arg;
  
  friend class S_Symbol;           	// to reduce subterms prior to rewrite, normalization
};

inline S_Symbol*
S_DagNode::symbol() const
{
  return safeCast(S_Symbol*, DagNode::symbol());
}

inline const mpz_class&
S_DagNode::getNumber() const
{
  return *number;
}

inline DagNode*
S_DagNode::getArgument() const
{
  return arg;
}

#endif
