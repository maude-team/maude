/*
 * ParamPropositionTable.cc
 *
 *  Created on: Aug 23, 2013
 *      Author: kquine
 */

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNodeSet.hh"
#include "term.hh"

//		higher class definitions
#include "matchSearchState.hh"

// core class definitions
#include "rewritingContext.hh"

// ltlr definitions
#include "Utility/TermUtil.hh"
#include "ParamPropositionTable.hh"

namespace modelChecker {

ParamPropositionTable::ParamPropositionTable(const PropInterpreter& pi): PropositionTable(pi)  {}

bool
ParamPropositionTable::hasParamProp() const
{
	return ! paramInfoTable.empty();
}

bool
ParamPropositionTable::isParamProp(unsigned int propId) const
{
	return getParamPropInfo(propId) != nullptr;
}

unsigned int
ParamPropositionTable::getParamNrVars(unsigned int propId) const
{
	const ParamPropInfo* ppi = getParamPropInfo(propId);
	Assert(ppi != nullptr, "ParamPropositionTable::getParamNrVars: not a param substitution");
	return paramInfoTable[ppi->paramInfoId]->pattern->getNrRealVariables();
}

Term*
ParamPropositionTable::getParamVariable(unsigned int propId, unsigned int varId) const
{
	const ParamPropInfo* ppi = getParamPropInfo(propId);
	Assert(ppi != nullptr, "ParamPropositionTable::getParamVariable: not a param substitution");
	return paramInfoTable[ppi->paramInfoId]->pattern->index2Variable(varId);
}

const vector<ParamPropositionTable::MatchingInfo>*
ParamPropositionTable::getParamMatches(unsigned int propId) const
{
	if (const InstancePropInfo* ipi = getInstancePropInfo(propId))
		return & ipi->matchingPropNSubstRefs;
	else
		return nullptr;
}

int
ParamPropositionTable::insertInstanceAndUpdate(DagNode* propDag, RewritingContext& parentContext)
{
	const int propId = this->dagNode2Index(propDag);
	if (propId != NONE)	// if the dag has stored
	{
		if (! getInstancePropInfo(propId))	// if the instance relation has NOT been computed
		{
			unique_ptr<InstancePropInfo> ipi(new InstancePropInfo(*propInfoTable[propId]));
			ipi->matchingPropNSubstRefs =  compact(computeMatchingProps(propDag, parentContext));
			propInfoTable[propId] = move(ipi);
		}
		return getInstancePropInfo(propId)->matchingPropNSubstRefs.empty() ? NONE : propId;
	}
	else // if the dag has not been stored (but it could have already been computed while not stored)
	{
		const auto& temp = computeMatchingProps(propDag, parentContext);

		if (! temp.empty())	// if it is an instance
		{
			const int newPropId = this->cardinality();
			this->insert(propDag);
			updatePropTable();

			unique_ptr<InstancePropInfo> ipi(new InstancePropInfo(*propInfoTable[newPropId]));
			ipi->matchingPropNSubstRefs = compact(temp);
			propInfoTable[newPropId] = move(ipi);
			return newPropId;
		}
		return NONE;
	}
}


map<unsigned int,set<const ParamSubstitution*>>
ParamPropositionTable::computeMatchingProps(DagNode* propDag, RewritingContext& parentContext)
{
	map<unsigned int,set<const ParamSubstitution*>> match;
	auto it = paramPropSymbolMap.find(propDag->symbol());
	if (it != paramPropSymbolMap.end())	// for corresponding param props
	{
		const unique_ptr<RewritingContext> dagCxt(parentContext.makeSubcontext(propDag));
		for (int k : it->second)
		{
			if (const ParamPropInfo* ppi = getParamPropInfo(k))
			{
				ParamInfo& pi = *paramInfoTable[ppi->paramInfoId];
				MatchSearchState mss(dagCxt.get(), pi.pattern.get());

				while (mss.findNextMatch())
				{
					auto res = pi.substitutions.emplace(new ParamSubstitution(*pi.pattern, *mss.getContext()));
					match[k].insert(res.first->get());
				}
			}
		}
	}
	return match;
}

vector<ParamPropositionTable::MatchingInfo>
ParamPropositionTable::compact(const map<unsigned int,set<const ParamSubstitution*>>& match) const
{
	vector<MatchingInfo> result(match.size());
	transform(match.begin(), match.end(), result.begin(),
			[](const pair<unsigned int,set<const ParamSubstitution*>>& i) {
		return make_pair(i.first,vector<const ParamSubstitution*>(i.second.begin(),i.second.end()));
	});
	return result;
}

void
ParamPropositionTable::updatePropInfo(unsigned int propId)
{
	PropositionTable::updatePropInfo(propId);	// first fill the basic info

	DagNode* propDag = this->index2DagNode(propId);
	if (! propDag->isGround())	// check if ground (variable info must be filled before)
	{
		unsigned int pInfoId;
		if (this->isEnabledProp(propId))
		{
			pInfoId = getParamPropInfo(getEnabledEventId(propId))->paramInfoId;
		}
		else
		{
			// register a related symbol for the prop (except for enalbed props)
			paramPropSymbolMap[propDag->symbol()].push_back(propId);
			pInfoId = paramInfoTable.size();
			paramInfoTable.emplace_back(new ParamInfo(TermUtil::constructTerm(propDag)));
		}
		propInfoTable[propId].reset(new ParamPropInfo(*propInfoTable[propId], pInfoId));
	}
}



} /* namespace modelChecker */
