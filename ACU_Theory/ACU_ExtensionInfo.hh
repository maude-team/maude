//
//	Class to record what parts of an ACU DAG node were not matched.
//
#ifndef _ACU_ExtensionInfo_hh_
#define _ACU_ExtensionInfo_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "extensionInfo.hh"

class ACU_ExtensionInfo : public ExtensionInfo
{
public:
  ACU_ExtensionInfo(ACU_DagNode* subject);
  DagNode* buildMatchedPortion() const;
  ExtensionInfo* makeClone() const;
  void copy(ExtensionInfo* extensionInfo);

  void setUnmatched(int argIndex, int multiplicity);
  int getUnmatched(int argIndex) const;
  void setUpperBound(int multiplicity);
  int getUpperBound() const;
  void clear();
  void reset();

private:
  ACU_DagNode* subject;
  Vector<int> unmatchedMultiplicity;
  int upperBound;
};

inline
ACU_ExtensionInfo::ACU_ExtensionInfo(ACU_DagNode* subject)
  : subject(subject)
{
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
ACU_ExtensionInfo::clear()
{
  int nrArgs = subject->argArray.length();
  unmatchedMultiplicity.resize(nrArgs);
  for (int i = 0; i < nrArgs; i++)
    unmatchedMultiplicity[i] = 0;
}

inline void
ACU_ExtensionInfo::reset()
{
  unmatchedMultiplicity.resize(subject->argArray.length());
}

#endif
