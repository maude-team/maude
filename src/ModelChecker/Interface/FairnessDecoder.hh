/*
 * FairnessDecoder.hh
 *
 *  Created on: Dec 4, 2010
 *      Author: kquine
 */

#ifndef FAIRNESSDECODER_HH_
#define FAIRNESSDECODER_HH_
#include "Interface/FormulaBuilder.hh"
#include "PropTable/PropositionTable.hh"
#include "FairTable/FairnessTable.hh"

namespace modelChecker {

class FairnessDecoder
{
public:
	FairnessDecoder(const FormulaBuilder& fBuilder, PropositionTable& propTable,
			Symbol* fairnessSymbol, Symbol* strongFairTypeSymbol, Symbol* weakFairTypeSymbol,
			Symbol* fairnessSetSymbol, Symbol* emptyFairnessSetSymbol);

	unique_ptr<AbstractFairnessTable> interpretFairnessSet(DagNode* fairSetDag) const;

private:
	using FairCond = tuple<vector<unsigned int>,bdd,bdd,DagNode*>;

	deque<FairCond> parseFairnessSet(DagNode* fairSetDag) const;
	FairCond parseFairnessDag(DagNode* fairnessDag) const;

	const FormulaBuilder& fBuilder;
	PropositionTable& propTable;

    Symbol* fairnessSymbol;
    Symbol* strongFairTypeSymbol;
    Symbol* weakFairTypeSymbol;
    Symbol* fairnessSetSymbol;
    Symbol* emptyFairnessSetSymbol;
};

}

#endif /* FAIRNESSDECODER_HH_ */
