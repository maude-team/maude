/*
 * ProofTermGenerator.hh
 *
 *  Created on: Aug 6, 2013
 *      Author: kquine
 */

#ifndef PROOFTERMGENERATOR_HH_
#define PROOFTERMGENERATOR_HH_
#include "quotedIdentifierSymbol.hh"
#include "quotedIdentifierDagNode.hh"
#include "mixfixModule.hh"
#include "positionState.hh"

namespace modelChecker {

class ProofTermGenerator
{
public:
	ProofTermGenerator(MixfixModule* module, RewritingContext& parent,
			Symbol* prooftermSymbol, Symbol* assignOp, Symbol* holeOp,
			Symbol* substitutionSymbol, Symbol* emptySubstSymbol, QuotedIdentifierSymbol* qidSymbol,
			Symbol* unlabeledSymbol, Symbol* noContextSymbol, DagNode* deadlockDag);

	DagNode* makeProofDag(const PositionState* ps, const Rule& rule, const Substitution* subst) const;
	DagNode* getDeadlockDag() const;

private:
    DagNode* makeContextDag(const PositionState* ps, const Sort* holeSort) const;
    DagNode* makeRuleNameDag(int ruleId) const;
    DagNode* makeSubstitutionDag(const Substitution* substitution, const VariableInfo* variableInfoconst) const;
    DagNode* makeAssignmentDag(const Term* variable, DagNode* value, Symbol* assignmentSymbol) const;
    Symbol* findAssignOp(const Term* var) const;
    Symbol* findHoleOp(const Sort* holeSort) const;

    MixfixModule* module;
    RewritingContext& parent;

    Symbol* prooftermSymbol;
    Symbol* assignOp;
    Symbol* holeOp;

    Symbol* substitutionSymbol;
    Symbol* emptySubstSymbol;
    QuotedIdentifierSymbol* qidSymbol;
    Symbol* unlabeledSymbol;
    Symbol* noContextSymbol;

    DagNode* deadlockDag;
};

} /* namespace modelChecker */
#endif /* PROOFTERMGENERATOR_HH_ */
