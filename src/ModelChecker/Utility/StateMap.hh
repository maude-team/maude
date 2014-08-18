/*
 * StateMap.hh
 *
 *  Created on: Nov 30, 2010
 *      Author: kquine
 */

#ifndef STATEMAP_HH_
#define STATEMAP_HH_
#include <memory>
#include <unordered_map>

namespace modelChecker {

//
//	map of (systemNr, propertyNr) |-> T, where systemNr's are consecutive..
//  NOTE: we use vector, assuming that stateNr is successively increased
//
template <class T>
class StateMap
{
	using IntMap =  unordered_map<unsigned int,T>;
	using State =	pair<unsigned int,unsigned int>;

public:
	bool contains(const State& s) const;
	void set(const State& s, const T& n);
	void remove(const State& s);
	const T& get(const State& s) const;

private:
	vector<unique_ptr<IntMap> > map;		// systemNr -> propertyNr -> dfs_number
};

}

#include "StateMap.cc"

#endif /* STATEMAP_HH_ */
