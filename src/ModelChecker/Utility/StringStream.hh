/*
 * StringStream.hh
 *
 *  Created on: Sep 8, 2013
 *      Author: kquine
 */

#ifndef STRINGSTREAM_HH_
#define STRINGSTREAM_HH_
#include <sstream>

namespace modelChecker {

//
// from: http://stackoverflow.com/questions/303562/c-format-macro-inline-ostringstream
//
class StringStream
{
public:
	operator std::string() const 			{ return stream.str(); }

	template <typename T>
	StringStream& operator<<(const T& v)	{ stream << v; return *this; }

private:
	std::stringstream stream;
};



} /* namespace modelChecker */
#endif /* STRINGSTREAM_HH_ */
