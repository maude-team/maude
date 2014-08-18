/*
 * ProofTermGenerator.cc
 *
 *  Created on: Aug 6, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"
#include "strategyLanguage.hh"
#include "mixfix.hh"

// interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

// core class definitions
#include "rewritingContext.hh"
#include "rule.hh"
#include "positionState.hh"

// ltlr definitions
#include "ProofTermGenerator.hh"

namespace modelChecker {

ProofTermGenerator::ProofTermGenerator(MixfixModule* module, RewritingContext& parent,
		Symbol* prooftermSymbol, Symbol* assignOp, Symbol* holeOp,
		Symbol* substitutionSymbol, Symbol* emptySubstSymbol, QuotedIdentifierSymbol* qidSymbol,
		Symbol* unlabeledSymbol, Symbol* noContextSymbol, DagNode* deadlockDag):
				module(module), parent(parent),
				prooftermSymbol(prooftermSymbol), assignOp(assignOp), holeOp(holeOp),
				substitutionSymbol(substitutionSymbol), emptySubstSymbol(emptySubstSymbol), qidSymbol(qidSymbol),
				unlabeledSymbol(unlabeledSymbol), noContextSymbol(noContextSymbol), deadlockDag(deadlockDag){}

DagNode*
ProofTermGenerator::makeProofDag(const PositionState* ps, const Rule& rule, const Substitution* subst) const
{
    static Vector<DagNode*> args(3);
	args[0] = makeContextDag(ps, rule.getLhs()->getSort());
	args[1] = makeRuleNameDag(rule.getLabel().id());
	args[2] = makeSubstitutionDag(subst, &rule);

	DagNode* pd = prooftermSymbol->makeDagNode(args);
	pd->reduce(parent);
	return pd;
}

DagNode*
ProofTermGenerator::getDeadlockDag() const
{
	return deadlockDag;
}

DagNode*
ProofTermGenerator::makeContextDag(const PositionState* ps, const Sort* holeSort) const
{
	if (ps)
	{
		if (Symbol* holeSymbol = findHoleOp(holeSort))
			return ps->rebuildDag(holeSymbol->makeDagNode()).first;
	}
    return noContextSymbol->makeDagNode();
}

DagNode*
ProofTermGenerator::makeRuleNameDag(int ruleId) const
{
	if (ruleId != NONE)
		return new QuotedIdentifierDagNode(qidSymbol, ruleId);
    return unlabeledSymbol->makeDagNode();
}

DagNode*
ProofTermGenerator::makeSubstitutionDag(const Substitution* substitution, const VariableInfo* variableInfo) const
{
	if (substitution && variableInfo)
	{
		auto nrVariable = variableInfo->getNrRealVariables();
		if (nrVariable > 0)
		{
			Vector<DagNode*> args;  // size may vary
			for (auto i = 0; i < nrVariable ; i++)
			{
				if (Symbol* assignSymbol = findAssignOp(variableInfo->index2Variable(i)))
					args.append(makeAssignmentDag(variableInfo->index2Variable(i), substitution->value(i), assignSymbol));
			}
			if (args.size() > 1)
				return substitutionSymbol->makeDagNode(args);
			else if (args.size() == 1)
				return args[0];
		}
	}
    return emptySubstSymbol->makeDagNode();
}

DagNode*
ProofTermGenerator::makeAssignmentDag(const Term* variable, DagNode* value, Symbol* assignmentSymbol) const
{
    static Vector<DagNode*> args(2);
    args[0] = new QuotedIdentifierDagNode(qidSymbol, safeCast(const VariableTerm*,variable)->id());
    args[1] = value;
    return assignmentSymbol->makeDagNode(args);
}

Symbol*
ProofTermGenerator::findAssignOp(const Term* var) const
{
	//
	// assignOp should have the form:  Qid Value -> Assignment..
	//
	static Vector<ConnectedComponent*> domainC(2);
	domainC[0] = const_cast<ConnectedComponent*>(assignOp->domainComponent(0));
	domainC[1] = var->getComponent();
	return module->findSymbol(assignOp->id(), domainC, assignOp->rangeComponent());
}

Symbol*
ProofTermGenerator::findHoleOp(const Sort* holeSort) const
{
	//
	// find a constant with the same name as the holeOp []
	//
	Vector<ConnectedComponent*> domainComponents(0); // no domain
	return module->findSymbol(holeOp->id(), domainComponents, holeSort->component());
}

} /* namespace modelChecker */
