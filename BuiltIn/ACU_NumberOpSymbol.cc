//
//      Implementation for class ACU_NumberOpSymbol.
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
#include "ACU_Theory.hh"
#include "builtIn.hh"

//      interface class definitions
#include "term.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "symbolMap.hh"

//      ACU theory class definitions
#include "ACU_Symbol.hh"
#include "ACU_DagNode.hh"

//      built in stuff
#include "bindingMacros.hh"
#include "succSymbol.hh"
#include "minusSymbol.hh"
#include "ACU_NumberOpSymbol.hh"

ACU_NumberOpSymbol::ACU_NumberOpSymbol(int id)
  : ACU_Symbol(id)
{
  op = NONE;
  succSymbol = 0;
  minusSymbol = 0;
}

bool
ACU_NumberOpSymbol::attachData(const Vector<Sort*>& opDeclaration,
			       const char* purpose,
			       const Vector<const char*>& data)
{
  BIND_OP(purpose, ACU_NumberOpSymbol, op, data);
  return ACU_Symbol::attachData(opDeclaration, purpose, data);
}

bool
ACU_NumberOpSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
  BIND_SYMBOL(purpose, symbol, succSymbol, SuccSymbol*);
  BIND_SYMBOL(purpose, symbol, minusSymbol, MinusSymbol*);
  return ACU_Symbol::attachSymbol(purpose, symbol);
}

void
ACU_NumberOpSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  ACU_NumberOpSymbol* orig = safeCast(ACU_NumberOpSymbol*, original);
  op = orig->op;
  COPY_SYMBOL(orig, succSymbol, map, SuccSymbol*);
  COPY_SYMBOL(orig, minusSymbol, map, MinusSymbol*);
  ACU_Symbol::copyAttachments(original, map);
}

bool
ACU_NumberOpSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), cerr << "bad symbol");
  if (!reduceArgumentsAndNormalize(subject, context))
    return false;  // collapsed under us
  //
  //	If we are aborting we don't want to eagerly compute with
  //	our numerical arguments and then throw the result away since
  //	the unreduced dag node might normalize into our parent
  //	which would do the same eager computation etc forming a
  //	potentially very expensive cascade. We must do this check
  //	after we have reduced our arguments otherwise we wouldn't
  //	notice an abort that occurred "on the way up".
  //
  if (RewritingContext::getTraceStatus() && context.traceAbort())
    return false;

  ACU_DagNode* d = safeCast(ACU_DagNode*, subject);
  int nrArgs = d->nrArgs();

  if (succSymbol != 0)
    {
      mpz_class accumulator;
      NatSet unused;
      int usedMultiplicity = 0;
      for (int i = 0; i < nrArgs; i++)
	{
	  DagNode* a = d->getArgument(i);
	  Symbol* s = a->symbol();
	  if ((s == minusSymbol) ? minusSymbol->isNeg(a) : succSymbol->isNat(a))
	    {
	      mpz_class storage;
	      const mpz_class& n = (s == minusSymbol) ? 
		minusSymbol->getNeg(a, storage) : succSymbol->getNat(a);
	      int m = d->getMultiplicity(i);
	      if (usedMultiplicity == 0)
		{
		  usedMultiplicity = m;
		  accumulator = n;
		  if (--m == 0)
		    continue;
		}
	      else
		usedMultiplicity += m;
	      switch (op)
		{
		case '+':
		  {
		    if (m == 1)
		      accumulator += n;
		    else
		      accumulator += n * m;
		    break;
		  }
		case '*':
		  {
		    if (m == 1)
		      accumulator *= n;
		    else
		      {
			mpz_class t;
			mpz_pow_ui (t.get_mpz_t(), n.get_mpz_t(), m);
			accumulator *= t;
		      }
		    break;
		  }
		case '|':
		  {
		    accumulator |= n;
		    break;
		  }
		case '&':
		  {
		    accumulator &= n;
		    break;
		  }
		case CODE('x', 'o'):
		  {
		    if (m & 1)
		      accumulator ^= n;
		    break;
		  }
		case CODE('g', 'c'):
		  {
		    mpz_gcd(accumulator.get_mpz_t(), accumulator.get_mpz_t(), n.get_mpz_t());
		    break;
		  }
		case CODE('l', 'c'):
		  {
		    mpz_lcm(accumulator.get_mpz_t(), accumulator.get_mpz_t(), n.get_mpz_t());
		    break;
		  }
		}
	    }
	  else
	    unused.insert(i); 
	}
      if (usedMultiplicity >= 2)
	{
	  Assert(minusSymbol != 0 || accumulator >= 0, cerr << "can't make -ve int");
	  if (unused.empty())
	    {
	      return (accumulator >= 0) ?
		succSymbol->rewriteToNat(subject, context, accumulator) :
		context.builtInReplace(subject, minusSymbol->makeNegDag(accumulator));
	    }
	  DagNode* n = (accumulator >= 0) ? succSymbol->makeNatDag(accumulator) :
	    minusSymbol->makeNegDag(accumulator);
	  int nrNewArgs = unused.size() + 1;
	  Vector<DagNode*> dagNodes(nrNewArgs);
	  Vector<int> multiplicities(nrNewArgs);
	  int j = 0;
	  const NatSet::const_iterator e = unused.end();
	  for (NatSet::const_iterator i = unused.begin(); i != e; ++i)
	    {
	      dagNodes[j] = d->getArgument(*i);
	      multiplicities[j] = d->getMultiplicity(*i);
	      ++j;
	    }
	  dagNodes[j] = n;
	  multiplicities[j] = 1;
	  return context.builtInReplace(subject, makeDagNode(dagNodes, multiplicities));
	}
    }
  return ACU_Symbol::eqRewrite(subject, context);
}
