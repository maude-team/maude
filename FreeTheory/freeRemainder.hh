//
//	Class for matching whats left of a pattern after free symbols have
//	been matched (could we derive FreeLhsAutomaton from this?).
//
#ifndef _freeRemainder_hh_
#define _freeRemainder_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include "freeLhsStructs.hh"

class FreeRemainder : private FreeLhsStructs
{
  NO_COPYING(FreeRemainder);

public:
  FreeRemainder(Equation* eqn,
		const Vector<FreeOccurrence>& freeSymbols,
		const Vector<FreeOccurrence>& freeVars,
		const Vector<FreeOccurrence>& boundVars,
		const Vector<FreeOccurrence>& gndAliens,
		const Vector<FreeOccurrence>& nonGndAliens,
		const Vector<int>& bestSequence,
		const Vector<LhsAutomaton*>& subAutomata,
		const Vector<int>& slotTranslation);
  FreeRemainder(Equation* eqn);  // trivial FreeRemainder for foreign equations
  ~FreeRemainder();

  bool fastMatchReplace(DagNode* subject,
			RewritingContext& context,
			Vector<DagNode**>& stack) const;
  bool slowMatchReplace(DagNode* subject,
			RewritingContext& context,
			Vector<DagNode**>& stack) const;

#ifdef DUMP
  void dump(ostream& s, int indentLevel = 0);
#endif

private:
  bool slowMatchReplace2(DagNode* subject,
			RewritingContext& context,
			Vector<DagNode**>& stack) const;
  //
  //	To qualify for "fast" treatment the associated equation must:
  //	(1) have a lhs that parses into a non-error sort
  //	(2) have only free symbols in lhs
  //	(3) be left linear
  //	(4) be unconditional
  //	(5) have no "problem" variables (ones which need their bindings copied to avoid
  //	    eager evaluation of lazy subterm)
  //	To qualify for "super-fast", additionally each variable must have a sort that
  //	is the unique maximal user sort in its component which must be error-free.
  //	
  //
  int fast;	// > 0 super-fast; < 0 fast; = 0 slow
  bool foreign;
  Equation* equation;
  Vector<FreeVariable> freeVariables;
  Vector<BoundVariable> boundVariables;
  Vector<GroundAlien> groundAliens;
  Vector<NonGroundAlien> nonGroundAliens;
};

inline bool 
FreeRemainder::fastMatchReplace(DagNode* subject,
				RewritingContext& context,
				Vector<DagNode**>& stack) const
{
  if (!(RewritingContext::getTraceStatus()))
    {
      if (fast > 0)
	{
	  Vector<DagNode**>::const_iterator stackBase =
	    const_cast<const Vector<DagNode**>&>(stack).begin();
	  Vector<FreeVariable>::const_iterator e = freeVariables.end();
	  for (Vector<FreeVariable>::const_iterator i = freeVariables.begin(); i != e; ++i)
	    {
	      DagNode* d = stackBase[i->position][i->argIndex];
	      Assert(d->getSortIndex() != Sort::SORT_UNKNOWN, cerr << "missing sort information");
	      context.bind(i->varIndex, d);
	    }
	}
      else if (fast < 0)
	{
	  Vector<DagNode**>::const_iterator stackBase =
	    const_cast<const Vector<DagNode**>&>(stack).begin();
	  Vector<FreeVariable>::const_iterator e = freeVariables.end();
	  for (Vector<FreeVariable>::const_iterator i = freeVariables.begin(); i != e; ++i)
	    {
	      DagNode* d = stackBase[i->position][i->argIndex];
	      Assert(d->getSortIndex() != Sort::SORT_UNKNOWN, cerr << "missing sort information");
	      if (d->leq(i->sort))
		context.bind(i->varIndex, d);
	      else
		return false;
	    }
	}
      else
	goto slow;
      equation->getRhsBuilder().replace(subject, context);
      context.incrementEqCount();
      DagNode::okToCollectGarbage();
      return true;
    }
slow:
  return slowMatchReplace(subject, context, stack);
}

#endif
