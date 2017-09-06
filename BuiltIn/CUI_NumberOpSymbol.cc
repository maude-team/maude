//
//      Implementation for class CUI_NumberOpSymbol.
//

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"
#include "CUI_Theory.hh"

//      interface class definitions
#include "term.hh"

//      core class definitions
#include "rewritingContext.hh"
#include "symbolMap.hh"

//      CUI theory class definitions
#include "CUI_Symbol.hh"
#include "CUI_DagNode.hh"

//      built in stuff
#include "bindingMacros.hh"
#include "succSymbol.hh"
#include "CUI_NumberOpSymbol.hh"

CUI_NumberOpSymbol::CUI_NumberOpSymbol(int id, Axioms axioms)
  : CUI_Symbol(id, standard, false, axioms)
{
  op = NONE;
  succSymbol = 0;
}

bool
CUI_NumberOpSymbol::attachData(const Vector<Sort*>& opDeclaration,
			       const char* purpose,
			       const Vector<const char*>& data)
{
  BIND_OP(purpose, CUI_NumberOpSymbol, op, data);
  return CUI_Symbol::attachData(opDeclaration, purpose, data);
}

bool
CUI_NumberOpSymbol::attachSymbol(const char* purpose, Symbol* symbol)
{
  BIND_SYMBOL(purpose, symbol, succSymbol, SuccSymbol*);
  return CUI_Symbol::attachSymbol(purpose, symbol);
}

void
CUI_NumberOpSymbol::copyAttachments(Symbol* original, SymbolMap* map)
{
  CUI_NumberOpSymbol* orig = safeCast(CUI_NumberOpSymbol*, original);
  op = orig->op;
  COPY_SYMBOL(orig, succSymbol, map, SuccSymbol*);
  CUI_Symbol::copyAttachments(original, map);
}

bool
CUI_NumberOpSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  CUI_DagNode* d = safeCast(CUI_DagNode*, subject);
  bool specialEval = true;
  //
  //	Evaluate our arguments and check that they are both numbers.
  //
  for (int i = 0; i < 2; i++)
    {
      DagNode* a = d->getArgument(i);
      a->reduce(context);
      if (!(succSymbol != 0 && succSymbol->isNat(a)))
	specialEval = false;
    }
  if (specialEval)
    {
      const mpz_class& a0 = succSymbol->getNat(d->getArgument(0));
      const mpz_class& a1 = succSymbol->getNat(d->getArgument(1));
      mpz_class r;
      switch (op)
	{
	case CODE('s', 'd'):
	  {
	    r = abs(a0 - a1);
	    break;
	  }
	default:
	  CantHappen("bad number op");
	}
      return succSymbol->rewriteToNat(subject, context, r);
    }
  return CUI_Symbol::eqRewrite(subject, context);
}
