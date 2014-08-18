/*
 * InputInterpreter.cc
 *
 *  Created on: Jul 26, 2014
 *      Author: kquine
 */

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"
#include "S_Theory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//      additional theory class definitions
#include "S_Symbol.hh"
#include "S_DagNode.hh"

// model checker
#include "InputInterpreter.hh"

namespace modelChecker {

InputInterpreter::InputInterpreter(SuccSymbol* succSymbol, Symbol* unboundedSymbol, DagNode* trueDag, DagNode* falseDag):
		succSymbol(succSymbol), unboundedSymbol(unboundedSymbol), trueDag(trueDag), falseDag(falseDag) {}

bool
InputInterpreter::interpretBoolDag(DagNode* dag) const
{
    if (dag->symbol() == trueDag->symbol())
    	return true;
    else
    {
    	if (dag->symbol() != falseDag->symbol())
    		IssueWarning("ModelChecker: the boolean argument is not reduced to boolean values");
    	return false;
    }
}

long
InputInterpreter::interpretNatDag(DagNode* dag) const
{
	S_DagNode* tmpBoundDag = dynamic_cast<S_DagNode*>(dag);
	if (tmpBoundDag != nullptr)
		return tmpBoundDag->getNumber().get_si();
	else
	{
		if (dag->symbol() != this->unboundedSymbol)
			IssueWarning("ModelChecker: the number argument is not reduced to bound values, and assumed as infinity");
		return NONE;
	}
}

}
