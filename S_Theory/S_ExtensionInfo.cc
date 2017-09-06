//
//      Implementation for class S_ExtensionInfo.
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
#include "S_Theory.hh"
 
//      S theory class definitions
#include "S_Symbol.hh"
#include "S_DagNode.hh"
#include "S_ExtensionInfo.hh"

S_ExtensionInfo::S_ExtensionInfo(S_DagNode* subject)
  : subject(subject)
{
}

DagNode*
S_ExtensionInfo::buildMatchedPortion() const
{
  return new S_DagNode(subject->symbol(),
		       subject->getNumber() - unmatched,
		       subject->getArgument());
}

ExtensionInfo* 
S_ExtensionInfo::makeClone() const
{
  S_ExtensionInfo* n = new S_ExtensionInfo(subject);
  n->unmatched = unmatched;
  return n;
}

void
S_ExtensionInfo::copy(ExtensionInfo* extensionInfo)
{
  S_ExtensionInfo* e = safeCast(S_ExtensionInfo*, extensionInfo);
  subject = e->subject;
  unmatched = e->unmatched;
}
