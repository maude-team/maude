//
//      Class for holding position information of a potential redex
//
#ifndef _redexPosition_hh_
#define _redexPosition_hh_

class RedexPosition
{
public:
  RedexPosition() {}
  RedexPosition(DagNode* node, int parentIndex, int argIndex);
  RedexPosition(DagNode* node, int parentIndex, int argIndex, bool eager);
  
  DagNode* node() const;
  int parentIndex() const;
  int argIndex() const;
  void replaceNode(DagNode* newNode);
  void setStale();
  void clearStale();
  bool isStale() const;
  bool isEager() const;

private:
  enum Flags
  {
    STALE = 1,
    EAGER = 2
  };

  DagNode* dagNode;
  int pIndex;
  int aIndex;
  int flags;
};

inline
RedexPosition::RedexPosition(DagNode* node, int parentIndex, int argIndex)
  : dagNode(node),
    pIndex(parentIndex),
    aIndex(argIndex),
    flags(0)
{
}

inline
RedexPosition::RedexPosition(DagNode* node, int parentIndex, int argIndex, bool eager)
  : dagNode(node),
    pIndex(parentIndex),
    aIndex(argIndex),
    flags(eager ? EAGER : 0)
{
}

inline DagNode*
RedexPosition::node() const
{
  return dagNode;
}

inline int
RedexPosition::parentIndex() const
{
  return pIndex;
}

inline int
RedexPosition::argIndex() const
{
  return aIndex;
}

inline void
RedexPosition::replaceNode(DagNode* newNode)
{
  dagNode = newNode;
}

inline void
RedexPosition::setStale()
{
  flags |= STALE;
}

inline void
RedexPosition::clearStale()
{
  flags &= ~STALE;
}

inline bool
RedexPosition::isStale() const
{
  return flags & STALE;
}

inline bool
RedexPosition::isEager() const
{
  return flags & EAGER;
}

#endif
