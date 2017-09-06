//
//	Implementation for class AU_Term.
//

//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "variable.hh"
#include "AU_Theory.hh"

//      core class definitions
#include "variableTerm.hh"
#include "rewritingContext.hh"
#include "equation.hh"
#include "symbolMap.hh"
#include "termBag.hh"
#include "rhsBuilder.hh"

//	variable class definitions
#include "variableTerm.hh"

//	AU theory class definitions
#include "AU_Symbol.hh"
#include "AU_DagNode.hh"
#include "AU_Term.hh"
#include "AU_ArgumentIterator.hh"
#include "AU_LhsAutomaton.hh"
#include "AU_RhsAutomaton.hh"

#include "AU_LhsCompiler.cc"

AU_Term::AU_Term(AU_Symbol* symbol, const Vector<Term*>& arguments)
: Term(symbol), argArray(arguments.length())
{
  int nrArgs = arguments.length();
  Assert(nrArgs >= 2, "insufficient arguments");
  for (int i = 0; i < nrArgs; i++)
    argArray[i].term = arguments[i];
}

AU_Term::AU_Term(const AU_Term& original, SymbolMap* map)
: Term(map == 0 ? original.symbol() : map->translate(original.symbol())),
  argArray(original.argArray.length())
{
  int nrArgs = original.argArray.length();
  for (int i = 0; i < nrArgs; i++)
    argArray[i].term = original.argArray[i].term->deepCopy(map);
}

RawArgumentIterator*
AU_Term::arguments()
{
  return new AU_ArgumentIterator(argArray);
}

void
AU_Term::deepSelfDestruct()
{
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    argArray[i].term->deepSelfDestruct();
  delete this;
}

Term*
AU_Term::deepCopy2(SymbolMap* map) const
{
  return new AU_Term(*this, map);
}

Term*
AU_Term::normalize(bool full, bool& changed)
{
  changed = false;
  AU_Symbol* s = symbol();
  int nrArgs = argArray.length();
  //
  //	Pass 1: normalize arguments and calculate number of extra arguments that
  //	will result from flattening.
  //
  int expansion = 0;
  for (int i = 0; i < nrArgs; i++)
    {
      bool subtermChanged;
      Term* t = argArray[i].term->normalize(full, subtermChanged);
      if (subtermChanged)
	changed = true;
      argArray[i].term = t;
      if (full && t->symbol() == s)
	expansion += static_cast<AU_Term*>(t)->argArray.length() - 1;
    }
  //
  //	Pass 2: flatten at the top.
  //
  if (expansion > 0)
    {
      changed = true;
      argArray.expandBy(expansion);
      int p = nrArgs + expansion - 1;
      for (int i = nrArgs - 1; i >= 0; i--)
        {
          Assert(p >= i, "loop invariant broken");
          Term* t = argArray[i].term;
	  if (t->symbol() == s)
            {
	      Vector<Tuple>& argArray2 = static_cast<AU_Term*>(t)->argArray;
	      for (int j = argArray2.length() - 1; j >= 0; j--)
		argArray[p--].term = argArray2[j].term;
              delete t;
	    }
	  else
	    argArray[p--].term = t;
	}
      nrArgs += expansion;
    }
  //
  //	Pass 3: remove identity elements.
  //
  Term* identity = s->getIdentity();
  if (identity != 0)
    {
      int p = 0;
      for (int i = 0; i < nrArgs; i++)
	{
	  Term* t = argArray[i].term;
	  if (identity->equal(t) && idPossible(i))
	    {
	      changed = true;
	      continue;
	    }
	  argArray[p].term = t;
	  ++p;
	}
      if (p < 2)
	{
	  //
	  //	Only one arg left (p == 1) or all args are identity elements (p == 0).
	  //	Either way we collapse to first arg.
	  //
	  Term* t = argArray[0].term;
	  delete this;
	  return t;
	}
      argArray.contractTo(p);
      nrArgs = p;
    }
  //
  //	Pass 4: compute hash value.
  //
  unsigned int hashValue = s->getHashValue();
  nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    hashValue = hash(hashValue, argArray[i].term->getHashValue());
  setHashValue(hashValue);
  return this;
}

