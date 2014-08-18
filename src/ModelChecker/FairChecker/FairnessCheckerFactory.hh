/*
 * FairnessCheckerFactory.hh
 *
 *  Created on: Sep 12, 2013
 *      Author: kquine
 */

#ifndef FAIRNESSCHECKERFACTORY_HH_
#define FAIRNESSCHECKERFACTORY_HH_
#include <memory>
#include "FairnessChecker.hh"
#include "CompositeFairnessChecker.hh"
#include "ParamWeakFairnessChecker.hh"
#include "ParamStrongFairnessChecker.hh"

namespace modelChecker {

/**
 * A factory class to generate various fairness checkers
 */
class FairnessCheckerFactory
{
public:
	static unique_ptr<FairnessChecker> createChecker(bool stateOnly, AbstractFairnessTable* fairTable);

private:
	template <typename Table> struct Traits;

	static unique_ptr<FairnessChecker> createCheckerAux(bool stateOnly, AbstractFairnessTable* fairTable);

	static unique_ptr<FairnessChecker> createCompositeChecker(bool stateOnly, CompositeFairnessTable& table);

	template <typename Table> static unique_ptr<FairnessChecker> createGroundChecker(bool stateOnly, Table& table);

	template <typename Table> static unique_ptr<FairnessChecker> createParamChecker(bool stateOnly, Table& table);

	template <typename Table> static vector<unsigned int> computeTagetIds(bool stateOnly, const Table& table);

};


} /* namespace modelChecker */
#endif /* FAIRNESSCHECKERFACTORY_HH_ */
