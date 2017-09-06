//
//	Class for argument-multiplicity pairs.
//
#ifndef _ACU_Pair_hh_
#define _ACU_Pair_hh_

class ACU_Pair
{
public:
  ACU_Pair();
  ACU_Pair(DagNode* d, int m);

  void set(DagNode* d, int m);
  DagNode* getDagNode() const;
  int getMultiplicity() const;

  /* HACK
private:
  */
  DagNode* dagNode;
  int multiplicity;
};

inline
ACU_Pair::ACU_Pair()
{
}

inline
ACU_Pair::ACU_Pair(DagNode* d, int m)
{
  dagNode = d;
  multiplicity = m;
}

inline void
ACU_Pair::set(DagNode* d, int m)
{
  dagNode = d;
  multiplicity = m;
}

inline DagNode*
ACU_Pair::getDagNode() const
{
  return dagNode;
}

inline int
ACU_Pair::getMultiplicity() const
{
  return multiplicity;
}

#endif
