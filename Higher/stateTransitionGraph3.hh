//
//	Class for building a state transition graph on-the-fly.
//
#ifndef _stateTransitionGraph3_hh_
#define _stateTransitionGraph3_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include <set>
#include <map>
#include "simpleRootContainer.hh"
#include "dagNodeSet.hh"
#include "rewritingContext.hh"

class StateTransitionGraph3 : private SimpleRootContainer
{
  NO_COPYING(StateTransitionGraph3);

public:
  typedef map<int, set<Rule*> > ArcMap;

  StateTransitionGraph3(RewritingContext* initial);
  ~StateTransitionGraph3();

  int getNrStates() const;
  int getNextState(int stateNr, int index);
  DagNode* getStateDag(int stateNr) const;
  const ArcMap& getStateFwdArcs(int stateNr) const;
  //
  //	Stuff needed for search.
  //
  RewritingContext* getContext();
  void transferCount(RewritingContext& recipient);
  int getStateParent(int stateNr) const;

private:
  struct State
  {
    Vector<int> nextStates;
    RewriteSearchState* rewriteState;
    bool fullyExplored;
    ArcMap fwdArcs;
    int parent;
  };

  void markReachableNodes();
  void insertNewState(int parent);

  RewritingContext* initial;
  Vector<State*> seen;
  DagNodeSet seenSet;
};

inline int
StateTransitionGraph3::getNrStates() const
{
  return seen.length();
}

inline DagNode*
StateTransitionGraph3::getStateDag(int stateNr) const
{
  return seenSet.index2DagNode(stateNr);
}

inline const StateTransitionGraph3::ArcMap&
StateTransitionGraph3::getStateFwdArcs(int stateNr) const
{
  return seen[stateNr]->fwdArcs;
}

inline RewritingContext*
StateTransitionGraph3::getContext()
{
  return initial;
}

inline void
StateTransitionGraph3::transferCount(RewritingContext& recipient)
{
  recipient.addInCount(*initial);
  initial->clearCount();
}

inline int
StateTransitionGraph3::getStateParent(int stateNr) const
{
  return seen[stateNr]->parent;
}

#endif
