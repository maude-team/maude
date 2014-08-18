/*
 * RealizedFairnessTable.hh
 *
 *  Created on: Sep 17, 2013
 *      Author: kquine
 */

#ifndef REALIZEDFAIRNESSTABLE_HH_
#define REALIZEDFAIRNESSTABLE_HH_
#include "AbstractFairnessTable.hh"
#include "ParamSubstitutionBuilder.hh"
#include "PropTable/ParamPropositionTable.hh"

namespace modelChecker {

class RealizedFairnessTable
{
public:
	virtual ~RealizedFairnessTable() = default;

	const ParamSubstitutionBuilder& getSubstBuilder(unsigned int fairId) const;

	const ParamSubstitution& getRealizedFairSubst(unsigned int fairId) const;

	// find the realized fair id in realizedFair (i.e.,parameter abstraction)
	unsigned int getRealizedFairId(unsigned int fairId, const NatSet& realizedFair) const;
	unsigned int insertFairnessInstance(unsigned int paramFairId, const ParamSubstitution& propSubst);

protected:
	using InstanceSubstMap = map<const ParamSubstitution,const unsigned int>;

	struct ParamInfo
	{
		ParamInfo(DagNode* fDag, const vector<unsigned int>& propIds,
				const ParamPropositionTable& pTable): builder(fDag,propIds,pTable) {}
		ParamSubstitutionBuilder builder;

		// realized substitution |-> an instance fair id  (its keys are ordered by the lexico-order)
		InstanceSubstMap substMap;
	};

	struct InstanceInfo
	{
		InstanceInfo(unsigned int pfi, const ParamSubstitution* s): paramFairId(pfi), substRef(s) {}
		const unsigned int paramFairId;			// the base param fair id
		const ParamSubstitution* substRef;		// the corresponding substitution id
		set<unsigned int> directBase;			// the set of immediate instance fair ids (in fairTable)
	};

	//
	//	client table interface
	//
	virtual ParamInfo& getParamInfo(unsigned int fairId) const = 0;
	virtual InstanceInfo* getInstanceInfo(unsigned int fairId) const = 0;
	virtual unsigned int getNextFairIndex() const = 0;
	virtual void insertInstance(unsigned int pfi, const ParamSubstitution* s) = 0;

private:

	// update the dependency map when f is newly added
	void updateInstanceBaseMap(const InstanceSubstMap& substMap, const InstanceSubstMap::const_iterator f);
};

} /* namespace modelChecker */
#endif /* REALIZEDFAIRNESSTABLE_HH_ */
