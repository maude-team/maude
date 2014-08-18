/*
 * InputInterpreter.hh
 *
 *  Created on: Jul 26, 2014
 *      Author: kquine
 */

#ifndef INPUTINTERPRETER_HH_
#define INPUTINTERPRETER_HH_
#include "succSymbol.hh"

namespace modelChecker {

class InputInterpreter
{
public:
	InputInterpreter(SuccSymbol* succSymbol, Symbol* unboundedSymbol, DagNode* trueDag, DagNode* falseDag);

	bool interpretBoolDag(DagNode* dag) const;
	long interpretNatDag(DagNode* dag) const;

private:
	SuccSymbol* succSymbol;
	Symbol* unboundedSymbol;
	DagNode* trueDag;
	DagNode* falseDag;
};

}
#endif /* INPUTINTERPRETER_HH_ */
