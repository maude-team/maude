/*
 * FormulaBuilder.cc
 *
 *  Created on: Aug 29, 2013
 *      Author: kquine
 */

//      utility stuff
#include <stdexcept>
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"

//		temporal class definitions
#include "bdd.hh"
#include "logicFormula.hh"

// ltlr definitions
#include "Utility/StringStream.hh"
#include "Utility/TermUtil.hh"
#include "FormulaBuilder.hh"

namespace modelChecker {

unique_ptr<FormulaBuilder::Formula>
FormulaBuilder::interpretFormula(DagNode* formulaDag, PropositionTable& propTable) const
{
	if (! TermUtil::checkGround(formulaDag))
		throw invalid_argument(StringStream() << "negated LTL formula " <<
				QUOTE(formulaDag) << " did not reduce to a ground term.");
	else
	{
		unique_ptr<Formula> formula(new Formula);
		formula->top = build(formula->data, propTable.getDagNodeSet(), formulaDag);
		if (formula->top == NONE)
			throw invalid_argument(StringStream() << "negated LTL formul " <<
					QUOTE(formulaDag) << "a did not reduce to a valid negative normal form.");
		else
		{
			formula->nrRealFormulaPropIds = propTable.cardinality();

			// update of the prop table will add event props from the existing enabled props.
			propTable.updatePropTable();
			formula->nrFormulaPropIds = propTable.cardinality();
			return formula;
		}
	}
}

bdd
FormulaBuilder::translateFairnessFormula(unsigned int subformulaIndex,
		const LogicFormula& formula, set<unsigned int>& propIds) const
{
	switch (formula.getOp(subformulaIndex))
	{
		case LogicFormula::PROPOSITION:
		{
			unsigned int pi = formula.getProp(subformulaIndex);
			propIds.insert(pi);
			return ithvar(pi);
		}
		case LogicFormula::LTL_TRUE:
			return bdd_true();
		case LogicFormula::LTL_FALSE:
			return bdd_false();
		case LogicFormula::NOT:
			return nithvar(formula.getProp(formula.getArg(subformulaIndex, 0)));
		case LogicFormula::AND:
			return  translateFairnessFormula(formula.getArg(subformulaIndex,0), formula, propIds) &
					translateFairnessFormula(formula.getArg(subformulaIndex,1), formula, propIds);
		case LogicFormula::OR:
			return  translateFairnessFormula(formula.getArg(subformulaIndex,0), formula, propIds) |
					translateFairnessFormula(formula.getArg(subformulaIndex,1), formula, propIds);
		default:
			throw invalid_argument("fairness formula cannot contains temporal operator");
	}
}

} /* namespace modelChecker */
