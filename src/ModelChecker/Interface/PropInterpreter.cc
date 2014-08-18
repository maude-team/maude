/*
 * PropInterpreter.cc
 *
 *  Created on: Jun 2, 2011
 *      Author: kquine
 */

// utility stuff
#include <stdexcept>
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

// core class definitions
#include "dagArgumentIterator.hh"

// ltlr definitions
#include "Utility/StringStream.hh"
#include "PropInterpreter.hh"

namespace modelChecker {

PropInterpreter::PropInterpreter(Symbol* satisfiesSymbol, Symbol* actionmatchSymbol, Symbol* enabledSymbol):
		satisfiesSymbol(satisfiesSymbol), actionmatchSymbol(actionmatchSymbol), enabledSymbol(enabledSymbol) {}

bool
PropInterpreter::isStateProp(DagNode* propDag) const
{
	Assert(propDag->getSortIndex() != Sort::SORT_UNKNOWN, "The sort of " << QUOTE(propDag) << " is not computed yet.");
	return propDag->leq(satisfiesSymbol->getOpDeclarations()[0].getDomainAndRange()[1]);
}

bool
PropInterpreter::isEventProp(DagNode* propDag) const
{
	if (actionmatchSymbol != nullptr)
	{
		Assert(propDag->getSortIndex() != Sort::SORT_UNKNOWN, "The sort of " << QUOTE(propDag) << " is not computed yet.");
		return propDag->leq(actionmatchSymbol->getOpDeclarations()[0].getDomainAndRange()[1]);
	}
	else
		return false;
}

DagNode*
PropInterpreter::getEnabledActionProp(DagNode* propDag) const
{
	if (enabledSymbol != nullptr && propDag->symbol() == enabledSymbol)
	{
		DagArgumentIterator ei(propDag);
		if (ei.valid())
			return ei.argument();
		else
			throw invalid_argument(StringStream() << "enabled proposition " << QUOTE(propDag) << " has no argument.");
	}
	return nullptr;
}


}
