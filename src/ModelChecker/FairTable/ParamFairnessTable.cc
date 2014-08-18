/*
 * ParamFairnessTable.cc
 *
 *  Created on: Sep 3, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "temporal.hh"
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "ParamFairnessTable.hh"

namespace modelChecker {

template <typename Formula>
ParamFairnessTable<Formula>::ParamFairnessTable(ParamPropositionTable& propTable):
	FairnessTable<Formula>(propTable), paramPropTableRef(propTable) {}


template <typename Formula> inline bool
ParamFairnessTable<Formula>::isParamFairness(unsigned int fairId) const
{
	return dynamic_cast<ParamFairness*>(this->fairTable[fairId].get());
}

template <typename Formula> inline bool
ParamFairnessTable<Formula>::isStateFairness(unsigned int fairId) const
{
	return Super::isStateFairness(getBaseFairId(fairId));
}

template <typename Formula> inline const Formula&
ParamFairnessTable<Formula>::getFairFormula(unsigned int fairId) const
{
	return Super::getFairFormula(getBaseFairId(fairId));
}

template <typename Formula> const ParamPropositionTable&
ParamFairnessTable<Formula>::getPropTable() const
{
	return paramPropTableRef;
}

template <typename Formula>
unique_ptr<typename ParamFairnessTable<Formula>::GroundFairness>
ParamFairnessTable<Formula>::createFormulaFairness(const Formula& f,
		const vector<unsigned int>& propIds, DagNode* fairDag) const
{
	unique_ptr<GroundFairness> gfi = Super::createFormulaFairness(f, propIds, fairDag);
	return fairDag->isGround() ?
			move(gfi) : unique_ptr<ParamFairness>(new ParamFairness(*gfi,fairDag,propIds,paramPropTableRef));
}

template <typename Formula> unsigned int
ParamFairnessTable<Formula>::getNextFairIndex() const
{
	return this->fairTable.size();
}

template <typename Formula>
typename ParamFairnessTable<Formula>::ParamInfo&
ParamFairnessTable<Formula>::getParamInfo(unsigned int fairId) const
{
	return *safeCast(ParamFairness*,this->fairTable[fairId].get());
}

template <typename Formula>
typename ParamFairnessTable<Formula>::InstanceInfo*
ParamFairnessTable<Formula>::getInstanceInfo(unsigned int fairId) const
{
	return dynamic_cast<InstanceFairnessInfo*>(this->fairTable[fairId].get());
}

template <typename Formula> void
ParamFairnessTable<Formula>::insertInstance(unsigned int pfi, const ParamSubstitution* s)
{
	this->fairTable.emplace_back(new InstanceFairnessInfo(pfi,s));
}

template <typename Formula> unsigned int
ParamFairnessTable<Formula>::getBaseFairId(unsigned int fairId) const
{
	if (InstanceFairnessInfo* ifi = dynamic_cast<InstanceFairnessInfo*>(this->fairTable[fairId].get()))
		return ifi->paramFairId;
	else
		return fairId;
}



} /* namespace modelChecker */