int
AU_Term::compareArguments(const Term* other) const
{
  int nrArgs = argArray.length();
  const Vector<Tuple>& argArray2 = static_cast<const AU_Term*>(other)->argArray;
  int nrArgs2 = argArray2.length();
  int limit = min(nrArgs, nrArgs2);
  for (int i = 0; i < limit; i++)
    {
      int r = argArray[i].term->compare(argArray2[i].term);
      if (r != 0)
	return r;
    }
  return nrArgs - nrArgs2;
}

int
AU_Term::compareArguments(const DagNode* other) const
{
  int nrArgs = argArray.length();
  const ArgVec<DagNode*>& argArray2 = static_cast<const AU_DagNode*>(other)->argArray;
  int nrArgs2 = argArray2.length();
  int limit = min(nrArgs, nrArgs2);
  for (int i = 0; i < limit; i++)
    {
      int r = argArray[i].term->compare(argArray2[i]);
      if (r != 0)
	return r;
    }
  return nrArgs - nrArgs2;
}

void
AU_Term::findEagerVariables(bool atTop, NatSet& eagerVariables) const
{
  BinarySymbol::PermuteStrategy strat = symbol()->getPermuteStrategy();
  if (strat == BinarySymbol::EAGER ||
      (strat == BinarySymbol::SEMI_EAGER && !atTop))
    {
      int nrArgs = argArray.length();
      for (int i = 0; i < nrArgs; i++)
	argArray[i].term->findEagerVariables(false, eagerVariables);
    }
}

void
AU_Term::markEagerArguments(int nrVariables,
			   const NatSet& eagerVariables,
			   Vector<int>& problemVariables)
{
  if (symbol()->getPermuteStrategy() == BinarySymbol::EAGER)
    {
      int nrArgs = argArray.length();
      for (int i = 0; i < nrArgs; i++)
	argArray[i].term->markEager(nrVariables, eagerVariables, problemVariables);
    }
}

DagNode*
AU_Term::dagify2()
{
  int nrArgs = argArray.length();
  AU_DagNode* d = new AU_DagNode(symbol(), nrArgs);
  ArgVec<DagNode*>& p = d->argArray;
  for (int i = 0; i < nrArgs; i++)    
    p[i] = argArray[i].term->dagify();
  return d;
}

void
AU_Term::analyseCollapses2()
{
  //
  //	(1) Analyse our subterms.
  //
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    argArray[i].term->analyseCollapses();
  //
  //	(2) Does our top symbol have an identity?
  //
  uniqueCollapseSubtermIndex = NONE;
  AU_Symbol* s = symbol();
  if (s->getIdentity() == 0)
    return;  // if no identity element then we can't collapse
  //
  //	(3) Can we collapse?
  //
  int firstNonIdArg = NONE;
  for (int i = 0; i < nrArgs; i++)
    {
      Term* t = argArray[i].term;
      if (idPossible(i) && s->mightMatchOurIdentity(t))
	continue;
      if (firstNonIdArg != NONE)
	return;  // can't collapse
      firstNonIdArg = i;
    }
  //
  //	(4) If so, what to?
  //
  if (firstNonIdArg != NONE)
    {
      //
      //        Can only collapse to firstNonIdArg.
      //
      uniqueCollapseSubtermIndex = firstNonIdArg;
      addCollapseSymbol(argArray[firstNonIdArg].term->symbol());
      addCollapseSymbols(argArray[firstNonIdArg].term->collapseSymbols());
    }
  else
    {
      //
      //        Can collapse to any of our arguments.
      //
      for (int i = 0; i < nrArgs; i++)
        {
	  Term* t = argArray[i].term;
	  addCollapseSymbol(t->symbol());
	  addCollapseSymbols(t->collapseSymbols());
	}
    }
}

