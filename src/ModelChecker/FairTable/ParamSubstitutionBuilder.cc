/*
 * ParamSubstitutionBuilder.cc
 *
 *  Created on: Aug 29, 2013
 *      Author: kquine
 */

//      utility stuff
#include <memory>
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "FairTable/RealizedFairnessTable.hh"
#include "ParamSubstitutionBuilder.hh"

namespace modelChecker {

ParamSubstitutionBuilder::ParamSubstitutionBuilder(DagNode* fairnessDag,
		const vector<unsigned int>& propIds, const ParamPropositionTable& propTable):
				ParamVarInfo(fairnessDag), propTable(propTable)
{
	for (auto p : propIds)
		if (propTable.isParamProp(p))
			pidInfo.emplace_back(new PropVarInfo(p, propTable, *this));

	// sorted by a number of vars
	sort(pidInfo.begin(), pidInfo.end(),
			[](const unique_ptr<PropVarInfo>& a, decltype(a) b) { return a->varMap.size() > b->varMap.size(); });
}

void
ParamSubstitutionBuilder::buildRealizedFairness(const PropSet& ps, unsigned int paramPropId,
		RealizedFairnessTable& rftable, deque<pair<unsigned int,NatSet>>& result) const
{
	set<unsigned int> fids;
	ParamSubstitution t(ParamVarInfo::getNrVariables());
	computeParamSubstitutions(pidInfo.cbegin(), t, ps, false, paramPropId, rftable, fids);

	for (auto& fi : fids)
		result.emplace_back(fi, trueParamProps(ps, rftable.getRealizedFairSubst(fi)));
}

void
ParamSubstitutionBuilder::computeParamSubstitutions(const PropInfoPos i, ParamSubstitution& t, const PropSet& ps,
		bool ever, unsigned int paramPropId, RealizedFairnessTable& rftable, set<unsigned int>& result) const
{
	if (i != pidInfo.cend())
	{
		const ParamSubstitution orig(t, (*i)->varMap);
		const bool total = orig.isTotal();

		for (auto target : ps.getTrueParamSubst((*i)->propId))
		{
			if ( target->isConsistent(orig) )
			{
				t.setSubst((*i)->varMap, *target);
				computeParamSubstitutions(i + 1, t, ps, true, paramPropId, rftable, result);

				if (total) break; 	// no need to compute more if old is total (i.e., no 'bot')
			}
		}
		t.setSubst((*i)->varMap, orig);	// the "bottom" case; backtrack always happens with the initial value
		computeParamSubstitutions(i + 1, t, ps, ever, paramPropId, rftable, result);
	}
	else
	{
		if (ever)
		{
			// add the realized fairness into the table except for the empty case;
			// directly add it to the table to avoid a redundant comparison "<"
			auto fi = rftable.insertFairnessInstance(paramPropId,t);
			result.insert(fi);
		}
	}
}

NatSet
ParamSubstitutionBuilder::trueParamProps(const PropSet& ps, const ParamSubstitution& subst) const
{
	NatSet result;
	for (auto& pi : pidInfo)
	{
		const ParamSubstitution propSubst(subst, pi->varMap);
		if (propSubst.isTotal())
		{
			for (auto i : ps.getTrueParamSubst(pi->propId))	//FIXME: the size of getTrueParamSubst should be small.
				if (propSubst == *i)
				{
					//dumpPropSubst(pi->propId, propSubst);
					result.insert(pi->propId);
				}
		}
	}
	return result;
}

void
ParamSubstitutionBuilder::dumpParamSubst(const ParamSubstitution& s) const
{
	cout << "{ ";
	for (unsigned int i = 0; i < s.getSubst().size(); ++i)
	{
		cout << "[" << static_cast<DagNode*>(this->index2Variable(i)) << " = ";
		if (s.getSubst()[i])
			cout << s.getSubst()[i];
		else
			cout << ".";
		cout << "] ";
	}
	cout << "}" << endl;
}

void
ParamSubstitutionBuilder::dumpPropSubst(unsigned int propId, const ParamSubstitution& s) const
{
	cout <<  " " << propTable.index2DagNode(propId) << " = ";
	cout << "{ ";
	for (unsigned int i = 0; i < s.getSubst().size(); ++i)
		cout << "[" << static_cast<Term*>(propTable.getParamVariable(propId,i)) << " = " << s.getSubst()[i] << "] ";
	cout << "} ";
}

ParamSubstitutionBuilder::PropVarInfo::PropVarInfo(unsigned int propId,
		const ParamPropositionTable& propTable, const ParamVarInfo& varInfo): propId(propId)
{
	varMap.resize(propTable.getParamNrVars(propId));
	for (unsigned int i = 0; i < varMap.size(); ++i)
		varMap[i] = varInfo.variable2Index(propTable.getParamVariable(propId, i));
}


} /* namespace modelChecker */
