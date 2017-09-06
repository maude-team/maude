//
//	Implementation for class ParityGame.
//
#ifdef __GNUG__
#pragma implementation
#endif
#include <queue>

//	utility stuff
#include "macros.hh"
#include "vector.hh"

#include "parityGame.hh"

ParityGame::ParityGame()
{
  nrNodesWithPriority1 = 0;
}

int
ParityGame::makeNode(int player, int priority)
{
  Assert(player == 0 || player == 1, cerr << "bad player");
  Assert(priority >= 0 && priority <= 2, cerr << "bad priority");

  int t = nodes.length();
  nodes.expandBy(1);
  nodes[t].player = player;
  nodes[t].priority = priority;
  if (priority == 1)
    ++nrNodesWithPriority1;
  return t;
}
    
void
ParityGame::insertArc(int from, int to)
{
  nodes[from].fwdArcs.append(to);
  nodes[to].bkwdArcs.append(from);
}

void
ParityGame::lift(Node& v)
{
  int m = UNDEFINED;
  int nrFwdArcs = v.fwdArcs.length();
  if (v.player == 0)
    {
      //
      //	Set m to the least rho of our successors.
      //
      for (int i = 0; i < nrFwdArcs; i++)
	{
	  int rho = nodes[v.fwdArcs[i]].rho;
	  if (m == UNDEFINED || rho < m)
	    m = rho;
	}
    }
  else
    {
      //
      //	Set m to the greatest rho of our successors.
      //
      for (int i = 0; i < nrFwdArcs; i++)
	{
	  int rho = nodes[v.fwdArcs[i]].rho;
	  if (m == UNDEFINED || rho > m)
	    m = rho;
	}
    }
  //
  //	m := <m>_{p(v)}
  //
  if (v.priority == 0 && m != UNBOUNDED)
    m = 0;
  //
  //	m now holds val(rho, v); update the values of v.best and v.count
  //
  v.best = m;
  int count = 0;
  if (v.priority == 0 && m == 0)
    {
      for (int i = 0; i < nrFwdArcs; i++)
	{
	  if (nodes[v.fwdArcs[i]].rho != UNBOUNDED)
	    ++count;
	}
    }
  else
    {
      for (int i = 0; i < nrFwdArcs; i++)
	{
	  if (nodes[v.fwdArcs[i]].rho == m)
	    ++count;
	}
    }
  v.count = count;
  //
  //	m := incr_{p(v)}(m)
  //
  if (v.priority == 1)
    {
      if (m == nrNodesWithPriority1)
	m = UNBOUNDED;
      else if (m != UNBOUNDED)
	++m;
    }
  v.rho = m;
}

void
ParityGame::solve()
{
  queue<int> pending;
  {
    //
    //	Initialize queue and calculated on-the-fly values.
    //
    int nrNodes = nodes.length();
    for (int i = 0; i < nrNodes; i++)
      {
	Node& v = nodes[i];
	v.best = 0;
	v.count = v.fwdArcs.length();
	v.rho = 0;
	if (v.priority == 1)
	  {
	    pending.push(i);
	    v.pending = true;
	  }
	else
	  v.pending = false;
      }
  }
  //
  //	While there are still pending nodes, choose one and `lift' it.
  //
  while (!(pending.empty()))
    {
      Node& v = nodes[pending.front()];
      pending.pop();
      v.pending = false;
      int t = v.rho;
      lift(v);
      //
      //	Find candidates for lifting.
      //
      int nrBkwdArcs = v.bkwdArcs.length();
      for (int i = 0; i < nrBkwdArcs; i++)
	{
	  Node& w = nodes[v.bkwdArcs[i]];
	  if (!(w.pending))
	    {
	      if (w.player == 0)
		{
		  if (t == w.best && --(w.count) == 0)
		    {
		      pending.push(i);
		      w.pending = true;
		    }
		}
	      else
		{
		  if (v.rho == w.best)
		    ++(w.count);
		  else if (v.rho > w.best)
		    {
		      pending.push(i);
		      w.pending = true;
		    }
		}
	    }
	}
    }
}
