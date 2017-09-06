//
//      Implementation for class FloatSymbol.
//
#ifdef SOLARIS
#include <ieeefp.h>
#else
#include <math.h>
#endif

//      utility stuff
#include "macros.hh"
#include "vector.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "NA_Theory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"

//      core class definitions
#include "rewritingContext.hh"

//	built in class definitions
#include "floatSymbol.hh"
#include "floatTerm.hh"
#include "floatDagNode.hh"

FloatSymbol::FloatSymbol(int id)
  : NA_Symbol(id)
{
  sort = 0;
  finiteSort = 0;
}

void
FloatSymbol::fillInSortInfo(Term* subject)
{
  Sort* s = finite(static_cast<FloatTerm*>(subject)->getValue()) ? finiteSort : sort;
  subject->setSortInfo(s->component(), s->index());
}

void
FloatSymbol::computeBaseSort(DagNode* subject)
{
  Sort* s = finite(static_cast<FloatDagNode*>(subject)->getValue()) ? finiteSort : sort;
  subject->setSortIndex(s->index());
}

bool
FloatSymbol::isConstructor(DagNode* /* subject */)
{
  return true;
}

void
FloatSymbol::compileOpDeclarations()
{
  // NA_Symbol::compileOpDeclarations();  // default processing
  const Vector<OpDeclaration>& opDecls = getOpDeclarations();
  int nrOpDecls = opDecls.length();
  for (int i = 0; i < nrOpDecls; i++)
    {
      Sort* s = opDecls[i].getDomainAndRange()[0];
      if (sort == 0 || s->index() < sort->index())
	sort = s;  // set sort to largest (smallest index) declared sort
      if (finiteSort == 0 || s->index() > finiteSort->index())
	finiteSort = s;  // set finiteSort to smallest (largest index) declared sort
    }
}

bool
FloatSymbol::rewriteToFloat(DagNode* subject,
					  RewritingContext& context,
					  double result)
{
  bool trace = RewritingContext::getTraceStatus();
  if (trace)
    {
      context.tracePreEqRewrite(subject, 0, RewritingContext::BUILTIN);
      if (context.traceAbort())
	return false;
    }
  (void) new(subject) FloatDagNode(this, result);
  context.incrementEqCount();
  if (trace)
    context.tracePostEqRewrite(subject);
  return true;  
}
