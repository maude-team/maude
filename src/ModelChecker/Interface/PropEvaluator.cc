/*
 * PropEvaluator.cc
 *
 *  Created on: Sep 5, 2013
 *      Author: kquine
 */

// utility stuff
#include <memory>
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNodeSet.hh"

// core class definitions
#include "rewritingContext.hh"
#include "symbolMap.hh"

// ltlr definitions
#include "PropEvaluator.hh"

//#define TDEBUG

namespace modelChecker {

PropEvaluator::PropEvaluator(Symbol* checkSymbol, Symbol* realizedSymbol, DagNode* trueDag):
		checkSymbol(checkSymbol), realizedSymbol(realizedSymbol), trueDagNode(trueDag) {}

bool
PropEvaluator::computeProp(DagNode* target, DagNode* prop, RewritingContext& context) const
{
	static Vector<DagNode*> args(2);
	args[0] = target;
	args[1] = prop;
	DagNode* checkDag = checkSymbol->makeDagNode(args);
#ifdef TDEBUG
	cout << checkDag << " is reduced to ";
#endif
	const unique_ptr<RewritingContext> testContext(context.makeSubcontext(checkDag));
	testContext->reduce();
	bool result = trueDagNode->equal(testContext->root());
#ifdef TDEBUG
	cout << (result ? "true" : "false") << endl;
#endif
	context.addInCount(*testContext);
	return result;
}

const Vector<Equation*>&
PropEvaluator::getCheckEquations() const
{
	return checkSymbol->getEquations();
}

DagNode*
PropEvaluator::getRealizedDag(DagNode* dag) const
{
	static Vector<DagNode*> targs(1);
	targs[0] = dag;
	return realizedSymbol->makeDagNode(targs);
}

Term*
PropEvaluator::getRealizedTerm(Term* term) const
{
	static Vector<Term*> largs(1);
	largs[0] = term;
	return realizedSymbol->makeTerm(largs);
}

} /* namespace modelChecker */
