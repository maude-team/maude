//
//	Class for dag nodes containing strings.
//
#ifndef _stringDagNode_hh_
#define _stringDagNode_hh_
#ifdef LIBv3
#include <ext/rope>
using namespace __gnu_cxx;
#else
#include <rope>
#endif
#include "NA_DagNode.hh"

class StringDagNode : public NA_DagNode
{
public:
  StringDagNode(StringSymbol* symbol, const crope& value);

  size_t getHashValue();
  int compareArguments(const DagNode* other) const;
  void overwriteWithClone(DagNode* old);
  DagNode* makeClone();

  const crope& getValue() const;

private:
  const crope value;  // assume that sizeof(crope) <= DagNode::nrWords
};

inline const crope&
StringDagNode::getValue() const
{
  return value;
}

#endif
