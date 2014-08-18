/*
 * FairnessTable.hh
 *
 *  Created on: Aug 22, 2013
 *      Author: kquine
 */

#ifndef FAIRNESSTABLE_HH_
#define FAIRNESSTABLE_HH_
#include <map>
#include <set>
#include "natSet.hh"
#include "bdd.h"
#include "AbstractFairnessTable.hh"
#include "PropTable/PropositionTable.hh"

namespace modelChecker {

template <typename Formula> class FairnessTable;

using WeakFairnessTable	= 	FairnessTable<Bdd>;
using StrongFairnessTable = FairnessTable<pair<Bdd,Bdd>>;

template <typename Formula>
class FairnessTable: public AbstractFairnessTable
{
public:
	FairnessTable(PropositionTable& propTable);

	bool hasStrongFairness() const override;
	virtual bool isParamFairness(unsigned int) const	{ return false; }

	unsigned int nrFairness() const override			{ return fairTable.size();}
	const NatSet& getOrigFairnessIds() const			{ return origFairIds; }

	virtual const Formula& getFairFormula(unsigned int fairId) const;
	virtual bool isStateFairness(unsigned int fairId) const;
	bool isStateEventFairness(unsigned int fairId) const;

	unsigned int insertFairnessFormula(const Formula& f, const vector<unsigned int>& propIds, DagNode* fairDag);

protected:
	struct Fairness    // empty base class
	{
		virtual ~Fairness() = default;
	};

	struct GroundFairness: public Fairness
	{
		GroundFairness(const Formula& f, bool noEvent): formula(f), noEvent(noEvent) {}

		const Formula& formula;
		const bool noEvent;
	};

	virtual unique_ptr<GroundFairness> createFormulaFairness(const Formula& f,
			const vector<unsigned int>& propIds, DagNode* fairDag) const;

	vector<unique_ptr<Fairness>> fairTable;		// fairId |-> fairnessInfo

private:
	NatSet origFairIds;							// a set of original (ground or param) fair ids
	map<Formula,unsigned int> fairFormulas;		// fair formula |-> fair id

	PropositionTable& propTable;
};

template <> inline bool
FairnessTable<Bdd>::hasStrongFairness() const
{
	return false;
}

template <> inline bool
FairnessTable<pair<Bdd,Bdd>>::hasStrongFairness() const
{
	return nrFairness() > 0;
}

} /* namespace modelChecker */

#include "FairnessTable.cc"

#endif /* FAIRNESSTABLE_HH_ */
