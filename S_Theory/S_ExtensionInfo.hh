//
//	Class to record what part of an S_DagNode was not matched.
//
#ifndef _S_ExtensionInfo_hh_
#define _S_ExtensionInfo_hh_
#include <gmpxx.h>
#include "extensionInfo.hh"

class S_ExtensionInfo : public ExtensionInfo
{
public:
  S_ExtensionInfo(S_DagNode* subject);
  //
  //	Member functions required by theory interface.
  //
  DagNode* buildMatchedPortion() const;
  ExtensionInfo* makeClone() const;
  void copy(ExtensionInfo* extensionInfo);
  //
  //	S_ExtensionInfo specific member functions.
  //
  void setUnmatched(const mpz_class& number);
  const mpz_class& getUnmatched() const;

private:
  S_DagNode* subject;
  mpz_class unmatched;
};

inline void
S_ExtensionInfo::setUnmatched(const mpz_class& number)
{
  unmatched = number;
}

inline const mpz_class&
S_ExtensionInfo::getUnmatched() const
{
  return unmatched;
}

#endif
