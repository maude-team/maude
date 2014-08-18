/*
 * PropEvaluator.hh
 *
 *  Created on: Sep 5, 2013
 *      Author: kquine
 */

#ifndef PROPEVALUATOR_HH_
#define PROPEVALUATOR_HH_

namespace modelChecker {

class PropEvaluator
{
public:
	PropEvaluator(Symbol* checkSymbol, Symbol* realizedSymbol, DagNode* trueDag);

	bool computeProp(DagNode* target, DagNode* prop, RewritingContext& context) const;

	const Vector<Equation*>& getCheckEquations() const;
	DagNode* getRealizedDag(DagNode* dag) const;
	Term* getRealizedTerm(Term* term) const;

private:
	Symbol* checkSymbol;
	Symbol* realizedSymbol;
	const DagNode* trueDagNode;
};

} /* namespace modelChecker */
#endif /* PROPEVALUATOR_HH_ */
