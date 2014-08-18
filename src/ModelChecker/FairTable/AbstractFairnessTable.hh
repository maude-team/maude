/*
 * AbstractFairnessTable.hh
 *
 *  Created on: Sep 11, 2013
 *      Author: kquine
 */

#ifndef ABSTRACTFAIRNESSTABLE_HH_
#define ABSTRACTFAIRNESSTABLE_HH_

namespace modelChecker {

class AbstractFairnessTable
{
public:
	virtual ~AbstractFairnessTable() = default;

	virtual bool hasStrongFairness() const = 0;
	virtual unsigned int nrFairness() const = 0;
};

} /* namespace modelChecker */
#endif /* ABSTRACTFAIRNESSTABLE_HH_ */
