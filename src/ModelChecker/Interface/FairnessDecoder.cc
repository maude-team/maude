/*
 * FairnessDecoder.cc
 *
 *  Created on: Dec 4, 2010
 *      Author: kquine
 */

//      utility stuff
#include <stdexcept>
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "dagArgumentIterator.hh"

//		temporal class definitions
#include "logicFormula.hh"

//      free theory class definitions
#include "freeDagNode.hh"

// ltlr definitions
#include "Utility/StringStream.hh"
#include "FairTable/ParamFairnessTable.hh"
#include "FairTable/CompositeFairnessTable.hh"
#include "FairnessDecoder.hh"


namespace modelChecker {

FairnessDecoder::FairnessDecoder(const FormulaBuilder& fBuilder, PropositionTable& propTable,
		Symbol* fairnessSymbol, Symbol* strongFairTypeSymbol, Symbol* weakFairTypeSymbol,
		Symbol* fairnessSetSymbol, Symbol* emptyFairnessSetSymbol):
				fBuilder(fBuilder), propTable(propTable), fairnessSymbol(fairnessSymbol),
				strongFairTypeSymbol(strongFairTypeSymbol), weakFairTypeSymbol(weakFairTypeSymbol),
				fairnessSetSymbol(fairnessSetSymbol), emptyFairnessSetSymbol(emptyFairnessSetSymbol) {}

unique_ptr<AbstractFairnessTable>
FairnessDecoder::interpretFairnessSet(DagNode* fairSetDag) const
{
	const deque<FairCond> fairConds = parseFairnessSet(fairSetDag);

	if (! fairConds.empty())
	{
		deque<deque<FairCond>::const_iterator> wConds;	bool weakParam = false;
		deque<deque<FairCond>::const_iterator> sConds;	bool strongParam = false;

		for (auto i = fairConds.cbegin(); i != fairConds.cend(); ++i)
		{
			if (get<1>(*i) == bdd_true())
			{
				weakParam |= (! get<3>(*i)->isGround());
				wConds.push_back(i);
			}
			else
			{
				strongParam |= (! get<3>(*i)->isGround());
				sConds.push_back(i);
			}
		}

		unique_ptr<WeakFairnessTable>	wft(weakParam	?
				new ParamWeakFairnessTable(static_cast<ParamPropositionTable&>(propTable)) :
				new WeakFairnessTable(propTable));
		unique_ptr<StrongFairnessTable> sft(strongParam ?
				new ParamStrongFairnessTable(static_cast<ParamPropositionTable&>(propTable)) :
				new StrongFairnessTable(propTable));

		for (auto i : wConds)	wft->insertFairnessFormula(get<2>(*i), get<0>(*i), get<3>(*i));
		for (auto i : sConds)	sft->insertFairnessFormula(make_pair(get<1>(*i),get<2>(*i)), get<0>(*i), get<3>(*i));

		if (wft->nrFairness() > 0 && sft->nrFairness() > 0)
		{
			CompositeFairnessTable* cft = new CompositeFairnessTable;
			cft->addComponent(move(wft));	cft->addComponent(move(sft));
			return unique_ptr<AbstractFairnessTable>(cft);
		}
		if (wft->nrFairness() > 0)
			return unique_ptr<AbstractFairnessTable>(move(wft));
		if (sft->nrFairness() > 0)
			return unique_ptr<AbstractFairnessTable>(move(sft));
	}
	return nullptr;
}

deque<FairnessDecoder::FairCond>
FairnessDecoder::parseFairnessSet(DagNode* fairSetDag) const
{
	deque<FairCond> result;
	if (fairSetDag->symbol() == fairnessSymbol)
	{
		result.push_back(parseFairnessDag(fairSetDag));
	}
	else if (fairSetDag->symbol() == fairnessSetSymbol)
	{
		for (DagArgumentIterator fi(fairSetDag); fi.valid(); fi.next())
			result.push_back(parseFairnessDag(fi.argument()));
	}
	else
	{
		if (fairSetDag->symbol() != emptyFairnessSetSymbol)
			throw invalid_argument(StringStream() << "fairness condition " <<
					QUOTE(fairSetDag) << " did not reduce to a valid term.");
	}
	return result;
}

FairnessDecoder::FairCond
FairnessDecoder::parseFairnessDag(DagNode* fairnessDag) const
{
	Assert(fairnessDag->symbol() == fairnessSymbol, "FairnessDecoder::interpretFairnessDag: invalid fairness formula");
	FreeDagNode* d = static_cast<FreeDagNode*>(fairnessDag);
	LogicFormula premF, consF;

	set<unsigned int> propIds;
	bdd prem = fBuilder.translateFairnessFormula(fBuilder.build(premF,
			propTable.getDagNodeSet(), d->getArgument(1)), premF, propIds);
	bdd cons = fBuilder.translateFairnessFormula(fBuilder.build(consF,
			propTable.getDagNodeSet(), d->getArgument(2)), consF, propIds);
	propTable.updatePropTable();

	if (d->getArgument(0)->symbol() == weakFairTypeSymbol)
		return make_tuple(vector<unsigned int>(propIds.begin(),propIds.end()), bdd_true(), prem>>cons, fairnessDag);
	else
		return make_tuple(vector<unsigned int>(propIds.begin(),propIds.end()), prem,cons,fairnessDag);
}

}
