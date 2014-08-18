/*
 * BaseSystemGraphOnce.cc
 *
 *  Created on: Sep 23, 2013
 *      Author: kquine
 */

#include "BaseSystemGraphOnce.hh"

namespace modelChecker {

template <typename T>
BaseSystemGraphOnce<T>::BaseSystemGraphOnce(RewritingContext& initial, const PropositionTable& propTable):
	BaseSystemGraph<T>(initial,propTable) {}

template <class T> inline unsigned int
BaseSystemGraphOnce<T>::getNrVisitedStates() const	// count only visited states
{
	return count_if(this->seen.begin(), this->seen.end(), [] (const unique_ptr<State>& s) { return bool(s); });
}

template <class T> inline unsigned int
BaseSystemGraphOnce<T>::getNrVisitedTransitions(unsigned int stateNr) const
{
	Assert(stateNr < this->seen.size(), "BaseSystemGraph::getNrVisitedStates: invalid state lookup");
	return this->seen[stateNr]? this->seen[stateNr]->nrVisited : 0;
}

template <typename T> unsigned int
BaseSystemGraphOnce<T>::insertState(DagNode* stateDag)
{
	return enableState(static_cast<T*>(this)->stateDag2index(stateDag));
}

template <typename T> int
BaseSystemGraphOnce<T>::computeNextState(unsigned int stateNr, unsigned int index)
{
	Assert(stateNr < this->seen.size(), "BaseSystemGraphOnce::computeNextState: Invalid state lookup");
	if (index >= this->getNrTransitions(stateNr))
		return NONE;
	else
	{
		if ( index >= this->seen[stateNr]->nrVisited )
			this->seen[stateNr]->nrVisited = index + 1;
		return enableState(this->seen[stateNr]->transitions[index]->nextState);
	}
}

template <typename T> int
BaseSystemGraphOnce<T>::enableState(unsigned int stateNr)
{
	if ( stateNr >= this->seen.size() )
		this->seen.resize(stateNr + 1);

	if ( !this->seen[stateNr] )		// if not already "enabled"
	{
		DagNode* cannStateDag = this->getStateDag(stateNr);
		RewriteTransitionState rts(this->context, cannStateDag);
		unique_ptr<State> s(new State);

		unsigned int transitionCount = 0;
		vector<unique_ptr<Transition>> trs;
		vector<DagNode*> proofDags;
		ptr_set<Transition> transitionPtrSet;	// to distinguish equivalent transitions
		ProtectedDagNodeSet tdags;		// to protect proofDags from the garbage collection.

		while (DagNode* ns =  rts.getNextStateDag(this->context))	// compute all transitions
		{
			auto nextState = static_cast<T*>(this)->stateDag2index(ns);
			trs.emplace_back(new Transition(nextState, ++ transitionCount));

			// identify a unique proof dag
			DagNode* td = static_cast<T*>(this)->makeProofDag(rts);
			auto di = tdags.dagNode2Index(td);
			if (di == NONE)
			{
				di = tdags.cardinality();
				tdags.insert(td);
			}

			proofDags.push_back(tdags.index2DagNode(di));
			MemoryCell::okToCollectGarbage();
		}

		if (transitionCount == 0)	// deadlock: add a fake self loop
		{
			Assert(proofDags.empty() && trs.empty(), "BaseSystemGraphOnce::enableState: invalid deadlock");
			trs.emplace_back(new Transition(stateNr, 0)); // 0 indicates a deadlock transition!
			DagNode* td = static_cast<T*>(this)->getDeadlockDag();
			proofDags.push_back(td);
		}

		static_cast<T*>(this)->updateAllLabels(cannStateDag, proofDags, *s, trs);

		for (auto& tr : trs)
		{
			if (transitionPtrSet.insert(tr.get()).second)	// if a new transition identified
				s->transitions.push_back(move(tr));				// NOTE: transfer ownership..
		}
		this->seen[stateNr] = move(s);
	}
	return stateNr;		// return an integer version to compare with NONE later..
}


} /* namespace modelChecker */
