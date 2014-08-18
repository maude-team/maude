/*
 * ptr_set.hh
 *
 *  Created on: Jul 26, 2014
 *      Author: kquine
 */

template <typename T>
struct ptr_compare
{
	bool operator() (const T* a, const T* b) const	{ return (*a) < (*b); }
};

template <typename T>
using ptr_set = set<T*,ptr_compare<T>>;
