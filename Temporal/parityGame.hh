//
//	Class for solving parity games with 3 priorities.
//
//	We implement the modified version of Jurdzinski's lifting
//	algorithm from:
//	  Kousha Etessami, Thomas Wilke and Rebecca A. Schuller.
//	  "Fair Simulation Relations, Parity Games and
//	   State Space Reduction for Buchi Automata",
//	  ICALP 2001, LNCS 2076, pp 694-707, 2001.
//
#ifndef _parityGame_hh_
#define _parityGame_hh_
#ifdef __GNUG__
#pragma interface
#endif

class ParityGame
{
public:
  ParityGame();

  int makeNode(int player, int priority);
  void insertArc(int from, int to);
  void solve();
  bool winForPlayer0(int nodeNr);

private:
  struct Node
  {
    Vector<int> fwdArcs;	// available moves
    Vector<int> bkwdArcs;	// nodes which can get to us
    int player;		// player who has to move, 0 or 1
    int priority;	// 0, 1 or 2
    //
    //	The following stuff is updated on-the-fly.
    //
    bool pending;	// on the pending queue
    int best;
    int count;
    int rho;
  };

  void lift(Node& v);

  Vector<Node> nodes;
  int nrNodesWithPriority1;
};

bool
ParityGame::winForPlayer0(int nodeNr)
{
  return nodes[nodeNr].rho < UNBOUNDED;
}

#endif
