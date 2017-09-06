//
//	Class for dag nodes containing quoted identifiers
//	(references to real identifiers).
//
#ifndef _quotedIdentifierDagNode_hh_
#define _quotedIdentifierDagNode_hh_
#include "NA_DagNode.hh"

class QuotedIdentifierDagNode : public NA_DagNode
{
public:
  QuotedIdentifierDagNode(QuotedIdentifierSymbol* symbol, int idIndex);

  size_t getHashValue();
  int compareArguments(const DagNode* other) const;
  void overwriteWithClone(DagNode* old);
  DagNode* makeClone();

  int getIdIndex() const;

private:
  NO_COPYING(QuotedIdentifierDagNode);

  const int idIndex;
};

inline int
QuotedIdentifierDagNode::getIdIndex() const
{
  return idIndex;
}

#endif
