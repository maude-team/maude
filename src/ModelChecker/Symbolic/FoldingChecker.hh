/*
 * FoldingChecker.hh
 *
 *  Created on: Aug 7, 2011
 *      Author: kquine
 */

#ifndef FOLDINGCHECKER_HH_
#define FOLDINGCHECKER_HH_

namespace modelChecker {

class FoldingChecker
{
public:
	FoldingChecker(Symbol* foldingRelSymbol, DagNode* trueDag, RewritingContext* context);
	bool fold(DagNode* s, DagNode* t) const;

private:
	Symbol* foldingRelSymbol;
    DagNode* trueDag;
	RewritingContext* parentContext;
};

}

#endif /* FOLDINGCHECKER_HH_ */
