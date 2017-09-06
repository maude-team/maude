//
//	Implementation for class TransitionSet.
//
#ifdef __GNUG__
#pragma implementation
#endif
#include <set>

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"
#include "bddUser.hh"  // for dump()

//	temporal class definitions
#include "transitionSet.hh"

void 
TransitionSet::insert(const Transition& transition)
{
  Bdd formula = transition.second;
  if (formula == bdd_false())
    return;  // for robustness
  const TransitionMap::iterator e = transitionMap.end();
  TransitionMap::iterator equal = e;
  for (TransitionMap::iterator i = transitionMap.begin(); i != e;)
    {
      TransitionMap::iterator t = i++;
      if (t->first == transition.first)
	equal = t;
      else if (t->first.contains(transition.first))
	{
	  t->second = bdd_and(t->second, bdd_not(formula));
	  if (t->second == bdd_false())
	    transitionMap.erase(t);  // existing pair completely subsumed
	}
      else if (transition.first.contains(t->first))
	{
	  formula = bdd_and(formula, bdd_not(t->second));
	  if (formula == bdd_false())
	    return;  // new transition completely subsumed
	}
    }
  if (equal == e)
    {
      pair<TransitionMap::iterator, bool> p = transitionMap.insert(transition);
      Assert(p.second, cerr << "failed to insert");
      p.first->second = formula;
    }
  else
    equal->second = bdd_or(equal->second, formula);
}

void
TransitionSet::insert(const TransitionSet& transitionSet)
{
  const TransitionMap::const_iterator e = transitionSet.transitionMap.end();
  for (TransitionMap::const_iterator i = transitionSet.transitionMap.begin(); i != e; ++i)
    insert(*i);
}

void
TransitionSet::product(const TransitionSet& ts1, const TransitionSet& ts2)
{
  transitionMap.clear();
  const TransitionMap::const_iterator ie = ts1.transitionMap.end();
  const TransitionMap::const_iterator je = ts2.transitionMap.end();
  Transition newTransition;
  for (TransitionMap::const_iterator i = ts1.transitionMap.begin(); i != ie; ++i)
    {
      for (TransitionMap::const_iterator j = ts2.transitionMap.begin(); j != je; ++j)
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

void
TransitionSet::rename(const TransitionSet& original, const Vector<int>& renaming)
{
  //
  //	Renaming must be injective: no two old states must map to
  //	the name new state. We make use of that to do a fast insertion
  //	of the renamed state sets.
  //
  transitionMap.clear();
  const TransitionMap::const_iterator ei = original.transitionMap.end();
  for (TransitionMap::const_iterator i = original.transitionMap.begin(); i != ei; ++i)
    {
      Transition t;
      const NatSet::const_iterator ej = i->first.end();
      for (NatSet::const_iterator j  = i->first.begin(); j != ej; ++j)
	{
	  Assert(renaming[*j] != NONE, cerr << "no renaming for " << *j);
	  t.first.insert(renaming[*j]);
	}
      t.second = i->second;
      transitionMap.insert(t);
    }
}

void
TransitionSet::dump(ostream& s, int indentLevel) const
{
  const TransitionMap::const_iterator e = transitionMap.end();
  for (TransitionMap::const_iterator i = transitionMap.begin(); i != e; ++i)
    {
      s << Indent(indentLevel) << i->first << '\t';
      BddUser::dump(s, i->second);
      s << '\n';
    }
}
