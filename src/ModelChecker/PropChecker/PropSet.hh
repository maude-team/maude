/*
 * PropSet.hh
 *
 *  Created on: Aug 26, 2013
 *      Author: kquine
 */

#ifndef PROPSET_HH_
#define PROPSET_HH_
#include "natSet.hh"
#include "PropTable/ParamPropositionTable.hh"

namespace modelChecker {

class PropSet
{
public:
	bool isTrue(unsigned int propId) const		{ return truePropIds.contains(propId); }
	const NatSet& getTruePropIds() const		{ return truePropIds; }
	void setTrue(unsigned int propId)			{ truePropIds.insert(propId); }

	void setInstance(unsigned int propId, const ParamPropositionTable& propTable);

	template <typename T> void setTrueParamSubst(unsigned int propId, const T& substs);
	const set<const ParamSubstitution*>& getTrueParamSubst(unsigned int propId) const;

	static void merge(unique_ptr<PropSet>& ps1, unique_ptr<PropSet>&& ps2);
	static void merge(unique_ptr<PropSet>& ps1, const unique_ptr<PropSet>& ps2);

	void dump(ostream& s);

private:
	void merge(const PropSet& ps);

	NatSet truePropIds;
	map<unsigned int,set<const ParamSubstitution*>> trueParamSubstRefs;	// paramId |-> a set of its realized substitutions

	static const set<const ParamSubstitution*> emptySet;
};

template <typename T> inline void
PropSet::setTrueParamSubst(unsigned int propId, const T& substIds)
{
	trueParamSubstRefs[propId].insert(substIds.begin(), substIds.end());
}

} /* namespace modelChecker */
#endif /* PROPSET_HH_ */
