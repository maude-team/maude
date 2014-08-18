/*
 * ParamStrongFairnessChecker.cc
 *
 *  Created on: Aug 20, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "FairSet/ParamStrongFairSet.hh"
#include "ParamStrongFairnessChecker.hh"

namespace modelChecker {

ParamStrongFairnessChecker::ParamStrongFairnessChecker(const vector<unsigned int>& strongFairIds,
		const vector<unsigned int>& prStrongFairIds, ParamStrongFairnessTable& fTable):
	StrongFairnessChecker(strongFairIds, fTable), RealizedFairnessGenerator(prStrongFairIds, fTable), fTableRef(fTable) {}

unsigned int
ParamStrongFairnessChecker::getNrFairness() const
{
	return StrongFairnessChecker::getNrFairness() + compactIndices.size();
}

unique_ptr<FairSet>
ParamStrongFairnessChecker::computeAllFairness(const PropSet& trueProps)
{
	auto result = new ParamStrongFairSet(
			std::move(static_cast<StrongFairSet&>(*StrongFairnessChecker::computeAllFairness(trueProps))));

	for (auto& pt : this->generateRealizedFairness(trueProps))
	{
		auto truth = [&] (unsigned int propId) {
			return fTableRef.getPropTable().isParamProp(propId) ? pt.second.contains(propId) : trueProps.isTrue(propId);
		};
		auto& formula = fTableRef.getFairFormula(pt.first);

		result->setRealized(pt.first);
		if ( !BddUtil::satisfiesFormula(formula.first, truth))	result->setSuppFalse(pt.first);
		if ( !BddUtil::satisfiesFormula(formula.second, truth))	result->setConsFalse(pt.first);
	}
	return unique_ptr<FairSet>(result);
}

unique_ptr<FairSet>
ParamStrongFairnessChecker::computeCompactFairness(const PropSet& trueProps)
{
	auto result = new ParamStrongFairSet(
			std::move(static_cast<StrongFairSet&>(*StrongFairnessChecker::computeCompactFairness(trueProps))));

	for (auto& pt : this->generateRealizedFairness(trueProps))
	{
		auto truth = [&] (unsigned int propId) {
			return fTableRef.getPropTable().isParamProp(propId) ? pt.second.contains(propId) : trueProps.isTrue(propId);
		};
		auto& formula = fTableRef.getFairFormula(pt.first);

		auto compactId = compactIndices.insert(pt.first).first + StrongFairnessChecker::getNrFairness();
		result->setRealized(compactId);
		if ( !BddUtil::satisfiesFormula(formula.first, truth))	result->setSuppFalse(compactId);
		if ( !BddUtil::satisfiesFormula(formula.second, truth))	result->setConsFalse(compactId);
	}
	return unique_ptr<FairSet>(result);
}

unique_ptr<FairSet>
ParamStrongFairnessChecker::unzip(const FairSet& fs) const
{
	auto& pss = static_cast<const ParamStrongFairSet&>(fs);
	auto result = new ParamStrongFairSet(move(static_cast<StrongFairSet&>(*StrongFairnessChecker::unzip(fs))));

	// store an expanded version
	for (unsigned int sn = StrongFairnessChecker::getNrFairness(), i = 0; i < compactIndices.size(); ++i)
	{
		if ( pss.getSuppFalse(sn + i) )	result->setSuppFalse(compactIndices[i]);
		if ( pss.getConsFalse(sn + i) )	result->setConsFalse(compactIndices[i]);
		if ( pss.getRealized(sn + i) )	result->setRealized(compactIndices[i]);
	}
	return unique_ptr<FairSet>(result);
}

} /* namespace modelChecker */
