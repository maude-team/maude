//
//      Implementation for class ACU_ExtensionInfo.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "ACU_RedBlack.hh"
#include "ACU_Theory.hh"

//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"
#include "ACU_TreeDagNode.hh"
#include "ACU_ExtensionInfo.hh"

DagNode*
ACU_ExtensionInfo::buildMatchedPortion() const
{
  if (matchedWhole())
    return subject;
  //
  //	We don't try to handle ACU_TreeDagNodes in an efficient way.
  //
  ACU_DagNode* s = getACU_DagNode(subject);
  const_cast<ACU_ExtensionInfo*>(this)->useUnmatched();  // HACK
  //
  //	Count number of distinct arguments matched.
  //
  int nrArgs = s->argArray.length();
  int size = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      if (unmatchedMultiplicity[i] != s->argArray[i].multiplicity)
	++size;
    }
  Assert(size >= 1, cerr << "no matched portion");
  //
  //	Build an ACU_DagNode for the matched portion.
  //
  ACU_DagNode* n = new ACU_DagNode(s->symbol(), size);
  int p = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      int d = s->argArray[i].multiplicity - unmatchedMultiplicity[i];
      Assert(d >= 0, cerr << "multiplicity subproblem");
      if (d > 0)
	{
	  Assert(d > 1 || size > 1, cerr << "at least 2 args must be matched");
	  n->argArray[p].dagNode = s->argArray[i].dagNode;
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
    {
      if (DagNode* d = unmatched.getNode())
	e->unmatched.setNode(d);
      else
	e->unmatchedMultiplicity = unmatchedMultiplicity;  // deep copy
    }
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
    {
      if (DagNode* d = e->unmatched.getNode())
	unmatched.setNode(d);
      else
	unmatchedMultiplicity = e->unmatchedMultiplicity;  // deep copy
    }
  upperBound = e->upperBound;
}

void
ACU_ExtensionInfo::convertToUnmatched()
{
  ArgVec<ACU_DagNode::Pair>& argArray = safeCast(ACU_DagNode*, subject)->argArray;
  unmatchedMultiplicity.resize(argArray.length());
  Vector<int>::iterator j = unmatchedMultiplicity.begin();
  ArgVec<ACU_DagNode::Pair>::const_iterator i = argArray.begin();
  const ArgVec<ACU_DagNode::Pair>::const_iterator e = argArray.end();

  DagNode* d = unmatched.getNode();
  if (d->symbol() == subject->symbol())
    {
      //
      //	Unmatched stuff is an unmatched ACU_TreeDagNode.
      //
      ACU_FastIter k(safeCast(ACU_TreeDagNode*, d)->getRoot());
      d = k.getDagNode();
      for (; i != e; ++i, ++j)
	{
	  if (i->dagNode == d)
	    {
	      *j = k.getMultiplicity();
	      k.next();
	      d = k.valid() ? k.getDagNode() : 0;
	    }
	  else
	    *j = 0;
	}
      Assert(d == 0, cerr << "didn't finish unmatched ACU_TreeDagNode");
    }
  else
    {
      //
      //	Unmatched stuff is a single unmatched argument.
      //
      for (; i != e; ++i, ++j)
	{
	  if (i->dagNode == d)
	    {
	      *j = 1;
	      d = 0;
	    }
	  else
	    *j = 0;
	}
      Assert(d == 0, cerr << "didn't find single unmatched arg");
    }
  unmatched.setNode(0);
}
