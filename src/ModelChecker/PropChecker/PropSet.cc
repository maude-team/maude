/*
 * PropSet.cc
 *
 *  Created on: Aug 26, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "PropTable/ParamPropositionTable.hh"
#include "PropSet.hh"


namespace modelChecker {

const set<const ParamSubstitution*> PropSet::emptySet;

void
PropSet::setInstance(unsigned int propId, const ParamPropositionTable& propTable)
{
	setTrue(propId);
	if (auto pmm = propTable.getParamMatches(propId))
		for (auto& j : *pmm)
			setTrueParamSubst(j.first, j.second);
}

const set<const ParamSubstitution*>&
PropSet::getTrueParamSubst(unsigned int propId) const
{
	auto it = trueParamSubstRefs.find(propId);
	return it != trueParamSubstRefs.end() ? it->second : emptySet;
}

void
PropSet::merge(const PropSet& ps)
{
	truePropIds.insert(ps.truePropIds);

	for (const auto& j : ps.trueParamSubstRefs)
		setTrueParamSubst(j.first, j.second);
}

void
PropSet::merge(unique_ptr<PropSet>& ps1, unique_ptr<PropSet>&& ps2)
{
	if (ps1)
	{
		if (ps2) ps1->merge(*ps2);
	}
	else if (ps2)
	{
		ps1 = move(ps2);
	}
}

void
PropSet::merge(unique_ptr<PropSet>& ps1, const unique_ptr<PropSet>& ps2)
{
	if (ps1)
	{
		if (ps2) ps1->merge(*ps2);
	}
	else if (ps2)
	{
		ps1.reset(new PropSet(*ps2));	// copy
	}
}

void
PropSet::dump(ostream& s)
{
	s << truePropIds << ", ";
	for (const auto& j : trueParamSubstRefs)
	{
		s << "(" << j.first << " |->";
		for (auto k : j.second)
			s<< " " << k;
		s << ") ";
	}

}



} /* namespace modelChecker */
