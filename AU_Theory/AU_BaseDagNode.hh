//
//	Base class for DAG nodes in the A, AU, AUl and theories.
//
#ifndef _AU_BaseDagNode_hh_
#define _AU_BaseDagNode_hh_
#include "dagNode.hh"

class AU_BaseDagNode : public DagNode
{
  NO_COPYING(AU_BaseDagNode);

public:
  enum NormalizationStatus
  {
    //
    //	Default: no guarantees.
    //
    FRESH,
    //
    //	Node was produced by an assignment in AU matcher:
    //	(a) all arguments are reduced up to strategy of our symbol
    //	   (this only holds if it was true of subject before matching);
    //	(b) all arguments have their true sort; and
    //	(c) argument list in theory normal form.
    //
    ASSIGNMENT,
    //
    //	As above but arguments are stored in a deque (AU_DequeNode)
    //	rather than in an ArgVec (AU_DagNode).
    //
    DEQUE
  };

  AU_BaseDagNode(AU_Symbol* symbol);

  AU_Symbol* symbol() const;
  NormalizationStatus getNormalizationStatus() const;
  void setNormalizationStatus(NormalizationStatus status);
  bool isDeque() const;
  bool isFresh() const;
};

inline
AU_BaseDagNode::AU_BaseDagNode(AU_Symbol* symbol)
  : DagNode(symbol)
{
}

inline AU_Symbol*
AU_BaseDagNode::symbol() const
{
  return safeCast(AU_Symbol*, DagNode::symbol());
}

inline AU_BaseDagNode::NormalizationStatus
AU_BaseDagNode::getNormalizationStatus() const
{
  return static_cast<NormalizationStatus>(getTheoryByte());
}

inline bool
AU_BaseDagNode::isDeque() const
{
  return getTheoryByte() == DEQUE;
}

inline bool
AU_BaseDagNode::isFresh() const
{
  return getTheoryByte() == FRESH;
}

inline void
AU_BaseDagNode::setNormalizationStatus(NormalizationStatus status)
{
  setTheoryByte(status);
}

#endif
