//
//	Intuitively a transition set maps each valuation to a disjunction
//	of conjunctions of next states. In practice is it maintained as a set of
//		<set of states, boolean formula>
//	pairs where the truth of the boolean formula on a valuation indicates that
//	the set of states in the pair is in the disjunction for that valuation.
//
//	We have the simplification rule that for any valuation, a conjunction
//	of states in its disjunction subsumes any larger conjunction of states
//	in its disjunction.
//
//	We maintain a canonical form by storing the set of pairs as a map
//	from sets of states to formulae such that for any set Q of states, the
//	formulae is true on exactly those valuations in which Q appears as part
//	of the simplified disjunction.
//
#ifndef _transitionSet_hh_
#define _transitionSet_hh_
#include <map>
#include "natSet.hh"
#include "bdd.hh"

typedef pair<NatSet, Bdd> Transition;  // HACK

class TransitionSet
{
public:
  typedef map<NatSet, Bdd> TransitionMap;

  void insert(const Transition& transition);
  void insert(const TransitionSet& transitionSet);
  void product(const TransitionSet& ts1, const TransitionSet& ts2);
  void swap(TransitionSet& other);
  void rename(const TransitionSet& original, const Vector<int>& renaming);

  const TransitionMap& getMap() const;
  void dump(ostream& s, int indentLevel = 0) const;

private:
  TransitionMap transitionMap;
};

inline void
TransitionSet::swap(TransitionSet& other)
{
  transitionMap.swap(other.transitionMap);
}

inline const TransitionSet::TransitionMap&
TransitionSet::getMap() const
{
  return transitionMap;
}

#endif
