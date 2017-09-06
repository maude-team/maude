//
//	Fast inlined sort computation function.
//
#ifndef _symbol2_hh_
#define _symbol2_hh_
#ifdef __GNUG__
#pragma interface
#endif

inline void
Symbol::fastComputeTrueSort(DagNode* subject, RewritingContext& context)
{
  int t = uniqueSortIndex;
  if (t < 0)
    computeBaseSort(subject);  // usual case
  else if (t > 0)
    subject->setSortIndex(t);  // unique sort case
  else
    slowComputeTrueSort(subject, context);  // most general case
}

#endif
