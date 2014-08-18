/*
 * ParamSubstitutionBuilder.hh
 *
 *  Created on: Aug 29, 2013
 *      Author: kquine
 */

#ifndef PARAMSUBSTITUTIONBUILDER_HH_
#define PARAMSUBSTITUTIONBUILDER_HH_
#include "variableDagNode.hh"
#include "Utility/indexedSet.hh"
#include "PropTable/ParamPropositionTable.hh"
#include "PropChecker/PropSet.hh"
#include "ParamVarInfo.hh"

namespace modelChecker {

class RealizedFairnessTable;	// forward declaration

class ParamSubstitutionBuilder: private ParamVarInfo
{
public:
	ParamSubstitutionBuilder(DagNode* fairnessDag, const vector<unsigned int>& propIds,
			const ParamPropositionTable& propTable);

	// returns a set of realized fairness ids and their truth values
	void buildRealizedFairness(const PropSet& ps, unsigned int paramPropId,
			RealizedFairnessTable& rftable, deque<pair<unsigned int,NatSet>>& result) const;

	void dumpParamSubst(const ParamSubstitution& s) const;
	void dumpPropSubst(unsigned int propId, const ParamSubstitution& s) const;

private:
	struct PropVarInfo
	{
		PropVarInfo(unsigned int propId, const ParamPropositionTable& propTable, const ParamVarInfo& varInfo);
		const unsigned int propId;
		vector<unsigned int> varMap;	// local var id -> global var id
	};

	using PropInfoPos = vector<unique_ptr<PropVarInfo>>::const_iterator;

	void computeParamSubstitutions(const PropInfoPos i, ParamSubstitution& t, const PropSet& ps, bool ever,
			unsigned int paramPropId, RealizedFairnessTable& rftable, set<unsigned int>& result) const;

	// returns a true param props for a given param substitution
	NatSet trueParamProps(const PropSet& ps, const ParamSubstitution& subst) const;

	vector<unique_ptr<PropVarInfo>> pidInfo;		// an "ordered" list of "param" prop ids
	const ParamPropositionTable& propTable;
};

} /* namespace modelChecker */
#endif /* PARAMSUBSTITUTIONBUILDER_HH_ */
