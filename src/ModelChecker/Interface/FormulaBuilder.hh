/*
 * FormulaBuilder.hh
 *
 *  Created on: Aug 29, 2013
 *      Author: kquine
 */

#ifndef FORMULABUILDER_HH_
#define FORMULABUILDER_HH_
#include <set>
#include "bddUser.hh"
#include "natSet.hh"
#include "logicFormula.hh"
#include "PropTable/PropositionTable.hh"

namespace modelChecker {

struct FormulaBuilder : private BddUser
{
public:
	struct Formula
	{
		LogicFormula data;
		int top;
		unsigned int nrRealFormulaPropIds;	// the number of props in the formula.
		unsigned int nrFormulaPropIds;		// the number including derived event props from enabled props in the formula.
	};

	virtual ~FormulaBuilder() = default;

	unique_ptr<Formula> interpretFormula(DagNode* formulaDag, PropositionTable& propTable) const;

	virtual int build(LogicFormula& formula, DagNodeSet& propositions, DagNode* dagNode) const = 0;

	bdd translateFairnessFormula(unsigned int subformulaIndex,
			const LogicFormula& formula, set<unsigned int>& propIds) const;
};

} /* namespace modelChecker */
#endif /* FORMULABUILDER_HH_ */
