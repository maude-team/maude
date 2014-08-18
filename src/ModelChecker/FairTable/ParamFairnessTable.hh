/*
 * ParamFairnessTable.hh
 *
 *  Created on: Sep 3, 2013
 *      Author: kquine
 */

#ifndef PARAMFAIRNESSTABLE_HH_
#define PARAMFAIRNESSTABLE_HH_
#include "FairnessTable.hh"
#include "RealizedFairnessTable.hh"

namespace modelChecker {

template <typename Formula> class ParamFairnessTable;

using ParamWeakFairnessTable =		ParamFairnessTable<Bdd>;
using ParamStrongFairnessTable =	ParamFairnessTable<pair<Bdd,Bdd>>;

template <typename Formula>
class ParamFairnessTable: public FairnessTable<Formula>, public RealizedFairnessTable
{
	using Super 			= FairnessTable<Formula>;
	using Fairness 			= typename Super::Fairness;
	using GroundFairness 	= typename Super::GroundFairness;
public:
	ParamFairnessTable(ParamPropositionTable& propTable);

	bool isParamFairness(unsigned int fairId) const override;
	bool isStateFairness(unsigned int fairId) const override;

	const ParamPropositionTable& getPropTable() const;
	const Formula& getFairFormula(unsigned int fairId) const override;

private:
	struct ParamFairness: public GroundFairness, public RealizedFairnessTable::ParamInfo
	{
		ParamFairness(const GroundFairness& fi, DagNode* fDag,
				const vector<unsigned int>& propIds, const ParamPropositionTable& pTable):
			GroundFairness(fi), ParamInfo(fDag,propIds,pTable) {}
	};
	struct InstanceFairnessInfo: public Fairness, public RealizedFairnessTable::InstanceInfo
	{
		InstanceFairnessInfo(unsigned int pfi, const ParamSubstitution* s): InstanceInfo(pfi, s) {}
	};

	unique_ptr<GroundFairness> createFormulaFairness(const Formula& f,
			const vector<unsigned int>& propIds, DagNode* fairDag) const override;

	unsigned int getNextFairIndex() const;
	typename ParamFairnessTable<Formula>::ParamInfo& getParamInfo(unsigned int fairId) const override;
	typename ParamFairnessTable<Formula>::InstanceInfo* getInstanceInfo(unsigned int fairId) const override;
	void insertInstance(unsigned int pfi, const ParamSubstitution* s) override;

	unsigned int getBaseFairId(unsigned int fairId) const;

	const ParamPropositionTable& paramPropTableRef;
};

} /* namespace modelChecker */

#include "ParamFairnessTable.cc"

#endif /* PARAMFAIRNESSTABLE_HH_ */
