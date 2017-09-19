/*
 * PropositionTable.hh
 *
 *  Created on: Aug 19, 2013
 *      Author: kquine
 */

#ifndef PROPOSITIONTABLE_HH_
#define PROPOSITIONTABLE_HH_
#include <memory>
#include <vector>
#include "protectedDagNodeSet.hh"
#include "Interface/PropInterpreter.hh"

namespace modelChecker {

class PropositionTable: private ProtectedDagNodeSet
{
public:
	explicit PropositionTable(const PropInterpreter& pi);
	virtual ~PropositionTable() = default;

	using ProtectedDagNodeSet::insert;
	using ProtectedDagNodeSet::dagNode2Index;
	using ProtectedDagNodeSet::cardinality;
	using ProtectedDagNodeSet::index2DagNode;

	void updatePropTable();

	unsigned int cardinality()							{ return ProtectedDagNodeSet::cardinality(); }
	virtual bool hasParamProp() const					{ return false; }
	virtual bool isParamProp(unsigned int) const		{ return false; }

	bool isStateProp(unsigned int propId) const			{ return !isEventProp(propId) && !isEnabledProp(propId); }
	bool isEventProp(unsigned int propId) const			{ return propInfoTable[propId]->isEvent; }
	bool isEnabledProp(unsigned int propId) const		{ return propInfoTable[propId]->enabledEventId != NONE; }

	int getEnabledEventId(unsigned int propId) const	{ return propInfoTable[propId]->enabledEventId; }
	DagNodeSet& getDagNodeSet()							{ return *this; }

protected:
	struct PropInfo
	{
		PropInfo(bool isEvent, int enabledEvtId): isEvent{isEvent}, enabledEventId{enabledEvtId} {}
		virtual ~PropInfo() = default;

		bool isEvent;
		int enabledEventId;
	};
	virtual void updatePropInfo(unsigned int propId);

	vector<unique_ptr<PropInfo>> propInfoTable;		// global prop id |-> propInfo

private:
	int checkEnabled(DagNode* propDag);

	unsigned int minIndex = 0;				// the minimum index that has not been updated
    const PropInterpreter& pInterpreter;
};

} /* namespace modelChecker */
#endif /* PROPOSITIONTABLE_HH_ */
