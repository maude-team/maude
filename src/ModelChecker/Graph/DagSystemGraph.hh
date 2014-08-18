/*
 * DagSystemGraph.hh
 *
 *  Created on: Sep 10, 2013
 *      Author: kquine
 */

#ifndef DAGSYSTEMGRAPH_HH_
#define DAGSYSTEMGRAPH_HH_
#include "SystemGraph.hh"

namespace modelChecker {

class DagSystemGraph: public SystemGraph
{
public:
	virtual DagNode* getStateDag(unsigned int stateNr) const = 0;
	virtual DagNode* getTransitionDag(unsigned int stateNr, unsigned int index) const = 0;
};

} /* namespace modelChecker */
#endif /* DAGSYSTEMGRAPH_HH_ */
