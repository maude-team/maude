
/************************************************
 ** SCP Parsing Algorithm                      **
 **  	Maude Implementation                   **
 **		Jose F. Quesada                **
 **		CSL - SRI Int.  1998           **
 ************************************************/

/*******
 ******* scp_kernel.hh
 *******/

#ifndef _scp_kernel_hh_
#define _scp_kernel_hh_

class ScpBaseNT
{
  friend class ScpParser;
  int	smallestPrec;
  int	largestPrec;
  int	firstAbs;
  int	lastAbs;
};

class ScpAbslNT
{
  friend class ScpParser;
  int	baseNT;
  int	precNT;
  int	nextNT;
  int	lhsdefs;
  char  adjbubble;
  int	bubblecov;
  int   bubbletermn;
  int   bubbleev;
};

class ScpProdtn
{
  friend class ScpParser;
  int	lhs;
  int	lrhs;
  int	rhs;
  int   lgather;
  int	bubble;	
};

class ScpCov
{
  friend class ScpParser;
  int	prodtn;
  int	next;
  int   ldernext;
};

class ScpBubble
{
  friend class ScpParser;
  int	abslnt;
  int	lbound;
  int	ubound;
  int	lparen;
  int 	rparen;
  int   addrbubexcept;
  int	except;
  int	lexcept;
  int	prodtn;
};

class ScpEvent
{
  friend class ScpParser;
  int   prodtn;
  int   dot;
  int   fpos;
  int   nextsymbol;
  int   addrnextsymbol;
  int   nextevent;
  int   subsumed;
  int   prevevent;
  int   prevnode;
};

class ScpNode
{
  friend class ScpParser;
  int   fpos;
  int   lpos;
  int   symbol;
  int   nextnode;
  int   initanal;
  int   skipanal;
};

class ScpAnal
{
  friend class ScpParser;
  int prodtn;
  int prevnode;
  int prevevent;
  int nextanal;
};

#endif // _scp_kernel_hh
