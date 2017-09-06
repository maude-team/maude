//
//      Implementation for class MinusSymbol.
//
#ifdef __GNUG__
#pragma implementation
#endif

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "builtIn.hh"

//      interface class definitions
#include "term.hh"
#include "argumentIterator.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "symbolMap.hh"

//      free theory class definitions
#include "freeNet.hh"
#include "freeDagNode.hh"

//      built in stuff
#include "succSymbol.hh"
#include "numberOpSymbol.hh"
#include "minusSymbol.hh"

MinusSymbol::MinusSymbol(int id)
  : NumberOpSymbol(id, 1)
{
}

bool
MinusSymbol::attachData(const Vector<Sort*>& opDeclaration,
			const char* purpose,
			const Vector<const char*>& data)
{
  if (strcmp(purpose, "MinusSymbol") == 0)
    {
      if (data.length() != 0)
	return false;
      Vector<const char*> t(1);
      t[0] = "-";
      return NumberOpSymbol::attachData(opDeclaration, "NumberOpSymbol", t);
    }
  return NumberOpSymbol::attachData(opDeclaration, purpose, data);
}

DagNode*
MinusSymbol::makeNegDag(const mpz_class& integer)
{
  Assert(integer < 0, cerr << "not negative");
  Vector<DagNode*> arg(1);
  arg[0] = getSuccSymbol()->makeNatDag(- integer);  // would like to avoid copy
  return makeDagNode(arg);
}

bool
MinusSymbol::isNeg(const DagNode* dagNode) const
{
  Assert(static_cast<const Symbol*>(dagNode->symbol()) == this,
	 cerr << "symbol mismatch");
  DagNode* a = safeCast(const FreeDagNode*, dagNode)->getArgument(0);
  return a->symbol() == getSuccSymbol() && getSuccSymbol()->isNat(a);
}

const mpz_class&
MinusSymbol::getNeg(const DagNode* dagNode, mpz_class& result) const
{
  Assert(static_cast<const Symbol*>(dagNode->symbol()) == this,
	 cerr << "symbol mismatch");
  result = - getSuccSymbol()->getNat(safeCast(const FreeDagNode*, dagNode)->getArgument(0));
  return result;
}

Term*
MinusSymbol::makeIntTerm(const mpz_class& integer)
{
  if (integer >= 0)
    return getSuccSymbol()->makeNatTerm(integer);
  Vector<Term*> arg(1);
  arg[0] = getSuccSymbol()->makeNatTerm(- integer);  // would like to avoid copy
  return makeTerm(arg);
}

bool
MinusSymbol::isNeg(/* const */ Term* term) const
{
  Assert(static_cast<const Symbol*>(term->symbol()) == this,
	 cerr << "symbol mismatch");
  ArgumentIterator i(*term);
  Term* t = i.argument();
  return t->symbol() == getSuccSymbol() && getSuccSymbol()->isNat(t);
}

const mpz_class&
MinusSymbol::getNeg(/* const */ Term* term, mpz_class& result) const
{
  Assert(static_cast<const Symbol*>(term->symbol()) == this,
	 cerr << "symbol mismatch");
  ArgumentIterator i(*term);
  result = - getSuccSymbol()->getNat(i.argument());
  return result;
}
