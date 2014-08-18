/*
 * ParamRealizedSet.hh
 *
 *  Created on: Sep 17, 2013
 *      Author: kquine
 */

#ifndef PARAMREALIZEDSET_HH_
#define PARAMREALIZEDSET_HH_
#include "natSet.hh"
#include "FairTable/RealizedFairnessTable.hh"

namespace modelChecker {

class ParamRealizedSet
{
public:
	void setRealized(unsigned int fairId);
	bool getRealized(unsigned int fairId) const;

	void paste(const ParamRealizedSet& f);
	void merge(const ParamRealizedSet& f);

	// extend target with a fair in other
	void extend(const NatSet& other, NatSet& target, const RealizedFairnessTable& rtable) const;
	void extend(const ParamRealizedSet& other, NatSet& target, const RealizedFairnessTable& rtable) const;

	void dump(ostream& o) const;

private:
	NatSet realizedFair;	// a set of realized fair ids
};

} /* namespace modelChecker */

#endif /* PARAMREALIZEDSET_HH_ */
