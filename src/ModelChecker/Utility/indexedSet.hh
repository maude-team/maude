/*
 * indexedSet.hh
 *
 *  Created on: Aug 29, 2013
 *      Author: kquine
 */

#ifndef INDEXEDSET_HH_
#define INDEXEDSET_HH_
#include <map>
#include <vector>

namespace modelChecker {

/*
 * a newer version of the existing indexed set
 */
template<typename T>
class indexed_set
{
public:
	using EltMap = 			map<T,unsigned int>;
	using iterator =		typename EltMap::iterator;
	using const_iterator =	typename EltMap::const_iterator;
	using size_type =		typename vector<const_iterator>::size_type;

	indexed_set() = default;
	~indexed_set() = default;

	indexed_set(indexed_set&&) noexcept;
	indexed_set& operator=(indexed_set&&) noexcept;	// move

	const T& operator[](size_type i) const;
	T& operator[](size_type i);

	iterator begin();
	const_iterator begin() const noexcept;
	iterator end();
	const_iterator end() const noexcept;

	const_iterator find(const T& element) const;
	iterator find(T& element);

	pair<size_type,bool> insert(const T& element);
	void swap(indexed_set& other);

	size_type size() const;
	void clear();

private:
	EltMap eltMap;
	vector<typename EltMap::const_iterator> indexMap;
};

template<typename T>
indexed_set<T>::indexed_set(indexed_set&& other) noexcept:
	eltMap(std::move(other.eltMap)), indexMap(std::move(other.indexMap)) {}

template<typename T>
inline indexed_set<T>&
indexed_set<T>::operator=(indexed_set&& other) noexcept
{
	eltMap = std::move(other.eltMap);
	indexMap = std::move(other.indexMap);
	return *this;
}

template<typename T> inline const T&
indexed_set<T>::operator[](size_type i) const
{
	return indexMap[i]->first;
}

template<typename T> inline T&
indexed_set<T>::operator[](size_type i)
{
	return indexMap[i]->first;
}

template<typename T>
inline typename indexed_set<T>::const_iterator
indexed_set<T>::begin() const noexcept
{
	return eltMap.begin();
}

template<typename T>
inline typename indexed_set<T>::const_iterator
indexed_set<T>::end() const noexcept
{
	return eltMap.end();
}

template<typename T> inline typename indexed_set<T>::iterator
indexed_set<T>::begin()
{
	return eltMap.begin();
}

template<typename T>
inline typename indexed_set<T>::iterator
indexed_set<T>::end()
{
	return eltMap.end();
}

template<typename T>
inline typename indexed_set<T>::const_iterator
indexed_set<T>::find(const T& element) const
{
	return eltMap.find(element);
}

template<typename T>
inline typename indexed_set<T>::iterator
indexed_set<T>::find(T& element)
{
	return eltMap.find(element);
}

template<typename T>
inline pair<typename indexed_set<T>::size_type,bool>
indexed_set<T>::insert(const T& element)
{
	pair<typename EltMap::iterator,bool> p = eltMap.insert(typename EltMap::value_type(element,indexMap.size()));
	if (p.second)
		indexMap.push_back(p.first);
	return make_pair(p.first->second,p.second);
}

template<typename T> inline void
indexed_set<T>::swap(indexed_set& other)
{
	indexMap.swap(other.indexMap);
	eltMap.swap(other.eltMap);
}

template<typename T>
inline typename indexed_set<T>::size_type
indexed_set<T>::size() const
{
	return indexMap.size();
}

template<typename T> inline void
indexed_set<T>::clear()
{
	indexMap.clear();
	eltMap.clear();
}


} /* namespace modelChecker */
#endif /* INDEXEDSET_HH_ */
