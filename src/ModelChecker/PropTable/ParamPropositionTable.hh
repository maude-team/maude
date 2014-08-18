/*
 * ParamPropositionTable.hh
 *
 *  Created on: Aug 23, 2013
 *      Author: kquine
 */

#ifndef PARAMPROPOSITIONTABLE_HH_
#define PARAMPROPOSITIONTABLE_HH_
#include <map>
#include "pattern.hh"
#include "PropTable/PropositionTable.hh"
#include "ParamSubstitution.hh"

namespace modelChecker {

class ParamPropositionTable: public PropositionTable
{
public:
	using MatchingInfo 	= pair<unsigned int,vector<const ParamSubstitution*>>;

	explicit ParamPropositionTable(const PropInterpreter& pi);

	bool hasParamProp() const override;
	bool isParamProp(unsigned int propId) const override;

	unsigned int getParamNrVars(unsigned int propId) const;
	Term* getParamVariable(unsigned int propId, unsigned int varId) const;

	const vector<MatchingInfo>* getParamMatches(unsigned int propId) const;

	int insertInstanceAndUpdate(DagNode* propDag, RewritingContext& parentContext);

private:
	struct ptr_compare
	{
		bool operator()(const unique_ptr<ParamSubstitution>& a, decltype(a) b) const { return *a < *b; }
	};

	struct ParamInfo
	{
		explicit ParamInfo(Term* t): pattern(new Pattern(t,false)) {}

		const unique_ptr<Pattern> pattern;
		set<unique_ptr<ParamSubstitution>,ptr_compare> substitutions;
	};

	struct InstancePropInfo: public PropInfo
	{
		InstancePropInfo(const PropInfo& opi): PropInfo(opi) {}
		vector<MatchingInfo> matchingPropNSubstRefs;
	};

	struct ParamPropInfo: public PropInfo
	{
		ParamPropInfo(const PropInfo& opi, unsigned int paramInfoId): PropInfo(opi), paramInfoId(paramInfoId) {}
		const unsigned int paramInfoId;
	};

	void updatePropInfo(unsigned int propId) override;
	map<unsigned int,set<const ParamSubstitution*>> computeMatchingProps(DagNode* propDag, RewritingContext& parentContext);
	vector<ParamPropositionTable::MatchingInfo> compact(const map<unsigned int,set<const ParamSubstitution*>>& match) const;

	const ParamPropInfo* getParamPropInfo(unsigned int propId) const;
	const InstancePropInfo* getInstancePropInfo(unsigned int propId) const;

	vector<unique_ptr<ParamInfo>> paramInfoTable;

	// top symbol |-> a set of the corresponding param prop ids
	map<const Symbol*,vector<unsigned int> > paramPropSymbolMap;
};


inline const ParamPropositionTable::ParamPropInfo*
ParamPropositionTable::getParamPropInfo(unsigned int propId) const
{
	return dynamic_cast<const ParamPropInfo*>(propInfoTable[propId].get());
}

inline const ParamPropositionTable::InstancePropInfo*
ParamPropositionTable::getInstancePropInfo(unsigned int propId) const
{
	return dynamic_cast<const InstancePropInfo*>(propInfoTable[propId].get());
}

} /* namespace modelChecker */
#endif /* PARAMPROPOSITIONTABLE_HH_ */
