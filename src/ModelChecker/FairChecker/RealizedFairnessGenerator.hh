/*
 * RealizedFairnessGenerator.hh
 *
 *  Created on: Sep 8, 2013
 *      Author: kquine
 */

#ifndef REALIZEDFAIRNESSGENERATOR_HH_
#define REALIZEDFAIRNESSGENERATOR_HH_
#include "Utility/BddUtil.hh"
#include "FairTable/RealizedFairnessTable.hh"
#include "FairSet/ParamRealizedSet.hh"

namespace modelChecker {

class RealizedFairnessGenerator
{
public:
	RealizedFairnessGenerator(const vector<unsigned int>& paramFairIds, RealizedFairnessTable& fairTable);

	deque<pair<unsigned int,NatSet>> generateRealizedFairness(const PropSet& ps);

private:
	const vector<unsigned int> paramFairIds;
	RealizedFairnessTable& fairTable;
};


} /* namespace modelChecker */

#endif /* REALIZEDFAIRNESSGENERATOR_HH_ */
