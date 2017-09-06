//
//	Class to record what parts of an ACU DAG node were not matched.
//
#ifndef _ACU_ExtensionInfo_hh_
#define _ACU_ExtensionInfo_hh_
#include "extensionInfo.hh"
#include "dagRoot.hh"

class ACU_ExtensionInfo : public ExtensionInfo
{
public:
  ACU_ExtensionInfo(ACU_BaseDagNode* subject);

  DagNode* buildMatchedPortion() const;
  ExtensionInfo* makeClone() const;
  void copy(ExtensionInfo* extensionInfo);
  //
  //	Stuff specific to ACU_ExtensionInfo.
  //

  //
  //	We (sometimes) keep track of the maximum amount of
  //	stuff we can put in the extension and still match
  //	two arguments.
  //
  void setUpperBound(int multiplicity);
  int getUpperBound() const;
  //
  //	Member functions for tracking the stuff in the extension
  //	as a dag node.
  //
  void setUnmatched(DagNode* unmatched);
  DagNode* getUnmatched() const;

  //
  //	Member functions for tracking the stuff in the
  //	extension as a vector of unmatched multiplicities.
  //
  void clear();  // setup vector and clear it
  void reset();  // setup vector without clearing it
  void useUnmatched();  // convert to unmatched form if in matched form
  void setUnmatched(int argIndex, int multiplicity);
  int getUnmatched(int argIndex) const;

private:
  void convertToUnmatched();  // HACK

  ACU_BaseDagNode* subject;
  DagRoot unmatched;
  Vector<int> unmatchedMultiplicity;
  int upperBound;
};

inline
ACU_ExtensionInfo::ACU_ExtensionInfo(ACU_BaseDagNode* subject)
  : subject(subject)
{
}

inline void
ACU_ExtensionInfo::setUpperBound(int multiplicity)
{
  upperBound = multiplicity;
}

inline int
ACU_ExtensionInfo::getUpperBound() const
{
  return upperBound;
}

inline void
ACU_ExtensionInfo::setUnmatched(DagNode* dagNode)
{
  unmatched.setNode(dagNode);
}

inline DagNode*
ACU_ExtensionInfo::getUnmatched() const
{
  return unmatched.getNode();
}

inline void
ACU_ExtensionInfo::clear()
{
  unmatched.setNode(0);
  int nrArgs = subject->getSize();
  unmatchedMultiplicity.resize(nrArgs);
  for (int i = 0; i < nrArgs; i++)
    unmatchedMultiplicity[i] = 0;
}

inline void
ACU_ExtensionInfo::reset()
{
  unmatched.setNode(0);
  unmatchedMultiplicity.resize(subject->getSize());
}

inline void
ACU_ExtensionInfo::useUnmatched()
{
  Assert(!(subject->isTree()), cerr << "tree form!");
  if (unmatched.getNode() != 0)
    convertToUnmatched();  // FIX name
}

inline void
ACU_ExtensionInfo::setUnmatched(int argIndex, int multiplicity)
{
  unmatchedMultiplicity[argIndex] = multiplicity;
}

inline int
ACU_ExtensionInfo::getUnmatched(int argIndex) const
{
  return unmatchedMultiplicity[argIndex];
}

#endif
