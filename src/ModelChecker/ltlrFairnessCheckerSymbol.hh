/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

#ifndef _LTLRFAIRNESSCHECKERSYMBOL_HH
#define _LTLRFAIRNESSCHECKERSYMBOL_HH
#include "temporalSymbol.hh"
#include "cachedDag.hh"
#include "Interface/FormulaBuilder.hh"
#include "ModelCheckerManager.hh"

namespace modelChecker {

class LTLRFairnessCheckerSymbol : public TemporalSymbol, public FormulaBuilder
{
public:
    LTLRFairnessCheckerSymbol(int id, int arity);

    LTLRFairnessCheckerSymbol(const LTLRFairnessCheckerSymbol&) = delete;
    LTLRFairnessCheckerSymbol& operator=(const LTLRFairnessCheckerSymbol&) = delete;

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
    Symbol* fairnessSymbol = nullptr;
    Symbol* strongFairTypeSymbol = nullptr;
    Symbol* weakFairTypeSymbol = nullptr;
    Symbol* fairnessSetSymbol = nullptr;
    Symbol* emptyFairnessSetSymbol = nullptr;

    Symbol* counterexampleSymbol = nullptr;
    Symbol* transitionSymbol = nullptr;
    Symbol* transitionListSymbol = nullptr;
    Symbol* nilTransitionListSymbol = nullptr;
    CachedDag falseTerm;

    Symbol* prooftermSymbol = nullptr;
    Symbol* assignOp = nullptr;
    Symbol* holeOp = nullptr;
    Symbol* substitutionSymbol = nullptr;
    Symbol* emptySubstSymbol = nullptr;
    QuotedIdentifierSymbol* qidSymbol = nullptr;
    Symbol* unlabeledSymbol = nullptr;
    Symbol* noContextSymbol = nullptr;

    Symbol* realizedPropSymbol = nullptr;
    Symbol* realizedActionSymbol = nullptr;

    Symbol* satisfiesSymbol = nullptr;
    Symbol* actionmatchSymbol = nullptr;
	Symbol* enabledSymbol = nullptr;
    CachedDag deadlockTerm;
    CachedDag trueTerm;
};

inline int
LTLRFairnessCheckerSymbol::build(LogicFormula& formula, DagNodeSet& propositions, DagNode* dagNode) const
{
	return TemporalSymbol::build(formula,propositions,dagNode);
}

}
#endif        /* _LTLRFAIRNESSCHECKERSYMBOL_HH */
