//
//      Implementation for class ACU_ExtensionInfo.
//
#ifdef __GNUG__
#pragma implementation
#endif
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_Theory.hh"
 
//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_ExtensionInfo.hh"

DagNode*
ACU_ExtensionInfo::buildMatchedPortion() const
{
  if (matchedWhole())
    return subject;

  int nrArgs = subject->argArray.length();
  int size = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      if (unmatchedMultiplicity[i] != subject->argArray[i].multiplicity)
	++size;
    }
  Assert(size >= 1, cerr << "no matched portion");
  ACU_DagNode* n = new ACU_DagNode(subject->symbol(), size);
  int p = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      int d = subject->argArray[i].multiplicity - unmatchedMultiplicity[i];
      Assert(d >= 0, cerr << "multiplicity subproblem");
      if (d > 0)
	{
	  Assert(d > 1 || size > 1, cerr << "at least 2 args must be matched");
	  n->argArray[p].dagNode = subject->argArray[i].dagNode;
	  n->argArray[p].multiplicity = d;
	  ++p;
	}
    }
  return n;
}

ExtensionInfo*
ACU_ExtensionInfo::makeClone() const
{
  ACU_ExtensionInfo* e = new ACU_ExtensionInfo(subject);
  e->setValidAfterMatch(validAfterMatch());
  bool whole = matchedWhole();
  e->setMatchedWhole(whole);
  if (!whole)
    e->unmatchedMultiplicity = unmatchedMultiplicity;  // deep copy
  e->upperBound = upperBound;
  return e;
}

void
ACU_ExtensionInfo::copy(ExtensionInfo* extensionInfo)
{
  ACU_ExtensionInfo* e = static_cast<ACU_ExtensionInfo*>(extensionInfo);
  setValidAfterMatch(e->validAfterMatch());
  bool whole = e->matchedWhole();
  setMatchedWhole(whole);
  subject = e->subject;
  if (!whole)
    unmatchedMultiplicity = e->unmatchedMultiplicity;  // deep copy
  upperBound = e->upperBound;
}
