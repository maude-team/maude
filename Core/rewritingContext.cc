//
//	Implementation for class RewritingContext.
//
#ifdef __GNUG__
#pragma implementation
#endif

//	utility stuff
#include "macros.hh"
#include "vector.hh"

//	forward declarations
#include "interface.hh"
#include "core.hh"

//	interface class definitions
#include "symbol.hh"
#include "dagNode.hh"

//	core class definitions
#include "rewritingContext.hh"

#include "run.cc"

bool RewritingContext::traceFlag = false;

void
RewritingContext::markReachableNodes()
{
  Assert(rootNode != 0, cerr << "null root");
  rootNode->mark();
  int nrFragile = nrFragileBindings();
  for (int i = 0; i < nrFragile; i++)
    {
      DagNode* d = value(i);
      if (d != 0)
	d->mark();     
    }
  int stackLength = redexStack.length();
  for (int i = 0; i < stackLength; i++)
    redexStack[i].node()->mark();
}

RewritingContext*
RewritingContext::makeSubcontext(DagNode* root, int /* purpose */)
{
  return new RewritingContext(root);
}

int
RewritingContext::traceBeginEqTrial(DagNode* /* subject */, const Equation* /* equation */)
{
  return 0;
}

int
RewritingContext::traceBeginRuleTrial(DagNode* /* subject */, const Rule* /* rule */)
{
  return 0;
}

int
RewritingContext::traceBeginScTrial(DagNode* /* subject */, const SortConstraint* /* sc */)
{
  return 0;
}

void
RewritingContext::traceEndTrial(int /* trailRef */, bool /* success */)
{
}

void
RewritingContext::traceExhausted(int /* trialRef */)
{
}

void
RewritingContext::tracePreEqRewrite(DagNode* /* redex */,
				    const Equation* /* equation */,
				    int /* type */)
{
}

void
RewritingContext::tracePostEqRewrite(DagNode* /* replacement */)
{
}

void
RewritingContext::tracePreRuleRewrite(DagNode* /* redex */, const Rule* /* rule */)
{
}

void
RewritingContext::tracePostRuleRewrite(DagNode* /* replacement */)
{
}

void
RewritingContext::tracePreScApplication(DagNode* /* subject */, const SortConstraint* /* sc */)
{
}

bool
RewritingContext::traceAbort()
{
  return false;
}

void
RewritingContext::traceBeginFragment(int /* trialRef */,
				     const PreEquation* /* preEquation */,
				     int /* fragmentIndex */,
				     bool /* firstAttempt */)
{
}

void
RewritingContext::traceEndFragment(int /* trialRef */,
				   const PreEquation* /* preEquation */,
				   int /* fragmentIndex */,
				   bool /* success */)
{
}

void
RewritingContext::rebuildUptoRoot()
{
  //  cout << "\nroot was " << rootNode << endl;
  //  cout << "rebuilding from " << currentIndex << endl;
  Assert(currentIndex >= 0, cerr << "bad currentIndex");
  //
  //	Locate deepest stack node  with a stale parent.
  //
  int c = currentIndex;  // all staleness guaranteed to be above currentIndex
  for (int i = redexStack[c].parentIndex(); i != staleMarker; i = redexStack[i].parentIndex())
    c = i;
  //
  //	We assume that we only have to rebuild the spine from
  //	staleMarker to root.
  //
  for (int i = staleMarker; i != UNDEFINED; i = redexStack[i].parentIndex())
    {
      remakeStaleDagNode(i, c);
      c = i;
    }
  rootNode = redexStack[0].node();
  staleMarker = ROOT_OK;
  //  cout << "root is " << rootNode << endl;
}

void
RewritingContext::remakeStaleDagNode(int staleIndex, int childIndex)
{
  //
  //	Find first stacked argument of stale dag node.
  //
  int first = childIndex;
  while (redexStack[first - 1].parentIndex() == staleIndex)
    --first;
  //
  //	Find last stacked argument of stale dag node.
  //
  int last = childIndex;
  int stackLength = redexStack.length();
  while (last + 1 < stackLength &&
	 redexStack[last + 1].parentIndex() == staleIndex)
    ++last;
  //
  //	Replace stale dag node with a copy in which stacked arguments
  //	replace corresponding arguments in original.
  //
  DagNode* remade = redexStack[staleIndex].node()->
    copyWithReplacement(redexStack, first, last);
  redexStack[staleIndex].replaceNode(remade);
}

#ifdef DUMP
void
RewritingContext::dumpStack(ostream& s, const Vector<RedexPosition>& stack)
{
  int stackLen = stack.length();
  for (int i = 0; i < stackLen; i++)
    {
      s << stack[i].parentIndex() << '\t' <<
	stack[i].argIndex() << '\t' <<
	stack[i].node() << '\n';
    }
}
#endif
