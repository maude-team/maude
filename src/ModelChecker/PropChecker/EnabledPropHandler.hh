/*
 * EnabledPropHandler.hh
 *
 *  Created on: Aug 28, 2013
 *      Author: kquine
 */

#ifndef ENABLEDPROPHANDLER_HH_
#define ENABLEDPROPHANDLER_HH_
#include "PropTable/PropositionTable.hh"
#include "PropSet.hh"

namespace modelChecker {

class EnabledPropHandler
{
public:
	EnabledPropHandler(const vector<unsigned int>& fairEnbPropIds, const PropositionTable& propositions);
	virtual ~EnabledPropHandler() = default;

	bool isFormulaEnabled(unsigned int propId) const;

	template <typename PL, typename EL>
	bool satisfiesEnabledProp(unsigned int propId,
			const typename PL::StateLabel& sL, const vector<unique_ptr<EL>>& eventLs, const PL& propLabel) const;

	virtual unique_ptr<PropSet> computeEnabledProps(const vector<unique_ptr<PropSet>>& trueEventPropIds) const;

	bool isEnabledProp(unsigned int propId) const		{ return propositions.isEnabledProp(propId); }
	int getEnabledEventId(unsigned int propId) const	{ return propositions.getEnabledEventId(propId); }


protected:
	const vector<unsigned int> fairEnabledPropIds;
	const PropositionTable& propositions;
};


template <typename PL, typename EL> inline bool
EnabledPropHandler::satisfiesEnabledProp(unsigned int propId,
		const typename PL::StateLabel& sL, const vector<unique_ptr<EL>>& eventLs, const PL& propLabel) const
{
	if (propositions.isEnabledProp(propId))
	{
		auto evtId = propositions.getEnabledEventId(propId);
		for (auto& j : eventLs)
			if (propLabel.satisfiesEventProp(evtId, static_cast<typename PL::EventLabel&>(*j))) return true;
		return false;
	}
	return propLabel.satisfiesStateProp(propId, sL);
}

} /* namespace modelChecker */
#endif /* ENABLEDPROPHANDLER_HH_ */
