/*
 * DagSystemLabelGraph.hh
 *
 *  Created on: Jul 29, 2014
 *      Author: kquine
 */

#ifndef DAGSYSTEMLABELGRAPH_HH_
#define DAGSYSTEMLABELGRAPH_HH_
#include "DagSystemGraph.hh"

namespace modelChecker {

class DagSystemLabelGraph: public DagSystemGraph
{
public:
	virtual bool satisfiesStateFormula(Bdd formula, unsigned int stateNr) const = 0;
	virtual bool satisfiesStateEventFormula(Bdd formula, unsigned int stateNr, unsigned int transitionNr) const = 0;
	virtual pair<bool,Bdd> satisfiesPartialStateFormula(Bdd formula, unsigned int stateNr) const = 0;
};

} /* namespace modelChecker */

#endif /* DAGSYSTEMLABELGRAPH_HH_ */
