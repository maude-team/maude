/*
 * FairnessCheckerFactory.cc
 *
 *  Created on: Sep 12, 2013
 *      Author: kquine
 */

// utility stuff
#include <memory>
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "FairnessCheckerFactory.hh"

namespace modelChecker {

/**
 * Return an appropriate fairness checker
 */
unique_ptr<FairnessChecker>
FairnessCheckerFactory::createChecker(bool stateOnly, AbstractFairnessTable* fairTable)
{
	unique_ptr<FairnessChecker> fc = createCheckerAux(stateOnly, fairTable);
	return fc && fc->getNrFairness() > 0 ? std::move(fc) : nullptr;
}


/**
 * An auxiliary function to create fairness checker (to deal with composite cases)
 */
unique_ptr<FairnessChecker>
FairnessCheckerFactory::createCheckerAux(bool stateOnly, AbstractFairnessTable* fairTable)
{
	if (CompositeFairnessTable* cft = dynamic_cast<CompositeFairnessTable*>(fairTable))
		return createCompositeChecker(stateOnly,*cft);
	if (ParamWeakFairnessTable* pwft = dynamic_cast<ParamWeakFairnessTable*>(fairTable))
		return createParamChecker(stateOnly,*pwft);
	if (ParamStrongFairnessTable* psft = dynamic_cast<ParamStrongFairnessTable*>(fairTable))
		return createParamChecker(stateOnly,*psft);
	if (WeakFairnessTable* wft = dynamic_cast<WeakFairnessTable*>(fairTable))
		return createGroundChecker(stateOnly,*wft);
	if (StrongFairnessTable* sft = dynamic_cast<StrongFairnessTable*>(fairTable))
		return createGroundChecker(stateOnly,*sft);
	return nullptr;
}


/**
 * Template specialization flags for fairness tables
 */
template <> struct FairnessCheckerFactory::Traits<CompositeFairnessTable>
{ using Checker = CompositeFairnessChecker; };
template <> struct FairnessCheckerFactory::Traits<ParamWeakFairnessTable>
{ using Checker = ParamWeakFairnessChecker;		using GroundChecker = WeakFairnessChecker; };
template <> struct FairnessCheckerFactory::Traits<ParamStrongFairnessTable>
{ using Checker = ParamStrongFairnessChecker; 	using GroundChecker = StrongFairnessChecker; };
template <> struct FairnessCheckerFactory::Traits<WeakFairnessTable>
{ using Checker = WeakFairnessChecker; };
template <> struct FairnessCheckerFactory::Traits<StrongFairnessTable>
{ using Checker = StrongFairnessChecker; };


/**
 * Create a composite fairness checker
 */
unique_ptr<FairnessChecker>
FairnessCheckerFactory::createCompositeChecker(bool stateOnly, CompositeFairnessTable& table)
{
	CompositeFairnessChecker* cfc = new CompositeFairnessChecker;
	for (unsigned int i = 0; i < table.nrComponents(); ++i)
		cfc->addComponent(createCheckerAux(stateOnly, &table.getComponent(i)));
	return unique_ptr<FairnessChecker>(cfc);
}


/**
 * Create a fairness checker for ground fairness
 */
template <typename Table> unique_ptr<FairnessChecker>
FairnessCheckerFactory::createGroundChecker(bool stateOnly, Table& table)
{
	return unique_ptr<FairnessChecker>(new typename Traits<Table>::Checker(computeTagetIds(stateOnly,table),table));
}


/**
 * Create a fairness checker for param fairness
 */
template <typename Table> unique_ptr<FairnessChecker>
FairnessCheckerFactory::createParamChecker(bool stateOnly, Table& table)
{
	vector<unsigned int> targetIds = computeTagetIds(stateOnly,table);
	vector<unsigned int> paramIds;
	copy_if(targetIds.begin(), targetIds.end(), back_inserter(paramIds), [&] (unsigned int i) {
		return table.isParamFairness(i);
	});

	if (paramIds.empty())
		return unique_ptr<FairnessChecker>(new typename Traits<Table>::GroundChecker(targetIds,table));
	else
		return unique_ptr<FairnessChecker>(new typename Traits<Table>::Checker(targetIds, paramIds, table));
}


/**
 * An auxiliary function for filtering fairness tables.
 */
template <typename Table> vector<unsigned int>
FairnessCheckerFactory::computeTagetIds(bool stateOnly, const Table& table)
{
	vector<unsigned int> targetIds;
	for (unsigned int i = 0; i < table.nrFairness(); ++i)
		if (table.isStateFairness(i) == stateOnly)
			targetIds.push_back(i);
	return targetIds;
}

} /* namespace modelChecker */
