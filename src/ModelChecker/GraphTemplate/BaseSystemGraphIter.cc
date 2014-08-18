/*
 * BaseSystemGraphIter.cc
 *
 *  Created on: Aug 27, 2013
 *      Author: kquine
 */

#include "BaseSystemGraphIter.hh"

namespace modelChecker {

template <typename T>
BaseSystemGraphIter<T>::BaseSystemGraphIter(RewritingContext& initial, const PropositionTable& propTable):
	BaseSystemGraph<T>(initial,propTable) {}

template <class T> inline unsigned int
BaseSystemGraphIter<T>::getNrVisitedStates() const	// count only visited states
{
	return this->getNrStates();
}

template <class T> inline unsigned int
BaseSystemGraphIter<T>::getNrVisitedTransitions(unsigned int stateNr) const
{
	return this->getNrTransitions(stateNr);
}

template <typename T> unsigned int
BaseSystemGraphIter<T>::insertState(DagNode* stateDag)
{
	auto nextState = static_cast<T*>(this)->stateDag2index(stateDag);
	if (nextState == this->seen.size())	// if a new state identified
	{
		DagNode* cannStateDag = this->getStateDag(nextState);
		unique_ptr<State> s(new State);
		s->explore.reset(new ActiveState(this->context,stateDag));
		static_cast<T*>(this)->updateStateLabel(cannStateDag, *s);
		this->seen.push_back(std::move(s));
	}
	return nextState;
}

template <typename T> int
BaseSystemGraphIter<T>::computeNextState(unsigned int stateNr, unsigned int index)
{
	Assert(stateNr < this->seen.size() && this->seen[stateNr], "BaseSystemGraphIter::computeNextState: invalid state lookup");

	State& n = *this->seen[stateNr];
	auto nrTransitions = this->getNrTransitions(stateNr);

	if (index < nrTransitions)
		return n.transitions[index]->nextState;

	if (! n.explore)
		return NONE;	// fully explored

	while (nrTransitions <= index)
	{
		// if there is a next state
		if (DagNode* ns = n.explore->getNextStateDag(this->context))
		{
			auto nextState = static_cast<T*>(this)->insertState(ns);
			if (static_cast<T*>(this)->insertTransition(nextState, n, ns))	// if a new transition identified
				++ nrTransitions;
			MemoryCell::okToCollectGarbage();
		}
		else
		{
			if (nrTransitions == 0 && index == 0)	// deadlock: add a fake self loop
			{
				static_cast<T*>(this)->insertDeadlockTransition(stateNr, n);
				n.explore.reset();
				return stateNr;
			}
			else
			{
				n.explore.reset();			// remove active state
				return NONE;				// no more transition,, (fully explored transitions)
			}
		}
	}
	return n.transitions[index]->nextState;
}


} /* namespace modelChecker */
