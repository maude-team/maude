/*
 * ParamWeakFairnessChecker.cc
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
#include "FairSet/ParamWeakFairSet.hh"
#include "ParamWeakFairnessChecker.hh"

namespace modelChecker {

ParamWeakFairnessChecker::ParamWeakFairnessChecker(const vector<unsigned int>& weakFairIds,
		const vector<unsigned int>& paramWeakFairIds, ParamWeakFairnessTable& fTable):
	WeakFairnessChecker(weakFairIds,fTable), RealizedFairnessGenerator(paramWeakFairIds,fTable), fTableRef(fTable) {}

unsigned int
ParamWeakFairnessChecker::getNrFairness() const
{
	return WeakFairnessChecker::getNrFairness() + compactIndices.size();
}

unique_ptr<FairSet>
ParamWeakFairnessChecker::computeAllFairness(const PropSet& trueProps)
{
	auto result = new ParamWeakFairSet(move(static_cast<WeakFairSet&>(
			*WeakFairnessChecker::computeAllFairness(trueProps))));

	for (auto& pt : this->generateRealizedFairness(trueProps))
	{
		auto truth = [&] (unsigned int propId) { return fTableRef.getPropTable().isParamProp(propId) ?
				pt.second.contains(propId) : trueProps.isTrue(propId);};
		auto& formula = fTableRef.getFairFormula(pt.first);

		result->setRealized(pt.first);
		if ( !BddUtil::satisfiesFormula(formula, truth))	result->setFalsified(pt.first);
	}
	return unique_ptr<FairSet>(result);
}

unique_ptr<FairSet>
ParamWeakFairnessChecker::computeCompactFairness(const PropSet& trueProps)
{
	auto result = new ParamWeakFairSet(move(static_cast<WeakFairSet&>(
			*WeakFairnessChecker::computeCompactFairness(trueProps))));

	for (auto& pt : this->generateRealizedFairness(trueProps))
	{
		auto truth = [&] (unsigned int propId) { return fTableRef.getPropTable().isParamProp(propId) ?
				pt.second.contains(propId) : trueProps.isTrue(propId);};
		auto& formula = fTableRef.getFairFormula(pt.first);

		auto compactId = compactIndices.insert(pt.first).first + WeakFairnessChecker::getNrFairness();
		result->setRealized(compactId);
		if ( !BddUtil::satisfiesFormula(formula, truth))	result->setFalsified(compactId);
	}
	return unique_ptr<FairSet>(result);
}

unique_ptr<FairSet>
ParamWeakFairnessChecker::unzip(const FairSet& fs) const
{
	auto& pws = static_cast<const ParamWeakFairSet&>(fs);
	auto result = new ParamWeakFairSet(move(static_cast<WeakFairSet&>(*WeakFairnessChecker::unzip(fs))));

	// store an expanded version
	for (unsigned int wn = WeakFairnessChecker::getNrFairness(), i = 0; i < compactIndices.size(); ++i)
	{
		if ( pws.getFalsified(wn + i) )	result->setFalsified(compactIndices[i]);
		if ( pws.getRealized(wn + i) )	result->setRealized(compactIndices[i]);
	}
	return unique_ptr<FairSet>(result);
}

} /* namespace modelChecker */
