/*
 * StateMap.cc
 *
 *  Created on: Dec 1, 2010
 *      Author: kquine
 */

#include "StateMap.hh"

namespace modelChecker {

template <class T> inline bool
StateMap<T>::contains(const State& s) const
{
	return s.first < map.size() && map[s.first]->find(s.second) != map[s.first]->end();
}

template <class T> inline void
StateMap<T>::set(const State& s, const T& n)
{
	while (s.first >= map.size()) map.emplace_back(new IntMap);	// allocate space
	(*map[s.first])[s.second] = n;
}

template <class T> inline void
StateMap<T>::remove(const State& s)
{
	map[s.first]->erase(s.second);
}

template <class T> inline const T&
StateMap<T>::get(const State& s) const
{
	return map[s.first]->find(s.second)->second;
}

}
