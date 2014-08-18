/*
 * PropInterpreter.hh
 *
 *  Created on: Jun 2, 2011
 *      Author: kquine
 */

#ifndef PROPINTERPRETER_HH_
#define PROPINTERPRETER_HH_

namespace modelChecker {

class PropInterpreter
{
public:
	PropInterpreter(Symbol* satisfiesSymbol, Symbol* actionmatchSymbol, Symbol* enabledSymbol);

	bool isStateProp(DagNode* propDag) const;
	bool isEventProp(DagNode* propDag) const;

	DagNode* getEnabledActionProp(DagNode* propDag) const;

private:
    const Symbol* satisfiesSymbol;
    const Symbol* actionmatchSymbol;
    const Symbol* enabledSymbol;
};

}

#endif /* PROPINTERPRETER_HH_ */
