/*
 * SystemGraph.hh
 *
 *  Created on: Aug 13, 2013
 *      Author: kquine
 */

#ifndef SYSTEMGRAPH_HH_
#define SYSTEMGRAPH_HH_

namespace modelChecker {

class SystemGraph
{
public:
	virtual ~SystemGraph() = default;

    virtual unsigned int getNrStates() const = 0;
    virtual unsigned int getNrTransitions(unsigned int stateNr) const = 0;

    virtual unsigned int getNrVisitedStates() const = 0;
    virtual unsigned int getNrVisitedTransitions(unsigned int stateNr) const = 0;

    virtual int getNextState(unsigned int stateNr, unsigned int index) = 0;		// return -1 if no more transitions
};


} /* namespace modelChecker */
#endif /* SYSTEMGRAPH_HH_ */
