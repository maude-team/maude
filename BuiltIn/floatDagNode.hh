//
//	Class for dag nodes containing floating point numbers.
//
#ifndef _floatDagNode_hh_
#define _floatDagNode_hh_
#include "NA_DagNode.hh"

class FloatDagNode : public NA_DagNode
{
public:
  FloatDagNode(FloatSymbol* symbol, double value);

  size_t getHashValue();
  int compareArguments(const DagNode* other) const;
  void overwriteWithClone(DagNode* old);
  DagNode* makeClone();

  double getValue() const;

private:
  const double value;

  friend class FloatTerm;		// for comparison
};

inline double
FloatDagNode::getValue() const
{
  return value;
}

#endif
