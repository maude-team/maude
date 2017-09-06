//
//	A raw transition set is a non-canonical set of transitions.
//
//	The only reason to define it is to encapsulate the (unsimplified)
//	product operation.
//
#ifndef _rawTransitionSet_hh_
#define _rawTransitionSet_hh_
#include <set>
#include "transitionSet.hh"

class RawTransitionSet : public set<Transition>
{
public:
  RawTransitionSet(const TransitionSet& transitionSet);
  RawTransitionSet(const RawTransitionSet& ts1, const RawTransitionSet& ts2);
};

#endif
