//
//	Abstract base class for dag nodes in the NA theory.
//
#ifndef _NA_DagNode_hh_
#define _NA_DagNode_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "dagNode.hh"

class NA_DagNode : public DagNode
{
public:
  NA_DagNode(NA_Symbol* symbol);
  //
  //    Functions required by theory interface.
  //
  //	The following functions are left to the derived class to handle:
  //
  //	int compareArguments(const DagNode* other) const
  //	void overwriteWithClone(DagNode* old);
  //	DagNode* makeClone();
  //
  RawDagArgumentIterator* arguments();
  DagNode* copyWithReplacement(int argIndex, DagNode* replacement);
  DagNode* copyWithReplacement(Vector<RedexPosition>& redexStack,
			       int first,
			       int last);
  void stackArguments(Vector<RedexPosition>& stack,
		      int parentIndex,
		      bool respectFrozen);

private:
  DagNode* markArguments();
  DagNode* copyEagerUptoReduced2();
  void clearCopyPointers2();
};

inline
NA_DagNode::NA_DagNode(NA_Symbol* symbol) : DagNode(symbol)
{
}

#endif
