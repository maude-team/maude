/*
 * RealizedPropGenerator.hh
 *
 *  Created on: Aug 15, 2013
 *      Author: kquine
 */

#ifndef REALIZEDPROPGENERATOR_HH_
#define REALIZEDPROPGENERATOR_HH_
#include "rule.hh"
#include "searchState.hh"
#include "Interface/PropEvaluator.hh"
#include "PropSet.hh"

namespace modelChecker {

class RealizedPropGenerator
{
public:
	RealizedPropGenerator(const vector<unsigned int>& paramPropIds,
			ParamPropositionTable& propTable, const PropEvaluator& pe, RewritingContext& parent);

	const ParamPropositionTable& getPropTable() const;
	void generateRealizedProps(DagNode* target, PropSet& result);	// return realized prop indices in the "propositions"

private:
	void constructRules();
	unique_ptr<Rule> makeRule(Term* left, Term* right, const Vector<ConditionFragment*>& condition) const;

	void computeGenRules(SearchState& sc, RewritingContext& context, PropSet& result);

	// adapted from deepCopyCondition in importModule.cc (declared as private)
	static void deepCopyCondition(const Vector<ConditionFragment*>& original,
					Vector<ConditionFragment*>& copy);

	vector<unique_ptr<Rule> > genRules;

    RewritingContext& parentContext;
    const PropEvaluator& pEval;

	const vector<unsigned int> paramPropIds;			// the corresponding param prop ids
	ParamPropositionTable& propTable;
};

} /* namespace modelChecker */
#endif /* REALIZEDPROPGENERATOR_HH_ */
