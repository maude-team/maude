//
//      Implementation for class VariableTerm.
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
#include "term.hh"
#include "lhsAutomaton.hh"
#include "rhsAutomaton.hh"

//	core class definitions
#include "variableInfo.hh"
#include "symbolMap.hh"
#include "termBag.hh"
#include "substitution.hh"

//	variable class definitions
#include "variableSymbol.hh"
#include "variableTerm.hh"
#include "variableDagNode.hh"
#include "variableLhsAutomaton.hh"

VariableTerm::VariableTerm(VariableSymbol* symbol, int name)
  : Term(symbol),
    NamedEntity(name)
{
  index = UNDEFINED;
}

RawArgumentIterator*
VariableTerm::arguments()
{
  return 0;
}

void
VariableTerm::deepSelfDestruct()
{
  delete this;
}

Term*
VariableTerm::deepCopy2(SymbolMap* map) const
{
  VariableSymbol* vs = safeCast(VariableSymbol*,
				(map == 0 ? symbol() : map->translate(symbol())));
  return new VariableTerm(vs, id());
}

Term*
VariableTerm::normalize(bool /* full */, bool& changed)
{
  changed = false;
  setHashValue(hash(symbol()->getHashValue(), id()));
  return this;
}

int
VariableTerm::compareArguments(const Term* other) const
{
  return id() - safeCast(const VariableTerm*, other)->id();
}

int
VariableTerm::compareArguments(const DagNode* other) const
{
  return id() - safeCast(const VariableDagNode*, other)->id();
}

void
VariableTerm::findEagerVariables(bool /* atTop */, NatSet& eagerVariables) const
{
  eagerVariables.insert(index);
}

void
VariableTerm::analyseConstraintPropagation(NatSet& boundUniquely) const
{
  boundUniquely.insert(index);
}

LhsAutomaton*
VariableTerm::compileLhs2(bool matchAtTop,
			  const VariableInfo& variableInfo,
			  NatSet& boundUniquely,
			  bool& subproblemLikely)
{
  boundUniquely.insert(index);
  subproblemLikely = false;
  bool copyToAvoidOverwriting = matchAtTop /* && variableInfo.rhsVariables().contains(index) */;
  return new VariableLhsAutomaton(index, getSort(), copyToAvoidOverwriting);
}

void
VariableTerm::markEagerArguments(int nrVariables,
				 const NatSet& eagerVariables,
				 Vector<int>& problemVariables)
{
}

DagNode*
VariableTerm::dagify2()
{
  return new VariableDagNode(symbol(), id());
}

bool
VariableTerm::subsumes(const Term* other, bool sameVariableSet) const
{
  //
  //	If "this" and "other" are using the same set of variables
  //	then a variable can subsume itself.
  //
  if (sameVariableSet &&
      symbol() == other->symbol() &&
      id() == safeCast(const VariableTerm*, other)->id())
    return true;
  //
  //	Otherwise a variable must be linear and have large enough
  //	sort.
  //
  return !(occursInContext().contains(index)) &&
    getComponent()->leq(other->getSortIndex(), getSortIndex());
}

int
VariableTerm::partialCompareUnstable(const Substitution& partialSubstitution,
				     DagNode* other) const
{
  DagNode* d = partialSubstitution.value(index);
  if (d == 0)
    return UNDECIDED;
  int r = d->compare(other);
  if (r < 0)
    return LESS;
  if (r > 0)
    return GREATER;
  return EQUAL;
}

void
VariableTerm::findAvailableTerms(TermBag& availableTerms, bool eagerContext, bool atTop)
{
  if (!atTop)
    availableTerms.insertMatchedTerm(this, eagerContext);
}

int 
VariableTerm::compileRhs2(RhsBuilder& /* rhsBuilder */,
			  VariableInfo& /* variableInfo */,
			  TermBag& /* availableTerms */,
			  bool /* eagerContext */)
{
  CantHappen("should never be called");
  return 0;
}
