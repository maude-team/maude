/*
 * BaseSystemGraph.cc
 *
 *  Created on: Aug 14, 2013
 *      Author: kquine
 */

// utility stuff
#include "macros.hh"
#include "vector.hh"

// forward declarations
#include "interface.hh"
#include "core.hh"

// ltlr definitions
#include "Utility/BddUtil.hh"
#include "BaseSystemGraph.hh"

namespace modelChecker {

template <class T>
BaseSystemGraph<T>::BaseSystemGraph(RewritingContext& initial, const PropositionTable& propTable):
	context(initial), propTable(propTable)
{
	initial.reduce();
}

template <class T> inline void
BaseSystemGraph<T>::init()
{
	static_cast<T*>(this)->insertState(context.root());
}

template <class T> inline DagNode*
BaseSystemGraph<T>::getStateDag(unsigned int stateNr) const
{
	return static_cast<const T*>(this)->index2StateDag(stateNr);
}

template <class T> inline DagNode*
BaseSystemGraph<T>::getTransitionDag(unsigned int stateNr, unsigned int index) const
{
	Assert(stateNr < seen.size() && seen[stateNr], "BaseSystemGraph::getTransitionDag: invalid state lookup");
	return static_cast<const T*>(this)->makeTransitionDag(
			*seen[stateNr]->transitions[index], this->getStateDag(stateNr), context);
}

template <class T> inline unsigned int
BaseSystemGraph<T>::getNrStates() const
{
	return seen.size();
}

template <class T> inline unsigned int
BaseSystemGraph<T>::getNrTransitions(unsigned int stateNr) const
{
	Assert(stateNr < seen.size(), "BaseSystemGraph::getNrTransitions: invalid state lookup");
	return seen[stateNr] ? seen[stateNr]->transitions.size() : 0;
}

template <class T> inline int
BaseSystemGraph<T>::getNextState(unsigned int stateNr, unsigned int index)
{
	return static_cast<T*>(this)->computeNextState(stateNr, index);
}

template <class T> inline bool
BaseSystemGraph<T>::satisfiesStateFormula(Bdd formula, unsigned int stateNr) const
{
	return BddUtil::satisfiesFormula(formula, [this,stateNr] (unsigned int propId)
	{
		return static_cast<const T*>(this)->satisfiesStateProp(propId, *seen[stateNr]);
	});
}

template <class T> inline bool
BaseSystemGraph<T>::satisfiesStateEventFormula(Bdd formula, unsigned int stateNr, unsigned int transitionNr) const
{
	auto check = [this,stateNr,transitionNr] (unsigned int propId)
	{
		return propTable.isEventProp(propId) ?
				  static_cast<const T*>(this)->satisfiesEventProp(propId, *seen[stateNr]->transitions[transitionNr])
				: static_cast<const T*>(this)->satisfiesStateProp(propId, *seen[stateNr]);
	};
	return BddUtil::satisfiesFormula(formula, check);
}


template <class T> inline pair<bool,Bdd>
BaseSystemGraph<T>::satisfiesPartialStateFormula(Bdd formula, unsigned int stateNr) const
{
	return BddUtil::satisfiesPartialFormula(formula,
			[this] (unsigned int propId) { return ! propTable.isEventProp(propId); },
			[this,stateNr] (unsigned int propId) {
				return static_cast<const T*>(this)->satisfiesStateProp(propId, *seen[stateNr]); });
}

inline bool
BaseSystemGraphTraits::Transition::operator<(const Transition& t) const
{
	return nextState < t.nextState;
}

} /* namespace modelChecker */
