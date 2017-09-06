//
//      Implementation for class EqualitySymbol.
//
 
//	utility stuff
#include "macros.hh"
#include "vector.hh"
#include "indent.hh"

//      forward declarations
#include "interface.hh"
#include "core.hh"
#include "freeTheory.hh"

//      interface class definitions
#include "symbol.hh"
#include "dagNode.hh"
#include "term.hh"
 
//      core class definitions
#include "argumentIterator.hh"
#include "rewritingContext.hh"

//      free theory class definitions
#include "freeDagNode.hh"
 
//	built in class definitions
#include "equalitySymbol.hh"

//	full compiler classes
#include "compilationContext.hh"
#include "variableName.hh"

EqualitySymbol::EqualitySymbol(int id,
			       Term* eq,
			       Term* neq,
			       const Vector<int>& strategy)
  : FreeSymbol(id, 2, strategy),
    equalTerm(eq),
    notEqualTerm(neq)
{
}

EqualitySymbol::~EqualitySymbol()
{
  equalTerm.setTerm(0);  // HACK to avoid deep self destructing it
  notEqualTerm.setTerm(0);  // HACK to avoid deep self destructing it
}

void
EqualitySymbol::postInterSymbolPass()
{
  (void) equalTerm.normalize();
  equalTerm.prepare();
  (void) notEqualTerm.normalize();
  notEqualTerm.prepare();
}

void
EqualitySymbol::reset()
{
  equalTerm.reset();  // so equal dag can be garbage collected
  notEqualTerm.reset();  // so notEqualDag dag can be garbage collected
  FreeSymbol::reset();  // parents reset() tasks
}

bool
EqualitySymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  Assert(this == subject->symbol(), "bad symbol");
  FreeDagNode* f = static_cast<FreeDagNode*>(subject);
  DagNode* l = f->getArgument(0);
  DagNode* r = f->getArgument(1);
  if (standardStrategy())
    {
      l->reduce(context);
      r->reduce(context);
    }
  else
    {
      const Vector<int>& userStrategy = getStrategy();
      for(int i = 0;; i++)
	{
	  int a = userStrategy[i];
	  if (a == 0)
	    break;
	  f->getArgument(a - 1)->reduce(context);
	}
      l->computeTrueSort(context);  // we don't need the sort but we do need to normalize
      r->computeTrueSort(context);
    }
  return context.builtInReplace(subject, l->equal(r) ? equalTerm.getDag() : notEqualTerm.getDag());
}

bool
EqualitySymbol::acceptEquation(Equation* /* equation */)
{
  return false;
}

void
EqualitySymbol::compileEquations()
{
}

#ifdef COMPILER

void
EqualitySymbol::generateCode(CompilationContext& context) const
{
  Vector<VariableName> varNames;  // dummy
  context.body() << Indent(1) << "if (compare(a0, a1) == 0)\n";
  context.body() << Indent(2) << "{\n";
  equalTerm.getTerm()->generateRhs(context, 3, varNames, 0);
  context.body() << Indent(2) << "}\n";
  context.body() << Indent(1) << "else\n";
  context.body() << Indent(2) << "{\n";
  notEqualTerm.getTerm()->generateRhs(context, 3, varNames, 0);
  context.body() << Indent(2) << "}\n";
}

#endif
