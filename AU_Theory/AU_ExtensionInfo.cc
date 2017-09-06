//
//      Implementation for class AU_ExtensionInfo.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "AU_Theory.hh"
 
//      A theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"
#include "AU_ExtensionInfo.hh"

DagNode*
AU_ExtensionInfo::buildMatchedPortion() const
{
  if (matchedWhole())
    return subject;
  int nrSubterms = last - first + 1;
  Assert(nrSubterms + extraIdentityFlag >= 2, "at least 2 subterms must be matched");
  return subject->makeFragment(first, nrSubterms, extraIdentityFlag);
}

ExtensionInfo*
AU_ExtensionInfo::makeClone() const
{
  AU_ExtensionInfo* e = new AU_ExtensionInfo(subject);
  e->setValidAfterMatch(validAfterMatch());
  bool whole = matchedWhole();
  e->setMatchedWhole(whole);
  if (!whole)
    {
      e->first = first;
      e->last = last;
      e->extraIdentityFlag = extraIdentityFlag;
    }
  return e;
}

void
AU_ExtensionInfo::copy(ExtensionInfo* extensionInfo)
{
  AU_ExtensionInfo* e = static_cast<AU_ExtensionInfo*>(extensionInfo);
  setValidAfterMatch(e->validAfterMatch());
  bool whole = e->matchedWhole();
  setMatchedWhole(whole);
  subject = e->subject;
  if (!whole)
    {
      first = e->first;
      last = e->last;
      extraIdentityFlag = e->extraIdentityFlag;
    }
}
