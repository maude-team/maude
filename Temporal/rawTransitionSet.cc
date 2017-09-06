//
//	Implementation for class RawTransitionSet.
//
#ifdef __GNUG__
#pragma implementation
#endif
#include <algorithm>

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	temporal class definitions
#include "rawTransitionSet.hh"

RawTransitionSet::RawTransitionSet(const TransitionSet& transitionSet)
{
  const TransitionSet::TransitionMap& tm = transitionSet.getMap();
  copy(tm.begin(), tm.end(), inserter(*this, begin()));
}

RawTransitionSet::RawTransitionSet(const RawTransitionSet& ts1, const RawTransitionSet& ts2)
{
  //
  //	Construct the raw product of the two argument transition sets.
  //
  const const_iterator ie = ts1.end();
  const const_iterator je = ts2.end();
  Transition newTransition;
  for (const_iterator i = ts1.begin(); i != ie; ++i)
    {
      for (const_iterator j = ts2.begin(); j != je; ++j)
	{
	  newTransition.second = bdd_and(i->second, j->second);
	  if (newTransition.second != bdd_false())
	    {
	      newTransition.first = i->first;
	      newTransition.first.insert(j->first);
	      insert(newTransition);
	    }
	}
    }
}
