/*
 * SCCBuchiModelChecker.h
 *
 *  Created on: Nov 30, 2010
 *      Author: kquine
 */

#ifndef SCCBUCHIMODELCHECKER_HH_
#define SCCBUCHIMODELCHECKER_HH_
#include "SCCModelChecker.hh"

namespace modelChecker {

template <typename PA>
class SCCBuchiModelChecker : public SCCModelChecker<PA>
{
public:
	explicit SCCBuchiModelChecker(FairAutomaton<PA>& graph);

private:
	using Super 		= SCCModelChecker<PA>;
	using State 		= typename Super::State;
	using Transition	= typename Super::Transition;
	using SCC 			= typename Super::SCC;
	using SCCStack		= typename Super::SCCStack;

	unique_ptr<SCC> findAcceptedSCC(const vector<State>& initials) override;
};

}

#include "SCCBuchiModelChecker.cc"

#endif /* SCCBUCHIMODELCHECKER_H_ */