void
AU_Term::insertAbstractionVariables(VariableInfo& variableInfo)
{
  AU_Symbol* s = symbol();
  bool honorsGroundOutMatch = true;
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    {
      Tuple& t = argArray[i];
      t.term->insertAbstractionVariables(variableInfo);
      if (!(t.term->honorsGroundOutMatch()))
        honorsGroundOutMatch = false;
      t.abstractionVariableIndex = NONE;
      t.collapseToOurSymbol = false;
      t.matchOurIdentity = false;
      if (dynamic_cast<VariableTerm*>(t.term) == 0)
        {
	  //
	  //	We don't bother checking wether we have a left identity
	  //	or a right identity because we may end up matching with
	  //	extension.
	  //
          t.matchOurIdentity = s->mightMatchOurIdentity(t.term);
          t.collapseToOurSymbol = s->mightCollapseToOurSymbol(t.term);
          if (t.matchOurIdentity || t.collapseToOurSymbol)
            {
              t.abstractionVariableIndex = variableInfo.makeProtectedVariable();
              honorsGroundOutMatch = false;
              DebugAdvisory("Introduced abstraction variable for " <<
			    t.term << " in " << this << '.');
            }
        }
    }
  setHonorsGroundOutMatch(honorsGroundOutMatch);
}

#ifdef DUMP
void
AU_Term::dump(ostream& s, const VariableInfo& variableInfo, int indentLevel)
{
  s << Indent(indentLevel) << "Begin{AU_Term}\n";
  ++indentLevel;
  dumpCommon(s, variableInfo, indentLevel);
  s << Indent(indentLevel) << "arguments:\n";
  ++indentLevel;
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    {
      const Tuple& p = argArray[i];
      s << Indent(indentLevel) << "collapseToOurSymbol = " << bool(p.collapseToOurSymbol) <<
        "\tmatchOurIdentity = " << bool(p.matchOurIdentity);
      if (p.abstractionVariableIndex != NONE)
        s << "\tabstractionVariableIndex = " << p.abstractionVariableIndex;
      s << '\n';
      p.term->dump(s, variableInfo, indentLevel);
    }
  s << Indent(indentLevel - 2) << "End{AU_Term}\n";
}
#endif

void
AU_Term::findAvailableTerms(TermBag& availableTerms, bool eagerContext, bool atTop)
{
  if (ground())
    return;
  if (!atTop)
    availableTerms.insertMatchedTerm(this, eagerContext);
  BinarySymbol::PermuteStrategy strat = symbol()->getPermuteStrategy();
  bool argEager = eagerContext && (strat == BinarySymbol::EAGER ||
				   (strat == BinarySymbol::SEMI_EAGER && !atTop));
  int nrArgs = argArray.length();
  for (int i = 0; i < nrArgs; i++)
    argArray[i].term->findAvailableTerms(availableTerms, argEager);
}

int
AU_Term::compileRhs2(RhsBuilder& rhsBuilder,
		     VariableInfo& variableInfo,
		     TermBag& availableTerms,
		     bool eagerContext)
{
  int nrArgs = argArray.length();
  AU_RhsAutomaton* automaton = new AU_RhsAutomaton(symbol(), nrArgs);
  bool argEager = eagerContext && symbol()->getPermuteStrategy() == BinarySymbol::EAGER;
  Vector<int> sources;
  for (int i = 0; i < nrArgs; i++)
    {
      int index = argArray[i].term->compileRhs(rhsBuilder,
					       variableInfo,
					       availableTerms,
					       argEager);
      automaton->addArgument(index);
      sources.append(index);
    }
  //
  //	Need to flag last use of each source.
  //
  for (int i = 0; i < nrArgs; i++)
    variableInfo.useIndex(sources[i]);

  int index = variableInfo.makeConstructionIndex();
  automaton->close(index);
  rhsBuilder.addRhsAutomaton(automaton);
  return index;
}
