//
//      Implementation for class VariableSymbol.
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

//	core class definitions
#include "variableSymbol.hh"
#include "variableTerm.hh"
#include "variableDagNode.hh"

VariableSymbol::VariableSymbol(int id)
  : Symbol(id, 0)
{
}

Term*
VariableSymbol::makeTerm(const Vector<Term*>& args)
{
  Assert(false, cerr << "makeTerm() not useable on variable symbol " << this);
  return 0;
}

DagNode*
VariableSymbol::makeDagNode(const Vector<DagNode*>& args)
{
  Assert(false, cerr << "makeDagNode() not useable on variable symbol " << this);
  return 0;
}

bool
VariableSymbol::eqRewrite(DagNode* subject, RewritingContext& context)
{
  return applyReplace(subject, context);
}

void
VariableSymbol::computeBaseSort(DagNode* subject)
{
  subject->setSortIndex(getSort()->index());
}

void
VariableSymbol::normalizeAndComputeTrueSort(DagNode* subject, RewritingContext& context)
{
  fastComputeTrueSort(subject, context);
}

void
VariableSymbol::stackArguments(DagNode* /* subject */,
			       Vector<RedexPosition>& /* stack */,
			       int /* parentIndex */)
{
}
