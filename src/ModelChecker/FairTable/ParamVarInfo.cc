/*
 * ParamVarInfo.cc
 *
 *  Created on: Sep 3, 2013
 *      Author: kquine
 */

// utility stuff
#include <stdexcept>
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "NA_Theory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

// core class definitions
#include "dagArgumentIterator.hh"
#include "NA_Symbol.hh"
#include "variableDagNode.hh"

// ltlr definitions
#include "Utility/StringStream.hh"
#include "ParamVarInfo.hh"

namespace modelChecker {

ParamVarInfo::ParamVarInfo(DagNode* dag)
{
	indexVariables(dag);
}

unsigned int
ParamVarInfo::getNrVariables() const
{
	return variables.size();
}

unsigned int
ParamVarInfo::variable2Index(VariableDagNode* variableDag) const
{
	indexed_set<VariableDagNode*>::const_iterator ci = variables.find(variableDag);
	if (ci != variables.end())
		return ci->second;
	else
		throw logic_error(StringStream() << "No variable " << QUOTE(static_cast<DagNode*>(variableDag)) <<" found");
}

unsigned int
ParamVarInfo::variable2Index(Term* variableTerm) const
{
	for (auto i : variables)
	{
		if (variableTerm->equal(i.first))
			return i.second;
	}
	throw logic_error(StringStream() << "No variable " << QUOTE(variableTerm) <<" found");
}

VariableDagNode*
ParamVarInfo::index2Variable(unsigned int index) const
{
	return variables[index];
}

void
ParamVarInfo::indexVariables(DagNode* dag)
{
	if (dag->isGround())
		return;
	else
	{
		if (dynamic_cast<VariableSymbol*>(dag->symbol()))
			variables.insert(static_cast<VariableDagNode*>(dag));
		else
		{
			for (DagArgumentIterator i(*dag); i.valid(); i.next())
				indexVariables(i.argument());
		}
	}
}


} /* namespace modelChecker */
