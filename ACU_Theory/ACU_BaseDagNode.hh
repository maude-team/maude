//
//	Base class for DAG nodes in the AC and ACU theories.
//
#ifndef _ACU_BaseDagNode_hh_
#define _ACU_BaseDagNode_hh_
#include "dagNode.hh"

class ACU_BaseDagNode : public DagNode
{
public:
  enum NormalizationStatus
  {
    //
    //	Default: no guarantees.
    //
    FRESH,
    //
    //	Node was produced by a partial replacement after matching:
    //	(a) all arguments except the last are reduced up to strategy
    //	    of our symbol (this only holds if it was true of subject
    //	    before matching);
    //	(b) all arguments except the last have the correct sort; and
    //	(c) argument list except for last argument is in theory normal form.
    //	There is no guarantee about our sort since extension could be in
    //	the error sort.
    //
    EXTENSION,
    //
    //	Node was produced by an assignment in ACU matcher:
    //	(a) all arguments are reduced up to strategy of our symbol
    //	   (this only holds if it was true of subject before matching);
    //	(b) all arguments have the correct sort;
    //	(c) argument list in theory normal form; and
    //
    ASSIGNMENT,
    //
    //	As above but arguments are stored in a red-black (ACU_TreeDagNode)
    //	rather than in an ArgVec (ACU_DagNode).
    //
    TREE
  };

  ACU_BaseDagNode(ACU_Symbol* symbol);

  ExtensionInfo* makeExtensionInfo();
  ACU_Symbol* symbol() const;
  NormalizationStatus getNormalizationStatus() const;
  void setNormalizationStatus(NormalizationStatus status);
  bool isTree() const;
  int getSize() const;
};

inline
ACU_BaseDagNode::ACU_BaseDagNode(ACU_Symbol* symbol)
  : DagNode(symbol)
{
}

inline ACU_Symbol*
ACU_BaseDagNode::symbol() const
{
  return safeCast(ACU_Symbol*, DagNode::symbol());
}

inline ACU_BaseDagNode::NormalizationStatus
ACU_BaseDagNode::getNormalizationStatus() const
{
  return static_cast<NormalizationStatus>(getTheoryByte());
}

inline bool
ACU_BaseDagNode::isTree() const
{
  return getTheoryByte() == TREE;
}

inline void
ACU_BaseDagNode::setNormalizationStatus(NormalizationStatus status)
{
  setTheoryByte(status);
}

#endif
