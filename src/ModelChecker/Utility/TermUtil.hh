/*
 * TermUtil.hh
 *
 *  Created on: Jul 27, 2011
 *      Author: kquine
 */

#ifndef TERMUTIL_HH_
#define TERMUTIL_HH_

namespace modelChecker {

class TermUtil
{
public:
	static Term* constructTerm(DagNode* dag);
	static bool checkGround(DagNode* dag);	// set all ground flags, and return true if it is ground.

private:
	static constexpr unsigned int nrPreallocatedArgs = 3;
};

}

#endif /* TERMUTIL_HH_ */
