//
//	Implementation of match compilation for AC and ACU theories.
//	Part 0: See if the pattern falls into one of several common cases
//	where we can try a fast heuristic.
//
#include "ACU_VarLhsAutomaton.hh"
#include "ACU_NGA_LhsAutomaton.hh"
#include "ACU_GndLhsAutomaton.hh"
#include "ACU_AlienAlienLhsAutomaton.hh"
#include "ACU_NonLinearLhsAutomaton.hh"

LhsAutomaton*
ACU_Term::compileLhs2(bool matchAtTop,
		      const VariableInfo& variableInfo,
		      NatSet& boundUniquely,
		      bool& subproblemLikely)
{
  HeuristicLhsAutomaton* h = 0;
  if (argArray.length() == 1)  // need to check if greediness is safe and var bound unlikely
    h = tryToMakeNonLinearLhsAutomaton(matchAtTop, variableInfo, boundUniquely);
  else if (argArray.length() == 2 &&
	   argArray[0].multiplicity == 1 &&
	   argArray[1].multiplicity == 1 &&
	   (!matchAtTop || collapseSymbols().empty()))  // don't handle collapses at the top
    {
      h = tryToMakeCollectorLhsAutomaton(matchAtTop, variableInfo, boundUniquely, 0);
      if (h == 0)
	{
	  h = tryToMakeCollectorLhsAutomaton(matchAtTop, variableInfo, boundUniquely, 1);
	  if (h == 0)
	    h = tryToMakeAlienAlienLhsAutomaton(variableInfo, boundUniquely);
	}
    }
  LhsAutomaton* f = compileLhs3(matchAtTop, variableInfo, boundUniquely, subproblemLikely);
  if (h == 0)
    {
      DebugAdvisory(*this << ": failed to produce heuristic ACU automaton for " << this);
      return f;
    }
  h->complete(f);
  return h;
}

ACU_NonLinearLhsAutomaton*
ACU_Term::tryToMakeNonLinearLhsAutomaton(bool matchAtTop,
					 const VariableInfo& variableInfo,
					 NatSet& boundUniquely)
{
  VariableTerm* v = dynamic_cast<VariableTerm*>(argArray[0].term);
  if (v == 0)
    return 0;
  ACU_Symbol* s = symbol();
  int vi = v->getIndex();
  Sort* vs = v->getSort();
  //
  //	Non linear variable should:
  //	(1) be unbound at match time (can't guarantee this of course);
  //	(2) not occur in condition (unless we have no extension);
  //	(3) not occur elsewhere in lhs (unless we have no extension);
  //	(4) have unit or pure sort w.r.t. top symbol; and
  //	(5) not be able to take identity.
  //
  if (boundUniquely.contains(vi) ||
      (matchAtTop && (variableInfo.getConditionVariables().contains(vi) ||
		      v->occursInContext().contains(vi))) ||
      (s->sortBound(vs) > 1 && s->sortStructure(vs) != AssociativeSymbol::PURE_SORT) ||
      s->takeIdentity(vs))
    return 0;
  return new ACU_NonLinearLhsAutomaton(s, vi, argArray[0].multiplicity, vs);
}

ACU_AlienAlienLhsAutomaton*
ACU_Term::tryToMakeAlienAlienLhsAutomaton(const VariableInfo& variableInfo,
					  NatSet& boundUniquely)
{
  for (int i = 0; i < 2; i++)
    {
      //
      //	Both subterms should be aliens which:
      //	(1) are non-ground;
      //	(2) are stable;
      //	(3) are not abstracted (might match identity); and
      //	(4) are greedySafe() (not contain unbound bad variables).
      //
      Term* t = argArray[i].term;
      if (t->ground() || !(t->stable()) ||
	  argArray[i].abstractionVariableIndex != NONE ||
	  !(t->greedySafe(variableInfo, boundUniquely)))
	return 0;
    }
  //
  //	Also the 1st term must guarantee early match failure on any instance
  //	of 2nd term or 2nd term must subsume 1st term.
  //
  Term* t1 = argArray[0].term;
  Term* t2 = argArray[1].term;
  if (!(t1->earlyMatchFailOnInstanceOf(t2) || t2->subsumes(t1, true)))
    {
      if (!(t2->earlyMatchFailOnInstanceOf(t1) || t1->subsumes(t2, true)))
	return 0;
      Term* t = t1;
      t1 = t2;
      t2 = t;
    }
  //
  //	Also subproblems must be unlikely from both subautomata.
  //
  NatSet local(boundUniquely);
  bool spl;
  LhsAutomaton* a1 = t1->compileLhs(false, variableInfo, local, spl);
  if (spl)
    {
      delete a1;
      return 0;
    }
  LhsAutomaton* a2 = t2->compileLhs(false, variableInfo, local, spl);
  if (spl)
    {
      delete a1;
      delete a2;
      return 0;
    }
  return new ACU_AlienAlienLhsAutomaton(symbol(),
					t1->symbol(), a1, t2->symbol(), a2,
					variableInfo.getNrProtectedVariables());
}
  
