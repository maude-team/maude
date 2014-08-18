/*
 * StateMetaGraph.hh
 *
 *  Created on: Nov 15, 2011
 *      Author: kquine
 */

#ifndef STATEMETAGRAPH_HH_
#define STATEMETAGRAPH_HH_
#include "Graph/StateSystemGraph.hh"
#include "GraphLabel/StatePropLabel.hh"
#include "Utility/ptr_set.hh"

namespace modelChecker {

class StateMetaGraph;

template <>
struct SystemGraphTraits<StateMetaGraph>: public SystemGraphTraits<StateSystemGraph<StatePropLabel>>
{
	struct State;
	struct Transition;
	struct ActiveState;
	SystemGraphTraits(unique_ptr<StatePropLabel>&& spl): SystemGraphTraits<StateSystemGraph<StatePropLabel>>(move(spl)) {}
};

/*
 * Generate a graph using Meta rules, given by:
 *   rl [State] => Transition' |->[State']
 * where "[_] : State -> Top" and "_|->[_] : Transition State -> Top".
 */
class StateMetaGraph:
		public BaseSystemGraphIter<StateMetaGraph>,
		private SystemGraphTraits<StateMetaGraph>
{
	friend class BaseSystemGraph<StateMetaGraph>;
	friend class BaseSystemGraphIter<StateMetaGraph>;

	using Traits =		SystemGraphTraits<StateMetaGraph>;
	using size_type =	vector<int>::size_type;
	using typename Traits::ActiveState;


public:
	using typename Traits::State;
	using typename Traits::Transition;

	StateMetaGraph(unique_ptr<StatePropLabel>&& spl, RewritingContext& initial,
			const PropositionTable& propTable, Symbol* stateSymbol, Symbol* transitionSymbol, DagNode* deadlockDag);

private:
	using Traits::satisfiesStateProp;					/* implements */
	using Traits::satisfiesEventProp;					/* implements */
	using Traits::updateStateLabel;						/* implements */
	//
	//  state and transition dags
	//
	DagNode* index2StateDag(size_type index) const;										/* implements */
	DagNode* makeTransitionDag(const Transition& t, DagNode*, RewritingContext&) const;	/* implements */
	//
	//  state and transition indices
	//
	unsigned int dag2index(DagNode* dag, int info);								/* new implementation */
	unsigned int insertState(DagNode* metaDag);									/* override (non-virtual) */
	bool insertTransition(unsigned int nextState, State& n, DagNode* metaDag);	/* implements (non-const) */
	void insertDeadlockTransition(unsigned int stateNr, State& n);				/* implements (non-const) */
	//
	// symbols for meta-graph
	//
	Symbol* stateSymbol;
	Symbol* transitionSymbol;
	DagNode* deadlockDag;
	//
	// hash-cons information
	//
	vector<int> hashCons2dagIndex;		// partial map of hashCons indices to dag info
	HashConsSet hashConsSet;
	static const int transId = -11;
};


/**
 * State information
 */
struct SystemGraphTraits<StateMetaGraph>::State:
	public BaseSystemGraphIterTraits::State<ActiveState,Transition>, public StatePropLabel::StateLabel
{
	State(int hashConsIndex): hashConsIndex(hashConsIndex) {}
	const unsigned int hashConsIndex;
};


/**
 * Transition information
 */
struct SystemGraphTraits<StateMetaGraph>::Transition: public BaseSystemGraphIterTraits::Transition

{
	Transition(unsigned int nextState, unsigned int hashConsIndex):
		BaseSystemGraphIterTraits::Transition{nextState}, hashConsIndex(hashConsIndex) {}
	bool operator<(const Transition& t) const {
		return BaseSystemGraphIterTraits::Transition::operator<(t) || hashConsIndex < t.hashConsIndex;
	}
	const unsigned int hashConsIndex;
};


/**
 * The information that is used only during graph search.
 */
struct SystemGraphTraits<StateMetaGraph>::ActiveState: public BaseSystemGraphIterTraits::ActiveState, private DagRoot
{
	ActiveState(RewritingContext& context, DagNode* activeDag):
		BaseSystemGraphIterTraits::ActiveState(context,activeDag), DagRoot(activeDag) {}
	ptr_set<Transition> transitionPtrSet;	// to distinguish equivalent transitions
};


} /* namespace modelChecker */
#endif /* STATEMETAGRAPH_HH_ */
