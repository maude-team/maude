//
//      Implementation for class DivisionSymbol.
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
#include "bindingMacros.hh"
#include "succSymbol.hh"
#include "minusSymbol.hh"
#include "divisionSymbol.hh"

DivisionSymbol::DivisionSymbol(int id)
  : FreeSymbol(id, 2)
{
  succSymbol = 0;
  minusSymbol = 0;
}

bool
DivisionSymbol::attachData(const Vector<Sort*>& opDeclaration,
			   const char* purpose,
			   const Vector<const char*>& data)
{
  NULL_DATA(purpose, DivisionSymbol, data)
  return FreeSymbol::attachData(opDeclaration, purpose, data);
}

bool
DivisionSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
  BIND_SYMBOL(purpose, symbol, succSymbol, SuccSymbol*);
  BIND_SYMBOL(purpose, symbol, minusSymbol, MinusSymbol*);
  return FreeSymbol::attachSymbol(purpose, symbol);
}

void
DivisionSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  DivisionSymbol* orig = safeCast(DivisionSymbol*, original);
  COPY_SYMBOL(orig, succSymbol, map, SuccSymbol*);
  COPY_SYMBOL(orig, minusSymbol, map, MinusSymbol*);
  FreeSymbol::copyAttachments(original, map);
}

bool
DivisionSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), cerr << "bad symbol");

  FreeDagNode* d = safeCast(FreeDagNode*, subject);
  DagNode* d0 = d->getArgument(0);
  d0->reduce(context);
  DagNode* d1 = d->getArgument(1);
  d1->reduce(context);

  if (isRat(subject))
    {
      const mpz_class& denominator = succSymbol->getNat(d1);
      if (denominator == 1)
	return context.builtInReplace(subject, d0);
      mpz_class storage0;
      const mpz_class& numerator = (d0->symbol() == minusSymbol) ? 
	minusSymbol->getNeg(d0, storage0) : succSymbol->getNat(d0);
      Assert(numerator != 0, cerr << "zero numerator");
      mpz_class common;
      mpz_gcd(common.get_mpz_t(), numerator.get_mpz_t(), denominator.get_mpz_t());
      if (common > 1)
	{
	  if (denominator == common)
	    {
	      mpz_class nr = numerator / common;
	      return (nr >= 0) ? succSymbol->rewriteToNat(subject, context, nr) :
		context.builtInReplace(subject, minusSymbol->makeNegDag(nr));
	    }
	  (void) context.builtInReplace(subject, makeRatDag(numerator / common,
							    denominator / common));
	  Assert(this == subject->symbol(), cerr << "unexpectedly changed top symbol");
	  //
	  //  	we don't want to revisit this node since it is already simplified
	  //	- so fall into regular case.
	  //
	}
    }
  return FreeSymbol::eqRewrite(subject, context);
}

DagNode*
DivisionSymbol::makeRatDag(const mpz_class& nr, const mpz_class& dr)
{
  Assert(nr != 0 && dr > 0, cerr << "not a strict rat");
  DagNode* d = (nr >= 0) ? succSymbol->makeNatDag(nr) : minusSymbol->makeNegDag(nr);
  if (dr == 1)
    return d;

  Vector<DagNode*> args(2);
  args[0] = d;
  args[1] = succSymbol->makeNatDag(dr);
  return makeDagNode(args);
}

bool
DivisionSymbol::isRat(const DagNode* dagNode) const
{
  Assert(this == static_cast<const Symbol*>(dagNode->symbol()),
	 cerr << "bad symbol");
  const FreeDagNode* d = safeCast(const FreeDagNode*, dagNode);
  DagNode* d0 = d->getArgument(0);
  DagNode* d1 = d->getArgument(1); 
  return d1->symbol() == succSymbol && succSymbol->isNat(d1) &&
    ((d0->symbol() == minusSymbol) ? minusSymbol->isNeg(d0) :
     (d0->symbol() == succSymbol && succSymbol->isNat(d0)));
}


const mpz_class&
DivisionSymbol::getRat(const DagNode* dagNode, mpz_class& numerator) const
{
  Assert(this == static_cast<const Symbol*>(dagNode->symbol()),
	 cerr << "bad symbol");
    const FreeDagNode* d = safeCast(const FreeDagNode*, dagNode);
  DagNode* d0 = d->getArgument(0);
  if (d0->symbol() == minusSymbol)
    (void) minusSymbol->getNeg(d0, numerator);
  else
    {
      Assert(d0->symbol() == succSymbol, cerr << "bad numerator");
      numerator = succSymbol->getNat(d0);
    }
  DagNode* d1 = d->getArgument(1);
  Assert(d1->symbol() == succSymbol, cerr << "bad denominator");
  return succSymbol->getNat(d1);
}

Term*
DivisionSymbol::makeRatTerm(const mpz_class& nr, const mpz_class& dr)
{
  Assert(nr != 0 && dr > 0, cerr << "not a strict rat");
  Vector<Term*> args(2);
  args[0] = (nr >= 0) ? succSymbol->makeNatTerm(nr) : minusSymbol->makeIntTerm(nr);
  args[1] = succSymbol->makeNatTerm(dr);
  return makeTerm(args);
}
bool
DivisionSymbol::isRat(/* const */ Term* term) const
{
  Assert(this == static_cast<const Symbol*>(term->symbol()),
	 cerr << "bad symbol");
  ArgumentIterator i(*term);
  Term* t0 = i.argument();
  i.next();
  Term* t1 = i.argument();
  return t1->symbol() == succSymbol && succSymbol->isNat(t1) &&
    ((t0->symbol() == minusSymbol) ? minusSymbol->isNeg(t0) :
     (t0->symbol() == succSymbol && succSymbol->isNat(t0)));
}


const mpz_class&
DivisionSymbol::getRat(/* const */ Term* term, mpz_class& numerator) const
{
  Assert(this == static_cast<const Symbol*>(term->symbol()),
	 cerr << "bad symbol");
  ArgumentIterator i(*term);
  Term* t0 = i.argument();
  if (t0->symbol() == minusSymbol)
    (void) minusSymbol->getNeg(t0, numerator);
  else
    {
      Assert(t0->symbol() == succSymbol, cerr << "bad numerator");
      numerator = succSymbol->getNat(t0);
    }
  i.next();
  Term* t1 = i.argument();
  Assert(t1->symbol() == succSymbol, cerr << "bad denominator");
  return succSymbol->getNat(t1);
}