ACU_CollectorLhsAutomaton*
ACU_Term::tryToMakeCollectorLhsAutomaton(bool matchAtTop,
					 const VariableInfo& variableInfo,
					 NatSet& boundUniquely,
					 int collectorCandidate)
{
  //
  //	First check collector.
  //
  VariableTerm* c = dynamic_cast<VariableTerm*>(argArray[collectorCandidate].term);
  if (c == 0)
    return 0;
  int ci = c->getIndex();
  //
  //	Collector variable should:
  //	(1) be unbound at match time (can't guarantee this of course); and
  //	(2) have limit or pure sort w.r.t. top symbol.
  //	Unless stripper is a ground term and there is no extension (i.e.
  //	there will be a unique match we also require that variable should:
  //	(3) not occur in condition; and
  //	(4) not occur elsewhere in lhs.
  //
  if (boundUniquely.contains(ci) ||
      symbol()->sortStructure(c->getSort()) < AssociativeSymbol::LIMIT_SORT)
    return 0;
  bool needAllCollectorSolutions =
    variableInfo.getConditionVariables().contains(ci) ||
    c->occursInContext().contains(ci);
  if (matchAtTop && needAllCollectorSolutions)
    return 0;
  //
  //	Then check stripper.
  //
  Term* t = argArray[1 - collectorCandidate].term;
  if (t->ground())
    return new ACU_GndLhsAutomaton(symbol(), !(collapseSymbols().empty()), t, c);
  if (needAllCollectorSolutions)
    return 0;

  VariableTerm* v = dynamic_cast<VariableTerm*>(t);
  if (v != 0)
    {
      //
      //	Stripper variable should:
      //	(1) be unbound at match time (can't guarantee this of course);
      //	(2) not occur in condition;
      //	(3) not occur elsewhere in lhs;
      //	(4) have unit or pure sort w.r.t. top symbol; and
      //	(5) not be able to take identity.
      //
      int vi = v->getIndex();
      if (boundUniquely.contains(vi) ||
	  variableInfo.getConditionVariables().contains(vi) ||
	  v->occursInContext().contains(vi))
	return 0;
      const Sort* vs = v->getSort();
      if (!(symbol()->sortBound(vs) == 1 ||
	    symbol()->sortStructure(vs) == AssociativeSymbol::PURE_SORT) ||
	  symbol()->takeIdentity(vs))
	return 0;
      return new ACU_VarLhsAutomaton(symbol(), !(collapseSymbols().empty()), v, c);
    }
  //
  //	Non ground stripper term should:
  //	(1) be stable;
  //	(2) not be abstracted (might match identity);
  //	(3) be greedySafe (not contain unbound bad variables); and
  //	(4) not be likely to return subproblems
  //
  if (!(t->stable()) ||
      argArray[1 - collectorCandidate].abstractionVariableIndex != NONE ||
      !(t->greedySafe(variableInfo, boundUniquely)))
    return 0;
  NatSet local(boundUniquely);
  bool spl;
  LhsAutomaton* a = t->compileLhs(false, variableInfo, local, spl);
  if (spl)
    {
      delete a;
      return 0;
    }
  return new ACU_NGA_LhsAutomaton(symbol(), !(collapseSymbols().empty()), a,
				  t, variableInfo.getNrProtectedVariables(), c);
}
