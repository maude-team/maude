/*
 * CompositeFairnessTable.hh
 *
 *  Created on: Sep 12, 2013
 *      Author: kquine
 */

#ifndef COMPOSITEFAIRNESSTABLE_HH_
#define COMPOSITEFAIRNESSTABLE_HH_
#include <memory>
#include <vector>
#include "AbstractFairnessTable.hh"

namespace modelChecker {

class CompositeFairnessTable: public AbstractFairnessTable
{
public:
	bool hasStrongFairness() const override;
	unsigned int nrFairness() const override;

	unsigned int nrComponents() const;
	void addComponent(unique_ptr<AbstractFairnessTable>&& table);
	AbstractFairnessTable& getComponent(unsigned int i) const;

private:
	vector<unique_ptr<AbstractFairnessTable>> fairTables;	// own the tables!
};

} /* namespace modelChecker */
#endif /* COMPOSITEFAIRNESSTABLE_HH_ */
