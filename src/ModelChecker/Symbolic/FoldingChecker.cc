/*
 * StateFoldingChecker.cc
 *
 *  Created on: Aug 7, 2011
 *      Author: kquine
 */

//      utility stuff
#include <memory>
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "higher.hh"
#include "freeTheory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "dagArgumentIterator.hh"

//		core class definitions
#include "symbolMap.hh"
#include "rewritingContext.hh"

//		built in class definitions
#include "bindingMacros.hh"

#include "FoldingChecker.hh"

namespace modelChecker {

FoldingChecker::FoldingChecker(Symbol* foldingRelSymbol, DagNode* trueDag, RewritingContext* context):
		foldingRelSymbol(foldingRelSymbol), trueDag(trueDag), parentContext(context) {}

bool
FoldingChecker::fold(DagNode* s, DagNode* t) const
{
	Assert(trueDag != nullptr, "FoldingChecker::fold: trueDag not set");
	static Vector<DagNode*> args(2);
	args[0] = s;
	args[1] = t;

	DagNode* checkDag = foldingRelSymbol->makeDagNode(args);
#ifdef TDEBUG
	cout << checkDag << " is reduced to ";
#endif
	const unique_ptr<RewritingContext> testContext(parentContext->makeSubcontext(checkDag));
	testContext->reduce();
	bool result = trueDag->equal(testContext->root());
#ifdef TDEBUG
	cout << testContext->root() << endl;
#endif
	parentContext->addInCount(*testContext);
	return result;
}

}
