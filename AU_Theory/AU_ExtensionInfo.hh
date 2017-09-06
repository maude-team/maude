//
//	Class to record what part of an AU theory dag node was matched.
//
#ifndef _AU_ExtensionInfo_hh_
#define _AU_ExtensionInfo_hh_
#include "extensionInfo.hh"

class AU_ExtensionInfo : public ExtensionInfo
{
public:
  AU_ExtensionInfo(AU_DagNode* subject);
  DagNode* buildMatchedPortion() const;
  ExtensionInfo* makeClone() const;
  void copy(ExtensionInfo* extensionInfo);

  void setFirstMatched(int firstMatched);
  void setLastMatched(int lastMatched);
  void setExtraIdentity(bool flag);
  int firstMatched() const;
  int lastMatched() const;
  bool bigEnough() const;

private:
  AU_DagNode* subject;
  int first;
  int last;
  bool extraIdentityFlag;  // portion matched contains an identity not present in subject.
};

inline
AU_ExtensionInfo::AU_ExtensionInfo(AU_DagNode* subject)
  : subject(subject)
{
}

inline void
AU_ExtensionInfo::setFirstMatched(int firstMatched)
{
  first = firstMatched;
}

inline void
AU_ExtensionInfo::setLastMatched(int lastMatched)
{
  last = lastMatched;
  setMatchedWhole(first == 0 && last == subject->argArray.length() - 1);
}

inline void
AU_ExtensionInfo::setExtraIdentity(bool flag)
{
  extraIdentityFlag =  flag;
}

inline int
AU_ExtensionInfo::firstMatched() const
{
  return first;
}

inline int
AU_ExtensionInfo::lastMatched() const
{
  return last;
}

inline bool
AU_ExtensionInfo::bigEnough() const
{
  return last - first + 1 + extraIdentityFlag >= 2;
}

#endif
