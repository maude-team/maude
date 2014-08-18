/*
 * SymbolicModelCheckerSymbol.hh
 *
 *  Created on: Jul 22, 2011
 *      Author: kquine
 */

#ifndef SYMBOLICMODELCHECKERSYMBOL_HH_
#define SYMBOLICMODELCHECKERSYMBOL_HH_
#include "temporalSymbol.hh"
#include "cachedDag.hh"
#include "succSymbol.hh"
#include "logicFormula.hh"

#include "Automaton/ProductAutomaton.hh"
#include "Graph/DagSystemGraph.hh"
#include "PropTable/PropositionTable.hh"
#include "PropChecker/PropChecker.hh"
#include "Interface/FormulaBuilder.hh"
#include "Search/ModelChecker.hh"
#include "Symbolic/StateMetaGraph.hh"
#include "Symbolic/StateFoldingGraph.hh"


namespace modelChecker {

class SymbolicModelCheckerSymbol: public TemporalSymbol, public FormulaBuilder
{
public:
	SymbolicModelCheckerSymbol(int id, int arity);

	SymbolicModelCheckerSymbol(const SymbolicModelCheckerSymbol&) = delete;
	SymbolicModelCheckerSymbol& operator=(const SymbolicModelCheckerSymbol&) = delete;

	int build(LogicFormula& formula, DagNodeSet& propositions, DagNode* dagNode) const override;

    bool attachData(const Vector<Sort*>& opDeclaration, const char* purpose, const Vector<const char*>& data) override;
    bool attachSymbol(const char* purpose, Symbol* symbol) override;
    bool attachTerm(const char* purpose, Term* term) override;
    void copyAttachments(Symbol* original, SymbolMap* map) override;
    void getDataAttachments(const Vector<Sort*>& opDeclaration,
    		Vector<const char*>& purposes, Vector<Vector<const char*> >& data) override;
    void getSymbolAttachments(Vector<const char*>& purposes, Vector<Symbol*>& symbols) override;
    void getTermAttachments(Vector<const char*>& purposes, Vector<Term*>& terms) override;
    bool eqRewrite(DagNode* subject, RewritingContext& context) noexcept override;
    void postInterSymbolPass() override;
    void reset() override;

private:
    using Graph =	StateFoldingGraph<StateMetaGraph>;
    using Prod =	ProductAutomaton<true,false,Graph,BuchiAutomaton2>;

    unique_ptr<Graph> createSystemGraph(RewritingContext& sysCxt,
    		bool subsumption, const vector<unsigned int>& stateProps, PropChecker& spc, const PropositionTable& propTable);

    DagNode* makeModelCheckReportDag(bool result, int bound, bool complete, bool subsume, Graph& g, const ModelChecker& mc);

    // satisfaction symbols
    Symbol* satisfiesSymbol = nullptr;
    CachedDag trueTerm = nullptr;

    // meta-graph symbols
    Symbol* metaStateSymbol = nullptr;
    Symbol* metaTransitionSymbol = nullptr;

    // folding symbols
    Symbol* subsumeFoldingRelSymbol = nullptr;
    Symbol* renameFoldingRelSymbol = nullptr;
    Symbol* compatibleTransSymbol = nullptr;

    // bound symbols
    Symbol* unboundedSymbol = nullptr;
    SuccSymbol* succSymbol = nullptr;

    // print symbols
    Symbol* prettyPrintStateSymbol = nullptr;
    Symbol* prettyPrintTransSymbol = nullptr;

    // result symbol
    Symbol* resultreportSymbol = nullptr;

    // counterexample symbols
    Symbol* counterexampleSymbol = nullptr;
    Symbol* transitionSymbol = nullptr;
    Symbol* transitionListSymbol = nullptr;
    Symbol* nilTransitionListSymbol = nullptr;
    CachedDag falseTerm = nullptr;
    CachedDag deadlockTerm = nullptr;
};

inline int
SymbolicModelCheckerSymbol::build(LogicFormula& formula, DagNodeSet& propositions, DagNode* dagNode) const
{
	return TemporalSymbol::build(formula,propositions,dagNode);
}

}

#endif /* SYMBOLICMODELCHECKERSYMBOL_HH_ */
